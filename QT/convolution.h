#ifndef CONVOLUTION_H
#define CONVOLUTION_H
#include <QImage>
#include <QColor>
#include <iostream>
#include "grisconvers.h"

class Convolution
{
public:
    QImage *conv(QImage *image, float **matrice, int tailleMatrice);
    QImage *flouGaussien(QImage *image, int tailleMatriceBinomiale);
    QImage *flouMoy(QImage *image, int tailleMatriceMoy);
    QImage *filtrePasseHaut(QImage *image);
    QImage *filtreRehaussement(QImage *image);
    QImage *detectionContours(QImage *image, float alpha);
    QImage *gradientX(QImage *image, float alpha);
    QImage *gradientY(QImage *image, float alpha);
    QImage *filtreMedian(QImage *image,int tailleVoisinage);

private:
    float **genererBinomial(float **matrice,  int tailleVoulue, int tailleActuelle);
    float **genererBinomial(int tailleVoulue);
    float **genererMoy(int tailleVoulue);
    float **appliquerFacteur(float **matrice, int taille);
};

#endif // CONVOLUTION_H
