#include "networkmanager.h"
#include<QDateTime>

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

    //心跳定时器(30秒发心跳+检测服务器掉线)
    heartbeatTimer=new QTimer(this);
    connect(heartbeatTimer,&QTimer::timeout,this,[this]{
        //检查服务器是否还活着(90秒没收到pong 判定服务器掉线)
        long long now=QDateTime::currentMSecsSinceEpoch();
        if(lastPongTime!=0&&now-lastPongTime>90000)
        {
            //服务器掉了 主动断开触发重连
            socket->abort();
            return;
        }
        //发心跳
        QJsonObject ping;
        ping["cmd"]="heartbeat";
        sendJson(ping);
    });

    //重连定时器(3秒重试一次)
    reconnectTimer=new QTimer(this);
    connect(reconnectTimer,&QTimer::timeout,this,[this]{
        socket->connectToHost(QHostAddress(SERVERADDR),PORT);
    });

    //连接服务器
    socket->connectToHost(QHostAddress(SERVERADDR),PORT);
    connect(socket,&QTcpSocket::connected,this,[this]{
        //连接成功 停重连 开心跳
        reconnectTimer->stop();
        heartbeatTimer->start(30000);
        //非首次连接 通知业务层重连成功(重新登录)
        if(!firstConnect)
            emit reconnectSuccess();
        firstConnect=false;
    });
    connect(socket,&QTcpSocket::disconnected,this,[this]{
        //断连 停心跳 开重连
        heartbeatTimer->stop();
        reconnectTimer->start(3000);
    });
    //读数据信号
    connect(socket,&QTcpSocket::readyRead,this,&NetworkManager::readJson);
}
//关闭套接字
void NetworkManager::stop()
{
    if (heartbeatTimer) { heartbeatTimer->stop(); heartbeatTimer->deleteLater(); heartbeatTimer=nullptr; }
    if (reconnectTimer) { reconnectTimer->stop(); reconnectTimer->deleteLater(); reconnectTimer=nullptr; }
    if (socket) { socket->disconnect(); socket->close(); socket->deleteLater(); socket=nullptr; }
}

//发送数据
void NetworkManager::sendJson(const QJsonObject&data)
{
    //未连接忽略
    if(socket->state()!=QTcpSocket::ConnectedState)return;
    //将json数据转换成qbytearray          删除换行空格精简文本
    QByteArray senddata=QJsonDocument(data).toJson(QJsonDocument::Compact);
    //数据大小
    int size=senddata.size();
    quint32 bigsize=qToBigEndian(size);     // 主机序 → 网络字节序
    //包太大丢弃
    if(size>=MAX_PACKET)
    {
        lg()(LogWarning,LogSCREEN,QString("发送包过大,cmd:%1 size:%2").arg(data["cmd"].toString(),QString::number(size)));
        return;
    }
    //前四字节报头
    senddata.insert(0,(char*)&bigsize,4);
    //发送数据
    socket->write(senddata);
    //将数据全部压入缓存区
    socket->flush();
}
//是否已连接
bool NetworkManager::isConnected()
{
    return socket&&socket->state()==QAbstractSocket::ConnectedState;
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
        size=qFromBigEndian(size);              // 网络字节序 → 主机序

        // 报头非法：协议错乱，无法确定边界，断开
        if(size<=0)
        {
            qDebug()<<"非法报头:"<<size<<"，断开连接";
            socket->abort();
            readbuf.clear();
            return;
        }

        // 正文没到齐：等更多数据，绝不清缓存
        if(readbuf.size() < size+4)
            break;

        // 到这里说明边界完整。如果是超大包，丢弃，继续读后续
        if(size > MAX_PACKET)
        {
            lg()(LogError,LogSCREEN,"丢弃超大包"+QString::number(size));
            readbuf.remove(0, size+4);   // 只清这一个包，不影响后续
            continue;
        }
        //数据完整取出数据
        QJsonObject data=QJsonDocument::fromJson(readbuf.mid(4,size)).object();
        //收到pong 刷新服务器活跃时间(不发给业务层)
        if(data.value("cmd").toString()=="pong")
        {
            lastPongTime=QDateTime::currentMSecsSinceEpoch();
            readbuf.remove(0,size+4);
            continue;
        }
        //将完整包发给业务层处理
        emit recvJson(data);
        //去除已消费的数据
        readbuf.remove(0,size+4);
    }
}
