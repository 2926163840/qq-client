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
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *account;
    QLineEdit *password;
    QPushButton *login;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *passwordlogin;
    QLabel *label;
    QPushButton *registeruser;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(255, 352);
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
"    background-color:#ffffff;\n"
"    border:1px solid #666666;\n"
"    border-radius:2px;\n"
"    color:#ffffff;\n"
"	border-radius:4px;\n"
"}\n"
"QLineEdit:hover{\n"
"    border:1px solid #666666;\n"
"}\n"
"QLineEdit:focus{\n"
"    border:1px solid #666666;\n"
"    outline:none; \n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        account = new QLineEdit(centralwidget);
        account->setObjectName("account");
        account->setGeometry(QRect(50, 100, 141, 31));
        password = new QLineEdit(centralwidget);
        password->setObjectName("password");
        password->setGeometry(QRect(50, 140, 141, 31));
        login = new QPushButton(centralwidget);
        login->setObjectName("login");
        login->setGeometry(QRect(50, 220, 141, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font.setPointSize(14);
        login->setFont(font);
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(50, 260, 131, 30));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        passwordlogin = new QPushButton(widget);
        passwordlogin->setObjectName("passwordlogin");

        horizontalLayout->addWidget(passwordlogin);

        label = new QLabel(widget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        registeruser = new QPushButton(widget);
        registeruser->setObjectName("registeruser");

        horizontalLayout->addWidget(registeruser);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(80, 40, 71, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 255, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        login->setText(QCoreApplication::translate("MainWindow", "\347\231\273\345\205\245", nullptr));
        passwordlogin->setText(QCoreApplication::translate("MainWindow", "\345\257\206\347\240\201\347\231\273\345\205\245", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "|", nullptr));
        registeruser->setText(QCoreApplication::translate("MainWindow", "\346\263\250\345\206\214\350\264\246\345\217\267", nullptr));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
