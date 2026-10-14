#include "log.h"

Log::Log() {
    fileInit();
    t = std::thread(&Log::worker, this);
}
Log::~Log() {
    // 退出工作线程
    run = false;
    cv.notify_all();
    if (t.joinable())
        t.join();
    for (int i = 0; i < LogFILENUM; i++) {
        if (fds[i].isOpen())
            fds[i].close();
    }
}

void Log::operator()(int lv, int method, QString str)
{
    QDateTime now=QDateTime::currentDateTime();
    QString level=getLevel(lv);
    QString info=QString("[%1][%2][%3]:%4")
                       .arg(now.toString("yyyy-MM-dd hh-mm-ss"),level,QString::number(quintptr(QThread::currentThreadId())),str);
    {
        //入队上锁
        std::lock_guard<std::mutex>lock(cvtex);
        logque.push_back({info,lv,method});
    }
    //唤醒锁
    cv.notify_one();
}
//工作函数
void Log::worker()
{
    while(run)
    {
        std::unique_lock<std::mutex>lock(cvtex);
        cv.wait(lock,[this]{return !logque.isEmpty()||!run;});
        while(!logque.isEmpty())
        {
            struct Loginfo temp=logque.front();
            logque.pop_front();
            //写文件解锁
            lock.unlock();
            switch(temp.method)
            {
            case LogSCREEN:
                qDebug()<<temp.print;
                break;
            case LogFILE:
                fds[temp.lv].write(temp.print.toUtf8());
                break;
            }
            //循环出队重新上锁
            lock.lock();
        }
    }
}
//获取日志等级字符串
QString Log::getLevel(int lv)
{
    switch(lv)
    {
    case LogDebug:
        return "LogDebug";
    case LogInfo:
        return "LogInfo";
    case LogWarning:
        return "LogWarning";
    case LogError:
        return "LogError";
    case LogFatal:
        return "LogFatal";
    }
    return "LogNone";
}
//初始化文件
void Log::fileInit() {
    // 文件不存在创建
    if (!QFile::exists(QCoreApplication::applicationDirPath() + "/fd")) {
        QDir().mkpath(QCoreApplication::applicationDirPath() + "/fd");
    }
    QString path = QCoreApplication::applicationDirPath() + "/fd/";
    // 设置文件路径 追加只读打开文件
    for (int i = 0; i < LogFILENUM; i++) {
        fds[i].setFileName(path + fdnames[i] + ".log");
        fds[i].open(QIODeviceBase::WriteOnly | QIODeviceBase::Append);
    }
}
Log &lg() {
    static Log log;
    return log;
}
