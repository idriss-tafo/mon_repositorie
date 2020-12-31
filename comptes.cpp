#include "comptes.h"

Comptes::Comptes(){

}

Comptes::Comptes(int a, QString b, QString c)
{

    this->id_compte = a;
    this->login = b;
    this->mot_de_passe = c;
}
int Comptes::get_id_compte(){
    return this->id_compte;
}

QString Comptes::get_login(){
    return this->login;
}


QString Comptes::get_motdepasse(){
    return this->mot_de_passe;
}


void Comptes::set_id_compte(int id){
    this->id_compte = id;
}

void Comptes::set_login(QString log){
    this->login = log;
}


void Comptes::set_motdepasse(QString passwd){
    this->mot_de_passe= passwd;
}


bool Comptes::addcompte(){
        QByteArray mpd;
        QByteArray mpd_sha;
        QString mpd_crypter;
        QSqlQuery query;
        mpd = this->mot_de_passe.toUtf8();

        mpd_sha= QCryptographicHash::hash(mpd, QCryptographicHash::Sha256);
        mpd_crypter= mpd_sha.toHex();
        QString request = "INSERT INTO COMPTES values (id_compte.nextval, '";
        request += this->login;
        request += "', '";

        request += mpd_crypter;
        request += "', ";
        request += "'oui', 'non-activer');";

        qDebug()<<request;
        query.exec(request);
        if(query.exec(request)){

            return true;
        }else{
            qDebug()<< "erreur d'ajout du compte du a:" <<query.lastError().text();

            return false;
        }

}
