#ifndef ETALEMENT_H
#define ETALEMENT_H

#include <QImage>
#include <QColor>

class Etalement
{
public:
    Etalement();
    QImage * etaler(QImage * im);
};

#endif // ETALEMENT_H
