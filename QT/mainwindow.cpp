#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "open.h"
#include "save.h"
#include "copier.h"
#include "couper.h"
#include "rogner.h"
#include "coller.h"
#include "grisconvers.h"
#include "fusion.h"
#include "redimensionnement.h"
#include "segmentation.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    cheminImage(),
    hist(),
    fPerso()
{
    setEmptylabel(false);
    ui->setupUi(this);
    scene = new QGraphicsScene();
    image = new QImage();
    copie = new QImage();
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
    QObject::connect( ui->pipette, SIGNAL(clicked()), this, SLOT(pipeit()) );
    QObject::connect( ui->actionEspace_RGB, SIGNAL(triggered()), this, SLOT(changeRGBtoYUVtrue()));
    QObject::connect( ui->actionEspace_YUV, SIGNAL(triggered()), this, SLOT(changeRGBtoYUVfalse()));
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
    QObject:graphicsView:connect( ui->actionFusion, SIGNAL(triggered()), this, SLOT(createFusion()) );
    QObject::connect( ui->fusion, SIGNAL(clicked()), this, SLOT(createFusion()) );

    ui->gris->setIcon(QIcon(":res/niv_gris.png"));
    QObject::connect( ui->actionNiveau_de_gris, SIGNAL(triggered()), this, SLOT(gris()) );
    QObject::connect( ui->gris, SIGNAL(clicked()), this, SLOT(gris()) );
    new QShortcut(QKeySequence("Ctrl+G"), this, SLOT(gris()) );

    ui->ouvrir->setIcon(QIcon(":res/ouvrir.jpg"));
    QObject::connect( ui->ouvrir, SIGNAL(clicked()), this, SLOT(ouv()) );
    QObject::connect( ui->actionOuvrir_2, SIGNAL(triggered()), this, SLOT(ouv()) );
    new QShortcut( QKeySequence("Ctrl+O"), this, SLOT(ouv()) );

    QObject::connect( ui->actionRedimensionner, SIGNAL(triggered()), this, SLOT(redimensionner()) );
    new QShortcut(QKeySequence("Ctrl+R"), this, SLOT(redimensionner()) );

    QObject::connect( ui->actionSegmentation, SIGNAL(triggered()), this, SLOT(segmenter()) );

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

    new QShortcut( QKeySequence("Ctrl+C"), this, SLOT(copier()) );
    new QShortcut( QKeySequence("Ctrl+V"), this, SLOT(coller()) );

    new QShortcut( QKeySequence("F11"), this, SLOT(pleinEcran()) );
    new QShortcut( QKeySequence("Ctrl+F11"), this, SLOT(minimiser()) );

    ui->selection->setIcon(QIcon(":res/selection.jpg"));
    QObject::connect( ui->selection, SIGNAL(clicked()), this, SLOT(selection()) );

    QObject::connect( ui->actionFusionner, SIGNAL(triggered()), this, SLOT(fusionnerCalques()) );

    desactive();

}

MainWindow::~MainWindow(){
    delete ui;
    delete image;
    delete scene;
    delete hist;
    delete fPerso;
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
    //ouverture
     Open op;
     int o = op.ouvrir(this);
     if( o == 1){
         for( int l=0; l<2; l++){
             annul[l] = NULL;
             refai[l] = NULL;
         }
     }
}

void MainWindow::nettoyage(){
    //nettoyage selection
    ui->graphicsView->setSelect( false );
    if( ui->graphicsView->getRb() != NULL ){
        delete ui->graphicsView->getRb();
        ui->graphicsView->setRb(NULL);
    }
    //nettoyage item
    scene->clear();
    //remise curseur
    ui->graphicsView->setCursor(Qt::ArrowCursor);
}

void MainWindow::desactive(){
    if( cheminImage == NULL ){
        ui->enregistrer->setEnabled(false);
        ui->annuler->setEnabled(false);
        ui->refaire->setEnabled(false);
        ui->selection->setEnabled(false);
        ui->couper->setEnabled(false);
        ui->rogner->setEnabled(false);
        ui->pipette->setEnabled(false);
        ui->gris->setEnabled(false);
        ui->fusion->setEnabled(false);
        ui->flou->setEnabled(false);
        ui->histogramme->setEnabled(false);
    }
}

