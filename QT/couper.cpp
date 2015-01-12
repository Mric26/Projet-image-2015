#include "couper.h"

void Couper::couper(MainWindow * w, MyGraphicsView * g, QPoint d, QPoint f){

    //calcul des bons points
    QPoint *a = new QPoint( qMin(d.x(),f.x()), qMin(d.y(),f.y()) );
    QPoint *b = new QPoint( qMax(d.x(),f.x()), qMax(d.y(),f.y()) );

    //calcul de l'origine de l'image
    int mw = qMax( qRound(w->getScene()->width()) , g->width() );
    int mh = qMax( qRound(w->getScene()->height()) , g->height() );
    int posx = (mw /2)  - (w->getImage()->width() / 2);
    int posy = (mh /2) - (w->getImage()->height() / 2);

    //calcul du point en bas a droite de l'image
    int pos2x = posx + w->getImage()->width();
    int pos2y = posy + w->getImage()->height();

    //positionnement des points dans l'image
    a->setX( qMax(a->x(), posx) );
    a->setY( qMax(a->y(), posy) );
    b->setX( qMin(b->x(), pos2x) );
    b->setY( qMin(b->y(), pos2y) );

    //calcul taille nouvelle image
    int wi = b->x() - a->x();
    int he = b->y() - a->y();

    QPoint* pos = new QPoint(posx, posy);

    QImage * im = new QImage();
    *im =  w->getImage()->copy( a->x()-pos->x(), a->y()-pos->y(), wi, he );
    w->setImage( im, w->getCheminImage() );

}
