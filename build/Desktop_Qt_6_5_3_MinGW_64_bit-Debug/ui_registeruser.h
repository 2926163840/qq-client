/********************************************************************************
** Form generated from reading UI file 'registeruser.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERUSER_H
#define UI_REGISTERUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_registerUser
{
public:
    QLineEdit *registeraccount;
    QLineEdit *registerPassword;
    QLabel *welcomqq;
    QPushButton *fastregister;
    QPushButton *getusername;
    QLabel *accounttip;
    QLabel *passwordtip;

    void setupUi(QDialog *registerUser)
    {
        if (registerUser->objectName().isEmpty())
            registerUser->setObjectName("registerUser");
        registerUser->resize(600, 600);
        registerUser->setMinimumSize(QSize(600, 600));
        registerUser->setMaximumSize(QSize(600, 600));
        QFont font;
        font.setPointSize(12);
        registerUser->setFont(font);
        registerUser->setStyleSheet(QString::fromUtf8("\n"
"QPushButton#fastregister{\n"
"	background-color:#0099FF;\n"
"	color:#ffffff;\n"
"	border-radius:8px;\n"
"}\n"
"QPushButton#fastregister:pressed{\n"
"	background-color:#0081D6;\n"
"	color:#40A1E0;\n"
"	border-radius:8px;\n"
"}\n"
"QPushButton#getaccount{\n"
"	background-color:#aa00ff;\n"
"	color:#ffffff;\n"
"	border-radius:8px;\n"
"}\n"
"QPushButton#getaccount:pressed{\n"
"	background-color:#6d00a4;\n"
"	color:#40A1E0;\n"
"	border-radius:8px;\n"
"}\n"
"QLineEdit{\n"
"    background-color:#ffffff;\n"
"    border:1px solid #666666;\n"
"    color:#black;\n"
"	placeholder-text-color:#999999;\n"
"	border-radius:4px;\n"
"}\n"
"QLineEdit:hover{\n"
"    border:1px solid #666666;\n"
"	border-radius:4px;\n"
"}\n"
"QLineEdit:focus{\n"
"    border:1px solid #666666;\n"
"    outline:none; \n"
"	border-radius:4px;\n"
"}\n"
"QLabel#passwordtip{\n"
"	color:#ff0000\n"
"}\n"
"QLabel#accounttip{\n"
"	color:#ff0000\n"
"}\n"
""));
        registeraccount = new QLineEdit(registerUser);
        registeraccount->setObjectName("registeraccount");
        registeraccount->setGeometry(QRect(190, 120, 231, 51));
        registerPassword = new QLineEdit(registerUser);
        registerPassword->setObjectName("registerPassword");
        registerPassword->setGeometry(QRect(190, 200, 231, 51));
        registerPassword->setFont(font);
        welcomqq = new QLabel(registerUser);
        welcomqq->setObjectName("welcomqq");
        welcomqq->setGeometry(QRect(220, 40, 161, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\351\273\221\344\275\223")});
        font1.setPointSize(20);
        welcomqq->setFont(font1);
        welcomqq->setAlignment(Qt::AlignCenter);
        fastregister = new QPushButton(registerUser);
        fastregister->setObjectName("fastregister");
        fastregister->setGeometry(QRect(190, 280, 221, 51));
        getusername = new QPushButton(registerUser);
        getusername->setObjectName("getusername");
        getusername->setGeometry(QRect(430, 120, 91, 41));
        accounttip = new QLabel(registerUser);
        accounttip->setObjectName("accounttip");
        accounttip->setGeometry(QRect(190, 170, 231, 21));
        passwordtip = new QLabel(registerUser);
        passwordtip->setObjectName("passwordtip");
        passwordtip->setGeometry(QRect(190, 250, 231, 21));

        retranslateUi(registerUser);

        QMetaObject::connectSlotsByName(registerUser);
    } // setupUi

    void retranslateUi(QDialog *registerUser)
    {
        registerUser->setWindowTitle(QCoreApplication::translate("registerUser", "Dialog", nullptr));
        welcomqq->setText(QCoreApplication::translate("registerUser", "\346\254\242\350\277\216\346\263\250\345\206\214QQ", nullptr));
        fastregister->setText(QCoreApplication::translate("registerUser", "\347\253\213\345\215\263\346\263\250\345\206\214", nullptr));
        getusername->setText(QCoreApplication::translate("registerUser", "\350\216\267\345\217\226\347\224\250\346\210\267\345\220\215", nullptr));
        accounttip->setText(QString());
        passwordtip->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class registerUser: public Ui_registerUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERUSER_H
