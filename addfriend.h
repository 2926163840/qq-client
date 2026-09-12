#ifndef ADDFRIEND_H
#define ADDFRIEND_H

#include <QWidget>
#include<QMouseEvent>
#include<QJsonObject>
#include<QJsonArray>
#include<QListWidget>
#include<QTimer>

#include"businessmanager.h"
#include"hovertip.h"
#include"itemwidget.h"
#include"addfriendwidget.h"
#include"UserData.h"
#include"emptytipwidget.h"

#define NOTKEYBG     10000
#define NOTRESULT    10001
#define HAVINGRESULT 10002

namespace Ui {
class AddFriend;
}

class AddFriend : public QWidget
{
    Q_OBJECT

public:
    explicit AddFriend(QWidget *parent = nullptr);
    ~AddFriend();
    //搜索失败
    void SearchFailed();
    //搜索成功
    void SearchSuccess(const QList<SearchInfo>&friendlist,const QList<SearchInfo>&grouplist);
    //推进成功
    void requestSuccess();
    //请求添加好友数据发送失败
    void requestFailed();
    //禁止添加自己
    void NotAddOneself();

private slots:
    //最大化按钮
    void on_max_clicked();
    //搜索按钮
    void on_search_clicked();
private:
    //窗口全屏
    void FullScreen();
    // 鼠标按下、移动、松开
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    // 双击事件
    void mouseDoubleClickEvent(QMouseEvent *event) override;
signals:
    void search(const QString&partaccount);

private:
    Ui::AddFriend *ui;
    //业务管理单例
    BusinessManager*busmana=BusinessManager::getBusMana();
    //全屏前窗口尺寸
    QByteArray previousscreen;
    //窗口是否为最大尺寸
    bool isMax=false;
    // 拖拽偏移量
    QPoint m_windowDragStartPos;
    // 标记是否正在拖拽窗口
    bool m_isWindowDragging = false;
    //背景标志位
    int user_backgroundflag=NOTKEYBG;
    int group_backgroundflag=NOTKEYBG;
};

#endif // ADDFRIEND_H
