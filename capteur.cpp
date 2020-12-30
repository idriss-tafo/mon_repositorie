#include "capteur.h"

capteur::capteur(int ID, QString type, QString departement)
{
    this->ID=ID;
    this->type=type;
    this->departement=departement;
}
bool capteur::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(ID);
    query.prepare("insert into capteur (ID,TYPE,DEPARTEMENTS)""values(:ID,:type,:departement)");

    query.bindValue(":ID",res);
    query.bindValue(":type",type);
    query.bindValue(":departement",departement);

    return query.exec();
}

bool capteur::supprimer(int ID)
{
QSqlQuery query;
QString res=QString::number(ID);
query.prepare("Delete from capteur where ID= :ID");
query.bindValue(":ID",res);
return query.exec();
}

QSqlQueryModel * capteur::afficher()
{
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from capteur");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("departement"));
return model;
}

QSqlQueryModel * capteur::trierID()
{
    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * from capteur ORDER BY ID");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("departement"));
        return model ;

}
QSqlQueryModel * capteur::triertype()
{
    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * from capteur ORDER BY type");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("departement"));
        return model ;

}
QSqlQueryModel * capteur::afficher_type(QString type)
{
    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * from capteur where ID ='"+type+"'");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("departement"));
        return model ;
}
