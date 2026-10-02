/********************************************************************************
** Form generated from reading UI file 'addfriend.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFRIEND_H
#define UI_ADDFRIEND_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddFriend
{
public:
    QVBoxLayout *verticalLayout_6;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_5;
    QFrame *titlebar;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *min;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *max;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *close;
    QSpacerItem *horizontalSpacer_6;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *searchedit;
    QPushButton *search;
    QTabWidget *tabWidget;
    QWidget *user;
    QVBoxLayout *verticalLayout_2;
    QWidget *userwidget;
    QVBoxLayout *verticalLayout;
    QListWidget *userlist;
    QWidget *group;
    QVBoxLayout *verticalLayout_3;
    QWidget *groupwidget;
    QVBoxLayout *verticalLayout_4;
    QListWidget *grouplist;

    void setupUi(QWidget *AddFriend)
    {
        if (AddFriend->objectName().isEmpty())
            AddFriend->setObjectName("AddFriend");
        AddFriend->resize(680, 700);
        AddFriend->setMinimumSize(QSize(680, 700));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/picture/QQICON.png"), QSize(), QIcon::Normal, QIcon::Off);
        AddFriend->setWindowIcon(icon);
        AddFriend->setStyleSheet(QString::fromUtf8("QListWidget{\n"
"    border:none;\n"
"}\n"
"#widget_2{\n"
"	background-color:#FFFFFF;\n"
"}\n"
"QLineEdit#searchedit {\n"
"	height:20px;\n"
"    border-radius:4px;\n"
"    background-color:#ffffff;\n"
"    border:1px solid #666666;\n"
"    color:black;\n"
"    font-size:12px;\n"
"    placeholder-text-color:#999999;\n"
"    /* \345\267\246\344\276\247\345\233\276\346\240\207 + \345\217\263\344\276\247\347\225\231\347\231\275\351\230\262\346\255\242\346\226\207\345\255\227\345\216\213\345\233\276\346\240\207 */\n"
"	background-image: url(:/picture/search.png);\n"
"    background-repeat: no-repeat;\n"
"    background-position:left center; /* \345\267\246\345\236\202\347\233\264\345\261\205\344\270\255 */\n"
"    padding-left: 16px; /* \347\273\231\345\233\276\346\240\207\350\205\276\345\207\272\345\256\275\345\272\246\357\274\214\346\225\260\345\200\274\345\244\247\344\272\216\345\233\276\346\240\207\345\256\275\345\272\246 */\n"
"}\n"
"QPushButton#search{\n"
"	border-radius:8px;\n"
"	height:30px;\n"
"	background"
                        "-color:#0099FF;\n"
