#include "histogrammes.h"
#include <iostream>

using namespace std;

Histogrammes::Histogrammes() : QWidget() {
}

void Histogrammes::afficher(MainWindow * w){
    cout << "TOTO" << endl;
    setFixedSize(300, 150);
    QPushButton * Annuler = new QPushButton("Annuler", this);
    this->show();
}
