#include "businessmanager.h"
//获取单例
BusinessManager *BusinessManager::getBusMana()
{
    static std::unique_ptr<BusinessManager>busmana=std::make_unique<BusinessManager>();
    return busmana.get();
}

BusinessManager::~BusinessManager()
{

}
BusinessManager::BusinessManager(QObject *parent)
    : QObject{parent}
{
    //接收网络数据
    connect(netmana,&NetworkManager::recvJson,this,&BusinessManager::doJson);
    //ui通知模式改变
    connect(this,&BusinessManager::NoticePatternChanged,&hc,&HandlerCmd::NoticePatternChanged);

    //窗口独立
    connect(this,&BusinessManager::haveIndependChatWidget,&hc,&HandlerCmd::haveIndependChatWidget);
    //独立窗口销毁或改变
    connect(this,&BusinessManager::removeIndependChatWidget,&hc,&HandlerCmd::removeIndependChatWidget);

    //有好友通知
    connect(&hc,&HandlerCmd::haveFriendNotice,this,&BusinessManager::haveFriendNotice);
    //有聊天消息
    connect(&hc,&HandlerCmd::haveChatMes,this,&BusinessManager::chatMesOwern);
    //有未读的聊天信息
    connect(&hc,&HandlerCmd::haveUnreadMes,this,&BusinessManager::haveUnreadMes);


    //注册
    //账号已存在
    connect(&hc,&HandlerCmd::useraccount_exists,this,&BusinessManager::useraccount_exists);
    //注册成功
    connect(&hc,&HandlerCmd::register_sucess,this,&BusinessManager::register_sucess);
    //注册失败
    connect(&hc,&HandlerCmd::register_failed,this,&BusinessManager::register_failed);

    //登入
    //获取登录历史记录
    connect(this,&BusinessManager::getLoginHistory,&hc,&HandlerCmd::getLoginHistory);
    //保存登入历史记录
    connect(&hc,&HandlerCmd::returnLoginHistory,this,&BusinessManager::saveLoginHistory);
    //登入成功
    connect(&hc,&HandlerCmd::login_success,this,&BusinessManager::login_success);
    //账号在别处登入
    connect(&hc,&HandlerCmd::login_online,this,&BusinessManager::login_online);
    //密码错误
    connect(&hc,&HandlerCmd::user_worningpassword,this,&BusinessManager::user_worningpassword);
    //账号不存在
    connect(&hc,&HandlerCmd::user_accountnoexists,this,&BusinessManager::user_accountnoexists);

    //获取数据
    //登入成功获取好友群聊列表数据
    connect(this,&BusinessManager::getFriendGroupInf0,&hc,&HandlerCmd::getFriendGroupInfo);
    //获取用户好友群聊数据成功
    connect(&hc,&HandlerCmd::getuserdata_success,this,&BusinessManager::saveUserListData);
    //登入成功传递登入信息
    connect(this,&BusinessManager::sendLoginInfo,&hc,&HandlerCmd::sendLoginInfo);
    //获取数据失败
    connect(&hc,&HandlerCmd::getuserdata_failed,this,&BusinessManager::getuserdata_failed);
    //获取消息增量(先回去会话信息handler内部拉取信息增量)
    connect(this,&BusinessManager::getConvInfo,&hc,&HandlerCmd::getConvInfo);
    //获取通知增量
    connect(this,&BusinessManager::getNoticeInfo,&hc,&HandlerCmd::getNoticeInfo);

    //搜索
    //搜索数据
    connect(this,&BusinessManager::searchRequest,&hc,&HandlerCmd::searchRequest);
    //搜索成功返回数据给ui层
    connect(&hc,&HandlerCmd::snedSearchInfo,this,&BusinessManager::snedSearchInfo);
    //搜索失败
    connect(&hc,&HandlerCmd::searchFailed,this,&BusinessManager::searchFailed);

    //添加好友
    //添加好友请求
    connect(this,&BusinessManager::requestAddFriend,&hc,&HandlerCmd::requestAddFriend);
    //通知处理结果
    connect(this,&BusinessManager::noticeResult,&hc,&HandlerCmd::noticeResult);
    //申请添加好友请求失败
    connect(&hc,&HandlerCmd::addFriendReuqestSuccess,this,&BusinessManager::addFriendReuqestSuccess);
    //申请添加好友请求失败
    connect(&hc,&HandlerCmd::addFriendReuqestFailed,this,&BusinessManager::addFriendReuqestFailed);
    //添加自己
    connect(&hc,&HandlerCmd::addOneself,this,&BusinessManager::addOneself);
    //添加好友成功发送好友信息
    connect(&hc,&HandlerCmd::NewFriendInfo,this,&BusinessManager::NewFriendInfo);
    //同意或拒绝好友请求出错
    connect(&hc,&HandlerCmd::addfriend_handlefailed,this,&BusinessManager::addfriend_handlefailed);

    //通知状态改变
    connect(&hc,&HandlerCmd::FriendNoticeStatusChanged,this,&BusinessManager::FriendNoticeStatusChanged);
}

