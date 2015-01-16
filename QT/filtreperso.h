#ifndef FILTREPERSO_H
#define FILTREPERSO_H

#include <QDialog>

namespace Ui {
class FiltrePerso;
}

class FiltrePerso : public QDialog
{
    Q_OBJECT

public:
    explicit FiltrePerso(QWidget *parent = 0);
    ~FiltrePerso();

private:
    Ui::FiltrePerso *ui;
};

#endif // FILTREPERSO_H
