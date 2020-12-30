#include "mainwindow.h"
#include <QApplication>
#include"connexionbd.h"
#include<QMessageBox>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connection c;
            bool test=c.createconnect();
            if(!test)
        {
                QMessageBox::critical( nullptr ,QObject::tr("database isn't open")
                        ,QObject::tr("connection failed.\n"
                                    "Click Cancel to exit.") ,QMessageBox::Cancel);



        }
            else{
    w.show();}
    return a.exec();
}
