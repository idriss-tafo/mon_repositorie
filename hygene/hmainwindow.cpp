#include "hmainwindow.h"
#include "ui_hmainwindow.h"
#include "dialogpoubelles.h"
#include "ui_dialogpoubelles.h"
#include <QPixmap>
#include <QLabel>
#include <QMessageBox>
#include "dialogdecharge.h"
#include "ui_dialogdecharge.h"
#include "connexionbd.h"

Connection ::Connection()
{


}
bool Connection::createconnect()
{ bool test=false;
    QSqlDatabase db = QSqlDatabase ::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A.");
    db.setUserName("Sana");
    db.setPassword("esprit20");
    if (db.open())
        test=true;
    return test;



}


HMainWindow::HMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HMainWindow)
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
