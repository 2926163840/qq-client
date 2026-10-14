#ifndef ITEMWIDGET_H
#define ITEMWIDGET_H

#include <QWidget>
#include<QMessageBox>
#include<QMouseEvent>

namespace Ui {
class ItemWidget;
}

class ItemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ItemWidget(QString info,QWidget *parent = nullptr);
    ~ItemWidget();
    //设置信息
    void setMessage(const QString&mes);

protected:
    //鼠标进入事件
    void enterEvent(QEnterEvent *event);
    //鼠标离开事件
    void leaveEvent(QEvent *event);
    //鼠标按压事件
    void mousePressEvent(QMouseEvent *event);
    //鼠标松开事件
    void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void on_add_clicked();
    //设置背景
    void setBG();

signals:
    //添加按钮被点击
    void addClicked();
private:
    Ui::ItemWidget *ui;
    //按压标志
    bool ispressed=false;
    //悬浮标志
    bool ishover=false;
};

#endif // ITEMWIDGET_H
