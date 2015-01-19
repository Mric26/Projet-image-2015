#include "diagramcolorwindow.h"
#include "ui_diagramcolorwindow.h"
#include <QFileDialog>
#include <stdio.h>
#include <iostream>

using namespace std;

DiagramColorWindow::DiagramColorWindow(QImage * im) :
    QDialog(),
    ui(new Ui::DiagramColorWindow)
{
    ui->setupUi(this);
    this->scene = new QGraphicsScene(this);
    this->ui->graphicsView->setScene(this->scene);
    this->setVisible(true);
    this->image = im;

    QObject::connect( ui->fermer, SIGNAL(clicked()), this, SLOT( ferm() ) );

    initDiagramColor( this->getImage() );
}

void DiagramColorWindow::ferm(){
    close();
}

QImage *DiagramColorWindow::getImage() const{
    return image;
}

void DiagramColorWindow::setImage(QImage *value){
    image = value;
}


void DiagramColorWindow::initDiagramColor( QImage * image){
    int lignes = image->width();
    int colonnes = image->height();

    for (int i=0; i<256; ++i){
         courbeRouge.push_back(0);
         courbeVerte.push_back(0);
         courbeBleu.push_back(0);
         courbeJaune.push_back(0);
         courbeCB.push_back(0);
         courbeCR.push_back(0);
         courbeCumul.push_back(0);
      }

    int rouge;
    int vert;
    int bleu;
    //calcul des courbes
    for (int i = 0; i<lignes; ++i){
        for( int j = 0; j<colonnes; ++j){
            QRgb * pix = new QRgb( image->pixel(i,j) );
            QColor c( *pix );
            rouge = c.red();
            vert = c.green();
            bleu = c.blue();
            ++courbeRouge[rouge];
            ++courbeVerte[vert];
            ++courbeBleu[bleu];
            ++courbeJaune[ (int)(0.299*rouge + 0.587*vert + 0.114*bleu) ];
            ++courbeCB[ (int)(128 + (-0.168*rouge) + (-0.331*vert) + (0.5*bleu)) ];
            ++courbeCR[ (int) (128 + (0.5*rouge) + (-0.4187*vert) + (-0.0813*bleu)) ];
        }
    }
    //construction courbe cumulée
    courbeCumul[0] = courbeRouge[0];
    for (int i = 1; i<256; ++i){
        courbeCumul[i] = courbeCumul[i-1] + courbeRouge[i];
    }
    this->reploot();
}

int DiagramColorWindow::maxValue(){
    //retrouver la valeur max dans tout les courbes pour retailler l'hitogramme
    int max =100;
    for (int i=0;i<256;++i)
    {
        if (max<courbeRouge[i] &&  this->ui->checkBoxR->isChecked()){
            max = courbeRouge[i]+10;
        }
        if (max<courbeVerte[i] &&  this->ui->checkBoxG->isChecked()){
            max = courbeVerte[i]+10;
        }
        if (max<courbeBleu[i] &&  this->ui->checkBoxB->isChecked()){
            max = courbeBleu[i]+10;
        }
        if (max<courbeJaune[i] &&  this->ui->checkBoxY->isChecked()){
            max = courbeJaune[i]+10;
        }
        if (max<courbeCB[i] &&  this->ui->checkBoxCb->isChecked()){
            max = courbeCB[i]+10;
        }
        if (max<courbeCR[i] &&  this->ui->checkBoxCr->isChecked()){
            max = courbeCR[i]+10;
        }
        if (max<courbeCumul[i] &&  this->ui->checkBoxCumu->isChecked()){
            max = courbeCumul[i]+10;
        }
    }
    return max;
}

DiagramColorWindow::~DiagramColorWindow(){
    delete scene;
    delete ui;
}

void DiagramColorWindow::on_checkBoxR_clicked(){
    reploot();
}

void DiagramColorWindow::on_checkBoxG_clicked(){
    reploot();
}

void DiagramColorWindow::on_checkBoxB_clicked(){
    reploot();
}

void DiagramColorWindow::on_checkBoxY_clicked(){
    reploot();
}

void DiagramColorWindow::on_checkBoxCb_clicked(){
    reploot();
}

void DiagramColorWindow::on_checkBoxCr_clicked(){
    reploot();
}

void DiagramColorWindow::on_checkBoxCumu_clicked(){
    reploot();
}

void DiagramColorWindow::reploot(){
     //traver les courbes

    int multAbscisse=3;
    QPen RBrush(Qt::red);
    QPen GBrush(Qt::green);
    QPen BBrush(Qt::blue);

    QPen YBrush(Qt::black);

    QColor purpule(255,0,255,255);
    QPen CbBrush(purpule);

    QColor orange(255,140,0,255);
    QPen CrBrush(orange);

    QColor violet(102,0,204,255);
    QPen VBrush(violet);

    scene->clear();

    int maxvalue =this->maxValue();
    int height= 400;
    int magin= height/50;

    for (int i=1; i<256;++i){
                if (this->ui->checkBoxR->isChecked()){
                    scene->addLine(magin+(i-1)*multAbscisse,height-height*courbeRouge[i-1]/maxvalue,magin+i*multAbscisse,height-height*courbeRouge[i]/maxvalue,RBrush);
                }
                if (this->ui->checkBoxG->isChecked()){
                    scene->addLine(magin+(i-1)*multAbscisse,height-height*courbeVerte[i-1]/maxvalue,magin+i*multAbscisse,height-height*courbeVerte[i]/maxvalue,GBrush);
                }
                if (this->ui->checkBoxB->isChecked()){
                    scene->addLine(magin+(i-1)*multAbscisse,height-height*courbeBleu[i-1]/maxvalue,magin+i*multAbscisse,height-height*courbeBleu[i]/maxvalue,BBrush);
                }
                if (this->ui->checkBoxY->isChecked()){
                    scene->addLine(magin+(i-1)*multAbscisse,height-height*courbeJaune[i-1]/maxvalue,magin+i*multAbscisse,height-height*courbeJaune[i]/maxvalue,YBrush);
                }
                if (this->ui->checkBoxCb->isChecked()){
                    scene->addLine(magin+(i-1)*multAbscisse,height-height*courbeCB[i-1]/maxvalue,magin+i*multAbscisse,height-height*courbeCB[i]/maxvalue,CbBrush);
                }
                if (this->ui->checkBoxCr->isChecked()){
                    scene->addLine(magin+(i-1)*multAbscisse,height-height*courbeCR[i-1]/maxvalue,magin+i*multAbscisse,height-height*courbeCR[i]/maxvalue,CrBrush);
                }
                if (this->ui->checkBoxCumu->isChecked()){
                    scene->addLine(magin+(i-1)*multAbscisse,height-height*courbeCumul[i-1]/maxvalue,magin+i*multAbscisse,height-height*courbeCumul[i]/maxvalue,VBrush);
                }
                if (i%50 == 0){
                    scene->addLine(i*multAbscisse,height+height/50,i*multAbscisse,height,YBrush);
                }
                else if (i%10 == 0){
                    scene->addLine(i*multAbscisse,height+height/100,i*multAbscisse,height,YBrush);
                }
            }

    //axes
    this->scene->addLine(magin,0,magin,height,YBrush);
    this->scene->addLine(magin,height,magin+255*multAbscisse,height,YBrush);
    this->resize(250*multAbscisse+125,height+height/50+100);
}
