#include "handlercmd.h"

HandlerCmd::HandlerCmd(QObject *parent)
    : QObject{parent}
{
    //传输json数据
    connect(this,&HandlerCmd::sendJson,netmana,&NetworkManager::sendJson);
    //传递好友通知信息给ui
    connect(dbmana,&DBManager::return_FRIENDNOTICE_Display,this,&HandlerCmd::haveFriendNotice);
    //传递好友通知信息给ui
    connect(dbmana,&DBManager::return_CONVMES_Display,this,&HandlerCmd::judgeMes);



    //登入成功初始化通知序列
    connect(this,&HandlerCmd::sendNoticeSeed,dbmana,&DBManager::sowNoticeSeq);
    //保存登入记录
    connect(this,&HandlerCmd::sendLoginInfo,dbmana,&DBManager::saveLoginhist);
    //获取登入历史
    connect(this,&HandlerCmd::getLoginHistory,dbmana,&DBManager::getLoginHistory);
    //返回登入历史
    connect(dbmana,&DBManager::returnLoginHistory,this,&HandlerCmd::returnLoginHistory);
    //给会话游标播种
    connect(this,&HandlerCmd::sendConvSeed,dbmana,&DBManager::sowConvSeq);
    //获取会话信息
    connect(this,&HandlerCmd::getConvInfo,dbmana,&DBManager::getConvInfo);
    //获取通知信息
    connect(this,&HandlerCmd::getNoticeInfo,dbmana,&DBManager::getNoticeInfo);
    //接收数据库返回离线消息信息（消息增量）
    connect(dbmana,&DBManager::returnConvInfo,this,&HandlerCmd::getOfflineMes);
    //接收数据库返回的通知信息（消息增量）
    connect(dbmana,&DBManager::returnNoticeInfo,this,&HandlerCmd::getNoticeMes);
    //保存聊天信息
    connect(this,&HandlerCmd::sendOfflineMes,dbmana,&DBManager::saveOfflineMes);
    //保存通知信息
    connect(this,&HandlerCmd::sendNoticeMes,dbmana,&DBManager::saveNoticeMes);



    //好友通知拉新
    connect(this,&HandlerCmd::getNewFriendNotice,dbmana,&DBManager::getNewFriendNotice);
    //好友通知拉旧
    connect(this,&HandlerCmd::getOlderFriendNotice,dbmana,&DBManager::getOlderFriendNotice);
    //聊天记录拉新
    connect(this,&HandlerCmd::getChatHistory_New,dbmana,&DBManager::getChatHistory_New);
    //聊天记录拉新
    connect(this,&HandlerCmd::getChatHistory_Older,dbmana,&DBManager::getChatHistory_Older);
    //聊天记录重置上下界
    connect(this,&HandlerCmd::resetChatBounds,dbmana,&DBManager::resetChatBounds);

}
//通知模式改变（拉新通知信息）
void HandlerCmd::NoticePatternChanged(const NoticeViewType NoticePattern)
{
    avtiveview.NVT=NoticePattern;
    if(NoticePattern==NoticeViewType::FRIEND)
    emit getNewFriendNotice(userid);
    else if(NoticePattern==NoticeViewType::GROUP){};
}
//拉旧通知信息
void HandlerCmd::getOlderNoticeHistory()
{
    if(avtiveview.NVT==NoticeViewType::FRIEND)
        emit getOlderFriendNotice(userid);
    else if(avtiveview.NVT==NoticeViewType::GROUP){};
}
//焦点窗口改变获取聊天记录
void HandlerCmd::chatWidgetChanged(const qint64 convid)
{
    avtiveview.focusconv=convid;
}
//聊天记录拉新
void HandlerCmd::getNewChatHistory(const qint64 convid)
{
    //焦点改变
    chatWidgetChanged(convid);
    //拉新
    emit getChatHistory_New(convid);
}
//拉旧聊天记录
void HandlerCmd::getOlderChatHistory(const qint64 convid)
{
    //拉旧聊天记录
    emit getChatHistory_Older(convid);
    qDebug()<<999;
}
//窗口独立
void HandlerCmd::haveIndependChatWidget(const qint64 convid)
{
    avtiveview.indepconv.insert(convid);
}
//独立窗口销毁或改变
void HandlerCmd::removeIndependChatWidget(const qint64 convid)
{
    avtiveview.indepconv.remove(convid);
    emit resetChatBounds(convid);
}
//判断消息应该是未读还是显示
void HandlerCmd::judgeMes(const std::shared_ptr<QList<Mes>> &ldpni)
{
    QList<qint64> unreaditem;
    for(auto it=ldpni->begin();it!=ldpni->end();it++)
    {
        Mes&row=*it;
        //窗口未独立且不是焦点只提示未读
        if(avtiveview.focusconv!=row.convid&&avtiveview.indepconv.contains(row.convid))
        {
            unreaditem.append(row.convid);
            //从原容器中移除
            ldpni->erase(it);
        }
    }
    if(!unreaditem.empty())
        emit haveUnreadMes(unreaditem);
    //要显示的消息
    emit haveChatMes(ldpni);
}

