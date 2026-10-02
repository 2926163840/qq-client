#ifndef CHATITEM_H
#define CHATITEM_H

#include <QWidget>
#include<QMouseEvent>
#include<QLabel>

#include"UserData.h"

namespace Ui {
class ChatItem;
}

class ChatItem : public QWidget
{
    Q_OBJECT

public:
    explicit ChatItem(IdentityInfo identityinfo,QString friendname,QWidget *parent = nullptr);
    ~ChatItem();
    void setSelected(bool checked);
    //添加未读数
    void addUnreadCount();

private:
    //双击条目事件
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    //单击条目事件
    void mousePressEvent(QMouseEvent *event) override;
    //松开鼠标
    void mouseReleaseEvent(QMouseEvent *event) override;
    //鼠标进入
    void enterEvent(QEnterEvent *event) override;
    //鼠标离开
    void leaveEvent(QEvent *event) override;
    //尺寸改变未读提示的位置也改变
    void resizeEvent(QResizeEvent*event) override;
    //根据选中状态改变背景色
    void SelectedBackGround();

signals:
    //双击条目信号
    void DoubleClicked(IdentityInfo identityinfo);
    //单击条目信号
    void Clicked(qint64 convid);
private:
    Ui::ChatItem *ui;
    //未读提示符
    QLabel *unreadBadge = nullptr;    //条目身份信息
    IdentityInfo identityinfo;
    //选中标识符
    bool selected=false;
    //悬浮标识符
    bool hover=false;
};

#endif // CHATITEM_H
