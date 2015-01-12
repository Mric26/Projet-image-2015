#ifndef GRISCONVERS_H
#define GRISCONVERS_H
#include "mainwindow.h"
#include <QImage>
#include <iostream>
#include <QRgb>
#include <QColor>

class GrisConvers
{
public:
    GrisConvers();
    QImage * versGris(MainWindow *w);
};

#endif // GRISCONVERS_H
