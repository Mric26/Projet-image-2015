#include "coller.h"

void Coller::coller(MainWindow * w, QPoint d, QPoint f){

    //calcul des bons points
    QPoint *a = new QPoint( qMin(d.x(),f.x()), qMin(d.y(),f.y()) );
    QPoint *b = new QPoint( qMax(d.x(),f.x()), qMax(d.y(),f.y()) );

    //positionnement des points dans l'image
    a->setX( qMax(a->x(), 0) );
    a->setY( qMax(a->y(), 0) );
    b->setX( qMin(b->x(), w->getImage()->width()) );
    b->setY( qMin(b->y(), w->getImage()->height()) );

    //calcul taille nouvelle image
    int wi = b->x() - a->x();
    int he = b->y() - a->y();

    //copy portion image
    QImage * im = new QImage();
    *im =  w->getImage()->copy( a->x(), a->y(), wi, he );

    //changement format
    QPixmap * pixmap = new QPixmap( im->width(), im->height() );
    pixmap->convertFromImage( *im );
    QGraphicsPixmapItem * coller = new QGraphicsPixmapItem( *pixmap );

//    w->getScene()->addItem(coller);
    coller->setFlag(QGraphicsItem::ItemIsSelectable);
    coller->setFlag(QGraphicsItem::ItemIsMovable);
    coller->setFlag(QGraphicsItem::ItemIsFocusable);
    coller->show();

}
