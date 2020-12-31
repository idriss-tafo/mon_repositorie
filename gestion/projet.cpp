#include "projet.h"

projet::projet()
{

}
projet::projet(int i,QString n,QString s,int d)
{
   id_projet=i;
   nom=n;
   secteur=s;
   duree=d;



}
bool projet::ajouter()
{
    QSqlQuery query(QSqlDatabase::database());

query.prepare("INSERT INTO PROJET(id_projet,nom,secteur,duree) VALUES(:id_projet,:nom,:secteur,:duree)");
QString res=QString::number(id_projet);
query.bindValue(":id_projet",res);
query.bindValue(":nom",nom);
query.bindValue(":secteur",secteur);
query.bindValue(":duree",duree);



return query.exec();
}
bool projet::modifier()
{
    QSqlQuery query(QSqlDatabase::database());

query.prepare("UPDATE PROJET SET id_projet=:id_projet,nom=:nom,secteur=:secteur,duree=:duree WHERE id_projet=:id_projet");
QString res=QString::number(id_projet);
query.bindValue(":id_projet",res);
query.bindValue(":nom",nom);
query.bindValue(":secteur",secteur);
query.bindValue(":duree",duree);



return query.exec();
}
bool projet::supprimer(int i)
{
    QSqlQuery query;
    query.prepare("Delete from projet where id_projet=:id_projet");
    QString res= QString::number(i);
    query.bindValue(":id_projet",res);
    return query.exec();

}
QSqlQueryModel * projet::afficher()
{
  QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("select * from projet");
model->setHeaderData(0,Qt::Horizontal,"id_projet");
model->setHeaderData(1,Qt::Horizontal,"nom");
model->setHeaderData(2,Qt::Horizontal,"secteur");
model->setHeaderData(3,Qt::Horizontal,"duree");

return model;

}
QSqlQueryModel * projet::tri()
{
  QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("select * from projet order by id_projet DESC");
model->setHeaderData(0,Qt::Horizontal,"id_projet");
model->setHeaderData(1,Qt::Horizontal,"nom");
model->setHeaderData(2,Qt::Horizontal,"secteur");
model->setHeaderData(3,Qt::Horizontal,"duree");

return model;

}
QSqlQueryModel * projet::chercherid_projet(const QString &type)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from projet where id_projet like '"+type+"%'");
    model->setHeaderData(0,Qt::Horizontal,"id_projet");
    model->setHeaderData(1,Qt::Horizontal,"nom");
    model->setHeaderData(2,Qt::Horizontal,"secteur");
    model->setHeaderData(3,Qt::Horizontal,"duree");
    return model;

}
QSqlQueryModel * projet::cherchernom(const QString &type)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from projet where nom like '"+type+"%'");
    model->setHeaderData(0,Qt::Horizontal,"id_projet");
    model->setHeaderData(1,Qt::Horizontal,"nom");
    model->setHeaderData(2,Qt::Horizontal,"secteur");
    model->setHeaderData(3,Qt::Horizontal,"duree");
    return model;

}
QSqlQueryModel * projet::cherchersecteur(const QString &type)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from projet where secteur like '"+type+"%'");
    model->setHeaderData(0,Qt::Horizontal,"id_projet");
    model->setHeaderData(1,Qt::Horizontal,"nom");
    model->setHeaderData(2,Qt::Horizontal,"secteur");
    model->setHeaderData(3,Qt::Horizontal,"duree");
    return model;

}
