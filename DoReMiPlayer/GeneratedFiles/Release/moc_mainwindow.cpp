/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DoReMiPlayer_t {
    QByteArrayData data[22];
    char stringdata0[239];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DoReMiPlayer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DoReMiPlayer_t qt_meta_stringdata_DoReMiPlayer = {
    {
QT_MOC_LITERAL(0, 0, 12), // "DoReMiPlayer"
QT_MOC_LITERAL(1, 13, 7), // "addSong"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 12), // "WebMusicInfo"
QT_MOC_LITERAL(4, 35, 8), // "addSongs"
QT_MOC_LITERAL(5, 44, 11), // "addPlaylist"
QT_MOC_LITERAL(6, 56, 12), // "savePlayList"
QT_MOC_LITERAL(7, 69, 14), // "searchPlaylist"
QT_MOC_LITERAL(8, 84, 12), // "sortPlayList"
QT_MOC_LITERAL(9, 97, 8), // "SortMode"
QT_MOC_LITERAL(10, 106, 4), // "mode"
QT_MOC_LITERAL(11, 111, 8), // "playSong"
QT_MOC_LITERAL(12, 120, 9), // "pauseSong"
QT_MOC_LITERAL(13, 130, 11), // "playPreSong"
QT_MOC_LITERAL(14, 142, 12), // "playNextSong"
QT_MOC_LITERAL(15, 155, 10), // "deleteSong"
QT_MOC_LITERAL(16, 166, 14), // "updateMediaPos"
QT_MOC_LITERAL(17, 181, 6), // "curPos"
QT_MOC_LITERAL(18, 188, 9), // "updateLrc"
QT_MOC_LITERAL(19, 198, 9), // "createTab"
QT_MOC_LITERAL(20, 208, 14), // "createSoundEff"
QT_MOC_LITERAL(21, 223, 15) // "createWebSearch"

    },
    "DoReMiPlayer\0addSong\0\0WebMusicInfo\0"
    "addSongs\0addPlaylist\0savePlayList\0"
    "searchPlaylist\0sortPlayList\0SortMode\0"
    "mode\0playSong\0pauseSong\0playPreSong\0"
    "playNextSong\0deleteSong\0updateMediaPos\0"
    "curPos\0updateLrc\0createTab\0createSoundEff\0"
    "createWebSearch"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DoReMiPlayer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x08 /* Private */,
       4,    0,   97,    2, 0x08 /* Private */,
       5,    0,   98,    2, 0x08 /* Private */,
       6,    0,   99,    2, 0x08 /* Private */,
       7,    0,  100,    2, 0x08 /* Private */,
       8,    1,  101,    2, 0x08 /* Private */,
      11,    1,  104,    2, 0x08 /* Private */,
      12,    0,  107,    2, 0x08 /* Private */,
      13,    0,  108,    2, 0x08 /* Private */,
      14,    0,  109,    2, 0x08 /* Private */,
      15,    1,  110,    2, 0x08 /* Private */,
      16,    1,  113,    2, 0x08 /* Private */,
      18,    1,  116,    2, 0x08 /* Private */,
      19,    0,  119,    2, 0x08 /* Private */,
      20,    0,  120,    2, 0x08 /* Private */,
      21,    0,  121,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DoReMiPlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DoReMiPlayer *_t = static_cast<DoReMiPlayer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addSong((*reinterpret_cast< WebMusicInfo(*)>(_a[1]))); break;
        case 1: _t->addSongs(); break;
        case 2: _t->addPlaylist(); break;
        case 3: _t->savePlayList(); break;
        case 4: _t->searchPlaylist(); break;
        case 5: _t->sortPlayList((*reinterpret_cast< SortMode(*)>(_a[1]))); break;
        case 6: _t->playSong((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->pauseSong(); break;
        case 8: _t->playPreSong(); break;
        case 9: _t->playNextSong(); break;
        case 10: _t->deleteSong((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->updateMediaPos((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->updateLrc((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->createTab(); break;
        case 14: _t->createSoundEff(); break;
        case 15: _t->createWebSearch(); break;
        default: ;
        }
    }
}

const QMetaObject DoReMiPlayer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_DoReMiPlayer.data,
      qt_meta_data_DoReMiPlayer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DoReMiPlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DoReMiPlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DoReMiPlayer.stringdata0))
        return static_cast<void*>(const_cast< DoReMiPlayer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int DoReMiPlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
