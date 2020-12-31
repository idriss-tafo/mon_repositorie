#include "notification.h"
#include "ui_notification.h"
#include <QDebug>

Notification::Notification(QString message, std::function<void ()> func, int timeToDisapear) : QWidget(NULL, Qt::Drawer
                                        | Qt::WindowStaysOnTopHint
                                        | Qt::X11BypassWindowManagerHint
                                        | Qt::FramelessWindowHint), moveTimer(new QTimer()), id(QUuid::createUuid()), func(func),
                                        ui(new Ui::Notification)
{
    ui->setupUi(this);
    auto rec = QApplication::desktop()->availableGeometry();
        qDebug() <<"longeur" <<rec.width();
        qDebug() <<"largeur" <<rec.height();
    this->setFixedWidth(2*rec.width()/10);
    this->setFixedHeight(100); // rec.height()/10
    this->deplacer(rec.topLeft(), rec.height()-this->height());
        QPixmap pix_logo("C:/Users/idris/Documents/qt/eye_of_god/resource/images/logos.png");
        int a = ui->logos_notification->width();
        int b = ui->logos_notification->height();
        ui->logos_notification->setPixmap(pix_logo.scaled(a,b,Qt::KeepAspectRatio));
    ui->texte->setText(message);
    connect(ui->pb_close_notification, &QAbstractButton::clicked, this, &Notification::close);
    QTimer::singleShot(timeToDisapear*1000, this, SLOT(close()));
    moveTimer->setInterval(16);

}

Notification::~Notification()
{

    delete ui;
    delete moveTimer;
}



void Notification::mouseReleaseEvent(QMouseEvent *event)
{
    event->accept();

    if (event->button() == Qt::LeftButton)
    {
        this->func();
        this->close();
    }
}

void Notification::deplacer(const QPoint &target, const float velocity)
{
    moveTimer->disconnect();
    auto origine = this->pos();
    auto direction = target - origine;
    connect(moveTimer, &QTimer::timeout, this, [&, target, velocity, origine, direction]()
    {
        auto nowPos = this->pos();
        auto newPose = this->pos() + direction*(velocity/moveTimer->interval());
        if ((newPose - target).manhattanLength() > (nowPos - target).manhattanLength())
        {
            newPose = target;
            moveTimer->stop();
        }

        this->move(newPose);

    });
    moveTimer->start();
}


bool Notification::oper(const Notification &notification) const
{
    if(this->id == notification.id)
    {
        return true;
    }
    return false;
}

void Notification::closeEvent(QCloseEvent *event)
{
    event->accept();
    emit beenDead(this->id);
}
