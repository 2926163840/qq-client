#include "userwidget.h"
#include "ui_userwidget.h"



UserWidget::UserWidget(QString account,QString name,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UserWidget)
{
    ui->setupUi(this);
    //初始化窗口信息
    widgetInit();
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
    //初始化接收业务信息信号
    readCmd();
    //登入成功告诉服务器可以把好友和群聊数据发过来了
    loginSuccess();
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

    //用户登入数据
    //登入成功获取好友群聊列表数据
    connect(this,&UserWidget::requestData,busmana,&BusinessManager::getFriendGroupInf0);
    //初始化用户好友群聊数据
    connect(busmana,&BusinessManager::getuserdata_success,this,&UserWidget::UserDataInit);
    //获取数据失败退出用户界面
    connect(busmana,&BusinessManager::getuserdata_failed,this,&UserWidget::getUserDataFailed);
    //好友群聊数据拉取成功获取离线消息（消息增量）
    connect(this,&UserWidget::getUserDataSuccess,busmana,&BusinessManager::getOfflineMes);
    //成功申请加好友
    connect(busmana,&BusinessManager::haveFriendNotice,this,&UserWidget::RenderFriendNotice);
    //成功同意添加好友请求将好友添加到对应的分组中
    connect(busmana,&BusinessManager::sendFriendInfo,this,[this](const qint64 friendid,const QString&friendname,const QString&friendidentity){
        QTreeWidgetItem*item=new QTreeWidgetItem(friendlisthash.find(friendidentity).value());
        item->setData(0,Qt::UserRole,friendid);
        item->setText(0,friendname);
    });
    //同意或拒绝请求出错
    connect(busmana,&BusinessManager::addfriend_handlefailed,this,[this]{
        HoverTip::showTip(this,"请求超时请稍后重试······");
    });
    //还有通知状态改变
    connect(busmana,&BusinessManager::FriendNoticeStatusChanged,this,[this](const qint64 bindid,const NoticeMode newstatus){
        friendnoticeitemhash.find(bindid).value()->setStatus(newstatus);
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
    qDebug()<<content;
    emit recvSuccess(reply);
}

//初始化用户信息
void UserWidget::UserDataInit(const QHash<qint64,UserInfo>&friendlist,const QHash<qint64,UserInfo>&grouplist)
{
    //初始化好友信息
    friendListInfoInit(friendlist);
    //初始化群聊信息
    groupListInfoInit(grouplist);
    //初始化数据成功
    emit getUserDataSuccess();
}
//初始化好友列表信息
void UserWidget::friendListInfoInit(const QHash<qint64,UserInfo>&friendlist)
{
    //将好友信息加到列表中
    for(const auto&it:friendlist)
    {
        //根据分组将好友设置到对应的主条目内
        QTreeWidgetItem*item=new QTreeWidgetItem(friendlisthash.find(it.useridentity).value());
        //设置条目所对应的好友会话id
        item->setData(0,Qt::UserRole,it.convid);
        QString curname=it.userremark=="无"?it.username:it.userremark;
        //没备注显示用户名
        item->setText(0,curname);
    }
}
//初始化群聊列表信息
void UserWidget::groupListInfoInit(const QHash<qint64,UserInfo>&grouplist)
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
void UserWidget::RenderFriendNotice(const std::shared_ptr< QList<DisplayNoticeInfo>>&ldpni)
{

    NoticeMode MODE=NoticeMode::NONE;
    for(auto&dpni:*ldpni)
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
        if(MODE!=NoticeMode::NONE)
        {
            //通知条目窗口
            FriendNoticeItem*itemwidget=new FriendNoticeItem(dpni.payload.value("friendname").toString(),
                                            dpni.payload.value("verificationmes").toString(),
                                            dpni.sendtime,
                                            dpni.bindid,
                                            MODE);
            //为通知处理着接收处理信息数据
            if(MODE==NoticeMode::PLEASEVERIFICATION)
            {
                connect(itemwidget,&FriendNoticeItem::sendJson,busmana,&BusinessManager::noticeResult);
            }
            //通知条目
            QListWidgetItem*item=new QListWidgetItem;
            //将条目添加到好友通知列表中
            ui->friendnoticelist->addItem(item);
            //设置内嵌窗口合适大小
            item->setSizeHint(itemwidget->sizeHint());
            //将窗口内嵌到条目中
            ui->friendnoticelist->setItemWidget(item,itemwidget);
            //将条目信息插入哈希表中
            friendnoticeitemhash.insert(dpni.bindid,itemwidget);
        }
    }
    EmptyTipWidget::SetEmptyTip(ui->friendnoticelist,":/new/prefix1/picture/NotNotice.png","暂无通知");

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
    setWindowFlag(Qt::FramelessWindowHint,Qt::NoDropShadowWindowHint);
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
            ui->chatwidget->setCurrentIndex(BACKGROUND_PATTERN);
            EmptyTipWidget::SetEmptyTip(ui->backgroundwidget,":/new/prefix1/picture/QQBackground.png","");
            emit NoticePatternChanged(NoticeViewType::NONE);
        }
    });
    connect(ui->friendpattern,&QPushButton::toggled,this,[this](bool checked){
        if(checked){
            ui->patternstacked->setCurrentIndex(FRIEND_PATTERN);
            ui->chatwidget->setCurrentIndex(BACKGROUND_PATTERN);
            EmptyTipWidget::SetEmptyTip(ui->backgroundwidget,":/new/prefix1/picture/QQBackground.png","");
            //默认好友选项选中
            ui->userfriend->setChecked(true);
            emit NoticePatternChanged(NoticeViewType::NONE);
        }
    });
    connect(ui->noticepattern,&QPushButton::toggled,this,[this](bool checked){
        if(checked){
            //默认选中好友通知窗口
            ui->friendnotice->setChecked(true);
            ui->patternstacked->setCurrentIndex(FRIEND_NOTICE_PATTERN);
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
        m_windowDragStartPos = event->globalPos() - this->frameGeometry().topLeft();
        event->accept();
    }
    QWidget::mousePressEvent(event);
}
//移动拖拽
void UserWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(m_isWindowDragging && event->buttons() & Qt::LeftButton)
    {
        this->move(event->globalPos() - m_windowDragStartPos);
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
//成功登入准备拉取好友群聊列表数据
void UserWidget::loginSuccess()
{
    emit requestData();
}

//关闭按钮
void UserWidget::on_close_clicked()
{
    emit quitInterface();
}

