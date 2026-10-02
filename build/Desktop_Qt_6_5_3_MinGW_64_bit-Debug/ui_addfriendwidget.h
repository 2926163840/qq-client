/********************************************************************************
** Form generated from reading UI file 'addfriendwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFRIENDWIDGET_H
#define UI_ADDFRIENDWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddFriendWidget
{
public:
    QVBoxLayout *verticalLayout_5;
    QFrame *titlebar;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QLabel *applyadd;
    QSpacerItem *horizontalSpacer;
    QPushButton *close;
    QFrame *frame_2;
    QWidget *userinfowidget;
    QVBoxLayout *verticalLayout;
    QLabel *userinfo;
    QLabel *message;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_6;
    QWidget *verificationwidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *verification;
    QTextEdit *verificationedit;
    QWidget *remarkwidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *remark;
    QLineEdit *remarkedit;
    QWidget *groupwidget;
    QVBoxLayout *verticalLayout_4;
    QLabel *group;
    QComboBox *groupcombobox;
    QFrame *dataidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *send;
    QPushButton *quit;

    void setupUi(QWidget *AddFriendWidget)
    {
        if (AddFriendWidget->objectName().isEmpty())
            AddFriendWidget->setObjectName("AddFriendWidget");
        AddFriendWidget->resize(320, 485);
        AddFriendWidget->setMinimumSize(QSize(320, 485));
        AddFriendWidget->setMaximumSize(QSize(320, 440));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/picture/QQICON.png"), QSize(), QIcon::Normal, QIcon::Off);
        AddFriendWidget->setWindowIcon(icon);
        AddFriendWidget->setStyleSheet(QString::fromUtf8("#quit{\n"
"	border:1px solid #e0e0e0;\n"
"	border-radius:8px;\n"
"	background-color:#F5F5F5;\n"
"	color:black;\n"
"	height:30px;\n"
"}\n"
"#send{\n"
"	border-radius:8px;\n"
"	background-color:#0099FF;\n"
"	color:#ffffff;\n"
"	height:30px;\n"
"\n"
"}\n"
"#frame_2{\n"
"	color:#e0e0e0;\n"
"}\n"
"#scrollAreaWidgetContents{\n"
"	background-color:#F5F5F5;\n"
"}\n"
"#scrollArea{\n"
"	background:transparent;\n"
"	border:none;\n"
"}\n"
"#message{\n"
"	color:#A0A0A0;\n"
"}\n"
"#group{\n"
"	color:#A0A0A0;\n"
"}\n"
"#verification{\n"
"	color:#A0A0A0;\n"
"}\n"
"#remark{\n"
"	color:#A0A0A0;\n"
"}\n"
"#verificationedit{\n"
"	background-color:#FFFFFF;\n"
"	border-radius:3px;\n"
"}\n"
"/* \346\225\264\344\275\223\344\270\213\346\213\211\346\241\206\345\256\271\345\231\250 */\n"
"QComboBox\n"
"{\n"
"    border:none;\n"
"    border-radius: 3px;\n"
"    background-color: #ffffff;\n"
"	placeholder-text-color:#999999;\n"
"	height:30px;\n"
"}\n"
"/* \344\270\213\346\213\211\347\256\255\345\244\264\346\214\211\351\222\256 */\n"
"QCom"
                        "boBox::drop-down\n"
"{\n"
"    border: none;\n"
"    width:30px;\n"
"}\n"
"\n"
"QComboBox::down-arrow\n"
"{\n"
"	image: url(:/picture/downarrow.png);\n"
"	width:12px;\n"
"	height:12px;\n"
"}\n"
"QComboBox::down-arrow:on\n"
"{\n"
"	image: url(:/picture/uparrow.png);\n"
"}\n"
"\n"
"\n"
"/* \344\270\213\346\213\211\345\274\271\345\207\272\345\210\227\350\241\250 */\n"
"QComboBox QAbstractItemView\n"
"{\n"
"	border-radius:6px;\n"
"    background: transparent;\n"
"    outline: none;\n"
"	padding:0px;\n"
"}\n"
"/* \344\270\213\346\213\211\345\210\227\350\241\250\346\235\241\347\233\256 */\n"
"QComboBox QAbstractItemView::item\n"
"{\n"
"    height: 30px;\n"
"	color:black;\n"
"	border-radius:6px;\n"
"	margin:2px;\n"
"}\n"
"QComboBox QAbstractItemView::item:hover\n"
"{\n"
"    background-color: #F5F5F5;\n"
"}\n"
"QComboBox QAbstractItemView::item:selected\n"
"{\n"
"    background-color: #E0E0E0;\n"
"}\n"
"\n"
"\n"
"/* \345\217\257\347\274\226\350\276\221\346\250\241\345\274\217\345\206\205\347\275\256LineEdit */\n"
"QC"
                        "omboBox QLineEdit\n"
