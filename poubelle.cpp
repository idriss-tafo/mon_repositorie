#include "poubelle.h"
#include "QDebug"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include<QSqlRecord>
#include <QString>
#include<QPainter>
#include <QPrinter>
#include<QTableView>
#include<QDate>
poubelle::poubelle(QString adresse,int numCap,float longitude,float latitude)
{
    this->adresse= adresse;
    this->numCap=numCap;
    this->longitude=longitude;
    this->latitude=latitude;

}
bool poubelle::enregistrer_poubelle(poubelle * pb)
{
QSqlQuery query;
QString str= "insert into POUBELLE (longitude,latitude,num_capteur,adress) values("+QString::number( pb->getLongitude())+", "+QString::number(pb->getLatitude())+","+QString::number(+pb->getnumCap())+",'"+pb->getadresse()+"')" ;
qDebug()<<str;
bool res1 = query.exec(str);
return res1;
}
QSqlQueryModel * poubelle::afficher_poubelle()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from POUBELLE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("numCap"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Longitude"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Latitude"));


    return model;
}
QSqlQueryModel * poubelle::rechercher_poubelle(int Id)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString str="select * from POUBELLE where Id_poubelle ="+QString::number(Id);
    model->setQuery(str);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id_poubelle"));
    return model;
}
// imprimer
QSqlQueryModel *poubelle::Imprimerpou()
{
    QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery("Select id_poubelle from poubelle where(num_capteur is not null)");

         return model;
}
int poubelle::nblignepou(int id)
{
    QSqlQuery query;
     int test=0;
     query.exec("select * from poubelle where id_poubelle="+QString::number(id));

     while(query.next())
         test++;

     return(test);
}
bool poubelle::supprimer_poubelle(int Id)
{
    QSqlQuery query;
    QString str="delete from POUBELLE where Id_poubelle ="+QString::number(Id);
    qDebug()<<str;
    bool res = query.exec(str);
    return res;
}

QSqlQueryModel * poubelle::afficher_poubelleRech(int Id)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString str="select * from POUBELLE where Id_poubelle ="+QString::number(Id);
    model->setQuery(str);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("numCap"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Longitude"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Latitude"));

    return model;
}
//suppmod
poubelle::poubelle(int ID_poubelle)
{
    this->ID_poubelle=ID_poubelle;}
int poubelle::Rechercher(int idp)
{

   QSqlQuery query;
    int test=0;
    query.exec("select * from POUBELLE where ID_poubelle="+QString::number(idp));

    while(query.next())
        test++;

    return(test);
}
void poubelle::Supprimer(int idp)
{QSqlQuery query;
    query.exec("delete from POUBELLE where(ID_poubelle="+QString::number(idp)+")");
}
void poubelle::Modifier(int idp)
{QSqlQuery query;
    query.exec("update POUBELLE Set numcap="+QString::number(getNouvnumCap())+",longitude="+QString::number(getNouvlongitude())+",latitude="+QString::number(getNouvlatitude())+",adresse='"+getNouvadresse()+"' where(id_poubelle="+QString::number(idp)+")");
}
/*
QSqlQueryModel * poubelle::Afficher(QString tripar, QString typetri)
{QString tri="asc";
    if(typetri=="Décroissant")tri="desc";
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from POUBELLE order by("+tripar+")"+tri+"");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_poubelle"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("numCap"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("Longitude"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Latitude"));
    return model;

}
QSqlQueryModel *poubelle::Rechercher_Afficher(int idp)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from Poubelle where(id_poubelle='"+QString::number(idp)+"')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("numCap"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("Longitude"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Latitude"));

       return model;

}

QSqlQueryModel *poubelle::Actualiser_idpoubelle()
{QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("Select ID_poubelle from poubelle");

     return model;

}

QString poubelle::TrouverNumCap(int idp)
{ QSqlQuery query;
    QString result;
    query.exec("Select * from poubelle where(ID_poubelle="+QString::number(idp)+")");
    QSqlRecord rec = query.record();

    //aqDebug() << "Number of columns: " << rec.count();

    int nameCol = rec.indexOf("ID_poubelle"); // index of the field "name"
    while (query.next())
    {
       // qDebug() << query.value(nameCol).toString(); // output all names
    //qDebug()<<"Select * from poubelle where(ID_poubelle="+QString::number(ID_poubelle)+")";
    result=query.value(nameCol).toString();
    }

    return(result);
}
float poubelle::TrouverLongitude(int idp)
{ QSqlQuery query;
    float result;
    query.exec("Select * from poubelle where(ID_poubelle="+QString::number(idp)+")");
    QSqlRecord rec = query.record();

    //aqDebug() << "Number of columns: " << rec.count();

    int nameCol = rec.indexOf("Longitude"); // index of the field "name"
    while (query.next())
    {
       // qDebug() << query.value(nameCol).toString(); // output all names
    //qDebug()<<"Select * from poubelle where(ID_poubelle="+QString::number(idp)+")";
    result=query.value(nameCol).toFloat();
    }

    return(result);

}
QString poubelle::TrouverAdresse(int idp)
{ QSqlQuery query;
    QString result;
    query.exec("Select * from poubelle where(id_poubelle="+QString::number(idp)+")");
    QSqlRecord rec = query.record();

    //aqDebug() << "Number of columns: " << rec.count();

    int nameCol = rec.indexOf("Description"); // index of the field "name"
    while (query.next())
    {

    result=query.value(nameCol).toString();
    }

    return(result);
}
void poubelle::cmdentree(int idp)
{ QSqlQuery query;
    query.exec("update POUBELLE SET Quantite = Quantite + (SELECT Quantite_C from Contenir where poubelle.id_poubelle = Contenir.id_poubelle and Contenir.numcap='"+QString::number(idp)+"')where id_poubelle in (select id_poubelle from Contenir where Contenir.id_poubelle='"+QString::number(idp)+"')");
}

void poubelle::cmdsortie(int id)
{
    QSqlQuery query,quer;
        query.exec("update poubelle SET Quantite = Quantite -(SELECT numcap from Utiliser where poubelle.id_poubelle = Utiliser.id_poubelle and Utiliser.id_Demande='"+QString::number(id)+"')where id_poubelle in (select id_poubelle from Utiliser where Utiliser.id_poubelle='"+QString::number(id)+"')");
quer.exec("update Demande set id_respStock='"+QString::number(15)+"'where id_Demande='"+QString::number(id)+"'");
}

*/
