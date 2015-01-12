#include "convolution.h"

QImage *Convolution::conv(QImage *image, int ** matrice, int tailleMatrice){

    int imWidth = image->width();
    int imHeight = image->height();
    int l = (tailleMatrice -1)/2;
    int c = (tailleMatrice -1)/2;

    //Calcul du coeff du noyau
    int somme = 0;
    for (int var = 0; var < tailleMatrice; ++var) {
        for (int var2 = 0; var2 < tailleMatrice; ++var2) {
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

int **Convolution::genererBinomial(int **matrice,  int tailleVoulue, int tailleActuelle){
    if (tailleVoulue == tailleActuelle) {
        return matrice;
    }
    else {
        int base[2][2] = {{1,1},{1,1}};
        //Choix arbitraire du centre aux coordonnées 1,1

        //Initialisation de la nouvelle matrice, plus grande d'une colonne et d'une ligne.
        int nouvTaille = tailleActuelle + 1 ;
        int **nouvMat;
        nouvMat = new int *[nouvTaille];
        //Remplissage de la matrice résultat avec des 0
        for (int i = 0; i < nouvTaille; ++i) {
            nouvMat[i] = new int[nouvTaille];
            for (int j = 0; j < nouvTaille; ++j) {
                nouvMat[i][j] = 0;
            }
        }
        //Agrandissement de la matrice en input
        int **matricePlusGrande;
        matricePlusGrande = new int *[nouvTaille];
        for (int i = 0; i < nouvTaille; ++i) {
             matricePlusGrande[i] = new int[nouvTaille];
            for (int j = 0; j < nouvTaille; ++j) {
                if (i == nouvTaille-1 || j == nouvTaille-1) {
                    matricePlusGrande[i][j] = 0;
                }else {
                    matricePlusGrande[i][j] = matrice[i][j];
                }
            }
        }

        //Convolution
        for (int i = 0; i < nouvTaille; ++i) {
            for (int j = 0; j < nouvTaille; ++j) {
                    for (int m = 0; m < 2; ++m) {
                        for (int n = 0; n < 2; ++n) {
                            int i2 = i+m-1;
                            int j2 = j+n-1;

                            if (i2 > -1 && j2 > -1 && i2 < nouvTaille && j2 < nouvTaille) {
                                nouvMat[i][j] = nouvMat[i][j] + matricePlusGrande[i2][j2] * base[2-1-m][2-1-n];
                            }
                        }
                    }
                }
        }

        return genererBinomial(nouvMat,tailleVoulue,nouvTaille);
    }
}

int **Convolution::genererBinomial(int tailleVoulue)
{
    int **base;
    base = new int *[2];
    //Création d'une matrice de base
    for (int i = 0; i < 2; ++i) {
        base[i] = new int[2];
        for (int j = 0; j < 2; ++j) {
            base[i][j] = 1;
        }
    }

    return genererBinomial(base,tailleVoulue,2);
}
