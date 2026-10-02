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
#include<QListWidgetItem>
#include<QScrollBar>

#include"emptytipwidget.h"
#include"businessmanager.h"
#include"hovertip.h"
#include"addfriend.h"
#include"friendnoticeitem.h"
#include"UserData.h"
#include"chatwidget.h"
#include"chatitem.h"
#include"eventmanager.h"


//好友模式
#define FRIEND_PATTERN 0
//消息模式
#define MESSAGE_PATTERN 1
//通知模式
#define NOTICE_PATTERN 2

//聊天模式
#define CHAT_PATTERN 0
//背景模式
#define BACKGROUND_PATTERN 1
//好友通知模式
#define FRIEND_NOTICE_PATTERN 2
//群通知模式
#define GROUP_NOTICE_PATTERN 3


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
    //读命令
    void readCmd();

    //添加好友信息条目
    void addFriendItem(const IdentityInfo identityinfo,const QString&friendname,const QString&friendidentity);
    //添加群聊信息条目

    //初始化群聊列表
    void groupListInfoInit(const QHash<qint64,FriendInfo>&grouplist);
    //添加好友或群聊
    void addFriOrGro();
    //创建群聊
    void createGroup();
    //创建聊天窗口
    void createChatWidget(const IdentityInfo&identityinfo,const QString&friendname);
    //创建聊天窗口_窗口
    void createChatWidget_Widget(const IdentityInfo&identityinfo,const QString&friendname);
    //聊天窗口被拖动中
    void ChatWidget_Draging(ChatWidget*obj);
    //聊天窗口拖动完成
    void ChatWidget_Draged(ChatWidget*obj);
    //创建消息条目
    void createChatWidget_Item(const IdentityInfo&identityinfo,const QString&friendname);
    //有新窗口添加消息列表
    void addMessageList();
    //设置聊天窗口位置大小
    void toggleChatWidget(ChatWidget*chatwidget);

    //收到消息
    void recvMessage(const qint64 sendid,const QString&content);
    //有通知消息渲染通知
    void RenderFriendNotice(const std::shared_ptr<QList<DisplayNoticeInfo>>&ldpni);
    //有聊天消息渲染通知
    void RenderChatMes(const std::shared_ptr<QList<Mes>>&ldpni);
    //添加未读计数
    void addUnreadCount(const QList<qint64>&uncv);


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

    //通知模式改变
    void NoticePatternChanged(const NoticeViewType NoticePattern);


    //获取信息
    void getMes(const MesRequest type,const qint64 convid=-1);
    //窗口独立
    void haveIndependChatWidget(const qint64 convid);
    //独立窗口销毁或改变
    void removeIndependChatWidget(const qint64 convid);


    //收到消息成功
    void recvSuccess(QJsonObject);

private:
    Ui::UserWidget *ui;
    //业务管理对象
    BusinessManager*busmana=BusinessManager::getBusMana();

    //好友通知条目窗口hash
    QHash<qint64,FriendNoticeItem*> friendnoticeitemhash;

    //窗口是否为最大尺寸
    bool isMax=false;
    // 拖拽偏移量
    QPoint m_windowDragStartPos;
    // 标记是否正在拖拽窗口
    bool m_isWindowDragging = false;
    //消息列表条目
    QHash<qint64,QListWidgetItem*> messagelisthash;  //key=convid
    //存取好友列表条目
    QHash<QString,QTreeWidgetItem*> friendlisthash;  //key=好友分组
    //存取好友列表好友的聊天窗口
    QHash<qint64,ChatWidget*> chatwidgethash;   //key=convid
    //当前显示的聊天窗口
    ChatWidget*curchatwidget=nullptr;
    //存取群聊列表条目
    QHash<QString,QTreeWidgetItem*> grouplisthash;  //key=群分组
    //会话id对应的条目
    QHash<qint64,QTreeWidgetItem*> chatitemhash;   //key=convid
    //模式切换按键组
    QButtonGroup patterngroup;
    //通知切换按钮组
    QButtonGroup NoticePatternGroup;
    //好友群聊列表切换按键组
    QButtonGroup switchlistgroup;
    QAction*menuselected=nullptr;
    //记录当前窗口信息
    QByteArray previousscreen;

    //获取通知或聊天信息中
    bool get_NoticeMesing_Friend=false;
    bool get_NoticeMesing_Group=false;
    bool get_ChatMesing=false;

    //用户id(重连的时候用)
    qint64 userid;

};

#endif // USERWIDGET_H
