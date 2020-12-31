#ifndef POUBELLE_H
#define POUBELLE_H
#include<QString>
#include<QDialog>
#include<iostream>
using namespace std;
#include<QSqlTableModel>

class poubelle
{

protected:
    int ID_poubelle;
    QString adresse;
    QString etat;
    int numCap;
    QString longitude,latitude;
public:
    //Les constructeurs
    poubelle(){};
       poubelle(QString adresse, int numCap,QString longitude,QString latitude,QString etat);
       //Les getteurs
       int getId(){return ID_poubelle;}
       QString getadresse(){ return adresse;}
       QString getetat(){ return etat;}
       int getnumCap() {return numCap;}
       QString getLongitude() {return longitude;}
       QString getLatitude() {return latitude;}
       //les setteurs
       void setAdress(QString adresse){this->adresse=adresse;}
       void setEtat(QString etat){this->etat=etat;}
       void setLongitude(QString longitude){this->longitude=longitude;}
       void setLatitude(QString latitude){this->latitude=latitude;}
       void setnumCap(int numCap){this->numCap=numCap;}
       void setID_poubelle(int ID_poubelle){this->ID_poubelle=ID_poubelle;}


       //Les Requets
       bool enregistrer_poubelle(poubelle *pb);
       QSqlQueryModel * Afficher(QString tripar,QString Type_Tri);
       virtual QSqlQueryModel * afficher_poubelle();
       QSqlQueryModel * rechercher_poubelle(int Id);
       QSqlQueryModel *Imprimerpou();
       int nblignepou(int);
     bool supprimer_poubelle(int Id);
      virtual QSqlQueryModel * afficher_poubelleRech(int ID);
     poubelle(int);
//MoDSuP
     int Rechercher(int);
     void Supprimer(int);
     void Modifier();
     void ajouterpoubelle();


    //impression
     QSqlQueryModel *Imprimercmd();
     QSqlQueryModel *cmdaImprimer();

   /* QSqlQueryModel * Rechercher_Afficher(int);
     QSqlQueryModel *Actualiser_idpoubelle();
     */
     float TrouverNumCap(int);
     QString TrouverLongitude(int);
     QString TrouverLatitude(int);
     QString TrouverAdresse(int);
     QString TrouverEtat(int);

public :static poubelle *getPoubelleParId(int);

};

#endif // POUBELLE_H
