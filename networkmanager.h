#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include<QTcpSocket>
#include<QObject>
#include<QDebug>
#include<QJsonObject>
#include<QJsonArray>
#include<QJsonDocument>

#include"log.h"

#define SERVERADDR "127.0.0.1"
#define PORT 9999

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

private:
    //读取数据
    void readJson();

signals:
    //接收数据
    void recvJson(const QJsonObject&);
private:
    //网络管理对象
    NetworkManager*netmana;
    //通信套接字
    QTcpSocket*socket=nullptr;
    //读缓存区
    QByteArray readbuf;
};

#endif // NETWORKMANAGER_H