//解析json数据
void BusinessManager::doJson(const QJsonObject&data)
{
    //注册
    if(data.value("cmd").toString()=="register_reply")
    {
        hc.handleRegisterCmd(data);
    }
    //登入回复
    else if(data.value("cmd").toString()=="login_reply")
    {
        hc.handleLoginCmd(data);
    }
    //用户成功登入获取好友群聊消息
    else if(data.value("cmd")=="user_loginsuccess_reply")
    {
        hc.handleloginsuccess(data);
    }
    //用户拉取离线消息
    else if(data.value("cmd")=="getofflinemes_reply")
    {
        hc.saveOfflineMes(data);
    }
    //用户拉取通知增量
    else if(data.value("cmd")=="getnoticemes_reply")
    {
        hc.saveNoticeMes(data);
    }
    //搜索信息
    else if(data.value("cmd")=="search_reply")
    {
        hc.handleSearchInfo(data);
    }
    //添加好友请求
    else if(data.value("cmd")=="addfriend_reply")
    {
        hc.handleaddfriend(data);
    }
    //收到好友请求
    else if(data.value("cmd")=="addfriend_request")
    {
        hc.addNewNotice(data.value("userid").toInteger(),
                        data.value("userseq").toInteger(),
                        data.value("bindid").toInteger(),
                        data.value("type").toInt(),
                        data.value("payload").toObject(),
                        data.value("status").toInt(),
                        data.value("sendtime").toInteger());
    }
    //接收好友消息
    else if(data.value("cmd")=="friend_message")
    {
        //recvMessage(data.value("sendid").toInt(),data.value("content").toString());
    }
}

//获取历史登入信息(自动登入)
void BusinessManager::saveLoginHistory(const std::shared_ptr<QList<LoginHistory>>&lsr)
{
    QList<QString>allaccount;
    bool lastlogin=true;
    QString password="";
    QString account;
    if(lsr->isEmpty())
    {
        return;
    }
    //将数据加到登入历史结构体数据里面
    for(auto&row:*lsr)
    {
        loginhistory.insert(row.historyaccount,row);
        if(lastlogin)
        {
            lastlogin=false;
            account=row.historyaccount;
            //第一次循环为最近一次登入者信息，根据是否记住密码获取密码信息
            password=row.historyrem_pwd?row.historypassword:"";
            //发送最近一次登入者的登入信息
            emit senduilogindata(password,row.historyauto_login,row.historyrem_pwd);
        }
        //历史账号信息
        allaccount.append(row.historyaccount);
    }
    //完成将数据发给ui层渲染用户账号
    emit senduiaccount(allaccount);
    //选中自动登入为true且为第一次登入
    if(loginhistory.find(account).value().historyauto_login&&!loginsuccessflag)
    {
        //自动登入
        login(account,password);
    }
}
//根据选中的账号和是否记住密码去输出
void BusinessManager::handleaAccountFocus(const QString&account)
{
    //获取下标
    QString curpassword=loginhistory.find(account).value().historyrem_pwd?loginhistory.find(account).value().historypassword:"";
    //发送自动登入记住密码状态
    emit senduilogindata(curpassword,
                         loginhistory.find(account).value().historyauto_login,
                         loginhistory.find(account).value().historyrem_pwd);
}

