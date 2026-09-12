#ifndef BUSINESSMANAGER_H
#define BUSINESSMANAGER_H

#include <QObject>
#include<QJsonObject>
#include<QJsonArray>
#include<QJsonDocument>

#include"networkmanager.h"
#include"dbmanager.h"
#include"handlercmd.h"
#include"UserData.h"


class BusinessManager : public QObject
{
    Q_OBJECT
public:
    explicit BusinessManager(QObject *parent = nullptr);
    //获取业务管理对象静态实例
    static BusinessManager*getBusMana();
    //禁止拷贝
    BusinessManager(const BusinessManager&)=delete;
    BusinessManager operator=(const BusinessManager&)=delete;
    ~BusinessManager();
    //解析json数据
    void doJson(const QJsonObject&data);
    //记录登录历史
    void saveLoginHistory(const std::shared_ptr<QList<LoginHistory>>&lsr);
    //根据账号和是否记住密码输入密码
    void handleaAccountFocus(const QString&account);
    //用户注册
    void Register(const QString&username, const QString&password);
    //用户要登入
    void login(const QString&account,const QString&password);
    //登入成功
    void login_success(const qint64 id, const QString&username);
    //保存用户好友群聊信息
    void saveUserListData(const QJsonArray&friendlist,const QJsonArray&grouplist);
    //保存用户好友列表信息
    void saveFriendListData(const QJsonArray&friendlist);
    //保存用户群聊列表信息
    void saveGroupListData(const QJsonArray&grouplist);
    //获取消息增量包
    void getOfflineMes();
    //成功添加好友
    void NewFriendInfo(const qint64 friendid,const qint64 convid,const QString&friendaccount,const QString&friendname,
                       const QString&friendremark,const QString&friendidentity);


signals:
    //通知模式改变
    void NoticePatternChanged(const NoticeViewType NoticePattern);
    //获取历史登入信息
    void getLoginHistory();
    //发送历史登入账号信息给ui层渲染
    void senduiaccount(const QList<QString>&vaccount);
    //发送用户其他登入信息给用户
    void senduilogindata(const QString&password,bool auto_login,bool rem_pwd);
    //账号已存在
    void useraccount_exists();
    //注册成功
    void register_sucess(const QString&useraccount);
    //注册失败
    void register_failed();
    //登入成功
    void login_success_data(const QString&username);
    //账号再别处已登入
    void login_online();
    //密码错误
    void user_worningpassword();
    //账号不存在
    void user_accountnoexists();
    //登入成功拉取好友群聊列表信息
    void getFriendGroupInf0();
    //获取用户好友群聊数据成功
    void getuserdata_success(const QHash<qint64,UserInfo>&friendlist,const QHash<qint64,UserInfo>&grouplist);
    //获取数据失败
    void getuserdata_failed();
    //传递登入信息
    void sendLoginInfo(const QString&account,const QString&pwd,bool auto_login,bool rem_pwd,qint64 login_time);
    //获取会话信息
    void getConvInfo(std::shared_ptr<QList<qint64>>);
    //获取通知信息
    void getNoticeInfo(const qint64 userid);
    //搜索请求
    void searchRequest(const QString&partaccount);
    //搜索成功将数据发给ui层
    void snedSearchInfo(const QList<SearchInfo>&friendlist,const QList<SearchInfo>&grouplist);
    //搜索失败
    void searchFailed();
    //请求添加好友
    void requestAddFriend(const qint64 userid,const QString&verificationmes,const QString&remark,const QString&identity);
    //有好友通知
    void haveFriendNotice(const std::shared_ptr< QList<DisplayNoticeInfo>>&ldpni);
    //申请添加好友成功
    void addFriendReuqestSuccess();
    //申请添加好友失败
    void addFriendReuqestFailed();
    //添加了自己
    void addOneself();
    //好友通知状态改变
    void FriendNoticeStatusChanged(const qint64 bindid,const NoticeMode status);
    //同意或拒绝好友请求出错
    void addfriend_handlefailed();
    //成功添加好友发送好友信息给ui渲染
    void sendFriendInfo(const qint64 friendid,const QString&friendname,const QString&friendidentity);
    //接收好友通知处理结果
    void noticeResult(const QString&result,const qint64 requestkey);

private:
    // //获取网络全局单列
    NetworkManager*netmana=NetworkManager::getNetMana();
    // //获取数据库全局单列
    // DBManager*dbmana=DBManager::getDBManager();
    //处理业务逻辑对象
    HandlerCmd hc;
    //登入历史结构体
    QHash<QString,LoginHistory> loginhistory; //key==account
    //用户好友信息哈希表
    QHash<qint64,UserInfo>userinfohash; //key=friendid
    //用户群聊信息哈希表
    QHash<qint64,UserInfo>groupinfohash;//key=groupid
    //登入成功标志位
    bool loginsuccessflag=false;
    //用户id
    qint64 userid=-1;

};

#endif // BUSINESSMANAGER_H
