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
    int numCap;
    float longitude,latitude;
    QString Nouvadresse;
    int NouvnumCap;
    float Nouvlongitude,Nouvlatitude;
public:
    poubelle(){};
       poubelle(QString adresse, int numCap,float longitude,float latitude);
       QString getadresse(){ return adresse;}
       int getnumCap() {return numCap;}
       float getLongitude() {return longitude;}
       float getLatitude() {return latitude;}
       bool enregistrer_poubelle(poubelle *pb);
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
     void Modifier(int);
     void ajouterpoubelle();
     QSqlQueryModel * Afficher(QString tripar,QString typetri);
    //impression
     QSqlQueryModel *Imprimercmd();
     QSqlQueryModel *cmdaImprimer();

   /* QSqlQueryModel * Rechercher_Afficher(int);
     QSqlQueryModel *Actualiser_idpoubelle();
     QString TrouverNumCap(int);
     float TrouverLongitude(int);
     float TrouverLatitude(int);
     QString TrouverAdresse(int);
    */
     QString getNouvadresse()
         {
             return Nouvadresse;
         }

     int getNouvnumCap()
         {
             return NouvnumCap;
         }

         float getNouvlongitude()
         {
             return Nouvlongitude;
         }
         float getNouvlatitude()
         {
             return Nouvlatitude;
         }



};

#endif // POUBELLE_H
