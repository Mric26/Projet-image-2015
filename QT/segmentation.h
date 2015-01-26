#ifndef SEGMENTATION_H
#define SEGMENTATION_H

#include <QDialog>
#include <QGraphicsScene>
#include "opencv.hpp"
#include "mainwindow.h"

namespace Ui {
class Segmentation;
}

class Segmentation : public QDialog
{
    Q_OBJECT

public:
    explicit Segmentation(QWidget *parent = 0);
    ~Segmentation();
    void addIMG(QImage *im, QString cheminIMG);

    MainWindow *getWin() const;
    void setWin(MainWindow *value);

    QImage *getImage() const;
    void setImage(QImage *value);

public slots:
    void ok();
    void cancel();

private:
    Ui::Segmentation *ui;
    QImage * image;
    QGraphicsScene *scene;
    QString cheminImage;
    MainWindow * win;
};

#endif // SEGMENTATION_H
