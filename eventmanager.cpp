#include "eventmanager.h"

EventManager::EventManager() {}
//回去事件管理者对象
EventManager *EventManager::instance()
{
    static std::unique_ptr<EventManager> uni_event_obj=std::make_unique<EventManager>();
    return uni_event_obj.get();
}

//加载事件过滤器
void EventManager::watch(QWidget *target)
{
    //重复加载
    if(handler_s.contains(target))
        return;
    target->installEventFilter(this);
    handler_s.emplace(target,QList<Handler>());
    //对象销毁自动从哈希表中剔除
    connect(target,&QObject::destroyed,this,[this](QObject*target){
        handler_s.remove(target);
    });
}
//追加事件处理函数
void EventManager::registerHandler(QObject*target,Handler h)
{
    const auto it=handler_s.find(target);
    if(it==handler_s.end())
        return;
    it.value().append(h);
}

bool EventManager::eventFilter(QObject *target, QEvent *event)
{
    const auto it=handler_s.find(target);
    //无东西加载事件过滤器返回
    if(it==handler_s.end())
        return QObject::eventFilter(target,event);
    //循环调用所加载的事件过滤处理函数
    for(const Handler&h:it.value())
    {
        //任何一个事件处理完成返回true消费事件
        if(h(target,event))
            return true;
    }
    return QObject::eventFilter(target,event);
}
