#ifndef REGISTERUSER_H
#define REGISTERUSER_H

#include <QDialog>
#include<QRandomGenerator>

namespace Ui {
class registerUser;
}

class registerUser : public QDialog
{
    Q_OBJECT

public:
    explicit registerUser(QWidget *parent = nullptr);
    ~registerUser();
    void handleSuccess();//注册成功
    void handleExists();//用户已存在
    void handleFailed();//注册失败



private slots:
    void on_getusername_clicked();;//获取用户名

    void on_fastregister_clicked();//马上注册

signals:
    void sendData(const QString&username,const QString&pwd);//上报json数据给主窗口

private:

private:
    Ui::registerUser *ui;
    QTimer*timer;//密码错误提示定时器
};

#endif // REGISTERUSER_H