"{\n"
"    border:none;\n"
"    background:transparent;\n"
"}\n"
"#remarkedit{\n"
"	background-color:#FFFFFF;\n"
"	height:30px;\n"
"	border-radius:3px;\n"
"\n"
"}\n"
"#AddFriendWidget{\n"
"	background-color:#F5F5F5;\n"
"}\n"
"#close{\n"
"	background:transparent;\n"
"}\n"
"#close:hover{\n"
"	background-color:#C42B1C;\n"
"}"));
        verticalLayout_5 = new QVBoxLayout(AddFriendWidget);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(10, 0, 10, 0);
        titlebar = new QFrame(AddFriendWidget);
        titlebar->setObjectName("titlebar");
        titlebar->setFrameShape(QFrame::StyledPanel);
        titlebar->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(titlebar);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        applyadd = new QLabel(titlebar);
        applyadd->setObjectName("applyadd");

        horizontalLayout->addWidget(applyadd);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        close = new QPushButton(titlebar);
        close->setObjectName("close");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/picture/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        close->setIcon(icon1);

        horizontalLayout->addWidget(close);


        verticalLayout_5->addWidget(titlebar);

        frame_2 = new QFrame(AddFriendWidget);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::HLine);
        frame_2->setFrameShadow(QFrame::Plain);
        frame_2->setLineWidth(1);

        verticalLayout_5->addWidget(frame_2);

        userinfowidget = new QWidget(AddFriendWidget);
        userinfowidget->setObjectName("userinfowidget");
        verticalLayout = new QVBoxLayout(userinfowidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 10, 0, 0);
        userinfo = new QLabel(userinfowidget);
        userinfo->setObjectName("userinfo");
        QFont font;
        font.setPointSize(12);
        userinfo->setFont(font);

        verticalLayout->addWidget(userinfo);

        message = new QLabel(userinfowidget);
        message->setObjectName("message");

        verticalLayout->addWidget(message);


        verticalLayout_5->addWidget(userinfowidget);

        scrollArea = new QScrollArea(AddFriendWidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 300, 317));
        verticalLayout_6 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_6->setSpacing(5);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        verificationwidget = new QWidget(scrollAreaWidgetContents);
        verificationwidget->setObjectName("verificationwidget");
        verticalLayout_3 = new QVBoxLayout(verificationwidget);
        verticalLayout_3->setSpacing(5);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verification = new QLabel(verificationwidget);
        verification->setObjectName("verification");

        verticalLayout_3->addWidget(verification);

        verificationedit = new QTextEdit(verificationwidget);
        verificationedit->setObjectName("verificationedit");

        verticalLayout_3->addWidget(verificationedit);


        verticalLayout_6->addWidget(verificationwidget);

        remarkwidget = new QWidget(scrollAreaWidgetContents);
        remarkwidget->setObjectName("remarkwidget");
        verticalLayout_2 = new QVBoxLayout(remarkwidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        remark = new QLabel(remarkwidget);
        remark->setObjectName("remark");

        verticalLayout_2->addWidget(remark);

        remarkedit = new QLineEdit(remarkwidget);
        remarkedit->setObjectName("remarkedit");

        verticalLayout_2->addWidget(remarkedit);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 3);

        verticalLayout_6->addWidget(remarkwidget);

        groupwidget = new QWidget(scrollAreaWidgetContents);
        groupwidget->setObjectName("groupwidget");
        verticalLayout_4 = new QVBoxLayout(groupwidget);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        group = new QLabel(groupwidget);
        group->setObjectName("group");

        verticalLayout_4->addWidget(group);

        groupcombobox = new QComboBox(groupwidget);
        groupcombobox->setObjectName("groupcombobox");

        verticalLayout_4->addWidget(groupcombobox);

        verticalLayout_4->setStretch(0, 1);
        verticalLayout_4->setStretch(1, 2);

        verticalLayout_6->addWidget(groupwidget);

        verticalLayout_6->setStretch(0, 2);
        verticalLayout_6->setStretch(1, 1);
        verticalLayout_6->setStretch(2, 1);
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_5->addWidget(scrollArea);

        dataidget = new QFrame(AddFriendWidget);
        dataidget->setObjectName("dataidget");
        dataidget->setFrameShape(QFrame::StyledPanel);
        dataidget->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(dataidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        send = new QPushButton(dataidget);
        send->setObjectName("send");

        horizontalLayout_2->addWidget(send);

        quit = new QPushButton(dataidget);
        quit->setObjectName("quit");

        horizontalLayout_2->addWidget(quit);

        horizontalLayout_2->setStretch(0, 2);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);

        verticalLayout_5->addWidget(dataidget);

        verticalLayout_5->setStretch(0, 4);
        verticalLayout_5->setStretch(1, 1);
        verticalLayout_5->setStretch(2, 10);
        verticalLayout_5->setStretch(3, 50);
        verticalLayout_5->setStretch(4, 12);

        retranslateUi(AddFriendWidget);
        QObject::connect(close, &QPushButton::clicked, AddFriendWidget, qOverload<>(&QWidget::close));
        QObject::connect(quit, &QPushButton::clicked, AddFriendWidget, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(AddFriendWidget);
    } // setupUi

    void retranslateUi(QWidget *AddFriendWidget)
    {
        AddFriendWidget->setWindowTitle(QCoreApplication::translate("AddFriendWidget", "Form", nullptr));
        applyadd->setText(QCoreApplication::translate("AddFriendWidget", "\347\224\263\350\257\267\345\212\240\345\245\275\345\217\213", nullptr));
        close->setText(QString());
        userinfo->setText(QCoreApplication::translate("AddFriendWidget", "info", nullptr));
        message->setText(QCoreApplication::translate("AddFriendWidget", "message", nullptr));
        verification->setText(QCoreApplication::translate("AddFriendWidget", "\351\252\214\350\257\201\344\277\241\346\201\257", nullptr));
        remark->setText(QCoreApplication::translate("AddFriendWidget", "\345\244\207\346\263\250", nullptr));
        remarkedit->setPlaceholderText(QCoreApplication::translate("AddFriendWidget", "\346\227\240", nullptr));
        group->setText(QCoreApplication::translate("AddFriendWidget", "\345\210\206\347\273\204", nullptr));
        send->setText(QCoreApplication::translate("AddFriendWidget", "\345\217\221\351\200\201", nullptr));
        quit->setText(QCoreApplication::translate("AddFriendWidget", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddFriendWidget: public Ui_AddFriendWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFRIENDWIDGET_H
