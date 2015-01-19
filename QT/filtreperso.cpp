#include "filtreperso.h"
#include "ui_filtreperso.h"

FiltrePerso::FiltrePerso(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FiltrePerso)
{
    this->setVisible(true);


    ui->setupUi(this);
     select3x3();

    QObject::connect( ui->radioButton3x3, SIGNAL(clicked()), this, SLOT(select3x3()) );
    QObject::connect( ui->radioButton5x5, SIGNAL(clicked()), this, SLOT(select5x5()) );
    QObject::connect( ui->radioButton7x7, SIGNAL(clicked()), this, SLOT(select7x7()) );
    QObject::connect( ui->buttonBox, SIGNAL(accepted()), this, SLOT(valider()) );
    QObject::connect( ui->buttonBox, SIGNAL(rejected()), this, SLOT(close()) );

}

FiltrePerso::~FiltrePerso()
{
    delete ui;
}

void FiltrePerso::select3x3()
{
    ui->c00->setVisible(false);
    ui->c01->setVisible(false);
    ui->c02->setVisible(false);
    ui->c03->setVisible(false);
    ui->c04->setVisible(false);
    ui->c05->setVisible(false);
    ui->c06->setVisible(false);

    ui->c10->setVisible(false);
    ui->c11->setVisible(false);
    ui->c12->setVisible(false);
    ui->c13->setVisible(false);
    ui->c14->setVisible(false);
    ui->c15->setVisible(false);
    ui->c16->setVisible(false);

    ui->c50->setVisible(false);
    ui->c51->setVisible(false);
    ui->c52->setVisible(false);
    ui->c53->setVisible(false);
    ui->c54->setVisible(false);
    ui->c55->setVisible(false);
    ui->c56->setVisible(false);

    ui->c60->setVisible(false);
    ui->c61->setVisible(false);
    ui->c62->setVisible(false);
    ui->c63->setVisible(false);
    ui->c64->setVisible(false);
    ui->c65->setVisible(false);
    ui->c66->setVisible(false);

    ui->c20->setVisible(false);
    ui->c30->setVisible(false);
    ui->c40->setVisible(false);

    ui->c21->setVisible(false);
    ui->c31->setVisible(false);
    ui->c41->setVisible(false);

    ui->c25->setVisible(false);
    ui->c35->setVisible(false);
    ui->c45->setVisible(false);

    ui->c26->setVisible(false);
    ui->c36->setVisible(false);
    ui->c46->setVisible(false);
}

void FiltrePerso::select5x5()
{
    ui->c00->setVisible(false);
    ui->c01->setVisible(false);
    ui->c02->setVisible(false);
    ui->c03->setVisible(false);
    ui->c04->setVisible(false);
    ui->c05->setVisible(false);
    ui->c06->setVisible(false);

    ui->c10->setVisible(false);
    ui->c11->setVisible(true);
    ui->c12->setVisible(true);
    ui->c13->setVisible(true);
    ui->c14->setVisible(true);
    ui->c15->setVisible(true);
    ui->c16->setVisible(false);

    ui->c50->setVisible(false);
    ui->c51->setVisible(true);
    ui->c52->setVisible(true);
    ui->c53->setVisible(true);
    ui->c54->setVisible(true);
    ui->c55->setVisible(true);
    ui->c56->setVisible(false);

    ui->c60->setVisible(false);
    ui->c61->setVisible(false);
    ui->c62->setVisible(false);
    ui->c63->setVisible(false);
    ui->c64->setVisible(false);
    ui->c65->setVisible(false);
    ui->c66->setVisible(false);

    ui->c20->setVisible(false);
    ui->c30->setVisible(false);
    ui->c40->setVisible(false);

    ui->c21->setVisible(true);
    ui->c31->setVisible(true);
    ui->c41->setVisible(true);

    ui->c25->setVisible(true);
    ui->c35->setVisible(true);
    ui->c45->setVisible(true);

    ui->c26->setVisible(false);
    ui->c36->setVisible(false);
    ui->c46->setVisible(false);
}

void FiltrePerso::select7x7()
{
    ui->c00->setVisible(true);
    ui->c01->setVisible(true);
    ui->c02->setVisible(true);
    ui->c03->setVisible(true);
    ui->c04->setVisible(true);
    ui->c05->setVisible(true);
    ui->c06->setVisible(true);

    ui->c10->setVisible(true);
    ui->c11->setVisible(true);
    ui->c12->setVisible(true);
    ui->c13->setVisible(true);
    ui->c14->setVisible(true);
    ui->c15->setVisible(true);
    ui->c16->setVisible(true);

    ui->c50->setVisible(true);
    ui->c51->setVisible(true);
    ui->c52->setVisible(true);
    ui->c53->setVisible(true);
    ui->c54->setVisible(true);
    ui->c55->setVisible(true);
    ui->c56->setVisible(true);

    ui->c60->setVisible(true);
    ui->c61->setVisible(true);
    ui->c62->setVisible(true);
    ui->c63->setVisible(true);
    ui->c64->setVisible(true);
    ui->c65->setVisible(true);
    ui->c66->setVisible(true);

    ui->c20->setVisible(true);
    ui->c30->setVisible(true);
    ui->c40->setVisible(true);

    ui->c21->setVisible(true);
    ui->c31->setVisible(true);
    ui->c41->setVisible(true);

    ui->c25->setVisible(true);
    ui->c35->setVisible(true);
    ui->c45->setVisible(true);

    ui->c26->setVisible(true);
    ui->c36->setVisible(true);
    ui->c46->setVisible(true);
}

