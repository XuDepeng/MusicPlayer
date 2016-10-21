/****************************************************************************
** Meta object code from reading C++ file 'MusicPlaylist.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MusicPlaylist.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MusicPlaylist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MusicPlaylist_t {
    QByteArrayData data[11];
    char stringdata0[151];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MusicPlaylist_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MusicPlaylist_t qt_meta_stringdata_MusicPlaylist = {
    {
QT_MOC_LITERAL(0, 0, 13), // "MusicPlaylist"
QT_MOC_LITERAL(1, 14, 14), // "sigPlayCurSong"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 5), // "index"
QT_MOC_LITERAL(4, 36, 15), // "sigPauseCurSong"
QT_MOC_LITERAL(5, 52, 16), // "sigDeleteCurSong"
QT_MOC_LITERAL(6, 69, 14), // "sigViewCurSong"
QT_MOC_LITERAL(7, 84, 15), // "slotPlayCurSong"
QT_MOC_LITERAL(8, 100, 16), // "slotPauseCurSong"
QT_MOC_LITERAL(9, 117, 17), // "slotDeleteCurSong"
QT_MOC_LITERAL(10, 135, 15) // "slotViewCurSong"

    },
    "MusicPlaylist\0sigPlayCurSong\0\0index\0"
    "sigPauseCurSong\0sigDeleteCurSong\0"
    "sigViewCurSong\0slotPlayCurSong\0"
    "slotPauseCurSong\0slotDeleteCurSong\0"
    "slotViewCurSong"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MusicPlaylist[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,
       5,    1,   60,    2, 0x06 /* Public */,
       6,    1,   63,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   66,    2, 0x08 /* Private */,
       8,    0,   67,    2, 0x08 /* Private */,
       9,    0,   68,    2, 0x08 /* Private */,
      10,    0,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MusicPlaylist::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MusicPlaylist *_t = static_cast<MusicPlaylist *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigPlayCurSong((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sigPauseCurSong((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->sigDeleteCurSong((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->sigViewCurSong((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->slotPlayCurSong(); break;
        case 5: _t->slotPauseCurSong(); break;
        case 6: _t->slotDeleteCurSong(); break;
        case 7: _t->slotViewCurSong(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MusicPlaylist::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MusicPlaylist::sigPlayCurSong)) {
                *result = 0;
            }
        }
        {
            typedef void (MusicPlaylist::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MusicPlaylist::sigPauseCurSong)) {
                *result = 1;
            }
        }
        {
            typedef void (MusicPlaylist::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MusicPlaylist::sigDeleteCurSong)) {
                *result = 2;
            }
        }
        {
            typedef void (MusicPlaylist::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MusicPlaylist::sigViewCurSong)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject MusicPlaylist::staticMetaObject = {
    { &QTableWidget::staticMetaObject, qt_meta_stringdata_MusicPlaylist.data,
      qt_meta_data_MusicPlaylist,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MusicPlaylist::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MusicPlaylist::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MusicPlaylist.stringdata0))
        return static_cast<void*>(const_cast< MusicPlaylist*>(this));
    return QTableWidget::qt_metacast(_clname);
}

int MusicPlaylist::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void MusicPlaylist::sigPlayCurSong(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MusicPlaylist::sigPauseCurSong(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MusicPlaylist::sigDeleteCurSong(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MusicPlaylist::sigViewCurSong(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
