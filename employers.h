#ifndef EMPLOYERS_H
#define EMPLOYERS_H

#include <QDate>
#include "roles.h"

class Employers
{
public:
    Employers();
    Employers(int id,
              QString nom,
              QString prenom,
              QString sexe,
              QString poste,
              QString email,
              QString id_carte,
              QString status,
              QString name_profil,
              QString perso_delete,
              QDate date_naissance,
              QDate date_embauche);
    int getId_employer();
    QString getNom();
    QString getPrenom();
    QString getSexe();
    QString getPoste();
    QString getEmail();
    QString getId_carte();
    QString getStatus();
    QString getName_profil();
    QString getPerso_delete();
    QString getType_personne();
    QDate getDate_naissance();
    QDate getDate_embauche();
    QImage getImage();


    void setId_employer(int id);
    void setNom(QString nom);
    void setPrenom(QString prenom);
    void setSexe(QString sexe);
    void setPoste(QString poste);
    void setEmail(QString email);
    void setId_carte(QString carte);
    void setStatus(QString status);
    void setName_profil(QString profil);
    void setPerso_delete(QString perso_delete);
    void setType_personne(QString type);
    void setDate_naissance(QDate date_naissance);
    void setDate_embauche(QDate date_embauche);
    void setImage(QImage img);

    bool adduser();
    bool modifier(Employers e);
    bool suprimer();
    QVector<Employers> listeEmployer();
    QVector<Employers> listeEmployerRequest(QString request, QString rech, QDate date1, QDate date2);
    QVector<Employers> selectionMultiple(QPair<QString, QString>critere, QList<QString>listchamp);
    Employers getPrecedent(Employers e, QVector<Employers> tableau);
    Employers getSuivant(Employers e, QVector<Employers> tableau);
    void AfficheListeEmployer(QVector<Employers> t, QTableWidget* tw);
    QVector<QPair<QString, int>> groupeEmployer_par_poste();



private:
    int id_employer;
    QString nom,prenom, sexe,poste, email, id_carte, status_matrimnial, name_profil, perso_delete, type_personne;
    QDate date_naissance, date_embauche;
    QImage image;

};

#endif // EMPLOYERS_H