//用户注册
void BusinessManager::Register(const QString&username, const QString&password)
{
    //处理注册请求
    hc.handleRegister(username,password);
}
//用户登入
void BusinessManager::login(const QString&account,const QString&password)
{
    //处理层处理请求
    hc.handleLogin(account,password);
}
//登入成功(记录用户id)
void BusinessManager::login_success(const qint64 id, const QString&username)
{
    //登入过了
    loginsuccessflag=true;
    userid=id;
    emit login_success_data(username);
}
//保存和发送用户列表信息
void BusinessManager::saveUserListData(const QJsonArray&friendlist,const QJsonArray&grouplist)
{
    //保存用户好友列表信息
    saveFriendListData(friendlist);
    //保存用户群聊列表信息
    saveGroupListData(grouplist);
    //回去完成开始回去离线消息
    getOfflineMes();
    emit getuserdata_success();
}
//保存用户好友列表信息
void BusinessManager::saveFriendListData(const QJsonArray&friendlist)
{
    //回去好友列表数据添加到hash表中
    for(const auto&data:friendlist)
    {
        QJsonObject info=data.toObject();
        qint64 friendid=info.value("friendid").toInteger();
        qint64 convid=info.value("convid").toInteger();
        QString friendaccount=info.value("friendaccount").toString();
        QString friendname=info.value("friendname").toString();
        QString friendremark=info.value("friendremark").toString();
        QString friendidentity=info.value("friendidentity").toString();

        QString curname=friendremark=="无"?friendname:friendremark;
        IdentityInfo identityinfo("Friend",convid);
        FriendInfo userinfo(friendaccount,friendname,friendremark,friendidentity,identityinfo);
        userinfohash.insert(convid,userinfo);
        //发送给ui显示
        emit sendFriendInfo(identityinfo,curname,friendidentity);
    }
}
//保存和发送用户群聊列表信息
void BusinessManager::saveGroupListData(const QJsonArray &grouplist)
{

}
//获取离线消息和通知信息
void BusinessManager::getOfflineMes()
{
    //用户好友的会话id
    std::shared_ptr<QList<qint64>> userconv=std::make_shared<QList<qint64>>();
    for(auto&conv:userinfohash)
    {
        userconv->append(conv.friendidentityinfo.convid);
    }
    //将会话id发给处理层获取数据
    if(!userconv->isEmpty())
    {
        emit getConvInfo(userconv);
    }
    //将用户id发给处理层获取用户通知信息
    emit getNoticeInfo(userid);
}

//新的好友信息
void BusinessManager::NewFriendInfo(const qint64 friendid,const qint64 convid,const QString&friendaccount,const QString&friendname,
                                    const QString&friendremark,const QString&friendidentity)
{
    //会话身份
    IdentityInfo identityinfo("Friend",convid);
    //保存好友信息
    FriendInfo friendinfo(friendaccount,friendname,friendremark,friendidentity,identityinfo);
    userinfohash.insert(friendid,friendinfo);
    //将好友名和分组发给ui
    QString curname=friendremark=="无"?friendname:friendremark;
    emit sendFriendInfo(identityinfo,curname,friendidentity);
}
//创建聊天窗口
void BusinessManager::createChatWidget(const IdentityInfo &identityinfo)
{
    const auto&it=userinfohash.find(identityinfo.convid);
    if(it!=userinfohash.end())
    {
        QString curname=it->friendremark=="无"?it->friendname:it->friendremark;
        emit sendChatWidgetInfo(it->friendidentityinfo,curname);
    }
}

//获取信息（好友聊天记录或通知）
void BusinessManager::getMes(const MesRequest type, const qint64 convid)
{
    switch(type)
    {
        //焦点窗口改变
    case MesRequest::CHATFOCUS:
        //焦点窗口消失只改变焦点
        if(convid==-1)
            hc.chatWidgetChanged(convid);
        //反之获取聊天记录
        else hc.getNewChatHistory(convid);
        break;
        //获取更多聊天记录
    case MesRequest::CHATMORE:
        hc.getOlderChatHistory(convid);
        break;//获取更多通知
    case MesRequest::NOTICEMORE:
        hc.getOlderNoticeHistory();
        break;
    }
}
//判断消息的发送者
void BusinessManager::chatMesOwern(const std::shared_ptr<QList<Mes>> &ldpni)
{
    for(auto it=ldpni->begin();it!=ldpni->end();it++)
    {
        Mes&row=*it;
        if(userid==row.sendid)
        {
            row.isself=true;
        }
        else
        {
            FriendInfo&friendinfo=userinfohash.find(row.convid).value();
            QString curname=friendinfo.friendremark="无"?friendinfo.friendname:friendinfo.friendremark;
            row.friendname=curname;
            row.isself=false;
        }
        //好友不存在剔除消息r
        if(!userinfohash.contains(row.convid))
        {
            ldpni->erase(it);
            continue;
        }
    }
    emit haveChatMes(ldpni);
}

