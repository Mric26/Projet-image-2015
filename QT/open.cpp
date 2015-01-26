#include "open.h"

int Open::ouvrir( MainWindow * w ) {

    //chemin
    QString chemin = QFileDialog::getOpenFileName(w,"Ouvrir un fichier");

    //ouverture
    QImage * im = new QImage();
    bool charge = im->load(chemin);

    if (charge) {
        w->nettoyage();
        w->setImage( im, chemin );
        w->active();
        return 1;
    }
    else{
        w->active();
        return 0;
    }

}
