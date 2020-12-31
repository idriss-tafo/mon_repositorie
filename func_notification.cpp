#include "func_notification.h"


func_notification::func_notification(QObject *parent) : QObject(parent), screen(QApplication::desktop()->availableGeometry()), list_notification()
{
}

void func_notification::notifier(QString message, std::function<void ()> func, int timeToDisapear)
{
    Notification *notification = new Notification(message, func, timeToDisapear);
    connect(notification, &Notification::beenDead, this, [this, notification]()
    {
        this->list_notification.removeOne(notification);
        delete notification;
        this->update();
    });
    list_notification.push_front(notification);
    this->update();
    notification->show();
}

void func_notification::update()
{
    auto heigth = screen.height();

    for(int i = 0; i< list_notification.size(); i++)
    {
        heigth -= list_notification[i]->height();
        list_notification[i]->deplacer(QPoint(screen.width()-list_notification[i]->width(),heigth), 1);
    }
}

func_notification::~func_notification()
{
    for (auto notification: list_notification)
    {
        delete notification;
    }
}
