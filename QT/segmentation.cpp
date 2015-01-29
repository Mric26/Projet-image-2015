#include "segmentation.h"
#include "ui_segmentation.h"
#include "opencv.hpp"
#include <iostream>
#include <QFileDialog>

using namespace cv;

Segmentation::Segmentation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Segmentation)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    image= new QImage();

    QObject::connect( ui->ok, SIGNAL(clicked()), this, SLOT(ok()) );

    QObject::connect( ui->cancel, SIGNAL(clicked()), this, SLOT(cancel()) );

    ui->graphicsView->setSelect(true);

    if (scene != NULL) {
        ui->graphicsView->setScene(scene);
    }

}

Segmentation::~Segmentation()
{
    delete ui;
}

void Segmentation::addIMG(QImage *im, QString cheminIMG){
    cheminImage = cheminIMG;

    if (im->format() <= QImage::Format_Indexed8) {
        *im = im->convertToFormat(QImage::Format_RGB32);
    }
    image = im;
    QPixmap *imagePix = new QPixmap();
    imagePix->convertFromImage(*image);
    ui->graphicsView->scene()->addPixmap(*imagePix);
    scene->setSceneRect(0,0,image->width(),image->height());
    ui->graphicsView->show();


}

void Segmentation::ok(){
    QPoint D= ui->graphicsView->getPointD();
    QPoint F= ui->graphicsView->getPointF();
    getImage()->save("temp.png");
    Mat img= imread("temp.png");
    Rect rect( D.x(),D.y(),(F.x()-D.x()),(F.y()-D.y()) );
    Mat result; // résultat de la segmentation

    if(ui->checkBox->isChecked()){ //utilisation de masques personnalisés (image servant de masque)
        QString chemin = QFileDialog::getOpenFileName(getWin(),"choisir l'image pour le masque");

        Mat mask;
        mask.create(img.rows, img.cols, CV_8UC1);

        Mat bgModel;
        Mat fgModel;

        QImage * im = new QImage();
        im->load(chemin);


        for (int i = 0; i < mask.cols; ++i) {
            for (int j = 0; j < mask.rows; ++j) {
                if( (QColor(QRgb(im->pixel(i,j))).blue() > QColor(QRgb(im->pixel(i,j))).red()) && (QColor(QRgb(im->pixel(i,j))).blue() > QColor(QRgb(im->pixel(i,j))).green()) ){ //points d'avant plan (définis en bleu)
                    mask.at<char>(j,i) = GC_FGD;
                }
                else if( (QColor(QRgb(im->pixel(i,j))).red() > QColor(QRgb(im->pixel(i,j))).blue()) && (QColor(QRgb(im->pixel(i,j))).red() > QColor(QRgb(im->pixel(i,j))).green()) ){ //point présumé d'arrière plan (défini en rouge)
                    mask.at<char>(j,i) = GC_BGD;
                }
                else{
                    mask.at<char>(j,i) = GC_PR_FGD;
                }
            }
        }

        grabCut(img,
                    mask,
                    rect,
                    bgModel,
                    fgModel,
                    1,
                    GC_INIT_WITH_MASK);


        //traitement du masque en sortie de grabcut
        for (int i = 0; i < mask.cols; ++i) {
            for (int j = 0; j < mask.rows; ++j) {
                if( (mask.at<char>(j,i) == 1) || (mask.at<char>(j,i) == 3) ){
                    mask.at<char>(j,i) = 1;
                }
                else{
                    mask.at<char>(j,i) = 0;
                }
            }
        }

        //Visualisation des résultats
        Mat foreground(img.size(),CV_8UC3, Scalar(0,0,0)); // génération de l'image de sortie
        img.copyTo(foreground,mask); //les éléments non nuls de 'mask' donnent les points de 'img' à copier dans 'foregroung'
        imshow("avant plan",foreground); //affichage

        close();
    }else{ //utilisation uniquement du rectangle définit par l'utilisateur
        Mat bgModel;
        Mat fgModel;

        grabCut(img,
                result,
                rect,
                bgModel,
                fgModel,
                1,
                GC_INIT_WITH_RECT);

        compare(result,GC_PR_FGD,result,CMP_EQ);
        Mat foreground(img.size(),CV_8UC3,Scalar(0,0,0));
        img.copyTo(foreground,result);
        imshow("avant plan",foreground);

        close();
    }
    QFile::remove("temp.png");
}

void Segmentation::cancel(){
    close();
}

QImage *Segmentation::getImage() const
{
    return image;
}

void Segmentation::setImage(QImage *value)
{
    image = value;
}

MainWindow *Segmentation::getWin() const
{
    return win;
}

void Segmentation::setWin(MainWindow *value)
{
    win = value;
}