//登入成功获取数据回复
void HandlerCmd::handleloginsuccess(const QJsonObject&data)
{
    //获取用户数据成功
    if(data.value("result")=="getuserdata_success")
    {
        //将数据发给业务层
        emit getuserdata_success(data.value("friendlist").toArray(),data.value("grouplist").toArray());
        //好友会话id容器
        std::shared_ptr<QList<qint64>> convidlist=std::make_shared<QList<qint64>>();
        //取出好友会话id
        for(const auto&row:data.value("friendlist").toArray())
        {
            QJsonObject friendinfo=row.toObject();
            convidlist->emplace_back(friendinfo.value("convid").toInteger());
        }
        for(const auto&row:data.value("grouplist").toArray())
        {
            QJsonObject friendinfo=row.toObject();
            convidlist->emplace_back(friendinfo.value("convid").toInteger());
        }
        //数据为空
        if(convidlist->isEmpty())
        {
            return;
        }
        //将会话id种子发给数据库
        emit sendConvSeed(convidlist);
    }
    //获取用户数据失败
    else if(data.value("result")=="getuserdata_failed")
    {
        getuserdata_failed();
    }
}
//登入成功拉取好友群聊列表信息
void HandlerCmd::getFriendGroupInfo()
{
    QJsonObject data;
    data.insert("cmd","user_loginsuccess");
    emit sendJson(data);
}
//获取离线消息（消息增量）
void HandlerCmd::getOfflineMes(const std::shared_ptr<QList<ConvSLInfo>>&convinfo)
{
    QJsonArray convinfoarray;
    //将会话信息全部放入json对象里面
    for(const auto&row:*convinfo)
    {
        QJsonObject convrow;
        convrow.insert("convid",row.convid);
        convrow.insert("lastseq",row.convseq);
        convinfoarray.append(convrow);
    }
    QJsonObject senddata;
    senddata.insert("cmd","getofflinemes");
    senddata.insert("convinfo",convinfoarray);
    emit sendJson(senddata);
}
//获取通知增量
void HandlerCmd::getNoticeMes(const NoticeSLInfo&noticeslinfo)
{
    QJsonObject senddata;
    senddata.insert("cmd","getnoticemes");
    senddata.insert("noticeseq",noticeslinfo.noticeseq);
    senddata.insert("syncseq",noticeslinfo.syncseq);
    emit sendJson(senddata);
}

//搜索请求
void HandlerCmd::searchRequest(const QString&partaccount)
{
    QJsonObject data;
    data.insert("cmd","search");
    //部分账号信息
    data.insert("accountinfo",partaccount);
    emit sendJson(data);
}

//处理搜索回复命令
void HandlerCmd::handleSearchInfo(const QJsonObject&data)
{
    //搜索成功显示到搜索界面
    if(data.value("result")=="search_success")
    {
        searchSuccess(data.value("friendinfo").toArray(),data.value("groupinfo").toArray());
    }
    //失败提示
    else if(data.value("result")=="search_failed")
    {
        emit searchFailed();
    }
}
//搜索成功
void HandlerCmd::searchSuccess(const QJsonArray&friendinfo,const QJsonArray&groupinfo)
{
    QList<SearchInfo> friendlist;
    QList<SearchInfo> grouplist;
    //将好友群聊数据放入容器
    for(const auto&row:friendinfo)
    {
        QJsonObject temp=row.toObject();
        friendlist.emplace_back(temp.value("friendaccount").toString(),temp.value("friendname").toString(),temp.value("friendid").toInteger());
    }
    for(const auto&row:groupinfo)
    {
        QJsonObject temp=row.toObject();
        grouplist.emplace_back(temp.value("groupaccount").toString(),temp.value("groupname").toString(),temp.value("groupid").toInteger());
    }
    //将取出的数据传会给业务层
    emit snedSearchInfo(friendlist,grouplist);
}

