#ifndef ROLES_H
#define ROLES_H

#include <QObject>
#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include<QtCore/QCoreApplication>


#include "QtSql"
#include <QtDebug>


class Roles
{

public:
    Roles();
    Roles(QString libele, QString service, QString description, float cout, int temptravail);
    QString getStatus();
    QString getLibele();
    QString getService();
    QString getDescription();
    float getCout();
    int gettemp_de_travail();
    void setLibele(QString libele);
    void setService(QString service);
    void setDescription(QString description);
    void setCout(float cout);
    void settTemp_de_travail(int temp);
    void setStatus(QString status);
    QList<Roles> rechercheTous(QPair<QString, QString> condition);
    QVector<Roles> listeRole();
    bool addRole(Roles role);
    bool suprimerRole(QString libele);
    bool modifierRole(Roles correcte);
    void AfficherListeRoles(QVector<Roles> t ,QTableWidget* tw);
    Roles getprecedent(QVector<Roles> t, Roles r);
    Roles getsuivant(QVector<Roles> t, Roles r);
    QVector<QPair<QString, QList<QString>>> createlistedepartement_poste();

private:
    QString libele, service, description, status;
    int temp_de_travail;
    float cout;



};

#endif // ROLES_H
