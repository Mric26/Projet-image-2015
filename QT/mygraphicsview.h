#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H
#include <iostream>
#include <QGraphicsView>
#include <QMouseEvent>


class MyGraphicsView : public QGraphicsView
{
public:
    MyGraphicsView(QWidget * w);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void setChecked(bool c);

private:
    bool checked;
};

#endif // MYGRAPHICSVIEW_H
