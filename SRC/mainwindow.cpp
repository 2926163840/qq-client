#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QSqlDatabase>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //关掉原生标题栏                         关闭退出事件循环               窗口可最小化
    setWindowFlags(Qt::FramelessWindowHint|Qt::NoDropShadowWindowHint|Qt::WindowMinimizeButtonHint);
    //开启关闭自销毁
    setAttribute(Qt::WA_DeleteOnClose);
    setAttribute(Qt::WA_QuitOnClose,true);
    //画qq图标
    paintQQ();
    setWindowTitle("QQ");
    setWindowIcon(QIcon(":/new/prefix1/picture/QQICON.png"));
    //combobox属性初始化
    comboboxInit();
    //初始化接收命令
    handleCmd();
    //获取历史登入账号存在accountedit中
    connect(this,&MainWindow::uiSuccess,busmana,&BusinessManager::getLoginHistory);
    connect(busmana,&BusinessManager::senduiaccount,this,[this](const QList<QString>&vaccount){
        //将数据渲染到账号edit里面
        for(const QString&account:vaccount)
        {
            ui->account->addItem(account);
        }
        //优先显示最近登入的用户信息
        ui->account->setCurrentIndex(0);
    });
    //接收用户登入信息
    connect(busmana,&BusinessManager::senduilogindata,this,[this](const QString&password,bool auto_login,bool rem_pwd){
        //输入密码（业务层判断是否记住）
        ui->password->setText(password);
        //延续上次登入的选项
        ui->autologin->setChecked(auto_login);
        ui->rememberpwd->setChecked(rem_pwd);
    });
    //ui初始化完成
    emit uiSuccess();
    //开局优先选中账号
    ui->account->setFocus();
    show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//读取数据
void MainWindow::handleCmd()
{
    //注册成功
    connect(busmana,&BusinessManager::register_sucess,this,[this](const QString&useraccount){
        //注册成功自动输入账号
        ui->account->setCurrentText(useraccount);
    });
    //注册失败

    //登入成功
    connect(busmana,&BusinessManager::login_success_data,this,[this](const QString&username){
        //用户登入成功
        userLoginSuccess(ui->account->currentText(),username);
    });
    //账号在别处登入
    connect(busmana,&BusinessManager::login_online,this,[this]{
        //账号密码可重新输入
        ui->account->setEnabled(true);
        ui->password->setEnabled(true);
        HoverTip::showTip(this,"账号已在别处登入");
    });
    //密码错误
    connect(busmana,&BusinessManager::user_worningpassword,this,[this]{
        //账号密码可重新输入
        ui->account->setEnabled(true);
        ui->password->setEnabled(true);
        HoverTip::showTip(this,"密码错误");
    });
    //账号不存在
    connect(busmana,&BusinessManager::user_accountnoexists,this,[this]{
        //账号密码可重新输入
        ui->account->setEnabled(true);
        ui->password->setEnabled(true);
        HoverTip::showTip(this,"账号不存在");
    });
}
//combobox属性
void MainWindow::comboboxInit()
{
    ui->account->lineEdit()->setAlignment(Qt::AlignHCenter);
    //设置悬浮字
    ui->account->lineEdit()->setPlaceholderText("账号");
    //限制最大长度(账号为10位数)
    ui->account->lineEdit()->setMaxLength(10);
    //根据选择用户判断是否自动输入密码
    connect(ui->account,&QComboBox::currentTextChanged,busmana,&BusinessManager::handleaAccountFocus);
}
//用户登入成功
void MainWindow::userLoginSuccess(const QString&account,const QString&name)
{
    //创建用户qq窗口
    UserWidget*userwidget=new UserWidget(account,name);
    //开启关闭自销毁
    userwidget->setAttribute(Qt::WA_DeleteOnClose);
    //数据初始化成功关闭登入界面将登入时间记录到sqllite中
    connect(busmana,&BusinessManager::getuserdata_success,this,[this,userwidget]{
        //传递用户界面给主函数(用户界面接手线程资源)
        emit sendUserWidget(userwidget);
        //传递登入信息给业务层
        connect(this,&MainWindow::sendLoginInfo,busmana,&BusinessManager::sendLoginInfo);
        QString useraccount=ui->account->currentText();
        QString userpassword=ui->password->text();
        //下次是否自动登入
        bool auto_login=ui->autologin->isChecked();
        bool rememberpwd=ui->rememberpwd->isChecked();
        //记录登入时间
        QDateTime now=QDateTime::currentDateTime();
        qint64 curtime=now.toMSecsSinceEpoch();
        //传递登入信息
        emit sendLoginInfo(useraccount,userpassword,auto_login,rememberpwd,curtime);
    });
    //数据初始化失败回退至登入界面并且关闭用户界面
    connect(busmana,&BusinessManager::getuserdata_failed,[this,userwidget]{
        this->show();
        userwidget->close();
        HoverTip::showTip(this,"请求错误请稍后重试······");
    });
    //显示用户界面
    userwidget->show();
    //登入成功先隐藏登入界面
    this->hide();
}

