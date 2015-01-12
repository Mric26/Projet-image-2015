#include "mygraphicsview.h"

MyGraphicsView::MyGraphicsView(QWidget *w):QGraphicsView(w){
    rb = NULL;
}

void MyGraphicsView::mousePressEvent(QMouseEvent *event){
    if( event->button() == Qt::LeftButton ){
        setPointD(event->pos());
        if( rb == NULL ){
            rb = new QRubberBand(QRubberBand::Rectangle, this);
        }
        else{
            delete rb;
            rb = new QRubberBand(QRubberBand::Rectangle, this);
        }
        rb->setGeometry(QRect(getPointD(),QSize()));
        rb->show();
    }
    if( event->button() == Qt::RightButton ){
        if( rb != NULL){
            delete rb;
            rb = NULL;
        }
    }
}

void MyGraphicsView::mouseMoveEvent(QMouseEvent *event) {
    if( rb != NULL){
        rb->setGeometry(QRect(getPointD(), event->pos()).normalized());
    }
}

void MyGraphicsView::mouseReleaseEvent(QMouseEvent *event){
    setPointD( this->mapToScene( getPointD() ).toPoint() );
    setPointF( this->mapToScene( event->pos() ).toPoint() );
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

QRubberBand *MyGraphicsView::getRb() const{
    return rb;
}

void MyGraphicsView::setRb(QRubberBand *value){
    rb = value;
}



