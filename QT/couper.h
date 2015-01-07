#ifndef COUPER_H
#define COUPER_H
#include <QGraphicsView>
#include <QMouseEvent>
#include <iostream>

class Couper{

public:
    void couper( QGraphicsView * g );
    void mousePressEvent(QMouseEvent *event);

};

#endif // COUPER_H
