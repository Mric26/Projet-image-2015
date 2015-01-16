#ifndef DIAGRAMCOLORWINDOW_H
#define DIAGRAMCOLORWINDOW_H

#include <QtCore>
#include <QtGui>
#include <QDialog>
#include <QGraphicsView>
#include <vector>
#include <QImage>

namespace Ui {
class DiagramColorWindow;
}

class DiagramColorWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DiagramColorWindow(QImage * im);
    ~DiagramColorWindow();


    QImage *getImage() const;
    void setImage(QImage *value);

private slots:
    void on_checkBoxR_clicked();
    void on_checkBoxG_clicked();
    void on_checkBoxB_clicked();
    void on_checkBoxY_clicked();
    void on_checkBoxCb_clicked();
    void on_checkBoxCr_clicked();
    void on_checkBoxCumu_clicked();

public slots:
    void ferm();

private:
    Ui::DiagramColorWindow *ui;
    QGraphicsScene *scene;
    QImage * image;
    std::vector<int> courbeRouge;
    std::vector<int> courbeVerte;
    std::vector<int> courbeBleu;
    std::vector<int> courbeJaune;
    std::vector<int> courbeCB;
    std::vector<int> courbeCR;
    std::vector<int> courbeCumul;
    void reploot();
    void initDiagramColor(QImage *image);
    int maxValue();

};

#endif // DIAGRAMCOLORWINDOW_H
