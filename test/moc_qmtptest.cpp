/****************************************************************************
** Meta object code from reading C++ file 'qmtptest.h'
**
** Created: Thu Feb 18 20:10:42 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qmtptest.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmtptest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QMtpTest[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x0a,
      25,    9,    9,    9, 0x0a,
      39,    9,    9,    9, 0x0a,
      58,    9,    9,    9, 0x0a,
      73,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QMtpTest[] = {
    "QMtpTest\0\0initTestCase()\0devicesTest()\0"
    "verboseFilesTest()\0storagesTest()\0"
    "filesTest()\0"
};

const QMetaObject QMtpTest::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QMtpTest,
      qt_meta_data_QMtpTest, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QMtpTest::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QMtpTest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QMtpTest::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QMtpTest))
        return static_cast<void*>(const_cast< QMtpTest*>(this));
    return QObject::qt_metacast(_clname);
}

int QMtpTest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: initTestCase(); break;
        case 1: devicesTest(); break;
        case 2: verboseFilesTest(); break;
        case 3: storagesTest(); break;
        case 4: filesTest(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
