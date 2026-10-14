#pragma once
#ifndef GROUPFEATURE_H
#define GROUPFEATURE_H

#include<QObject>

#include "chatfeature.h"
#include"groupannouncement.h"
#include"chatwidget.h"


//#include "chatwidget.h"

class GroupFeature:public ChatFeature
{
public:
    GroupFeature();
    ~GroupFeature();

    void attach(ChatWidget*parent) override;

};

#endif // GROUPFEATURE_H
