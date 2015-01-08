#include "convolution.h"


QImage *Convolution::conv(QImage *image, int ** matrice, int matWidth, int matHeight)
{

    int imWidth = image->width();
    int imHeight = image->height();
    int l = (matWidth -1)/2;
    int c = (matHeight -1)/2;

    //Calcul du coeff du noyau
    int somme = 0;
    for (int var = 0; var < matWidth; ++var) {
        for (int var2 = 0; var2 < matHeight; ++var2) {
            somme = somme + matrice[var][var2];
        }
    }

    float bleu = 0;
    float rouge = 0;
    float vert = 0;
    QRgb couleurPix;

    QImage *nouvelleImage = new QImage(imWidth, imHeight, image->format() );
    for (int i = 0; i < imWidth; ++i) {
        for (int j = 0; j < imHeight; ++j) {
                bleu = 0;
                rouge = 0;
                vert = 0;
                for (int m = -l; m < l+1; ++m) {
                    for (int n = -c; n < c+1; ++n) {
                        if (i-m > -1 && j-n > -1 && i-m < imWidth && j-n < imHeight) {
                            couleurPix = image->pixel(i-m,j-n);
                        }else {
                            couleurPix = image->pixel(i,j);
                        }


                         bleu = bleu + (float) matrice[m+c][n+l] * qBlue(couleurPix);
                         rouge = rouge + (float) matrice[m+c][n+l] * qRed(couleurPix);
                         vert = vert +  (float) matrice[m+c][n+l] * qGreen(couleurPix);

                    }
                }
                rouge = rouge/somme;
                bleu = bleu/somme;
                vert = vert/somme;
                if (bleu >255) {
                     bleu = 255;
                 }
                else if (bleu < 0) {
                     bleu = 0;
                }
                 if (vert >255) {
                      vert = 255;
                  }
                 else if (vert < 0) {
                      vert = 0;
                 }
                 if (rouge >255) {
                      rouge = 255;
                  }
                 else if (rouge < 0) {
                      rouge = 0;
                 }
//                 std::cout << "nouvelles couleurs" << qRgb(rouge, vert, bleu) << std::endl;
                 nouvelleImage->setPixel(i,j,qRgb(int(rouge + 0.5), int(vert + 0.5), int(bleu + 0.5)));
            }
    }
//    std::cout << "Done" << std::endl;
    return nouvelleImage;
}
