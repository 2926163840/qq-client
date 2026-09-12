#include "networkmanager.h"

NetworkManager *NetworkManager::getNetMana()
{
    static std::unique_ptr<NetworkManager>netmana=std::make_unique<NetworkManager>();
    return netmana.get();
}

NetworkManager::~NetworkManager()
{
}
//开始通信
void NetworkManager::start()
{
    //初始化socket
    socket=new QTcpSocket;
    //连接服务器
    socket->connectToHost(QHostAddress(SERVERADDR),PORT);
    connect(socket,&QTcpSocket::connected,this,[]{qDebug()<<"连接成功";});
    connect(socket,&QTcpSocket::disconnected,this,[]{qDebug()<<"服务器断开连接";});
    //读数据信号
    connect(socket,&QTcpSocket::readyRead,this,&NetworkManager::readJson);
}
//关闭套接字
void NetworkManager::stop()
{
    //关闭套接字
    if(socket)
    {
        socket->disconnect();
        socket->close();
        socket->deleteLater();
        socket=nullptr;
    }
}

//发送数据
void NetworkManager::sendJson(const QJsonObject&data)
{
    //将json数据转换成qbytearray          删除换行空格精简文本
    QByteArray senddata=QJsonDocument(data).toJson(QJsonDocument::Compact);
    //数据大小
    int size=senddata.size();
    //前四字节报头
    senddata.insert(0,(char*)&size,4);
    //发送数据
    socket->write(senddata);
    //将数据全部压入缓存区
    socket->flush();
}

NetworkManager::NetworkManager(QObject *parent)
    : QObject{parent}
{
}


//读取数据
void NetworkManager::readJson()
{
    //读取套接字缓存区全部数据
    readbuf.append(socket->readAll());
    //不足四字节报头不完整
    while(readbuf.size()>=4)
    {
        //获取报头正文数据大小
        int size=0;
        memcpy(&size,readbuf.constData(),4);
        //报头大小不对
        if(size==0||size>65536)
        {
            break;
        }
        //正文内容不足不是完整数据退出
        if(readbuf.size()<size+4)
        {
            break;
        }
        //数据完整取出数据
        QJsonObject data=QJsonDocument::fromJson(readbuf.mid(4,size)).object();
        //将完整包发给业务层处理
        recvJson(data);
        //去除已消费的数据
        readbuf.remove(0,size+4);
    }
}
