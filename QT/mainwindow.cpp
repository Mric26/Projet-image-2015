#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "open.h"
#include "save.h"
#include "couper.h"
#include "rogner.h"
#include "grisconvers.h"
#include "fusion.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    cheminImage(),
    hist(),
    fPerso()
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    image = new QImage();
    imageaffichee = new QGraphicsPixmapItem();
    for( int l=0; l<2; l++){
        annul[l] = NULL;
        refai[l] = NULL;
    }

    ui->annuler->setIcon(QIcon(":res/Annuler.png"));
    QObject::connect( ui->annuler, SIGNAL(clicked()), this, SLOT(annuler()) );
    new QShortcut( QKeySequence("Ctrl+Z"), this, SLOT(annuler()) );

    ui->refaire->setIcon(QIcon(":res/Refaire.png"));
    QObject::connect( ui->refaire, SIGNAL(clicked()), this, SLOT(refaire()) );
    new QShortcut( QKeySequence("Ctrl+Shift+Z"), this, SLOT(refaire()) );

    ui->couper->setIcon(QIcon(":res/ciseaux.png"));
    QObject::connect( ui->couper, SIGNAL(clicked()), this, SLOT(couper()) );
    new QShortcut( QKeySequence("Ctrl+X"), this, SLOT(couper()) );

    ui->rogner->setIcon(QIcon(":res/Rogner.png"));
    QObject::connect( ui->rogner, SIGNAL(clicked()), this, SLOT(rogner()) );
    new QShortcut( QKeySequence("Ctrl+R"), this, SLOT(rogner()) );

    ui->pipette->setIcon(QIcon(":res/pipette.jpg"));
    QObject::connect( ui->actionPipette, SIGNAL(triggered()), this, SLOT(pipeit()) );
    QObject::connect( ui->pipette, SIGNAL(clicked()), this, SLOT(pipeit()) );
    new QShortcut( QKeySequence("Ctrl+P"), this, SLOT(pipeit()) );

    ui->histogramme->setIcon(QIcon(":res/histogramme.jpg"));
    QObject::connect( ui->histogramme, SIGNAL(clicked()), this, SLOT(showHisto()) );
    QObject::connect( ui->actionHistogramme, SIGNAL(triggered()), this, SLOT(showHisto()) );
    QObject::connect( ui->actionEtalement, SIGNAL(triggered()), this, SLOT(etaler()) );
    QObject::connect( ui->actionEgalisation, SIGNAL(triggered()), this, SLOT(egaler()) );
    new QShortcut( QKeySequence("Ctrl+H"), this, SLOT(showHisto()) );

    ui->flou->setIcon(QIcon(":res/flou.png"));
    QObject::connect( ui->flou, SIGNAL(clicked()), this, SLOT(flouGaussLeger()) );
    QObject::connect( ui->actionFlouGaussLeger, SIGNAL(triggered()), this, SLOT(flouGaussLeger()) );
    QObject::connect( ui->actionFlouGaussMoyen, SIGNAL(triggered()), this, SLOT(flouGaussMoyen()) );
    QObject::connect( ui->actionFlouGaussFort, SIGNAL(triggered()), this, SLOT(flouGaussFort()) );
    QObject::connect( ui->actionFlouMoyLeger, SIGNAL(triggered()), this, SLOT(flouMoyLeger()) );
    QObject::connect( ui->actionFlouMoyMoyen, SIGNAL(triggered()), this, SLOT(flouMoyMoyen()) );
    QObject::connect( ui->actionFlouMoyFort, SIGNAL(triggered()), this, SLOT(flouMoyFort()) );
    QObject::connect( ui->actionRehaussement, SIGNAL(triggered()), this, SLOT(rehaussement()) );
    QObject::connect( ui->actionPasse_haut, SIGNAL(triggered()), this, SLOT(passeHaut()) );
    QObject::connect( ui->actionGradientX, SIGNAL(triggered()), this, SLOT(gradientX()) );
    QObject::connect( ui->actionGradientY, SIGNAL(triggered()), this, SLOT(gradientY()) );
    QObject::connect( ui->actionDetectionContours, SIGNAL(triggered()), this, SLOT(detectionContours()) );
    QObject::connect( ui->actionMedian, SIGNAL(triggered()), this, SLOT(median()) );
    QObject::connect( ui->actionPersonnaliser, SIGNAL(triggered()), this, SLOT(filtrePerso()) );
    new QShortcut( QKeySequence("Ctrl+F"), this, SLOT(median()) );

    ui->fusion->setIcon(QIcon(":res/fusion.png"));
    QObject::connect( ui->actionFusion, SIGNAL(triggered()), this, SLOT(createFusion()) );
    QObject::connect( ui->fusion, SIGNAL(clicked()), this, SLOT(createFusion()) );

    ui->gris->setIcon(QIcon(":res/niv_gris.png"));
    QObject::connect( ui->actionNiveau_de_gris, SIGNAL(triggered()), this, SLOT(gris()) );
    QObject::connect( ui->gris, SIGNAL(clicked()), this, SLOT(gris()) );
    new QShortcut(QKeySequence("Ctrl+G"), this, SLOT(gris()) );

    ui->ouvrir->setIcon(QIcon(":res/ouvrir.jpg"));
    QObject::connect( ui->ouvrir, SIGNAL(clicked()), this, SLOT(ouv()) );
    QObject::connect( ui->actionOuvrir_2, SIGNAL(triggered()), this, SLOT(ouv()) );
    new QShortcut( QKeySequence("Ctrl+O"), this, SLOT(ouv()) );

    if (scene != NULL) {
        ui->graphicsView->setScene(scene);
    }

    ui->enregistrer->setIcon(QIcon(":res/enregistrer.png"));
    QObject::connect( ui->enregistrer, SIGNAL(clicked()), this, SLOT(save()) );
    new QShortcut( QKeySequence("Ctrl+S"), this, SLOT(save()) );
    QObject::connect( ui->actionEnregistrer, SIGNAL(triggered()), this, SLOT(save()) );

    QObject::connect( ui->actionEnregistrer_sous, SIGNAL(triggered()), this, SLOT(saveAs()) );

    QObject::connect( ui->actionFermer, SIGNAL(triggered()), this, SLOT(quit()) );
    new QShortcut( QKeySequence("Ctrl+Q"), this, SLOT(quit()) );

}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *){
}

