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


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

       QPixmap pix("C:/Users/Sana/Documents/untitled12/background.jpg");
       ui->labelback_menu->setPixmap(pix.scaled(1366,768));
}

        /*Connection c;
        bool test=c.createconnect();
        if(!test)
    {
            QMessageBox::critical( nullptr ,QObject::tr("database isn't open")
                    ,QObject::tr("connection failed.\n"
                                "Click Cancel to exit.") ,QMessageBox::Cancel);



    }
        else{
            ui->setupUi(this);

               QPixmap pix("C:/Users/Sana/Documents/untitled12/background.jpg");
               ui->labelback_menu->setPixmap(pix.scaled(1366,768));
        }

}*/

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButtonpoubelles_clicked()
{

     Dialogpoubelles dialogpoubelles;
     dialogpoubelles.setModal(true);
     dialogpoubelles.exec();

}



void MainWindow::on_pushButtonDecharge_clicked()
{
    Dialogdecharge dialogdecharge;
    dialogdecharge.setModal(true);
    dialogdecharge.exec();
}
