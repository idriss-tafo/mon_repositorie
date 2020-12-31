
#include<QtCore/QCoreApplication>
#include "connection.h"
#include "ui_connection.h"
#include "dialog.h"


#include <QtDebug>

Connection::Connection(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Connection)
{

    ui->setupUi(this);
    QPixmap pix("C:/Users/idris/Documents/qt/eye_of_god/resource/images/avatar.png");
    int w = ui->label_3->width();
    int h = ui->label_3->height();
    ui->label_3->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

    QPixmap pix_logo("C:/Users/idris/Documents/qt/eye_of_god/resource/images/logos.png");
    int a = ui->label_2->width();
    int b = ui->label_2->height();
    ui->label_2->setPixmap(pix_logo.scaled(a,b,Qt::KeepAspectRatio));

    ui->label->setTextFormat(Qt::RichText);
    ui->label->setText("<a href=\"njnjnjnjnj\">mot de passe oublié</a>");
        connect(ui->valider, SIGNAL(clicked(bool)),this,SLOT(nb_click()) );
}


int Connection:: nb_click(){
    this->reessayer -= 1;
    Dialog dialog;
    dialog.setModal(true);
    dialog.exec();
    qDebug() <<"vous aavez cliquez et il vous reste "<< this->reessayer<<" essaie";

    return this->reessayer;
}


Connection::~Connection()
{
    delete ui;
}

