/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cuda_test/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata0[338];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 24), // "on_actionAbrir_triggered"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 10), // "rutaImagen"
QT_MOC_LITERAL(4, 48, 19), // "on_infoCuda_clicked"
QT_MOC_LITERAL(5, 68, 23), // "on_button_sobel_clicked"
QT_MOC_LITERAL(6, 92, 31), // "on_actionAbrir_Filtro_triggered"
QT_MOC_LITERAL(7, 124, 10), // "rutaFiltro"
QT_MOC_LITERAL(8, 135, 25), // "on_actionCerrar_triggered"
QT_MOC_LITERAL(9, 161, 24), // "on_actionSalir_triggered"
QT_MOC_LITERAL(10, 186, 30), // "on_actionConvolucion_triggered"
QT_MOC_LITERAL(11, 217, 15), // "mousePressEvent"
QT_MOC_LITERAL(12, 233, 12), // "QMouseEvent*"
QT_MOC_LITERAL(13, 246, 1), // "e"
QT_MOC_LITERAL(14, 248, 28), // "on_actionBilinieal_triggered"
QT_MOC_LITERAL(15, 277, 26), // "on_actionGuardar_triggered"
QT_MOC_LITERAL(16, 304, 33) // "on_actionCorreccion_Bil_trigg..."

    },
    "MainWindow\0on_actionAbrir_triggered\0"
    "\0rutaImagen\0on_infoCuda_clicked\0"
    "on_button_sobel_clicked\0"
    "on_actionAbrir_Filtro_triggered\0"
    "rutaFiltro\0on_actionCerrar_triggered\0"
    "on_actionSalir_triggered\0"
    "on_actionConvolucion_triggered\0"
    "mousePressEvent\0QMouseEvent*\0e\0"
    "on_actionBilinieal_triggered\0"
    "on_actionGuardar_triggered\0"
    "on_actionCorreccion_Bil_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x0a /* Public */,
       1,    0,   82,    2, 0x2a /* Public | MethodCloned */,
       4,    0,   83,    2, 0x08 /* Private */,
       5,    0,   84,    2, 0x08 /* Private */,
       6,    1,   85,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x28 /* Private | MethodCloned */,
       8,    0,   89,    2, 0x08 /* Private */,
       9,    0,   90,    2, 0x08 /* Private */,
      10,    0,   91,    2, 0x08 /* Private */,
      11,    1,   92,    2, 0x08 /* Private */,
      14,    0,   95,    2, 0x08 /* Private */,
      15,    0,   96,    2, 0x08 /* Private */,
      16,    0,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionAbrir_triggered((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_actionAbrir_triggered(); break;
        case 2: _t->on_infoCuda_clicked(); break;
        case 3: _t->on_button_sobel_clicked(); break;
        case 4: _t->on_actionAbrir_Filtro_triggered((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->on_actionAbrir_Filtro_triggered(); break;
        case 6: _t->on_actionCerrar_triggered(); break;
        case 7: _t->on_actionSalir_triggered(); break;
        case 8: _t->on_actionConvolucion_triggered(); break;
        case 9: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 10: _t->on_actionBilinieal_triggered(); break;
        case 11: _t->on_actionGuardar_triggered(); break;
        case 12: _t->on_actionCorreccion_Bil_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
