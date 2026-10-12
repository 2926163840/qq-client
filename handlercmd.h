#ifndef HANDLERCMD_H
#define HANDLERCMD_H

#include <QObject>
#include<QJsonObject>
#include<QJsonArray>
#include<QUuid>
#include<QHash>
#include<QMutex>
#include<QTimer>

#include"networkmanager.h"
#include"dbmanager.h"
#include"UserData.h"

// 分片收集器：收分片 → 缓存 → 到齐后按序合并（消息回执和离线消息共用）
class ChunkCollector
{
public:
    // 塞一个分片，返回是否收齐（收齐后调 merged 拿合并结果）
    bool add(int seq, int chunk_total, const QJsonArray &data)
    {
        if (seq == 0)
        {
            chunks.clear();
            collected = 0;
            total = chunk_total;
        }
        chunks[seq] = data;
        collected++;
        return collected == total;
    }
    // 按 seq 顺序合并所有分片
    QJsonArray merged()
    {
        QJsonArray result;
        for (int i = 0; i < total; i++)
            for (const auto &item : chunks[i])
                result.append(item);
        return result;
    }

private:
    QHash<int, QJsonArray> chunks;
    int total = 0;
    int collected = 0;
};

class HandlerCmd : public QObject
{
    Q_OBJECT
public:
    explicit HandlerCmd(QObject *parent = nullptr);
    //通知模式改变(通知拉新)
    void NoticePatternChanged(const NoticeViewType NoticePattern);
    //拉旧通知
    void getOlderNoticeHistory();

    //选中窗口改变
    void chatWidgetChanged(const qint64 convid);
    //聊天记录拉新
    void getNewChatHistory(const qint64 convid);
    //聊天记录拉旧
    void getOlderChatHistory(const qint64 convid);
    //窗口独立
    void haveIndependChatWidget(const qint64 convid);
    //剔除独立出口（附着和销毁都调用）
    void removeIndepChat(const qint64 convid);
    //独立窗口销毁（剔除独立+重置边界）
    void closeChatWidget(const qint64 convid);

    //判断消息是否显示(拆成要显示的和未读的)
    void judgeMes(const std::shared_ptr<QList<Mes>>&meslist,std::shared_ptr<QList<Mes>>&displaylist,QList<qint64>&unreadlist);
    //消息分发(判断+emit 拉取历史/别人发/离线都用)
    void dispatchMes(const std::shared_ptr<QList<Mes>>&meslist);
    //消息落库+分发(别人发/离线用)
    void persistMes(const std::shared_ptr<QList<Mes>>&meslist);

    //发送消息
    void sendMes(const qint64 convid,const QString&content,const QString&uuid);


    //处理登入请求
    void handleLogin(const QString&account,const QString&password);
    //处理注册请求
    void handleRegister(const QString&username,const QString&password);
    //处理注册回复命令
    void handleRegisterCmd(const QJsonObject&data);
    //处理登入回复命令
    void handleLoginCmd(const QJsonObject&data);
    //处理登入成功命令
    void handleloginsuccess(const QJsonObject&data);
    //登入成功拉取好友群聊列表信息
    void getFriendGroupInfo();
    //获取离线会话信息
    void getOfflineMes(const std::shared_ptr<QList<ConvSLInfo>>&convinfo);
    //获取离线通知信息
    void getNoticeMes(const NoticeSLInfo&noticeslinfo);
    //保存离线消息
    void saveOfflineMes(const QJsonObject&data);
    //保存通知增量
    void saveNoticeMes(const QJsonObject&data);
    //搜索请求
    void searchRequest(const QString&partaccount,const QString&lastaccount);
    //处理搜索回复命令
    void handleSearchInfo(const QJsonObject&data);
    //搜索成功
    void searchSuccess(const QJsonArray&friendinfo,const QJsonArray&groupinfo);
    //添加好友请求
    void requestAddFriend(const qint64 userid,const QString&verificationmes,const QString&remark,const QString&identity);
    //有新通知
    void addNewNotice(const qint64 userid,const qint64 userseq,const qint64 bindid,const qint8 type,const QJsonObject&payload,const qint8 status,const qint64 sendtime);
    //接收好友通知处理结果
    void noticeResult(const QString&result,const qint64 requestkey);
    //处理添加好友回复命令
    void handleaddfriend(const QJsonObject&data);
    //保存申请通知
    void saveFriendRequest(const qint64 userid,const qint64 userseq,const qint64 bindid,const qint8 type,const QString&payload,const qint8 status,const qint64 sendtime);
    //添加好友成功
    void AddFriendSuccess(const qint64 convid,const qint64 myconvseq,const qint64 friendconvseq,const qint64 friendid,
                          const QString&mycontent,const QString&friendcontent,const qint64 sendtime,const qint64 bindid,
                          const qint64 syncseq,const QString&friendaccount,const QString&friendremark,const QString&friendname,
                          const QString&friendidentity,const QString&mygreetuuid,const QString&friendgreetuuid);
    //处理发送消息回复（成功确认/失败）
    void handleSendMessageReply(const QJsonObject&data);

signals:
    //发送json数据
    void sendJson(const QJsonObject&data);
    //获取历史登入信息
    void getLoginHistory();
    //返回历史登入信息
    void returnLoginHistory(const std::shared_ptr<QList<LoginHistory>>&loginhistoryinfo);
    //获取会话信息
    void getConvInfo(const qint64 userid,const std::shared_ptr<QList<qint64>>&convid);
    //获取通知信息
    void getNoticeInfo(const qint64 userid);
    //账号已存在
    void useraccount_exists();
    //注册成功
    void register_sucess(const QString&useraccount);
    //注册失败
    void register_failed();
    //登入成功
    void login_success(const qint64 userid,const QString&username);
    //发射用户通知种子(初始化通知序列)
    void sendNoticeSeed(const qint64 userid);
    //账号再别处已登入
    void login_online();
    //密码错误
    void user_worningpassword();
    //账号不存在
    void user_accountnoexists();
    //获取用户好友群聊数据成功
    void getuserdata_success(const QJsonArray&firendlist,const QJsonArray&grouplist);
    //将数据发给数据库播种游标(初始化未初始的游标序列)
    void sendConvSeed(const qint64 userid,const std::shared_ptr<QList<qint64>>&convid);
    //传递登入信息
    void sendLoginInfo(const QString&useraccount,const QString&userpassword,bool autologin,bool rempwd,qint64 login_time);
    //获取数据失败
    void getuserdata_failed();
    //发送离线消息给数据库处理
    void sendOfflineMes(const qint64 userid,const std::shared_ptr<QList<Mes>>&allmes);
    //发送通知增量给数据库处理
    void sendNoticeMes(const std::shared_ptr<QList<Notice>>&allnotice);
    //搜索失败
    void searchFailed();
    //搜索成功将数据发给业务层
    void snedSearchInfo(const QList<SearchInfo>&friendlist,const QList<SearchInfo>&grouplist);

