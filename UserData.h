#pragma once
#ifndef USERDATA_H
#define USERDATA_H

#endif // USERDATA_H

#include<QSTring>
#include<QVector>
#include<QJsonObject>
#include<QJsonDocument>

//通知视图类型
enum class NoticeViewType{NONE,FRIEND,GROUP};

//通知状态              //等待验证            请验证              已同意 已拒绝
enum class NoticeMode{NONE,PENDINGVERIFICATION,PLEASEVERIFICATION,AGREED,REFUSED};

//活跃视图结构体
struct ActiveView
{
    QSet<qint64> indepconv;//独立窗口集合
    qint64 focusconv=-1;//焦点窗口
    NoticeViewType NVT=NoticeViewType::NONE;//通知界面类型
};

//登入历史数据
struct LoginHistory{
    //用户历史账号密码是否自动登入记住密码
    QString historyaccount;
    QString historypassword;
    bool historyauto_login;
    bool historyrem_pwd;
};

//用户信息
struct UserInfo{
    QString useraccount;
    QString username;
    QString userremark;
    QString useridentity;
    qint64 convid;
};
//会话信息
struct ConvInfo{
    qint64 convseq;//连续游标
    qint64 convlwbdseq=-1;//下界序列
    qint64 curupbdseq=-1;//上界序列
};
//精简会话信息
struct ConvSLInfo{
    qint64 convid;//会话id
    qint64 convseq;//连续游标
};


//精简通知信息
struct NoticeSLInfo{
    qint64 noticeseq;//连续通知游标
    qint64 syncseq;//连续同步游标
};

//通知信息
struct NoticeInfo{
    NoticeSLInfo noticeseq;
    qint64 noticelwbdseq=-1;//下界序列
    qint64 noticeupbdseq=-1;//上界序列
};
//用于展示的显示信息
struct DisplayNoticeInfo{
    QJsonObject payload;
    qint64 userid;
    qint64 bindid;
    qint64 sendtime;
    qint8 status;
    DisplayNoticeInfo(QString pl,qint64 uid,qint64 bid,qint8 sendtm,qint8 st)
    {
        QByteArray pl_by=pl.toUtf8();
        payload=QJsonDocument::fromJson(pl_by).object();
        userid=uid;
        bindid=bid;
        sendtime=sendtm;
        status=st;
    }
};

//消息结构体
struct Mes
{
    QString content;
    qint64 sendtime;
    qint64 convid;
    qint64 convseq;
    qint64 sendid;
};
//通知结构体
struct Notice
{
    QString payload;
    qint64 userid;
    qint64 userseq;
    qint64 syncseq;
    qint64 bindid;
    qint8 type;
    qint8 status;
    qint64 sendtime;
};

//搜索信息数据结构体
struct SearchInfo{
    QString account;
    QString name;
    qint64 id;
};

//注册元类型
Q_DECLARE_METATYPE(std::shared_ptr<QList<Mes>>);
Q_DECLARE_METATYPE(std::shared_ptr<QList<Notice>>);
Q_DECLARE_METATYPE(std::shared_ptr<QList<LoginHistory>>);
Q_DECLARE_METATYPE(std::shared_ptr<QList<ConvSLInfo>>);
Q_DECLARE_METATYPE(NoticeSLInfo);
Q_DECLARE_METATYPE(QList<DisplayNoticeInfo>);
Q_DECLARE_METATYPE(std::shared_ptr<QList<SearchInfo>>);
Q_DECLARE_METATYPE(std::shared_ptr<QList<qint64>>);

