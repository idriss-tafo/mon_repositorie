#ifndef OPERATION_H
#define OPERATION_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class operation
{
public:
    operation();
    operation(int,int,int,QString,int);
    QString get_type();



    int get_id;
    int get_date_debut;
    int get_date_fin;
    int get_nbr_employee;

    bool ajouter();
    QSqlQueryModel *afficher();
   bool supprimer(int);
   bool modifier();
   QSqlQueryModel *tri();
   QSqlQueryModel * cherchertype(const QString &);
   QSqlQueryModel * cherchernbr_employee(const QString &);
   QSqlQueryModel * chercherid(const QString &);

private:
    QString type;
    int id,date_debut,date_fin,nbr_employee;
};


#endif // OPERATION_H
