#include "redimensionnement.h"
#include "ui_redimensionnement.h"
#include <QImage>
#include "qrgb.h"

using namespace std;

Redimensionnement::Redimensionnement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Redimensionnement)
{
    setCancel(false);

    ui->setupUi(this);

    ui->coordonneesX->setRange(1,5000);

    ui->coordonneesY->setRange(1,5000);

    QObject::connect( ui->ok, SIGNAL(clicked()), this, SLOT(ok()));

    QObject::connect( ui->cancel, SIGNAL(clicked()), this, SLOT(canceled()));
}

Redimensionnement::~Redimensionnement(){
    delete ui;
}

void Redimensionnement::redimHauteur(QImage *final){
    float tauxRedimensionnement,r1,g1,b1;
    if(getYFinal() > getWin()->getImage()->height()){//agrandissment en hauteur
        tauxRedimensionnement = (float(getYFinal()) / float(getWin()->getImage()->height()));
        for (int j = 0; j < getWin()->getImage()->width(); ++j) {
            for (int i = 0; i < getWin()->getImage()->height(); ++i) {

                r1= (QColor(getWin()->getImage()->pixel(j,i)).red());
                g1= (QColor(getWin()->getImage()->pixel(j,i)).green());
                b1= (QColor(getWin()->getImage()->pixel(j,i)).blue());

                for (int k = 0; k < tauxRedimensionnement; ++k) {
                    final->setPixel(j,i*tauxRedimensionnement+k,qRgb(int(r1+0.5),int(g1+0.5),int(b1+0.5)));
                }
            }
        }
    }else if(getYFinal() < getWin()->getImage()->height()){ //réduction en hauteur
        tauxRedimensionnement = (float(getWin()->getImage()->height()) / float(getYFinal()));
        for (int j = 0; j < getWin()->getImage()->width(); ++j) {
            for (int i = 0; i < getWin()->getImage()->height(); i+=tauxRedimensionnement) {

                r1= ((QColor(getWin()->getImage()->pixel(j,i)).red()) + (QColor(getWin()->getImage()->pixel(j,i+1)).red()))/2;
                g1= ((QColor(getWin()->getImage()->pixel(j,i)).green()) + (QColor(getWin()->getImage()->pixel(j,i+1)).green()))/2;
                b1= ((QColor(getWin()->getImage()->pixel(j,i)).blue()) + (QColor(getWin()->getImage()->pixel(j,i+1)).blue()))/2;

                final->setPixel(j,i/tauxRedimensionnement,qRgb(int(r1+0.5),int(g1+0.5),int(b1+0.5)));
            }
        }
    }else{
        *final = *(getWin()->getImage());
    }
}

void Redimensionnement::redimLargeur(QImage *final, QImage *inter){

    float tauxRedimensionnement,r1,g1,b1;
    if(getXFinal() > inter->width()){ //agrandissement en largeur
        tauxRedimensionnement = (float(getXFinal()) / float(inter->width()));
        for (int j = 0; j < inter->height(); ++j) {
            for (int i = 0; i < getWin()->getImage()->width(); ++i) {

                r1= (QColor(inter->pixel(i,j)).red());
                g1= (QColor(inter->pixel(i,j)).green());
                b1= (QColor(inter->pixel(i,j)).blue());

                for (int k = 0; k < tauxRedimensionnement; ++k) {
                    final->setPixel(i*tauxRedimensionnement+k,j,qRgb(int(r1+0.5),int(g1+0.5),int(b1+0.5)));
                }
            }
        }
    }else if(getXFinal() < inter->width()){ //réduction en largeur
        tauxRedimensionnement = (float(inter->width()) / float(getXFinal()));
        for (int j = 0; j < getYFinal(); ++j) {
            for (int i = 0; i < inter->width(); i+=tauxRedimensionnement) {

                r1= ((QColor(inter->pixel(i,j)).red()) + (QColor(inter->pixel(i+1,j)).red()))/2;
                g1= ((QColor(inter->pixel(i,j)).green()) + (QColor(inter->pixel(i+1,j)).green()))/2;
                b1= ((QColor(inter->pixel(i,j)).blue()) + (QColor(inter->pixel(i+1,j)).blue()))/2;

                final->setPixel(i/tauxRedimensionnement,j,qRgb(int(r1+0.5),int(g1+0.5),int(b1+0.5)));
            }
        }
    }else{
        *final = *inter;
    }
}

