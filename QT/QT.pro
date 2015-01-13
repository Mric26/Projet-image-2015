#-------------------------------------------------
#
# Project created by QtCreator 2015-01-05T10:30:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QT
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    open.cpp \
    save.cpp \
    couper.cpp \
    mygraphicsview.cpp \
    convolution.cpp \
    grisconvers.cpp \
    histogrammes.cpp \
    diagramcolorwindow.cpp

HEADERS  += mainwindow.h \
    open.h \
    save.h \
    couper.h \
    mygraphicsview.h \
    convolution.h \
    grisconvers.h \
    histogrammes.h \
    diagramcolorwindow.h

FORMS    += mainwindow.ui \
    diagramcolorwindow.ui

RESOURCES += \
    resources.qrc
