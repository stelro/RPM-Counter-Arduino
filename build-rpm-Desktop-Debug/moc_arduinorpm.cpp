/****************************************************************************
** Meta object code from reading C++ file 'arduinorpm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../rpm/arduinorpm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'arduinorpm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ArduinoRpm_t {
    QByteArrayData data[8];
    char stringdata[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ArduinoRpm_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ArduinoRpm_t qt_meta_stringdata_ArduinoRpm = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ArduinoRpm"
QT_MOC_LITERAL(1, 11, 12), // "valueChanged"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 8), // "newValue"
QT_MOC_LITERAL(4, 34, 13), // "serialReciver"
QT_MOC_LITERAL(5, 48, 11), // "getBaudRate"
QT_MOC_LITERAL(6, 60, 23), // "on_actionExit_triggered"
QT_MOC_LITERAL(7, 84, 27) // "on_actionSettings_triggered"

    },
    "ArduinoRpm\0valueChanged\0\0newValue\0"
    "serialReciver\0getBaudRate\0"
    "on_actionExit_triggered\0"
    "on_actionSettings_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ArduinoRpm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   42,    2, 0x0a /* Public */,
       5,    1,   43,    2, 0x0a /* Public */,
       6,    0,   46,    2, 0x08 /* Private */,
       7,    0,   47,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ArduinoRpm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ArduinoRpm *_t = static_cast<ArduinoRpm *>(_o);
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->serialReciver(); break;
        case 2: _t->getBaudRate((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_actionExit_triggered(); break;
        case 4: _t->on_actionSettings_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ArduinoRpm::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ArduinoRpm::valueChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ArduinoRpm::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ArduinoRpm.data,
      qt_meta_data_ArduinoRpm,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ArduinoRpm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ArduinoRpm::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ArduinoRpm.stringdata))
        return static_cast<void*>(const_cast< ArduinoRpm*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ArduinoRpm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
void ArduinoRpm::valueChanged(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
