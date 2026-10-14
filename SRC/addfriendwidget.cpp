#include "addfriendwidget.h"
#include "ui_addfriendwidget.h"



AddFriendWidget::AddFriendWidget(int id,QString info,QString message,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddFriendWidget)
{
    ui->setupUi(this);
    // 去掉标原生题栏
    setWindowFlags(Qt::FramelessWindowHint|Qt::NoDropShadowWindowHint|Qt::WindowMinimizeButtonHint);
    //设置用户信息
    ui->userinfo->setText(info);
    ui->message->setText(message);
    userid=id;
    //初始化分组
    GroupInit();
}

AddFriendWidget::~AddFriendWidget()
{
    delete ui;
}



//按下获取坐标
void AddFriendWidget::mousePressEvent(QMouseEvent *event)
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
void AddFriendWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(m_isWindowDragging && event->buttons() & Qt::LeftButton)
    {
        this->move(event->globalPosition().toPoint() - m_windowDragStartPos);
        event->accept();
    }
    QWidget::mouseMoveEvent(event);
}
//松手取消
void AddFriendWidget::mouseReleaseEvent(QMouseEvent *event)
{
    m_isWindowDragging = false;
    QWidget::mouseReleaseEvent(event);
}
//初始化分组
void AddFriendWidget::GroupInit()
{
    ui->groupcombobox->addItem("我的好友");
    ui->groupcombobox->addItem("朋友");
    ui->groupcombobox->addItem("同学");
    ui->groupcombobox->addItem("家人");
}
//发送按钮
void AddFriendWidget::on_send_clicked()
{
    if(ui->verificationedit->toPlainText().isEmpty())
    {
        HoverTip::showTip(this,"请输入验证信息");
        return;
    }
    QString remark;
    //备注
    remark=ui->remarkedit->text();
    QString curname=remark.isEmpty()?"无":remark;
    //上传数据
    emit requestAddFriend(userid,ui->verificationedit->toPlainText(),curname,ui->groupcombobox->currentText());
    close();
}

