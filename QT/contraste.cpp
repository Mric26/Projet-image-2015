#include "contraste.h"
#include "ui_contraste.h"

Contraste::Contraste(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Contraste){
    ui->setupUi(this);
    this->setVisible(true);
    setDone(false);
    setCanceled(false);

    QObject::connect( ui->ok, SIGNAL(clicked()), this, SLOT(valider()) );
    QObject::connect( ui->cancel, SIGNAL(clicked()), this, SLOT(annuler()) );

}

Contraste::~Contraste(){
    delete ui;
}
int Contraste::getValue() const
{
    return value;
}

void Contraste::setValue(int value){
    this->value = value;
}

bool Contraste::getDone() const{
    return done;
}

void Contraste::setDone(bool value){
    done = value;
}

bool Contraste::getCanceled() const{
    return canceled;
}

void Contraste::setCanceled(bool value){
    canceled = value;
}

void Contraste::valider(){
    setValue((ui->horizontalSlider->value()));
    setDone(true);
    close();
}

void Contraste::annuler(){
    setCanceled(true);
    close();
}



