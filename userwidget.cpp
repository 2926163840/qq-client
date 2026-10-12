#include "userwidget.h"
#include "ui_userwidget.h"



UserWidget::UserWidget(QString account,QString name,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UserWidget)
{
    ui->setupUi(this);
    //初始化窗口信息
    widgetInit();
    //加载背景页以及通知页背景
    EmptyTipWidget::SetEmptyTip(ui->backgroundpage,":/new/prefix1/picture/QQBackground.png","");
    EmptyTipWidget::SetEmptyTip(ui->friendnoticelist,":/new/prefix1/picture/NotNotice.png","暂无通知");

    ui->more->move(ui->more_2->pos());
    // //开局选中消息模式
    // QTimer::singleShot(0,this,[this]{
    //     ui->messagepattern->setChecked(true);
    //     //信息模式页
    //     ui->patternstacked->setCurrentIndex(MESSAGE_PATTERN);
    //     //背景页
    //     ui->chatwidget->setCurrentIndex(BACKGROUND_PATTERN);
    // });
    //显示用户名
    ui->username->setText(name);
    //好友列表分组初始化
    friendListInit();
    //群聊分组初始化
    groupListInit();
    //更多按钮初始化（创建加入好友群聊）
    moreButtonInit();
    //隐藏聊天窗口模型
    ui->userchatwidget->hide();
    //初始化接收业务信息信号
    readCmd();
    //登入成功告诉服务器可以把好友和群聊数据发过来了
    emit requestData();
    //收到消息后回复给服务器
    //connect(this,&UserWidget::recvSuccess,busmana,&BusinessManager::sendJson);
}

UserWidget::~UserWidget()
{
    delete ui;
}
//接收数据
void UserWidget::readCmd()
{
    //ui通知模式改变
    connect(this,&UserWidget::NoticePatternChanged,busmana,&BusinessManager::NoticePatternChanged);
    //ui焦点聊天窗口改变获取聊天记录
    connect(this,&UserWidget::getMes,busmana,&BusinessManager::getMes);
    //出现独立聊天窗口
    connect(this,&UserWidget::haveIndependChatWidget,busmana,&BusinessManager::haveIndependChatWidget);
    //窗口附着（拖回主窗口）
    connect(this,&UserWidget::chatwidgetAttached,busmana,&BusinessManager::chatwidgetAttached);
    //独立窗口销毁
    connect(this,&UserWidget::closeSelf,busmana,&BusinessManager::closeSelf);

    //有好友通知
    connect(busmana,&BusinessManager::haveFriendNotice,this,&UserWidget::RenderFriendNotice);
    //有聊天信息
    connect(busmana,&BusinessManager::haveChatMes,this,&UserWidget::RenderChatMes);
    //有未读消息添加计数
    connect(busmana,&BusinessManager::haveUnreadMes,this,&UserWidget::addUnreadCount);
    //消息状态变化(转圈圈/感叹号)
    connect(busmana,&BusinessManager::mesStatusChanged,this,&UserWidget::onMesStatusChanged);

    void haveUnreadMes(const QList<qint64>&urcv);

    //用户登入数据
    //登入成功获取好友群聊列表数据
    connect(this,&UserWidget::requestData,busmana,&BusinessManager::getFriendGroupInf0);
    //成功同意添加好友请求将好友添加到对应的分组中
    connect(busmana,&BusinessManager::sendFriendInfo,this,&UserWidget::addFriendItem);
    //同意或拒绝请求出错
    connect(busmana,&BusinessManager::addfriend_handlefailed,this,[this]{
        HoverTip::showTip(this,"请求超时请稍后重试······");
    });
    //还有通知状态改变
    connect(busmana,&BusinessManager::FriendNoticeStatusChanged,this,[this](const qint64 bindid,const NoticeMode newstatus){
        auto it=friendnoticeitemhash.find(bindid);
        if(it!=friendnoticeitemhash.end()&&it.value())
            it.value()->setStatus(newstatus);
    });

    // //接收好友消息
    // else if(data.value("cmd")=="friend_message")
    // {
    //     recvMessage(data.value("sendid").toInt(),data.value("content").toString());
    // }
}



