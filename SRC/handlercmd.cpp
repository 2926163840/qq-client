#include "handlercmd.h"
#include<QDateTime>

HandlerCmd::HandlerCmd(QObject *parent)
    : QObject{parent}
{
    //传输json数据
    connect(this,&HandlerCmd::sendJson,netmana,&NetworkManager::sendJson);
    //传递好友通知信息给ui
    connect(dbmana,&DBManager::return_FRIENDNOTICE_Display,this,&HandlerCmd::haveFriendNotice);
    //传递好友通知信息给ui
    connect(dbmana,&DBManager::return_CONVMES_Display,this,&HandlerCmd::dispatchMes);



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
    //查询发送中消息
    connect(this,&HandlerCmd::getSendingMes,dbmana,&DBManager::getSendingMessages);
    //数据库返回发送中消息
    connect(dbmana,&DBManager::returnSendingMes,this,&HandlerCmd::initSendingHash);
    //定时重发
    connect(&retryTimer,&QTimer::timeout,this,&HandlerCmd::onRetryTimeout);

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
    qDebug()<<"拉旧";
}
//窗口独立
void HandlerCmd::haveIndependChatWidget(const qint64 convid)
{
    avtiveview.indepconv.insert(convid);
}
//剔除独立出口（附着和销毁都调用）
void HandlerCmd::removeIndepChat(const qint64 convid)
{
    avtiveview.indepconv.remove(convid);
}
//独立窗口销毁（剔除独立+重置边界）
void HandlerCmd::closeChatWidget(const qint64 convid)
{
    //剔除独立
    removeIndepChat(convid);
    //重置窗口聊天消息边界
    emit resetChatBounds(convid);
}
//判断消息应该是未读还是显示(拆成要显示的和未读的)
void HandlerCmd::judgeMes(const std::shared_ptr<QList<Mes>>&meslist,std::shared_ptr<QList<Mes>>&displaylist,QList<qint64>&unreadlist)
{
    displaylist=std::make_shared<QList<Mes>>();
    for(const auto&row:*meslist)
    {
        //拉旧的历史消息总是显示（用户主动滚动到顶拉的，不受焦点影响）
        if(row.isolder)
        {
            displaylist->append(row);
            continue;
        }
        //非焦点且非独立(未打开)只提示未读
        if(avtiveview.focusconv!=row.convid&&!avtiveview.indepconv.contains(row.convid))
            unreadlist.append(row.convid);
        //焦点窗口和独立窗口 要显示
        else
            displaylist->append(row);
    }
}
//消息分发(判断+emit 拉取历史/别人发/离线都用)
void HandlerCmd::dispatchMes(const std::shared_ptr<QList<Mes>>&meslist)
{
    std::shared_ptr<QList<Mes>> displaylist;
    QList<qint64> unreadlist;
    judgeMes(meslist,displaylist,unreadlist);
    if(!unreadlist.isEmpty())
        emit haveUnreadMes(unreadlist);
    //无条件发（哪怕空列表，让 UI 复位拉旧中标志）
    emit haveChatMes(displaylist);
}
//消息落库+分发(别人发/离线用)
void HandlerCmd::persistMes(const std::shared_ptr<QList<Mes>>&meslist)
{
    if(meslist->isEmpty())
        return;
    //落库
    emit sendOfflineMes(userid,meslist);
    //分发
    dispatchMes(meslist);
}
//发送消息
void HandlerCmd::sendMes(const qint64 convid, const QString &content, const QString &uuid)
{
    qint64 sendtime=QDateTime::currentMSecsSinceEpoch();

    //断连了：直接标失败 不加入哈希表 不发网络
    if(!netmana->isConnected())
    {
        //构造失败消息落库
        std::shared_ptr<QList<Mes>> meslist=std::make_shared<QList<Mes>>();
        Mes m;
        m.uuid=uuid;
        m.convid=convid;
        m.convseq=-1;
        m.sendid=userid;
        m.content=content;
        m.sendtime=sendtime;
        m.status=static_cast<qint8>(MsgStatus::Failed);
        meslist->emplace_back(m);
        emit sendOfflineMes(userid,meslist);
        //通知UI报红
        emit mesStatusChanged(uuid,convid,static_cast<qint8>(MsgStatus::Failed));
        return;
    }

    //内存哈希表记录发送中
    {
        QMutexLocker locker(&sendingMutex);
        sendinghash.insert(uuid,{uuid,convid,content,sendtime,0});
    }

    //构造发送中消息落库(序列-1 状态发送中)
    std::shared_ptr<QList<Mes>> meslist=std::make_shared<QList<Mes>>();
    Mes m;
    m.uuid=uuid;
    m.convid=convid;
    m.convseq=-1;
    m.sendid=userid;
    m.content=content;
    m.sendtime=sendtime;
    m.status=static_cast<qint8>(MsgStatus::Sending);
    meslist->emplace_back(m);
    emit sendOfflineMes(userid,meslist);

    //发网络
    QJsonObject senddata;
    senddata.insert("cmd","sendmessage");
    senddata.insert("convid",convid);
    senddata.insert("sendid",userid);
    senddata.insert("content",content);
    senddata.insert("uuid",uuid);
    emit sendJson(senddata);

    //开启定时器
    if(!retryTimer.isActive())
        retryTimer.start(RETRY_INTERVAL);
}

