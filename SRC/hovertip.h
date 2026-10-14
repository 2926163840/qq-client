#ifndef TOAST_H
#define TOAST_H
#include <QLabel>
#include <QTimer>
#include <QWidget>
class HoverTip : public QLabel
{
    Q_OBJECT
public:
    // 提示信息  parent：父窗口，text提示文字，duration显示时长(ms)
    static void showTip(QWidget* parent, const QString& text, int duration = 3000);
private:
    explicit HoverTip(QWidget* parent = nullptr);
};
#endif // TOAST_H
