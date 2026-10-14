#ifndef RESIZEITEMLISTWIDGET_H
#define RESIZEITEMLISTWIDGET_H

#include<QListWidget>
#include<QWidget>
#include<QResizeEvent>

class ResizeItemListWidget:public QListWidget
{
public:
    explicit ResizeItemListWidget(QWidget*parent=nullptr);
    //调整条目的大小
    void resizeEvent(QResizeEvent *event) override;
};

#endif // RESIZEITEMLISTWIDGET_H
