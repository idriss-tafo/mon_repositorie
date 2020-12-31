#ifndef CONNECTION_H
#define CONNECTION_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Connection; }
QT_END_NAMESPACE

class Connection : public QMainWindow
{
    Q_OBJECT
    int reessayer = 3;

public:
    Connection(QWidget *parent = nullptr);

    ~Connection();

private:
    Ui::Connection *ui;

private slots:
    int nb_click();

};
#endif // CONNECTION_H
