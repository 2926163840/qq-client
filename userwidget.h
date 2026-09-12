#ifndef USERWIDGET_H
#define USERWIDGET_H

#include <QWidget>
#include<QTreeWidget>
#include<QAbstractItemView>
#include<QMouseEvent>
#include<QHash>
#include<QButtonGroup>
#include<QMenu>
#include <QTcpSocket>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include <QSqlDatabase>
#include<QListWidget>

#include"emptytipwidget.h"
#include"businessmanager.h"
#include"hovertip.h"
#include"addfriend.h"
#include"friendnoticeitem.h"
#include"UserData.h"

//好友模式
#define FRIEND_PATTERN 0
//消息模式
#define MESSAGE_PATTERN 1
//好友通知模式
#define FRIEND_NOTICE_PATTERN 2
//群通知模式
#define GROUP_NOTICE_PATTERN 3
//背景模式
#define BACKGROUND_PATTERN 1

//显示好友列表
#define FRIEND_LIST 1
//显示群聊列表
#define GROUP_LIST 0


namespace Ui {
class UserWidget;
}

class UserWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UserWidget(QString account,QString name,QWidget *parent = nullptr);
    ~UserWidget();

private:
    //界面功能初始化
    void widgetInit();
    //成功登入
    void loginSuccess();
    //好友列表分组初始化
    void friendListInit();
    //群聊分组初始化
    void groupListInit();
    //更多按钮初始化（创建加入好友群聊）
    void moreButtonInit();
    //窗口全屏
    void FullScreen();
    // 鼠标按下、移动、松开
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    // 双击事件
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    //读数据
    void readCmd();

    //初始化用户信息
    void UserDataInit(const QHash<qint64,UserInfo>&friendlist,const QHash<qint64,UserInfo>&grouplist);
    //初始化好友列表
    void friendListInfoInit(const QHash<qint64,UserInfo>&friendlist);
    //初始化群聊列表
    void groupListInfoInit(const QHash<qint64,UserInfo>&grouplist);
    //添加好友或群聊
    void addFriOrGro();
    //添加好友申请发送成功渲染通知
    void RenderFriendNotice(const std::shared_ptr<QList<DisplayNoticeInfo>>&ldpni);
    //创建群聊
    void createGroup();
    //收到消息
    void recvMessage(const qint64 sendid,const QString&content);

private slots:
    //最大化按钮
    void on_max_clicked();
    //关闭按钮
    void on_close_clicked();

signals:
    //退出界面信号
    void quitInterface();
    //请求获取好友群聊数据
    void requestData();
    //获取数据失败
    void getUserDataFailed();
    //获取数据成功
    void getUserDataSuccess();
    //通知模式改变
    void NoticePatternChanged(const NoticeViewType NoticePattern);

    //收到消息成功
    void recvSuccess(QJsonObject);

private:
    Ui::UserWidget *ui;
    //业务管理对象
    BusinessManager*busmana=BusinessManager::getBusMana();

    //窗口是否为最大尺寸
    bool isMax=false;
    // 拖拽偏移量
    QPoint m_windowDragStartPos;
    // 标记是否正在拖拽窗口
    bool m_isWindowDragging = false;
    //存取好友列表条目便于修改数据
    QHash<QString,QTreeWidgetItem*> friendlisthash;
    //存取群聊列表条目
    QHash<QString,QTreeWidgetItem*> grouplisthash;
    //模式切换按键组
    QButtonGroup patterngroup;
    //通知切换按钮组
    QButtonGroup NoticePatternGroup;
    //好友群聊列表切换按键组
    QButtonGroup switchlistgroup;
    QAction*menuselected=nullptr;
    //记录当前窗口信息
    QByteArray previousscreen;

    //用户id(重连的时候用)
    qint64 userid;
    //好友通知条目窗口hash
    QHash<qint64,FriendNoticeItem*> friendnoticeitemhash;

};

#endif // USERWIDGET_H
