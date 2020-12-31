#ifndef PROJET_H
#define PROJET_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class projet
{
public:
    projet();
    projet(int,QString,QString,int);
    QString get_nom();
    QString get_secteur();


    int get_id_projet;
    int get_duree;

    bool ajouter();
    QSqlQueryModel *afficher();
   bool supprimer(int);
   bool modifier();
   QSqlQueryModel *tri();
   QSqlQueryModel * cherchernom(const QString &);
   QSqlQueryModel * cherchersecteur(const QString &);
   QSqlQueryModel * chercherid_projet(const QString &);

private:
    QString nom,secteur;
    int id_projet,duree;
};

#endif // PROJET_H
