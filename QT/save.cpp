#include "save.h"

void Save::sauv(MainWindow * w){
    if( w->getImage() != NULL ){
        w->getImage()->save(w->getCheminImage());
    }
}

void Save::sauvSous(MainWindow * w){
    if( w->getImage() != NULL ){
        QString chemin = QFileDialog::getSaveFileName(w,"Enregistrer sous...");
        w->getImage()->save(chemin);
    }
}