//收到消息
void UserWidget::recvMessage(const qint64 sendid,const QString&content)
{
    QJsonObject reply;
    reply.insert("cmd","recvmessuccess");
    emit recvSuccess(reply);
}

//添加好友条目信息(好友列表)
void UserWidget::addFriendItem(const IdentityInfo identityinfo, const QString &friendname, const QString &friendidentity)
{
    auto groupit=friendlisthash.find(friendidentity);
    if(groupit==friendlisthash.end())return; // 分组不存在时忽略
    QTreeWidgetItem*item=new QTreeWidgetItem(groupit.value());
    //好友信息条目窗口
    ChatItem*itemwidget=new ChatItem(identityinfo,friendname);
    //建立信号（双击创建窗口）
    connect(itemwidget,&ChatItem::DoubleClicked,busmana,&BusinessManager::createChatWidget);
    connect(busmana,&BusinessManager::sendChatWidgetInfo,this,&UserWidget::createChatWidget);
    ui->friendlist->setItemWidget(item,0,itemwidget);
    item->setSizeHint(0,itemwidget->sizeHint());
    //将好友条目放到哈希表中
    chatitemhash.insert(identityinfo.convid,item);
}

//初始化群聊列表信息
void UserWidget::groupListInfoInit(const QHash<qint64,FriendInfo>&grouplist)
{
    // //遍历群聊json数组
    // for(auto info:grouplist)
    // {
    //     //取出数据
    //     QJsonObject value=info.toObject();
    //     int groupid=value.value("groupid").toInt();
    //     QString groupaccount=value.value("groupaccount").toString();
    //     QString groupname=value.value("groupname").toString();
    //     QString groupremark=value.value("groupremark").toString();
    //     QString useridentity=value.value("useridentity").toString();
    //     //哈希表中存在对应分组就将好友插入对应的分组中
    //     if(friendlisthash.value(useridentity)!=nullptr)
    //     {
    //         QTreeWidgetItem*item=new QTreeWidgetItem(grouplisthash.value(useridentity));
    //         //群名字或备注
    //         if(groupremark=="无")item->setText(0,groupname);
    //         else                item->setText(0,groupremark);
    //         //设置群聊id
    //         item->setData(0,Qt::UserRole,groupid);
    //     }
    // }
}


