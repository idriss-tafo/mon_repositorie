#ifndef CAPTEUR_H
#define CAPTEUR_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class capteur
{
    QString type, departement;
    int ID;

public:
    //constructeur
    capteur(){}
    capteur(int,QString,QString);
    //getteurs
    QString gettype(){return type; }
    QString getdepartement(){ return departement;}
    int getID(){return ID;}
    //setters
    void settype(QString n){type = n;}
    void setdepartement(QString p){departement=p;}
    void setID(int ID){this->ID=ID;}
    //fonction de base
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * trierID();
    QSqlQueryModel * triertype();
    QSqlQueryModel * afficher_type(QString);

    bool supprimer(int);
};

#endif // CAPTEUR_H
