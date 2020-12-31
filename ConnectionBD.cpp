
#include "connectionbd.h"


bool ConnectionBD(){
//QDebug("je commence la connection a la bd.");
QSqlDatabase con=QSqlDatabase::addDatabase("QODBC");
con.setConnectOptions();

// con.setHostName("localhost/apex");
con.setUserName("idriss");
con.setDatabaseName("test");
// con.setPort(8080);
con.setPassword("96250011");
if(con.open()) {
qDebug("yesssssssss");
return true;
}
else {
     qDebug() << "Error = "<< con.lastError().text();
     return false;
}

}

int ifExiste(QString table, QString attribut, QString nom){
    QString request;
    int retour = 0;
    request = "SELECT :id FROM :table WHERE :attribut = :nom;";
    QString tmp;
    tmp ="id_";
    tmp += table;
    QSqlQuery query;
    query.prepare(request);
    query.bindValue(":id",tmp);
    table += "s";
    table = table.toUpper();
    query.bindValue(":table", table);
    query.bindValue(":attribut", attribut);
    query.bindValue("nom", nom);

    if(query.exec(request)){
        qDebug()<<request;
        qDebug()<<tmp;
        qDebug()<<table << " "<<attribut <<"le nom" << nom;

        retour = query.value(0).toInt();
        return retour;

    }else{
        qDebug()<< "l'erreur est le suivant: "<< query.lastError().text();
        return -1;;
    }
}
