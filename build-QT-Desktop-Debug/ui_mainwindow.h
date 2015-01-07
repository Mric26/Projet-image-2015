/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionEnregistrer;
    QAction *actionFermer;
    QAction *actionEnregistrer_sous;
    QAction *actionKjshg;
    QAction *actionOuvrir_2;
    QAction *actionHistogramme;
    QAction *actionNiveau_de_gris;
    QAction *actionFlou;
    QAction *actionFusion;
    QAction *actionPipette;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *aireDeDessin;
    QGridLayout *gridLayout_3;
    QWidget *dessin;
    QGridLayout *gridLayout_2;
    QPushButton *histogramme;
    QPushButton *flou;
    QSpacerItem *verticalSpacer_2;
    QPushButton *fusion;
    QPushButton *ouvrir;
    QPushButton *pipette;
    QPushButton *enregistrer;
    QPushButton *couper;
    QSpacerItem *verticalSpacer;
    QPushButton *gris;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menu_dition;
    QMenu *menuAbout;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(688, 451);
        actionEnregistrer = new QAction(MainWindow);
        actionEnregistrer->setObjectName(QStringLiteral("actionEnregistrer"));
        actionFermer = new QAction(MainWindow);
        actionFermer->setObjectName(QStringLiteral("actionFermer"));
        actionEnregistrer_sous = new QAction(MainWindow);
        actionEnregistrer_sous->setObjectName(QStringLiteral("actionEnregistrer_sous"));
        actionKjshg = new QAction(MainWindow);
        actionKjshg->setObjectName(QStringLiteral("actionKjshg"));
        actionOuvrir_2 = new QAction(MainWindow);
        actionOuvrir_2->setObjectName(QStringLiteral("actionOuvrir_2"));
        actionHistogramme = new QAction(MainWindow);
        actionHistogramme->setObjectName(QStringLiteral("actionHistogramme"));
        actionNiveau_de_gris = new QAction(MainWindow);
        actionNiveau_de_gris->setObjectName(QStringLiteral("actionNiveau_de_gris"));
        actionFlou = new QAction(MainWindow);
        actionFlou->setObjectName(QStringLiteral("actionFlou"));
        actionFusion = new QAction(MainWindow);
        actionFusion->setObjectName(QStringLiteral("actionFusion"));
        actionPipette = new QAction(MainWindow);
        actionPipette->setObjectName(QStringLiteral("actionPipette"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        aireDeDessin = new QWidget();
        aireDeDessin->setObjectName(QStringLiteral("aireDeDessin"));
        aireDeDessin->setGeometry(QRect(0, 0, 585, 394));
        gridLayout_3 = new QGridLayout(aireDeDessin);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        dessin = new QWidget(aireDeDessin);
        dessin->setObjectName(QStringLiteral("dessin"));

        gridLayout_3->addWidget(dessin, 0, 0, 1, 1);

        scrollArea->setWidget(aireDeDessin);

        gridLayout->addWidget(scrollArea, 0, 1, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
        gridLayout_2->setContentsMargins(-1, 75, 0, 75);
        histogramme = new QPushButton(centralWidget);
        histogramme->setObjectName(QStringLiteral("histogramme"));
        histogramme->setAutoFillBackground(false);
        histogramme->setAutoDefault(false);
        histogramme->setDefault(false);
        histogramme->setFlat(false);

        gridLayout_2->addWidget(histogramme, 11, 0, 1, 1);

        flou = new QPushButton(centralWidget);
        flou->setObjectName(QStringLiteral("flou"));
        flou->setAutoFillBackground(false);
        flou->setAutoDefault(false);
        flou->setDefault(false);
        flou->setFlat(false);

        gridLayout_2->addWidget(flou, 7, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 0, 0, 1, 1);

        fusion = new QPushButton(centralWidget);
        fusion->setObjectName(QStringLiteral("fusion"));
        fusion->setAutoFillBackground(false);
        fusion->setAutoDefault(false);
        fusion->setDefault(false);
        fusion->setFlat(false);

        gridLayout_2->addWidget(fusion, 8, 0, 1, 1);

        ouvrir = new QPushButton(centralWidget);
        ouvrir->setObjectName(QStringLiteral("ouvrir"));
        ouvrir->setAutoFillBackground(false);
        ouvrir->setAutoDefault(false);
        ouvrir->setDefault(false);
        ouvrir->setFlat(false);

        gridLayout_2->addWidget(ouvrir, 1, 0, 1, 1);

        pipette = new QPushButton(centralWidget);
        pipette->setObjectName(QStringLiteral("pipette"));
        pipette->setAutoFillBackground(false);
        pipette->setAutoDefault(false);
        pipette->setDefault(false);
        pipette->setFlat(false);

        gridLayout_2->addWidget(pipette, 5, 0, 1, 1);

        enregistrer = new QPushButton(centralWidget);
        enregistrer->setObjectName(QStringLiteral("enregistrer"));
        enregistrer->setAutoFillBackground(false);
        enregistrer->setAutoDefault(false);
        enregistrer->setDefault(false);
        enregistrer->setFlat(false);

        gridLayout_2->addWidget(enregistrer, 3, 0, 1, 1);

        couper = new QPushButton(centralWidget);
        couper->setObjectName(QStringLiteral("couper"));
        couper->setAutoFillBackground(false);
        couper->setAutoDefault(false);
        couper->setDefault(false);
        couper->setFlat(false);

        gridLayout_2->addWidget(couper, 4, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 13, 0, 1, 1);

        gris = new QPushButton(centralWidget);
        gris->setObjectName(QStringLiteral("gris"));
        gris->setAutoFillBackground(false);
        gris->setAutoDefault(false);
        gris->setDefault(false);
        gris->setFlat(false);

        gridLayout_2->addWidget(gris, 6, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 688, 19));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        menu_dition = new QMenu(menuBar);
        menu_dition->setObjectName(QStringLiteral("menu_dition"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menu_dition->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFichier->addAction(actionOuvrir_2);
        menuFichier->addAction(actionEnregistrer);
        menuFichier->addAction(actionEnregistrer_sous);
        menuFichier->addAction(actionFermer);
        menuFichier->addSeparator();
        menu_dition->addAction(actionHistogramme);
        menu_dition->addAction(actionNiveau_de_gris);
        menu_dition->addAction(actionFlou);
        menu_dition->addAction(actionFusion);
        menu_dition->addAction(actionPipette);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionEnregistrer->setText(QApplication::translate("MainWindow", "enregistrer", 0));
        actionFermer->setText(QApplication::translate("MainWindow", "fermer", 0));
        actionEnregistrer_sous->setText(QApplication::translate("MainWindow", "enregistrer sous", 0));
        actionKjshg->setText(QApplication::translate("MainWindow", "kjshg", 0));
        actionOuvrir_2->setText(QApplication::translate("MainWindow", "ouvrir", 0));
        actionHistogramme->setText(QApplication::translate("MainWindow", "histogramme", 0));
        actionNiveau_de_gris->setText(QApplication::translate("MainWindow", "niveau de gris", 0));
        actionFlou->setText(QApplication::translate("MainWindow", "flou", 0));
        actionFusion->setText(QApplication::translate("MainWindow", "fusion", 0));
        actionPipette->setText(QApplication::translate("MainWindow", "pipette", 0));
        histogramme->setText(QApplication::translate("MainWindow", "PushButton", 0));
        flou->setText(QApplication::translate("MainWindow", "PushButton", 0));
        fusion->setText(QApplication::translate("MainWindow", "PushButton", 0));
        ouvrir->setText(QApplication::translate("MainWindow", "PushButton", 0));
        pipette->setText(QApplication::translate("MainWindow", "PushButton", 0));
        enregistrer->setText(QApplication::translate("MainWindow", "PushButton", 0));
        couper->setText(QApplication::translate("MainWindow", "PushButton", 0));
        gris->setText(QApplication::translate("MainWindow", "PushButton", 0));
        menuFichier->setTitle(QApplication::translate("MainWindow", "fichier", 0));
        menu_dition->setTitle(QApplication::translate("MainWindow", "\303\251dition", 0));
        menuAbout->setTitle(QApplication::translate("MainWindow", "about", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
