/****************************************************************************
** Meta object code from reading C++ file 'Editwidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Editwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Editwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_editwidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      22,   11,   11,   11, 0x0a,
      37,   11,   11,   11, 0x0a,
      55,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_editwidget[] = {
    "editwidget\0\0go_home()\0save_clicked()\0"
    "discard_clicked()\0browse_clicked()\0"
};

void editwidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        editwidget *_t = static_cast<editwidget *>(_o);
        switch (_id) {
        case 0: _t->go_home(); break;
        case 1: _t->save_clicked(); break;
        case 2: _t->discard_clicked(); break;
        case 3: _t->browse_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData editwidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject editwidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_editwidget,
      qt_meta_data_editwidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &editwidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *editwidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *editwidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_editwidget))
        return static_cast<void*>(const_cast< editwidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int editwidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void editwidget::go_home()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
