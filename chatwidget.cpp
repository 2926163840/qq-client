#include "chatwidget.h"
#include "ui_chatwidget.h"

ChatWidget::ChatWidget(qint64 convid,const QString &friendname,std::unique_ptr<ChatFeature> feature,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChatWidget)
{
    ui->setupUi(this);
    //窗口名字
    ui->chatname->setText(friendname);
    this->convid=convid;
    //画logo
    PaintLogo();
    //隐藏工具栏
    ui->titlebar->hide();
    //加载对应窗口特性
    feature->attach(this);
    //如果特性窗口没有子控件则隐藏
    if(ui->chatwidgettop->layout()->count()==0)
    {
        ui->chatwidgettop->hide();
    }
    if(ui->chatwidgetright->layout()->count()==0)
    {
        ui->chatwidgetright->hide();
    }
    //关闭原生状态栏
    setWindowFlags(Qt::FramelessWindowHint|Qt::NoDropShadowWindowHint|Qt::WindowMinimizeButtonHint);
    //开启关闭自销毁
    setAttribute(Qt::WA_DeleteOnClose);
}

ChatWidget::~ChatWidget()
{
    delete ui;
}
//获取聊天窗口工厂
ChatWidget*ChatWidget::createChatWidget(const IdentityInfo&widgetidentity,const QString &friendname)
{
    //好友特性
    if(widgetidentity.identity=="Friend")
    {
        std::unique_ptr<ChatFeature> feature=std::make_unique<PrivateFeature>();
        return new ChatWidget(widgetidentity.convid,friendname,std::move(feature));
    }
    //群聊特性
    std::unique_ptr<ChatFeature> feature=std::make_unique<GroupFeature>();
    return new ChatWidget(widgetidentity.convid,friendname,std::move(feature));
}
//安装特性控件
void ChatWidget::AddControl_Top(QWidget *children)
{
    ui->chatwidgettop->layout()->addWidget(children);
}
//安装右侧特性控件
void ChatWidget::AddControl_Right(QWidget *children)
{
    ui->chatwidgetright->layout()->addWidget(children);
}
//获取关联会话id
qint64 ChatWidget::getConvid()
{
    return convid;
}
//设置独立标志位
void ChatWidget::setIndepend(bool flag)
{
    isIndependent=flag;
}
//获取独立标志位
bool ChatWidget::getIndepend()
{
    return isIndependent;
}
//是否展示标题栏
void ChatWidget::setTitlebarStatus(bool flag)
{
    if(flag)ui->titlebar->show();
    else ui->titlebar->hide();
}

QPoint ChatWidget::getbefore()
{
    return beforetopleft;
}
//添加消息（适用拉新）
void ChatWidget::addMessage(const bool isself, const QString &nickname, const QString &mescontent)
{
    ChatBubble*meswidget=new ChatBubble(isself,nickname,mescontent);
    QListWidgetItem*mesitem=new QListWidgetItem;
    mesitem->setSizeHint(meswidget->sizeHint());
    ui->meslist->addItem(mesitem);
    ui->meslist->setItemWidget(mesitem,meswidget);
}
//插入以往聊天记录
void ChatWidget::insertMessage(const bool isself, const QString &nickname, const QString &mescontent)
{
    ChatBubble*meswidget=new ChatBubble(isself,nickname,mescontent);
    QListWidgetItem*mesitem=new QListWidgetItem;
    mesitem->setSizeHint(QSize(ui->meslist->viewport()->width(),ui->meslist->viewport()->height()));
    ui->meslist->insertItem(0,mesitem);
    ui->meslist->setItemWidget(mesitem,meswidget);
}
//按下获取坐标
void ChatWidget::mousePressEvent(QMouseEvent *event)
{
    // event->pos() 是窗口内部坐标，判断点击落在你的标题栏widget区域    没独立可拖动上层特性窗口
    beforetopleft=this->mapToGlobal(QPoint(0,0));
    QRect titleBarRect = ui->titlebar->geometry();
    QRect toprect=ui->chatwidgettop->geometry();
    if((event->button() == Qt::LeftButton && titleBarRect.contains(event->pos()))
        ||(!isIndependent&&toprect.contains(event->pos())&&event->button()&Qt::LeftButton))
    {
        //拖拽中
        m_isWindowDragging = true;
        //不为真拖动
        m_draged=false;
        //不处于分离中
        m_detaching=false;
        //记录按下时的坐标
        m_pressGlobalPos=event->globalPosition().toPoint();
        // 记录鼠标相对于窗口左上角的偏移
        m_windowDragStartPos = event->globalPosition().toPoint()-this->mapToGlobal(QPoint(0,0));
        event->accept();
    }

    QWidget::mousePressEvent(event);
}
//移动拖拽
void ChatWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(m_isWindowDragging && event->buttons() & Qt::LeftButton)
    {
        QPoint g=event->globalPosition().toPoint();
        if(!m_draged)
        {
            //误抖动
            if((g-m_pressGlobalPos).manhattanLength()<=QApplication::startDragDistance())
                return;
            //非抖动表示已拖动
            m_draged=true;
        }
        //窗口未独立
        if(!isIndependent)
        {
            //还在脱离中防止重复启动脱离程序
            if(m_detaching)
                return;
            //脱离中
            m_detaching=true;
            QTimer::singleShot(0,this,[this]{
                //启动脱离程序
                emit draging(this);
                m_detaching=false;
                //脱离会中断鼠标事件当鼠标还按着的时候重新捕获鼠标事件防止无脑捕获无法释放
                if(QApplication::mouseButtons()&Qt::LeftButton)
                {
                    grabMouse();
                }
                //脱离会重置坐标使窗口复原
                this->move(beforetopleft);
            });
            return;
        }
        //已经独立直接移动
        this->move(event->globalPosition().toPoint() - m_windowDragStartPos);
        event->accept();
    }
    QWidget::mouseMoveEvent(event);
}
//松手取消
void ChatWidget::mouseReleaseEvent(QMouseEvent *event)
{
    m_isWindowDragging = false;
    //释放鼠标事件
    releaseMouse();
    //拖拽了
    if(m_draged)
    {
        emit draged(this);
    }
    QWidget::mouseReleaseEvent(event);
}
//双击放大
void ChatWidget::mouseDoubleClickEvent(QMouseEvent *event)
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

void ChatWidget::closeEvent(QCloseEvent *event)
{
    emit closeSelf(convid);
    QWidget::closeEvent(event);
}
//画logo
void ChatWidget::PaintLogo()
{
    QPixmap pix(":/new/prefix1/picture/QQICON.png");
    // 缩放至40×40，保持比例 + 平滑抗锯齿
    ui->logo->setPixmap(pix.scaled(40,40,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    ui->logo->setFixedSize(40,40);
}
//全屏
void ChatWidget::FullScreen()
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
void ChatWidget::on_max_clicked()
{
    FullScreen();
}


