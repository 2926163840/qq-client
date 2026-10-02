/********************************************************************************
** Form generated from reading UI file 'chatitem.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATITEM_H
#define UI_CHATITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatItem
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *Textwidget;
    QVBoxLayout *verticalLayout;
    QLabel *objectname;

    void setupUi(QWidget *ChatItem)
    {
        if (ChatItem->objectName().isEmpty())
            ChatItem->setObjectName("ChatItem");
        ChatItem->resize(225, 50);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ChatItem->sizePolicy().hasHeightForWidth());
        ChatItem->setSizePolicy(sizePolicy);
        ChatItem->setMinimumSize(QSize(135, 50));
        ChatItem->setMaximumSize(QSize(300, 50));
        horizontalLayout = new QHBoxLayout(ChatItem);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Textwidget = new QWidget(ChatItem);
        Textwidget->setObjectName("Textwidget");
        sizePolicy.setHeightForWidth(Textwidget->sizePolicy().hasHeightForWidth());
        Textwidget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(Textwidget);
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(10, 5, 10, 5);
        objectname = new QLabel(Textwidget);
        objectname->setObjectName("objectname");

        verticalLayout->addWidget(objectname);


        horizontalLayout->addWidget(Textwidget);


        retranslateUi(ChatItem);

        QMetaObject::connectSlotsByName(ChatItem);
    } // setupUi

    void retranslateUi(QWidget *ChatItem)
    {
        ChatItem->setWindowTitle(QCoreApplication::translate("ChatItem", "Form", nullptr));
        objectname->setText(QCoreApplication::translate("ChatItem", "objectname", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatItem: public Ui_ChatItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATITEM_H