//登入成功获取数据回复
void HandlerCmd::handleloginsuccess(const QJsonObject&data)
{
    //获取用户数据成功
    if(data.value("result")=="getuserdata_success")
    {
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
        //先播种游标(插入convseqtable 保证后面查游标能查到 否则第一次登入查不到游标就不拉离线)
        if(!convidlist->isEmpty())
            emit sendConvSeed(userid,convidlist);
        //再通知业务层获取数据(拉离线 此时游标已播种)
        emit getuserdata_success(data.value("friendlist").toArray(),data.value("grouplist").toArray());
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
        qDebug()<<"lastseq"<<row.convseq;

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
void HandlerCmd::searchRequest(const QString&partaccount,const QString&lastaccount)
{
    QJsonObject data;
    data.insert("cmd","search");
    //部分账号信息
    data.insert("accountinfo",partaccount);
    //分页游标（上一批最后一条账号，首次为空）
    data.insert("lastaccount",lastaccount);
    emit sendJson(data);
}

//处理搜索回复命令
void HandlerCmd::handleSearchInfo(const QJsonObject&data)
{
    qDebug() << "搜索回复:" << data.value("result").toString()
        << " 好友数:" << data.value("friendinfo").toArray().size();
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

//从JSON数组解析消息列表（离线消息offlinemes和消息回执meslist共用）
std::shared_ptr<QList<Mes>> HandlerCmd::parseMesArray(const QJsonArray&arr)
{
    std::shared_ptr<QList<Mes>>allmes=std::make_shared<QList<Mes>>();
    allmes->reserve(arr.size());
    for(const auto&mes:arr)
    {
        QJsonObject row=mes.toObject();
        Mes m;
        m.convid=row.value("convid").toInteger();
        m.convseq=row.value("convseq").toInteger();
        m.sendid=row.value("sendid").toInteger();
        m.content=row.value("content").toString();
        m.sendtime=row.value("sendtime").toInteger();
        m.uuid=row.value("uuid").toString();
        m.status=row.value("status").toInt();
        allmes->emplace_back(m);
        qDebug()<<"m.content:"<<m.content;
    }
    return allmes;
}
//保存离线消息
void HandlerCmd::saveOfflineMes(const QJsonObject&data)
{
    QJsonArray offlinemes = data.value("offlinemes").toArray();
    int chunk_seq = data.value("chunk_seq").toInt(-1);
    int chunk_total = data.value("chunk_total").toInt(1);

    //分片：缓存，收齐后合并处理
    if (chunk_total > 1)
    {
        if (!offlineCollector.add(chunk_seq, chunk_total, offlinemes))
            return;  // 还没收齐
        offlinemes = offlineCollector.merged();
    }

    //复用解析函数，离线消息批量落库
    std::shared_ptr<QList<Mes>> allmes=parseMesArray(offlinemes);
    //有新的消息增量就落库+分发
    persistMes(allmes);
    //拉完离线消息后初始化发送中哈希表 此时剩下的发送中才是真正没入库的
    emit getSendingMes();
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
        qDebug() << "收到同意好友, friendidentity=" << data.value("friendidentity").toString()
                 << " bindid=" << data.value("bindid").toInteger();
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
                         data.value("friendconvseq").toInteger(),
                         data.value("friendid").toInteger(),
                         data.value("mygreet").toString(),
                         data.value("friendgreet").toString(),
                         data.value("sendtime").toInteger(),
                         data.value("bindid").toInteger(),
                         data.value("syncseq").toInteger(),
                         data.value("friendaccount").toString(),
                         data.value("friendremark").toString(),
                         data.value("friendname").toString(),
                         data.value("friendidentity").toString(),
                         data.value("uuid").toString(),
                         data.value("friendgreetuuid").toString());
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
                                  const QString&friendidentity,const QString&mygreetuuid,const QString&friendgreetuuid)
{
    //发送信息给数据库保存
    std::shared_ptr<QList<Mes>>allmes=std::make_shared<QList<Mes>>();
    //我的招呼信息
    Mes mygreet;
    mygreet.content=mycontent;
    mygreet.sendtime=sendtime;
    mygreet.convid=convid;
    mygreet.convseq=myconvseq;
    mygreet.sendid=userid;
    mygreet.uuid=mygreetuuid;
    mygreet.status=static_cast<qint8>(MsgStatus::Delivered);
    allmes->emplace_back(mygreet);
    //好友招呼信息
    Mes friendgreet;
    friendgreet.content=friendcontent;
    friendgreet.sendtime=sendtime;
    friendgreet.convid=convid;
    friendgreet.convseq=friendconvseq;
    friendgreet.sendid=friendid;
    friendgreet.uuid=friendgreetuuid;
    friendgreet.status=static_cast<qint8>(MsgStatus::Delivered);
    allmes->emplace_back(friendgreet);

    emit sendOfflineMes(userid,allmes);
    //通知状态改变将新通知信息发给数据库(只改状态和同步序列) 2为同意状态
    std::shared_ptr<QList<Notice>> allnotice=std::make_shared<QList<Notice>>();
    allnotice->emplace_back("",userid,-1,syncseq,bindid,-1,2,-1);

    //发送新的会话种子
    std::shared_ptr<QList<qint64>>convidseed=std::make_shared<QList<qint64>>(QList<qint64>{convid});
    emit sendConvSeed(userid,convidseed);
    //发送好友信息给业务层保存和ui渲染
    emit NewFriendInfo(friendid,convid,friendaccount,friendname,friendremark,friendidentity);
    //触发persistMes处理招呼信息
    emit persistMes(allmes);
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
        emit useraccount_exists();
    }
    else if(data.value("result").toString()=="register_sucess"){
        //注册成功
        QString useraccount=data.value("useraccount").toString();
        emit register_sucess(useraccount);
    }
    else if(data.value("result").toString()=="register_failed"){
        //注册失败
        emit register_failed();
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
//处理发送消息回复（批量回执：遍历 meslist）
void HandlerCmd::handleSendMessageReply(const QJsonObject&data)
{
    qDebug()<<"处理消息回执";
    //服务器批量回执：meslist 是消息数组
    QJsonArray meslist = data.value("meslist").toArray();

    //分片序号
    int chunk_seq = data.value("chunk_seq").toInt(-1);
    int chunk_total = data.value("chunk_total").toInt(1);

    //分片：缓存，收齐后合并处理
    if (chunk_total > 1)
    {
        if (!mesCollector.add(chunk_seq, chunk_total, meslist))
            return;  // 还没收齐
        meslist = mesCollector.merged();
    }

    //解析消息数组（复用 parseMesArray）
    std::shared_ptr<QList<Mes>> allmes = parseMesArray(meslist);

    //分离自己发的和别人发的
    std::shared_ptr<QList<Mes>> self = std::make_shared<QList<Mes>>();
    std::shared_ptr<QList<Mes>> others = std::make_shared<QList<Mes>>();
    for (auto &m : *allmes)
    {
        if (m.sendid == userid) self->emplace_back(m);
        else others->emplace_back(m);
    }

    //自己发的：移除哈希表 + 批量落库更新 + mesStatusChanged 逐个发
    if (!self->isEmpty())
    {
        for (const auto &m : *self)
        {
            QMutexLocker locker(&sendingMutex);
            sendinghash.remove(m.uuid);
        }
        emit sendOfflineMes(userid, self);
        for (const auto &m : *self)
            emit mesStatusChanged(m.uuid, m.convid, static_cast<qint8>(MsgStatus::Delivered));
    }

    //别人发的：批量落库 + 分发
    if (!others->isEmpty())
        persistMes(others);
}
//初始化发送中哈希表（登录/断线重连拉完离线消息后）
void HandlerCmd::initSendingHash(const std::shared_ptr<QList<Mes>>&sendingmes)
{
    qint64 now=QDateTime::currentMSecsSinceEpoch();
    std::shared_ptr<QList<Mes>> faillist=std::make_shared<QList<Mes>>();//失败的消息
    QList<QPair<QString,qint64>> failconvids;//失败的uuid+convid 通知UI
    {
        QMutexLocker locker(&sendingMutex);
        for(const auto&m:*sendingmes)
        {
            //超时直接判失败
            if(now-m.sendtime>TIMEOUT_MS)
            {
                Mes fm;
                fm.uuid=m.uuid;
                fm.convid=m.convid;
                fm.convseq=-1;
                fm.sendtime=m.sendtime;
                fm.status=static_cast<qint8>(MsgStatus::Failed);
                faillist->emplace_back(fm);
                failconvids.append(qMakePair(m.uuid,m.convid));
            }
            //未超时加入哈希表等定时器重发
            else
                sendinghash.insert(m.uuid,{m.uuid,m.convid,m.content,m.sendtime,0});
        }
    }
    //超时的批量落库
    if(!faillist->isEmpty())
        emit sendOfflineMes(userid,faillist);
    //通知UI显示失败感叹号
    for(const auto&fc:failconvids)
        emit mesStatusChanged(fc.first,fc.second,static_cast<qint8>(MsgStatus::Failed));
    //有发送中的开定时器
    if(!sendinghash.isEmpty())
        retryTimer.start(RETRY_INTERVAL);
}
//定时重发
void HandlerCmd::onRetryTimeout()
{
    qint64 now=QDateTime::currentMSecsSinceEpoch();
    std::shared_ptr<QList<Mes>> faillist=std::make_shared<QList<Mes>>();//失败的消息
    QList<QPair<QString,qint64>> failconvids;//失败的uuid+convid 通知UI
    {
        QMutexLocker locker(&sendingMutex);
        for(auto it=sendinghash.begin();it!=sendinghash.end();++it)
        {
            //没超时跳过
            if(now-it->sendtime<=TIMEOUT_MS)
                continue;
            //还能重试 重发(同uuid服务器幂等)
            if(it->retrycount<MAX_RETRY)
            {
                QJsonObject data;
                data.insert("cmd","sendmessage");
                data.insert("convid",it->convid);
                data.insert("sendid",userid);
                data.insert("content",it->content);
                data.insert("uuid",it->uuid);
                emit sendJson(data);
                it->sendtime=now;
                it->retrycount++;
            }
            //重试耗尽 构造失败消息
            else
            {
                Mes fm;
                fm.uuid=it->uuid;
                fm.convid=it->convid;
                fm.convseq=-1;
                fm.sendtime=it->sendtime;
                fm.status=static_cast<qint8>(MsgStatus::Failed);
                faillist->emplace_back(fm);
                failconvids.append(qMakePair(it->uuid,it->convid));
            }
        }
        //标失败的从哈希表剔除
        for(const auto&fc:failconvids)
            sendinghash.remove(fc.first);
    }
    //批量落库
    if(!faillist->isEmpty())
        emit sendOfflineMes(userid,faillist);
    //通知UI显示失败感叹号
    for(const auto&fc:failconvids)
        emit mesStatusChanged(fc.first,fc.second,static_cast<qint8>(MsgStatus::Failed));
    //哈希表空 停定时器
    if(sendinghash.isEmpty())
        retryTimer.stop();
}
