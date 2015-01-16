#include "filtreperso.h"
#include "ui_filtreperso.h"

FiltrePerso::FiltrePerso(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FiltrePerso)
{
    ui->setupUi(this);
}

FiltrePerso::~FiltrePerso()
{
    delete ui;
}