QImage * MainWindow::getImage(){
    return image;
}

void MainWindow::setImage(QImage *im, QString chem){

    if( image != NULL){
        if( annul[0] == NULL){
            annul[0] = image;
        }
        else{
            annul[1] = annul[0];
            annul[0] = image;
        }
    }

    if (im->format() <= QImage::Format_Indexed8) {
        *im = im->convertToFormat(QImage::Format_RGB32);
    }
    image = im;

    cheminImage = chem;

    QPixmap *imagePix = new QPixmap();
    imagePix->convertFromImage(*image);

    if (imageaffichee != NULL) {
        scene->removeItem(imageaffichee);
    }

    imageaffichee = scene->addPixmap(*imagePix);
    scene->setSceneRect(0,0,image->width(),image->height());
    ui->graphicsView->show();
}

void MainWindow::quit(){
     qApp->quit();
}

void MainWindow::ouv(){
     Open op;
     op.ouvrir(this);
     for( int l=0; l<2; l++){
         annul[l] = NULL;
         refai[l] = NULL;
     }
}

void MainWindow::save(){
    if( cheminImage != NULL ){
        Save sv;
        sv.sauv(this);
    }
}

void MainWindow::saveAs(){
    if( cheminImage != NULL ){
        Save sv;
        sv.sauvSous(this);
    }
}

void MainWindow::annuler(){
    if( annul[0] != NULL){
        if( refai[0] != NULL){
            refai[1] = refai[0];
        }
        refai[0] = image;
        QImage * temp = annul[1];
        setImage( annul[0], cheminImage );
        annul[0] = temp;
        annul[1] = NULL;
    }
}

void MainWindow::refaire(){
    if( refai[0] != NULL ){
        if( annul[0] != NULL ){
            annul[1] = annul[0];
        }
        setImage( refai[0], cheminImage );
        refai[0] = refai[1];
        refai[1] = NULL;
    }
}

void MainWindow::couper(){
    if( ui->graphicsView->getRb() != NULL ){
        Couper cp;
        cp.couper(this, ui->graphicsView->getPointD(), ui->graphicsView->getPointF());
    }
    delete ui->graphicsView->getRb();
    ui->graphicsView->setRb(NULL);
}

void MainWindow::rogner(){
    if( ui->graphicsView->getRb() != NULL ){
        Rogner ro;
        ro.rogner(this, ui->graphicsView->getPointD(), ui->graphicsView->getPointF());
    }
    delete ui->graphicsView->getRb();
    ui->graphicsView->setRb(NULL);
}

void MainWindow::showHisto(){
    if( cheminImage != NULL ){
        hist = new DiagramColorWindow( this->getImage() );
    }
}

void MainWindow::etaler(){
    if( cheminImage != NULL ){
        Etalement et;
        this->setImage( et.etaler(image), cheminImage );
    }
}

void MainWindow::egaler(){
    if( cheminImage != NULL ){
        Egalisation eg;
        this->setImage( eg.egaler(image), cheminImage );
    }
}

void MainWindow::flouMoyLeger(){
    if( cheminImage != NULL ){
        Convolution c;
        setImage(c.flouMoy(image,3),cheminImage);
    }
}

void MainWindow::flouMoyMoyen(){
    if( cheminImage != NULL ){
        Convolution c;
        setImage(c.flouMoy(image,5),cheminImage);
    }
}

void MainWindow::flouMoyFort(){
    if( cheminImage != NULL ){
        Convolution c;
        setImage(c.flouMoy(image,7),cheminImage);
    }
}

