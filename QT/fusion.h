#ifndef FUSION_H
#define FUSION_H

#include <QWidget>
#include "mainwindow.h"
#include <QGraphicsPixmapItem>
#include <QFileDialog>
#include <QPixmap>
#include <iostream>

class Fusion :QWidget
{
public:
    Fusion();
    void fusionner(MainWindow *w);
};

#endif // FUSION_H
