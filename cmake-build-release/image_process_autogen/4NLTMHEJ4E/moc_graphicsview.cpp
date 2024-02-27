/****************************************************************************
** Meta object code from reading C++ file 'graphicsview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../graphics/graphicsview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphicsview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_graphicsview_t {
    QByteArrayData data[11];
    char stringdata0[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_graphicsview_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_graphicsview_t qt_meta_stringdata_graphicsview = {
    {
QT_MOC_LITERAL(0, 0, 12), // "graphicsview"
QT_MOC_LITERAL(1, 13, 9), // "drawImage"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 8), // "beginPos"
QT_MOC_LITERAL(4, 33, 7), // "nextPos"
QT_MOC_LITERAL(5, 41, 4), // "type"
QT_MOC_LITERAL(6, 46, 5), // "state"
QT_MOC_LITERAL(7, 52, 5), // "CtrlZ"
QT_MOC_LITERAL(8, 58, 6), // "Delete"
QT_MOC_LITERAL(9, 65, 5), // "CtrlV"
QT_MOC_LITERAL(10, 71, 15) // "shutdownErasing"

    },
    "graphicsview\0drawImage\0\0beginPos\0"
    "nextPos\0type\0state\0CtrlZ\0Delete\0CtrlV\0"
    "shutdownErasing"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_graphicsview[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   39,    2, 0x06 /* Public */,
       7,    0,   48,    2, 0x06 /* Public */,
       8,    0,   49,    2, 0x06 /* Public */,
       9,    0,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPointF, QMetaType::QPointF, QMetaType::Int, QMetaType::Int,    3,    4,    5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void graphicsview::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        graphicsview *_t = static_cast<graphicsview *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->drawImage((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< QPointF(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 1: _t->CtrlZ(); break;
        case 2: _t->Delete(); break;
        case 3: _t->CtrlV(); break;
        case 4: _t->shutdownErasing(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (graphicsview::*_t)(QPointF , QPointF , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&graphicsview::drawImage)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (graphicsview::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&graphicsview::CtrlZ)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (graphicsview::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&graphicsview::Delete)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (graphicsview::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&graphicsview::CtrlV)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject graphicsview::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_graphicsview.data,
      qt_meta_data_graphicsview,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *graphicsview::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *graphicsview::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_graphicsview.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int graphicsview::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void graphicsview::drawImage(QPointF _t1, QPointF _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void graphicsview::CtrlZ()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void graphicsview::Delete()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void graphicsview::CtrlV()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