void MainWindow::flouGaussLeger(){
    if( cheminImage != NULL ){
        Convolution c;
        setImage(c.flouGaussien(image,3),cheminImage);
    }
}

void MainWindow::flouGaussMoyen(){
    if( cheminImage != NULL ){
        Convolution c;
        setImage(c.flouGaussien(image,5),cheminImage);
    }
}

void MainWindow::flouGaussFort(){
    if( cheminImage != NULL ){
        Convolution c;
        setImage(c.flouGaussien(image,7),cheminImage);
    }
}

void MainWindow::passeHaut(){
    if( cheminImage != NULL ){
        Convolution c;
        setImage(c.filtrePasseHaut(image),cheminImage);
    }
}

void MainWindow::rehaussement(){
    if( cheminImage != NULL ){
        Convolution c;
        setImage(c.filtreRehaussement(image),cheminImage);
    }
}

void MainWindow::gradientX(){
    if( cheminImage != NULL ){
        Convolution c;
        setImage(c.gradientX(image),cheminImage);
    }
}

void MainWindow::gradientY(){
    if( cheminImage != NULL ){
        Convolution c;
        setImage(c.gradientY(image),cheminImage);
    }
}

void MainWindow::detectionContours(){
    if( cheminImage != NULL ){
        Convolution c;
        setImage(c.detectionContours(image),cheminImage);
    }
}

void MainWindow::filtrePerso()
{
    fPerso = new FiltrePerso(this);
    QObject::connect( fPerso, SIGNAL(envoyerMatrice(float**,int)), this, SLOT(appliquerFiltrePerso(float**,int)) );

}

void MainWindow::appliquerFiltrePerso(float **matrice, int tailleMatrice)
{
    Convolution c;
    setImage(c.conv(image,matrice,tailleMatrice),cheminImage);
}

void MainWindow::median()
{
    Convolution c;
    setImage(c.filtreMedian(image,1),cheminImage);
}

DiagramColorWindow *MainWindow::getHist() const{
    return hist;
}

void MainWindow::setHist(DiagramColorWindow *value){
    hist = value;
}

void MainWindow::gris(){
    if( cheminImage != NULL ){
        GrisConvers gc;
        this->setImage( gc.versGris(this), this->getCheminImage() );
    }
}

QGraphicsScene* MainWindow::getScene(){
    return scene;
}

void MainWindow::setScene(QGraphicsScene *value){
    scene = value;
}

QString MainWindow::getCheminImage(){
    return cheminImage;
}

bool MainWindow::getRgbORyuv() const{
    return rgbORyuv;
}

void MainWindow::setRgbORyuv(bool value){
    rgbORyuv = value;
}

bool MainWindow::getEmptylabel() const{
    return emptylabel;
}

void MainWindow::setEmptylabel(bool value){
    emptylabel = value;
}

void MainWindow::changeRGBtoYUVtrue(){
    setRgbORyuv(true);
}

void MainWindow::changeRGBtoYUVfalse(){
    setRgbORyuv(false);
}

void MainWindow::createFusion(){
    Fusion fus;
    fus.fusionner(this);
}

QGraphicsPixmapItem *MainWindow::getImageaffichee() const{
    return imageaffichee;
}

void MainWindow::setImageaffichee(QGraphicsPixmapItem *value){
    imageaffichee = value;
}

void MainWindow::pipeit(){
    ui->graphicsView->setWin(this);
    ui->graphicsView->setDopipe(true);
    QPixmap pix(":res/curseurpipette.png");
    QApplication::setOverrideCursor(QCursor(pix));
}

void MainWindow::refresh(){
    if(getEmptylabel()){
        ui->label->setText(" ");
        setEmptylabel(false);
    }else if(!ui->graphicsView->getDopipe()) //s'il ne faut plus regarder les composantes d'un pixel
    {
        QApplication::setOverrideCursor(Qt::ArrowCursor);

        if(ui->graphicsView->getReadRGB()){
            if(getRgbORyuv()){ //espace RGB
                QRgb* component = new QRgb(getImage()->pixel(ui->graphicsView->getPos()));
                QColor couleur(*component);
                QString txt;
                txt =       "alpha:"   + QString::number(couleur.alpha());
                txt = txt + " rouge: " + QString::number(couleur.red());
                txt = txt + " vert: "  + QString::number(couleur.green());
                txt = txt + " bleu: "  + QString::number(couleur.blue());
                ui->label->setText(txt);
            }else{ //espace YUV
                QRgb* component = new QRgb(getImage()->pixel(ui->graphicsView->getPos()));
                QColor couleur(*component);
                QString txt;
                int R(couleur.red());
                int G(couleur.green());
                int B(couleur.blue());
                txt =  " Y: " + QString::number(R *  .299000 + G *  .587000 + B *  .114000);
                txt = txt + " U: "  + QString::number(R * -.168736 + G * -.331264 + B *  .500000 + 128);
                txt = txt + " V: "  + QString::number(R *  .500000 + G * -.418688 + B * -.081312 + 128);
                ui->label->setText(txt);
            }
        }
    }
}
