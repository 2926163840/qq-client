#include "resizeitemlistwidget.h"

ResizeItemListWidget::ResizeItemListWidget(QWidget*parent):QListWidget(parent) {}
//调整条目的尺寸大小
void ResizeItemListWidget::resizeEvent(QResizeEvent *event)
{
    //更新viewport
    QListWidget::resizeEvent(event);

    //同步宽度
    for(int i=0;i<this->count();i++)
    {
        QListWidgetItem *item=this->item(i);
        QWidget*itemwidget=this->itemWidget(item);
        if(!itemwidget)continue;//悬空指针
        item->setSizeHint(QSize(this->viewport()->width(),itemwidget->sizeHint().height()));
    }
}
