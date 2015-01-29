#ifndef FENSEAMCARVING_H
#define FENSEAMCARVING_H

#include <QDialog>
#include "convolution.h"
#include <iostream>
#include <QPoint>
#include "chemin.h"
#include "listechemins.h"
#include "grisconvers.h"

namespace Ui {
class FenSeamCarving;
}

class FenSeamCarving : public QDialog
{
    Q_OBJECT

public:
    explicit FenSeamCarving( QImage *im, QWidget *parent = 0);
    ~FenSeamCarving();


public slots:
    void detectionDesChemins();
signals:
    void envoyerImage(QImage*);
private:
    Ui::FenSeamCarving *ui;
    QImage *image;
    QImage *imageContours;
    ListeChemins *listeChemins;
    void detect(int nb);
};

#endif // FENSEAMCARVING_H
