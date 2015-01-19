#ifndef FUSION_H
#define FUSION_H

#include <QWidget>
#include "mainwindow.h"
#include <QGraphicsPixmapItem>
#include <QFileDialog>
#include <QPixmap>

class Fusion :QWidget
{
public:
    void fusionner(MainWindow *w);
};

#endif // FUSION_H
