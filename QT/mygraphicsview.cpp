#include "mygraphicsview.h"


MyGraphicsView::MyGraphicsView(QWidget *w):QGraphicsView(w){
    setSelect(false);
    rb = NULL;
    setDopipe(false);
    setReadRGB(true);
}


void MyGraphicsView::mousePressEvent(QMouseEvent *event){
    QGraphicsView::mousePressEvent(event);
    if(getDopipe()) {
        //on veux pipeter
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
        if( event->button() == Qt::RightButton ){
            setDopipe( false );
        }
     }
    else if( select ){
        //on veux faire une selection
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
            foreach (QGraphicsItem* q, this->scene()->items()) {
                q->setSelected(false);
//                q->setActive(false);
            }
            if( rb != NULL){
                delete rb;
                rb = NULL;                
            }
            setSelect( false );
        }
    }
    if( event->button() == Qt::RightButton ){
        foreach (QGraphicsItem* q, this->scene()->items()) {
            q->setSelected(false);
//            q->setActive(false);
        }
    }
}

void MyGraphicsView::mouseMoveEvent(QMouseEvent *event) {
    QGraphicsView::mouseMoveEvent(event);
    if( rb != NULL){
        rb->setGeometry(QRect(getPointD(), event->pos()).normalized());
    }
}

void MyGraphicsView::mouseReleaseEvent(QMouseEvent *event){
    QGraphicsView::mouseReleaseEvent(event);
    if ( rb != NULL ){
        setPointD( this->mapToScene( getPointD() ).toPoint() );
        setPointF( this->mapToScene( event->pos() ).toPoint() );
    }
    //regarde si selection d'item
    QList<QGraphicsItem *> list = this->scene()->items();
    for (int i=0; i<list.length()-1; i++) {
        QGraphicsItem * q = list[i];
        if( itemIsSelected(q) ){           
            q->setSelected(true);
//            q->setActive(true);
            setSelect(false);
            delete rb;
            rb = NULL;
        }
        else{
            q->setSelected(false);
//            q->setActive(false);
        }
    }
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
    if (dopipe == false){
        setCursor(Qt::ArrowCursor);
    }
    else{
        if( rb != NULL ){
            delete rb;
            rb = NULL;
        }
        QPixmap pix(":res/curseurpipette.png");
        setCursor(QCursor(pix));
    }
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

bool MyGraphicsView::getSelect() const{
    return select;
}

void MyGraphicsView::setSelect(bool value){
    select = value;
    if (select == false){
        setCursor(Qt::ArrowCursor);
    }
    else{
        setCursor(Qt::CrossCursor);
    }
}

bool MyGraphicsView::itemIsSelected(QGraphicsItem *q){
    //calcul des bons points et du rectangle de selection
    QPoint *a = new QPoint( qMin(pointD.x(),pointF.x()), qMin(pointD.y(),pointF.y()) );
    QPoint *b = new QPoint( qMax(pointD.x(),pointF.x()), qMax(pointD.y(),pointF.y()) );
    QRectF *selec = new QRectF(*a, *b);
    //calcul rectangle de l'item
    QRectF item = q->boundingRect();
    item.setRect( q->pos().x(), q->pos().y(), item.width(), item.height());
    //regarde si intersection
    if( selec->intersects(item) ){
        return true;
    }
    else{
        return false;
    }
}

MyGraphicsView::~MyGraphicsView() {
    delete rb;
}
