#include "quantite.h"
#include "QDebug"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
quantite::quantite(QString type, QString provenance, float poids)
{
    this->type=type;
    this->provenance=provenance;
    this->poids=poids;

}
bool quantite::enregistrer_quantite(quantite * qnt)
{
QSqlQuery query;
QString str= "insert into DECHARGE (poids,provenance,type) values("+QString::number( qnt->getpoids())+",'"+qnt->getprovenance()+"','"+qnt->gettype()+"')" ;
qDebug()<<str;
bool res1 = query.exec(str);
return res1;
}
QSqlQueryModel * quantite::afficher_quantite()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from POUBELLE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("numCap"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Longitude"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Latitude"));


    return model;
}
QSqlQueryModel * quantite::rechercher_quantite(int Id)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString str="select * from POUBELLE where cin ="+QString::number(Id);
    model->setQuery(str);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    return model;
}
bool quantite::supprimer_quantite(int Id)
{
    QSqlQuery query;
    QString str="delete from POUBELLE where Id ="+QString::number(Id);
    qDebug()<<str;
    bool res = query.exec(str);
    return res;
}

QSqlQueryModel * quantite::afficher_quantiteRech(int Id)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString str="select * from POUBELLES where Id ="+QString::number(Id);
    model->setQuery(str);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("numCap"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Longitude"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Latitude"));

    return model;
}

