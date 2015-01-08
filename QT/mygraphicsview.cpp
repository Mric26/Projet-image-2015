#include "mygraphicsview.h"
#include "couper.h"

using namespace std;

MyGraphicsView::MyGraphicsView(QWidget *w):QGraphicsView(w){
    //rb = new QRubberBand(QRubberBand::Rectangle, this);
}

void MyGraphicsView::mousePressEvent(QMouseEvent *event){
    setPointD(event->pos());
    rb = new QRubberBand(QRubberBand::Rectangle, this);
    rb->setGeometry(QRect(getPointD(),QSize()));
    rb->show();
}

void MyGraphicsView::mouseMoveEvent(QMouseEvent *event) {
    rb->setGeometry(QRect(getPointD(), event->pos()).normalized());
}

void MyGraphicsView::mouseReleaseEvent(QMouseEvent *event){
    setPointF(event->pos());
}

QPoint MyGraphicsView::getPointD() const{
    return pointD;
}

void MyGraphicsView::setPointD(const QPoint &value){
    pointD = value;
}

QPoint MyGraphicsView::getPointF() const{
    return pointF;
}

void MyGraphicsView::setPointF(const QPoint &value){
    pointF = value;
}
QRubberBand *MyGraphicsView::getRb() const
{
    return rb;
}

void MyGraphicsView::setRb(QRubberBand *value)
{
    rb = value;
}