//保存离线消息
void HandlerCmd::saveOfflineMes(const QJsonObject&data)
{
    std::shared_ptr<QList<Mes>> allmes=std::make_shared<QList<Mes>>();
    //将离线消息全部取出放list容器里面
    for(const auto&mes:data.value("offlinemes").toArray())
    {
        QJsonObject row=mes.toObject();
        qint64 convid=row.value("convid").toInteger();
        qint64 convseq=row.value("convseq").toInteger();
        qint64 sendid=row.value("sendid").toInteger();
        QString content=row.value("content").toString();
        qint64 sendtime=row.value("sendtime").toInteger();
        allmes->emplace_back(content,sendtime,convid,convseq,sendid);
    }
    //没有新的消息增量
    if(allmes->isEmpty())
    {
        return;
    }
    //发送离线消息给数据库处理
    emit sendOfflineMes(allmes);
}
//保存通知增量
void HandlerCmd::saveNoticeMes(const QJsonObject &data)
{
    std::shared_ptr<QList<Notice>> noticeinfo=std::make_shared<QList<Notice>>();
    //读取通知增量
    for(const auto&mes:data.value("noticemes").toArray())
    {
        QJsonObject row=mes.toObject();
        qint64 userid=row.value("userid").toInteger();
        qint64 userseq=row.value("userseq").toInteger();
        qint64 syncseq=row.value("syncseq").toInteger();
        qint64 bindid=row.value("bindid").toInteger();
        qint8 type=row.value("type").toInt();
        QJsonObject payload=row.value("payload").toObject();
        QByteArray payload_by=QJsonDocument(payload).toJson(QJsonDocument::Compact);
        QString payload_str=QString::fromUtf8(payload_by);
        qint64 sendtime=row.value("sendtime").toInteger();
        qint8 status=row.value("status").toInt();
        noticeinfo->emplace_back(payload_str,userid,userseq,syncseq,bindid,type,status,sendtime);
    }
    //没有新的通知增量
    if(noticeinfo->isEmpty())
    {
        return;
    }
    //发送通知增量给数据库处理
    emit sendNoticeMes(noticeinfo);
}

