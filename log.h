#pragma once
#ifndef LOG_H
#define LOG_H

#include <QObject>
#include <QDateTime>
#include<QThread>
#include<QQueue>
#include<QFile>
#include <QCoreApplication>
#include <QDir>

#define LogDebug   10000
#define LogInfo    10001
#define LogWarning 10002
#define LogError   10003
#define LogFatal   10004

#define LogSCREEN 0
#define LogFILE   1

#define LogFILENUM 4

struct Loginfo{
    QString print;
    int lv;
    int method;
};

class Log
{
public:
    Log();
    ~Log();
    void operator()(int lv,int method,QString str);

private:
    //工作函数
    void worker();
    //获取等级字符串
    QString getLevel(int lv);
    //初始化文件
    void fileInit();

    QQueue<Loginfo> logque; //日志队列
    std::mutex cvtex;       //锁
    std::condition_variable cv;//条件变量
    bool run=true;
    QFile fds[4];               //文件数组
    QString fdnames[5]={"debug","info","warning","error","Fatal"};
    std::thread t;
};
//全局共享静态对象
Log &lg();

#endif // LOG_H
