#include "parking.h"

Parking::Parking()
{
    reff=0;
    adresse=".";
    nom=".";
    nb_place=0;
}
Parking::Parking(int r,QString n,QString a,int nb)
{
    reff=r;
    adresse=a;
    nb_place=nb;
    nom=n;
}

bool Parking::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO PARKINGS (reff,nom,adresse,nb_place) VALUES (:reff,:nom,:adresse,:nb_place)");
    QString ress= QString::number(reff);
    query.bindValue(":reff",ress);
    query.bindValue(":adresse",adresse);
    query.bindValue(":nom",nom);
    QString res= QString::number(nb_place);
    query.bindValue(":nb_place",res);

    return query.exec();
}
bool Parking::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE PARKINGS SET reff=:reff,nom=:nom,adresse=:adresse,nb_place=:nb_place WHERE reff=:reff");
    QString ress= QString::number(reff);
    query.bindValue(":reff",ress);
    query.bindValue(":adresse",adresse);
    query.bindValue(":nom",nom);
    QString res= QString::number(nb_place);
    query.bindValue(":nb_place",res);


    return query.exec();
}
bool Parking::supprimer(int reff)
{
    QSqlQuery query ;
    query.prepare("Delete from PARKINGS where reff= :reff");
    QString res= QString::number(reff);
    query.bindValue(":reff",res);
    return query.exec();
}

 QSqlQueryModel * Parking:: afficher()
 {

     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("Select * from  PARKINGS");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("reff"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("adresse"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("nb_place"));

     return model;

 }
 QSqlQueryModel * Parking::tri_reff()
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("Select * from PARKINGS order by reff ASC ");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("reff"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("adresse"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("nb_place"));
     return model;
 }
 QSqlQueryModel * Parking::tri_Adresse()
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("Select * from PARKINGS order by adresse ASC ");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("reff"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("adresse"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("nb_place"));
     return model;
 }
 QSqlQueryModel * Parking::tri_nb_place()
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("Select * from PARKINGS order by nb_place ASC ");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("reff"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("adresse"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("nb_place"));
     return model;
 }

 QSqlQueryModel * Parking::chercher(int reff)
 {
 QSqlQueryModel * model= new QSqlQueryModel();
 QString code=QString::number(reff);
 model->setQuery("select * FROM PARKINGS WHERE reff="+code );
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("reff"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("adresse"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("nb_place"));
     return model;
 }
