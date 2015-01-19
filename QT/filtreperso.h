#ifndef FILTREPERSO_H
#define FILTREPERSO_H

#include <QDialog>
#include <iostream>

namespace Ui {
class FiltrePerso;
}

class FiltrePerso : public QDialog
{
    Q_OBJECT

public:
    explicit FiltrePerso(QWidget *parent = 0);
    ~FiltrePerso();

public slots:
    void select3x3();
    void select5x5();
    void select7x7();
    void valider();

signals:
    void envoyerMatrice(float**,int);
private:


    Ui::FiltrePerso *ui;
};

#endif // FILTREPERSO_H