    //申请添加好友成功
    void addFriendReuqestSuccess();
    //申请添加好友失败
    void addFriendReuqestFailed();
    //添加了自己
    void addOneself();
    // //成功同意好友添加好友请求
    // void successAgree(const qint64&friendid,const qint64&convid,const QString&friendaccount,const QString&friendname,
    //                   const QString&friendremark,const QString&friendidentity);
    //发送好友信息给ui渲染
    void NewFriendInfo(const qint64 friendid,const qint64 convid,const QString&friendaccount,const QString&friendname,
                       const QString&friendremark,const QString&friendidentity);
    //好友通知状态改变
    void FriendNoticeStatusChanged(const qint64 bindid,const NoticeMode status);
    //同意或拒绝好友请求出错
    void addfriend_handlefailed();
    //查询发送中消息
    void getSendingMes();
    //消息状态变化(status:0发送中 1已送达 2失败) UI根据status显示转圈圈/正常/感叹号
    void mesStatusChanged(const QString&uuid,qint64 convid,qint8 status);




    //拉新聊天记录
    void getChatHistory_New(const qint64 convid);
    //拉旧聊天记录
    void getChatHistory_Older(const qint64 convid);
    //有聊天消息
    void haveChatMes(const std::shared_ptr<QList<Mes>>&ldpni);
    //有未读消息添加计数
    void haveUnreadMes(const QList<qint64>&urcv);
    //独立出口销毁重置上下界
    void resetChatBounds(const qint64 convid);

    //拉新好友通知信息
    void getNewFriendNotice(const qint64 userid);
    //拉旧好友通知信息
    void getOlderFriendNotice(const qint64 userid);
    //有好友通知
    void haveFriendNotice(const std::shared_ptr<QList<DisplayNoticeInfo>>&ldpni);
    //有群通知
    void haveGroupNotice(QList<DisplayNoticeInfo> ldpni);

private:
    //网络层全局单例
    NetworkManager*netmana=NetworkManager::getNetMana();
    //数据库全局单例
    DBManager*dbmana=DBManager::getDBManager();
    //活跃窗口结构体
    ActiveView avtiveview;
    //用户通知信息
    NoticeInfo noticeinfo;
    //用户id
    qint64 userid=-1;
    //发送中消息哈希表 key=uuid
    QHash<QString,SendingInfo>sendinghash;
    //保护哈希表
    QMutex sendingMutex;
    //定时重发定时器
    QTimer retryTimer;
    //消息回执分片收集器
    ChunkCollector mesCollector;
    //离线消息分片收集器
    ChunkCollector offlineCollector;
    //从JSON数组解析消息列表（离线消息offlinemes和消息回执meslist共用）
    std::shared_ptr<QList<Mes>> parseMesArray(const QJsonArray&arr);
    //初始化发送中哈希表（登录/断线重连拉完离线消息后）
    void initSendingHash(const std::shared_ptr<QList<Mes>>&sendingmes);
    //定时重发回调
    void onRetryTimeout();
};

#endif // HANDLERCMD_H
