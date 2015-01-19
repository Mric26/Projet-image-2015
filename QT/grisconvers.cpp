#include "grisconvers.h"

using namespace std;

GrisConvers::GrisConvers(){
}

QImage * GrisConvers::versGris( MainWindow * w ){

    QImage * i = w->getImage();
    float rouge;
    float vert;
    float bleu;
    float gris;
    QImage * ret = new QImage( i->width(), i->height(), i->format());
    for(int j=0; j<i->width(); j++){
        for(int k=0; k<i->height(); k++){

            QRgb * pix = new QRgb( i->pixel(j,k) );
            QColor c( *pix );
            rouge = c.red();
            vert = c.green();
            bleu = c.blue();

            gris = 0.299*rouge + 0.587*vert + 0.114*bleu;

            ret->setPixel( QPoint(j,k), qRgb(gris,gris,gris) );
        }
    }
    return ret;
}
