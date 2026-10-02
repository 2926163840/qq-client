/********************************************************************************
** Form generated from reading UI file 'groupannouncement.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPANNOUNCEMENT_H
#define UI_GROUPANNOUNCEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GroupAnnouncement
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *announcementlabel;
    QTextEdit *announcement;

    void setupUi(QWidget *GroupAnnouncement)
    {
        if (GroupAnnouncement->objectName().isEmpty())
            GroupAnnouncement->setObjectName("GroupAnnouncement");
        GroupAnnouncement->resize(400, 300);
        GroupAnnouncement->setStyleSheet(QString::fromUtf8("#GroupAnnouncement{\n"
"	background-color:#F5F5F5;\n"
"}\n"
"\n"
"#announcement{\n"
"	background-color:#FFFFFF;\n"
"	border:none;\n"
"	color:#F1F1F1;\n"
"}\n"
"\n"
"#announcementlabel{\n"
"	color:#000000;\n"
"}"));
        verticalLayout = new QVBoxLayout(GroupAnnouncement);
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(10, 10, 10, 0);
        announcementlabel = new QLabel(GroupAnnouncement);
        announcementlabel->setObjectName("announcementlabel");
        QFont font;
        font.setFamilies({QString::fromUtf8("\351\273\221\344\275\223")});
        font.setPointSize(12);
        announcementlabel->setFont(font);

        verticalLayout->addWidget(announcementlabel);

        announcement = new QTextEdit(GroupAnnouncement);
        announcement->setObjectName("announcement");

        verticalLayout->addWidget(announcement);


        retranslateUi(GroupAnnouncement);

        QMetaObject::connectSlotsByName(GroupAnnouncement);
    } // setupUi

    void retranslateUi(QWidget *GroupAnnouncement)
    {
        GroupAnnouncement->setWindowTitle(QCoreApplication::translate("GroupAnnouncement", "Form", nullptr));
        announcementlabel->setText(QCoreApplication::translate("GroupAnnouncement", "\347\276\244\345\205\254\345\221\212", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GroupAnnouncement: public Ui_GroupAnnouncement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPANNOUNCEMENT_H