void Redimensionnement::ok(){
    setXFinal(ui->coordonneesX->value());
    setYFinal(ui->coordonneesY->value());

    QImage *inter= new QImage(getWin()->getImage()->width(),getYFinal(), QImage::Format_RGB32);//création d'une image intermédiaire

    redimHauteur(inter);

    QImage *final= new QImage(getXFinal(),getYFinal(), QImage::Format_RGB32);//image finale à retourner

    redimLargeur(final,inter);

    getWin()->setImage(final,QString(" "));

    close();
}

void Redimensionnement::canceled(){
    setCancel(true);
    close();
}
MainWindow *Redimensionnement::getWin() const
{
    return win;
}

void Redimensionnement::setWin(MainWindow *value)
{
    win = value;
}

bool Redimensionnement::getCancel() const
{
    return cancel;
}

void Redimensionnement::setCancel(bool value)
{
    cancel = value;
}

int Redimensionnement::getYFinal() const
{
    return yFinal;
}

void Redimensionnement::setYFinal(int value)
{
    yFinal = value;
}

int Redimensionnement::getXFinal() const
{
    return xFinal;
}

void Redimensionnement::setXFinal(int value)
{
    xFinal = value;
}


void Redimensionnement::redim(MainWindow *w){
    int largeurInitiale, hauteurInintiale;
    largeurInitiale = w->getImage()->width();
    hauteurInintiale = w->getImage()->height();

    setWin(w);

    ui->coordonneesX->setValue(largeurInitiale);
    ui->coordonneesY->setValue(hauteurInintiale);


    setXFinal(largeurInitiale);
    setYFinal(hauteurInintiale);

    setCancel(false);
}

//tentative d'interpollation
//    if(getYFinal() > getWin()->getImage()->height()){//agrandissment en hauteur
//        tauxRedimensionnement = (float(getYFinal()) / float(getWin()->getImage()->height()));
//        for (int j = 0; j < getXFinal(); ++j) {
//            for (int i = 0; i < getWin()->getImage()->height(); ++i) {

//                r1= (QColor(getWin()->getImage()->pixel(j,i)).red());
//                g1= (QColor(getWin()->getImage()->pixel(j,i)).green());
//                b1= (QColor(getWin()->getImage()->pixel(j,i)).blue());

//                for (int k = 0; k < tauxRedimensionnement; ++k) {
//                    final->setPixel(j,i*tauxRedimensionnement+k,qRgb(int(r1+0.5),int(g1+0.5),int(b1+0.5)));
//                }
//            }
//        }
//    }else if(getYFinal() < getWin()->getImage()->height()){ //réduction en hauteur
//        tauxRedimensionnement = (float(getWin()->getImage()->height()) / float(getYFinal()));
//        for (int j = 0; j < getXFinal(); ++j) {
//            for (int i = 0; i < getWin()->getImage()->height(); i+=tauxRedimensionnement) {

//                r1= ((QColor(getWin()->getImage()->pixel(j,i)).red()) + (QColor(getWin()->getImage()->pixel(j,i+1)).red()))/2;
//                g1= ((QColor(getWin()->getImage()->pixel(j,i)).green()) + (QColor(getWin()->getImage()->pixel(j,i+1)).green()))/2;
//                b1= ((QColor(getWin()->getImage()->pixel(j,i)).blue()) + (QColor(getWin()->getImage()->pixel(j,i+1)).blue()))/2;

//                final->setPixel(j,i/tauxRedimensionnement,qRgb(int(r1+0.5),int(g1+0.5),int(b1+0.5)));
//            }
//        }
//    }else{

//    }

//    if(getXFinal() > getWin()->getImage()->width()){ //agrandissement en largeur
//        tauxRedimensionnement = (float(getXFinal()) / float(getWin()->getImage()->width()));
//        for (int j = 0; j < getYFinal(); ++j) {
//            for (int i = 0; i < getWin()->getImage()->width(); i+=tauxRedimensionnement) {
//                r1= (QColor(getWin()->getImage()->pixel(j,i)).red());
//                g1= (QColor(getWin()->getImage()->pixel(j,i)).green());
//                b1= (QColor(getWin()->getImage()->pixel(j,i)).blue());
//                final->setPixel(i*tauxRedimensionnement+k,j,qRgb(int(r1+0.5),int(g1+0.5),int(b1+0.5)));
//            }
//        }
//        for (int j = 0; j < getYFinal(); ++j) {
//            for (int i = 0; i < getWin()->getImage()->width(); ++i) {

