#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include<QTcpSocket>
#include<QObject>
#include<QDebug>
#include<QTimer>
#include<QJsonObject>
#include<QJsonArray>
#include<QJsonDocument>
#include <QtEndian>

#include"log.h"

#define SERVERADDR "127.0.0.1"
#define PORT 9999
#define MAX_PACKET 65536

class NetworkManager:public QObject
{
    Q_OBJECT
Q_SIGNALS:
public:
    NetworkManager(QObject *parent=nullptr);
    //获取网络管理对象静态实例
    static NetworkManager*getNetMana();
    //禁止拷贝
    NetworkManager(const NetworkManager&)=delete;
    NetworkManager operator=(const NetworkManager&)=delete;
    ~NetworkManager();
    //开始通信
    void start();
    //关闭线程
    void stop();
    //发送数据
    void sendJson(const QJsonObject&);
    //是否已连接
    bool isConnected();

private:
    //读取数据
    void readJson();

signals:
    //接收数据
    void recvJson(const QJsonObject&);
    //重连成功(通知业务层重新登录)
    void reconnectSuccess();
private:
    //网络管理对象
    NetworkManager*netmana;
    //通信套接字
    QTcpSocket*socket=nullptr;
    //读缓存区
    QByteArray readbuf;
    //心跳定时器
    QTimer*heartbeatTimer=nullptr;
    //重连定时器
    QTimer*reconnectTimer=nullptr;
    //是否首次连接(首次连接不触发重连登录)
    bool firstConnect=true;
    //上次收到pong的时间(检测服务器掉线用)
    long long lastPongTime=0;
};

#endif // NETWORKMANAGER_H
