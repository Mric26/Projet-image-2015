#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPainter>
#include <iostream>
#include <QString>
#include <QRgb>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
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
    void mousePressEvent(QMouseEvent *event);
    ~MainWindow();

    QImage * getImage();    
    void setImage(QImage * im, QString chem);

    QString getCheminImage();

    std::vector<QRgb> getMatrice() const;
    void setMatrice(const std::vector<QRgb> &value);

    QGraphicsScene * getScene() ;
    void setScene(QGraphicsScene *value);

public slots:
    void ouv();
    void save();
    void saveAs();
    void couper();
    void flouLeger();
    void flouMoyen();
    void flouFort();

private:
    Ui::MainWindow *ui;
    QImage* image;
    QString cheminImage;
    std::vector<QRgb> matrice;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *imageaffichee;
};

#endif // MAINWINDOW_H
