#ifndef VEHICULE_H
#define VEHICULE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Vehicule
{
private:
    int id;
    QString date;
    QString marque ;
    QString matricule;
    QString type;
public:
    Vehicule();
    Vehicule(QString,QString,QString,QString,int);
    int getID(){return id;}
    QString getDate(){return date;}
    QString getMarque(){return marque;}
    QString getMatricule(){return matricule;}
    QString getType(){return type;}
    bool ajouter();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * afficher();
    QSqlQueryModel * tri_id();
    QSqlQueryModel *chercher(int);

};

#endif // VEHICULE_H
