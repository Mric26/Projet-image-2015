#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "open.h"
#include "save.h"
#include "couper.h"
#include "grisconvers.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    cheminImage(),
    hist()
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    image = new QImage();
    imageaffichee = new QGraphicsPixmapItem();

    ui->couper->setIcon(QIcon(":res/ciseaux.png"));
    QObject::connect( ui->couper, SIGNAL(clicked()), this, SLOT(couper()) );
    new QShortcut(QKeySequence("Ctrl+X"), this, SLOT(couper()) );

    ui->pipette->setIcon(QIcon(":res/pipette.jpg"));
    QObject::connect( ui->pipette, SIGNAL(clicked()), this, SLOT(pipeit()));

    ui->histogramme->setIcon(QIcon(":res/histogramme.jpg"));
    QObject::connect( ui->histogramme, SIGNAL(clicked()), this, SLOT(showHisto()) );
    new QShortcut(QKeySequence("Ctrl+H"), this, SLOT(showHisto()) );

    ui->flou->setIcon(QIcon(":res/flou.png"));
    QObject::connect( ui->flou, SIGNAL(clicked()), this, SLOT(flouGaussLeger()) );
    QObject::connect( ui->actionFlouGaussLeger, SIGNAL(triggered()), this, SLOT(flouGaussLeger()) );
    QObject::connect( ui->actionFlouGaussMoyen, SIGNAL(triggered()), this, SLOT(flouGaussMoyen()) );
    QObject::connect( ui->actionFlouGaussFort, SIGNAL(triggered()), this, SLOT(flouGaussFort()) );
    QObject::connect( ui->actionFlouMoyLeger, SIGNAL(triggered()), this, SLOT(flouMoyLeger()) );
    QObject::connect( ui->actionFlouMoyMoyen, SIGNAL(triggered()), this, SLOT(flouMoyMoyen()) );
    QObject::connect( ui->actionFlouMoyFort, SIGNAL(triggered()), this, SLOT(flouMoyFort()) );
    QObject::connect( ui->actionRehaussement, SIGNAL(triggered()), this, SLOT(rehaussement()) );
    QObject::connect( ui->actionGradientX, SIGNAL(triggered()), this, SLOT(gradientX()) );
    QObject::connect( ui->actionGradientY, SIGNAL(triggered()), this, SLOT(gradientY()) );
    QObject::connect( ui->actionDetectionContours, SIGNAL(triggered()), this, SLOT(detectionContours()) );
    new QShortcut(QKeySequence("Ctrl+F"), this, SLOT(flouGaussLeger()) );

    ui->fusion->setIcon(QIcon(":res/fusion.png"));

    ui->gris->setIcon(QIcon(":res/niv_gris.png"));
    QObject::connect( ui->gris, SIGNAL(clicked()), this, SLOT(gris()) );
    new QShortcut(QKeySequence("Ctrl+G"), this, SLOT(gris()) );

    ui->ouvrir->setIcon(QIcon(":res/ouvrir.jpg"));
    QObject::connect( ui->ouvrir, SIGNAL(clicked()), this, SLOT(ouv()) );
    QObject::connect( ui->actionOuvrir_2, SIGNAL(triggered()), this, SLOT(ouv()) );
    new QShortcut(QKeySequence("Ctrl+O"), this, SLOT(ouv()) );

    ui->enregistrer->setIcon(QIcon(":res/enregistrer.png"));
    QObject::connect( ui->enregistrer, SIGNAL(clicked()), this, SLOT(save()) );
    new QShortcut(QKeySequence("Ctrl+S"), this, SLOT(save()) );
    QObject::connect( ui->actionEnregistrer, SIGNAL(triggered()), this, SLOT(save()) );

    if (scene != NULL) {
        ui->graphicsView->setScene(scene);
    }

    QObject::connect( ui->actionEnregistrer_sous, SIGNAL(triggered()), this, SLOT(saveAs()) );
    QObject::connect( ui->actionPasse_haut, SIGNAL(triggered()), this, SLOT(passeHaut()) );

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

void MainWindow::ouv(){
     Open op;
     op.ouvrir(this);
}

void MainWindow::save(){
     Save sv;
     sv.sauv(this);
}

void MainWindow::saveAs(){
     Save sv;
     sv.sauvSous(this);
}

void MainWindow::couper(){
    if( ui->graphicsView->getRb() != NULL ){
        Couper cp;
        cp.couper(this, ui->graphicsView->getPointD(), ui->graphicsView->getPointF());
    }
    delete ui->graphicsView->getRb();
    ui->graphicsView->setRb(NULL);
}

void MainWindow::showHisto(){
    hist = new DiagramColorWindow( this->getImage() );
}

void MainWindow::flouMoyLeger(){
    Convolution c;
    setImage(c.flouMoy(image,3),cheminImage);
}

void MainWindow::flouMoyMoyen(){
    Convolution c;
    setImage(c.flouMoy(image,5),cheminImage);
}

void MainWindow::flouMoyFort(){
    Convolution c;
    setImage(c.flouMoy(image,7),cheminImage);
}

void MainWindow::flouGaussLeger(){
    Convolution c;
    setImage(c.flouGaussien(image,3),cheminImage);
}

void MainWindow::flouGaussMoyen(){
    Convolution c;
    setImage(c.flouGaussien(image,5),cheminImage);
}

void MainWindow::flouGaussFort(){
    Convolution c;
    setImage(c.flouGaussien(image,7),cheminImage);
}

void MainWindow::passeHaut(){
    Convolution c;
    setImage(c.filtrePasseHaut(image),cheminImage);
}

void MainWindow::rehaussement(){
    Convolution c;
    setImage(c.filtreRehaussement(image),cheminImage);
}

void MainWindow::gradientX()
{
    Convolution c;
    setImage(c.gradientX(image),cheminImage);
}

void MainWindow::gradientY()
{
    Convolution c;
    setImage(c.gradientY(image),cheminImage);
}

void MainWindow::detectionContours()
{
    Convolution c;
    setImage(c.detectionContours(image),cheminImage);
}
DiagramColorWindow *MainWindow::getHist() const{
    return hist;
}

void MainWindow::setHist(DiagramColorWindow *value){
    hist = value;
}

void MainWindow::gris(){
    GrisConvers gc;
    this->setImage( gc.versGris(this), this->getCheminImage() );
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

void MainWindow::pipeit(){
    ui->graphicsView->setWin(this);
    ui->graphicsView->setDopipe(true);
    QPixmap pix(":res/curseurpipette.png");
    QApplication::setOverrideCursor(QCursor(pix));
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

void MainWindow::refresh(){
    if(getEmptylabel()){
        ui->label->setText(" ");
        setEmptylabel(false);
    }else if(!ui->graphicsView->getDopipe()) //s'il ne faut plus regarder les composantes d'un pixel
    {
        cout << "restauration du curseur" << endl;
        QApplication::restoreOverrideCursor();
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
