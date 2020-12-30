#ifndef CONNEXIONBD_H
#define CONNEXIONBD_H
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQuery>

class Connection
{
public:
Connection();
bool createconnect();
};
#endif // CONNEXIONBD_H
