#ifndef FUSIONCALQUES_H
#define FUSIONCALQUES_H

#include <QGraphicsItem>
#include <QImage>
#include <QVector>

#include "contraste.h"

class FusionCalques
{
public:
    QImage *fusionCalques(QList<QGraphicsItem *> list, QImage *im );
};

#endif // FUSIONCALQUES_H
