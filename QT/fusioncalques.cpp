#include "fusioncalques.h"

QImage * FusionCalques::fusionCalques(QList<QGraphicsItem *> list, QImage * im){

    //copie image
    QImage * image = new QImage(*im);

    //variable
    QPoint origine;
    int w;
    int h;
    QGraphicsItem * it;
    QGraphicsPixmapItem * it2;
    QPixmap map;
    QImage item;
    float nivFusion, r, g, b, alpha;

    //récupération du niveau de transparence
    Contraste *fenetre = new Contraste;
    fenetre->show();
    fenetre->activateWindow();
    fenetre->exec();
    if( fenetre->getCanceled() ){
        fenetre->close();
        return NULL;
    }
    else{
        nivFusion= fenetre->getValue();
        nivFusion= nivFusion/100.0;
    }

    //insertion
    for( int i=0; i<list.size(); i++){
        it = list[i];

        origine = it->pos().toPoint();
        w = it->boundingRect().width();
        h = it->boundingRect().height();
        if( it->type() == 7 ){
            it2 = (QGraphicsPixmapItem *)it;
        }
        else{
            return NULL;
        }
        map = it2->pixmap();
        item = map.toImage();

        for (int j = origine.y(); j < origine.y()+h-1; ++j) {
            for (int i = origine.x(); i < origine.x()+w-1; ++i) {
                r = QColor(item.pixel(i-origine.x(),j-origine.y())).red()*(nivFusion) + (QColor(image->pixel(i,j)).red()*(1-nivFusion));
                g = QColor(item.pixel(i-origine.x(),j-origine.y())).green()*(nivFusion) + (QColor(image->pixel(i,j)).green()*(1-nivFusion));
                b = QColor(item.pixel(i-origine.x(),j-origine.y())).blue()*(nivFusion) + (QColor(image->pixel(i,j)).blue()*(1-nivFusion));
                alpha = QColor(item.pixel(i-origine.x(),j-origine.y())).alpha()*(nivFusion) + (QColor(image->pixel(i,j)).alpha()*(1-nivFusion));
                image->setPixel(i,j,qRgba(int(r+0.5),int(g+0.5),int(b+0.5),int(alpha+0.5)));
            }
        }
    }

    return image;
}
