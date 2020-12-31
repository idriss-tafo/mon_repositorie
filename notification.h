#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QApplication>
#include <QWidget>
#include <QUuid>
#include <QTimer>
#include <QDesktopWidget>
#include <QPixmap>
#include <QPoint>
#include <QMouseEvent>


namespace Ui {
class Notification;
}

class Notification : public QWidget
{
    Q_OBJECT

public:
    explicit Notification(QString message, std::function<void ()> func, int timeToDisapear = 10);


    void deplacer(const QPoint &target, const float velocity);
    bool oper(const Notification &notification) const;
    ~Notification();


private:
    Ui::Notification *ui;
    QTimer *moveTimer;
    QUuid id;
    std::function<void ()> func;
protected:
    void mouseReleaseEvent(QMouseEvent *event);
    void closeEvent(QCloseEvent *event);

signals:
    void beenDead(const QUuid id);

public slots:


};

#endif // NOTIFICATION_H
