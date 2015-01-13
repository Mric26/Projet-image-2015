#ifndef CONTRASTE_H
#define CONTRASTE_H

#include <QDialog>

namespace Ui {
class Contraste;
}

class Contraste : public QDialog
{
    Q_OBJECT

public:
    explicit Contraste(QWidget *parent = 0);
    ~Contraste();

    int getValue() const;
    void setValue(int value);

    bool getDone() const;
    void setDone(bool value);

    bool getCanceled() const;
    void setCanceled(bool value);

public slots:
    void valider();
    void annuler();

private:
    Ui::Contraste *ui;
    bool done;
    int value;
    bool canceled;
};

#endif // CONTRASTE_H
