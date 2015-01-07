#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "open.h"
#include "save.h"
#include <QGraphicsPixmapItem>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    cheminImage(),
    matrice()
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    image = new QImage();

    ui->couper->setText("");
    ui->couper->setIcon(QIcon("IMG/ciseaux.png"));

    ui->pipette->setText("");
    ui->pipette->setIcon(QIcon("IMG/pipette.jpg"));

    ui->histogramme->setText("");
    ui->histogramme->setIcon(QIcon("IMG/histogramme.jpg"));

    ui->flou->setText("");
    ui->flou->setIcon(QIcon("IMG/flou.png"));

    ui->fusion->setText("");
    ui->fusion->setIcon(QIcon("IMG/fusion.png"));

    ui->gris->setText("");
    ui->gris->setIcon(QIcon("IMG/niv_gris.png"));

    ui->ouvrir->setText("");
    ui->ouvrir->setIcon(QIcon("IMG/ouvrir.jpg"));
    QObject::connect( ui->ouvrir, SIGNAL(clicked()), this, SLOT(ouv()) );

    ui->enregistrer->setText("");
    ui->enregistrer->setIcon(QIcon("IMG/enregistrer.png"));

    if (scene != NULL) {

        ui->graphicsView->setScene(scene);
    }


    QObject::connect( ui->enregistrer, SIGNAL(clicked()), this, SLOT(save()) );
    QObject::connect( ui->actionEnregistrer_sous, SIGNAL(clicked()), this, SLOT(saveAs()) );

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *){
//    if( image != NULL ){
//        QPainter qp(this);
//        int x = 0;
//        int y = 0;
//        if( image->width() < this->width() ){
//            x = this->width()/2 - image->width()/2;
//        }
//        if( image->height() < this->height() ){
//            y = this->height()/2 - image->height()/2;
//        }
//       qp.drawImage(x,y,*image);
//       qp.end();
//    }
}

QImage * MainWindow::getImage(){
    return image;
}

void MainWindow::setImage(QImage *im, QString chem){
    image = im;
    cheminImage = chem;

    QPixmap *imagePix = new QPixmap();
    imagePix->convertFromImage(*image);

    scene->addPixmap(*imagePix);
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
QGraphicsScene* MainWindow::getScene()
{
    return scene;
}

void MainWindow::setScene(QGraphicsScene *value)
{
    scene = value;
}


std::vector<QRgb> MainWindow::getMatrice() const{
    return matrice;
}

void MainWindow::setMatrice(const std::vector<QRgb> &value){
    matrice = value;
}

QString MainWindow::getCheminImage(){
    return cheminImage;
}
