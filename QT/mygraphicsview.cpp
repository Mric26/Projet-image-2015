#include "mygraphicsview.h"

using namespace std;

MyGraphicsView::MyGraphicsView(QWidget *w):QGraphicsView(w){}

void MyGraphicsView::mousePressEvent(QMouseEvent *event){
    this->setDragMode(QGraphicsView::RubberBandDrag);
    QGraphicsView::mousePressEvent(event);
    QPoint point = QWidget::mapFromGlobal(QCursor::pos());
    cout << "MGV Init x : " << point.x() << " y : " << point.y() << endl;
}

void MyGraphicsView::mouseReleaseEvent(QMouseEvent *event){
    QPoint point = QWidget::mapFromGlobal(QCursor::pos());
    cout << "MGV End x : " << point.x() << " y : " << point.y() << endl;
    this->setDragMode(QGraphicsView::NoDrag);
}
