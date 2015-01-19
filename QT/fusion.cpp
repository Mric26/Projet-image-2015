#include "fusion.h"
#include "contraste.h"

Fusion::Fusion(){
}

void Fusion::fusionner(MainWindow *w){
    if(w->getCheminImage() != NULL){ //une image est déjà ouverte, la fusionner avec une autre


        float nivFusion;

        //chargement de la deuxième image
        QString chemin = QFileDialog::getOpenFileName(w,"Ouvrir un fichier");
        QImage * im = new QImage();
        im->load(chemin);

        //récupération du niveau de transparence
        Contraste *fenetre= new Contraste;
        fenetre->show();
        fenetre->activateWindow();
        fenetre->exec();
        if(fenetre->getCanceled()){
            return;
        }else{
            nivFusion= fenetre->getValue();
            nivFusion= nivFusion/100.0;
        }

        //création d'une image pouvant contenir les deux images
        int maxWidth, maxHeigh;
        if(w->getImage()->width() > im->width()){
            maxWidth = w->getImage()->width();
        }else{
            maxWidth = im->width();
        }
        if(w->getImage()->height() > im->height()){
            maxHeigh = w->getImage()->height();
        }else{
            maxHeigh = im->height();
        }

        QImage *final= new QImage(maxWidth,maxHeigh, QImage::Format_RGB32);
        float r,g,b;

        for (int j = 0; j < w->getImage()->height(); ++j) { //insertion de la première image
            for (int i = 0; i < w->getImage()->width(); ++i) {
                    r= QColor(w->getImage()->pixel(i,j)).red();
                    g= QColor(w->getImage()->pixel(i,j)).green();
                    b= QColor(w->getImage()->pixel(i,j)).blue();
                    final->setPixel(i,j,qRgb(int(r+0.5),int(g+0.5),int(b+0.5)));
            }
        }

        for (int j = 0; j < im->height(); ++j) { //insertion de la deuxième image
            for (int i = 0; i < im->width(); ++i) {
                if((j> w->getImage()->height()-1 || i> w->getImage()->width()-1)){
                    r= QColor(im->pixel(i,j)).red();
                    g= QColor(im->pixel(i,j)).green();
                    b= QColor(im->pixel(i,j)).blue();
                    final->setPixel(i,j,qRgb(int(r+0.5),int(g+0.5),int(b+0.5)));
                }else{
                    r= QColor(im->pixel(i,j)).red()*(1-(nivFusion)) + (QColor(w->getImage()->pixel(i,j)).red()*(nivFusion));
                    g= QColor(im->pixel(i,j)).green()*(1-(nivFusion)) + (QColor(w->getImage()->pixel(i,j)).green()*(nivFusion));
                    b= QColor(im->pixel(i,j)).blue()*(1-(nivFusion)) + (QColor(w->getImage()->pixel(i,j)).blue()*(nivFusion));
                    final->setPixel(i,j,qRgb(int(r+0.5),int(g+0.5),int(b+0.5)));
                }
            }
        }

        for (int j = 0; j < maxHeigh; ++j) { //insertion des blancs
            for (int i = 0; i < maxWidth; ++i) {
                if((i > im->width() && j > w->getImage()->height()) || (i > w->getImage()->width() && j >im->height())){
                   final->setPixel(i,j,qRgb(255,255,255));
                }
            }
        }

        //affichage de la nouvelle image
        chemin = chemin + "_fusion";
        w->setImage(final, chemin);


    }else{ //pas d'image ouverte, en ouvrir simplement une
        w->ouv();
    }
}
