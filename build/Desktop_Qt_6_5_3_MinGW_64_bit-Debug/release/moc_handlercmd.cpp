/****************************************************************************
** Meta object code from reading C++ file 'handlercmd.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../handlercmd.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'handlercmd.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSHandlerCmdENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSHandlerCmdENDCLASS = QtMocHelpers::stringData(
    "HandlerCmd",
    "sendJson",
    "",
    "data",
    "getLoginHistory",
    "returnLoginHistory",
    "std::shared_ptr<QList<LoginHistory>>",
    "loginhistoryinfo",
    "getConvInfo",
    "std::shared_ptr<QList<qint64>>",
    "convid",
    "getNoticeInfo",
    "userid",
    "useraccount_exists",
    "register_sucess",
    "useraccount",
    "register_failed",
    "login_success",
    "username",
    "sendNoticeSeed",
    "login_online",
    "user_worningpassword",
    "user_accountnoexists",
    "getuserdata_success",
    "firendlist",
    "grouplist",
    "sendConvSeed",
    "sendLoginInfo",
    "userpassword",
    "autologin",
    "rempwd",
    "login_time",
    "getuserdata_failed",
    "sendOfflineMes",
    "std::shared_ptr<QList<Mes>>",
    "allmes",
    "sendNoticeMes",
    "std::shared_ptr<QList<Notice>>",
    "allnotice",
    "searchFailed",
    "snedSearchInfo",
    "QList<SearchInfo>",
    "friendlist",
    "haveFriendNotice",
    "std::shared_ptr<QList<DisplayNoticeInfo>>",
    "ldpni",
    "haveGroupNotice",
    "QList<DisplayNoticeInfo>",
    "getFriendNotice",
    "addFriendReuqestSuccess",
    "addFriendReuqestFailed",
    "addOneself",
    "NewFriendInfo",
    "friendid",
    "friendaccount",
    "friendname",
    "friendremark",
    "friendidentity",
    "FriendNoticeStatusChanged",
    "bindid",
    "NoticeMode",
    "status",
    "addfriend_handlefailed"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSHandlerCmdENDCLASS_t {
    uint offsetsAndSizes[126];
    char stringdata0[11];
    char stringdata1[9];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[16];
    char stringdata5[19];
    char stringdata6[37];
    char stringdata7[17];
    char stringdata8[12];
    char stringdata9[31];
    char stringdata10[7];
    char stringdata11[14];
    char stringdata12[7];
    char stringdata13[19];
    char stringdata14[16];
    char stringdata15[12];
    char stringdata16[16];
    char stringdata17[14];
    char stringdata18[9];
    char stringdata19[15];
    char stringdata20[13];
    char stringdata21[21];
    char stringdata22[21];
    char stringdata23[20];
    char stringdata24[11];
    char stringdata25[10];
    char stringdata26[13];
    char stringdata27[14];
    char stringdata28[13];
    char stringdata29[10];
    char stringdata30[7];
    char stringdata31[11];
    char stringdata32[19];
    char stringdata33[15];
    char stringdata34[28];
    char stringdata35[7];
    char stringdata36[14];
    char stringdata37[31];
    char stringdata38[10];
    char stringdata39[13];
    char stringdata40[15];
    char stringdata41[18];
    char stringdata42[11];
    char stringdata43[17];
    char stringdata44[42];
    char stringdata45[6];
    char stringdata46[16];
    char stringdata47[25];
    char stringdata48[16];
    char stringdata49[24];
    char stringdata50[23];
    char stringdata51[11];
    char stringdata52[14];
    char stringdata53[9];
    char stringdata54[14];
    char stringdata55[11];
    char stringdata56[13];
    char stringdata57[15];
    char stringdata58[26];
    char stringdata59[7];
    char stringdata60[11];
    char stringdata61[7];
    char stringdata62[23];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSHandlerCmdENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSHandlerCmdENDCLASS_t qt_meta_stringdata_CLASSHandlerCmdENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "HandlerCmd"
        QT_MOC_LITERAL(11, 8),  // "sendJson"
        QT_MOC_LITERAL(20, 0),  // ""
        QT_MOC_LITERAL(21, 4),  // "data"
        QT_MOC_LITERAL(26, 15),  // "getLoginHistory"
        QT_MOC_LITERAL(42, 18),  // "returnLoginHistory"
        QT_MOC_LITERAL(61, 36),  // "std::shared_ptr<QList<LoginHi..."
        QT_MOC_LITERAL(98, 16),  // "loginhistoryinfo"
        QT_MOC_LITERAL(115, 11),  // "getConvInfo"
        QT_MOC_LITERAL(127, 30),  // "std::shared_ptr<QList<qint64>>"
        QT_MOC_LITERAL(158, 6),  // "convid"
        QT_MOC_LITERAL(165, 13),  // "getNoticeInfo"
        QT_MOC_LITERAL(179, 6),  // "userid"
        QT_MOC_LITERAL(186, 18),  // "useraccount_exists"
        QT_MOC_LITERAL(205, 15),  // "register_sucess"
        QT_MOC_LITERAL(221, 11),  // "useraccount"
        QT_MOC_LITERAL(233, 15),  // "register_failed"
        QT_MOC_LITERAL(249, 13),  // "login_success"
        QT_MOC_LITERAL(263, 8),  // "username"
        QT_MOC_LITERAL(272, 14),  // "sendNoticeSeed"
        QT_MOC_LITERAL(287, 12),  // "login_online"
        QT_MOC_LITERAL(300, 20),  // "user_worningpassword"
        QT_MOC_LITERAL(321, 20),  // "user_accountnoexists"
        QT_MOC_LITERAL(342, 19),  // "getuserdata_success"
        QT_MOC_LITERAL(362, 10),  // "firendlist"
        QT_MOC_LITERAL(373, 9),  // "grouplist"
        QT_MOC_LITERAL(383, 12),  // "sendConvSeed"
        QT_MOC_LITERAL(396, 13),  // "sendLoginInfo"
        QT_MOC_LITERAL(410, 12),  // "userpassword"
        QT_MOC_LITERAL(423, 9),  // "autologin"
        QT_MOC_LITERAL(433, 6),  // "rempwd"
        QT_MOC_LITERAL(440, 10),  // "login_time"
        QT_MOC_LITERAL(451, 18),  // "getuserdata_failed"
        QT_MOC_LITERAL(470, 14),  // "sendOfflineMes"
        QT_MOC_LITERAL(485, 27),  // "std::shared_ptr<QList<Mes>>"
        QT_MOC_LITERAL(513, 6),  // "allmes"
        QT_MOC_LITERAL(520, 13),  // "sendNoticeMes"
        QT_MOC_LITERAL(534, 30),  // "std::shared_ptr<QList<Notice>>"
        QT_MOC_LITERAL(565, 9),  // "allnotice"
        QT_MOC_LITERAL(575, 12),  // "searchFailed"
        QT_MOC_LITERAL(588, 14),  // "snedSearchInfo"
        QT_MOC_LITERAL(603, 17),  // "QList<SearchInfo>"
        QT_MOC_LITERAL(621, 10),  // "friendlist"
        QT_MOC_LITERAL(632, 16),  // "haveFriendNotice"
        QT_MOC_LITERAL(649, 41),  // "std::shared_ptr<QList<Display..."
        QT_MOC_LITERAL(691, 5),  // "ldpni"
        QT_MOC_LITERAL(697, 15),  // "haveGroupNotice"
        QT_MOC_LITERAL(713, 24),  // "QList<DisplayNoticeInfo>"
        QT_MOC_LITERAL(738, 15),  // "getFriendNotice"
        QT_MOC_LITERAL(754, 23),  // "addFriendReuqestSuccess"
        QT_MOC_LITERAL(778, 22),  // "addFriendReuqestFailed"
        QT_MOC_LITERAL(801, 10),  // "addOneself"
        QT_MOC_LITERAL(812, 13),  // "NewFriendInfo"
        QT_MOC_LITERAL(826, 8),  // "friendid"
        QT_MOC_LITERAL(835, 13),  // "friendaccount"
        QT_MOC_LITERAL(849, 10),  // "friendname"
        QT_MOC_LITERAL(860, 12),  // "friendremark"
        QT_MOC_LITERAL(873, 14),  // "friendidentity"
        QT_MOC_LITERAL(888, 25),  // "FriendNoticeStatusChanged"
        QT_MOC_LITERAL(914, 6),  // "bindid"
        QT_MOC_LITERAL(921, 10),  // "NoticeMode"
        QT_MOC_LITERAL(932, 6),  // "status"
        QT_MOC_LITERAL(939, 22)   // "addfriend_handlefailed"
    },
    "HandlerCmd",
    "sendJson",
    "",
    "data",
    "getLoginHistory",
    "returnLoginHistory",
    "std::shared_ptr<QList<LoginHistory>>",
    "loginhistoryinfo",
    "getConvInfo",
    "std::shared_ptr<QList<qint64>>",
    "convid",
    "getNoticeInfo",
    "userid",
    "useraccount_exists",
    "register_sucess",
    "useraccount",
    "register_failed",
    "login_success",
    "username",
    "sendNoticeSeed",
    "login_online",
    "user_worningpassword",
    "user_accountnoexists",
    "getuserdata_success",
    "firendlist",
    "grouplist",
    "sendConvSeed",
    "sendLoginInfo",
    "userpassword",
    "autologin",
    "rempwd",
    "login_time",
    "getuserdata_failed",
    "sendOfflineMes",
    "std::shared_ptr<QList<Mes>>",
    "allmes",
    "sendNoticeMes",
    "std::shared_ptr<QList<Notice>>",
    "allnotice",
    "searchFailed",
    "snedSearchInfo",
    "QList<SearchInfo>",
    "friendlist",
    "haveFriendNotice",
    "std::shared_ptr<QList<DisplayNoticeInfo>>",
    "ldpni",
    "haveGroupNotice",
    "QList<DisplayNoticeInfo>",
    "getFriendNotice",
    "addFriendReuqestSuccess",
    "addFriendReuqestFailed",
    "addOneself",
    "NewFriendInfo",
    "friendid",
    "friendaccount",
    "friendname",
    "friendremark",
    "friendidentity",
    "FriendNoticeStatusChanged",
    "bindid",
    "NoticeMode",
    "status",
    "addfriend_handlefailed"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSHandlerCmdENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      30,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      30,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  194,    2, 0x06,    1 /* Public */,
       4,    0,  197,    2, 0x06,    3 /* Public */,
       5,    1,  198,    2, 0x06,    4 /* Public */,
       8,    1,  201,    2, 0x06,    6 /* Public */,
      11,    1,  204,    2, 0x06,    8 /* Public */,
      13,    0,  207,    2, 0x06,   10 /* Public */,
      14,    1,  208,    2, 0x06,   11 /* Public */,
      16,    0,  211,    2, 0x06,   13 /* Public */,
      17,    2,  212,    2, 0x06,   14 /* Public */,
      19,    1,  217,    2, 0x06,   17 /* Public */,
      20,    0,  220,    2, 0x06,   19 /* Public */,
      21,    0,  221,    2, 0x06,   20 /* Public */,
      22,    0,  222,    2, 0x06,   21 /* Public */,
      23,    2,  223,    2, 0x06,   22 /* Public */,
      26,    1,  228,    2, 0x06,   25 /* Public */,
      27,    5,  231,    2, 0x06,   27 /* Public */,
      32,    0,  242,    2, 0x06,   33 /* Public */,
      33,    1,  243,    2, 0x06,   34 /* Public */,
      36,    1,  246,    2, 0x06,   36 /* Public */,
      39,    0,  249,    2, 0x06,   38 /* Public */,
      40,    2,  250,    2, 0x06,   39 /* Public */,
      43,    1,  255,    2, 0x06,   42 /* Public */,
      46,    1,  258,    2, 0x06,   44 /* Public */,
      48,    1,  261,    2, 0x06,   46 /* Public */,
      49,    0,  264,    2, 0x06,   48 /* Public */,
      50,    0,  265,    2, 0x06,   49 /* Public */,
      51,    0,  266,    2, 0x06,   50 /* Public */,
      52,    6,  267,    2, 0x06,   51 /* Public */,
      58,    2,  280,    2, 0x06,   58 /* Public */,
      62,    0,  285,    2, 0x06,   61 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QJsonObject,    3,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::LongLong,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::QString,   12,   18,
    QMetaType::Void, QMetaType::LongLong,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonArray, QMetaType::QJsonArray,   24,   25,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::Bool, QMetaType::LongLong,   15,   28,   29,   30,   31,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 34,   35,
    QMetaType::Void, 0x80000000 | 37,   38,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 41, 0x80000000 | 41,   42,   25,
    QMetaType::Void, 0x80000000 | 44,   45,
    QMetaType::Void, 0x80000000 | 47,   45,
    QMetaType::Void, QMetaType::LongLong,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   53,   10,   54,   55,   56,   57,
    QMetaType::Void, QMetaType::LongLong, 0x80000000 | 60,   59,   61,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject HandlerCmd::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSHandlerCmdENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSHandlerCmdENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSHandlerCmdENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<HandlerCmd, std::true_type>,
        // method 'sendJson'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonObject &, std::false_type>,
        // method 'getLoginHistory'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'returnLoginHistory'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::shared_ptr<QList<LoginHistory>> &, std::false_type>,
        // method 'getConvInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::shared_ptr<QList<qint64>> &, std::false_type>,
        // method 'getNoticeInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const qint64, std::false_type>,
        // method 'useraccount_exists'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'register_sucess'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'register_failed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'login_success'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const qint64, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'sendNoticeSeed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const qint64, std::false_type>,
        // method 'login_online'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'user_worningpassword'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'user_accountnoexists'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getuserdata_success'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonArray &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonArray &, std::false_type>,
        // method 'sendConvSeed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::shared_ptr<QList<qint64>> &, std::false_type>,
        // method 'sendLoginInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'getuserdata_failed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sendOfflineMes'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::shared_ptr<QList<Mes>> &, std::false_type>,
        // method 'sendNoticeMes'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::shared_ptr<QList<Notice>> &, std::false_type>,
        // method 'searchFailed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'snedSearchInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QList<SearchInfo> &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QList<SearchInfo> &, std::false_type>,
        // method 'haveFriendNotice'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::shared_ptr<QList<DisplayNoticeInfo>> &, std::false_type>,
        // method 'haveGroupNotice'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QList<DisplayNoticeInfo>, std::false_type>,
        // method 'getFriendNotice'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const qint64, std::false_type>,
        // method 'addFriendReuqestSuccess'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addFriendReuqestFailed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addOneself'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'NewFriendInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const qint64, std::false_type>,
        QtPrivate::TypeAndForceComplete<const qint64, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'FriendNoticeStatusChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const qint64, std::false_type>,
        QtPrivate::TypeAndForceComplete<const NoticeMode, std::false_type>,
        // method 'addfriend_handlefailed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void HandlerCmd::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HandlerCmd *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendJson((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 1: _t->getLoginHistory(); break;
        case 2: _t->returnLoginHistory((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<QList<LoginHistory>>>>(_a[1]))); break;
        case 3: _t->getConvInfo((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<QList<qint64>>>>(_a[1]))); break;
        case 4: _t->getNoticeInfo((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 5: _t->useraccount_exists(); break;
        case 6: _t->register_sucess((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->register_failed(); break;
        case 8: _t->login_success((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 9: _t->sendNoticeSeed((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 10: _t->login_online(); break;
        case 11: _t->user_worningpassword(); break;
        case 12: _t->user_accountnoexists(); break;
        case 13: _t->getuserdata_success((*reinterpret_cast< std::add_pointer_t<QJsonArray>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QJsonArray>>(_a[2]))); break;
        case 14: _t->sendConvSeed((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<QList<qint64>>>>(_a[1]))); break;
        case 15: _t->sendLoginInfo((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<qint64>>(_a[5]))); break;
        case 16: _t->getuserdata_failed(); break;
        case 17: _t->sendOfflineMes((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<QList<Mes>>>>(_a[1]))); break;
        case 18: _t->sendNoticeMes((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<QList<Notice>>>>(_a[1]))); break;
        case 19: _t->searchFailed(); break;
        case 20: _t->snedSearchInfo((*reinterpret_cast< std::add_pointer_t<QList<SearchInfo>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<SearchInfo>>>(_a[2]))); break;
        case 21: _t->haveFriendNotice((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<QList<DisplayNoticeInfo>>>>(_a[1]))); break;
        case 22: _t->haveGroupNotice((*reinterpret_cast< std::add_pointer_t<QList<DisplayNoticeInfo>>>(_a[1]))); break;
        case 23: _t->getFriendNotice((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 24: _t->addFriendReuqestSuccess(); break;
        case 25: _t->addFriendReuqestFailed(); break;
        case 26: _t->addOneself(); break;
        case 27: _t->NewFriendInfo((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qint64>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[6]))); break;
        case 28: _t->FriendNoticeStatusChanged((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<NoticeMode>>(_a[2]))); break;
        case 29: _t->addfriend_handlefailed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< std::shared_ptr<QList<LoginHistory>> >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< std::shared_ptr<QList<qint64>> >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< std::shared_ptr<QList<qint64>> >(); break;
            }
            break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< std::shared_ptr<QList<Mes>> >(); break;
            }
            break;
        case 18:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< std::shared_ptr<QList<Notice>> >(); break;
            }
            break;
        case 22:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<DisplayNoticeInfo> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (HandlerCmd::*)(const QJsonObject & );
            if (_t _q_method = &HandlerCmd::sendJson; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (HandlerCmd::*)();
            if (_t _q_method = &HandlerCmd::getLoginHistory; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (HandlerCmd::*)(const std::shared_ptr<QList<LoginHistory>> & );
            if (_t _q_method = &HandlerCmd::returnLoginHistory; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (HandlerCmd::*)(const std::shared_ptr<QList<qint64>> & );
            if (_t _q_method = &HandlerCmd::getConvInfo; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (HandlerCmd::*)(const qint64 );
            if (_t _q_method = &HandlerCmd::getNoticeInfo; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (HandlerCmd::*)();
            if (_t _q_method = &HandlerCmd::useraccount_exists; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (HandlerCmd::*)(const QString & );
            if (_t _q_method = &HandlerCmd::register_sucess; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (HandlerCmd::*)();
            if (_t _q_method = &HandlerCmd::register_failed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (HandlerCmd::*)(const qint64 , const QString & );
            if (_t _q_method = &HandlerCmd::login_success; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (HandlerCmd::*)(const qint64 );
            if (_t _q_method = &HandlerCmd::sendNoticeSeed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (HandlerCmd::*)();
            if (_t _q_method = &HandlerCmd::login_online; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (HandlerCmd::*)();
            if (_t _q_method = &HandlerCmd::user_worningpassword; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (HandlerCmd::*)();
            if (_t _q_method = &HandlerCmd::user_accountnoexists; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (HandlerCmd::*)(const QJsonArray & , const QJsonArray & );
            if (_t _q_method = &HandlerCmd::getuserdata_success; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (HandlerCmd::*)(const std::shared_ptr<QList<qint64>> & );
            if (_t _q_method = &HandlerCmd::sendConvSeed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (HandlerCmd::*)(const QString & , const QString & , bool , bool , qint64 );
            if (_t _q_method = &HandlerCmd::sendLoginInfo; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (HandlerCmd::*)();
            if (_t _q_method = &HandlerCmd::getuserdata_failed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (HandlerCmd::*)(const std::shared_ptr<QList<Mes>> & );
            if (_t _q_method = &HandlerCmd::sendOfflineMes; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (HandlerCmd::*)(const std::shared_ptr<QList<Notice>> & );
            if (_t _q_method = &HandlerCmd::sendNoticeMes; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (HandlerCmd::*)();
            if (_t _q_method = &HandlerCmd::searchFailed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (HandlerCmd::*)(const QList<SearchInfo> & , const QList<SearchInfo> & );
            if (_t _q_method = &HandlerCmd::snedSearchInfo; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (HandlerCmd::*)(const std::shared_ptr<QList<DisplayNoticeInfo>> & );
            if (_t _q_method = &HandlerCmd::haveFriendNotice; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (HandlerCmd::*)(QList<DisplayNoticeInfo> );
            if (_t _q_method = &HandlerCmd::haveGroupNotice; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (HandlerCmd::*)(const qint64 );
            if (_t _q_method = &HandlerCmd::getFriendNotice; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 23;
                return;
            }
        }
        {
            using _t = void (HandlerCmd::*)();
            if (_t _q_method = &HandlerCmd::addFriendReuqestSuccess; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 24;
                return;
            }
        }
        {
            using _t = void (HandlerCmd::*)();
            if (_t _q_method = &HandlerCmd::addFriendReuqestFailed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 25;
                return;
            }
        }
        {
            using _t = void (HandlerCmd::*)();
            if (_t _q_method = &HandlerCmd::addOneself; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 26;
                return;
            }
        }
        {
            using _t = void (HandlerCmd::*)(const qint64 , const qint64 , const QString & , const QString & , const QString & , const QString & );
            if (_t _q_method = &HandlerCmd::NewFriendInfo; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 27;
                return;
            }
        }
        {
            using _t = void (HandlerCmd::*)(const qint64 , const NoticeMode );
            if (_t _q_method = &HandlerCmd::FriendNoticeStatusChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 28;
                return;
            }
        }
        {
            using _t = void (HandlerCmd::*)();
            if (_t _q_method = &HandlerCmd::addfriend_handlefailed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 29;
                return;
            }
        }
    }
}

const QMetaObject *HandlerCmd::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HandlerCmd::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSHandlerCmdENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int HandlerCmd::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    }
    return _id;
}

// SIGNAL 0
void HandlerCmd::sendJson(const QJsonObject & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void HandlerCmd::getLoginHistory()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void HandlerCmd::returnLoginHistory(const std::shared_ptr<QList<LoginHistory>> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void HandlerCmd::getConvInfo(const std::shared_ptr<QList<qint64>> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void HandlerCmd::getNoticeInfo(const qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void HandlerCmd::useraccount_exists()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void HandlerCmd::register_sucess(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void HandlerCmd::register_failed()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void HandlerCmd::login_success(const qint64 _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void HandlerCmd::sendNoticeSeed(const qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void HandlerCmd::login_online()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void HandlerCmd::user_worningpassword()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void HandlerCmd::user_accountnoexists()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void HandlerCmd::getuserdata_success(const QJsonArray & _t1, const QJsonArray & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void HandlerCmd::sendConvSeed(const std::shared_ptr<QList<qint64>> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void HandlerCmd::sendLoginInfo(const QString & _t1, const QString & _t2, bool _t3, bool _t4, qint64 _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void HandlerCmd::getuserdata_failed()
{
    QMetaObject::activate(this, &staticMetaObject, 16, nullptr);
}

// SIGNAL 17
void HandlerCmd::sendOfflineMes(const std::shared_ptr<QList<Mes>> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void HandlerCmd::sendNoticeMes(const std::shared_ptr<QList<Notice>> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void HandlerCmd::searchFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 19, nullptr);
}

// SIGNAL 20
void HandlerCmd::snedSearchInfo(const QList<SearchInfo> & _t1, const QList<SearchInfo> & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void HandlerCmd::haveFriendNotice(const std::shared_ptr<QList<DisplayNoticeInfo>> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void HandlerCmd::haveGroupNotice(QList<DisplayNoticeInfo> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void HandlerCmd::getFriendNotice(const qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}

// SIGNAL 24
void HandlerCmd::addFriendReuqestSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 24, nullptr);
}

// SIGNAL 25
void HandlerCmd::addFriendReuqestFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 25, nullptr);
}

// SIGNAL 26
void HandlerCmd::addOneself()
{
    QMetaObject::activate(this, &staticMetaObject, 26, nullptr);
}

// SIGNAL 27
void HandlerCmd::NewFriendInfo(const qint64 _t1, const qint64 _t2, const QString & _t3, const QString & _t4, const QString & _t5, const QString & _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))) };
    QMetaObject::activate(this, &staticMetaObject, 27, _a);
}

// SIGNAL 28
void HandlerCmd::FriendNoticeStatusChanged(const qint64 _t1, const NoticeMode _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 28, _a);
}

// SIGNAL 29
void HandlerCmd::addfriend_handlefailed()
{
    QMetaObject::activate(this, &staticMetaObject, 29, nullptr);
}
QT_WARNING_POP
