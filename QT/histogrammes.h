#ifndef HISTOGRAMMES_H
#define HISTOGRAMMES_H
#include <QWidget>
#include <QPushButton>
#include "mainwindow.h"

class Histogrammes : QWidget
{
public:
    Histogrammes();
    void afficher(MainWindow *w);
};

#endif // HISTOGRAMMES_H
