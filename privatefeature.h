#pragma once

#ifndef PRIVATEFEATURE_H
#define PRIVATEFEATURE_H

#include<QObject>

#include"chatfeature.h"
//#include"chatwidget.h"

class PrivateFeature:public ChatFeature
{
public:
    PrivateFeature();
    ~PrivateFeature();

    void attach(ChatWidget*parent) override;
};

#endif // PRIVATEFEATURE_H
