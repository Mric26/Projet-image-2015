#include "histogrammes.h"

using namespace std;

Histogrammes::Histogrammes() :
    QDialog(),
    v(),
    s()
{
    v = new QGraphicsView();
    s = new QGraphicsScene(5,5,300,300);
    v->setScene(s);
    this->setVisible(true);
}

Histogrammes::~Histogrammes(){
    delete s;
    delete v;
}

void Histogrammes::afficher(){
    s->addLine(5,5,5,260);
    s->addLine(5,5,260,5);
    this->show();
}

QGraphicsView *Histogrammes::getV(){
    return v;
}

void Histogrammes::setV(QGraphicsView * value){
    v = value;
}

QGraphicsScene *Histogrammes::getS(){
    return s;
}

void Histogrammes::setS(QGraphicsScene * value){
    s = value;
}
