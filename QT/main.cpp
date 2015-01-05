#include "mainwindow.h"
#include <QApplication>
#include "open.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Open op;
    op.ouvrir( "../Images/Chaton_01.jpg");
    return a.exec();
}
