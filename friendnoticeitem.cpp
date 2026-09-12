#include "friendnoticeitem.h"
#include "ui_friendnoticeitem.h"

FriendNoticeItem::FriendNoticeItem(QString requestername,QString verificationinfo,qint64 requesttime,qint64 key,NoticeMode status,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FriendNoticeItem)
{
    ui->setupUi(this);
    //请求者名字
    ui->requestername->setText(requestername);
    //请求者的验证信息
    ui->verificationinfo->setText(verificationinfo);
    //请求时间
    ui->requesttime->setText("requesttime");
    //记住用户id
    // userid=sendid;
    //记住请求信息id
    requestkey=key;
    //收到设置combobox
    setStatus(status);
}

FriendNoticeItem::~FriendNoticeItem()
{
    delete ui;
}

void FriendNoticeItem::setStatus(NoticeMode status)
{
    if(status==NoticeMode::PLEASEVERIFICATION)
    {
        ui->stackedWidget->setCurrentIndex(SELECTING);
        ui->select->addItem("同意");
        ui->select->addItem("拒绝");
    }
    //发出设置label
    else if(status==NoticeMode::PENDINGVERIFICATION)
    {
        //切换成label模式
        ui->stackedWidget->setCurrentIndex(SELECTED);
        ui->selected->setText("等待对方验证信息");
        ui->requestmethod->setText("正在验证您的邀请");
    }
    else if(status==NoticeMode::AGREED)
    {
        //切换成label模式
        ui->stackedWidget->setCurrentIndex(SELECTED);
        ui->selected->setText("已同意");
    }
    else if(status==NoticeMode::REFUSED)
    {
        //切换成label模式
        ui->stackedWidget->setCurrentIndex(SELECTED);
        ui->selected->setText("已拒绝");
    }
}

//处理添加好友请求
void FriendNoticeItem::on_select_activated(int index)
{
    emit sendJson(ui->select->itemText(index),requestkey);
}

