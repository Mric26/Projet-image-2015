#ifndef COLLER_H
#define COLLER_H

#include <QGraphicsPathItem>
#include <QImage>
#include <QPixmap>

#include "mainwindow.h"

class Coller
{
public:
    void coller(MainWindow *w , QImage im);
};

#endif // COLLER_H