//请求添加好友请求
void HandlerCmd::requestAddFriend(const qint64 userid,const QString&verificationmes,const QString&remark,const QString&identity)
{
    QJsonObject data;
    data.insert("cmd","addfriend");
    //接收用户id
    data.insert("recvid",userid);
    //验证消息
    data.insert("verificationinfo",verificationmes);
    QString curremark=remark.isEmpty()?"无":remark;
    //备注
    data.insert("remark",curremark);
    //所在分组
    data.insert("ingroup",identity);
    //uuid（去除大括号）
    data.insert("uuid",QUuid::createUuid().toString(QUuid::WithoutBraces));
    emit sendJson(data);
}
//有新通知
void HandlerCmd::addNewNotice(const qint64 userid,const qint64 userseq,const qint64 bindid,const qint8 type,const QJsonObject&payload,const qint8 status,const qint64 sendtime)
{
    const QByteArray&payload_by=QJsonDocument(payload).toJson();
    QString payload_str=QString::fromUtf8(payload_by);
    // QList<DisplayNoticeInfo> ldpni;
    // ldpni.emplaceFront(payload_str,userid,bindid,sendtime,status);
    //保存添加好友申请
    saveFriendRequest(userid,userseq,bindid,type,payload_str,status,sendtime);
    //如果当前界面是对应的通知窗口界面直接渲染
    switch(type)
    {
    case 1:
        //好友类型通知
        if(avtiveview.NVT==NoticeViewType::FRIEND&&type==1)
        {
            emit getNewFriendNotice(userid);
        }
        break;
    case 2:
        //群类型通知
        if(avtiveview.NVT==NoticeViewType::GROUP&&type==2)
        {
        }
        break;
    }

}
//添加好友处理结果
void HandlerCmd::noticeResult(const QString&result,const qint64 requestkey)
{
    QJsonObject reply;
    reply.insert("cmd","handlefriendrequest");
    reply.insert("result",result);
    reply.insert("reuqestkey",requestkey);
    emit sendJson(reply);
}
//处理添加好友回复命令
void HandlerCmd::handleaddfriend(const QJsonObject&data)
{
    //请求成功
    if(data.value("result")=="addfriend_success")
    {
        addNewNotice(data.value("userid").toInteger(),
                     data.value("userseq").toInteger(),
                     data.value("bindid").toInteger(),
                     data.value("type").toInt(),
                     data.value("payload").toObject(),
                     data.value("status").toInt(),
                     data.value("sendtime").toInteger());
        //
        emit addFriendReuqestSuccess();
    }
    //添加自己
    else if(data.value("result")=="addfriend_addoneself")
    {
        emit addOneself();
    }
    //请求失败(申请没发出去)
    else if(data.value("result")=="addfriend_failed")
    {
        emit addFriendReuqestFailed();
    }
    //同意好友请求
    else if(data.value("result")=="addfriend_agree")
    {
        AddFriendSuccess(data.value("convid").toInteger(),
                         data.value("myconvseq").toInteger(),
                         data.value("friendgreetseq").toInteger(),
                         data.value("friendid").toInteger(),
                         data.value("mygreet").toString(),
                         data.value("friendgreet").toString(),
                         data.value("sendtime").toInteger(),
                         data.value("bindid").toInteger(),
                         data.value("syncseq").toInteger(),
                         data.value("friendaccount").toString(),
                         data.value("friendremark").toString(),
                         data.value("friendname").toString(),
                         data.value("friendidentity").toString());
    }
    //拒绝好友请求
    else if(data.value("result")=="addfriend_refuse")
    {
        //用户在好友通知界面渲染新通知状态
        if(avtiveview.NVT==NoticeViewType::FRIEND)
        {
            emit FriendNoticeStatusChanged(data.value("bindid").toInteger(),NoticeMode::REFUSED);
        }
    }
    //同意或拒绝请求出错
    else if(data.value("result")=="addfriend_handlefailed")
    {
        emit addfriend_handlefailed();
    }
}
//保存好友申请
void HandlerCmd::saveFriendRequest(const qint64 userid,const qint64 userseq,const qint64 bindid,const qint8 type,const QString&payload,const qint8 status,const qint64 sendtime)
{
    //申请没有同步序列所以为0
    std::shared_ptr<QList<Notice>> temp=std::make_shared<QList<Notice>>();
    //新申请同步序列syncseq为0
    temp->emplace_back(payload,userid,userseq,0,bindid,type,status,sendtime);
    //保存申请通知
    emit sendNoticeMes(temp);
}
//添加好友成功
void HandlerCmd::AddFriendSuccess(const qint64 convid,const qint64 myconvseq,const qint64 friendconvseq,const qint64 friendid,
                                  const QString&mycontent,const QString&friendcontent,const qint64 sendtime,const qint64 bindid,
                                  const qint64 syncseq,const QString&friendaccount,const QString&friendremark,const QString&friendname,
                                  const QString&friendidentity)
{
    //发送信息给数据库保存
    std::shared_ptr<QList<Mes>>allmes=std::make_shared<QList<Mes>>();
    //我的招呼信息
    allmes->emplace_back(mycontent,sendtime,convid,myconvseq,userid);
    //好友招呼信息
    allmes->emplace_back(friendcontent,sendtime,convid,friendconvseq,friendid);
    emit sendOfflineMes(allmes);
    //通知状态改变将新通知信息发给数据库(只改状态和同步序列) 2为同意状态
    std::shared_ptr<QList<Notice>> allnotice=std::make_shared<QList<Notice>>();
    allnotice->emplace_back("",userid,-1,syncseq,bindid,-1,2,-1);
    emit sendNoticeMes(allnotice);
    //发送新的会话种子
    std::shared_ptr<QList<qint64>>convidseed=std::make_shared<QList<qint64>>(QList<qint64>{convid});
    emit sendConvSeed(convidseed);
    //发送好友信息给ui渲染
    emit NewFriendInfo(friendid,convid,friendaccount,friendname,friendremark,friendidentity);
    //用户在好友通知界面渲染新通知状态
    if(avtiveview.NVT==NoticeViewType::FRIEND)
    {
        emit FriendNoticeStatusChanged(bindid,NoticeMode::AGREED);
    }
}
//处理登回复入命令
void HandlerCmd::handleLoginCmd(const QJsonObject&data)
{
    //登入成功
    if(data.value("result").toString()=="login_success")
    {
        emit login_success(data.value("userid").toInteger(),data.value("username").toString());
        //记录登入者的id
        userid=data.value("userid").toInteger();
        //登入成功发射用户通知种子（初始化通知序列游标）
        emit sendNoticeSeed(userid);
    }
    //账号在别处登入
    else if(data.value("result").toString()=="login_online")
    {
        login_online();
    }
    //密码错误
    else if(data.value("result").toString()=="user_worningpassword")
    {
        user_worningpassword();
    }
    //账号不存在
    else if(data.value("result").toString()=="user_accountnoexists")
    {
        user_accountnoexists();
    }
}
//处理注册回复命令
void HandlerCmd::handleRegisterCmd(const QJsonObject&data)
{
    //账号已存在
    if(data.value("result").toString()=="useraccount_exists")
    {
        useraccount_exists();
    }
    else if(data.value("result").toString()=="register_sucess"){
        //注册成功
        register_sucess(data.value("useraccount").toString());
    }
    else if(data.value("result").toString()=="register_failed"){
        //注册失败
        register_failed();
    }
}
//处理登入请求
void HandlerCmd::handleLogin(const QString&account,const QString&password)
{
    QJsonObject senddata;
    senddata.insert("cmd","login");
    senddata.insert("useraccount",account);
    senddata.insert("userpassword",password);
    //网络层发送数据
    emit sendJson(senddata);
}
//处理注册请求
void HandlerCmd::handleRegister(const QString&username,const QString&password)
{
    QJsonObject info;
    info.insert("cmd","register");
    info.insert("username",username);
    info.insert("userpassword",password);
    emit sendJson(info);
}
