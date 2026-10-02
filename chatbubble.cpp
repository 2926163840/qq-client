#include "chatbubble.h"

ChatBubble::ChatBubble(const bool isself,const QString nickname,const QString mescontent,QWidget*parent):QWidget(parent)
{
    //头像正文布局
    QHBoxLayout*outer=new QHBoxLayout(this);
    //头像和正文的间距
    outer->setSpacing(6);

    //昵称信息内容布局
    QVBoxLayout*contentlayout=new QVBoxLayout;
    //昵称和消息的间距
    contentlayout->setSpacing(2);;
    //昵称
    QLabel*nick=new QLabel(this);
    //昵称为灰色大小11px透明背景
    nick->setStyleSheet("color:#999999;font-size:11px;background:transparent;padding:2px");
    nick->setText(nickname);
    //加入正文布局  好友在左边用户在右边
    contentlayout->addWidget(nick,0,isself?Qt::AlignRight:Qt::AlignLeft);
    //正文
    contentlabel=new QLabel(this);
    //开启文本自动换行
    contentlabel->setWordWrap(true);
    //可选中
    contentlabel->setTextInteractionFlags(Qt::TextSelectableByMouse);
    contentlabel->setText(mescontent);
    //好友正文背景白色用户浅蓝色
    contentlabel->setStyleSheet(isself ?
                                    "color:#000000;background-color:#CCEBFF;border-radius:12px;padding:2px 8px;":
                                    "color:#000000;background-color:#FFFFFF;border-radius:12px;padding:2px 8px;");
    //设置字体大小
    QFont f=contentlabel->font();
    f.setPixelSize(14);
    contentlabel->setFont(f);
    //控件最大宽度
    int maxW = qMin(int(this->width() * 0.7), BUBBLE_MAX_WIDGET);
    // 手动算文字单行宽度 并补上固定误差和padding
    int textW = measureTextWidth(contentlabel->text(),contentlabel->font())+19;
    //单行长度超过maxw取maxw换行 24为padding
    contentlabel->setFixedWidth(qMin(textW, maxW));

    //加入正文布局
    contentlayout->addWidget(contentlabel,0,isself?Qt::AlignRight:Qt::AlignLeft);
    //好友消息在左侧用户在右侧
    if(isself)
    {
        //先加弹簧
        outer->addStretch();
        //后加布局
        outer->addLayout(contentlayout);
    }
    else
    {
        outer->addLayout(contentlayout);
        outer->addStretch();
    }
}
//调整当前正文窗口的大小
void ChatBubble::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);


    int maxW = qMin(int(this->width() * 0.7), BUBBLE_MAX_WIDGET);
    // 手动算文字单行宽度 并补上固定误差和padding
    int textW = measureTextWidth(contentlabel->text(),contentlabel->font())+19;
    //单行长度超过maxw取maxw换行 24为padding
    contentlabel->setFixedWidth(qMin(textW, maxW));

}
//计算单行文本宽度
int ChatBubble::measureTextWidth(const QString &text,const  QFont &font)
{
    //文本排版引擎
    QTextLayout layout(text,font);
    //开始计算
    layout.beginLayout();
    //创建第一行文本
    QTextLine line=layout.createLine();
    //强制不换行
    line.setLineWidth(1e6);
    //绘制计算完成
    layout.endLayout();
    //向上取整原生文本宽度
    return qCeil(line.naturalTextWidth());
}
