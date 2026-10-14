#include "addfriend.h"
#include "ui_addfriend.h"

AddFriend::AddFriend(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddFriend)
{
    ui->setupUi(this);
    // 去掉标原生题栏
    setWindowFlags(Qt::FramelessWindowHint|Qt::NoDropShadowWindowHint|Qt::WindowMinimizeButtonHint);
    //延迟设置初始背景
    QTimer::singleShot(0,this,[this]{
        //要手动切换一下不然第二页一开始没有展示默认不会初始化位置不对
        ui->tabWidget->setCurrentIndex(1);
        ui->tabWidget->setCurrentIndex(0);
        //初始状态为关键词背景1
        EmptyTipWidget::SetEmptyTip(ui->userlist,":/new/prefix1/picture/notkeyword.png","输入关键词搜素");
        EmptyTipWidget::SetEmptyTip(ui->grouplist,":/new/prefix1/picture/notkeyword.png","输入关键词搜素");
    });
    //进来就选中搜索框
    ui->searchedit->setFocus();
    //搜索
    //搜索请求
    connect(this,&AddFriend::search,busmana,&BusinessManager::searchRequest);
    //搜索成功
    connect(busmana,&BusinessManager::snedSearchInfo,this,&AddFriend::SearchSuccess);
    //搜索失败
    connect(busmana,&BusinessManager::searchFailed,this,&AddFriend::SearchFailed);

    //添加好友
    //请求成功
    connect(busmana,&BusinessManager::addFriendReuqestSuccess,this,&AddFriend::requestSuccess);
    //请求失败
    connect(busmana,&BusinessManager::addFriendReuqestFailed,this,&AddFriend::requestFailed);
    //添加了自己
    connect(busmana,&BusinessManager::addOneself,this,&AddFriend::NotAddOneself);

    //滚动到底加载更多搜索结果
    connect(ui->userlist->verticalScrollBar(),&QScrollBar::valueChanged,this,[this](int value){
        if(ui->userlist->verticalScrollBar()->maximum()>0 &&
           value==ui->userlist->verticalScrollBar()->maximum() &&
           !m_lastaccount.isEmpty())
            loadMore();
    });
}

AddFriend::~AddFriend()
{
    delete ui;
}

//按下获取坐标
void AddFriend::mousePressEvent(QMouseEvent *event)
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
void AddFriend::mouseMoveEvent(QMouseEvent *event)
{
    if(m_isWindowDragging && event->buttons() & Qt::LeftButton)
    {
        this->move(event->globalPosition().toPoint() - m_windowDragStartPos);
        event->accept();
    }
    QWidget::mouseMoveEvent(event);
}
//松手取消
void AddFriend::mouseReleaseEvent(QMouseEvent *event)
{
    m_isWindowDragging = false;
    QWidget::mouseReleaseEvent(event);
}
//双击放大
void AddFriend::mouseDoubleClickEvent(QMouseEvent *event)
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

