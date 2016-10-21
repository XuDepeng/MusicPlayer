/****************************************************************************
** Meta object code from reading C++ file 'MusicPlayer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MusicPlayer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MusicPlayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MusicPlayer_t {
    QByteArrayData data[29];
    char stringdata0[276];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MusicPlayer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MusicPlayer_t qt_meta_stringdata_MusicPlayer = {
    {
QT_MOC_LITERAL(0, 0, 11), // "MusicPlayer"
QT_MOC_LITERAL(1, 12, 12), // "songFinished"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 15), // "positionChanged"
QT_MOC_LITERAL(4, 42, 8), // "Position"
QT_MOC_LITERAL(5, 51, 4), // "play"
QT_MOC_LITERAL(6, 56, 8), // "songName"
QT_MOC_LITERAL(7, 65, 5), // "pause"
QT_MOC_LITERAL(8, 71, 6), // "resume"
QT_MOC_LITERAL(9, 78, 4), // "stop"
QT_MOC_LITERAL(10, 83, 9), // "setVolume"
QT_MOC_LITERAL(11, 93, 3), // "vol"
QT_MOC_LITERAL(12, 97, 11), // "setPosition"
QT_MOC_LITERAL(13, 109, 8), // "position"
QT_MOC_LITERAL(14, 118, 10), // "setLowFreq"
QT_MOC_LITERAL(15, 129, 4), // "freq"
QT_MOC_LITERAL(16, 134, 13), // "setLowmidFreq"
QT_MOC_LITERAL(17, 148, 10), // "setMidFreq"
QT_MOC_LITERAL(18, 159, 14), // "setMidhighFreq"
QT_MOC_LITERAL(19, 174, 11), // "setHighFreq"
QT_MOC_LITERAL(20, 186, 17), // "setExtremhighFreq"
QT_MOC_LITERAL(21, 204, 9), // "setReverb"
QT_MOC_LITERAL(22, 214, 6), // "reverb"
QT_MOC_LITERAL(23, 221, 7), // "setEcho"
QT_MOC_LITERAL(24, 229, 9), // "isEnabled"
QT_MOC_LITERAL(25, 239, 9), // "setRotate"
QT_MOC_LITERAL(26, 249, 10), // "setFlanger"
QT_MOC_LITERAL(27, 260, 8), // "isEnaled"
QT_MOC_LITERAL(28, 269, 6) // "update"

    },
    "MusicPlayer\0songFinished\0\0positionChanged\0"
    "Position\0play\0songName\0pause\0resume\0"
    "stop\0setVolume\0vol\0setPosition\0position\0"
    "setLowFreq\0freq\0setLowmidFreq\0setMidFreq\0"
    "setMidhighFreq\0setHighFreq\0setExtremhighFreq\0"
    "setReverb\0reverb\0setEcho\0isEnabled\0"
    "setRotate\0setFlanger\0isEnaled\0update"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MusicPlayer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  109,    2, 0x06 /* Public */,
       3,    1,  110,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,  113,    2, 0x0a /* Public */,
       7,    0,  116,    2, 0x0a /* Public */,
       8,    0,  117,    2, 0x0a /* Public */,
       9,    0,  118,    2, 0x0a /* Public */,
      10,    1,  119,    2, 0x0a /* Public */,
      12,    1,  122,    2, 0x0a /* Public */,
      14,    1,  125,    2, 0x0a /* Public */,
      16,    1,  128,    2, 0x0a /* Public */,
      17,    1,  131,    2, 0x0a /* Public */,
      18,    1,  134,    2, 0x0a /* Public */,
      19,    1,  137,    2, 0x0a /* Public */,
      20,    1,  140,    2, 0x0a /* Public */,
      21,    1,  143,    2, 0x0a /* Public */,
      23,    1,  146,    2, 0x0a /* Public */,
      25,    1,  149,    2, 0x0a /* Public */,
      26,    1,  152,    2, 0x0a /* Public */,
      28,    0,  155,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Bool,   27,
    QMetaType::Void,

       0        // eod
};

void MusicPlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MusicPlayer *_t = static_cast<MusicPlayer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->songFinished(); break;
        case 1: _t->positionChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->play((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->pause(); break;
        case 4: _t->resume(); break;
        case 5: _t->stop(); break;
        case 6: _t->setVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setPosition((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setLowFreq((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->setLowmidFreq((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->setMidFreq((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->setMidhighFreq((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->setHighFreq((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->setExtremhighFreq((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->setReverb((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->setEcho((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->setRotate((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->setFlanger((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->update(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MusicPlayer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MusicPlayer::songFinished)) {
                *result = 0;
            }
        }
        {
            typedef void (MusicPlayer::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MusicPlayer::positionChanged)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject MusicPlayer::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_MusicPlayer.data,
      qt_meta_data_MusicPlayer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MusicPlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MusicPlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MusicPlayer.stringdata0))
        return static_cast<void*>(const_cast< MusicPlayer*>(this));
    return QThread::qt_metacast(_clname);
}

int MusicPlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void MusicPlayer::songFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MusicPlayer::positionChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
