#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPainter>
#include <iostream>
#include <QString>
#include <QRgb>
#include <vector>
#include <QGraphicsScene>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    ~MainWindow();
    QImage * getImage();
    void setImage(QImage * im, QString chem);
    QString getCheminImage();
    std::vector<QRgb> getMatrice() const;
    void setMatrice(const std::vector<QRgb> &value);
    QGraphicsScene * getScene() ;
    void setScene(QGraphicsScene *value);

public slots:
    void ouv();
    void save();
    void saveAs();
     void couper();

private:
    Ui::MainWindow *ui;
    QImage* image;
    QString cheminImage;
    std::vector<QRgb> matrice;
    QGraphicsScene *scene;
};

#endif // MAINWINDOW_H
