#ifndef REDIMENSIONNEMENT_H
#define REDIMENSIONNEMENT_H

#include <QDialog>
#include "mainwindow.h"
#include <QImage>

namespace Ui {
class Redimensionnement;
}

class Redimensionnement : public QDialog
{
    Q_OBJECT

public:
    explicit Redimensionnement(QWidget *parent = 0);
    ~Redimensionnement();
    void redim(MainWindow *value);

    int getXFinal() const;
    void setXFinal(int value);
    int getYFinal() const;
    void setYFinal(int value);
    bool getCancel() const;
    void setCancel(bool value);
    MainWindow *getWin() const;
    void setWin(MainWindow *value);

    void redimHauteur(QImage *final);
    void redimLargeur(QImage *final,QImage *inter);

public slots:
    void ok();
    void canceled();

private:
    Ui::Redimensionnement *ui;
    MainWindow *win;
    int xFinal;
    int yFinal;
    bool cancel;
};

#endif // REDIMENSIONNEMENT_H
