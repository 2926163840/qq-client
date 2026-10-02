/********************************************************************************
** Form generated from reading UI file 'emptytipwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPTYTIPWIDGET_H
#define UI_EMPTYTIPWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmptyTipWidget
{
public:

    void setupUi(QWidget *EmptyTipWidget)
    {
        if (EmptyTipWidget->objectName().isEmpty())
            EmptyTipWidget->setObjectName("EmptyTipWidget");
        EmptyTipWidget->resize(400, 300);

        retranslateUi(EmptyTipWidget);

        QMetaObject::connectSlotsByName(EmptyTipWidget);
    } // setupUi

    void retranslateUi(QWidget *EmptyTipWidget)
    {
        EmptyTipWidget->setWindowTitle(QCoreApplication::translate("EmptyTipWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmptyTipWidget: public Ui_EmptyTipWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPTYTIPWIDGET_H
