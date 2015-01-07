#include "mygraphicsview.h"

using namespace std;

MyGraphicsView::MyGraphicsView(QWidget *w):QGraphicsView(w){}

void MyGraphicsView::mousePressEvent(QMouseEvent *event){
    if (checked) {
        this->setDragMode(QGraphicsView::RubberBandDrag);
        QGraphicsView::mousePressEvent(event);
        QPoint point = QWidget::mapFromGlobal(QCursor::pos());
        cout << "MGV Init x : " << point.x() << " y : " << point.y() << endl;
    }
    else {
        this->setDragMode(QGraphicsView::NoDrag);
    }

}

void MyGraphicsView::mouseReleaseEvent(QMouseEvent *event){
    if (checked) {
        QPoint point = QWidget::mapFromGlobal(QCursor::pos());
        cout << "MGV End x : " << point.x() << " y : " << point.y() << endl;
        this->setDragMode(QGraphicsView::NoDrag);
    }
}


void MyGraphicsView::setChecked(bool c){
    checked = c;
}
