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

//通知状态                   //等待验证            请验证              已同意 已拒绝
enum class NoticeMode{NONE,PENDINGVERIFICATION,PLEASEVERIFICATION,AGREED,REFUSED};

//获取信息的类型        焦点改变拉新 滚轮上限拉旧 拉旧
enum class MesRequest{CHATFOCUS,CHATMORE,NOTICEMORE};
//消息状态             发送中  发送成功 失败
enum class MesStatus{SENDING,SENT,FAILED};

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

//会话身份
struct IdentityInfo{
    QString identity;  //会话身份（群聊or好友）
    qint64 convid;
};

//用户好友信息
struct FriendInfo{
    QString friendaccount;
    QString friendname;
    QString friendremark;
    QString friendidentity; //好友身份
    IdentityInfo friendidentityinfo;
};

//用户群聊信息
struct GroupInfo{
    QString groupaccount;
    QString groupname;
    QString groupremark;
    QString useridentity;//群身份
    IdentityInfo identityinfo;
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
        //将json字符串转换成json数据
        QByteArray pl_by=pl.toUtf8();
        payload=QJsonDocument::fromJson(pl_by).object();
        userid=uid;
        bindid=bid;
        sendtime=sendtm;
        status=st;
    }
};

//消息状态（服务器和客户端统一）
enum class MsgStatus : qint8
{
    Sending = 0,    // 发送中
    Delivered = 1,  // 已送达
    Failed = 2      // 失败
};

//消息结构体
struct Mes
{
    QString content;
    qint64 sendtime;
    qint64 convid;
    qint64 convseq;
    qint64 sendid;
    bool isself=false;
    QString friendname;
    QString uuid="";       // 消息唯一id
    qint8 status=1;     // 消息状态 默认已送达
    bool isolder=false; // 是否为拉旧的历史消息（决定插入开头还是追加末尾）
};

//发送中消息信息（哈希表value key是uuid）
struct SendingInfo
{
    QString uuid;       // 重发用
    qint64 convid;
    QString content;    // 重发需要重新发内容
    qint64 sendtime;    // 客户端发送时间戳 超时判断
    int retrycount;     // 重试次数
};

#define TIMEOUT_MS 60000      // 60秒总超时（3次重试5+15+25=45s，留余量给最后的ACK）
#define MAX_RETRY 3           // 最多重试3次
#define RETRY_INTERVAL 5000   // 定时器5秒
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

