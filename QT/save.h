#ifndef SAVE_H
#define SAVE_H

#include <string>
#include <QFileDialog>

#include "mainwindow.h"

using namespace std;

class Save
{
public:
    void sauv(MainWindow *w);
    void sauvSous(MainWindow * w);
};

#endif // SAVE_H
