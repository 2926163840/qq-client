/********************************************************************************
** Form generated from reading UI file 'userwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERWIDGET_H
#define UI_USERWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "resizeitemlistwidget.h"

QT_BEGIN_NAMESPACE

class Ui_UserWidget
{
public:
    QVBoxLayout *verticalLayout_17;
    QFrame *titlebar;
    QHBoxLayout *horizontalLayout;
    QLabel *logo;
    QLabel *logoname;
    QSpacerItem *horizontalSpacer_8;
    QLabel *usericon;
    QSpacerItem *horizontalSpacer_9;
    QLabel *username;
    QSpacerItem *horizontalSpacer;
    QPushButton *min;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *max;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *close;
    QSpacerItem *horizontalSpacer_6;
    QFrame *frame_2;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_6;
    QWidget *qqwidget;
    QHBoxLayout *horizontalLayout_4;
    QWidget *selectwidget;
    QPushButton *messagepattern;
    QPushButton *friendpattern;
    QPushButton *noticepattern;
    QFrame *frame;
    QStackedWidget *patternstacked;
    QWidget *friendpatternpage;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_6;
    QWidget *widget_5;
    QPushButton *more_2;
    QFrame *frame_8;
    QWidget *switchbtn;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *userfriend;
    QPushButton *usergroup;
    QStackedWidget *friendandgroupstacked;
    QWidget *page;
    QVBoxLayout *verticalLayout;
    QTreeWidget *grouplist;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_2;
    QTreeWidget *friendlist;
    QFrame *frame_3;
    QWidget *messagepatternpage;
    QHBoxLayout *horizontalLayout_5;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_7;
    QWidget *widget_4;
    QPushButton *more;
    QFrame *frame_10;
    QListWidget *messagelist;
    QFrame *frame_6;
    QWidget *noticepatternpage;
    QVBoxLayout *verticalLayout_19;
    QWidget *noticepatternwidget;
    QVBoxLayout *verticalLayout_21;
    QPushButton *friendnotice;
    QPushButton *groupnotice;
    QSpacerItem *verticalSpacer;
    QStackedWidget *chatwidget;
    QWidget *userchatpage;
    QVBoxLayout *verticalLayout_3;
    QFrame *userchatwidget;
    QVBoxLayout *verticalLayout_5;
    QWidget *usermessagewidget;
    QVBoxLayout *verticalLayout_8;
    QListWidget *userchatlist;
    QWidget *sendusermessagwidget;
    QVBoxLayout *verticalLayout_4;
    QFrame *frame_4;
    QTextEdit *sendusermessageedit;
    QWidget *backgroundpage;
    QVBoxLayout *verticalLayout_16;
    QFrame *backgroundwidget;
    QVBoxLayout *verticalLayout_13;
    QWidget *friendnoticepage;
    QVBoxLayout *verticalLayout_18;
    QWidget *friendnoticepagewidget;
    QVBoxLayout *verticalLayout_22;
    QWidget *friendnotcelistwidget;
    QVBoxLayout *verticalLayout_20;
    QWidget *friendnoticepattern;
    QHBoxLayout *horizontalLayout_7;
    QLabel *friendnoticepatternlabel;
    QSpacerItem *horizontalSpacer_3;
    ResizeItemListWidget *friendnoticelist;
    QWidget *groupnoticepage;
    QVBoxLayout *verticalLayout_25;
    QWidget *groupnoticepagewidget;
    QVBoxLayout *verticalLayout_23;
    QWidget *groupnotcelistwidget;
    QVBoxLayout *verticalLayout_24;
    QWidget *groupnoticepattern;
    QHBoxLayout *horizontalLayout_8;
    QLabel *groupnoticepatternlabel;
    QSpacerItem *horizontalSpacer_4;
    ResizeItemListWidget *groupnoticelist;

    void setupUi(QWidget *UserWidget)
    {
        if (UserWidget->objectName().isEmpty())
            UserWidget->setObjectName("UserWidget");
        UserWidget->resize(950, 650);
        UserWidget->setMinimumSize(QSize(950, 650));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/picture/QQICON.png"), QSize(), QIcon::Normal, QIcon::Off);
        UserWidget->setWindowIcon(icon);
        UserWidget->setStyleSheet(QString::fromUtf8("#username{\n"
"	color:#000000;\n"
"}\n"
"#backgroundwidget{\n"
"	background-color:#F5F5F5;\n"
"}\n"
"#friendnoticepattern{\n"
"	background-color:#F5F5F5;\n"
"}\n"
"#groupnoticepattern{\n"
"	background-color:#F5F5F5;\n"
"}\n"
"#friendnoticepatternlabel{\n"
"	width:30px;\n"
"	color:black;\n"
"}\n"
"#groupnoticepatternlabel{\n"
"	width:30px;\n"
"	color:black;\n"
"}\n"
"#friendnoticelist{\n"
"	background-color:#F5F5F5;\n"
"	border:1px solid #E0E0E0\n"
"}\n"
"#groupnoticelist{\n"
"	background-color:#F5F5F5;\n"
"	border:1px solid #E0E0E0\n"
"}\n"
"#friendnotice{\n"
"	height:40px;\n"
"	background-color:#F5F5F5;\n"
"	border:none;\n"
"	border-radius:10px;\n"
"	color:black;\n"
"}\n"
"#friendnotice:hover{\n"
"	background-color:#EBEBEB;\n"
"}\n"
"#friendnotice:pressed{\n"
"	background-color:#D7D7D7;\n"
"}\n"
"#friendnotice:checked{\n"
"	background-color:#0099FF;	\n"
"	border:none;\n"
"}\n"
"#groupnotice{\n"
"	height:40px;\n"
"	background-color:#F5F5F5;\n"
"	border:none;\n"
"	border-radius:10px;\n"
"	color:black;\n"
"}\n"
""
                        "#groupnotice:hover{\n"
"	background-color:#EBEBEB;\n"
"}\n"
"#groupnotice:pressed{\n"
"	background-color:#D7D7D7;\n"
"}\n"
"#groupnotice:checked{\n"
"	background-color:#0099FF;	\n"
"	border:none;\n"
"}\n"
"#feiendnoticepagewidget{\n"
"	background-color:#F5F5F5;\n"
"}\n"
"#noticepatternwidget{\n"
"	background-color:#F5F5F5;\n"
"}\n"
"\n"
"#groupchatlist{\n"
"	background-color:#F5F5F5;\n"
"	border:none;\n"
"}\n"
"#sendgroupmessageedit{\n"
"	background-color:#F5F5F5;\n"
"	border:none;\n"
"}\n"
"#userchatlist{\n"
"	background-color:#F5F5F5;\n"
"	border:none;\n"
"}\n"
"#widget_4{\n"
"	background-color:#F5F5F5;\n"
"}\n"
"#widget_5{\n"
"	background-color:#F5F5F5;\n"
"}\n"
"#more_2{\n"
"	background-color:#EBEBEB;\n"
"	border:none;\n"
"	border-radius:15px;\n"
"}\n"
"#more_2:hover{\n"
"	background-color:#E2E2E2;\n"
"	border:none;\n"
"}\n"
"#more_2:pressed{\n"
"	background-color:#CECECE;	\n"
"	border:none;\n"
"}\n"
"#more{\n"
"	background-color:#EBEBEB;\n"
"	border:none;\n"
"	border-radius:15px;\n"
"}\n"
"#more:hover{\n"
""
                        "	background-color:#E2E2E2;\n"
"	border:none;\n"
"}\n"
"#more:pressed{\n"
"	background-color:#CECECE;	\n"
"	border:none;\n"
"}\n"
"#messagelist{\n"
"	border:none;\n"
"}\n"
"#titlebar{\n"
"	background-color:#F1F1F1;\n"
"}\n"
"#messagepattern{\n"
"	background-color:#F5F5F5;\n"
"	border:none;\n"
"}\n"
"#messagepattern:hover{\n"
"	background-color:#EBEBEB;\n"
"	border:none;\n"
"}\n"
"#messagepattern:pressed{\n"
"	background-color:#E7E7E7;	\n"
"	border:none;\n"
"}\n"
"#messagepattern:checked{\n"
"	background-color:#0099FF;	\n"
"	border:none;\n"
"}\n"
"#friendpattern{\n"
"	background-color:#F5F5F5;\n"
"	border:none;\n"
"}\n"
"#friendpattern:hover{\n"
"	background-color:#EBEBEB;\n"
"	border:none;\n"
"}\n"
"#friendpattern:pressed{\n"
"	background-color:#E7E7E7;\n"
"	border:none;\n"
"}\n"
"#friendpattern:checked{\n"
"	background-color:#0099FF;	\n"
"	border:none;\n"
"}\n"
"#noticepattern{\n"
"	background-color:#F5F5F5;\n"
"	border:none;\n"
"}\n"
"#noticepattern:hover{\n"
"	background-color:#EBEBEB;\n"
"	border:none;\n"
""
                        "}\n"
"#noticepattern:pressed{\n"
"	background-color:#E7E7E7;\n"
"	border:none;\n"
"}\n"
"#noticepattern:checked{\n"
"	background-color:#0099FF;	\n"
"	border:none;\n"
"}\n"
"#selectwidget{\n"
"	background-color:#F5F5F5;\n"
"}\n"
"#min{\n"
"	border:none;\n"
"}\n"
"#min:hover{\n"
"	background-color:#E8E8E8;\n"
"}\n"
"#min:pressed{\n"
"	background-color:#D4D4D4;\n"
"}\n"
"#max{\n"
"	border:none;\n"
"}\n"
"#max:hover{\n"
"	background-color:#E8E8E8;\n"
"}\n"
"#max:pressed{\n"
"	background-color:#D4D4D4;\n"
"}\n"
"#close{\n"
"	border:none;\n"
"}\n"
"#close:hover{\n"
"	background-color:#E8E8E8;\n"
"}\n"
"#close:pressed{\n"
"	background-color:#D4D4D4;\n"
"}\n"
"#messagelist{\n"
"	background-color:#F5F5F5\n"
"}\n"
"#messagewidget{\n"
"	background-color:#F5F5F5\n"
"}\n"
"#sendusermessageedit{\n"
"	background-color:#F5F5F5\n"
"}\n"
"#messagewidget_2{\n"
"	background-color:#F5F5F5\n"
"}\n"
"#sendmessageedit_2{\n"
"	background-color:#F5F5F5\n"
"}\n"
"#friendlist{\n"
"	background-color:#F5F5F5\n"
"}\n"
"#selectframe{\n"
"	ba"
                        "ckground-color:#F5F5F5\n"
"}\n"
"#grouplist{\n"
"	background-color:#F5F5F5\n"
"}\n"
"#switchbtn{\n"
"	background-color:#F5F5F5\n"
"}\n"
"QPushButton#userfriend{\n"
"    color: #333333;\n"
"    border: none;\n"
"    background-color: #EBEBEB;\n"
"    padding: 6px 12px;\n"
"    font-size:12px;\n"
"}\n"
"QPushButton#userfriend:checked{\n"
"    color: #0C9EFF;\n"
"    border: 1px solid #0066ff;\n"
"    border-radius:3px;\n"
"}\n"
"QPushButton#userfriend:hover:!checked{\n"
"    color:#AEAEAE;\n"
"}\n"
"QPushButton#usergroup{\n"
"    color: #333333;\n"
"    border: none;\n"
"    background-color: #EBEBEB;\n"
"    padding: 6px 12px;\n"
"    font-size:12px;\n"
"}\n"
"QPushButton#usergroup:checked{\n"
"    color: #0C9EFF;\n"
"    border: 1px solid #0066ff;\n"
"    border-radius:3px;\n"
"}\n"
"QPushButton#usergroup:hover:!checked{\n"
"    color:#AEAEAE;\n"
"}\n"
"#switchbtn{\n"
"	background-color:#F5F5F5;\n"
"}\n"
"\n"
"\n"
"QTreeWidget {\n"
"	 show-decoration-selected: 1;\n"
"     background-color: #F5F5F5;\n"
"     bo"
                        "rder: none;\n"
"     outline: none;\n"
"}\n"
"/*\345\216\273\346\273\232\345\212\250\346\235\241\350\276\271\350\247\222*/\n"
"QTreeWidget::corner {\n"
"    background: transparent;\n"
"    width:0px;\n"
"}\n"
"/* ==========\345\210\206\347\273\204\357\274\210\347\210\266\350\212\202\347\202\271\357\274\232\346\210\221\347\232\204\345\245\275\345\217\213\343\200\201\347\211\271\345\210\253\345\205\263\345\277\203\357\274\211\344\273\273\344\275\225\347\212\266\346\200\201\351\203\275\344\270\215\345\217\230\350\211\262========== */\n"
"QTreeWidget::item:has-children {\n"
"    background-color: #F5F5F5;\n"
"    color: #333333;\n"
"    height:34px;\n"
"    padding-left:0px;\n"
"}\n"
"QTreeWidget::item:has-children:hover {\n"
"    background-color: #F5F5F5;\n"
"}\n"
"QTreeWidget::item:has-children:selected {\n"
"    background-color: #F5F5F5;\n"
"    color: #333333;\n"
"}\n"
"\n"
"/* ==========\345\245\275\345\217\213\345\255\220\346\235\241\347\233\256========== */\n"
"QTreeWidget::item:!has-children {\n"
"    b"
                        "ackground-color: #F5F5F5;\n"
