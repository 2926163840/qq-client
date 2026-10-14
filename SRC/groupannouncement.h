#ifndef GROUPANNOUNCEMENT_H
#define GROUPANNOUNCEMENT_H

#include <QWidget>

namespace Ui {
class GroupAnnouncement;
}

class GroupAnnouncement : public QWidget
{
    Q_OBJECT

public:
    explicit GroupAnnouncement(QWidget *parent = nullptr);
    ~GroupAnnouncement();

private:
    Ui::GroupAnnouncement *ui;
};

#endif // GROUPANNOUNCEMENT_H
