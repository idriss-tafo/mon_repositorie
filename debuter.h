#ifndef DEBUTER_H
#define DEBUTER_H

#include <QMainWindow>
#include <QtCore>
#include "login.h"

namespace Ui {
class Debuter;
}

class Debuter : public QMainWindow
{
    Q_OBJECT


public:
     QTimer *timer;
     Login a;
     bool fin = false;
    explicit Debuter(QWidget *parent = nullptr);
    ~Debuter();

private:
    Ui::Debuter *ui;
    //Connection *cnt;

protected slots:
    bool update_progressbar();
    void description_init();
    void description_conbd();
    void description_parametre();

};

#endif // DEBUTER_H
