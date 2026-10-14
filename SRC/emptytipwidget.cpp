#include "emptytipwidget.h"
#include "ui_emptytipwidget.h"

EmptyTipWidget::EmptyTipWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EmptyTipWidget)
{
    ui->setupUi(this);
}

EmptyTipWidget::~EmptyTipWidget()
{
    delete ui;
}

//渲染空背景
void EmptyTipWidget::SetEmptyTip(QWidget *parentWidget, QString res, QString tip_str)
{
    if (!parentWidget)return;

    QWidget* emptyWidget = parentWidget->findChild<QWidget*>("empty_tip_widget");

    // 控件不存在创建
    if (!emptyWidget)
    {
        //背景窗口控件
        emptyWidget = new QWidget(parentWidget);
        emptyWidget->setObjectName("empty_tip_widget");
        emptyWidget->setAttribute(Qt::WA_TransparentForMouseEvents);

        //图标控件
        QLabel* iconLabel = new QLabel(emptyWidget);
        iconLabel->setObjectName("tip_icon");
        iconLabel->setScaledContents(true);
        iconLabel->setFixedSize(120, 120);
        //不截取鼠标事件
        iconLabel->setAttribute(Qt::WA_TransparentForMouseEvents);

        //文字控件
        QLabel* textLabel = new QLabel(emptyWidget);
        textLabel->setObjectName("tip_text");
        textLabel->setAlignment(Qt::AlignCenter);
        textLabel->setFixedHeight(32);

        //设置文字大小
        QFont font=textLabel->font();
        font.setPointSize(14);
        textLabel->setFont(font);
        //不截取鼠标事件
        textLabel->setAttribute(Qt::WA_TransparentForMouseEvents);
        //居中布局
        QVBoxLayout*layout=new QVBoxLayout(emptyWidget);
        layout->setContentsMargins(0,0,0,0);
        layout->addStretch();
        //水平居中不拉伸
        layout->addWidget(iconLabel,0,Qt::AlignHCenter);
        layout->addSpacing(20);
        layout->addWidget(textLabel,0,Qt::AlignHCenter);
        layout->addStretch();

        //给父对象加载事件过滤器
        EventManager* evemana=EventManager::instance();
        evemana->watch(parentWidget);
        //加载事件处理函数
        evemana->registerHandler(parentWidget,[emptyWidget](QObject*target,QEvent*event)->bool{
            //背景页尺寸变化重新加载背景图的尺寸
            if(event->type()==QEvent::Resize)
            {
                emptyWidget->setGeometry(static_cast<QWidget*>(target)->rect());
                //不消费事件
                return false;
            }
            return false;
        });
    }


    //获取内部标签
    QLabel* iconLabel = emptyWidget->findChild<QLabel*>("tip_icon");
    QLabel* textLabel = emptyWidget->findChild<QLabel*>("tip_text");
    if (!iconLabel || !textLabel)
        return;

    //加载图片和文字
    iconLabel->setPixmap(QPixmap(res));
    textLabel->setText(tip_str);
    // // 摆放坐标
    // const int iconSize = 120;
    // const int gap = 20; // 图标底部到文字固定20px
    // int w = parentWidget->width();
    // int h = parentWidget->height();
    // //居中摆放
    // int iconX = (w - iconSize) / 2;
    // //图片+文字总高度
    // int iconY = (h - (iconSize + gap + 32)) / 2;
    // iconLabel->setGeometry(iconX, iconY, iconSize, iconSize);

    // int textY = iconY + iconSize + gap;
    // textLabel->setGeometry(0, textY, w, 32);

    emptyWidget->setGeometry(parentWidget->rect());
    emptyWidget->show();
}

void EmptyTipWidget::SetEmptyTip(QListWidget *parentWidget, QString res, QString tip_str)
{
    if (!parentWidget)return;

    QWidget* emptyWidget = parentWidget->findChild<QWidget*>("empty_tip_widget");

    // 控件不存在创建
    if (!emptyWidget)
    {
        emptyWidget = new QWidget(parentWidget);
        emptyWidget->setObjectName("empty_tip_widget");
        emptyWidget->setAttribute(Qt::WA_TransparentForMouseEvents);

        QLabel* iconLabel = new QLabel(emptyWidget);
        iconLabel->setObjectName("tip_icon");
        iconLabel->setScaledContents(true);
        iconLabel->setFixedSize(120, 120);
        //不截取鼠标事件
        iconLabel->setAttribute(Qt::WA_TransparentForMouseEvents);

        QLabel* textLabel = new QLabel(emptyWidget);
        textLabel->setObjectName("tip_text");
        textLabel->setAlignment(Qt::AlignCenter);
        textLabel->setFixedHeight(32);
        //设置文字大小
        QFont font=textLabel->font();
        font.setPointSize(14);
        textLabel->setFont(font);
        //不截取鼠标事件
        textLabel->setAttribute(Qt::WA_TransparentForMouseEvents);
        //居中布局
        QVBoxLayout*layout=new QVBoxLayout(emptyWidget);
        layout->setContentsMargins(0,0,0,0);
        layout->addStretch();
        //水平居中不拉伸
        layout->addWidget(iconLabel,0,Qt::AlignHCenter);
        layout->addSpacing(20);
        layout->addWidget(textLabel,0,Qt::AlignHCenter);
        layout->addStretch();

        //给父对象加载事件过滤器
        EventManager* evemana=EventManager::instance();
        evemana->watch(parentWidget);
        //加载事件处理函数
        evemana->registerHandler(parentWidget,[emptyWidget](QObject*target,QEvent*event)->bool{
            //背景页尺寸变化重新加载背景图的尺寸
            if(event->type()==QEvent::Resize)
            {
                QListWidget*temp=static_cast<QListWidget*>(target);
                emptyWidget->setGeometry(temp->rect());
                //不消费事件
                return false;
            }
            return false;
        });
        //数据变化动态显示隐藏背景
        connect(parentWidget->model(),&QAbstractItemModel::rowsInserted,emptyWidget,[emptyWidget,parentWidget]{
            if(parentWidget->count()==0)
                emptyWidget->show();
            else
                emptyWidget->hide();
        });
        connect(parentWidget->model(),&QAbstractItemModel::rowsRemoved,emptyWidget,[emptyWidget,parentWidget]{
            if(parentWidget->count()==0)
                emptyWidget->show();
            else
                emptyWidget->hide();
        });
    }

    //获取内部标签
    QLabel* iconLabel = emptyWidget->findChild<QLabel*>("tip_icon");
    QLabel* textLabel = emptyWidget->findChild<QLabel*>("tip_text");
    if (!iconLabel || !textLabel)
        return;

    //加载图片和文字
    iconLabel->setPixmap(QPixmap(res));
    textLabel->setText(tip_str);

    emptyWidget->setGeometry(parentWidget->rect());
    emptyWidget->show();
}

