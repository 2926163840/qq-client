#ifndef MAINWINDOW_H
#define MAINWINDOW_H



#include <QMainWindow>

#include<QTcpSocket>
#include <QMessageBox>
#include <QPainter>
#include <QPainterPath>
#include <QPixmap>
#include <QToolTip>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QDateTime>
#include<QMap>
#include<QCoreApplication>
#include<QSqlError>

#include"networkmanager.h"
#include"businessmanager.h"
#include"registeruser.h"
#include"log.h"
#include"userwidget.h"
#include "hovertip.h"
#include"addfriend.h"


#define SERVERADDR "127.0.0.1"
#define PORT 9999

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    //注册按钮
    void on_registeruser_clicked();
    //登入按钮
    void on_login_clicked();
    //关闭按钮
    void on_close_clicked();

signals:
    //ui界面渲染完成
    void uiSuccess();
    //传递登入信息
    void sendLoginInfo(const QString&account,const QString&pwd,bool auto_login,bool rem_pwd,qint64 logintime);
    //传递用户界面给主函数
    void sendUserWidget(UserWidget*);
    //退出界面信号
    void quitInterface();
    //登入成功
    // void loginSuccess(UserWidget*);

private:
    void connectserver();                  //连接服务器
    void paintQQ();                        //画QQ图标
    void handleCmd();                       //读取数据
    void comboboxInit();                   //设置accountedit属性
    void userLoginSuccess(const QString&account,const QString&name);     //成功登入
    // 鼠标按下、移动、松开
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    Ui::MainWindow *ui;
    // 拖拽偏移量
    QPoint m_windowDragStartPos;
    // 标记是否正在拖拽窗口
    bool m_isWindowDragging = false;
    //业务管理对象
    BusinessManager*busmana=BusinessManager::getBusMana();
};
#endif // MAINWINDOW_H
