/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QFrame *titlebar;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QPushButton *close;
    QWidget *widget_4;
    QLabel *Icon;
    QWidget *widget_3;
    QLineEdit *password;
    QComboBox *account;
    QCheckBox *autologin;
    QCheckBox *rememberpwd;
    QWidget *widget_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *passwordlogin;
    QLabel *label;
    QPushButton *registeruser;
    QPushButton *login;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(320, 440);
        MainWindow->setMinimumSize(QSize(320, 440));
        MainWindow->setMaximumSize(QSize(320, 440));
        MainWindow->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius:8px;\n"
"}\n"
"QPushButton#passwordlogin{\n"
"	background-color:transparent;\n"
"	color:#2036ff;\n"
"}\n"
"QPushButton#registeruser{\n"
"	background-color:transparent;\n"
"	color:#2036ff;\n"
"}\n"
"QPushButton#login{\n"
"	background-color:#0099FF;\n"
"	color:#ffffff;\n"
"}\n"
"QPushButton#login:pressed{\n"
"	background-color:#0081D6;\n"
"	color:#40A1E0;\n"
"}\n"
"QLineEdit{\n"
"	border-radius:4px;\n"
"    background-color:#ffffff;\n"
"    border:1px solid #666666;\n"
"    color:black;\n"
"    font-size: 18px;\n"
"	placeholder-text-color:#999999;\n"
"	text-align:center;\n"
"\n"
"}\n"
"QLineEdit:hover{\n"
"    border:1px solid #666666;\n"
"}\n"
"QLineEdit:focus{\n"
"    border:1px solid #666666;\n"
"    outline:none; \n"
"}\n"
"/* \346\225\264\344\275\223\344\270\213\346\213\211\346\241\206\345\256\271\345\231\250 */\n"
"QComboBox\n"
"{\n"
"    border: 1px solid #666666;\n"
"    border-radius: 6px;\n"
"    font-size: 18px;\n"
"    color: balck;\n"
"    background-color: #ffffff;\n"
""
                        "	placeholder-text-color:#999999;\n"
"	padding-left:35px;\n"
"}\n"
"/* \351\274\240\346\240\207\346\202\254\346\265\256\346\240\267\345\274\217 */\n"
"QComboBox:hover\n"
"{\n"
"    border:1px solid #666666;\n"
"}\n"
"/* \347\202\271\345\207\273\350\201\232\347\204\246\346\240\267\345\274\217 */\n"
"QComboBox:focus\n"
"{\n"
"    border:1px solid #666666;\n"
"    outline:none; }\n"
"/* \344\270\213\346\213\211\347\256\255\345\244\264\346\214\211\351\222\256 */\n"
"QComboBox::drop-down\n"
"{\n"
"    border: none;\n"
"    width:36px;\n"
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
"   \n"
"	image: url(:/picture/uparrow.png);\n"
"}\n"
"\n"
"\n"
"/* \344\270\213\346\213\211\345\274\271\345\207\272\345\210\227\350\241\250 */\n"
"QComboBox QAbstractItemView\n"
"{\n"
"	border-radius:8px;\n"
"    background: transparent;\n"
"    outline: none;\n"
"	padding:0px;\n"
"}\n"
"/* \344\270\213\346\213\211\345\210\227"
                        "\350\241\250\346\235\241\347\233\256 */\n"
"QComboBox QAbstractItemView::item\n"
"{\n"
"    height: 36px;\n"
"	color:black;\n"
"	border-radius:8px;\n"
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
"QComboBox QLineEdit\n"
"{\n"
"    border:none;\n"
"    background:transparent;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        titlebar = new QFrame(centralwidget);
        titlebar->setObjectName("titlebar");
        titlebar->setFrameShape(QFrame::StyledPanel);
        titlebar->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(titlebar);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(247, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(titlebar);
        pushButton_2->setObjectName("pushButton_2");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/picture/more.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon);

        horizontalLayout_2->addWidget(pushButton_2);

        close = new QPushButton(titlebar);
        close->setObjectName("close");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/picture/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        close->setIcon(icon1);

        horizontalLayout_2->addWidget(close);

        horizontalLayout_2->setStretch(0, 8);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);

        verticalLayout_3->addWidget(titlebar);

        widget_4 = new QWidget(centralwidget);
        widget_4->setObjectName("widget_4");
        Icon = new QLabel(widget_4);
        Icon->setObjectName("Icon");
        Icon->setGeometry(QRect(110, 30, 91, 61));

        verticalLayout_3->addWidget(widget_4);

        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName("widget_3");
        password = new QLineEdit(widget_3);
        password->setObjectName("password");
        password->setGeometry(QRect(30, 70, 251, 41));
        password->setMaxLength(16);
        password->setEchoMode(QLineEdit::Password);
        password->setAlignment(Qt::AlignCenter);
        account = new QComboBox(widget_3);
        account->setObjectName("account");
        account->setGeometry(QRect(30, 20, 251, 41));
        account->setEditable(true);
        autologin = new QCheckBox(widget_3);
        autologin->setObjectName("autologin");
        autologin->setGeometry(QRect(40, 120, 91, 17));
        rememberpwd = new QCheckBox(widget_3);
        rememberpwd->setObjectName("rememberpwd");
        rememberpwd->setGeometry(QRect(210, 120, 91, 17));

        verticalLayout_3->addWidget(widget_3);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        widget = new QWidget(widget_2);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(50, 40, 201, 91));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        passwordlogin = new QPushButton(widget);
        passwordlogin->setObjectName("passwordlogin");

        horizontalLayout->addWidget(passwordlogin);

        label = new QLabel(widget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        registeruser = new QPushButton(widget);
        registeruser->setObjectName("registeruser");

        horizontalLayout->addWidget(registeruser);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 3);
        login = new QPushButton(widget_2);
        login->setObjectName("login");
        login->setGeometry(QRect(30, 0, 251, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font.setPointSize(14);
        login->setFont(font);

        verticalLayout_3->addWidget(widget_2);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 4);
        verticalLayout_3->setStretch(2, 6);
        verticalLayout_3->setStretch(3, 6);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_2->setText(QString());
        close->setText(QString());
        Icon->setText(QString());
        password->setPlaceholderText(QCoreApplication::translate("MainWindow", "\345\257\206\347\240\201", nullptr));
        account->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\264\246\345\217\267", nullptr));
        autologin->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\347\231\273\345\205\245", nullptr));
        rememberpwd->setText(QCoreApplication::translate("MainWindow", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        passwordlogin->setText(QCoreApplication::translate("MainWindow", "\345\257\206\347\240\201\347\231\273\345\205\245", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "|", nullptr));
        registeruser->setText(QCoreApplication::translate("MainWindow", "\346\263\250\345\206\214\350\264\246\345\217\267", nullptr));
        login->setText(QCoreApplication::translate("MainWindow", "\347\231\273\345\205\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
