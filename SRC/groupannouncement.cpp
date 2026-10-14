#include "groupannouncement.h"
#include "ui_groupannouncement.h"

GroupAnnouncement::GroupAnnouncement(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GroupAnnouncement)
{
    ui->setupUi(this);
}

GroupAnnouncement::~GroupAnnouncement()
{
    delete ui;
}
