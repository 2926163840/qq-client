/****************************************************************************
** Meta object code from reading C++ file 'dbmanager.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../dbmanager.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dbmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSDBManagerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSDBManagerENDCLASS = QtMocHelpers::stringData(
    "DBManager",
    "returnLoginHistory",
    "",
    "std::shared_ptr<QList<LoginHistory>>",
    "loginhistoryinfo",
    "returnConvInfo",
    "std::shared_ptr<QList<ConvSLInfo>>",
    "convinfo",
    "returnNoticeInfo",
    "NoticeSLInfo",
    "noticeslinfo",
    "return_FRIENDNOTICE_Display",
    "std::shared_ptr<QList<DisplayNoticeInfo>>",
    "ldpni"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSDBManagerENDCLASS_t {
    uint offsetsAndSizes[28];
    char stringdata0[10];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[37];
    char stringdata4[17];
    char stringdata5[15];
    char stringdata6[35];
    char stringdata7[9];
    char stringdata8[17];
    char stringdata9[13];
    char stringdata10[13];
    char stringdata11[28];
    char stringdata12[42];
    char stringdata13[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSDBManagerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSDBManagerENDCLASS_t qt_meta_stringdata_CLASSDBManagerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 9),  // "DBManager"
        QT_MOC_LITERAL(10, 18),  // "returnLoginHistory"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 36),  // "std::shared_ptr<QList<LoginHi..."
        QT_MOC_LITERAL(67, 16),  // "loginhistoryinfo"
        QT_MOC_LITERAL(84, 14),  // "returnConvInfo"
        QT_MOC_LITERAL(99, 34),  // "std::shared_ptr<QList<ConvSLI..."
        QT_MOC_LITERAL(134, 8),  // "convinfo"
        QT_MOC_LITERAL(143, 16),  // "returnNoticeInfo"
        QT_MOC_LITERAL(160, 12),  // "NoticeSLInfo"
        QT_MOC_LITERAL(173, 12),  // "noticeslinfo"
        QT_MOC_LITERAL(186, 27),  // "return_FRIENDNOTICE_Display"
        QT_MOC_LITERAL(214, 41),  // "std::shared_ptr<QList<Display..."
        QT_MOC_LITERAL(256, 5)   // "ldpni"
    },
    "DBManager",
    "returnLoginHistory",
    "",
    "std::shared_ptr<QList<LoginHistory>>",
    "loginhistoryinfo",
    "returnConvInfo",
    "std::shared_ptr<QList<ConvSLInfo>>",
    "convinfo",
    "returnNoticeInfo",
    "NoticeSLInfo",
    "noticeslinfo",
    "return_FRIENDNOTICE_Display",
    "std::shared_ptr<QList<DisplayNoticeInfo>>",
    "ldpni"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSDBManagerENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x06,    1 /* Public */,
       5,    1,   41,    2, 0x06,    3 /* Public */,
       8,    1,   44,    2, 0x06,    5 /* Public */,
      11,    1,   47,    2, 0x06,    7 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,

       0        // eod
};

Q_CONSTINIT const QMetaObject DBManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSDBManagerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSDBManagerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSDBManagerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<DBManager, std::true_type>,
        // method 'returnLoginHistory'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::shared_ptr<QList<LoginHistory>> &, std::false_type>,
        // method 'returnConvInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::shared_ptr<QList<ConvSLInfo>> &, std::false_type>,
        // method 'returnNoticeInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const NoticeSLInfo &, std::false_type>,
        // method 'return_FRIENDNOTICE_Display'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::shared_ptr<QList<DisplayNoticeInfo>> &, std::false_type>
    >,
    nullptr
} };

void DBManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DBManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->returnLoginHistory((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<QList<LoginHistory>>>>(_a[1]))); break;
        case 1: _t->returnConvInfo((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<QList<ConvSLInfo>>>>(_a[1]))); break;
        case 2: _t->returnNoticeInfo((*reinterpret_cast< std::add_pointer_t<NoticeSLInfo>>(_a[1]))); break;
        case 3: _t->return_FRIENDNOTICE_Display((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<QList<DisplayNoticeInfo>>>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< std::shared_ptr<QList<LoginHistory>> >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< std::shared_ptr<QList<ConvSLInfo>> >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< NoticeSLInfo >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DBManager::*)(const std::shared_ptr<QList<LoginHistory>> & );
            if (_t _q_method = &DBManager::returnLoginHistory; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DBManager::*)(const std::shared_ptr<QList<ConvSLInfo>> & );
            if (_t _q_method = &DBManager::returnConvInfo; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DBManager::*)(const NoticeSLInfo & );
            if (_t _q_method = &DBManager::returnNoticeInfo; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DBManager::*)(const std::shared_ptr<QList<DisplayNoticeInfo>> & );
            if (_t _q_method = &DBManager::return_FRIENDNOTICE_Display; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject *DBManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DBManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSDBManagerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DBManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void DBManager::returnLoginHistory(const std::shared_ptr<QList<LoginHistory>> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DBManager::returnConvInfo(const std::shared_ptr<QList<ConvSLInfo>> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DBManager::returnNoticeInfo(const NoticeSLInfo & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DBManager::return_FRIENDNOTICE_Display(const std::shared_ptr<QList<DisplayNoticeInfo>> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
