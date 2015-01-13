#include "diagramcolorwindow.h"
#include "ui_diagramcolorwindow.h"
#include <QFileDialog>
#include <stdio.h>

DiagramColorWindow::DiagramColorWindow(QImage * image) :
    QDialog(),
    ui(new Ui::DiagramColorWindow)
{
    ui->setupUi(this);
    this->scene = new QGraphicsScene(this);
    this->ui->graphicsView->setScene(this->scene);
    this->setVisible(true);

    initDiagramColor( image );
}

void DiagramColorWindow::initDiagramColor( QImage * image){
    int rows = image->width();
    int cols = image->height();

     for (int i=0; i<256; ++i){
         rCourbe.push_back(0);
         gCourbe.push_back(0);
         bCourbe.push_back(0);
         yCourbe.push_back(0);
         cbCourbe.push_back(0);
         crCourbe.push_back(0);
      }

    int rouge;
    int vert;
    int bleu;
    for (int i = 0; i<rows; ++i){
        for( int j = 0; j<cols; ++j){
            QRgb * pix = new QRgb( image->pixel(i,j) );
            QColor c( *pix );
            rouge = c.red();
            vert = c.green();
            bleu = c.blue();
            ++rCourbe[rouge];
            ++gCourbe[vert];
            ++bCourbe[bleu];
            ++yCourbe[ (int)(0.299*rouge+ 0.587*vert + 0.114*bleu) ];
            ++cbCourbe[ (int)(128 + (-0.168*rouge)+ (-0.331*vert) + (0.5*bleu)) ];
            ++crCourbe[ (int) (128 + (0.5*rouge)+ (-0.4187*vert) + (-0.0813*bleu)) ];
        }
    }
    this->reploot();
}

int DiagramColorWindow::maxValue(){
    int max =100;
    for (int i=0;i<256;++i)
    {
        if (max<rCourbe[i] &&  this->ui->checkBoxR->isChecked()){
            max = rCourbe[i]+10;
        }
        if (max<gCourbe[i] &&  this->ui->checkBoxG->isChecked()){
            max = gCourbe[i]+10;
        }
        if (max<bCourbe[i] &&  this->ui->checkBoxB->isChecked()){
            max = bCourbe[i]+10;
        }
        if (max<yCourbe[i] &&  this->ui->checkBoxY->isChecked()){
            max = yCourbe[i]+10;
        }
        if (max<cbCourbe[i] &&  this->ui->checkBoxCb->isChecked()){
            max = cbCourbe[i]+10;
        }
        if (max<crCourbe[i] &&  this->ui->checkBoxCr->isChecked()){
            max = crCourbe[i]+10;
        }
    }

    return max;
}

DiagramColorWindow::~DiagramColorWindow(){
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

 void DiagramColorWindow::reploot(){

     int multAbscisse=3;
     QPen RBrush(Qt::red);
     QPen GBrush(Qt::green);
     QPen BBrush(Qt::blue);

     QPen YBrush(Qt::black);

     QColor purpule(255,0,255,255);
     QPen CbBrush(purpule);

     QColor orange(255,255,0,255);
     QPen CrBrush(orange);

     scene->clear();

     int maxvalue =this->maxValue();
     int height= 750;
     int magin= height/50;

            for (int i=1; i<256;++i){
                if (this->ui->checkBoxR->isChecked()){
                    scene->addLine(magin+(i-1)*multAbscisse,height-height*rCourbe[i-1]/maxvalue,magin+i*multAbscisse,height-height*rCourbe[i]/maxvalue,RBrush);
                }
                if (this->ui->checkBoxG->isChecked()){
                    scene->addLine(magin+(i-1)*multAbscisse,height-height*gCourbe[i-1]/maxvalue,magin+i*multAbscisse,height-height*gCourbe[i]/maxvalue,GBrush);
                }
                if (this->ui->checkBoxB->isChecked()){
                    scene->addLine(magin+(i-1)*multAbscisse,height-height*bCourbe[i-1]/maxvalue,magin+i*multAbscisse,height-height*bCourbe[i]/maxvalue,BBrush);
                }
                if (this->ui->checkBoxY->isChecked()){
                    scene->addLine(magin+(i-1)*multAbscisse,height-height*yCourbe[i-1]/maxvalue,magin+i*multAbscisse,height-height*yCourbe[i]/maxvalue,YBrush);
                }
                if (this->ui->checkBoxCb->isChecked()){
                    scene->addLine(magin+(i-1)*multAbscisse,height-height*cbCourbe[i-1]/maxvalue,magin+i*multAbscisse,height-height*cbCourbe[i]/maxvalue,CbBrush);
                }
                if (this->ui->checkBoxCr->isChecked()){
                    scene->addLine(magin+(i-1)*multAbscisse,height-height*crCourbe[i-1]/maxvalue,magin+i*multAbscisse,height-height*crCourbe[i]/maxvalue,CrBrush);
                }
                if (i%50 == 0){
                    scene->addLine(i*multAbscisse,height+height/50,i*multAbscisse,height,YBrush);
                }
                else if (i%10 == 0){
                    scene->addLine(i*multAbscisse,height+height/100,i*multAbscisse,height,YBrush);
                }
            }

//            for (int i=0; i< height; ++i){
//                if (i%50 == 0){
//                    scene->addLine(0,i,height/50,i,YBrush);
//                    QGraphicsTextItem * io = new QGraphicsTextItem();
//                  io->setPos(0,i);
//                  char sc[100];
//                  intToString(sc,maxvalue*i/height);
//                    QString s( );
//                    io->setPlainText(sc);
//                    this->scene->addItem(io);
//                }
//                else if (i%10 == 0){
//                    scene->addLine(magin-height/100,i,magin,i,YBrush);
//                }
//            }

        this->scene->addLine(magin,0,magin,height,YBrush);
        this->scene->addLine(magin,height,magin+255*multAbscisse,height,YBrush);
        this->resize(250*multAbscisse+150,height+height/50+100);

}
