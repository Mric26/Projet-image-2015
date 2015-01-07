#include "couper.h"

using namespace std;

void Couper::couper(QGraphicsView * g){
    g->setDragMode(QGraphicsView::RubberBandDrag);
}

void Couper::mousePressEvent(QMouseEvent *event) {
    if (event->MouseButtonPress ) {
        cout << "Clique de départ" << endl;
    }
    if (event->MouseButtonRelease ) {
        cout << "Clique de d'arrivée" << endl;
    }
}