"    color:#222222;\n"
"    height:36px;\n"
"    padding-left:0px;\n"
"}\n"
"QTreeWidget::item:!has-children:hover {\n"
"    background:transparent ;\n"
"}\n"
"QTreeWidget::item:!has-children:selected {\n"
"    background:transparents ;\n"
"    color:#222222;\n"
"}\n"
"\n"
"/* \346\273\232\345\212\250\346\235\241 */\n"
"QScrollBar:vertical {\n"
"    width:8px;\n"
"    background:transparent;\n"
"}\n"
"QScrollBar::handle:vertical {\n"
"    background-color: #cccccc;\n"
"    border-radius:4px;\n"
"}\n"
"QScrollBar::handle:vertical:hover {\n"
"    background-color:#aaaaaa;\n"
"}\n"
"QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical {\n"
"    width:0px;\n"
"    height:0px;\n"
"}\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {\n"
"    background: transparent;\n"
"}\n"
"\n"
"QTreeWidget::item\n"
"{\n"
"    border-bottom:1px solid #E8E8E8; /*\345\210\206\345\211\262\347\272\277\351\242\234\350\211\262*/\n"
"}\n"
"/* \345\216\273\346\216\211\346\234\200\345\220"
                        "\216\344\270\200\346\235\241item\345\244\232\344\275\231\345\272\225\347\272\277\357\274\210\345\217\257\351\200\211\344\274\230\345\214\226\357\274\211 */\n"
