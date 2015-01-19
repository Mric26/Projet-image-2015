#include "coller.h"

QGraphicsPixmapItem * Coller::coller(MainWindow * w, QPoint d, QPoint f){

    //calcul des bons points
    QPoint *a = new QPoint( qMin(d.x(),f.x()), qMin(d.y(),f.y()) );
    QPoint *b = new QPoint( qMax(d.x(),f.x()), qMax(d.y(),f.y()) );

    //positionnement des points dans l'image
    a->setX( qMax(a->x(), 0) );
    a->setY( qMax(a->y(), 0) );
    b->setX( qMin(b->x(), w->getImage()->width()) );
    b->setY( qMin(b->y(), w->getImage()->height()) );

    QImage * im = w->getImage();

    //decoupe de la zone
    for( int i = a->x(); i < b->x(); i++ ){
        for( int j = a->y(); j < b->y(); j++ ){
            im->setPixel(i, j, qRgb(255, 255, 255) );
        }
    }

    QGraphicsPixmapItem * coller = new QGraphicsPixmapItem();
    return coller;

}
