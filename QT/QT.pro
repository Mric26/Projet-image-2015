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
    diagramcolorwindow.cpp \
    etalement.cpp \
    egalisation.cpp \
    fusion.cpp \
    contraste.cpp \
    filtreperso.cpp \
    rogner.cpp \
    coller.cpp \
    redimensionnement.cpp \
    copier.cpp \
    fusioncalques.cpp

HEADERS  += mainwindow.h \
    open.h \
    save.h \
    couper.h \
    mygraphicsview.h \
    convolution.h \
    grisconvers.h \
    diagramcolorwindow.h \
    etalement.h \
    egalisation.h \
    fusion.h \
    contraste.h \
    filtreperso.h \
    rogner.h \
    coller.h \
    redimensionnement.h \
    copier.h \
    fusioncalques.h

FORMS    += mainwindow.ui \
    diagramcolorwindow.ui \
    contraste.ui \
    filtreperso.ui \
    redimensionnement.ui

RESOURCES += \
    resources.qrc
