#include<QtCore/QCoreApplication>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogpoubelles.h"
#include "ui_dialogpoubelles.h"
#include <QPixmap>
#include <QLabel>
#include <QMessageBox>
#include "dialogdecharge.h"
#include "ui_dialogdecharge.h"
#include "connexionbd.h"
#include "QDebug"

Connection ::Connection()
{


}
bool Connection::createconnect()
{ bool test=false;
    QSqlDatabase db = QSqlDatabase ::addDatabase("QODBC");
db.setConnectOptions();
    db.setUserName("idriss");
    db.setDatabaseName("test");
    db.setPassword("96250011");
    if (db.open()){
        test=true;
    qDebug()<<"je suis";}
    else{
        qDebug()<<"je suis"<<test;
       qDebug() << "Error = "<< db.lastError().text();
    }
    return test;



}

HMainWindow::HMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

       QPixmap pix("C:/Users/Sana/Documents/untitled12/background.jpg");
       ui->labelback_menu->setPixmap(pix.scaled(1366,768));
}

HMainWindow::~HMainWindow()
{
    delete ui;
}



void HMainWindow::on_pushButtonpoubelles_clicked()
{

     Dialogpoubelles dialogpoubelles;
     dialogpoubelles.setModal(true);
     dialogpoubelles.exec();

}



void HMainWindow::on_pushButtonDecharge_clicked()
{
    Dialogdecharge dialogdecharge;
    dialogdecharge.setModal(true);
    dialogdecharge.exec();
}
