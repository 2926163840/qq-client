#include "mainwindow.h"

#include <QApplication>
#include<QObject>
#include<QThread>
#include<QMetaObject>

#include"userwidget.h"
#include"networkmanager.h"
#include"dbmanager.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //注册自定义类型不然跨线程无法传递
    qRegisterMetaType<std::shared_ptr<QList<Mes>>>();
    qRegisterMetaType<std::shared_ptr<QList<Notice>>>();
    qRegisterMetaType<std::shared_ptr<QList<LoginHistory>>>();
    qRegisterMetaType<std::shared_ptr<QList<ConvSLInfo>>>();
    qRegisterMetaType<NoticeSLInfo>();
    qRegisterMetaType<std::shared_ptr<QList<SearchInfo>>>();
    qRegisterMetaType<QList<DisplayNoticeInfo>>();

    qRegisterMetaType<std::shared_ptr<QList<qint64>>>();


    //网络管理对象
    NetworkManager*netmana=NetworkManager::getNetMana();
    //创建传输数据子线程
    QThread*netthread=new QThread();
    //将网络管理对象放进子线程
    netmana->moveToThread(netthread);
    //数据库管理对象
    DBManager*dbmana=DBManager::getDBManager();
    //数据库线程
    QThread*dbthread=new QThread();
    //将数据库管理对象放到数据库线程里面
    dbmana->moveToThread(dbthread);
    //连接工作对象初始信号
    QObject::connect(netthread,&QThread::started,netmana,&NetworkManager::start);
    QObject::connect(dbthread,&QThread::started,dbmana,&DBManager::DBInit);

    MainWindow*w=new MainWindow;
    //w.show();
    //关闭登入界面的同时释放线程资源
    QObject::connect(w,&MainWindow::quitInterface,[&]{
        //先隐藏界面
        w->hide();
        netthread->quit();
        netthread->wait(3000);
        dbthread->quit();
        dbthread->wait(3000);
        //释放玩资源后再关闭界面
        w->close();
    });
    //登入成功后由用户界面接管线程生命
    QObject::connect(w,&MainWindow::sendUserWidget,[&](UserWidget*userwidget){
        UserWidget*temp=userwidget;
        QObject::connect(temp,&UserWidget::quitInterface,[&,temp]{
            temp->hide();
            //阻塞释放网络资源
            QMetaObject::invokeMethod(netmana,&NetworkManager::stop,Qt::BlockingQueuedConnection);
            netthread->quit();
            netthread->wait(3000);
            //阻塞数据库线程释放资源
            QMetaObject::invokeMethod(dbmana,&DBManager::DBClose,Qt::BlockingQueuedConnection);
            dbthread->quit();
            dbthread->wait(3000);
            temp->close();
        });
        w->close();
    });
    //开启子线程
    netthread->start();
    dbthread->start();
    int ret= a.exec();
    //事件循环结束后兜底确保线程安全退出
    netthread->quit();
    dbthread->quit();
    //还是退出失败说明有问题直接强制杀死子线程
    if(!netthread->wait(3000))
    {
        netthread->terminate();
    }
    delete netthread;
    dbthread->quit();
    //还是退出失败说明有问题直接强制杀死子线程
    if(!dbthread->wait(3000))
    {
        dbthread->terminate();
    }
    delete dbthread;
    return ret;
}
