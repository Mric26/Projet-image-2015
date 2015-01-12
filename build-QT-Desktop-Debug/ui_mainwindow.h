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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "mygraphicsview.h"

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
    QAction *actionFusion;
    QAction *actionPipette;
    QAction *actionFlouGaussLeger;
    QAction *actionFlouGaussMoyen;
    QAction *actionFlouGaussFort;
    QAction *actionPasse_haut;
    QAction *actionLeger;
    QAction *actionL;
    QAction *actionFlouMoyLeger;
    QAction *actionFlouMoyMoyen;
    QAction *actionFlouMoyFort;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
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
    MyGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menu_dition;
    QMenu *menuFiltres;
    QMenu *menuFlou_2;
    QMenu *menuGaussien;
    QMenu *menuMoyenneur;
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
        actionFusion = new QAction(MainWindow);
        actionFusion->setObjectName(QStringLiteral("actionFusion"));
        actionPipette = new QAction(MainWindow);
        actionPipette->setObjectName(QStringLiteral("actionPipette"));
        actionFlouGaussLeger = new QAction(MainWindow);
        actionFlouGaussLeger->setObjectName(QStringLiteral("actionFlouGaussLeger"));
        actionFlouGaussMoyen = new QAction(MainWindow);
        actionFlouGaussMoyen->setObjectName(QStringLiteral("actionFlouGaussMoyen"));
        actionFlouGaussFort = new QAction(MainWindow);
        actionFlouGaussFort->setObjectName(QStringLiteral("actionFlouGaussFort"));
        actionPasse_haut = new QAction(MainWindow);
        actionPasse_haut->setObjectName(QStringLiteral("actionPasse_haut"));
        actionLeger = new QAction(MainWindow);
        actionLeger->setObjectName(QStringLiteral("actionLeger"));
        actionL = new QAction(MainWindow);
        actionL->setObjectName(QStringLiteral("actionL"));
        actionFlouMoyLeger = new QAction(MainWindow);
        actionFlouMoyLeger->setObjectName(QStringLiteral("actionFlouMoyLeger"));
        actionFlouMoyMoyen = new QAction(MainWindow);
        actionFlouMoyMoyen->setObjectName(QStringLiteral("actionFlouMoyMoyen"));
        actionFlouMoyFort = new QAction(MainWindow);
        actionFlouMoyFort->setObjectName(QStringLiteral("actionFlouMoyFort"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
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
        couper->setCheckable(false);
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

        graphicsView = new MyGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(graphicsView, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 688, 29));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        menu_dition = new QMenu(menuBar);
        menu_dition->setObjectName(QStringLiteral("menu_dition"));
        menuFiltres = new QMenu(menu_dition);
        menuFiltres->setObjectName(QStringLiteral("menuFiltres"));
        menuFlou_2 = new QMenu(menuFiltres);
        menuFlou_2->setObjectName(QStringLiteral("menuFlou_2"));
        menuGaussien = new QMenu(menuFlou_2);
        menuGaussien->setObjectName(QStringLiteral("menuGaussien"));
        menuMoyenneur = new QMenu(menuFlou_2);
        menuMoyenneur->setObjectName(QStringLiteral("menuMoyenneur"));
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
        menu_dition->addAction(actionFusion);
        menu_dition->addAction(actionPipette);
        menu_dition->addAction(menuFiltres->menuAction());
        menuFiltres->addAction(actionPasse_haut);
        menuFiltres->addAction(menuFlou_2->menuAction());
        menuFlou_2->addAction(menuGaussien->menuAction());
        menuFlou_2->addAction(menuMoyenneur->menuAction());
        menuGaussien->addAction(actionFlouGaussLeger);
        menuGaussien->addAction(actionFlouGaussMoyen);
        menuGaussien->addAction(actionFlouGaussFort);
        menuMoyenneur->addAction(actionFlouMoyLeger);
        menuMoyenneur->addAction(actionFlouMoyMoyen);
        menuMoyenneur->addAction(actionFlouMoyFort);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Projet Image", 0));
        actionEnregistrer->setText(QApplication::translate("MainWindow", "enregistrer", 0));
        actionFermer->setText(QApplication::translate("MainWindow", "fermer", 0));
        actionEnregistrer_sous->setText(QApplication::translate("MainWindow", "enregistrer sous", 0));
        actionKjshg->setText(QApplication::translate("MainWindow", "kjshg", 0));
        actionOuvrir_2->setText(QApplication::translate("MainWindow", "ouvrir", 0));
        actionHistogramme->setText(QApplication::translate("MainWindow", "histogramme", 0));
        actionNiveau_de_gris->setText(QApplication::translate("MainWindow", "niveau de gris", 0));
        actionFusion->setText(QApplication::translate("MainWindow", "fusion", 0));
        actionPipette->setText(QApplication::translate("MainWindow", "pipette", 0));
        actionFlouGaussLeger->setText(QApplication::translate("MainWindow", "l\303\251ger", 0));
        actionFlouGaussMoyen->setText(QApplication::translate("MainWindow", "moyen", 0));
        actionFlouGaussFort->setText(QApplication::translate("MainWindow", "fort", 0));
        actionPasse_haut->setText(QApplication::translate("MainWindow", "passe haut", 0));
        actionLeger->setText(QApplication::translate("MainWindow", "leger", 0));
        actionL->setText(QApplication::translate("MainWindow", "l", 0));
        actionFlouMoyLeger->setText(QApplication::translate("MainWindow", "leger", 0));
        actionFlouMoyMoyen->setText(QApplication::translate("MainWindow", "moyen", 0));
        actionFlouMoyFort->setText(QApplication::translate("MainWindow", "fort", 0));
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
        menuFiltres->setTitle(QApplication::translate("MainWindow", "filtres", 0));
        menuFlou_2->setTitle(QApplication::translate("MainWindow", "flou", 0));
        menuGaussien->setTitle(QApplication::translate("MainWindow", "gaussien", 0));
        menuMoyenneur->setTitle(QApplication::translate("MainWindow", "moyenneur", 0));
        menuAbout->setTitle(QApplication::translate("MainWindow", "about", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
