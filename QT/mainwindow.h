#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QString>
#include <QRgb>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QColor>
#include <string>
#include <QShortcut>

#include "convolution.h"
#include "etalement.h"
#include "egalisation.h"
#include "diagramcolorwindow.h"
#include "filtreperso.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void refresh();
    void paintEvent(QPaintEvent *);
    ~MainWindow();

    QImage * getImage();    
    void setImage(QImage * im, QString chem);

    QString getCheminImage();

    bool getEmptylabel() const;
    void setEmptylabel(bool value);

    bool getRgbORyuv() const;
    void setRgbORyuv(bool value);

    QGraphicsPixmapItem *getImageaffichee() const;
    void setImageaffichee(QGraphicsPixmapItem *value);

public slots:
    // ouv / fermeture / enregistrement
    void ouv();
    void save();
    void saveAs();
    //Annuler & refaire
    void annuler();
    void refaire();
    //decoupe
    void couper();
    void rogner();
    //niveau de gris
    void gris();
    //histogramme
    void showHisto();
    void etaler();
    void egaler();
    //pipette
    void pipeit();
    void changeRGBtoYUVfalse();
    void changeRGBtoYUVtrue();
    //Filtres
    void flouGaussLeger();
    void flouGaussMoyen();
    void flouGaussFort();
    void flouMoyLeger();
    void flouMoyMoyen();
    void flouMoyFort();
    void passeHaut();
    void rehaussement();
    void gradientX();
    void gradientY();
    void detectionContours();
    void filtrePerso();
    void appliquerFiltrePerso(float **matrice, int tailleMatrice);
    //quitter
    void quit();
    void createFusion();
    void median();
    //redimensionnement
    void redimensionner();

private:
    Ui::MainWindow *ui;
    QImage* image;
    QString cheminImage;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *imageaffichee;
    DiagramColorWindow * hist;
    FiltrePerso * fPerso;
    bool emptylabel;
    bool rgbORyuv;
    QImage *annul[2];
    QImage* refai[2];

};

#endif // MAINWINDOW_H
