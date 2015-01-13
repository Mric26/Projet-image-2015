#ifndef COUPER_H
#define COUPER_H
#include "mainwindow.h"
#include <QMouseEvent>
#include "mygraphicsview.h"

class Couper{

public:
    void couper(MainWindow *w, QPoint d, QPoint f);

};

#endif // COUPER_H
