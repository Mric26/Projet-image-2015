#ifndef COUPER_H
#define COUPER_H
#include "mainwindow.h"
#include <QMouseEvent>
#include <iostream>
#include "mygraphicsview.h"

class Couper{

public:
    void couper(MainWindow *w, MyGraphicsView *q, QPoint d, QPoint f);

};

#endif // COUPER_H