"QTreeWidget::item:last-child\n"
"{\n"
"    border-bottom:none;\n"
"}\n"
"QTextEdit {\n"
"    selection-background-color: transparent;\n"
"    selection-color: #000000;\n"
"    border: 1px solid #E0E0E0;\n"
"}\n"
"QTextEdit:focus {\n"
"    border: 1px solid #E0E0E0;\n"
"}"));
        verticalLayout_17 = new QVBoxLayout(UserWidget);
        verticalLayout_17->setSpacing(0);
        verticalLayout_17->setObjectName("verticalLayout_17");
        verticalLayout_17->setContentsMargins(0, 0, 0, 0);
        titlebar = new QFrame(UserWidget);
        titlebar->setObjectName("titlebar");
        titlebar->setMinimumSize(QSize(0, 40));
        titlebar->setMaximumSize(QSize(16777215, 40));
        titlebar->setFrameShape(QFrame::StyledPanel);
        titlebar->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(titlebar);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        logo = new QLabel(titlebar);
        logo->setObjectName("logo");

        horizontalLayout->addWidget(logo);

        logoname = new QLabel(titlebar);
        logoname->setObjectName("logoname");

        horizontalLayout->addWidget(logoname);

        horizontalSpacer_8 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        usericon = new QLabel(titlebar);
        usericon->setObjectName("usericon");

        horizontalLayout->addWidget(usericon);

        horizontalSpacer_9 = new QSpacerItem(10, 5, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_9);

        username = new QLabel(titlebar);
        username->setObjectName("username");

        horizontalLayout->addWidget(username);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        min = new QPushButton(titlebar);
        min->setObjectName("min");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/picture/min.png"), QSize(), QIcon::Normal, QIcon::Off);
        min->setIcon(icon1);
        min->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(min);

        horizontalSpacer_2 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        max = new QPushButton(titlebar);
        max->setObjectName("max");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/picture/max.png"), QSize(), QIcon::Normal, QIcon::Off);
        max->setIcon(icon2);
        max->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(max);

        horizontalSpacer_5 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        close = new QPushButton(titlebar);
        close->setObjectName("close");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/picture/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        close->setIcon(icon3);
        close->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(close);

        horizontalSpacer_6 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);


        verticalLayout_17->addWidget(titlebar);

        frame_2 = new QFrame(UserWidget);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::HLine);
        frame_2->setFrameShadow(QFrame::Raised);

        verticalLayout_17->addWidget(frame_2);

        widget_6 = new QWidget(UserWidget);
        widget_6->setObjectName("widget_6");
        horizontalLayout_6 = new QHBoxLayout(widget_6);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        qqwidget = new QWidget(widget_6);
        qqwidget->setObjectName("qqwidget");
        horizontalLayout_4 = new QHBoxLayout(qqwidget);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        selectwidget = new QWidget(qqwidget);
        selectwidget->setObjectName("selectwidget");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(selectwidget->sizePolicy().hasHeightForWidth());
        selectwidget->setSizePolicy(sizePolicy);
        selectwidget->setMinimumSize(QSize(45, 0));
        selectwidget->setMaximumSize(QSize(45, 16777215));
        messagepattern = new QPushButton(selectwidget);
        messagepattern->setObjectName("messagepattern");
        messagepattern->setGeometry(QRect(-10, 10, 61, 41));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/picture/message.png"), QSize(), QIcon::Normal, QIcon::Off);
        messagepattern->setIcon(icon4);
        messagepattern->setCheckable(true);
        friendpattern = new QPushButton(selectwidget);
        friendpattern->setObjectName("friendpattern");
        friendpattern->setGeometry(QRect(-10, 50, 61, 41));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/picture/contact.png"), QSize(), QIcon::Normal, QIcon::Off);
        friendpattern->setIcon(icon5);
        friendpattern->setCheckable(true);
        noticepattern = new QPushButton(selectwidget);
        noticepattern->setObjectName("noticepattern");
        noticepattern->setGeometry(QRect(-10, 90, 61, 41));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/picture/notice.png"), QSize(), QIcon::Normal, QIcon::Off);
        noticepattern->setIcon(icon6);
        noticepattern->setCheckable(true);

        horizontalLayout_4->addWidget(selectwidget);

        frame = new QFrame(qqwidget);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::VLine);
        frame->setFrameShadow(QFrame::Raised);

        horizontalLayout_4->addWidget(frame);

        patternstacked = new QStackedWidget(qqwidget);
        patternstacked->setObjectName("patternstacked");
        friendpatternpage = new QWidget();
        friendpatternpage->setObjectName("friendpatternpage");
        friendpatternpage->setMinimumSize(QSize(300, 0));
        friendpatternpage->setMaximumSize(QSize(300, 16777215));
        horizontalLayout_3 = new QHBoxLayout(friendpatternpage);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(friendpatternpage);
        widget_2->setObjectName("widget_2");
        verticalLayout_6 = new QVBoxLayout(widget_2);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        widget_5 = new QWidget(widget_2);
        widget_5->setObjectName("widget_5");
        widget_5->setMinimumSize(QSize(300, 40));
        widget_5->setMaximumSize(QSize(300, 40));
        more_2 = new QPushButton(widget_5);
        more_2->setObjectName("more_2");
        more_2->setGeometry(QRect(250, 10, 41, 31));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/picture/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        more_2->setIcon(icon7);

        verticalLayout_6->addWidget(widget_5);

        frame_8 = new QFrame(widget_2);
        frame_8->setObjectName("frame_8");
        frame_8->setMinimumSize(QSize(0, 1));
        frame_8->setMaximumSize(QSize(16777215, 1));
        frame_8->setFrameShape(QFrame::HLine);
        frame_8->setFrameShadow(QFrame::Raised);

        verticalLayout_6->addWidget(frame_8);

        switchbtn = new QWidget(widget_2);
        switchbtn->setObjectName("switchbtn");
        switchbtn->setMinimumSize(QSize(300, 60));
        switchbtn->setMaximumSize(QSize(300, 60));
        horizontalLayout_2 = new QHBoxLayout(switchbtn);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        userfriend = new QPushButton(switchbtn);
        userfriend->setObjectName("userfriend");

        horizontalLayout_2->addWidget(userfriend);

        usergroup = new QPushButton(switchbtn);
        usergroup->setObjectName("usergroup");

        horizontalLayout_2->addWidget(usergroup);


        verticalLayout_6->addWidget(switchbtn);

        friendandgroupstacked = new QStackedWidget(widget_2);
        friendandgroupstacked->setObjectName("friendandgroupstacked");
        page = new QWidget();
        page->setObjectName("page");
        verticalLayout = new QVBoxLayout(page);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        grouplist = new QTreeWidget(page);
        grouplist->setObjectName("grouplist");
        grouplist->setSelectionMode(QAbstractItemView::NoSelection);
        grouplist->setIndentation(15);

        verticalLayout->addWidget(grouplist);

        friendandgroupstacked->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        verticalLayout_2 = new QVBoxLayout(page_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        friendlist = new QTreeWidget(page_2);
        friendlist->setObjectName("friendlist");
        friendlist->setSelectionMode(QAbstractItemView::NoSelection);
        friendlist->setIndentation(15);

        verticalLayout_2->addWidget(friendlist);

        friendandgroupstacked->addWidget(page_2);

        verticalLayout_6->addWidget(friendandgroupstacked);

        verticalLayout_6->setStretch(3, 1);

        horizontalLayout_3->addWidget(widget_2);

        frame_3 = new QFrame(friendpatternpage);
        frame_3->setObjectName("frame_3");
        frame_3->setFrameShape(QFrame::VLine);
        frame_3->setFrameShadow(QFrame::Raised);

        horizontalLayout_3->addWidget(frame_3);

        horizontalLayout_3->setStretch(0, 10);
        horizontalLayout_3->setStretch(1, 1);
        patternstacked->addWidget(friendpatternpage);
        messagepatternpage = new QWidget();
        messagepatternpage->setObjectName("messagepatternpage");
        messagepatternpage->setMinimumSize(QSize(300, 0));
        messagepatternpage->setMaximumSize(QSize(300, 16777215));
        horizontalLayout_5 = new QHBoxLayout(messagepatternpage);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(messagepatternpage);
        widget_3->setObjectName("widget_3");
        widget_3->setMinimumSize(QSize(300, 0));
        widget_3->setMaximumSize(QSize(300, 16777215));
        verticalLayout_7 = new QVBoxLayout(widget_3);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName("widget_4");
        widget_4->setMinimumSize(QSize(300, 40));
        widget_4->setMaximumSize(QSize(300, 40));
        more = new QPushButton(widget_4);
        more->setObjectName("more");
        more->setGeometry(QRect(250, 10, 41, 31));
        more->setIcon(icon7);

        verticalLayout_7->addWidget(widget_4);

        frame_10 = new QFrame(widget_3);
        frame_10->setObjectName("frame_10");
        frame_10->setMinimumSize(QSize(0, 1));
        frame_10->setMaximumSize(QSize(16777215, 1));
        frame_10->setFrameShape(QFrame::HLine);
        frame_10->setFrameShadow(QFrame::Raised);

        verticalLayout_7->addWidget(frame_10);

        messagelist = new QListWidget(widget_3);
        messagelist->setObjectName("messagelist");
        messagelist->setSelectionMode(QAbstractItemView::SingleSelection);

        verticalLayout_7->addWidget(messagelist);

        verticalLayout_7->setStretch(2, 1);

        horizontalLayout_5->addWidget(widget_3);

        frame_6 = new QFrame(messagepatternpage);
        frame_6->setObjectName("frame_6");
        frame_6->setFrameShape(QFrame::VLine);
        frame_6->setFrameShadow(QFrame::Raised);

        horizontalLayout_5->addWidget(frame_6);

        horizontalLayout_5->setStretch(0, 10);
        horizontalLayout_5->setStretch(1, 1);
        patternstacked->addWidget(messagepatternpage);
        noticepatternpage = new QWidget();
        noticepatternpage->setObjectName("noticepatternpage");
        noticepatternpage->setMinimumSize(QSize(300, 0));
        noticepatternpage->setMaximumSize(QSize(300, 16777215));
        verticalLayout_19 = new QVBoxLayout(noticepatternpage);
        verticalLayout_19->setSpacing(0);
        verticalLayout_19->setObjectName("verticalLayout_19");
        verticalLayout_19->setContentsMargins(0, 0, 0, 0);
        noticepatternwidget = new QWidget(noticepatternpage);
        noticepatternwidget->setObjectName("noticepatternwidget");
        verticalLayout_21 = new QVBoxLayout(noticepatternwidget);
        verticalLayout_21->setSpacing(20);
        verticalLayout_21->setObjectName("verticalLayout_21");
        verticalLayout_21->setContentsMargins(0, 20, 0, 0);
        friendnotice = new QPushButton(noticepatternwidget);
        friendnotice->setObjectName("friendnotice");
        QFont font;
        font.setPointSize(12);
        friendnotice->setFont(font);
        friendnotice->setCheckable(true);

        verticalLayout_21->addWidget(friendnotice);

        groupnotice = new QPushButton(noticepatternwidget);
        groupnotice->setObjectName("groupnotice");
        groupnotice->setFont(font);
        groupnotice->setCheckable(true);

        verticalLayout_21->addWidget(groupnotice);

        verticalSpacer = new QSpacerItem(20, 502, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_21->addItem(verticalSpacer);


        verticalLayout_19->addWidget(noticepatternwidget);

        patternstacked->addWidget(noticepatternpage);

        horizontalLayout_4->addWidget(patternstacked);

        chatwidget = new QStackedWidget(qqwidget);
        chatwidget->setObjectName("chatwidget");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(chatwidget->sizePolicy().hasHeightForWidth());
        chatwidget->setSizePolicy(sizePolicy1);
        userchatpage = new QWidget();
        userchatpage->setObjectName("userchatpage");
        verticalLayout_3 = new QVBoxLayout(userchatpage);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        userchatwidget = new QFrame(userchatpage);
        userchatwidget->setObjectName("userchatwidget");
        userchatwidget->setFrameShape(QFrame::StyledPanel);
        userchatwidget->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(userchatwidget);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        usermessagewidget = new QWidget(userchatwidget);
        usermessagewidget->setObjectName("usermessagewidget");
        verticalLayout_8 = new QVBoxLayout(usermessagewidget);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        userchatlist = new QListWidget(usermessagewidget);
        userchatlist->setObjectName("userchatlist");

        verticalLayout_8->addWidget(userchatlist);


        verticalLayout_5->addWidget(usermessagewidget);

        sendusermessagwidget = new QWidget(userchatwidget);
        sendusermessagwidget->setObjectName("sendusermessagwidget");
        verticalLayout_4 = new QVBoxLayout(sendusermessagwidget);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        frame_4 = new QFrame(sendusermessagwidget);
        frame_4->setObjectName("frame_4");
        frame_4->setFrameShape(QFrame::HLine);
        frame_4->setFrameShadow(QFrame::Raised);

        verticalLayout_4->addWidget(frame_4);

        sendusermessageedit = new QTextEdit(sendusermessagwidget);
        sendusermessageedit->setObjectName("sendusermessageedit");

        verticalLayout_4->addWidget(sendusermessageedit);


        verticalLayout_5->addWidget(sendusermessagwidget);

        verticalLayout_5->setStretch(0, 2);
        verticalLayout_5->setStretch(1, 1);

        verticalLayout_3->addWidget(userchatwidget);

        chatwidget->addWidget(userchatpage);
        backgroundpage = new QWidget();
        backgroundpage->setObjectName("backgroundpage");
        verticalLayout_16 = new QVBoxLayout(backgroundpage);
        verticalLayout_16->setSpacing(0);
        verticalLayout_16->setObjectName("verticalLayout_16");
        verticalLayout_16->setContentsMargins(0, 0, 0, 0);
        backgroundwidget = new QFrame(backgroundpage);
        backgroundwidget->setObjectName("backgroundwidget");
        backgroundwidget->setFrameShape(QFrame::StyledPanel);
        backgroundwidget->setFrameShadow(QFrame::Raised);
        verticalLayout_13 = new QVBoxLayout(backgroundwidget);
        verticalLayout_13->setSpacing(0);
        verticalLayout_13->setObjectName("verticalLayout_13");
        verticalLayout_13->setContentsMargins(0, 0, 0, 0);

        verticalLayout_16->addWidget(backgroundwidget);

        chatwidget->addWidget(backgroundpage);
        friendnoticepage = new QWidget();
        friendnoticepage->setObjectName("friendnoticepage");
        verticalLayout_18 = new QVBoxLayout(friendnoticepage);
        verticalLayout_18->setSpacing(0);
        verticalLayout_18->setObjectName("verticalLayout_18");
        verticalLayout_18->setContentsMargins(0, 0, 0, 0);
        friendnoticepagewidget = new QWidget(friendnoticepage);
        friendnoticepagewidget->setObjectName("friendnoticepagewidget");
        verticalLayout_22 = new QVBoxLayout(friendnoticepagewidget);
        verticalLayout_22->setSpacing(0);
        verticalLayout_22->setObjectName("verticalLayout_22");
        verticalLayout_22->setContentsMargins(0, 0, 0, 0);
        friendnotcelistwidget = new QWidget(friendnoticepagewidget);
        friendnotcelistwidget->setObjectName("friendnotcelistwidget");
        verticalLayout_20 = new QVBoxLayout(friendnotcelistwidget);
        verticalLayout_20->setSpacing(0);
        verticalLayout_20->setObjectName("verticalLayout_20");
        verticalLayout_20->setContentsMargins(0, 0, 0, 0);
        friendnoticepattern = new QWidget(friendnotcelistwidget);
        friendnoticepattern->setObjectName("friendnoticepattern");
        friendnoticepattern->setMinimumSize(QSize(0, 40));
        friendnoticepattern->setMaximumSize(QSize(16777215, 40));
        horizontalLayout_7 = new QHBoxLayout(friendnoticepattern);
        horizontalLayout_7->setSpacing(5);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(15, 0, 0, 0);
        friendnoticepatternlabel = new QLabel(friendnoticepattern);
        friendnoticepatternlabel->setObjectName("friendnoticepatternlabel");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font1.setPointSize(12);
        font1.setBold(true);
        friendnoticepatternlabel->setFont(font1);

        horizontalLayout_7->addWidget(friendnoticepatternlabel);

        horizontalSpacer_3 = new QSpacerItem(542, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);


        verticalLayout_20->addWidget(friendnoticepattern);

        friendnoticelist = new ResizeItemListWidget(friendnotcelistwidget);
        friendnoticelist->setObjectName("friendnoticelist");

        verticalLayout_20->addWidget(friendnoticelist);

        verticalLayout_20->setStretch(0, 1);
        verticalLayout_20->setStretch(1, 15);

        verticalLayout_22->addWidget(friendnotcelistwidget);


        verticalLayout_18->addWidget(friendnoticepagewidget);

        chatwidget->addWidget(friendnoticepage);
        groupnoticepage = new QWidget();
        groupnoticepage->setObjectName("groupnoticepage");
        verticalLayout_25 = new QVBoxLayout(groupnoticepage);
        verticalLayout_25->setSpacing(0);
        verticalLayout_25->setObjectName("verticalLayout_25");
        verticalLayout_25->setContentsMargins(0, 0, 0, 0);
        groupnoticepagewidget = new QWidget(groupnoticepage);
        groupnoticepagewidget->setObjectName("groupnoticepagewidget");
        verticalLayout_23 = new QVBoxLayout(groupnoticepagewidget);
        verticalLayout_23->setSpacing(0);
        verticalLayout_23->setObjectName("verticalLayout_23");
        verticalLayout_23->setContentsMargins(0, 0, 0, 0);
        groupnotcelistwidget = new QWidget(groupnoticepagewidget);
        groupnotcelistwidget->setObjectName("groupnotcelistwidget");
        verticalLayout_24 = new QVBoxLayout(groupnotcelistwidget);
        verticalLayout_24->setSpacing(0);
        verticalLayout_24->setObjectName("verticalLayout_24");
        verticalLayout_24->setContentsMargins(0, 0, 0, 0);
        groupnoticepattern = new QWidget(groupnotcelistwidget);
        groupnoticepattern->setObjectName("groupnoticepattern");
        groupnoticepattern->setMinimumSize(QSize(0, 40));
        groupnoticepattern->setMaximumSize(QSize(16777215, 40));
        horizontalLayout_8 = new QHBoxLayout(groupnoticepattern);
        horizontalLayout_8->setSpacing(5);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_8->setContentsMargins(15, 0, 0, 0);
        groupnoticepatternlabel = new QLabel(groupnoticepattern);
        groupnoticepatternlabel->setObjectName("groupnoticepatternlabel");
        groupnoticepatternlabel->setFont(font1);

        horizontalLayout_8->addWidget(groupnoticepatternlabel);

        horizontalSpacer_4 = new QSpacerItem(542, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);


        verticalLayout_24->addWidget(groupnoticepattern);

        groupnoticelist = new ResizeItemListWidget(groupnotcelistwidget);
        groupnoticelist->setObjectName("groupnoticelist");

        verticalLayout_24->addWidget(groupnoticelist);

        verticalLayout_24->setStretch(0, 1);
        verticalLayout_24->setStretch(1, 15);

        verticalLayout_23->addWidget(groupnotcelistwidget);


        verticalLayout_25->addWidget(groupnoticepagewidget);

        chatwidget->addWidget(groupnoticepage);

        horizontalLayout_4->addWidget(chatwidget);

        horizontalLayout_4->setStretch(3, 1);

        horizontalLayout_6->addWidget(qqwidget);

        horizontalLayout_6->setStretch(0, 3);

        verticalLayout_17->addWidget(widget_6);

        verticalLayout_17->setStretch(2, 1);

        retranslateUi(UserWidget);
        QObject::connect(min, &QPushButton::clicked, UserWidget, qOverload<>(&QWidget::showMinimized));

        patternstacked->setCurrentIndex(0);
        friendandgroupstacked->setCurrentIndex(0);
        chatwidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(UserWidget);
    } // setupUi

    void retranslateUi(QWidget *UserWidget)
    {
        UserWidget->setWindowTitle(QCoreApplication::translate("UserWidget", "Form", nullptr));
        logo->setText(QString());
        logoname->setText(QCoreApplication::translate("UserWidget", "QQ", nullptr));
        usericon->setText(QCoreApplication::translate("UserWidget", "\345\244\264\345\203\217", nullptr));
        username->setText(QCoreApplication::translate("UserWidget", "\345\220\215\345\255\227", nullptr));
        min->setText(QString());
        max->setText(QString());
        close->setText(QString());
#if QT_CONFIG(tooltip)
        messagepattern->setToolTip(QCoreApplication::translate("UserWidget", "\346\266\210\346\201\257", nullptr));
#endif // QT_CONFIG(tooltip)
        messagepattern->setText(QString());
#if QT_CONFIG(tooltip)
        friendpattern->setToolTip(QCoreApplication::translate("UserWidget", "\350\201\224\347\263\273\344\272\272", nullptr));
#endif // QT_CONFIG(tooltip)
        friendpattern->setText(QString());
#if QT_CONFIG(tooltip)
        noticepattern->setToolTip(QCoreApplication::translate("UserWidget", "\351\200\232\347\237\245", nullptr));
#endif // QT_CONFIG(tooltip)
        noticepattern->setText(QString());
#if QT_CONFIG(tooltip)
        more_2->setToolTip(QCoreApplication::translate("UserWidget", "\346\233\264\345\244\232", nullptr));
#endif // QT_CONFIG(tooltip)
        more_2->setText(QString());
        userfriend->setText(QCoreApplication::translate("UserWidget", "\345\245\275\345\217\213", nullptr));
        usergroup->setText(QCoreApplication::translate("UserWidget", "\347\276\244\350\201\212", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = grouplist->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("UserWidget", "\347\276\244\350\201\212", nullptr));
        QTreeWidgetItem *___qtreewidgetitem1 = friendlist->headerItem();
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("UserWidget", "\346\210\221\347\232\204\345\245\275\345\217\213", nullptr));
#if QT_CONFIG(tooltip)
        more->setToolTip(QCoreApplication::translate("UserWidget", "\346\233\264\345\244\232", nullptr));
#endif // QT_CONFIG(tooltip)
        more->setText(QString());
        friendnotice->setText(QCoreApplication::translate("UserWidget", "\345\245\275\345\217\213\351\200\232\347\237\245", nullptr));
        groupnotice->setText(QCoreApplication::translate("UserWidget", "\347\276\244\351\200\232\347\237\245", nullptr));
        friendnoticepatternlabel->setText(QCoreApplication::translate("UserWidget", "\345\245\275\345\217\213\351\200\232\347\237\245", nullptr));
        groupnoticepatternlabel->setText(QCoreApplication::translate("UserWidget", "\347\276\244\351\200\232\347\237\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserWidget: public Ui_UserWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWIDGET_H