//创建群聊
void UserWidget::createGroup()
{

}
//创建聊天窗口信息(双击好友群聊条目触发)
void UserWidget::createChatWidget(const IdentityInfo &identityinfo,const QString&friendname)
{
    //对应的条目不存在则创建
    if(!messagelisthash.contains(identityinfo.convid))
    {
        //创建消息列表条目
        createChatWidget_Item(identityinfo,friendname);
    }//存在则清空未读计数
    else
        static_cast<ChatItem*>(ui->messagelist->itemWidget(messagelisthash.find(identityinfo.convid).value()))->removeUnreadCount();
    //聊天窗口窗口不存在则创建后切换
    if(!chatwidgethash.contains(identityinfo.convid))
    {
        createChatWidget_Widget(identityinfo,friendname);
    }
    //存在跳转到消息模式显示窗口
    else
    {
        //如果当前窗口不为双击好友对应的窗口则隐藏当前聊天窗口显示切换窗口反之显示聊天窗口
        ChatWidget*chatwidget=chatwidgethash.find(identityinfo.convid).value();
        //如果聊天窗口已经独立则直接顶层显示
        if(chatwidget->getIndepend()){chatwidget->show();chatwidget->raise();}
        //不独立但已经为焦点窗口
        else if(curchatwidget==chatwidget) {curchatwidget->show();}
        //如果有其他窗口在显示就隐藏显示当前的
        else if(curchatwidget)
        {
            curchatwidget->hide();
            curchatwidget=chatwidget;
            curchatwidget->show();
            //焦点窗口切换发出信号
            emit getMes(MesRequest::CHATFOCUS,chatwidget->getConvid());
        }
        //当前无正在展示的窗口
        else{
            curchatwidget=chatwidget;
            curchatwidget->show();
            //焦点窗口切换发出信号
            emit getMes(MesRequest::CHATFOCUS,chatwidget->getConvid());
        }
    }
    //跳转到消息模式
    ui->messagepattern->setChecked(true);
    //统一同步选中态
    syncSelectionState();
}
//创建聊天窗口
void UserWidget::createChatWidget_Widget(const IdentityInfo &identityinfo,const QString&friendname)
{
    ChatWidget*chatwidget=ChatWidget::createChatWidget(identityinfo,friendname);
    //拖拽窗口时独立聊天窗口
    connect(chatwidget,&ChatWidget::draging,this,&UserWidget::ChatWidget_Draging);
    //拖拽完成判断独立还是附着
    connect(chatwidget,&ChatWidget::draged,this,&UserWidget::ChatWidget_Draged);
    //独立窗口关闭
    connect(chatwidget,&ChatWidget::closeSelf,this,[this](const qint64 convid){
        chatwidgethash.remove(convid);
        //独立窗口销毁
        emit closeSelf(convid);
    });
    //滚动到顶部（历史记录拉旧）
    connect(chatwidget,&ChatWidget::loadOlder,this,[this](const qint64 convid){
        //拉旧中防重（和通知拉旧一样）
        if(get_ChatMesing) return;
        get_ChatMesing=true;
        getMes(MesRequest::CHATMORE,convid);
    });
    //发送消息信号
    connect(chatwidget,&ChatWidget::sendMes,busmana,&BusinessManager::sendMes);
    //将窗口加入哈希表
    chatwidgethash.insert(identityinfo.convid,chatwidget);
    //设置窗口初始位置
    toggleChatWidget(chatwidget);
}
//拖拽窗口时独立聊天窗口
void UserWidget::ChatWidget_Draging(ChatWidget *obj)
{
    obj->setParent(nullptr);
    //如果是将焦点窗口独立设为背景页
    if(curchatwidget==obj)
    {
        curchatwidget=nullptr;
        ui->chatwidget->setCurrentIndex(BACKGROUND_PATTERN);
        //窗口独立
        emit haveIndependChatWidget(obj->getConvid());
        //焦点消失
        emit getMes(MesRequest::CHATFOCUS,-1);
    }
    //真正变成独立窗口
    obj->setWindowFlag(Qt::Window,true);
    //改变独立标志位
    obj->setIndepend(true);
    obj->show();
    //独立后清除对应条目选中态
    syncSelectionState();
}
//拖拽完成判断独立还是附着
void UserWidget::ChatWidget_Draged(ChatWidget *obj)
{
    //计算附着面积（聊天页上8分之一）
    QPoint leftp=ui->userchatwidget->mapToGlobal(QPoint(0,0));
    QRect adherisonrect(leftp.x(),leftp.y(),ui->userchatwidget->width(),ui->userchatwidget->height()/12);
    //拖拽后的独立聊天窗口左上角坐标
    QPoint objleftp=obj->frameGeometry().topLeft();
    //当前页为背景页且窗口无正在展示的聊天窗口且独立窗口左上角坐标处于附着面积处则附着
    if(ui->chatwidget->currentWidget()==ui->backgroundpage&&
        curchatwidget==nullptr&&
        adherisonrect.contains(objleftp)&&
        isVisible()&&
        !isMinimized())
    {
        //改变独立标志位
        obj->setIndepend(false);
        //关闭状态栏
        obj->setTitlebarStatus(false);
        //走切换窗口代码（重新加入布局改变焦点窗口）
        toggleChatWidget(obj);
        //焦点改变
        emit getMes(MesRequest::CHATFOCUS,obj->getConvid());
        //窗口附着
        emit chatwidgetAttached(obj->getConvid());
    }
    //反之成功独立窗口
    else{
        //显示状态栏
        obj->setTitlebarStatus(true);
    }
}
//创建消息列表条目
void UserWidget::createChatWidget_Item(const IdentityInfo &identityinfo, const QString &friendname)
{
    //消息列表条目
    ChatItem*itemwidget=new ChatItem(identityinfo,friendname);
    //单击判断窗口是否还存在
    connect(itemwidget,&ChatItem::Clicked,this,[this,identityinfo,friendname](qint64 convid){
        ChatWidget*cw=chatwidgethash.value(convid,nullptr);
        //窗口不存在则创建
        if(!cw)
            createChatWidget_Widget(identityinfo,friendname);
        //窗口独立只激活独立窗口(条目不选中)
        else if(cw->getIndepend())
        {
            cw->show();
            cw->raise();
        }
        //窗口附着切换显示(内部统一同步选中态)
        else
            toggleChatWidget(cw);
    });

    //新建立的窗口置顶
    QListWidgetItem *item=new QListWidgetItem;
    item->setSizeHint(itemwidget->sizeHint());
    ui->messagelist->insertItem(0,item);
    ui->messagelist->setItemWidget(item,itemwidget);
    ui->messagelist->setCurrentItem(0);    
    //将消息条目放到哈希表中
    messagelisthash.insert(identityinfo.convid,item);
}
//设置聊天窗口隐藏和显示
void UserWidget::toggleChatWidget(ChatWidget *chatwidget)
{
    //选择窗口为独立窗口
    if(chatwidget->getIndepend())
    {
        //顶层显示
        chatwidget->show();
        chatwidget->raise();
        //独立窗口条目不选中
        syncSelectionState();
        //返回不发送后续聊天窗口焦点改变信号
        return;
    }
    qint64 convid=chatwidget->getConvid();
    //没有加进布局里面加进去
    if(chatwidget->parentWidget()!=ui->userchatpage)
    {
        ui->userchatpage->layout()->addWidget(chatwidget);
    }

    //当前窗口不为空且不为选择的窗口隐藏换成要切换的窗口
    if(curchatwidget&&curchatwidget!=chatwidget)
    {
        ui->chatwidget->setCurrentIndex(CHAT_PATTERN);
        curchatwidget->hide();
        curchatwidget=chatwidget;
        curchatwidget->show();
    }
    //当前窗口为选择窗口直接隐藏且至背景页
    else if(curchatwidget==chatwidget)
    {
        curchatwidget->hide();
        curchatwidget=nullptr;
        ui->chatwidget->setCurrentIndex(BACKGROUND_PATTERN);
        //无展示窗口将焦点convid变为-1
        convid=-1;
    }
    //为空直接赋值显示
    else
    {
        ui->chatwidget->setCurrentIndex(CHAT_PATTERN);
        curchatwidget=chatwidget;
        curchatwidget->show();
    }
    //焦点窗口切换发出信号
    emit getMes(MesRequest::CHATFOCUS,convid);
    //统一同步消息条目选中态
    syncSelectionState();
}

