/****************************************************************************
** Meta object code from reading C++ file 'graphicsscene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../graphics/graphicsscene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphicsscene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_graphicsscene_t {
    QByteArrayData data[21];
    char stringdata0[236];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_graphicsscene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_graphicsscene_t qt_meta_stringdata_graphicsscene = {
    {
QT_MOC_LITERAL(0, 0, 13), // "graphicsscene"
QT_MOC_LITERAL(1, 14, 16), // "showUpdatedImage"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 4), // "flag"
QT_MOC_LITERAL(4, 37, 12), // "getImageSort"
QT_MOC_LITERAL(5, 50, 4), // "type"
QT_MOC_LITERAL(6, 55, 11), // "OnDrawImage"
QT_MOC_LITERAL(7, 67, 8), // "beginPos"
QT_MOC_LITERAL(8, 76, 7), // "nextPos"
QT_MOC_LITERAL(9, 84, 5), // "state"
QT_MOC_LITERAL(10, 90, 18), // "moveSelectedObject"
QT_MOC_LITERAL(11, 109, 6), // "PointF"
QT_MOC_LITERAL(12, 116, 21), // "releaseSelectedObject"
QT_MOC_LITERAL(13, 138, 19), // "pasteSelectedObject"
QT_MOC_LITERAL(14, 158, 12), // "deleteObject"
QT_MOC_LITERAL(15, 171, 13), // "getEraserSize"
QT_MOC_LITERAL(16, 185, 4), // "size"
QT_MOC_LITERAL(17, 190, 10), // "saveChange"
QT_MOC_LITERAL(18, 201, 18), // "applyForWholeImage"
QT_MOC_LITERAL(19, 220, 5), // "CtrlZ"
QT_MOC_LITERAL(20, 226, 9) // "reAddItem"

    },
    "graphicsscene\0showUpdatedImage\0\0flag\0"
    "getImageSort\0type\0OnDrawImage\0beginPos\0"
    "nextPos\0state\0moveSelectedObject\0"
    "PointF\0releaseSelectedObject\0"
    "pasteSelectedObject\0deleteObject\0"
    "getEraserSize\0size\0saveChange\0"
    "applyForWholeImage\0CtrlZ\0reAddItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_graphicsscene[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   77,    2, 0x0a /* Public */,
       6,    4,   80,    2, 0x0a /* Public */,
      10,    1,   89,    2, 0x0a /* Public */,
      12,    0,   92,    2, 0x0a /* Public */,
      13,    0,   93,    2, 0x0a /* Public */,
      14,    0,   94,    2, 0x0a /* Public */,
      15,    1,   95,    2, 0x0a /* Public */,
      17,    0,   98,    2, 0x0a /* Public */,
      18,    0,   99,    2, 0x0a /* Public */,
      19,    0,  100,    2, 0x0a /* Public */,
      20,    0,  101,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::QPointF, QMetaType::QPointF, QMetaType::Int, QMetaType::Int,    7,    8,    5,    9,
    QMetaType::Void, QMetaType::QPointF,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void graphicsscene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        graphicsscene *_t = static_cast<graphicsscene *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showUpdatedImage((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->getImageSort((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->OnDrawImage((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< QPointF(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 3: _t->moveSelectedObject((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 4: _t->releaseSelectedObject(); break;
        case 5: _t->pasteSelectedObject(); break;
        case 6: _t->deleteObject(); break;
        case 7: _t->getEraserSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->saveChange(); break;
        case 9: _t->applyForWholeImage(); break;
        case 10: _t->CtrlZ(); break;
        case 11: _t->reAddItem(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (graphicsscene::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&graphicsscene::showUpdatedImage)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject graphicsscene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_graphicsscene.data,
      qt_meta_data_graphicsscene,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *graphicsscene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *graphicsscene::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_graphicsscene.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsScene::qt_metacast(_clname);
}

int graphicsscene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void graphicsscene::showUpdatedImage(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
