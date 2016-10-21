/****************************************************************************
** Meta object code from reading C++ file 'WebSearchDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../WebSearchDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WebSearchDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WebSearchDialog_t {
    QByteArrayData data[11];
    char stringdata0[136];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WebSearchDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WebSearchDialog_t qt_meta_stringdata_WebSearchDialog = {
    {
QT_MOC_LITERAL(0, 0, 15), // "WebSearchDialog"
QT_MOC_LITERAL(1, 16, 14), // "searchFinished"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 14), // "sigPlayCurSong"
QT_MOC_LITERAL(4, 47, 12), // "WebMusicInfo"
QT_MOC_LITERAL(5, 60, 13), // "sigAddCurSong"
QT_MOC_LITERAL(6, 74, 9), // "searchWeb"
QT_MOC_LITERAL(7, 84, 14), // "showWebResults"
QT_MOC_LITERAL(8, 99, 15), // "slotPlayCurSong"
QT_MOC_LITERAL(9, 115, 5), // "index"
QT_MOC_LITERAL(10, 121, 14) // "slotAddCurSong"

    },
    "WebSearchDialog\0searchFinished\0\0"
    "sigPlayCurSong\0WebMusicInfo\0sigAddCurSong\0"
    "searchWeb\0showWebResults\0slotPlayCurSong\0"
    "index\0slotAddCurSong"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WebSearchDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    1,   50,    2, 0x06 /* Public */,
       5,    1,   53,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   56,    2, 0x08 /* Private */,
       7,    0,   57,    2, 0x08 /* Private */,
       8,    1,   58,    2, 0x08 /* Private */,
      10,    1,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 4,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,

       0        // eod
};

void WebSearchDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WebSearchDialog *_t = static_cast<WebSearchDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->searchFinished(); break;
        case 1: _t->sigPlayCurSong((*reinterpret_cast< WebMusicInfo(*)>(_a[1]))); break;
        case 2: _t->sigAddCurSong((*reinterpret_cast< WebMusicInfo(*)>(_a[1]))); break;
        case 3: _t->searchWeb(); break;
        case 4: _t->showWebResults(); break;
        case 5: _t->slotPlayCurSong((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->slotAddCurSong((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WebSearchDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WebSearchDialog::searchFinished)) {
                *result = 0;
            }
        }
        {
            typedef void (WebSearchDialog::*_t)(WebMusicInfo );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WebSearchDialog::sigPlayCurSong)) {
                *result = 1;
            }
        }
        {
            typedef void (WebSearchDialog::*_t)(WebMusicInfo );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WebSearchDialog::sigAddCurSong)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject WebSearchDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_WebSearchDialog.data,
      qt_meta_data_WebSearchDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WebSearchDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WebSearchDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WebSearchDialog.stringdata0))
        return static_cast<void*>(const_cast< WebSearchDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int WebSearchDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void WebSearchDialog::searchFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void WebSearchDialog::sigPlayCurSong(WebMusicInfo _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void WebSearchDialog::sigAddCurSong(WebMusicInfo _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
