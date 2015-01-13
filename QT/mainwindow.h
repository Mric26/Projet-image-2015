#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <iostream>
#include <QString>
#include <QRgb>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QColor>
#include <string>
#include <QShortcut>

#include "convolution.h"
#include "diagramcolorwindow.h"

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

    QGraphicsScene * getScene() ;
    void setScene(QGraphicsScene *value);

    DiagramColorWindow *getHist() const;
    void setHist(DiagramColorWindow *value);

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
    //decoupe
    void couper();
    //niveau de gris
    void gris();
    //histogramme
    void showHisto();
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
    void createFusion();
    void median();

private:
    Ui::MainWindow *ui;
    QImage* image;
    QString cheminImage;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *imageaffichee;
    DiagramColorWindow * hist;
    bool emptylabel;
    bool rgbORyuv;
};

#endif // MAINWINDOW_H
