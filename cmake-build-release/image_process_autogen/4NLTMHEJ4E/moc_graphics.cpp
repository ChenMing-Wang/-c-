/****************************************************************************
** Meta object code from reading C++ file 'graphics.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../graphics/graphics.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphics.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QGraphics_t {
    QByteArrayData data[19];
    char stringdata0[233];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGraphics_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGraphics_t qt_meta_stringdata_QGraphics = {
    {
QT_MOC_LITERAL(0, 0, 9), // "QGraphics"
QT_MOC_LITERAL(1, 10, 9), // "saveImage"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 10), // "reAddItems"
QT_MOC_LITERAL(4, 32, 13), // "sendImageType"
QT_MOC_LITERAL(5, 46, 4), // "type"
QT_MOC_LITERAL(6, 51, 14), // "shutdownEraser"
QT_MOC_LITERAL(7, 66, 13), // "drawPolyLines"
QT_MOC_LITERAL(8, 80, 8), // "drawRect"
QT_MOC_LITERAL(9, 89, 10), // "drawEraser"
QT_MOC_LITERAL(10, 100, 9), // "showImage"
QT_MOC_LITERAL(11, 110, 4), // "edit"
QT_MOC_LITERAL(12, 115, 18), // "valueChangedSliver"
QT_MOC_LITERAL(13, 134, 5), // "value"
QT_MOC_LITERAL(14, 140, 14), // "valueChangedCu"
QT_MOC_LITERAL(15, 155, 20), // "saveThresholdMessage"
QT_MOC_LITERAL(16, 176, 19), // "checkBoxStateChange"
QT_MOC_LITERAL(17, 196, 3), // "arg"
QT_MOC_LITERAL(18, 200, 32) // "saveThresholdImageAndInformation"

    },
    "QGraphics\0saveImage\0\0reAddItems\0"
    "sendImageType\0type\0shutdownEraser\0"
    "drawPolyLines\0drawRect\0drawEraser\0"
    "showImage\0edit\0valueChangedSliver\0"
    "value\0valueChangedCu\0saveThresholdMessage\0"
    "checkBoxStateChange\0arg\0"
    "saveThresholdImageAndInformation"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGraphics[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    0,   85,    2, 0x06 /* Public */,
       4,    1,   86,    2, 0x06 /* Public */,
       6,    0,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   90,    2, 0x08 /* Private */,
       8,    0,   91,    2, 0x08 /* Private */,
       9,    0,   92,    2, 0x08 /* Private */,
      10,    0,   93,    2, 0x08 /* Private */,
      11,    0,   94,    2, 0x08 /* Private */,
      12,    1,   95,    2, 0x08 /* Private */,
      14,    1,   98,    2, 0x08 /* Private */,
      15,    0,  101,    2, 0x08 /* Private */,
      16,    1,  102,    2, 0x08 /* Private */,
      18,    0,  105,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,

       0        // eod
};

void QGraphics::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QGraphics *_t = static_cast<QGraphics *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->saveImage(); break;
        case 1: _t->reAddItems(); break;
        case 2: _t->sendImageType((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->shutdownEraser(); break;
        case 4: _t->drawPolyLines(); break;
        case 5: _t->drawRect(); break;
        case 6: _t->drawEraser(); break;
        case 7: _t->showImage(); break;
        case 8: _t->edit(); break;
        case 9: _t->valueChangedSliver((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->valueChangedCu((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->saveThresholdMessage(); break;
        case 12: _t->checkBoxStateChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->saveThresholdImageAndInformation(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QGraphics::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QGraphics::saveImage)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QGraphics::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QGraphics::reAddItems)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (QGraphics::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QGraphics::sendImageType)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (QGraphics::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QGraphics::shutdownEraser)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject QGraphics::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_QGraphics.data,
      qt_meta_data_QGraphics,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QGraphics::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGraphics::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGraphics.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int QGraphics::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void QGraphics::saveImage()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QGraphics::reAddItems()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QGraphics::sendImageType(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QGraphics::shutdownEraser()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
