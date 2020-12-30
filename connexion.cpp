#include "connexion.h"

Connection::Connection()
{

}

bool Connection::createconnection()
{
db = QSqlDatabase::addDatabase("QODBC");
bool test=false;
db.setDatabaseName("Projet_2A");//inserer le nom de la source de données ODBC
db.setUserName("salim");//inserer nom de l'utilisateur
db.setPassword("salim");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
void Connection::closeConnection(){db.close();}

