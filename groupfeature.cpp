#include "groupfeature.h"


GroupFeature::GroupFeature() {}

GroupFeature::~GroupFeature()
{

}

//添加群聊窗口控件
void GroupFeature::attach(ChatWidget*parent)
{
    //创建群公告控件
    GroupAnnouncement*groupannouncement=new GroupAnnouncement;
    parent->AddControl_Right(groupannouncement);
}
