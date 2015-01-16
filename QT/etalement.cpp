#include "etalement.h"

Etalement::Etalement(){
}

QImage * Etalement::etaler( QImage * im ){

    QImage * image = im;

    float vMinR = 255;
    float vMinV = 255;
    float vMinB = 255;
    float vMaxR = 0;
    float vMaxV = 0;
    float vMaxB = 0;
    int lignes = image->width();
    int colonnes = image->height();
    QRgb * pix;
    double valR, valB, valV;

    //v0 et v1 correspondent au debut et a la fin de la zone non nulle
    for (int i = 0; i<lignes; ++i){
        for( int j = 0; j<colonnes; ++j){
            pix = new QRgb( image->pixel(i,j) );
            QColor c( *pix );
            valR = c.red();
            valB = c.blue();
            valV = c.green();
            if( vMinR > valR ){
                vMinR = valR;
            }
            if( vMinB > valB ){
                vMinB = valB;
            }
            if( vMinV > valV ){
                vMinV = valV;
            }
            if( vMaxR < valR ){
                vMaxR = valR;
            }
            if( vMaxB < valB ){
                vMaxB = valB;
            }
            if( vMaxV < valV ){
                vMaxV = valV;
            }
        }
    }

    //modif image
    for (int i = 0; i<lignes; ++i){
        for( int j = 0; j<colonnes; ++j){
            pix = new QRgb( image->pixel(i,j) );
            QColor c( *pix );
            valR = c.red();
            valB = c.blue();
            valV = c.green();
            valR = 255*(valR-vMinR)/(vMaxR-vMinR);
            valV = 255*(valV-vMinV)/(vMaxV-vMinV);
            valB = 255*(valB-vMinB)/(vMaxB-vMinB);
            if( valR > 255){
                valR = 255;
            }
            else if( valR < 0){
                valR = 0;
            }
            else if( valV > 255){
                valV = 255;
            }
            else if( valV < 0){
                valV = 0;
            }
            else if( valB > 255){
                valB = 255;
            }
            else if( valB < 0){
                valB = 0;
            }
            image->setPixel( i, j, qRgb( valR, valV, valB) );
        }
    }

    return image;
}

