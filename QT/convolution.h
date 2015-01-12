#ifndef CONVOLUTION_H
#define CONVOLUTION_H
#include <QImage>
#include <iostream>
#include <QColor>

class Convolution
{
public:
    QImage *conv(QImage *image, int **matrice, int tailleMatrice);
    QImage *flouGaussien(QImage *image, int tailleMatriceBinomiale);
    QImage *flouMoy(QImage *image, int tailleMatriceBinomiale);
    QImage *filtrePasseHaut(QImage *image);
private:
    int **genererBinomial(int **matrice,  int tailleVoulue, int tailleActuelle);
    int **genererBinomial(int tailleVoulue);
};

#endif // CONVOLUTION_H
