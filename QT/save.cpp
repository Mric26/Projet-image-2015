#include "save.h"

void Save::sauv(MainWindow * w){
    w->getImage()->save(w->getCheminImage());
}

void Save::sauvSous(MainWindow * w){
    QString chemin = QFileDialog::getSaveFileName(w,"Enregistrer sous...");
    w->getImage()->save(chemin);
}
