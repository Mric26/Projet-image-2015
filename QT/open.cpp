#include "open.h"

using namespace std;

void Open::ouvrir( MainWindow * w ) {

    //chemin
    QString chemin = QFileDialog::getOpenFileName(w,"Ouvrir un fichier");

    //ouverture
    QImage * im = new QImage();
    bool charge = im->load(chemin);

    if (charge) {
        w->setImage( im, chemin );
    }
}
