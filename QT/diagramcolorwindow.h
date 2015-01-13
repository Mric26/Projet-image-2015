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
    explicit DiagramColorWindow( QImage * image );
    ~DiagramColorWindow();


private slots:
    void on_checkBoxR_clicked();
    void on_checkBoxG_clicked();
    void on_checkBoxB_clicked();
    void on_checkBoxY_clicked();
    void on_checkBoxCb_clicked();
    void on_checkBoxCr_clicked();

private:
    Ui::DiagramColorWindow *ui;
    QGraphicsScene *scene;
    std::vector<int> rCourbe;
    std::vector<int> gCourbe;
    std::vector<int> bCourbe;
    std::vector<int> yCourbe;
    std::vector<int> cbCourbe;
    std::vector<int> crCourbe;
    void reploot();
    void initDiagramColor(QImage *image);
    int maxValue();


};

#endif // DIAGRAMCOLORWINDOW_H
