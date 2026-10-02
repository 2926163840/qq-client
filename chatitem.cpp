#include "chatitem.h"
#include "ui_chatitem.h"

ChatItem::ChatItem(IdentityInfo identityinfo,QString friendname,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChatItem)
{
    ui->setupUi(this);
    this->identityinfo=identityinfo;
    ui->objectname->setText(friendname);
    //未读提示控件
    unreadBadge = new QLabel(this);
    //垂直居中
    unreadBadge->setAlignment(Qt::AlignCenter);
    unreadBadge->setStyleSheet("background:#FA5151;color:#FFFFFF;"
                               "border-radius:9px;font-size:10px;font-weight:bold;");
    unreadBadge->setFixedHeight(18);
    unreadBadge->setMinimumWidth(18);
    unreadBadge->hide();
    unreadBadge->setText("0");
    //置顶
    unreadBadge->raise();
}

ChatItem::~ChatItem()
{
    delete ui;
}

void ChatItem::setSelected(bool checked)
{
    selected=checked;
    SelectedBackGround();

}
//添加未读数
void ChatItem::addUnreadCount()
{
    int unreadcount=unreadBadge->text().toInt()+1;
    if(unreadcount>99)
    {
        unreadcount=99;
        unreadBadge->setText("99+");
    }
    else unreadBadge->setText(QString::number(unreadcount));
    unreadBadge->show();
}
//双击窗口发出信号和身份标识创建聊天窗口
void ChatItem::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        //传递数据
        emit DoubleClicked(identityinfo);
        //消化掉信号
        event->accept();
        return;
    }
}
//单击窗口发出信号改变颜色
void ChatItem::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        emit Clicked(identityinfo.convid);
        //改变背景颜色
        setStyleSheet("#Textwidget{background-color:#D7D7D7}");
        if(selected)
        {
            selected=false;
        }
        else
        {
            selected=true;
        }
        //清空未读数隐藏未读提示
        unreadBadge->hide();
        unreadBadge->setText("0");
    }
    QWidget::mousePressEvent(event);
}
//松开鼠标
void ChatItem::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        SelectedBackGround();
    }
    QWidget::mouseReleaseEvent(event);
}
//鼠标进入改变颜色
void ChatItem::enterEvent(QEnterEvent *event)
{
    hover=true;
    //不是选中庄涛才改变
    if(!selected)
    {
        setStyleSheet("#Textwidget{background-color:#EBEBEB}");
    }
    QWidget::enterEvent(event);
}
//鼠标离开
void ChatItem::leaveEvent(QEvent *event)
{
    hover=false;
    //不是选中状态回退悬浮前的颜色
    if(!selected)
    {
        setStyleSheet("#Textwidget{background-color:#F5F5F5}");
    }
    QWidget::leaveEvent(event);

}
//同步未读提示的位置
void ChatItem::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    int x=(this->width()-unreadBadge->width())-20;
    int y=this->y()+(this->height()-unreadBadge->height())/2;
    unreadBadge->move(x,y);
    unreadBadge->raise();
}
//根据选中状态改变背景色

void ChatItem::SelectedBackGround()
{
    //根据选中状态改变背景颜色
    if(selected)
    {
        setStyleSheet("#Textwidget{background-color:#E2E2E2}");
    }
    else
    {
        //取消选中但还是悬浮状态
        if(hover)
        {
            setStyleSheet("#Textwidget{background-color:#EBEBEB}");
        }
        else
            setStyleSheet("#Textwidget{background-color:#F5F5F5}");
    }
}
