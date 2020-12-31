#ifndef VEHICULE_H
#define VEHICULE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Vehicule
{
private:
    int id;
    QString date_mise;
    QString marque ;
    QString matricule;
    QString type;
    int id_parking;
public:
    Vehicule();
    Vehicule(QString,QString,QString,QString,int,int);
    int getID(){return id;}
    QString getDate(){return date_mise;}
    QString getMarque(){return marque;}
    QString getMatricule(){return matricule;}
    QString getType(){return type;}
    int getId_parking(){return id_parking ;}
    bool ajouter();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * afficher();
    QSqlQueryModel * tri_id();
    QSqlQueryModel * tri_date_mise_en_marche();
    QSqlQueryModel * tri_marque();
    QSqlQueryModel *chercher(int);


};

#endif // VEHICULE_H
