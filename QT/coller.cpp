#include "coller.h"
#include <iostream>

void Coller::coller( MainWindow * w, QImage im ){

    //changement format
    QPixmap * pixmap = new QPixmap( im.width(), im.height() );
    pixmap->convertFromImage( im );
    QGraphicsPixmapItem * coller;

    coller = w->getScene()->addPixmap(*pixmap);
    coller->setFlag(QGraphicsItem::ItemIsSelectable);
    coller->setFlag(QGraphicsItem::ItemIsMovable);
    coller->setFlag(QGraphicsItem::ItemIsFocusable);

}
