/********************************************************************************
** Form generated from reading UI file 'itemwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ITEMWIDGET_H
#define UI_ITEMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ItemWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *info;
    QPushButton *add;
    QWidget *widget_2;
    QLabel *message;

    void setupUi(QWidget *ItemWidget)
    {
        if (ItemWidget->objectName().isEmpty())
            ItemWidget->setObjectName("ItemWidget");
        ItemWidget->resize(430, 177);
        ItemWidget->setStyleSheet(QString::fromUtf8("\n"
"QPushButton#add{\n"
"	border-radius:8px;\n"
"	height:30px;\n"
"	background-color:#0099FF;\n"
"	color:#ffffff;\n"
"}\n"
"QPushButton#add:hover{\n"
"	background-color:#008DEB;\n"
"	color:#ffffff;\n"
"}\n"
"QPushButton#add:pressed{\n"
"	background-color:#0081D6;\n"
"	color:#40A1E0;\n"
"}"));
        verticalLayout = new QVBoxLayout(ItemWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(ItemWidget);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        info = new QLabel(widget);
        info->setObjectName("info");

        horizontalLayout->addWidget(info);

        add = new QPushButton(widget);
        add->setObjectName("add");

        horizontalLayout->addWidget(add);

        horizontalLayout->setStretch(0, 10);
        horizontalLayout->setStretch(1, 1);

        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(ItemWidget);
        widget_2->setObjectName("widget_2");
        message = new QLabel(widget_2);
        message->setObjectName("message");
        message->setGeometry(QRect(30, 20, 40, 12));

        verticalLayout->addWidget(widget_2);

        verticalLayout->setStretch(0, 4);
        verticalLayout->setStretch(1, 1);

        retranslateUi(ItemWidget);

        QMetaObject::connectSlotsByName(ItemWidget);
    } // setupUi

    void retranslateUi(QWidget *ItemWidget)
    {
        ItemWidget->setWindowTitle(QCoreApplication::translate("ItemWidget", "Form", nullptr));
        info->setText(QCoreApplication::translate("ItemWidget", "info", nullptr));
        add->setText(QCoreApplication::translate("ItemWidget", "\346\267\273\345\212\240", nullptr));
        message->setText(QCoreApplication::translate("ItemWidget", "message", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ItemWidget: public Ui_ItemWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ITEMWIDGET_H
