#include "mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include "connexion.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Connexion c;
    bool test=c.create_cnx();
    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("database is open"),
                                 QObject::tr("connexion etablie"),QMessageBox::Ok);
        //qDebug() <<"connexion etablie";
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("database is not open"),
                                 QObject::tr("erreur de connexion"),QMessageBox::Cancel);
        //qDebug() <<"ereur de connexion";
    }
    return a.exec();
}
