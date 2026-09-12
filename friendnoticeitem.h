#ifndef FRIENDNOTICEITEM_H
#define FRIENDNOTICEITEM_H

#include <QWidget>
#include<QJsonObject>
#include"UserData.h"

//stackwidget状态（发出为label，收到为combobox）
#define SELECTING 0
#define SELECTED 1

namespace Ui {
class FriendNoticeItem;
}

class FriendNoticeItem : public QWidget
{
    Q_OBJECT

public:
    explicit FriendNoticeItem(QString requestername,QString verificationinfo,qint64 requesttime,qint64 requestkey,NoticeMode status,QWidget *parent = nullptr);
    ~FriendNoticeItem();
    //设置通知状态
    void setStatus(NoticeMode status);

signals:
    //向上传递数据
    void sendJson(const QString&selected,qint64 requestkey);
    //同意
    void Agree();
    //拒绝
    void Refuse();
private slots:
    //处理好友请求
    void on_select_activated(int index);

private:
    Ui::FriendNoticeItem *ui;
    qint64 userid;
    //请求信息id
    qint64 requestkey;
};

#endif // FRIENDNOTICEITEM_H
