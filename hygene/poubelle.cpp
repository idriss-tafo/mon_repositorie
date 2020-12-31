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
poubelle::poubelle(QString adresse, int numCap, QString longitude, QString latitude, QString etat)
{
    this->adresse= adresse;
    this->numCap=numCap;
    this->longitude=longitude;
    this->latitude=latitude;
    this->etat=etat;
}
bool poubelle::enregistrer_poubelle(poubelle * pb)
{
QSqlQuery query;
QString str= "insert into POUBELLE (longitude,latitude,num_capteur,adress,etat) values("+pb->getLongitude()+", "+pb->getLatitude()+","+QString::number(+pb->getnumCap())+",'"+pb->getadresse()+"','"+pb->getetat()+"')" ;
qDebug()<<str;
bool res1 = query.exec(str);
return res1;
}
QSqlQueryModel * poubelle::afficher_poubelle()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from POUBELLE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_poubelle"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_modifiction"));
           model->setHeaderData(4, Qt::Horizontal, QObject::tr("num_capteur"));
           model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("Longitude"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("Latitude"));
           model->setHeaderData(6, Qt::Horizontal, QObject::tr("etat"));


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
void poubelle::Modifier()
{QSqlQuery query;
    query.exec("update POUBELLE Set num_capteur="+QString::number(getnumCap())+",longitude='"+getLongitude()+"',latitude='"+getLatitude()+"',adress='"+getadresse()+"',etat='"+getetat()+"'  where(id_poubelle="+QString::number(getId())+")");
qDebug()<<"update POUBELLE Set num_capteur="+QString::number(getnumCap())+",longitude='"+getLongitude()+"',latitude='"+getLatitude()+"',adress='"+getadresse()+"',etat='"+getetat()+"' where(id_poubelle="+QString::number(getId())+")";
}

QSqlQueryModel * poubelle::Afficher(QString tripar, QString type_tri)
{ QString selected_Tritype=(type_tri=="croissant")?"asc":"desc"; //the conditional operator or ternary(the operator ?:)
   // if(Type_Tri=="decroissant")comboBox_Tri="desc";
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from POUBELLE order by("+tripar+") "+selected_Tritype);
qDebug()<<"select * from POUBELLE order by("+tripar+") "+selected_Tritype;
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_poubelle"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_modifiction"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("num_capteur"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("Longitude"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("Latitude"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("etat"));

    return model;

}
/*
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
*/

poubelle* poubelle:: getPoubelleParId(int idp){
    QSqlQuery query;

        query.exec("Select * from POUBELLE where(ID_poubelle="+QString::number(idp)+")");
        QSqlRecord rec = query.record();
            poubelle* p= new poubelle();

                    while (query.next())
                    {
                       // qDebug() << query.value(nameCol).toString(); // output all names
                    //qDebug()<<"Select * from Poubelle where(id_poubelle="+QString::number(idp)+")";
                   p->setnumCap( query.value(rec.indexOf("num_capteur")).toFloat());
                   p->setAdress( query.value(rec.indexOf("adresse")).toString());
                   p->setLatitude( query.value(rec.indexOf("latitude")).toString());
                   p->setLongitude( query.value(rec.indexOf("longitude")).toString());
                    p->setEtat( query.value(rec.indexOf("etat")).toString());
                     p->setID_poubelle(query.value(rec.indexOf("ID_poubelle")).toInt());



                    //rec.indexOf("adresse"),,rec.indexOf("Longitude"),rec.indexOf("Latitude"),rec.indexOf("etat"))
                    }
                    return p;

}

float poubelle::TrouverNumCap(int idp)
{ QSqlQuery query;
    float result;
    query.exec("Select * from POUBELLE where(ID_poubelle="+QString::number(idp)+")");
    QSqlRecord rec = query.record();

    //aqDebug() << "Number of columns: " << rec.count();

    int nameCol = rec.indexOf("num_capteur"); // index of the field "name"
    while (query.next())
    {
       // qDebug() << query.value(nameCol).toString(); // output all names
    //qDebug()<<"Select * from Poubelle where(id_poubelle="+QString::number(idp)+")";
    result=query.value(nameCol).toFloat();
    }

    return(result);

}
QString poubelle::TrouverLongitude(int idp)
{ QSqlQuery query;
    QString result;
    query.exec("Select * from poubelle where(id_poubelle="+QString::number(idp)+")");
    QSqlRecord rec = query.record();

    //aqDebug() << "Number of columns: " << rec.count();

    int nameCol = rec.indexOf("Longitude"); // index of the field "name"
    while (query.next())
    {

    result=query.value(nameCol).toString();
    }

    return(result);
}
    QString poubelle::TrouverLatitude(int idp)
    { QSqlQuery query;
        QString result;
        query.exec("Select * from poubelle where(id_poubelle="+QString::number(idp)+")");
        QSqlRecord rec = query.record();

        //aqDebug() << "Number of columns: " << rec.count();

        int nameCol = rec.indexOf("Latitude"); // index of the field "name"
        while (query.next())
        {

        result=query.value(nameCol).toString();
        }

        return(result);
    }

QString poubelle::TrouverAdresse(int idp)
{ QSqlQuery query;
    QString result;
    query.exec("Select * from poubelle where(id_poubelle="+QString::number(idp)+")");
    QSqlRecord rec = query.record();

    //aqDebug() << "Number of columns: " << rec.count();

    int nameCol = rec.indexOf("adress"); // index of the field "name"
    while (query.next())
    {

    result=query.value(nameCol).toString();
    }

    return(result);

}
QString poubelle::TrouverEtat(int idp)
{ QSqlQuery query;
    QString result;
    query.exec("Select * from poubelle where(id_poubelle="+QString::number(idp)+")");
    QSqlRecord rec = query.record();

    //aqDebug() << "Number of columns: " << rec.count();

    int nameCol = rec.indexOf("etat"); // index of the field "name"
    while (query.next())
    {

    result=query.value(nameCol).toString();
    }

    return(result);
}

