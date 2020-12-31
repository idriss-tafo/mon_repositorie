#ifndef QUANTITE_H
#define QUANTITE_H

#include<QString>

#include<QSqlTableModel>
class quantite
{

protected:
    QString type ;
    QString provenance ;
    float poids ;
public:
    quantite(){};
       quantite(QString type,  QString provenance, float poids);
       QString gettype(){ return type;}
       QString getprovenance(){ return provenance;}
       float getpoids() {return poids;}
       bool enregistrer_quantite(quantite *qnt);
       virtual QSqlQueryModel * afficher_quantite();
       QSqlQueryModel * rechercher_quantite(int Id);
     bool supprimer_quantite(int Id);
      virtual QSqlQueryModel * afficher_quantiteRech(int ID);
};

#endif // QUANTITE_H
