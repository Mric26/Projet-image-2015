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
#include "convolution.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    ~MainWindow();

    QImage * getImage();    
    void setImage(QImage * im, QString chem);

    QString getCheminImage();

    QGraphicsScene * getScene() ;
    void setScene(QGraphicsScene *value);

public slots:
    void ouv();
    void save();
    void saveAs();
    void couper();
    void gris();
    void showHisto();
    //Filtres
    void flouLeger();
    void flouMoyen();
    void flouFort();
    void passeHaut();

private:
    Ui::MainWindow *ui;
    QImage* image;
    QString cheminImage;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *imageaffichee;
};

#endif // MAINWINDOW_H
