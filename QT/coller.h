#ifndef COLLER_H
#define COLLER_H

#include <QGraphicsPathItem>
#include "mainwindow.h""

class Coller
{
public:
    QGraphicsPixmapItem * coller(MainWindow * w, QPoint d, QPoint f);
};

#endif // COLLER_H