#ifndef HISTOGRAMMES_H
#define HISTOGRAMMES_H

#include <QDialog>
#include <iostream>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QtCore>
#include <QtGui>

class Histogrammes : QDialog
{
public:
    Histogrammes();
    ~Histogrammes();
    void afficher();

    QGraphicsView * getV();
    void setV(QGraphicsView *value);

    QGraphicsScene * getS();
    void setS(QGraphicsScene *value);

private:
    QGraphicsView * v;
    QGraphicsScene * s;

};

#endif // HISTOGRAMMES_H