//根据当前焦点窗口统一同步消息条目选中态
void UserWidget::syncSelectionState()
{
    //本次应该选中的会话id:curchatwidget 为空(无焦点窗口)则为 -1
    qint64 target = curchatwidget ? curchatwidget->getConvid() : -1;

    //目标没变,选中态无需调整
    if(target == m_selectedConvid) return;

    //撤销旧的上一次选中的条目取消选中(上次无选中则 m_selectedConvid==-1,跳过)
    if(m_selectedConvid != -1 && messagelisthash.contains(m_selectedConvid))
    {
        ChatItem*old=static_cast<ChatItem*>(ui->messagelist->itemWidget(messagelisthash.value(m_selectedConvid)));
        if(old) old->setSelected(false);
    }

    //选中新的本次目标条目选中(本次无焦点则 target==-1,跳过)
    if(target != -1 && messagelisthash.contains(target))
    {
        ChatItem*cur=static_cast<ChatItem*>(ui->messagelist->itemWidget(messagelisthash.value(target)));
        if(cur) cur->setSelected(true);
    }

    //记录本次选中结果,供下次增量撤销
    m_selectedConvid = target;
}

//添加好友或群聊
void UserWidget::addFriOrGro()
{
    //显示添加好友窗口
    AddFriend*addmem=new AddFriend;
    //父窗口销毁他也跟着销毁
    connect(this,&UserWidget::quitInterface,addmem,&AddFriend::close);
    //关闭窗口自销毁
    addmem->setAttribute(Qt::WA_DeleteOnClose);
    addmem->show();
}
//显示好友通知
void UserWidget::RenderFriendNotice(const std::shared_ptr<QList<DisplayNoticeInfo>>&ldpni)
{
    NoticeMode MODE=NoticeMode::NONE;
    for(const auto&dpni:*ldpni)
    {
        switch(dpni.status)
        {
            //待处理
        case 1:
            if(dpni.payload.value("sendid").toInteger()==dpni.userid)
                MODE=NoticeMode::PENDINGVERIFICATION;
            else
                MODE=NoticeMode::PLEASEVERIFICATION;
            break;
            //已同意
        case 2:
            MODE=NoticeMode::AGREED;
            break;
            //已拒绝
        case 3:
            MODE=NoticeMode::REFUSED;
            break;
        }
        //存在
        if(MODE!=NoticeMode::NONE)
        {
            //条目窗口
            FriendNoticeItem*itemwidget=new FriendNoticeItem(dpni.payload.value("friendname").toString(),
                                                                dpni.payload.value("verificationmes").toString(),
                                                                dpni.sendtime,
                                                                dpni.bindid,
                                                                MODE);
            //为处理着接收处理信息数据
            if(MODE==NoticeMode::PLEASEVERIFICATION)
            {
                connect(itemwidget,&FriendNoticeItem::sendJson,busmana,&BusinessManager::noticeResult);
            }
            //通知条目
            QListWidgetItem*item=new QListWidgetItem;
            //将条目添加到好友通知列表中
            ui->friendnoticelist->addItem(item);
            //设置内嵌窗口合适大小
            item->setSizeHint(QSize(ui->friendnoticelist->viewport()->width(),itemwidget->sizeHint().height()));
            //将窗口内嵌到条目中
            ui->friendnoticelist->setItemWidget(item,itemwidget);
            //将条目信息插入哈希表中
            friendnoticeitemhash.insert(dpni.bindid,itemwidget);
        }
    }
    //如果是拉旧数据获取完毕取消拉取中状态
    if(get_NoticeMesing_Friend)get_NoticeMesing_Friend=false;
}
//有聊天信息 只做显示
void UserWidget::RenderChatMes(const std::shared_ptr<QList<Mes>> &ldpni)
{
    //收到拉旧结果（空或非空）就复位拉旧中标志
    get_ChatMesing=false;
    for(auto&row:*ldpni)
    {
        //窗口已打开直接显示消息
        if(chatwidgethash.contains(row.convid))
        {
            //拉旧的历史消息插入到开头，新消息追加到末尾
            if(row.isolder)
                chatwidgethash.value(row.convid)->insertMessage(row.isself,row.friendname,row.content);
            else
                chatwidgethash.value(row.convid)->addMessage(row.isself,row.friendname,row.content);
        }
    }
}
//消息状态变化(发送中/发送成功/发送失败)
void UserWidget::onMesStatusChanged(const QString&uuid,qint64 convid,qint8 status)
{
    //窗口不存在不处理
    if(!chatwidgethash.contains(convid))
        return;
    ChatWidget*chatwidget=chatwidgethash.find(convid).value();
    //根据status更新气泡状态
    chatwidget->updateBubbleStatus(uuid,status);
}
//添加未读计数
void UserWidget::addUnreadCount(const QList<qint64> &uncv)
{
    for(auto&row:uncv)
    {
        //条目不存在则创建
        if(!messagelisthash.contains(row))
        {
            IdentityInfo identityinfo("Friend", row);
            createChatWidget_Item(identityinfo, busmana->getFriendName(row));
        }
        //添加未读计数
        ChatItem*chatitem=static_cast<ChatItem*>(ui->messagelist->itemWidget(messagelisthash.find(row).value()));
        if(chatitem)
            chatitem->addUnreadCount();
    }
}

