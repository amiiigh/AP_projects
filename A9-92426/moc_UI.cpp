/****************************************************************************
** Meta object code from reading C++ file 'UI.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "UI.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_UI[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       4,    3,    3,    3, 0x0a,
      21,    3,    3,    3, 0x0a,
      38,    3,    3,    3, 0x0a,
      55,    3,    3,    3, 0x0a,
      73,    3,    3,    3, 0x0a,
      87,    3,    3,    3, 0x0a,
     102,    3,    3,    3, 0x0a,
     117,    3,    3,    3, 0x0a,
     135,    3,    3,    3, 0x0a,
     153,    3,    3,    3, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_UI[] = {
    "UI\0\0signin_clicked()\0signup_clicked()\0"
    "logout_clicked()\0profile_clicked()\0"
    "fav_clicked()\0home_clicked()\0"
    "newp_clicked()\0seeprof_clicked()\0"
    "delbutt_clicked()\0edit_clicked()\0"
};

void UI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        UI *_t = static_cast<UI *>(_o);
        switch (_id) {
        case 0: _t->signin_clicked(); break;
        case 1: _t->signup_clicked(); break;
        case 2: _t->logout_clicked(); break;
        case 3: _t->profile_clicked(); break;
        case 4: _t->fav_clicked(); break;
        case 5: _t->home_clicked(); break;
        case 6: _t->newp_clicked(); break;
        case 7: _t->seeprof_clicked(); break;
        case 8: _t->delbutt_clicked(); break;
        case 9: _t->edit_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData UI::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject UI::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_UI,
      qt_meta_data_UI, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &UI::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *UI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *UI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UI))
        return static_cast<void*>(const_cast< UI*>(this));
    return QWidget::qt_metacast(_clname);
}

int UI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
