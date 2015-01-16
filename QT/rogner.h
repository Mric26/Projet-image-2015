#ifndef ROGNER_H
#define ROGNER_H

#include "mainwindow.h"
#include <QMouseEvent>
#include "mygraphicsview.h"

class Rogner
{
public:
    void rogner( MainWindow *w, QPoint d, QPoint f );
};

#endif // ROGNER_H