void MainWindow::active(){
    if( cheminImage != NULL ){
        ui->enregistrer->setEnabled(true);
        ui->annuler->setEnabled(true);
        ui->refaire->setEnabled(true);
        ui->selection->setEnabled(true);
        ui->couper->setEnabled(true);
        ui->rogner->setEnabled(true);
        ui->pipette->setEnabled(true);
        ui->gris->setEnabled(true);
        ui->fusion->setEnabled(true);
        ui->flou->setEnabled(true);
        ui->histogramme->setEnabled(true);
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
    ui->graphicsView->setSelect( false );
}

void MainWindow::rogner(){
    if( ui->graphicsView->getRb() != NULL ){
        Rogner ro;
        ro.rogner(this, ui->graphicsView->getPointD(), ui->graphicsView->getPointF());
        delete ui->graphicsView->getRb();
        ui->graphicsView->setRb(NULL);
        ui->graphicsView->setSelect( false );
    }
}

void MainWindow::copier(){
    if( ui->graphicsView->getRb() != NULL ){
        Copier cop;
        copie = cop.copier( this, ui->graphicsView->getPointD(), ui->graphicsView->getPointF() );
        delete ui->graphicsView->getRb();
        ui->graphicsView->setRb(NULL);
        ui->graphicsView->setSelect( false );
    }

}

void MainWindow::coller(){
    if( copie != NULL ){
        Coller col;
        col.coller(this, *copie);
    }
}

void MainWindow::pleinEcran(){
    this->showFullScreen();
}

void MainWindow::minimiser(){
    this->showNormal();
}

void MainWindow::selection(){
    ui->graphicsView->setDopipe( false );
    ui->graphicsView->setSelect( true );
    if ( !(ui->graphicsView->getSelect()) ){
        delete ui->graphicsView->getRb();
        ui->graphicsView->setRb(NULL);
    }
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

void MainWindow::filtrePerso(){
    if( cheminImage != NULL ){
        fPerso = new FiltrePerso(this);
        QObject::connect( fPerso, SIGNAL(envoyerMatrice(float**,int)), this, SLOT(appliquerFiltrePerso(float**,int)) );
    }

}

void MainWindow::appliquerFiltrePerso(float **matrice, int tailleMatrice)
{
    if( cheminImage != NULL ){
        Convolution c;
        setImage(c.conv(image,matrice,tailleMatrice),cheminImage);
    }
}

void MainWindow::median()
{
    if( cheminImage != NULL ){
        Convolution c;
        setImage(c.filtreMedian(image,1),cheminImage);
    }
}

void MainWindow::gris(){
    if( cheminImage != NULL ){
        GrisConvers gc;
        this->setImage( gc.versGris(this), this->getCheminImage() );
    }
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
    if( cheminImage != NULL ){
        ui->graphicsView->setWin(this);
        ui->graphicsView->setSelect( false );
        ui->graphicsView->setDopipe(true);
    }
}

void MainWindow::refresh(){
    if(getEmptylabel()){ //on a cliqué dans la graphicview mais en dehors de l'image: vider le label
        ui->label->setText(" ");
        setEmptylabel(false);
    }
    // s'il ne faut plus regarder les composantes d'un pixel
    else if(!ui->graphicsView->getDopipe())  {
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

void MainWindow::redimensionner(){
 if(getCheminImage() != NULL){ //image ouverte, on peut la redimensionner
     Redimensionnement* fenetreRedim= new Redimensionnement;
     fenetreRedim->redim(this);
     fenetreRedim->show();
     fenetreRedim->activateWindow();
     fenetreRedim->exec();
 }
}

void MainWindow::segmenter(){
    if(getCheminImage() != NULL){
        Segmentation *seg= new Segmentation;
        seg->setWin(this);
        seg->setImage(getImage());
        seg->addIMG(getImage(), getCheminImage());
        seg->show();
        seg->activateWindow();
        //seg->doSeg(this, ui->graphicsView->getPointD(), ui->graphicsView->getPointF());
    }
}

void MainWindow::fusionnerCalques(){
    FusionCalques fc;
    //ajout des item a fusionner a la liste
    QList<QGraphicsItem *> list = scene->selectedItems();
    //fusion des items
    QImage * res = NULL;
    if( !list.isEmpty() ){
        res = fc.fusionCalques(list, image);
    }
    //si nouvelle image
    if( res != NULL ){
        QList<QGraphicsItem *> list2;
        QList<QPointF> list3;
        //enleve les items
        QGraphicsItem * it;
        list = scene->items();
        for( int i=0; i<list.size(); i++){
            it = list[i];
            if( !(it->isSelected()) && (it != imageaffichee) ){
                list2.push_back(it);
                list3.push_back(it->pos());
            }
            this->scene->removeItem(it);
        }
        //ajoute image
        this->setImage( res, cheminImage );
        //ajoute item
        QGraphicsPixmapItem * it2;
        QPointF pos;
        for( int i=0; i<list2.size(); i++){
            it = list2[i];
            if( it->type() == 7 ){
                //item
                it2 = (QGraphicsPixmapItem *)it;
                it2 = scene->addPixmap(it2->pixmap());
                //position
                pos = list3[i];
                it2->setPos(pos);
                //falgs
                it2->setFlag(QGraphicsItem::ItemIsSelectable);
                it2->setFlag(QGraphicsItem::ItemIsMovable);
                it2->setFlag(QGraphicsItem::ItemIsFocusable);
            }
        }
    }
}

QImage * MainWindow::getcopie() const{
    return copie;
}

void MainWindow::setcopie(QImage * value){
    copie = value;
}

QGraphicsScene *MainWindow::getScene() const{
    return scene;
}

void MainWindow::setScene(QGraphicsScene *value){
    scene = value;
}

