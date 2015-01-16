#include "convolution.h"

QImage *Convolution::conv(QImage *image, float ** matrice, int tailleMatrice){

    int imWidth = image->width();
    int imHeight = image->height();
    int l = (tailleMatrice -1)/2;
    int c = (tailleMatrice -1)/2;

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
                         bleu = bleu + matrice[m+c][n+l] * qBlue(couleurPix);
                         rouge = rouge + matrice[m+c][n+l] * qRed(couleurPix);
                         vert = vert + matrice[m+c][n+l] * qGreen(couleurPix);
                    }
                }
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
                 nouvelleImage->setPixel(i,j,qRgb(int(rouge + 0.5), int(vert + 0.5), int(bleu + 0.5)));
            }
    }
    return nouvelleImage;
}

QImage *Convolution::flouGaussien(QImage *image, int tailleMatriceBinomiale){
    return conv(image,genererBinomial(tailleMatriceBinomiale),tailleMatriceBinomiale);
}

QImage *Convolution::flouMoy(QImage *image, int tailleMatriceMoy){
    return conv(image,genererMoy(tailleMatriceMoy),tailleMatriceMoy);
}

QImage *Convolution::filtrePasseHaut(QImage *image){
    float **matPasseHaut;
    matPasseHaut = new float *[3];

    for (int i = 0; i < 3; ++i) {
        matPasseHaut[i] = new float[3];
    }

    matPasseHaut[0][0] = 1.0;
    matPasseHaut[0][1] = 2.0;
    matPasseHaut[0][2] = 1.0;
    matPasseHaut[1][0] = 2.0;
    matPasseHaut[1][1] = -12.0;
    matPasseHaut[1][2] = 2.0;
    matPasseHaut[2][0] = 1.0;
    matPasseHaut[2][1] = 2.0;
    matPasseHaut[2][2] = 1.0;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
        }
    }

    return conv(image,matPasseHaut,3);
}

QImage *Convolution::filtreRehaussement(QImage *image){
    //Calcul de (1-alpha)*d
    float **d;
    d = new float *[3];

    for (int i = 0; i < 3; ++i) {
        d[i] = new float[3];
        for (int j = 0; j < 3; ++j) {
            d[i][j] = 0;
        }
    }
    //alpha totalement arbitraire, de manière a avoir un résultat plus fin
    int alpha = 16;
    d[1][1] = 1+alpha;

    //Calcul de alpha*KPB
    float **passeBas = genererBinomial(3);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            passeBas[i][j] = alpha * passeBas[i][j];
        }
    }

    //Calcul de KR
    float **rehauss;
    rehauss = new float *[3];

    for (int i = 0; i < 3; ++i) {
        rehauss[i] = new float[3];
        for (int j = 0; j < 3; ++j) {
           rehauss[i][j] = d[i][j]-passeBas[i][j];
        }
    }
    delete d;
    delete passeBas;
    return conv(image,rehauss,3);
}

QImage *Convolution::detectionContours(QImage *image)
{

    QImage *res = new QImage(image->width(),image->height(),image->format());
    QImage * sobelX = gradientX(image);
    QImage * sobelY = gradientY(image);

    for (int i = 0; i < image->width(); ++i) {
        for (int j = 0; j < image->height(); ++j) {
            QRgb norm = sobelX->pixel(i,j)+sobelY->pixel(i,j);
            float bleu = qBlue(norm);
            float vert = qGreen(norm);
            float rouge = qRed(norm);

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


            res->setPixel(i,j,qRgb(int(bleu+0.5),int(vert+0.5),(rouge+0.5)));
        }
    }

    return res;
}

QImage *Convolution::gradientX(QImage *image){
    float **sobelX;
    sobelX = new float *[3];

    for (int i = 0; i < 3; ++i) {
        sobelX[i] = new float[3];
    }

    sobelX[0][0] = 1.0/0.5;
    sobelX[0][1] = 0.0/0.5;
    sobelX[0][2] = -1.0/0.5;
    sobelX[1][0] = 2.0/0.5;
    sobelX[1][1] = 0.0/0.5;
    sobelX[1][2] = -2.0/0.5;
    sobelX[2][0] = 1.0/0.5;
    sobelX[2][1] = 0.0/0.5;
    sobelX[2][2] = -1.0/0.5;

    return conv(image,sobelX,3);
}

QImage *Convolution::gradientY(QImage *image){
    float **sobelY;
    sobelY = new float *[3];

    for (int i = 0; i < 3; ++i) {
        sobelY[i] = new float[3];
    }

    sobelY[0][0] = 1.0/0.5 ;
    sobelY[0][1] = 2.0/0.5 ;
    sobelY[0][2] = 1.0/0.5 ;
    sobelY[1][0] = 0.0/0.5 ;
    sobelY[1][1] = 0.0/0.5 ;
    sobelY[1][2] = 0.0/0.5 ;
    sobelY[2][0] = -1.0/0.5 ;
    sobelY[2][1] = -2.0/0.5 ;
    sobelY[2][2] = -1.0/0.5 ;

    return conv(image,sobelY,3);
}

