#include "convolution.h"

QImage *Convolution::conv(QImage *image, int ** matrice, int matWidth, int matHeight){

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

int **Convolution::genererBinomial(int **matrice,  int tailleVoulue, int tailleActuelle){
    if (tailleVoulue == tailleActuelle) {
        std::cout << "matrice générée : "<< std::endl;
        for (int i = 0; i < tailleVoulue; ++i) {
            for (int j = 0; j < tailleVoulue; ++j) {
                std::cout << matrice[i][j] << ' ';
            }
            std::cout << std::endl;
        }
        return matrice;
    }
    else {
        std::cout << "matrice input : "<< std::endl;
        for (int i = 0; i < tailleActuelle; ++i) {
            for (int j = 0; j < tailleActuelle; ++j) {
                std::cout << matrice[i][j] << ' ';
            }
            std::cout << std::endl;
        }
        int base[2][2] = {{1,1},{1,1}};
        std::cout << "matrice base : "<< std::endl;
        for (int i = 0; i < tailleActuelle; ++i) {
            for (int j = 0; j < tailleActuelle; ++j) {
                std::cout << base[i][j] << ' ';
            }
            std::cout << std::endl;
        }
        //Choix arbitraire du centre aux coordonnées 1,1
        int l = 1, c = 1;
        //Initialisation de la nouvelle matrice, plus grande d'une colonne et d'une ligne.
        int nouvTaille = tailleActuelle + 1 ;
        int **nouvMat;
        nouvMat = new int *[nouvTaille];
        //Remplissage de la matrice. Elle est égale à l'ancienne, avec la colonne nouveTaille-1 et la ligne nouvTaille-1 à 0
        for (int i = 0; i < nouvTaille; ++i) {
            nouvMat[i] = new int[nouvTaille];
            for (int j = 0; j < nouvTaille; ++j) {
                nouvMat[i][j] = 0;
            }
        }
        //Agrandissement de la matrice
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

        //Convolution -> ne marche pas :(
        for (int i = 0; i < nouvTaille; ++i) {
            for (int j = 0; j < nouvTaille; ++j) {

                    for (int m = -l; m < l+1; ++m) {
                        for (int n = -c; n < c+1; ++n) {
                            if (i-m > -1 && j-n > -1 && i-m < nouvTaille && j-n < nouvTaille && l> -1 && c > -1 && l< 2 && c < 2) {
                                std::cout << "--nouvMat["<<i<<"]["<<j<<"] = " << nouvMat[i][j] << std::endl;
                                std::cout << "--matricePlusGrande["<<i-m<<"]["<<j-n<<"] = " << matricePlusGrande[i-m][j-n] << std::endl;
                                std::cout << "--base["<<m+l<<"]["<<n+c<<"] = " << base[m+l][n+c] << std::endl;
                                nouvMat[i][j] = nouvMat[i][j] + matricePlusGrande[i-m][j-n] * base[m+l][n+c];
                                std::cout << "--nouvMat["<<i<<"]["<<j<<"] final = " << nouvMat[i][j] << std::endl;
                               std::cout << "---------------------"<< std::endl;
                            } else if (i-m <= -1 && j-n <= -1 && i-m >= nouvTaille && j-n >= nouvTaille && l> -1 && c > -1 && l< 2 && c < 2) {
                                nouvMat[i][j] = nouvMat[i][j] + matricePlusGrande[i-m][j-n] * base[m+l][n+c];
                            }
                        }
                    }
                    nouvMat[i][j] = nouvMat[i][j];
                }
        }

        return genererBinomial(nouvMat,tailleVoulue,nouvTaille);
    }
}
