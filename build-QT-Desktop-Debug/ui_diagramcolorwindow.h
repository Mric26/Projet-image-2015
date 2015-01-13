/********************************************************************************
** Form generated from reading UI file 'diagramcolorwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIAGRAMCOLORWINDOW_H
#define UI_DIAGRAMCOLORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DiagramColorWindow
{
public:
    QGridLayout *gridLayout;
    QGroupBox *histoGroupBox;
    QGridLayout *gridLayout_2;
    QGraphicsView *graphicsView;
    QVBoxLayout *checkBoxLayout;
    QCheckBox *checkBoxR;
    QCheckBox *checkBoxG;
    QCheckBox *checkBoxB;
    QCheckBox *checkBoxY;
    QCheckBox *checkBoxCb;
    QCheckBox *checkBoxCr;

    void setupUi(QDialog *DiagramColorWindow)
    {
        if (DiagramColorWindow->objectName().isEmpty())
            DiagramColorWindow->setObjectName(QStringLiteral("DiagramColorWindow"));
        DiagramColorWindow->resize(423, 251);
        gridLayout = new QGridLayout(DiagramColorWindow);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        histoGroupBox = new QGroupBox(DiagramColorWindow);
        histoGroupBox->setObjectName(QStringLiteral("histoGroupBox"));
        gridLayout_2 = new QGridLayout(histoGroupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        graphicsView = new QGraphicsView(histoGroupBox);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setFrameShadow(QFrame::Sunken);
        graphicsView->setLineWidth(0);
        graphicsView->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        gridLayout_2->addWidget(graphicsView, 0, 0, 1, 1);

        checkBoxLayout = new QVBoxLayout();
        checkBoxLayout->setObjectName(QStringLiteral("checkBoxLayout"));
        checkBoxR = new QCheckBox(histoGroupBox);
        checkBoxR->setObjectName(QStringLiteral("checkBoxR"));
        checkBoxR->setChecked(true);

        checkBoxLayout->addWidget(checkBoxR);

        checkBoxG = new QCheckBox(histoGroupBox);
        checkBoxG->setObjectName(QStringLiteral("checkBoxG"));
        checkBoxG->setChecked(true);

        checkBoxLayout->addWidget(checkBoxG);

        checkBoxB = new QCheckBox(histoGroupBox);
        checkBoxB->setObjectName(QStringLiteral("checkBoxB"));
        checkBoxB->setChecked(true);

        checkBoxLayout->addWidget(checkBoxB);

        checkBoxY = new QCheckBox(histoGroupBox);
        checkBoxY->setObjectName(QStringLiteral("checkBoxY"));

        checkBoxLayout->addWidget(checkBoxY);

        checkBoxCb = new QCheckBox(histoGroupBox);
        checkBoxCb->setObjectName(QStringLiteral("checkBoxCb"));

        checkBoxLayout->addWidget(checkBoxCb);

        checkBoxCr = new QCheckBox(histoGroupBox);
        checkBoxCr->setObjectName(QStringLiteral("checkBoxCr"));

        checkBoxLayout->addWidget(checkBoxCr);


        gridLayout_2->addLayout(checkBoxLayout, 0, 1, 1, 1);


        gridLayout->addWidget(histoGroupBox, 0, 0, 1, 1);


        retranslateUi(DiagramColorWindow);

        QMetaObject::connectSlotsByName(DiagramColorWindow);
    } // setupUi

    void retranslateUi(QDialog *DiagramColorWindow)
    {
        DiagramColorWindow->setWindowTitle(QApplication::translate("DiagramColorWindow", "Dialog", 0));
        histoGroupBox->setTitle(QApplication::translate("DiagramColorWindow", "Diagrammes des couleurs", 0));
        checkBoxR->setText(QApplication::translate("DiagramColorWindow", "R", 0));
        checkBoxG->setText(QApplication::translate("DiagramColorWindow", "G", 0));
        checkBoxB->setText(QApplication::translate("DiagramColorWindow", "B", 0));
        checkBoxY->setText(QApplication::translate("DiagramColorWindow", "Y", 0));
        checkBoxCb->setText(QApplication::translate("DiagramColorWindow", "Cb", 0));
        checkBoxCr->setText(QApplication::translate("DiagramColorWindow", "Cr", 0));
    } // retranslateUi

};

namespace Ui {
    class DiagramColorWindow: public Ui_DiagramColorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIAGRAMCOLORWINDOW_H
