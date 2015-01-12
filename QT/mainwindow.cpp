#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "open.h"
#include "save.h"
#include "couper.h"
#include "grisconvers.h"
#include "histogrammes.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    cheminImage()
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    image = new QImage();
    imageaffichee = new QGraphicsPixmapItem();

    ui->couper->setText("");
    ui->couper->setIcon(QIcon("IMG/ciseaux.png"));
    QObject::connect( ui->couper, SIGNAL(clicked()), this, SLOT(couper()) );
    //QObject::connect( ui->, SIGNAL(triggered()), this, SLOT(couper()) );

    ui->pipette->setText("");
    ui->pipette->setIcon(QIcon("IMG/pipette.jpg"));

    ui->histogramme->setText("");
    ui->histogramme->setIcon(QIcon("IMG/histogramme.jpg"));
    QObject::connect( ui->histogramme, SIGNAL(clicked()), this, SLOT(showHisto()) );

    ui->flou->setText("");
    ui->flou->setIcon(QIcon("IMG/flou.png"));
    QObject::connect( ui->flou, SIGNAL(clicked()), this, SLOT(flouLeger()) );
    QObject::connect( ui->actionFlouLeger, SIGNAL(triggered()), this, SLOT(flouLeger()) );
    QObject::connect( ui->actionFlouMoyen, SIGNAL(triggered()), this, SLOT(flouMoyen()) );
    QObject::connect( ui->actionFlouFort, SIGNAL(triggered()), this, SLOT(flouFort()) );

    ui->fusion->setText("");
    ui->fusion->setIcon(QIcon("IMG/fusion.png"));

    ui->gris->setText("");
    ui->gris->setIcon(QIcon("IMG/niv_gris.png"));
    QObject::connect( ui->gris, SIGNAL(clicked()), this, SLOT(gris()) );

    ui->ouvrir->setText("");
    ui->ouvrir->setIcon(QIcon(":res/ouvrir.jpg"));
    QObject::connect( ui->ouvrir, SIGNAL(clicked()), this, SLOT(ouv()) );
    QObject::connect( ui->actionOuvrir_2, SIGNAL(triggered()), this, SLOT(ouv()) );

    ui->enregistrer->setText("");
    ui->enregistrer->setIcon(QIcon("IMG/enregistrer.png"));
    QObject::connect( ui->enregistrer, SIGNAL(clicked()), this, SLOT(save()) );
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
        cp.couper(this, ui->graphicsView, ui->graphicsView->getPointD(), ui->graphicsView->getPointF());
    }
    delete ui->graphicsView->getRb();
    ui->graphicsView->setRb(NULL);
}

void MainWindow::showHisto(){
    Histogrammes h();
    //h.afficher();
}

void MainWindow::flouLeger(){
    Convolution c;
    setImage(c.flouGaussien(image,3),cheminImage);
}

void MainWindow::flouMoyen(){
    Convolution c;
    setImage(c.flouGaussien(image,5),cheminImage);
}

void MainWindow::flouFort(){
    Convolution c;
    setImage(c.flouGaussien(image,7),cheminImage);
}

void MainWindow::passeHaut()
{
    Convolution c;
    setImage(c.filtrePasseHaut(image),cheminImage);
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
