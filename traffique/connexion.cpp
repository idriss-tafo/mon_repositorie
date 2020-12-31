#include "connexion.h"
//test tuto git
Connexion::Connexion()
{

}

bool Connexion:: create_cnx()
{
    bool test=false;
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Projet2A8");
    db.setUserName("Ines");
    db.setPassword("Ines");
    if(db.open())
    test=true;
    return test;
}

void Connexion:: Fermer_cnx()
{
    db.close();
}
