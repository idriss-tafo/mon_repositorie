#ifndef COMPTES_H
#define COMPTES_H

#include <QObject>
#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include<QtCore/QCoreApplication>
#include <QSqlQuery>


#include "QtSql"
#include <QtDebug>

using namespace std;

class Comptes
{
private:

    int id_compte;
    QString login, mot_de_passe;

public:
    Comptes();
    Comptes(int,QString,QString);
    int get_id_compte();
    QString get_login();
    QString get_motdepasse();
    void set_id_compte(int id);
    void set_login(QString log);
    void set_motdepasse(QString passwd);
    bool addcompte();


};

#endif // COMPTES_H
