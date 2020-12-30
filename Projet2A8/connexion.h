#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>

class Connexion
{
private:
    QSqlDatabase db;
public:
    Connexion();
    bool create_cnx();
    void Fermer_cnx();
};

#endif // CONNEXION_H
