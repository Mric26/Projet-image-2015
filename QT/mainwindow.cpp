#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "open.h"
#include "save.h"
#include "couper.h"

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
    imageaffichee = new QGraphicsPixmapItem();

    ui->couper->setText("");
    ui->couper->setIcon(QIcon("IMG/ciseaux.png"));
    QObject::connect( ui->couper, SIGNAL(clicked()), this, SLOT(couper()) );
    //QObject::connect( ui->, SIGNAL(triggered()), this, SLOT(couper()) );

    ui->pipette->setText("");
    ui->pipette->setIcon(QIcon("IMG/pipette.jpg"));

    ui->histogramme->setText("");
    ui->histogramme->setIcon(QIcon("IMG/histogramme.jpg"));

    ui->flou->setText("");
    ui->flou->setIcon(QIcon("IMG/flou.png"));
    QObject::connect( ui->flou, SIGNAL(clicked()), this, SLOT(flouLeger()) );
    QObject::connect( ui->actionFlouLeger, SIGNAL(clicked()), this, SLOT(flouLeger()) );
    QObject::connect( ui->actionFlouMoyen, SIGNAL(clicked()), this, SLOT(flouMoyen()) );
    QObject::connect( ui->actionFlouFort, SIGNAL(clicked()), this, SLOT(flouFort()) );

    ui->fusion->setText("");
    ui->fusion->setIcon(QIcon("IMG/fusion.png"));

    ui->gris->setText("");
    ui->gris->setIcon(QIcon("IMG/niv_gris.png"));

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

}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *){
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    //cout << "MainW x : " << point.x() << " y : " << point.y() << endl;
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
    ui->graphicsView->getRb()->hide();
    Couper cp;
    cp.couper(this, ui->graphicsView->getPointD(), ui->graphicsView->getPointF());
}

void MainWindow::flouLeger()
{
    Convolution c;
//    int **matFlou;
//    matFlou = new int *[3];
//    matFlou[0] = new int[3];
//    matFlou[0][0] = 1;
//    matFlou[0][1] = 2;
//    matFlou[0][2] = 1;
//    matFlou[1] = new int[3];
//    matFlou[1][0] = 2;
//    matFlou[1][1] = 4;
//    matFlou[1][2] = 2;
//    matFlou[2] = new int[3];
//    matFlou[2][0] = 1;
//    matFlou[2][1] = 2;
//    matFlou[2][2] = 1;

//    setImage(c.conv(image,matFlou,3,3),cheminImage);
    int **base;
    base = new int *[2];
    base[0] = new int[2];
    base [0][0] = 1;
    base [0][1] = 1;
    base[1] = new int[2];
    base [1][0] = 1;
    base [1][1] = 1;
    setImage(c.conv(image,c.genererBinomial(base,3,2),3,3),cheminImage);
}

void MainWindow::flouMoyen()
{
//    Convolution c;
//    int **matFlou;
//    matFlou = new int *[5];
//    matFlou[0] = new int[5];
//    matFlou[0] = {1,4,6,4,1};
//    matFlou[1] = new int[5];
//    matFlou[1][0] = 2;
//    matFlou[1][1] = 4;
//    matFlou[1][2] = 2;
//    matFlou[2] = new int[5];
//    matFlou[2][0] = 1;
//    matFlou[2][1] = 2;
//    matFlou[2][2] = 1;

//    setImage(c.conv(image,matFlou,3,3),cheminImage);
}

void MainWindow::flouFort()
{
    Convolution c;
    int **base;
    base = new int *[2];
    base[0] = new int[2];
    base [0][0] = 1;
    base [0][1] = 1;
    base[1] = new int[2];
    base [1][0] = 1;
    base [1][1] = 1;
    setImage(c.conv(image,c.genererBinomial(base,3,2),3,3),cheminImage);
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
