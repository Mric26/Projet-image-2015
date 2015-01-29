#include "fenseamcarving.h"
#include "ui_fenseamcarving.h"

FenSeamCarving::FenSeamCarving(QImage *im, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FenSeamCarving)
{
    image = new QImage();
    imageContours = new QImage();
    listeChemins = new ListeChemins();
    ui->setupUi(this);
    Convolution co;

    QObject::connect( ui->buttonBox, SIGNAL(accepted()), this, SLOT(detectionDesChemins()) );
    std::cout << "Détection des contours de l'image...";
    *image = im->copy();

    ui->spinHeight->setValue(image->height());
    ui->spinWidth->setValue(image->width());

    imageContours = co.detectionContours(image,4.0);
    std::cout << "Fait" << std::endl;

    this->setVisible(true);
}

FenSeamCarving::~FenSeamCarving()
{
    delete ui;
}

void FenSeamCarving::detect(int nb) {
    //Création d'une matrice représentant l'image en cours de traitement
    int ** im = new int * [imageContours->width()];
    for (int i = 0; i < imageContours->width(); ++i) {
        im[i] = new int [imageContours->height()];
        for (int j = 0; j < imageContours->height(); ++j) {
            im[i][j] = qGray(imageContours->pixel(i,j));
        }
    }

    //Création d'une matrice des sommes cumulées
    int ** mSommes = new int * [imageContours->width()];
    for (int i = 0; i < imageContours->width(); ++i) {
        mSommes[i] = new int [imageContours->height()];
    }

    //Création de la matrice indiquant si un pixel est utilisé dans un chemin ou non

    bool ** pixelsUtilises = new bool * [imageContours->width()];
    for (int i = 0; i < imageContours->width(); ++i) {
        pixelsUtilises[i] = new bool [imageContours->height()];
        for (int j = 0; j < imageContours->height(); ++j) {
            pixelsUtilises[i][j] = false;
        }
    }

    //Création d'une matrice de pixels utilisés temporaire
    bool ** pixelsTemp = new bool * [imageContours->width()];
    for (int i = 0; i < imageContours->width(); ++i) {
        pixelsTemp[i] = new bool [imageContours->height()];
        for (int j = 0; j < imageContours->height(); ++j) {
            pixelsTemp[i][j] = false;
        }
    }

    //Tableau représentant les pixels du bas de l'image dont le chemin a déjà été étudié

    bool *vu = new bool [imageContours->width()];

    for (int i = 0; i < imageContours->width(); ++i) {
        vu[i] = false;
    }

    int cheminsTestes = 0;
    int CheminsTrouves = 0;
    int nbCheminVoulu = 0;

    if (nb > imageContours->width()) {
        nbCheminVoulu = nb - imageContours->width();
    } else {
        nbCheminVoulu = imageContours->width() - nb;
    }

    while (cheminsTestes < imageContours->width() && CheminsTrouves < nbCheminVoulu) {
        //Initialisation de la première ligne de la matrice de somme
        for (int j = 0; j < imageContours->width(); ++j) {
            mSommes[j][0] = im[j][0];
        }

        int sommeG,sommeD,sommeM;
        bool utilisableG, utilisableD, utilisableM;
        for (int j = 1; j < imageContours->height(); ++j) {
            for (int i = 0; i < imageContours->width(); ++i) {
                utilisableG = i-1 > -1;
                utilisableD = i+1 < imageContours->width();
                //Calcul des sommes cumulées
                if (utilisableG){
                    sommeG = im[i][j] + mSommes[i-1][j-1];
                }
                if (utilisableD) {
                    sommeD = im[i][j] + mSommes[i+1][j-1];
                }
                sommeM = im[i][j] + mSommes[i][j-1];
                //Choix de la somme à mettre dans la matrice
                if (utilisableD
                        && (!utilisableG ||sommeD <= sommeG)
                        && (sommeD <= sommeM)) {
                    mSommes[i][j] = sommeD;
                } else if (utilisableG
                           && (!utilisableD || sommeG < sommeD)
                           && (sommeG <= sommeM)) {
                    mSommes[i][j] = sommeG;
                } else if ((!utilisableG || sommeM < sommeG)
                           && (!utilisableD || sommeM < sommeD)) {
                    mSommes[i][j] = sommeM;
                }
            }
        }

        //Recherche de la valeur minimale sur la dernière ligne de l'image
        int min = 0;
        for (int j = 0; j < imageContours->width(); ++j) {
            if (mSommes[j][imageContours->height()-1] <= mSommes[min][imageContours->height()-1] && !vu[j]) {
                min = j;
            }
        }

        vu[min] = true;

        int nouvI = min;
        int j = imageContours->height()-1;
        Chemin *c = new Chemin();

        bool cheminPossible =true;
        while (cheminPossible && j > 0) {
            c->ajouterPoint(new QPoint(nouvI,j),im[nouvI][j]);
            pixelsTemp[nouvI][j] = true;
            im[nouvI][j] = 256;
            --j;

            utilisableG = nouvI-1 > -1 && pixelsUtilises[nouvI-1][j] == false;
            utilisableD = nouvI+1 < imageContours->width() && pixelsUtilises[nouvI+1][j] == false;
            utilisableM = pixelsUtilises[nouvI][j] == false;

            bool possibleD = utilisableD
                    && (!utilisableG || mSommes[nouvI+1][j] < mSommes[nouvI-1][j])
                    && (!utilisableM || mSommes[nouvI+1][j] < mSommes[nouvI][j]);
            bool possibleG = utilisableG
                    && (!utilisableD || mSommes[nouvI-1][j] <= mSommes[nouvI+1][j])
                    && (!utilisableM || mSommes[nouvI-1][j] < mSommes[nouvI][j]);
            bool possibleM = utilisableM
                    && (!utilisableG || mSommes[nouvI][j] <= mSommes[nouvI-1][j])
                    && (!utilisableD || mSommes[nouvI][j] <= mSommes[nouvI+1][j]);

            if (possibleD) {
                nouvI = nouvI+1;
            } else if (possibleG) {
                nouvI = nouvI-1;
            } else if (possibleM) {
                nouvI = nouvI;
            } else {
                cheminPossible = false;
            }
        }
        if (j == 0) {
            //ajouter chemin courant à la liste des chemins
            c->ajouterPoint(new QPoint(nouvI,j),im[nouvI][j]);
            pixelsTemp[nouvI][j] = true;
            im[nouvI][j] = 256;
            listeChemins->ajouterChemin(c);
            for (int a = 0; a < imageContours->width(); ++a) {
                for (int b = 0; b < imageContours->height(); ++b) {
                    pixelsUtilises[a][b] = pixelsTemp[a][b];
                }
            }
            ++CheminsTrouves;
        } else {
            for (int a = 0; a < imageContours->width(); ++a) {
                for (int b = 0; b < imageContours->height(); ++b) {
                    if (pixelsTemp[a][b] != pixelsUtilises[a][b]) {
                        im[a][b] = qGray(imageContours->pixel(a,b));
                        pixelsTemp[a][b] = pixelsUtilises[a][b];
                    }
                }
            }
            delete c;
        }
        ++cheminsTestes;
    }
    //Création d'un masque des chemins
    QImage masque(image->width(),image->height(),image->format());
    masque.fill(qRgb(0,0,0));
    for (int i = 0; i < listeChemins->getListeChemins().size(); ++i) {
        Chemin *c = listeChemins->getListeChemins().at(i);
        for (int j = 0; j < c->getListePoints().size(); ++j) {
            QPoint *p = c->getPoint(j);
            masque.setPixel(p->x(),p->y(),qRgb(255,0,0));
        }
    }

    if (nb > image->width()) {
        QImage * imageAgrandie = new QImage(nb,image->height(), image->format());
        for (int i = 0; i < masque.height(); ++i) {
            int x = 0;
            for (int j = 0; j < masque.width(); ++j) {
                if (qRed(masque.pixel(j,i)) == 255) {
                    imageAgrandie->setPixel(x,i,image->pixel(j,i));
                    ++x;
                }
                imageAgrandie->setPixel(x,i,image->pixel(j,i));
                ++x;
            }
        }
        image = imageAgrandie;
    }else {

        QImage * imageReduite = new QImage(image->width()-CheminsTrouves,image->height(), image->format());
        for (int i = 0; i < masque.height(); ++i) {
            int x = 0;
            for (int j = 0; j < masque.width(); ++j) {
                if (qRed(masque.pixel(j,i)) != 255) {
                    imageReduite->setPixel(x,i,image->pixel(j,i));
                    ++x;
                }
            }
        }
        image = imageReduite;
    }
}

void FenSeamCarving::detectionDesChemins()
{
    std::cout << "Détection des chemins verticaux..." << std::endl;

    detect(ui->spinWidth->value());

    std::cout << "Fait!" << std::endl;

    QImage * transposee = new QImage(image->height(),image->width(),image->format());

    for (int i = 0; i < image->width(); ++i) {
        for (int j = 0; j < image->height(); ++j) {
            transposee->setPixel(j,i,image->pixel(i,j));
        }
    }

    image = transposee;

    Convolution co;
    imageContours = co.detectionContours(image,4.0);
    delete listeChemins;
    listeChemins = new ListeChemins();

    std::cout << "Détection des chemins horizontaux..." << std::endl;

    detect(ui->spinHeight->value());

    std::cout << "Fait!" << std::endl;

    transposee = new QImage(image->height(),image->width(),image->format());

    for (int i = 0; i < image->width(); ++i) {
        for (int j = 0; j < image->height(); ++j) {
            transposee->setPixel(j,i,image->pixel(i,j));
        }
    }

    image = transposee;

    close();
    emit(envoyerImage(image));
}
