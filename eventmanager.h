#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include<QObject>
#include<QWidget>
#include<QHash>

//事件消费者
using Handler=std::function<bool(QObject*,QEvent*)>;

class EventManager:public QObject
{
public:
    EventManager();
    //回去事件管理者对象
    static EventManager* instance();
    //加载事件过滤器
    void watch(QWidget*target);
    //追加事件处理函数
    void registerHandler(QObject*target,Handler h);
    bool eventFilter(QObject *target, QEvent *event) override;

private:

    QHash<QObject*,QList<Handler>> handler_s;

};

#endif // EVENTMANAGER_H
