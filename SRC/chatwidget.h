#pragma once

#ifndef CHATWIDGET_H
#define CHATWIDGET_H

#include <QWidget>
#include<QMouseEvent>
#include<QTimer>
#include<QShortcut>
#include<QHash>

#include"UserData.h"
#include"chatfeature.h"
#include"privatefeature.h"
#include"groupfeature.h"
#include"chatbubble.h"

namespace Ui {
class ChatWidget;
}

class ChatWidget : public QWidget
{
    Q_OBJECT

public:
    ~ChatWidget();
    //工厂创建不同的窗口特性类
    static ChatWidget* createChatWidget(const IdentityInfo&widgetidentity,const QString &friendname);
    //安装控件接口
    void AddControl_Top(QWidget*children);
    void AddControl_Right(QWidget*children);
    //获取关联会话id
    qint64 getConvid();
    //设置窗口独立标志位
    void setIndepend(bool flag);
    //获取独立窗口标志位
    bool getIndepend();
    //是否展示标题栏
    void setTitlebarStatus(bool flag);
    //获取独立前坐标
    QPoint getbefore();
    //添加消息（拉新）
    void addMessage(const bool isself,const QString&nickname,const QString&mescontent);
    //添加消息（拉旧）
    void insertMessage(const bool isself,const QString&nickname,const QString&mescontent);
    //添加发送中的气泡(转圈圈)
    void appendSendingBubble(const QString&uuid,const QString&content);
    //更新气泡状态(转圈圈/感叹号/正常)
    void updateBubbleStatus(const QString&uuid,qint8 status);
private slots:
    void on_max_clicked();

    void on_sendmesedit_textChanged();

    void on_sendbtn_clicked();

private:
    explicit ChatWidget(qint64 convid,const QString &friendname,std::unique_ptr<ChatFeature>feature,QWidget *parent = nullptr);
    //窗口全屏
    void FullScreen();
    // 鼠标按下、移动、松开
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    // 双击事件
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    //关闭事件
    void closeEvent(QCloseEvent *event) override;
    //画logo
    void PaintLogo();

signals:
    //独立信号
    void draging(ChatWidget*chatwidget);
    //附着信号
    void draged(ChatWidget*chatwidget);
    //关闭独立窗口
    void closeSelf(const qint64 convid);
    //发送消息
    void sendMes(const qint64 convid,const QString&content,const QString&uuid);
    //滚动到顶部请求拉取更早的消息
    void loadOlder(const qint64 convid);

private:
    Ui::ChatWidget *ui;
    //窗口是否为最大尺寸
    bool isMax=false;
    // 拖拽偏移量
    QPoint m_windowDragStartPos;
    //点击时的全局坐标
    QPoint m_pressGlobalPos;
    // 标记是否正在拖拽窗口
    bool m_isWindowDragging = false;
    //记录当前窗口信息
    QByteArray previousscreen;
    //窗口特性
    std::unique_ptr<ChatFeature> widgetfeature;
    //关联的会话id
    qint64 convid;
    //uuid到发送中气泡的映射
    QHash<QString,ChatBubble*>sendingbubblehash;
    //是否是独立聊天窗口
    bool isIndependent=false;
    //是否首次移动
    bool m_draged=false;
    //是否脱离中
    bool m_detaching=false;
    //独立前左上角坐标
    QPoint beforetopleft;
};

#endif // CHATWIDGET_H
