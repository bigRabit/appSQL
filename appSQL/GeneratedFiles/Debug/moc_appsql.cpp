/****************************************************************************
** Meta object code from reading C++ file 'appsql.h'
**
** Created: Sat Jul 4 10:11:46 2015
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../appsql.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'appsql.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_appSQL[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x08,
      31,    7,    7,    7, 0x08,
      60,    7,    7,    7, 0x08,
      89,    7,    7,    7, 0x08,
     108,    7,    7,    7, 0x08,
     130,    7,    7,    7, 0x08,
     152,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_appSQL[] = {
    "appSQL\0\0displayButtonClicked()\0"
    "submitChangedButtonClicked()\0"
    "revertChangedButtonClicked()\0"
    "addButtonClicked()\0deleteButtonClicked()\0"
    "searchButtonClicked()\0closeButtonClicked()\0"
};

const QMetaObject appSQL::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_appSQL,
      qt_meta_data_appSQL, 0 }
};

const QMetaObject *appSQL::metaObject() const
{
    return &staticMetaObject;
}

void *appSQL::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_appSQL))
	return static_cast<void*>(const_cast< appSQL*>(this));
    return QWidget::qt_metacast(_clname);
}

int appSQL::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: displayButtonClicked(); break;
        case 1: submitChangedButtonClicked(); break;
        case 2: revertChangedButtonClicked(); break;
        case 3: addButtonClicked(); break;
        case 4: deleteButtonClicked(); break;
        case 5: searchButtonClicked(); break;
        case 6: closeButtonClicked(); break;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
