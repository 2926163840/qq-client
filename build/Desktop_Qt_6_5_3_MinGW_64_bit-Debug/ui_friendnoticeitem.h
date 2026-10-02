/********************************************************************************
** Form generated from reading UI file 'friendnoticeitem.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDNOTICEITEM_H
#define UI_FRIENDNOTICEITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FriendNoticeItem
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *requestername;
    QLabel *requestmethod;
    QLabel *requesttime;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *leavemessage;
    QLabel *verificationinfo;
    QSpacerItem *horizontalSpacer_2;
    QStackedWidget *stackedWidget;
    QWidget *selectingpage;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *select;
    QWidget *selectedpage;
    QVBoxLayout *verticalLayout_3;
    QLabel *selected;

    void setupUi(QWidget *FriendNoticeItem)
    {
        if (FriendNoticeItem->objectName().isEmpty())
            FriendNoticeItem->setObjectName("FriendNoticeItem");
        FriendNoticeItem->resize(344, 89);
        FriendNoticeItem->setStyleSheet(QString::fromUtf8("\n"
"#requesttime{\n"
"	color:#999999;\n"
"}\n"
"#leavemessage{\n"
"	color:#999999;\n"
"}\n"
"#verificationinfo{\n"
"	color:#999999;\n"
"}\n"
"#selectedpage{\n"
"	background-color:#FFFFFF;\n"
"}\n"
"#selectingpage{\n"
"	background-color:#FFFFFF;\n"
"}\n"
"#requestername{\n"
"	color:#0099FF;\n"
"}\n"
"#selected{\n"
"	color:#999999;\n"
"}\n"
"#requestmethod{\n"
"	color:balck;\n"
"}\n"
"\n"
"#widget_2{\n"
"	background-color:#FFFFFF;\n"
"}\n"
"#widget_3{\n"
"	background-color:#FFFFFF;\n"
"}\n"
"/* \346\225\264\344\275\223\344\270\213\346\213\211\346\241\206\345\256\271\345\231\250 */\n"
"QComboBox\n"
"{\n"
"    border: 1px solid #666666;\n"
"    border-radius: 6px;\n"
"    font-size: 12px;\n"
"    color: black;\n"
"    background-color: #ffffff;\n"
"	height:25px;\n"
"	placeholder-text-color:#999999;\n"
"}\n"
"/* \351\274\240\346\240\207\346\202\254\346\265\256\346\240\267\345\274\217 */\n"
"QComboBox:hover\n"
"{\n"
"    border:1px solid #666666;\n"
"}\n"
"/* \347\202\271\345\207\273\350\201\232\347\204\246\346\240"
                        "\267\345\274\217 */\n"
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
"/* \344\270\213\346\213\211\345\210\227\350\241\250\346\235\241\347\233\256 */\n"
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
"QCombo"
                        "Box QAbstractItemView::item:selected\n"
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
        horizontalLayout = new QHBoxLayout(FriendNoticeItem);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(FriendNoticeItem);
        widget_2->setObjectName("widget_2");
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        widget = new QWidget(widget_2);
        widget->setObjectName("widget");
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, -1, -1, -1);
        requestername = new QLabel(widget);
        requestername->setObjectName("requestername");

        horizontalLayout_2->addWidget(requestername);

        requestmethod = new QLabel(widget);
        requestmethod->setObjectName("requestmethod");

        horizontalLayout_2->addWidget(requestmethod);

        requesttime = new QLabel(widget);
        requesttime->setObjectName("requesttime");

        horizontalLayout_2->addWidget(requesttime);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addWidget(widget);

        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName("widget_3");
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        leavemessage = new QLabel(widget_3);
        leavemessage->setObjectName("leavemessage");
        leavemessage->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(leavemessage);

        verificationinfo = new QLabel(widget_3);
        verificationinfo->setObjectName("verificationinfo");

        horizontalLayout_3->addWidget(verificationinfo);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget_3);


        horizontalLayout->addWidget(widget_2);

        stackedWidget = new QStackedWidget(FriendNoticeItem);
        stackedWidget->setObjectName("stackedWidget");
        selectingpage = new QWidget();
        selectingpage->setObjectName("selectingpage");
        horizontalLayout_4 = new QHBoxLayout(selectingpage);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(10, 0, 25, 0);
        select = new QComboBox(selectingpage);
        select->setObjectName("select");
        select->setMinimumSize(QSize(60, 30));
        select->setMaximumSize(QSize(60, 30));

        horizontalLayout_4->addWidget(select);

        stackedWidget->addWidget(selectingpage);
        selectedpage = new QWidget();
        selectedpage->setObjectName("selectedpage");
        verticalLayout_3 = new QVBoxLayout(selectedpage);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(10, 0, 25, -1);
        selected = new QLabel(selectedpage);
        selected->setObjectName("selected");
        selected->setMinimumSize(QSize(60, 30));
        selected->setMaximumSize(QSize(60, 30));
        QFont font;
        font.setPointSize(8);
        selected->setFont(font);

        verticalLayout_3->addWidget(selected);

        stackedWidget->addWidget(selectedpage);

        horizontalLayout->addWidget(stackedWidget);

        horizontalLayout->setStretch(0, 5);
        horizontalLayout->setStretch(1, 1);

        retranslateUi(FriendNoticeItem);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(FriendNoticeItem);
    } // setupUi

    void retranslateUi(QWidget *FriendNoticeItem)
    {
        FriendNoticeItem->setWindowTitle(QCoreApplication::translate("FriendNoticeItem", "Form", nullptr));
        requestername->setText(QCoreApplication::translate("FriendNoticeItem", "requestername", nullptr));
        requestmethod->setText(QCoreApplication::translate("FriendNoticeItem", "\350\257\267\346\261\202\345\212\240\344\270\272\345\245\275\345\217\213", nullptr));
        requesttime->setText(QCoreApplication::translate("FriendNoticeItem", "time", nullptr));
        leavemessage->setText(QCoreApplication::translate("FriendNoticeItem", "\347\225\231\350\250\200\357\274\232", nullptr));
        verificationinfo->setText(QCoreApplication::translate("FriendNoticeItem", "verificationinfo", nullptr));
        selected->setText(QCoreApplication::translate("FriendNoticeItem", "selected", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FriendNoticeItem: public Ui_FriendNoticeItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDNOTICEITEM_H
