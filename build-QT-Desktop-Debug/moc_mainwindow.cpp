/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../QT/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[16];
    char stringdata[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 3),
QT_MOC_LITERAL(2, 15, 0),
QT_MOC_LITERAL(3, 16, 4),
QT_MOC_LITERAL(4, 21, 6),
QT_MOC_LITERAL(5, 28, 6),
QT_MOC_LITERAL(6, 35, 4),
QT_MOC_LITERAL(7, 40, 9),
QT_MOC_LITERAL(8, 50, 14),
QT_MOC_LITERAL(9, 65, 14),
QT_MOC_LITERAL(10, 80, 13),
QT_MOC_LITERAL(11, 94, 12),
QT_MOC_LITERAL(12, 107, 12),
QT_MOC_LITERAL(13, 120, 11),
QT_MOC_LITERAL(14, 132, 9),
QT_MOC_LITERAL(15, 142, 12)
    },
    "MainWindow\0ouv\0\0save\0saveAs\0couper\0"
    "gris\0showHisto\0flouGaussLeger\0"
    "flouGaussMoyen\0flouGaussFort\0flouMoyLeger\0"
    "flouMoyMoyen\0flouMoyFort\0passeHaut\0"
    "rehaussement\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x0a,
       3,    0,   85,    2, 0x0a,
       4,    0,   86,    2, 0x0a,
       5,    0,   87,    2, 0x0a,
       6,    0,   88,    2, 0x0a,
       7,    0,   89,    2, 0x0a,
       8,    0,   90,    2, 0x0a,
       9,    0,   91,    2, 0x0a,
      10,    0,   92,    2, 0x0a,
      11,    0,   93,    2, 0x0a,
      12,    0,   94,    2, 0x0a,
      13,    0,   95,    2, 0x0a,
      14,    0,   96,    2, 0x0a,
      15,    0,   97,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->ouv(); break;
        case 1: _t->save(); break;
        case 2: _t->saveAs(); break;
        case 3: _t->couper(); break;
        case 4: _t->gris(); break;
        case 5: _t->showHisto(); break;
        case 6: _t->flouGaussLeger(); break;
        case 7: _t->flouGaussMoyen(); break;
        case 8: _t->flouGaussFort(); break;
        case 9: _t->flouMoyLeger(); break;
        case 10: _t->flouMoyMoyen(); break;
        case 11: _t->flouMoyFort(); break;
        case 12: _t->passeHaut(); break;
        case 13: _t->rehaussement(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