//                //obtention du premier pixel
//                r1= (QColor(getWin()->getImage()->pixel(i,j)).red());
//                g1= (QColor(getWin()->getImage()->pixel(i,j)).green());
//                b1= (QColor(getWin()->getImage()->pixel(i,j)).blue());

//                //obtention du deuxième pixel
//                r2= (QColor(getWin()->getImage()->pixel(i+1,j)).red());
//                g2= (QColor(getWin()->getImage()->pixel(i+1,j)).green());
//                b2= (QColor(getWin()->getImage()->pixel(i+1,j)).blue());

//                for (int k = 0; k < tauxRedimensionnement; ++k) { //remplissage des nouveaux pixels intermédiares

//                    r1= (((i+1) - (i*tauxRedimensionnement+k)*r1)/tauxRedimensionnement) + (((i*tauxRedimensionnement+k) - i)*r2)/tauxRedimensionnement;
//                    g1= (((i+1) - (i*tauxRedimensionnement+k))*g1)/tauxRedimensionnement + (((i*tauxRedimensionnement+k) - i)*g2)/tauxRedimensionnement;
//                    b1= (((i+1) - (i*tauxRedimensionnement+k))*b1)/tauxRedimensionnement + (((i*tauxRedimensionnement+k) - i)*b2)/tauxRedimensionnement;

//                    r1= r1*( (i*tauxRedimensionnement+tauxRedimensionnement - i*tauxRedimensionnement+k)/tauxRedimensionnement ) + r2*( (i*tauxRedimensionnement+k - i*tauxRedimensionnement)/tauxRedimensionnement );
//                    g1= g1*( (i*tauxRedimensionnement+tauxRedimensionnement - i*tauxRedimensionnement+k)/tauxRedimensionnement ) + g2*( (i*tauxRedimensionnement+k - i*tauxRedimensionnement)/tauxRedimensionnement );
//                    b1= b1*( (i*tauxRedimensionnement+tauxRedimensionnement - i*tauxRedimensionnement+k)/tauxRedimensionnement ) + b2*( (i*tauxRedimensionnement+k - i*tauxRedimensionnement)/tauxRedimensionnement );

//                    r1= r1 + (i*tauxRedimensionnement+k - i)*(r2 - r1)/tauxRedimensionnement;
//                    g1= g1 + (i*tauxRedimensionnement+k - i)*(g2 - g1)/tauxRedimensionnement;
//                    b1= b1 + (i*tauxRedimensionnement+k - i)*(b2 - b1)/tauxRedimensionnement;

//                    r1= r1*((tauxRedimensionnement-k)/tauxRedimensionnement) + r2*((k+tauxRedimensionnement)/tauxRedimensionnement);
//                    g1= g1*((tauxRedimensionnement-k)/tauxRedimensionnement) + g2*((k+tauxRedimensionnement)/tauxRedimensionnement);
//                    b1= b1*((tauxRedimensionnement-k)/tauxRedimensionnement) + b2*((k+tauxRedimensionnement)/tauxRedimensionnement);

//                    r1 = r1 + (r2 - r1)*((i*tauxRedimensionnement+k - i)/tauxRedimensionnement);
//                    g1 = g1 + (g2 - g1)*((i*tauxRedimensionnement+k - i)/tauxRedimensionnement);
//                    b1 = b1 + (b2 - b1)*((i*tauxRedimensionnement+k - i)/tauxRedimensionnement);

//                    final->setPixel(i*tauxRedimensionnement+k,j,qRgb(int(r1+0.5),int(g1+0.5),int(b1+0.5)));
//                }
//            }
//        }
//    }else if(getXFinal() < getWin()->getImage()->width()){ //réduction en largeur
//        tauxRedimensionnement = (float(getWin()->getImage()->width()) / float(getXFinal()));
//        for (int j = 0; j < getYFinal(); ++j) {
//            for (int i = 0; i < getWin()->getImage()->width(); i+=tauxRedimensionnement) {

//                r1= ((QColor(getWin()->getImage()->pixel(i,j)).red()) + (QColor(getWin()->getImage()->pixel(i+1,j)).red()))/2;
//                g1= ((QColor(getWin()->getImage()->pixel(i,j)).green()) + (QColor(getWin()->getImage()->pixel(i+1,j)).green()))/2;
//                b1= ((QColor(getWin()->getImage()->pixel(i,j)).blue()) + (QColor(getWin()->getImage()->pixel(i+1,j)).blue()))/2;

//                final->setPixel(i/tauxRedimensionnement,j,qRgb(int(r1+0.5),int(g1+0.5),int(b1+0.5)));
//            }

//        }
//    }else{

//    }
