#ifndef CONVOLUTION_H
#define CONVOLUTION_H
#include <QImage>
#include <iostream>
#include <QColor>

class Convolution
{
public:
    QImage *conv(QImage *image, int **matrice, int matWidth, int matHeight);
};

#endif // CONVOLUTION_H