//好友列表初始化
void UserWidget::friendListInit()
{
    //好友列表
    //我的好友
    QTreeWidgetItem *myfriend = new QTreeWidgetItem(ui->friendlist);
    myfriend->setText(0, "我的好友");
    //没有字条目也显示箭头
    myfriend->setChildIndicatorPolicy(QTreeWidgetItem::ShowIndicator);
    //加入好友哈希容器
    friendlisthash.insert("我的好友",myfriend);
    //朋友
    QTreeWidgetItem*mygoodfriend=new QTreeWidgetItem(ui->friendlist);
    mygoodfriend->setText(0,"朋友");
    mygoodfriend->setChildIndicatorPolicy(QTreeWidgetItem::ShowIndicator);
    friendlisthash.insert("朋友",mygoodfriend);
    //同学
    QTreeWidgetItem*classmate=new QTreeWidgetItem(ui->friendlist);
    classmate->setText(0,"同学");
    classmate->setChildIndicatorPolicy(QTreeWidgetItem::ShowIndicator);
    friendlisthash.insert("同学",classmate);
    //家人
    QTreeWidgetItem*family=new QTreeWidgetItem(ui->friendlist);
    family->setText(0,"家人");
    family->setChildIndicatorPolicy(QTreeWidgetItem::ShowIndicator);
    friendlisthash.insert("家人",family);
    //全部条目默认收起
    ui->friendlist->collapseAll();
}
//群聊列表初始化
void UserWidget::groupListInit()
{
    //群聊列表
    //我创建的群聊
    QTreeWidgetItem*mygroup=new QTreeWidgetItem(ui->grouplist);
    mygroup->setText(0,"我创建的群聊");
    mygroup->setChildIndicatorPolicy(QTreeWidgetItem::ShowIndicator);
    //加入群聊哈希容器
    grouplisthash.insert("群主",mygroup);
    //我加入的群聊
    QTreeWidgetItem*joinedgroup=new QTreeWidgetItem(ui->grouplist);
    joinedgroup->setText(0,"我加入的群聊");
    joinedgroup->setChildIndicatorPolicy(QTreeWidgetItem::ShowIndicator);
    grouplisthash.insert("群成员",joinedgroup);
    //我管理的群聊
    QTreeWidgetItem*managementgroup=new QTreeWidgetItem(ui->grouplist);
    managementgroup->setText(0,"我管理的群聊");
    managementgroup->setChildIndicatorPolicy(QTreeWidgetItem::ShowIndicator);
    grouplisthash.insert("管理员",managementgroup);
    // 全部默认收起
    ui->grouplist->collapseAll();
}
//更多按钮初始化（创建加入好友群聊）
void UserWidget::moreButtonInit()
{
    //加菜单
    QMenu*menu=new QMenu(this);
    //创建群聊事件
    QAction*creategroup=new QAction("创建群聊",this);
    //添加好友群事件
    QAction*addfriorgro=new QAction("加好友/群",this);
    //将事件加入菜单中
    menu->addAction(creategroup);
    menu->addAction(addfriorgro);
    //绑定action事件
    connect(creategroup,&QAction::triggered,this,&UserWidget::createGroup);
    connect(addfriorgro,&QAction::triggered,this,&UserWidget::addFriOrGro);
    //点击事件触发相应的事件
    connect(ui->more,&QPushButton::clicked,this,[=,this]{
        QPoint pos=ui->more->mapToGlobal(QPoint(0,ui->more->height()));
        menu->popup(pos);
    });
    connect(ui->more_2,&QPushButton::clicked,this,[=,this]{
        QPoint pos=ui->more->mapToGlobal(QPoint(0,ui->more->height()));
        menu->popup(pos);
    });
}
//界面功能初始化
void UserWidget::widgetInit()
{
    // 去掉标原生题栏
    setWindowFlags(Qt::FramelessWindowHint|Qt::NoDropShadowWindowHint|Qt::WindowMinimizeButtonHint);
    // 画logo
    QPixmap pix(":/new/prefix1/picture/QQICON.png");
    // 缩放至40×40，保持比例 + 平滑抗锯齿
    pix = pix.scaled(40, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->logo->setPixmap(pix);
    ui->logo->setFixedSize(40,40);

    //消息联系人通知模式可选
    ui->friendpattern->setCheckable(true);
    ui->messagepattern->setCheckable(true);
    ui->noticepattern->setCheckable(true);
    //加入模式按钮组
    //消息模式
    patterngroup.addButton(ui->friendpattern);
    patterngroup.addButton(ui->messagepattern);
    patterngroup.addButton(ui->noticepattern);
    //通知模式
    NoticePatternGroup.addButton(ui->friendnotice);
    NoticePatternGroup.addButton(ui->groupnotice);
    //开启互斥模式
    patterngroup.setExclusive(true);
    NoticePatternGroup.setExclusive(true);
    //选中模式切换(同时更换背景)
    connect(ui->messagepattern,&QPushButton::toggled,this,[this](bool checked){
        if(checked){
            ui->patternstacked->setCurrentIndex(MESSAGE_PATTERN);
            //有在显示的聊天窗口就切会聊天页
            if(curchatwidget)
            {ui->chatwidget->setCurrentIndex(CHAT_PATTERN);}
            //没有显示的聊天窗口设为背景页有就切会聊天页
            else
            {
                ui->chatwidget->setCurrentIndex(BACKGROUND_PATTERN);
            }
            emit NoticePatternChanged(NoticeViewType::NONE);
        }

    });
    connect(ui->friendpattern,&QPushButton::toggled,this,[this](bool checked){
        if(checked){
            ui->patternstacked->setCurrentIndex(FRIEND_PATTERN);
            ui->chatwidget->setCurrentIndex(BACKGROUND_PATTERN);
            //默认好友选项选中
            ui->userfriend->setChecked(true);
            emit NoticePatternChanged(NoticeViewType::NONE);
        }
    });
    connect(ui->noticepattern,&QPushButton::toggled,this,[this](bool checked){
        if(checked){
            //默认选中好友通知窗口
            ui->friendnotice->setChecked(true);
            ui->patternstacked->setCurrentIndex(NOTICE_PATTERN);
            ui->chatwidget->setCurrentIndex(FRIEND_NOTICE_PATTERN);
            emit NoticePatternChanged(NoticeViewType::FRIEND);
        }
    });
    //通知模式切换
    connect(ui->friendnotice,&QPushButton::clicked,this,[this]{
        ui->chatwidget->setCurrentIndex(FRIEND_NOTICE_PATTERN);
        emit NoticePatternChanged(NoticeViewType::FRIEND);
    });
    connect(ui->groupnotice,&QPushButton::clicked,this,[this]{
        ui->chatwidget->setCurrentIndex(GROUP_NOTICE_PATTERN);
        emit NoticePatternChanged(NoticeViewType::GROUP);
    });
    //通知信息拉到底（通知拉旧拉旧）
    connect(ui->friendnoticelist->verticalScrollBar(),&QScrollBar::valueChanged,this,[this](int value){
        //滑到底部获取更多通知信息
        if(value==ui->friendnoticelist->verticalScrollBar()->maximum()&&!get_NoticeMesing_Friend)
        {
            //获取中
            get_NoticeMesing_Friend=true;
            getMes(MesRequest::NOTICEMORE);
        }
    });
    //通知信息拉到底（通知拉旧拉旧）
    connect(ui->groupnoticelist->verticalScrollBar(),&QScrollBar::valueChanged,this,[this](int value){
        //滑到底部获取更多通知信息
        if(value==ui->groupnoticelist->verticalScrollBar()->maximum()&&!get_NoticeMesing_Friend)
        {
            //获取中
            get_NoticeMesing_Friend=true;
            getMes(MesRequest::NOTICEMORE);
        }
    });
    //默认打开是消息模式
    ui->messagepattern->setChecked(true);
    //信息模式页
    ui->patternstacked->setCurrentIndex(MESSAGE_PATTERN);
    //背景页
    ui->chatwidget->setCurrentIndex(BACKGROUND_PATTERN);


    //隐藏friendandgroupstacked各页QTreeWidget表头
    ui->friendlist->header()->hide();
    ui->grouplist->header()->hide();
    //让好友群聊按钮可选中
    ui->userfriend->setCheckable(true);
    ui->usergroup->setCheckable(true);
    //加入选择列表按键组
    switchlistgroup.addButton(ui->userfriend);
    switchlistgroup.addButton(ui->usergroup);
    //开启按键选中互斥
    switchlistgroup.setExclusive(true);
    //选中哪个显示哪个列表
    connect(ui->userfriend,&QPushButton::toggled,this,[this](bool checked)
            {
                if(checked)
                {
                    ui->friendandgroupstacked->setCurrentIndex(FRIEND_LIST);
                }
                else{
                    ui->friendandgroupstacked->setCurrentIndex(GROUP_LIST);
                }
            });
}

//按下获取坐标
void UserWidget::mousePressEvent(QMouseEvent *event)
{
    // event->pos() 是窗口内部坐标，判断点击落在你的标题栏widget区域
    QRect titleBarRect = ui->titlebar->geometry();
    if(event->button() == Qt::LeftButton && titleBarRect.contains(event->pos()))
    {
        m_isWindowDragging = true;
        // 记录鼠标相对于窗口左上角的偏移
        m_windowDragStartPos = event->globalPosition().toPoint() - this->frameGeometry().topLeft();
        event->accept();
    }
    QWidget::mousePressEvent(event);
}
//移动拖拽
void UserWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(m_isWindowDragging && event->buttons() && Qt::LeftButton)
    {
        this->move(event->globalPosition().toPoint() - m_windowDragStartPos);
        event->accept();
    }
    QWidget::mouseMoveEvent(event);
}
//松手取消
void UserWidget::mouseReleaseEvent(QMouseEvent *event)
{
    m_isWindowDragging = false;
    QWidget::mouseReleaseEvent(event);
}
//双击放大
void UserWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    // 双击范围限制在自定义标题栏内
    QRect titleBarRect = ui->titlebar->rect();
    if(titleBarRect.contains(event->pos()))
    {
        FullScreen();
        //成功消费事件不在向上传递
        event->accept();
    }
    QWidget::mouseDoubleClickEvent(event);
}
//全屏
void UserWidget::FullScreen()
{
    if(!isMax)
    {
        //记录全屏前的窗口信息
        previousscreen=saveGeometry();

        showMaximized();
        isMax=true;
        ui->max->setIcon(QIcon(":/picture/remax.png"));
    }
    else
    {
        //回复全屏前的窗口大小信息
        restoreGeometry(previousscreen);
        isMax=false;
        ui->max->setIcon(QIcon(":/picture/max.png"));
    }
}
//全屏按键
void UserWidget::on_max_clicked()
{
    FullScreen();
}

//关闭按钮
void UserWidget::on_close_clicked()
{
    emit quitInterface();
}

