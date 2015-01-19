#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QRubberBand>
#include <iostream>

#include "mainwindow.h"

class MyGraphicsView : public QGraphicsView
{
public:
    MyGraphicsView(QWidget * w);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    QPoint getPointD() const;
    void setPointD(const QPoint &value);

    QPoint getPointF() const;
    void setPointF(const QPoint &value);

    QRubberBand *getRb() const;
    void setRb(QRubberBand *value);

    void setChecked(bool c);

    bool getDopipe() const;
    void setDopipe(bool value);

    bool getReadRGB() const;
    void setReadRGB(bool value);

    QPoint getPos() const;
    void setPos(const QPoint &value);

    MainWindow *getWin() const;
    void setWin(MainWindow *value);

    bool getSelect() const;
    void setSelect(bool value);

private:
    QPoint pointD;
    QPoint pointF;
    QRubberBand *rb;
    bool checked;
    bool dopipe;
    bool readRGB;
    bool select;
    QPoint pos;
    MainWindow *win;
};

#endif // MYGRAPHICSVIEW_H
