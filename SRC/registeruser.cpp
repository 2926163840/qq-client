#include "registeruser.h"
#include "ui_registeruser.h"

#include <QTimer>
#include <qmessagebox.h>

registerUser::registerUser(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::registerUser)
{
    ui->setupUi(this);
    setWindowTitle("QQ注册");
    setWindowIcon(QIcon(":/new/prefix1/picture/QQICON.png"));
    //初始化定时器
    timer=new QTimer(this);
    //用户不得自主创建账号名
    //ui->accounttip->setEnabled(false);
    //ui->registeraccount->setEnabled(false);

}

registerUser::~registerUser()
{
    delete ui;
}

//立即注册
void registerUser::on_fastregister_clicked()
{
    //获取用户名和密码
    QString username=ui->registeraccount->text();
    QString password=ui->registerPassword->text();
    //没有用户名
    if(username.isEmpty())
    {
        ui->accounttip->setText("请输入用户名");
        timer->stop();
        timer->start(5000);
        connect(timer,&QTimer::timeout,this,[this]{ui->accounttip->setText("");});
        return;
    }
    //密码不得少于8位不得多余16位
    if(password.size()<8||password.size()>16)
    {
        ui->passwordtip->setText("请输入8-16位的密码");
        timer->stop();
        timer->start(5000);
        connect(timer,&QTimer::timeout,this,[this]{ui->passwordtip->setText("");});
        return;
    }
    //将json数据上报给主窗口
    emit sendData(username,password);
    //防止多次注册关闭互动
    ui->fastregister->setEnabled(false);
}

//注册成功
void registerUser::handleSuccess()
{
    QMessageBox tip(this);
    tip.setText("注册成功");
    tip.setStandardButtons(QMessageBox::Ok);
    tip.exec();
    this->close();
}
//用户已存在
void registerUser::handleExists()
{
    QMessageBox tip(this);
    tip.setText("用户已存在");
    //设置单一按钮
    tip.setStandardButtons(QMessageBox::Ok);
    //阻塞
    tip.exec();
    ui->fastregister->setEnabled(true);
}
//注册失败
void registerUser::handleFailed()
{
    QMessageBox tip(this);
    tip.setText("注册失败请稍后重试");
    //设置单一按钮
    tip.setStandardButtons(QMessageBox::Ok);
    //阻塞
    tip.exec();
    ui->fastregister->setEnabled(true);
}

//获取用户名
void registerUser::on_getusername_clicked()
{
    //获取随机的十位数用户名
    QString username=QString::number(QRandomGenerator::global()->bounded(1000000000ULL,9999999999ULL));
    ui->registeraccount->setText(username);
}