void FiltrePerso::valider()
{
    float ** matrice;
    int taille;
    if (ui->radioButton3x3->isChecked()) {
        matrice = new float *[3];
        for (int i = 0; i < 3; ++i) {
            matrice[i] = new float[3];
        }

        matrice[0][0] = (float) ui->c22->value();
        matrice[0][1] = (float) ui->c23->value();
        matrice[0][2] = (float) ui->c24->value();
        matrice[1][0] = (float) ui->c32->value();
        matrice[1][1] = (float) ui->c33->value();
        matrice[1][2] = (float) ui->c34->value();
        matrice[2][0] = (float) ui->c42->value();
        matrice[2][1] = (float) ui->c43->value();
        matrice[2][2] = (float) ui->c44->value();
        taille = 3;
    }
    else if (ui->radioButton5x5->isChecked()) {
        matrice = new float *[5];
        for (int i = 0; i < 5; ++i) {
            matrice[i] = new float[5];
        }

        matrice[0][0] = (float) ui->c11->value();
        matrice[0][1] = (float) ui->c12->value();
        matrice[0][2] = (float) ui->c13->value();
        matrice[0][3] = (float) ui->c14->value();
        matrice[0][4] = (float) ui->c15->value();
        matrice[1][0] = (float) ui->c21->value();
        matrice[1][1] = (float) ui->c22->value();
        matrice[1][2] = (float) ui->c23->value();
        matrice[1][3] = (float) ui->c24->value();
        matrice[1][4] = (float) ui->c25->value();
        matrice[2][0] = (float) ui->c31->value();
        matrice[2][1] = (float) ui->c32->value();
        matrice[2][2] = (float) ui->c33->value();
        matrice[2][3] = (float) ui->c34->value();
        matrice[2][4] = (float) ui->c35->value();
        matrice[3][0] = (float) ui->c41->value();
        matrice[3][1] = (float) ui->c42->value();
        matrice[3][2] = (float) ui->c43->value();
        matrice[3][3] = (float) ui->c44->value();
        matrice[3][4] = (float) ui->c45->value();
        matrice[4][0] = (float) ui->c51->value();
        matrice[4][1] = (float) ui->c52->value();
        matrice[4][2] = (float) ui->c53->value();
        matrice[4][3] = (float) ui->c54->value();
        matrice[4][4] = (float) ui->c55->value();
        taille = 5;
    }
    else {
        matrice = new float *[7];
        for (int i = 0; i < 7; ++i) {
            matrice[i] = new float[7];
        }

        matrice[0][0] = (float) ui->c00->value();
        matrice[0][1] = (float) ui->c01->value();
        matrice[0][2] = (float) ui->c02->value();
        matrice[0][3] = (float) ui->c03->value();
        matrice[0][4] = (float) ui->c04->value();
        matrice[0][5] = (float) ui->c05->value();
        matrice[0][6] = (float) ui->c06->value();
        matrice[1][0] = (float) ui->c10->value();
        matrice[1][1] = (float) ui->c11->value();
        matrice[1][2] = (float) ui->c12->value();
        matrice[1][3] = (float) ui->c13->value();
        matrice[1][4] = (float) ui->c14->value();
        matrice[1][5] = (float) ui->c15->value();
        matrice[1][6] = (float) ui->c16->value();
        matrice[2][0] = (float) ui->c20->value();
        matrice[2][1] = (float) ui->c21->value();
        matrice[2][2] = (float) ui->c22->value();
        matrice[2][3] = (float) ui->c23->value();
        matrice[2][4] = (float) ui->c24->value();
        matrice[2][5] = (float) ui->c25->value();
        matrice[2][6] = (float) ui->c26->value();
        matrice[3][0] = (float) ui->c30->value();
        matrice[3][1] = (float) ui->c31->value();
        matrice[3][2] = (float) ui->c32->value();
        matrice[3][3] = (float) ui->c33->value();
        matrice[3][4] = (float) ui->c34->value();
        matrice[3][5] = (float) ui->c35->value();
        matrice[3][6] = (float) ui->c36->value();
        matrice[4][0] = (float) ui->c40->value();
        matrice[4][1] = (float) ui->c41->value();
        matrice[4][2] = (float) ui->c42->value();
        matrice[4][3] = (float) ui->c43->value();
        matrice[4][4] = (float) ui->c44->value();
        matrice[4][5] = (float) ui->c45->value();
        matrice[4][6] = (float) ui->c46->value();
        matrice[5][0] = (float) ui->c50->value();
        matrice[5][1] = (float) ui->c51->value();
        matrice[5][2] = (float) ui->c52->value();
        matrice[5][3] = (float) ui->c53->value();
        matrice[5][4] = (float) ui->c54->value();
        matrice[5][5] = (float) ui->c55->value();
        matrice[5][6] = (float) ui->c56->value();
        matrice[6][0] = (float) ui->c60->value();
        matrice[6][1] = (float) ui->c61->value();
        matrice[6][2] = (float) ui->c62->value();
        matrice[6][3] = (float) ui->c63->value();
        matrice[6][4] = (float) ui->c64->value();
        matrice[6][5] = (float) ui->c65->value();
        matrice[6][6] = (float) ui->c66->value();
        taille = 7;
    }

    close();
    emit(envoyerMatrice(matrice,taille));

}
