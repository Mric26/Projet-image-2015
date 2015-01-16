#ifndef EGALISATION_H
#define EGALISATION_H

#include <QImage>
#include <vector>
#include <QColor>
#include <QRgb>

class Egalisation
{
public:
    Egalisation();
    QImage * egaler(QImage * im);
};

#endif // EGALISATION_H
