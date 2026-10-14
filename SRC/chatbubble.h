#ifndef CHATBUBBLE_H
#define CHATBUBBLE_H

#include<QWidget>
#include<QHBoxLayout>
#include<QLabel>
#include<QtMath>
#include<QTextLayout>

#define BUBBLE_MAX_WIDGET 600

class ChatBubble:public QWidget
{
public:
    ChatBubble(const bool isself,const QString nickname,const QString mescontent,QWidget*parent=nullptr);
    //设置气泡状态 0发送中 1已送达 2失败
    void setStatus(qint8 status);

private:
    //调整正文窗口的大小
    void resizeEvent(QResizeEvent *event) override;
    //计算气泡内容长度
    int measureTextWidth(const QString&text,const QFont&font);


private:
    QLabel*contentlabel;
    QLabel*statuslabel;  //状态图标(转圈圈/感叹号)
};

#endif // CHATBUBBLE_H
