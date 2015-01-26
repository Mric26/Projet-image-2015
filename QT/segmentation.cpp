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

    if (scene != NULL) {
        ui->graphicsView->setScene(scene);
    }

}

Segmentation::~Segmentation()
{
    delete ui;
}

void Segmentation::addIMG(QImage *im, QString cheminIMG){
//    QImage * im = new QImage();
//    im->load(chIMG);
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
        Mat mask = imread(chemin.toStdString(),CV_8UC1); //masque d'avant plan
        mask= mask & 1; //convertion en masque binaire

        Mat bgModel= *(new Mat());
        Mat fgModel= *(new Mat());

//        for (int i = 0; i < mask.cols; ++i) {
//            for (int j = 0; j < mask.rows; ++j) {
//                if(mask.at<double>(i,j) == 255){
//                    //mask.setTo(cv::GC_FGD);

//                    mask.at<double>(i,j) = GC_FGD;
//                }else{
//                    //mask.setTo(cv::GC_PR_BGD);
//                    mask.at<double>(i,j) = GC_PR_BGD;
//                }
//            }
//        }

        grabCut(img,
                    mask,
                    rect,
                    bgModel,
                    fgModel,
                    1,
                    GC_INIT_WITH_MASK);

        //Visualize results.
        compare(mask,cv::GC_FGD,mask,cv::CMP_EQ);
        Mat foreground(img.size(),CV_8UC3, cv::Scalar(0,0,0));
        img.copyTo(foreground,mask); //les éléments non nuls de 'mask' donnent les points de 'img' à copier dans 'foregroung'
        imshow("avant plan",foreground);
        imshow("masque", mask);

        close();
    }else{ //utilisation uniquement du rectangle définit par l'utilisateur
        Mat bgModel;// = *(new Mat());
        Mat fgModel;// = *(new Mat());


        grabCut(img,
                result,
                rect,
                bgModel,
                fgModel,
                1,
                GC_INIT_WITH_RECT);

        //le résultat est-il bien un avant-plan
        compare(result,GC_PR_FGD,result,CMP_EQ);

        // génération de l'image de sortie
        Mat foreground(img.size(),CV_8UC3,Scalar(0,0,0));
        img.copyTo(foreground,result); // bg pixels not copied

        // affichage
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


//void Segmentation::mousePressEvent(QMouseEvent *event){
//    if(event->button() == Qt::RightButton){ //ajouter un nuage de point au masque d'arrière plan
//        for (int i = event->pos().x()-5; i < event->pos().x()+5; ++i) {
//            for (int j = event->pos().y()-5; j < event->pos().y()+5; ++j) {
//                image->setPixel(i,j,qRgb(255,255,255));
//            }
//        }
//    }
//    useMask = true;
//    std::cout << "usemask? " << useMask << std::endl;
//}
