#ifndef FUNC_NOTIFICATION_H
#define FUNC_NOTIFICATION_H

#include <QObject>
#include "notification.h"
#include <QList>
#include <QVector>
#include <QString>
#include <functional>

class func_notification: public QObject
{
    Q_OBJECT
public:
    explicit func_notification(QObject *parent = 0);
    void notifier(QString message, std::function<void ()> func, int timeToDisapear = 10);
    virtual ~func_notification();

signals:

public slots:
private:
    QList<Notification*> list_notification;
    QRect screen;
    void update();
};

#endif // FUNC_NOTIFICATION_H