//加载更多搜索结果
void AddFriend::loadMore()
{
    //没有关键词或没有上一批游标则不再拉
    if(m_curkeyword.isEmpty() || m_lastaccount.isEmpty())
        return;
    m_isloadmore=true;
    emit search(m_curkeyword,m_lastaccount);
}
//搜索失败
void AddFriend::SearchFailed()
{
    HoverTip::showTip(this,"没有搜索到相关内容");
}
//搜索成功
void AddFriend::SearchSuccess(const QList<SearchInfo>&friendlist,const QList<SearchInfo>&grouplist)
{
    //首次搜索清空，加载更多追加
    if(!m_isloadmore)
        ui->userlist->clear();
    //无搜索信息换背景
    if(friendlist.isEmpty())
    {
        if(!m_isloadmore)
        {
            user_backgroundflag=NOTRESULT;
            EmptyTipWidget::SetEmptyTip(ui->userlist,":/new/prefix1/picture/notresult.png","暂无搜索结果");
        }
    }
    else
    {
        //有数据去掉背景
        user_backgroundflag=HAVINGRESULT;
        EmptyTipWidget::SetEmptyTip(ui->userlist,"","");
        //读取搜索到的数据
        for(const auto&row:friendlist)
        {
            //拼接搜索到的用户信息
            QString text=QString("%1(%2)").arg(row.name,row.account);
            //条目内嵌窗口
            ItemWidget*itemwidget=new ItemWidget(text);
            //搜索条目
            QListWidgetItem*item=new QListWidgetItem;
            //将搜索条目添加到listwidget中
            ui->userlist->addItem(item);
            //给条目设置内嵌窗口
            ui->userlist->setItemWidget(item,itemwidget);
            //给内嵌窗口设置合适大小
            item->setSizeHint(itemwidget->sizeHint());
            //回去好友id
            const qint64&friendid=row.id;
            //当用户点击了添加按钮时打开添加好友窗口并将好友id传进去
            connect(itemwidget,&ItemWidget::addClicked,this,[friendid,text,this]{
                AddFriendWidget*addwidget=new AddFriendWidget(friendid,text);
                //设置关闭自动销毁
                addwidget->setAttribute(Qt::WA_DeleteOnClose);
                //主窗口销毁子窗口跟着销毁
                connect(this,&AddFriend::destroyed,addwidget,&AddFriendWidget::close);
                addwidget->show();
                //接收添加好友窗口发出的数据
                connect(addwidget,&AddFriendWidget::requestAddFriend,busmana,&BusinessManager::requestAddFriend);
            });
        }
        //更新游标为最后一条账号（供下次加载更多）
        m_lastaccount=friendlist.last().account;
    }
    //加载完成，复位标志
    m_isloadmore=false;
    //再次搜索前先清空原本的内容
    ui->grouplist->clear();
    //无搜索信息换背景
    if(grouplist.isEmpty())
    {
        group_backgroundflag=NOTRESULT;
        EmptyTipWidget::SetEmptyTip(ui->grouplist,":/new/prefix1/picture/notresult.png","暂无搜索结果");
    }
    else
    {
        group_backgroundflag=HAVINGRESULT;
        EmptyTipWidget::SetEmptyTip(ui->userlist,"","");
        //添加信息到群聊列表里面
        for(auto row:grouplist)
        {
            //再次搜索前先清空原本的内容
            ui->grouplist->clear();
            //设置条目信息
            QString iteminfo=QString("%1(%2)").arg(row.name).arg(row.account);
            //创建条目和条目窗口
            ItemWidget*itemwidget=new ItemWidget(iteminfo,ui->grouplist);
            QListWidgetItem*item=new QListWidgetItem;
            //将条目设置到userlist内
            ui->grouplist->addItem(item);
            //设置条目大小0代表自动铺满x轴
            item->setSizeHint(itemwidget->sizeHint());
            //给条目设置一个内嵌widget
            ui->grouplist->setItemWidget(item,itemwidget);
            //群聊id
            qint64 groupid=row.id;

        }
    }
}
//请求成功
void AddFriend::requestSuccess()
{
    HoverTip::showTip(this,"发送成功");
}
//请求失败
void AddFriend::requestFailed()
{
    HoverTip::showTip(this,"请求超时,请稍后重试······");
}
//禁止添加自己
void AddFriend::NotAddOneself()
{
    HoverTip::showTip(this,"不允许添加自己");
}
//全屏
void AddFriend::FullScreen()
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
//全屏按钮
void AddFriend::on_max_clicked()
{
    FullScreen();
}


//搜索按钮
void AddFriend::on_search_clicked()
{
    if(!ui->searchedit->text().isEmpty())
    {
        //首次搜索：清空游标和加载更多标志
        m_curkeyword=ui->searchedit->text();
        m_lastaccount="";
        m_isloadmore=false;
        //发送要搜索的信息
        emit search(m_curkeyword,m_lastaccount);
    }
    //未输入搜索文本
    else
    {
        user_backgroundflag=NOTKEYBG;
        group_backgroundflag=NOTKEYBG;
        EmptyTipWidget::SetEmptyTip(ui->userlist,":/new/prefix1/picture/notkeyword.png","输入关键词搜素");
        EmptyTipWidget::SetEmptyTip(ui->grouplist,":/new/prefix1/picture/notkeyword.png","输入关键词搜素");
    }
}
