#include "hovertip.h"
#include <QApplication>

HoverTip::HoverTip(QWidget *parent)
    :QLabel(parent)
{
    setAttribute(Qt::WA_DeleteOnClose,Qt::WA_TranslucentBackground); // 开启自动销毁
    setStyleSheet(R"(
        QLabel{
            color:#000000;
            padding:10px 18px;
            border-radius:5px;
            font-size:16px;
        }
    )");
    //工具窗口无边框
    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
}

void HoverTip::showTip(QWidget *parent, const QString &text, int duration)
{
    HoverTip* tip = new HoverTip(parent);
    tip->setText(text);
    tip->adjustSize();

    // 位置
    QRect rect = parent->geometry();
    int x = rect.x() + rect.width()/2 - tip->width()/2;
    int y = rect.y() + rect.height()/4 - tip->height() - 60;
    tip->move(x,y);

    tip->show();
    // 定时自动关闭
    QTimer::singleShot(duration, tip, &HoverTip::close);
}
