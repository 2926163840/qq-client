#ifndef EMPTYTIPWIDGET_H
#define EMPTYTIPWIDGET_H

#include <QWidget>
#include<QListWidget>
#include<QLabel>

namespace Ui {
class EmptyTipWidget;
}

class EmptyTipWidget : public QWidget
{
    Q_OBJECT

public:
    ~EmptyTipWidget();
    static void SetEmptyTip(QWidget*parentWidget,QString res,QString tip_str);
    static void SetEmptyTip(QListWidget*parentWidget,QString res,QString tip_str);

public:
    explicit EmptyTipWidget(QWidget *parent = nullptr);

private:
    Ui::EmptyTipWidget *ui;
};

#endif // EMPTYTIPWIDGET_H
