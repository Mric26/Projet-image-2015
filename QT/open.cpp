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


    //Génération de la matrice de l'image
//  vector<QRgb> mat(im->width()*im->height());
//    for (int i = 0; i < im->height() ; ++i) {
//        for (int j = 0; j < im->width(); ++j) {
//               mat.insert(mat.begin() + (i * im->width() + j), im->pixel(j,i));
//               cout << (i * im->width() + j) << endl;
//        }
//    }
//    w->setMatrice(mat);

}