//按下获取坐标
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    // event->pos() 是窗口内部坐标，判断点击落在你的标题栏widget区域
    QRect titleBarRect = ui->titlebar->geometry();
    if(event->button() == Qt::LeftButton && titleBarRect.contains(event->pos()))
    {
        m_isWindowDragging = true;
        // 记录鼠标相对于窗口左上角的偏移
        m_windowDragStartPos = event->globalPosition().toPoint() - this->frameGeometry().topLeft();
        event->accept();
    }
    QWidget::mousePressEvent(event);
}

//移动拖拽
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(m_isWindowDragging && event->buttons() & Qt::LeftButton)
    {
        this->move(event->globalPosition().toPoint() - m_windowDragStartPos);
        event->accept();
    }
    QWidget::mouseMoveEvent(event);
}

//松手取消
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    m_isWindowDragging = false;
    QWidget::mouseReleaseEvent(event);
}

void MainWindow::createShortcut()
{
    //快速登入
    QShortcut*qsc_login=new QShortcut(QKeySequence(Qt::Key_Enter),this);
    connect(qsc_login,&QShortcut::activated,ui->login,&QPushButton::click);
}

//进入注册界面
void MainWindow::on_registeruser_clicked()
{
    registerUser*dialog=new registerUser;
    //登入界面整理好数据上报主线程发送数据
    connect(dialog,&registerUser::sendData,busmana,&BusinessManager::Register);
    //注册成功关闭注册窗口失败启动立即注册按钮
    connect(busmana,&BusinessManager::register_failed,dialog,&registerUser::handleFailed);
    //注册成功
    connect(busmana,&BusinessManager::register_sucess,dialog,&registerUser::handleSuccess);
    //账号已存在
    connect(busmana,&BusinessManager::useraccount_exists,dialog,&registerUser::handleExists);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    //主窗口没了注册页面也跟着消失
    connect(this,&MainWindow::quitInterface,dialog,&registerUser::close);
    dialog->show();
}
//画QQ图标
void MainWindow::paintQQ()
{
    // 固定Label尺寸
    ui->Icon->setFixedSize(90,90);
    //加背景底色调试，正常显示后可删掉
    // ui->Icon->setStyleSheet("background:#f5f5f5;");

    // 加载资源图片，修正你的资源路径
    QPixmap srcPix(":/new/prefix1/picture/QQICON.png");
    if(srcPix.isNull()){
        qDebug()<<"图标资源加载失败，请检查qrc路径";
        return;
    }

    // 创建透明画布，绘制圆形裁剪
    QPixmap circlePix(srcPix.size());
    circlePix.fill(Qt::transparent);

    QPainter *painter = new QPainter(&circlePix);
    // 开启抗锯齿，圆形边缘平滑
    painter->setRenderHint(QPainter::Antialiasing);
    QPainterPath *clipPath = new QPainterPath;
    // 椭圆裁剪：整圆
    clipPath->addEllipse(srcPix.rect());
    painter->setClipPath(*clipPath);
    painter->drawPixmap(0,0,srcPix);
    painter->end();

    //等比缩放到Label大小，平滑插值
    QPixmap finalPix = circlePix.scaled(
        ui->Icon->size(),
        Qt::KeepAspectRatio,
        Qt::SmoothTransformation
        );

    //赋值给Label、居中显示
    ui->Icon->setPixmap(finalPix);
    ui->Icon->setAlignment(Qt::AlignCenter);
    //禁止拉伸填满控件
    ui->Icon->setScaledContents(false);
}
//登入
void MainWindow::on_login_clicked()
{
    QString account=ui->account->currentText();
    QString password=ui->password->text();
    //账号不足10位错误
    if(account.size()!=10)
    {
        HoverTip::showTip(this,"请输入正确的账号");
        return;
    }
    //密码不足8位
    if(password.size()<8)
    {
        HoverTip::showTip(this,"请输入正确的密码");
        return;
    }
    //登入业务
    busmana->login(account,password);
}

//关闭按钮
void MainWindow::on_close_clicked()
{
    emit quitInterface();
}

