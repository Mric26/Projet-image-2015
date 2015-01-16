#include "mygraphicsview.h"

using namespace std;

MyGraphicsView::MyGraphicsView(QWidget *w):QGraphicsView(w){
    rb = NULL;
    setDopipe(false);
}

void MyGraphicsView::mousePressEvent(QMouseEvent *event){
    if(getDopipe()) {
        if(event->button() == Qt::LeftButton){
            if( (event->pos().x() >= (this->width()*0.5 - getWin()->getImage()->width()*0.5)) && (event->pos().x() <= (this->width()*0.5 + getWin()->getImage()->width()*0.5)) && (event->pos().y() >= (this->height()*0.5 - getWin()->getImage()->height()*0.5)) && (event->pos().y() <= (this->height()*0.5 + getWin()->getImage()->height()*0.5))){
                int xCorrectif(this->width()*0.5 - getWin()->getImage()->width()*0.5);
                int yCorrectif(this->height()*0.5 - getWin()->getImage()->height()*0.5);
                setPos(QPoint(event->pos().x() - xCorrectif , event->pos().y() - yCorrectif ));
                setReadRGB(true);
                setDopipe(false); //on a fini d'écouter les actions de la souris
                getWin()->refresh();
            }
            else{
                getWin()->setEmptylabel(true);
                getWin()->refresh();
            }
        }
     }
    else{
        //sinon on autorise la selection
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

void MyGraphicsView::setChecked(bool c){
    checked = c;
}

bool MyGraphicsView::getDopipe() const{
    return dopipe;
}

void MyGraphicsView::setDopipe(bool value){
    dopipe = value;
}

bool MyGraphicsView::getReadRGB() const{
    return readRGB;
}

void MyGraphicsView::setReadRGB(bool value){
    readRGB = value;
}

QPoint MyGraphicsView::getPos() const{
    return pos;
}

void MyGraphicsView::setPos(const QPoint &value){
    pos = value;
}

MainWindow *MyGraphicsView::getWin() const{
    return win;
}

void MyGraphicsView::setWin(MainWindow *value){
    win = value;
}

