#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QObject>
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQuery>
#include<QSqlRecord>
#include<QPair>
#include<QJsonDocument>

#include"UserData.h"
#include"log.h"

#define USERDB "user_sqlite"

class DBManager : public QObject
{
    Q_OBJECT
Q_SIGNALS:

public:
    explicit DBManager(QObject *parent = nullptr);
    //禁止拷贝
    DBManager(const DBManager&)=delete;
    DBManager operator=(const DBManager&)=delete;
    ~DBManager();
    //获取数据库管理对象单列
    static DBManager*getDBManager();
    //初始化数据库
    void DBInit();
    //关闭数据库
    void DBClose();
    //记录历史登入记录
    void saveLoginhist(const QString&useraccount,const QString&userpassword,bool auto_login,bool rememberpwd,qint64 login_time);
    //获取历史登入信息
    void getLoginHistory();
    //播种会话游标
    void sowConvSeq(const std::shared_ptr<QList<qint64>>&convid);
    //播种通知游标
    void sowNoticeSeq(const qint64 userid);
    //获取会话信息
    void getConvInfo(const std::shared_ptr<QList<qint64>>&convid);
    //获取通知信息
    void getNoticeInfo(const qint64 userid);
    //保存离线消息到本地
    void saveOfflineMes(const std::shared_ptr<QList<Mes>>&mesinfo);
    //保存通知增量到本地
    void saveNoticeMes(const std::shared_ptr<QList<Notice>>&mesinfo);
    //判断会话游标是否连续
    void hasnextconvseq(const qint64 convid);
    //判断游标是否连续
    void hasnextnoticeseq(const qint64 userid);
    //判断通知游标是否连续
    bool hasnextuserseq(const qint64 userid);
    //判断同步游标是否连续
    bool hasnextsyncseq(const qint64 userid);

    //拉新用户好友通知信息
    void getNewFriendNotice(const qint64 userid);
    //拉新用户好友通知信息
    void getOlderFriendNotice(const qint64 userid);
    //聊天记录拉新
    void getChatHistory_New(const qint64 convid);
    //聊天记录拉旧
    void getChatHistory_Older(const qint64 convid);
    //重置聊天窗口上下界
    void resetChatBounds(const qint64 convid);


signals:
    //返回历史登入信息
    void returnLoginHistory(const std::shared_ptr<QList<LoginHistory>>&loginhistoryinfo);
    //返回会话信息
    void returnConvInfo(const std::shared_ptr<QList<ConvSLInfo>>&convinfo);
    //返回通知信息
    void returnNoticeInfo(const NoticeSLInfo&noticeslinfo);
    //返回用于显示的通知消息
    void return_FRIENDNOTICE_Display(const std::shared_ptr<QList<DisplayNoticeInfo>>&ldpni);
    //返回用于消失的会话消息
    void return_CONVMES_Display(const std::shared_ptr< QList<Mes>>&ldpni);

public:
    QSqlDatabase db;
    //会话信息哈希表
    QHash<qint64,ConvInfo>convinfohash; //key=convid
    //通知信息
    NoticeInfo noticeif;
};

#endif // DBMANAGER_H
