/****************************************************************************
** Meta object code from reading C++ file 'SoundEffectDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SoundEffectDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SoundEffectDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SouncEffectDialog_t {
    QByteArrayData data[26];
    char stringdata0[327];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SouncEffectDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SouncEffectDialog_t qt_meta_stringdata_SouncEffectDialog = {
    {
QT_MOC_LITERAL(0, 0, 17), // "SouncEffectDialog"
QT_MOC_LITERAL(1, 18, 14), // "lowFreqChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 4), // "freq"
QT_MOC_LITERAL(4, 39, 14), // "midFreqChanged"
QT_MOC_LITERAL(5, 54, 15), // "highFreqChanged"
QT_MOC_LITERAL(6, 70, 17), // "lowmidFreqChanged"
QT_MOC_LITERAL(7, 88, 18), // "midhighFreqChanged"
QT_MOC_LITERAL(8, 107, 21), // "extremhighFreqChanged"
QT_MOC_LITERAL(9, 129, 13), // "reverbChanged"
QT_MOC_LITERAL(10, 143, 6), // "reverb"
QT_MOC_LITERAL(11, 150, 13), // "rotateChanged"
QT_MOC_LITERAL(12, 164, 9), // "isEnabled"
QT_MOC_LITERAL(13, 174, 11), // "echoChanged"
QT_MOC_LITERAL(14, 186, 14), // "flangerChanged"
QT_MOC_LITERAL(15, 201, 10), // "setLowFreq"
QT_MOC_LITERAL(16, 212, 10), // "setMidFreq"
QT_MOC_LITERAL(17, 223, 11), // "setHighFreq"
QT_MOC_LITERAL(18, 235, 13), // "setLowmidFreq"
QT_MOC_LITERAL(19, 249, 14), // "setMidhighFreq"
QT_MOC_LITERAL(20, 264, 17), // "setExtremhighFreq"
QT_MOC_LITERAL(21, 282, 9), // "setReverb"
QT_MOC_LITERAL(22, 292, 7), // "setEcho"
QT_MOC_LITERAL(23, 300, 9), // "setRotate"
QT_MOC_LITERAL(24, 310, 10), // "setFlanger"
QT_MOC_LITERAL(25, 321, 5) // "reset"

    },
    "SouncEffectDialog\0lowFreqChanged\0\0"
    "freq\0midFreqChanged\0highFreqChanged\0"
    "lowmidFreqChanged\0midhighFreqChanged\0"
    "extremhighFreqChanged\0reverbChanged\0"
    "reverb\0rotateChanged\0isEnabled\0"
    "echoChanged\0flangerChanged\0setLowFreq\0"
    "setMidFreq\0setHighFreq\0setLowmidFreq\0"
    "setMidhighFreq\0setExtremhighFreq\0"
    "setReverb\0setEcho\0setRotate\0setFlanger\0"
    "reset"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SouncEffectDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  119,    2, 0x06 /* Public */,
       4,    1,  122,    2, 0x06 /* Public */,
       5,    1,  125,    2, 0x06 /* Public */,
       6,    1,  128,    2, 0x06 /* Public */,
       7,    1,  131,    2, 0x06 /* Public */,
       8,    1,  134,    2, 0x06 /* Public */,
       9,    1,  137,    2, 0x06 /* Public */,
      11,    1,  140,    2, 0x06 /* Public */,
      13,    1,  143,    2, 0x06 /* Public */,
      14,    1,  146,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    1,  149,    2, 0x0a /* Public */,
      16,    1,  152,    2, 0x0a /* Public */,
      17,    1,  155,    2, 0x0a /* Public */,
      18,    1,  158,    2, 0x0a /* Public */,
      19,    1,  161,    2, 0x0a /* Public */,
      20,    1,  164,    2, 0x0a /* Public */,
      21,    1,  167,    2, 0x0a /* Public */,
      22,    1,  170,    2, 0x0a /* Public */,
      23,    1,  173,    2, 0x0a /* Public */,
      24,    1,  176,    2, 0x0a /* Public */,
      25,    0,  179,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool,   12,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void,

       0        // eod
};

void SouncEffectDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SouncEffectDialog *_t = static_cast<SouncEffectDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->lowFreqChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->midFreqChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->highFreqChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->lowmidFreqChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->midhighFreqChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->extremhighFreqChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->reverbChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->rotateChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->echoChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->flangerChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->setLowFreq((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->setMidFreq((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->setHighFreq((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->setLowmidFreq((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->setMidhighFreq((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->setExtremhighFreq((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->setReverb((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->setEcho((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->setRotate((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->setFlanger((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: _t->reset(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SouncEffectDialog::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SouncEffectDialog::lowFreqChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (SouncEffectDialog::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SouncEffectDialog::midFreqChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (SouncEffectDialog::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SouncEffectDialog::highFreqChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (SouncEffectDialog::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SouncEffectDialog::lowmidFreqChanged)) {
                *result = 3;
            }
        }
        {
            typedef void (SouncEffectDialog::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SouncEffectDialog::midhighFreqChanged)) {
                *result = 4;
            }
        }
        {
            typedef void (SouncEffectDialog::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SouncEffectDialog::extremhighFreqChanged)) {
                *result = 5;
            }
        }
        {
            typedef void (SouncEffectDialog::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SouncEffectDialog::reverbChanged)) {
                *result = 6;
            }
        }
        {
            typedef void (SouncEffectDialog::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SouncEffectDialog::rotateChanged)) {
                *result = 7;
            }
        }
        {
            typedef void (SouncEffectDialog::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SouncEffectDialog::echoChanged)) {
                *result = 8;
            }
        }
        {
            typedef void (SouncEffectDialog::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SouncEffectDialog::flangerChanged)) {
                *result = 9;
            }
        }
    }
}

const QMetaObject SouncEffectDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SouncEffectDialog.data,
      qt_meta_data_SouncEffectDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SouncEffectDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SouncEffectDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SouncEffectDialog.stringdata0))
        return static_cast<void*>(const_cast< SouncEffectDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int SouncEffectDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void SouncEffectDialog::lowFreqChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SouncEffectDialog::midFreqChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SouncEffectDialog::highFreqChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SouncEffectDialog::lowmidFreqChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void SouncEffectDialog::midhighFreqChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void SouncEffectDialog::extremhighFreqChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void SouncEffectDialog::reverbChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void SouncEffectDialog::rotateChanged(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void SouncEffectDialog::echoChanged(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void SouncEffectDialog::flangerChanged(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_END_MOC_NAMESPACE