"	color:#ffffff;\n"
"}\n"
"QPushButton#search:hover{\n"
"	background-color:#008DEB;\n"
"	color:#ffffff;\n"
"}\n"
"QPushButton#search:pressed{\n"
"	background-color:#0081D6;\n"
"	color:#40A1E0;\n"
"}\n"
"#min{\n"
"	border:none;\n"
"	height:20px;\n"
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
        verticalLayout_6 = new QVBoxLayout(AddFriend);
        verticalLayout_6->setSpacing(10);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(AddFriend);
        widget_2->setObjectName("widget_2");
        verticalLayout_5 = new QVBoxLayout(widget_2);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        titlebar = new QFrame(widget_2);
        titlebar->setObjectName("titlebar");
        titlebar->setMinimumSize(QSize(0, 30));
        titlebar->setMaximumSize(QSize(16777215, 30));
        titlebar->setFrameShape(QFrame::StyledPanel);
        titlebar->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(titlebar);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        label = new QLabel(titlebar);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        min = new QPushButton(titlebar);
        min->setObjectName("min");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/picture/min.png"), QSize(), QIcon::Normal, QIcon::Off);
        min->setIcon(icon1);

        horizontalLayout->addWidget(min);

        horizontalSpacer_2 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        max = new QPushButton(titlebar);
        max->setObjectName("max");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/picture/max.png"), QSize(), QIcon::Normal, QIcon::Off);
        max->setIcon(icon2);

        horizontalLayout->addWidget(max);

        horizontalSpacer_5 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        close = new QPushButton(titlebar);
        close->setObjectName("close");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/picture/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        close->setIcon(icon3);

        horizontalLayout->addWidget(close);

        horizontalSpacer_6 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);


        verticalLayout_5->addWidget(titlebar);

        widget = new QWidget(widget_2);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(0, 50));
        widget->setMaximumSize(QSize(16777215, 50));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(10, 0, 10, 0);
        searchedit = new QLineEdit(widget);
        searchedit->setObjectName("searchedit");

        horizontalLayout_2->addWidget(searchedit);

        search = new QPushButton(widget);
        search->setObjectName("search");
        search->setMinimumSize(QSize(80, 30));
        search->setMaximumSize(QSize(80, 30));

        horizontalLayout_2->addWidget(search);

        horizontalLayout_2->setStretch(0, 5);
        horizontalLayout_2->setStretch(1, 1);

        verticalLayout_5->addWidget(widget);

        verticalLayout_5->setStretch(0, 1);

        verticalLayout_6->addWidget(widget_2);

        tabWidget = new QTabWidget(AddFriend);
        tabWidget->setObjectName("tabWidget");
        user = new QWidget();
        user->setObjectName("user");
        verticalLayout_2 = new QVBoxLayout(user);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(6, 0, 6, 0);
        userwidget = new QWidget(user);
        userwidget->setObjectName("userwidget");
        verticalLayout = new QVBoxLayout(userwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        userlist = new QListWidget(userwidget);
        userlist->setObjectName("userlist");
        userlist->setSelectionMode(QAbstractItemView::NoSelection);

        verticalLayout->addWidget(userlist);


        verticalLayout_2->addWidget(userwidget);

        tabWidget->addTab(user, QString());
        group = new QWidget();
        group->setObjectName("group");
        verticalLayout_3 = new QVBoxLayout(group);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(6, 0, 6, 0);
        groupwidget = new QWidget(group);
        groupwidget->setObjectName("groupwidget");
        verticalLayout_4 = new QVBoxLayout(groupwidget);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        grouplist = new QListWidget(groupwidget);
        grouplist->setObjectName("grouplist");

        verticalLayout_4->addWidget(grouplist);


        verticalLayout_3->addWidget(groupwidget);

        tabWidget->addTab(group, QString());

        verticalLayout_6->addWidget(tabWidget);

        verticalLayout_6->setStretch(1, 1);

        retranslateUi(AddFriend);
        QObject::connect(close, &QPushButton::clicked, AddFriend, qOverload<>(&QWidget::close));
        QObject::connect(min, &QPushButton::clicked, AddFriend, qOverload<>(&QWidget::showMinimized));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(AddFriend);
    } // setupUi

    void retranslateUi(QWidget *AddFriend)
    {
        AddFriend->setWindowTitle(QCoreApplication::translate("AddFriend", "\346\220\234\347\264\242", nullptr));
        label->setText(QCoreApplication::translate("AddFriend", "\346\220\234\347\264\242", nullptr));
        min->setText(QString());
        max->setText(QString());
        close->setText(QString());
        searchedit->setPlaceholderText(QCoreApplication::translate("AddFriend", "\350\276\223\345\205\245\346\220\234\347\264\242\345\205\263\351\224\256\350\257\215", nullptr));
        search->setText(QCoreApplication::translate("AddFriend", "\346\220\234\347\264\242", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(user), QCoreApplication::translate("AddFriend", "\347\224\250\346\210\267", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(group), QCoreApplication::translate("AddFriend", "\347\276\244\350\201\212", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddFriend: public Ui_AddFriend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFRIEND_H
