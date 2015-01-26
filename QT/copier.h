#ifndef COPIER_H
#define COPIER_H

#include "mainwindow.h"

#include <QImage>

class Copier
{
public:
    QImage * copier(MainWindow * w, QPoint d, QPoint f);
};

#endif // COPIER_H
