#include "itemwidget.h"
#include "ui_itemwidget.h"

ItemWidget::ItemWidget(QString info,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ItemWidget)
{
    ui->setupUi(this);
    ui->info->setText(info);
}

ItemWidget::~ItemWidget()
{
    delete ui;
}

void ItemWidget::setMessage(const QString&message)
{
    ui->message->setText(message);
}

void ItemWidget::enterEvent(QEnterEvent *event)
{
    ishover=true;
    setBG();
    QWidget::enterEvent(event);
}

void ItemWidget::leaveEvent(QEvent *event)
{
    ishover=false;
    setBG();
    QWidget::leaveEvent(event);
}

void ItemWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        ispressed=true;
        //独占鼠标事件(接收按压鼠标期间出窗口后的relase的事件)
        this->grabMouse();
        setBG();
    }
    QWidget::mousePressEvent(event);
}

void ItemWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        ispressed=false;
        //释放鼠标事件
        this->releaseMouse();
        setBG();
    }
    QWidget::mouseReleaseEvent(event);
}
//添加按钮
void ItemWidget::on_add_clicked()
{
    emit addClicked();
}

void ItemWidget::setBG()
{
    //切换背景颜色（按压优先级大于悬浮）
    //按压换颜色
    if(ispressed)
    {
        ui->widget->setStyleSheet("#widget{background-color:#D7D7D7} #widget_2{background-color:#D7D7D7}");
    }
    else if(ishover)
    {
        ui->widget->setStyleSheet("#widget{background-color:#EBEBEB} #widget_2{background-color:#EBEBEB}");
    }
    else
    {
        ui->widget->setStyleSheet("#widget{background-color:#FFFFFF} #widget_2{background-color:#FFFFFF}");
    }
}

