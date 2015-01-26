#include "egalisation.h"

using namespace std;

Egalisation::Egalisation(){
}

QImage *Egalisation::egaler(QImage *im){

    QImage * image = new QImage(*im);
    int lignes = image->width();
    int colonnes = image->height();

    std::vector<int> courbeRouge;
    std::vector<int> courbeCumul;

    for (int i=0; i<256; ++i){
        courbeRouge.push_back(0);
        courbeCumul.push_back(0);
    }

    //utile pour parcour image
    int val;
    float rouge;

    //construction histo rouge (vert ou bleu sont bon aussi)
    for (int i = 0; i<lignes; ++i){
        for( int j = 0; j<colonnes; ++j){
            rouge = qRed( image->pixel(i,j) );
            ++courbeRouge[(int)rouge];
        }
    }

    //construction histo courbe
    courbeCumul[0] = courbeRouge[0];
    for (int i = 1; i<256; ++i){
        courbeCumul[i] = courbeCumul[i-1] + courbeRouge[i];
    }

    //egalisation sur image
    double nbpixels = lignes * colonnes;
    for (int i = 0; i<lignes; ++i){
        for( int j = 0; j<colonnes; ++j){
            rouge = qRed( image->pixel(i,j) );
            if( (int)rouge != 0 ){
                //calcul pourcentage de pixel plus petit que la valeur du pixel courant
                double pourc = courbeCumul[(int)rouge - 1] / nbpixels;
                val = 255 * pourc;
                image->setPixel( i, j, qRgb( val, val, val) );
            }
        }
    }

    return image;

}
