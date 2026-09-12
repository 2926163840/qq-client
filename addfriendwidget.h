#ifndef ADDFRIENDWIDGET_H
#define ADDFRIENDWIDGET_H

#include <QWidget>
#include<QMouseEvent>
#include<QJsonObject>

#include"hovertip.h"
namespace Ui {
class AddFriendWidget;
}

class AddFriendWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AddFriendWidget(int id,QString info,QString message="",QWidget *parent = nullptr);
    ~AddFriendWidget();

private slots:
    void on_send_clicked();

signals:
    //传递添加好友数据       userid是成员不引用
    void requestAddFriend(const qint64 userid,const QString&verificationmes,const QString&remark,const QString&identity);

private:
    // 鼠标按下、移动、松开
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    //初始化分组
    void GroupInit();

private:
    Ui::AddFriendWidget *ui;
    // 拖拽偏移量
    QPoint m_windowDragStartPos;
    //对应用户id
    qint64 userid;
    // 标记是否正在拖拽窗口
    bool m_isWindowDragging = false;
};

#endif // ADDFRIENDWIDGET_H
