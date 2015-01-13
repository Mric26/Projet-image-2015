#ifndef CONVOLUTION_H
#define CONVOLUTION_H
#include <QImage>
#include <iostream>
#include <QColor>

class Convolution
{
public:
    QImage *conv(QImage *image, float **matrice, int tailleMatrice);
    QImage *flouGaussien(QImage *image, int tailleMatriceBinomiale);
    QImage *flouMoy(QImage *image, int tailleMatriceMoy);
    QImage *filtrePasseHaut(QImage *image);
    QImage *filtreRehaussement(QImage *image);
private:
    float **genererBinomial(float **matrice,  int tailleVoulue, int tailleActuelle);
    float **genererBinomial(int tailleVoulue);
    float **genererMoy(int tailleVoulue);
};

#endif // CONVOLUTION_H
