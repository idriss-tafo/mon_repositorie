#include "operation.h"

operation::operation()
{

}
operation::operation(int i,int db,int df,QString t,int ne)
{
   id=i;
   date_debut=db;
   date_fin=df;
   type=t;
   nbr_employee=ne;



}
bool operation::ajouter()
{
    QSqlQuery query(QSqlDatabase::database());

query.prepare("INSERT INTO OPERATION(id,date_debut,date_fin,type,nbr_employee) VALUES(:id,:date_debut,:date_fin,:type,:nbr_employee)");
QString res=QString::number(id);
query.bindValue(":id",res);
query.bindValue(":date_debut",date_debut);
query.bindValue(":date_fin",date_fin);
query.bindValue(":type",type);
query.bindValue(":nbr_employee",nbr_employee);



return query.exec();
}
bool operation::modifier()
{
    QSqlQuery query(QSqlDatabase::database());

query.prepare("UPDATE OPERATION SET id=:id,date_debut=:date_debut,date_fin=:date_fin,type=:type,nbr_employee=:nbr_employee WHERE id=:id");
QString res=QString::number(id);
query.bindValue(":id",res);
query.bindValue(":date_debut",date_debut);
query.bindValue(":date_fin",date_fin);
query.bindValue(":type",type);
query.bindValue(":nbr_employee",nbr_employee);



return query.exec();
}
bool operation::supprimer(int i)
{
    QSqlQuery query;
    query.prepare("Delete from operation where id=:id");
    QString res= QString::number(i);
    query.bindValue(":id",res);
    return query.exec();

}
QSqlQueryModel * operation::afficher()
{
  QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("select * from operation");
model->setHeaderData(0,Qt::Horizontal,"id");
model->setHeaderData(1,Qt::Horizontal,"date_debut");
model->setHeaderData(2,Qt::Horizontal,"date_fin");
model->setHeaderData(3,Qt::Horizontal,"type");
model->setHeaderData(4,Qt::Horizontal,"nbr_employee");

return model;

}
QSqlQueryModel * operation::tri()
{
  QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("select * from operation order by id DESC");
model->setHeaderData(0,Qt::Horizontal,"id");
model->setHeaderData(1,Qt::Horizontal,"date_debut");
model->setHeaderData(2,Qt::Horizontal,"date_fin");
model->setHeaderData(3,Qt::Horizontal,"type");
model->setHeaderData(4,Qt::Horizontal,"nbr_employee");

return model;

}
QSqlQueryModel * operation::chercherid(const QString &type)
{

    QSqlQueryModel * model = new QSqlQueryModel();
  model->setQuery("select * from operation where id like '"+type+"%'");
  model->setHeaderData(0,Qt::Horizontal,"id");
  model->setHeaderData(1,Qt::Horizontal,"date_debut");
  model->setHeaderData(2,Qt::Horizontal,"date_fin");
  model->setHeaderData(3,Qt::Horizontal,"type");
  model->setHeaderData(4,Qt::Horizontal,"nbr_employee");

  return model;
}
QSqlQueryModel * operation::cherchertype(const QString &type)
{

    QSqlQueryModel * model = new QSqlQueryModel();
  model->setQuery("select * from operation where type like '"+type+"%'");
  model->setHeaderData(0,Qt::Horizontal,"id");
  model->setHeaderData(1,Qt::Horizontal,"date_debut");
  model->setHeaderData(2,Qt::Horizontal,"date_fin");
  model->setHeaderData(3,Qt::Horizontal,"type");
  model->setHeaderData(4,Qt::Horizontal,"nbr_employee");

  return model;
}

QSqlQueryModel * operation::cherchernbr_employee(const QString &type)
{

    QSqlQueryModel * model = new QSqlQueryModel();
  model->setQuery("select * from operation where nbr_employee like '"+type+"%'");
  model->setHeaderData(0,Qt::Horizontal,"id");
  model->setHeaderData(1,Qt::Horizontal,"date_debut");
  model->setHeaderData(2,Qt::Horizontal,"date_fin");
  model->setHeaderData(3,Qt::Horizontal,"type");
  model->setHeaderData(4,Qt::Horizontal,"nbr_employee");

  return model;
}

