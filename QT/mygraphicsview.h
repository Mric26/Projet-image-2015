#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H
#include <iostream>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QRubberBand>


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

private:
    QPoint pointD;
    QPoint pointF;
    QRubberBand *rb;
};

#endif // MYGRAPHICSVIEW_H
