#-------------------------------------------------
#
# Project created by QtCreator 2015-01-05T10:30:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH = /usr/include/opencv2 \

LIBS +=-lopencv_core \
    -lopencv_imgproc \
    -lopencv_highgui \
    -lopencv_ml \
    -lopencv_video \
    -lopencv_features2d \
    -lopencv_calib3d \
    -lopencv_objdetect \
    -lopencv_contrib \
    -lopencv_legacy \
    -lopencv_flann \

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
    fenseamcarving.cpp \
    chemin.cpp \
    listechemins.cpp \
    segmentation.cpp \
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
    fenseamcarving.h \
    chemin.h \
    listechemins.h \
    segmentation.h \
    copier.h \
    fusioncalques.h

FORMS    += mainwindow.ui \
    diagramcolorwindow.ui \
    contraste.ui \
    filtreperso.ui \
    redimensionnement.ui \
    fenseamcarving.ui \
    segmentation.ui

RESOURCES += \
    resources.qrc