QImage *Convolution::filtreMedian(QImage *image, int tailleVoisinage){  
    int nv = (2*tailleVoisinage +1)*(2*tailleVoisinage +1);
    QImage *resultat = new QImage(image->width(),image->height(),image->format());
    int l = (2*tailleVoisinage +1 -1)/2;
    int c = (2*tailleVoisinage +1 -1)/2;

    for (int i = 0; i < image->width(); ++i) {
        for (int j = 0; j < image->height(); ++j) {
            //Récupération des valeurs du voisinage du pixel (i,j)
            int valeurs[nv];
            for (int m = -l; m < l+1; ++m) {
                for (int n  = -c; n < c+1; ++n) {
                    if (i-m > -1 && i-m< image->width() && j-n > -1 && j-n< image->height()) {
                        valeurs[(m+1)*(2*tailleVoisinage+1)+(n+1)] = qGray(image->pixel(i-m,j-n));
                    }else {
                        valeurs[(m+1)*(2*tailleVoisinage+1)+(n+1)] = qGray(image->pixel(i,j));
                    }

                }
            }
            //Tri de ces valeurs pour trouver la médiane
            int temp;
            for (int k = nv-1; k >= 0; --k) {
                for (int k2 = 0; k2 < k; ++k2) {
                    if (valeurs[k2] > valeurs[k2+1]) {
                        temp = valeurs[k2];
                        valeurs[k2] = valeurs[k2+1];
                        valeurs[k2+1] = temp;
                    }
                }
            }
            int mediane = valeurs[(nv+1)/2];
            resultat->setPixel(i,j,qRgb(mediane,mediane,mediane));
        }
    }

    return resultat;
}

float **Convolution::genererBinomial(float **matrice,  int tailleVoulue, int tailleActuelle){
    if (tailleVoulue == tailleActuelle) {
        return appliquerFacteur(matrice,tailleVoulue);
    }
    else {
        float base[2][2] = {{1.0,1.0},{1.0,1.0}};
        //Choix arbitraire du centre aux coordonnées 1,1

        //Initialisation de la nouvelle matrice, plus grande d'une colonne et d'une ligne.
        int nouvTaille = tailleActuelle + 1 ;
        float **nouvMat;
        nouvMat = new float *[nouvTaille];
        //Remplissage de la matrice résultat avec des 0
        for (int i = 0; i < nouvTaille; ++i) {
            nouvMat[i] = new float[nouvTaille];
            for (int j = 0; j < nouvTaille; ++j) {
                nouvMat[i][j] = 0;
            }
        }
        //Agrandissement de la matrice en input
        float **matricePlusGrande;
        matricePlusGrande = new float *[nouvTaille];
        for (int i = 0; i < nouvTaille; ++i) {
             matricePlusGrande[i] = new float[nouvTaille];
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
        delete matrice;
        delete matricePlusGrande;
        return genererBinomial(nouvMat,tailleVoulue,nouvTaille);
    }
}

float **Convolution::genererBinomial(int tailleVoulue){
    float **base;
    base = new float *[2];
    //Création d'une matrice de base
    for (int i = 0; i < 2; ++i) {
        base[i] = new float[2];
        for (int j = 0; j < 2; ++j) {
            base[i][j] = 1;
        }
    }

    return genererBinomial(base,tailleVoulue,2);
}

float **Convolution::genererMoy(int tailleVoulue){
    float **mat;
    mat = new float *[tailleVoulue];
    for (int i = 0; i < tailleVoulue; ++i) {
        mat[i] = new float[tailleVoulue];
        for (int j = 0; j < tailleVoulue; ++j) {
            mat[i][j] = 1.0;
        }
    }
    return appliquerFacteur(mat,tailleVoulue);
}

float **Convolution::appliquerFacteur(float **matrice, int taille){
    float somme = 0.0;
    for (int i = 0; i < taille; ++i) {
        for (int j = 0; j < taille; ++j) {
            somme = somme + matrice[i][j];
        }
    }

    for (int i = 0; i < taille; ++i) {
        for (int j = 0; j < taille; ++j) {
            matrice[i][j] = matrice[i][j]/somme;
        }
    }

    return matrice;
}

float **Convolution::conv2(QImage *image, float **matrice, int tailleMatrice){
    int imWidth = image->width();
    int imHeight = image->height();
    int l = (tailleMatrice -1)/2;
    int c = (tailleMatrice -1)/2;

    float bleu = 0;
    float rouge = 0;
    float vert = 0;
    QRgb couleurPix;

    float **nouvelleImage;
    nouvelleImage = new float *[image->width()];
    for (int i = 0; i < imWidth; ++i) {
        nouvelleImage[i] = new float[image->height()];
        for (int j = 0; j < imHeight; ++j) {
            nouvelleImage[i][j] = 0.0;
        }
    }

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
                         bleu = bleu + matrice[m+c][n+l] * qBlue(couleurPix);
                         rouge = rouge + matrice[m+c][n+l] * qRed(couleurPix);
                         vert = vert + matrice[m+c][n+l] * qGreen(couleurPix);
                    }
                }
                 nouvelleImage[i][j] = qRgb(int(rouge + 0.5), int(vert + 0.5), int(bleu + 0.5));
            }
    }
    return nouvelleImage;
}
