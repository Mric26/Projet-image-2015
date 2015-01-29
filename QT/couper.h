#ifndef COUPER_H
#define COUPER_H

#include <QMouseEvent>
#include <QImage>

#include "mainwindow.h"
#include "mygraphicsview.h"

class Couper{

public:
    void couper(MainWindow *w, QPoint d, QPoint f);

};

#endif // COUPER_H
