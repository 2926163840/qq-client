#pragma once

#ifndef CHATFEATURE_H
#define CHATFEATURE_H

#include<QObject>

class ChatWidget;

class ChatFeature
{
public:
    ChatFeature();
    //赛控件的纯虚函数
    virtual void attach(ChatWidget*parent)=0;
    virtual ~ChatFeature();
};

#endif // CHATFEATURE_H
