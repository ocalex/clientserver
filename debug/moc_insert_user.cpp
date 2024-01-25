/****************************************************************************
** Meta object code from reading C++ file 'insert_user.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../insert_user.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'insert_user.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_insert_user_t {
    const uint offsetsAndSize[18];
    char stringdata0[80];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_insert_user_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_insert_user_t qt_meta_stringdata_insert_user = {
    {
QT_MOC_LITERAL(0, 11), // "insert_user"
QT_MOC_LITERAL(12, 11), // "changelogin"
QT_MOC_LITERAL(24, 0), // ""
QT_MOC_LITERAL(25, 1), // "s"
QT_MOC_LITERAL(27, 14), // "changepassword"
QT_MOC_LITERAL(42, 11), // "changeadmin"
QT_MOC_LITERAL(54, 3), // "adm"
QT_MOC_LITERAL(58, 10), // "insertdata"
QT_MOC_LITERAL(69, 10) // "show_users"

    },
    "insert_user\0changelogin\0\0s\0changepassword\0"
    "changeadmin\0adm\0insertdata\0show_users"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_insert_user[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x0a,    1 /* Public */,
       4,    1,   47,    2, 0x0a,    3 /* Public */,
       5,    1,   50,    2, 0x0a,    5 /* Public */,
       7,    0,   53,    2, 0x0a,    7 /* Public */,
       8,    0,   54,    2, 0x0a,    8 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void insert_user::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<insert_user *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->changelogin((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->changepassword((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->changeadmin((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->insertdata(); break;
        case 4: _t->show_users(); break;
        default: ;
        }
    }
}

const QMetaObject insert_user::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_insert_user.offsetsAndSize,
    qt_meta_data_insert_user,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_insert_user_t
, QtPrivate::TypeAndForceComplete<insert_user, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *insert_user::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *insert_user::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_insert_user.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int insert_user::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
