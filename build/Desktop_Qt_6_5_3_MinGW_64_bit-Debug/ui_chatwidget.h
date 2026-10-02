/********************************************************************************
** Form generated from reading UI file 'chatwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWIDGET_H
#define UI_CHATWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatWidget
{
public:
    QVBoxLayout *verticalLayout_3;
    QFrame *titlebar;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *min;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *max;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *close;
    QSpacerItem *horizontalSpacer_6;
    QWidget *Vchatwidget;
    QVBoxLayout *verticalLayout;
    QWidget *chatwidgettop;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QFrame *frame;
    QWidget *Hchatwidget;
    QHBoxLayout *horizontalLayout_3;
    QFrame *chatwidget;
    QVBoxLayout *verticalLayout_5;
    QWidget *meslistwidget;
    QVBoxLayout *verticalLayout_8;
    QListWidget *meslist;
    QWidget *sendmeswidget;
    QVBoxLayout *verticalLayout_4;
    QFrame *frame_4;
    QTextEdit *sendmesedit;
    QFrame *frame_2;
    QWidget *chatwidgetright;
    QVBoxLayout *verticalLayout_2;

    void setupUi(QWidget *ChatWidget)
    {
        if (ChatWidget->objectName().isEmpty())
            ChatWidget->setObjectName("ChatWidget");
        ChatWidget->resize(645, 648);
        ChatWidget->setMinimumSize(QSize(435, 435));
        ChatWidget->setStyleSheet(QString::fromUtf8("#chatwidgettop{\n"
"	background-color:#F5F5F5;\n"
"}\n"
"#chatwidgetright{\n"
"	background-color:#F5F5F5;\n"
"}\n"
"#meslist{\n"
"	background-color:#F5F5F5;\n"
"}\n"
"#sendmesedit{\n"
"	background-color:#F5F5F5;\n"
"}\n"
"#titlebar{\n"
"		background-color:#F1F1F1;\n"
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
"}"));
        verticalLayout_3 = new QVBoxLayout(ChatWidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        titlebar = new QFrame(ChatWidget);
        titlebar->setObjectName("titlebar");
        titlebar->setMinimumSize(QSize(0, 35));
        titlebar->setFrameShape(QFrame::StyledPanel);
        titlebar->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(titlebar);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(titlebar);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(16, 16));
        label_2->setMaximumSize(QSize(16, 16));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/picture/QQICON.png")));

        horizontalLayout->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        min = new QPushButton(titlebar);
        min->setObjectName("min");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/picture/min.png"), QSize(), QIcon::Normal, QIcon::Off);
        min->setIcon(icon);
        min->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(min);

        horizontalSpacer_2 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        max = new QPushButton(titlebar);
        max->setObjectName("max");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/picture/max.png"), QSize(), QIcon::Normal, QIcon::Off);
        max->setIcon(icon1);
        max->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(max);

        horizontalSpacer_5 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        close = new QPushButton(titlebar);
        close->setObjectName("close");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/picture/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        close->setIcon(icon2);
        close->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(close);

        horizontalSpacer_6 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);


        verticalLayout_3->addWidget(titlebar);

        Vchatwidget = new QWidget(ChatWidget);
        Vchatwidget->setObjectName("Vchatwidget");
        Vchatwidget->setMinimumSize(QSize(0, 0));
        Vchatwidget->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout = new QVBoxLayout(Vchatwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        chatwidgettop = new QWidget(Vchatwidget);
        chatwidgettop->setObjectName("chatwidgettop");
        chatwidgettop->setMinimumSize(QSize(0, 35));
        horizontalLayout_2 = new QHBoxLayout(chatwidgettop);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(10, 0, 10, 0);
        label = new QLabel(chatwidgettop);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("\351\273\221\344\275\223")});
        font.setPointSize(12);
        font.setBold(true);
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(chatwidgettop);

        frame = new QFrame(Vchatwidget);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::HLine);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(1);

        verticalLayout->addWidget(frame);

        Hchatwidget = new QWidget(Vchatwidget);
        Hchatwidget->setObjectName("Hchatwidget");
        horizontalLayout_3 = new QHBoxLayout(Hchatwidget);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        chatwidget = new QFrame(Hchatwidget);
        chatwidget->setObjectName("chatwidget");
        chatwidget->setFrameShape(QFrame::StyledPanel);
        chatwidget->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(chatwidget);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        meslistwidget = new QWidget(chatwidget);
        meslistwidget->setObjectName("meslistwidget");
        verticalLayout_8 = new QVBoxLayout(meslistwidget);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        meslist = new QListWidget(meslistwidget);
        meslist->setObjectName("meslist");
        meslist->setFrameShape(QFrame::NoFrame);

        verticalLayout_8->addWidget(meslist);


        verticalLayout_5->addWidget(meslistwidget);

        sendmeswidget = new QWidget(chatwidget);
        sendmeswidget->setObjectName("sendmeswidget");
        verticalLayout_4 = new QVBoxLayout(sendmeswidget);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        frame_4 = new QFrame(sendmeswidget);
        frame_4->setObjectName("frame_4");
        frame_4->setFrameShape(QFrame::HLine);
        frame_4->setFrameShadow(QFrame::Raised);

        verticalLayout_4->addWidget(frame_4);

        sendmesedit = new QTextEdit(sendmeswidget);
        sendmesedit->setObjectName("sendmesedit");
        sendmesedit->setFrameShape(QFrame::NoFrame);

        verticalLayout_4->addWidget(sendmesedit);


        verticalLayout_5->addWidget(sendmeswidget);

        verticalLayout_5->setStretch(0, 2);
        verticalLayout_5->setStretch(1, 1);

        horizontalLayout_3->addWidget(chatwidget);

        frame_2 = new QFrame(Hchatwidget);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::VLine);
        frame_2->setFrameShadow(QFrame::Raised);

        horizontalLayout_3->addWidget(frame_2);

        chatwidgetright = new QWidget(Hchatwidget);
        chatwidgetright->setObjectName("chatwidgetright");
        chatwidgetright->setMinimumSize(QSize(135, 0));
        verticalLayout_2 = new QVBoxLayout(chatwidgetright);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(10, 0, 0, 0);

        horizontalLayout_3->addWidget(chatwidgetright);


        verticalLayout->addWidget(Hchatwidget);


        verticalLayout_3->addWidget(Vchatwidget);


        retranslateUi(ChatWidget);
        QObject::connect(min, &QPushButton::clicked, ChatWidget, qOverload<>(&QWidget::showMinimized));

        QMetaObject::connectSlotsByName(ChatWidget);
    } // setupUi

    void retranslateUi(QWidget *ChatWidget)
    {
        ChatWidget->setWindowTitle(QCoreApplication::translate("ChatWidget", "Form", nullptr));
        label_2->setText(QString());
        min->setText(QString());
        max->setText(QString());
        close->setText(QString());
        label->setText(QCoreApplication::translate("ChatWidget", "objectname", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatWidget: public Ui_ChatWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWIDGET_H
