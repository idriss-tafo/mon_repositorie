#include "employers.h"

Employers::Employers()
{

}

Employers::Employers(int id, QString nom, QString prenom, QString sexe, QString poste, QString email, QString id_carte, QString status, QString name_profil, QString perso_delete, QDate date_naissance, QDate date_embauche)
{
    this->id_employer = id;
    this->nom = nom;
    this->prenom = prenom;
    this->sexe = sexe;
    this->poste= poste;
    this->email = email;
    this->id_carte = id_carte;
    this->status_matrimnial = status;
    this->name_profil = name_profil;
    this->perso_delete = perso_delete;
    this->type_personne ="employer";
    this->date_naissance = date_naissance;
    this->date_embauche = date_embauche;

}

int Employers::getId_employer()
{
    return this->id_employer;
}

QString Employers::getNom()
{
    return this->nom;
}

QString Employers::getPrenom()
{
    return this->prenom;
}

QString Employers::getSexe()
{
    return this->sexe;
}

QString Employers::getPoste()
{
    return this->poste;
}

QString Employers::getEmail()
{
    return this->email;
}

QString Employers::getId_carte()
{
    return this->id_carte;
}

QString Employers::getStatus()
{
    return this->status_matrimnial;
}

QString Employers::getName_profil()
{
    return this->name_profil;
}

QString Employers::getPerso_delete()
{
    return this->perso_delete;
}

QString Employers::getType_personne()
{
    return this->type_personne;
}

QDate Employers::getDate_naissance()
{
    return this->date_naissance;
}

QDate Employers::getDate_embauche()
{
    return this->date_embauche;
}

QImage Employers::getImage()
{
    return this->image;
}

void Employers::setId_employer(int id)
{
    this->id_employer = id;
}

void Employers::setNom(QString nom)
{
    this->nom =nom;
}

void Employers::setPrenom(QString prenom)
{
    this->prenom = prenom;
}

void Employers::setSexe(QString sexe)
{
    this->sexe =sexe;
}

void Employers::setPoste(QString poste)
{
    this->poste = poste;
}

void Employers::setEmail(QString email)
{
    this->email = email;
    qDebug()<<email;

}

void Employers::setId_carte(QString carte)
{
    this->id_carte = carte;
}

void Employers::setStatus(QString status)
{
    this->status_matrimnial = status;
}

void Employers::setName_profil(QString profil)
{
    this->name_profil = profil;
}

void Employers::setPerso_delete(QString perso_delete)
{
    this->perso_delete =perso_delete;
}

void Employers::setType_personne(QString type)
{
    this->type_personne = type;
}

void Employers::setDate_naissance(QDate date_naissance)
{
    this->date_naissance = date_naissance;
}

void Employers::setDate_embauche(QDate date_embauche)
{
    this->date_embauche = date_embauche;
}

void Employers::setImage(QImage img)
{
    this->image = img;
}

bool Employers::adduser()
{
   QSqlQuery query;
   QByteArray byteArray;
   QString request = "insert into PERSONNES values (id_personne.nextval, :nom, :prenom, :sexe,"
                     " :poste, :email, :id_carte, :statu_matrimonial, :datenaissance,"
                     " :dateembauche, :image, 'actif', 'employer', :img); ";
  query.prepare(request);
  query.bindValue(":nom", this->nom);
  query.bindValue(":prenom", this->prenom);
  query.bindValue(":sexe", this->sexe);
  query.bindValue(":poste", this->poste);
  query.bindValue(":email", this->email);
  query.bindValue(":id_carte", this->id_carte);
  query.bindValue(":statu_matrimonial", this->status_matrimnial);
  query.bindValue(":datenaissance", this->date_naissance);
  query.bindValue(":dateembauche", this->date_embauche);
  if (this->name_profil== "photo.png")
  {
      qDebug()<<"EMPTY EMPTY !!!!!";

      this->name_profil="C:/Users/idris/Documents/qt/eye_of_god/resource/images/avatar.png";

  }else{
    qDebug()<< this->name_profil;
  QImage imageTMP(this->name_profil);
    this->image = imageTMP;
  QBuffer buffer(&byteArray);

  imageTMP.save(&buffer, "PNG");
  query.bindValue(":img", byteArray, QSql::Binary);
  }
    query.bindValue(":image", this->name_profil);
//qDebug()<<"requette dajout = "<<request;
  if(query.exec()){
      return true;
  }else{
       qDebug()<< "erreur du a:" <<query.lastError().text();
       return false;
  }
}

bool Employers::modifier(Employers e)
{
    QSqlQuery query;
    QByteArray byteArray;
    QString request = "update PERSONNES set nom = :nom, prenom = :prenom, sexe = :sexe, poste = :poste, email = :email, id_carte = :id_carte, statut_matrimonial = :statu_matrimonial, date_naissance = :datenaissance, date_embauche = :dateembauche, name_profil = :image, perso_delete = :del, type_personne = :employer , :img where id_personne = :id;";


    QBuffer buffer(&byteArray);

    e.image.save(&buffer, "PNG");
    query.prepare(request);
    query.bindValue(":id",e.getId_employer());
    query.bindValue(":nom", e.getNom());
    query.bindValue(":prenom", e.getPrenom());
    query.bindValue(":sexe", e.getSexe());
    query.bindValue(":poste", e.getPoste());
    query.bindValue(":email", e.getEmail());
    query.bindValue(":id_carte", e.getId_carte());
    query.bindValue(":statu_matrimonial", e.getStatus());
    query.bindValue(":datenaissance", e.getDate_naissance());
    query.bindValue(":dateembauche", e.getDate_embauche());
    query.bindValue(":del", e.getPerso_delete());
    query.bindValue(":employer", e.getType_personne());
    if (this->name_profil.isEmpty())
    {
        qDebug()<<"EMPTY EMPTY !!!!!";

        e.setName_profil("employe-image_standard.png");

    }else{
    QImage imageTMP(e.getName_profil());

    QBuffer buffer(&byteArray);

    imageTMP.save(&buffer, "PNG");
    query.bindValue(":img", byteArray, QSql::Binary);

    }
query.bindValue(":image", e.getName_profil());
    if(query.exec()){

        return true;

    }else{
         qDebug()<< "erreur de modification du a:" <<query.lastError().text();
         return false;
    }
}

bool Employers::suprimer()
{
    QSqlQuery query;
    QString request = "update PERSONNES set perso_delete = 'suprimer' where id_personne = :id;";
   query.prepare(request);
   query.bindValue(":id", this->id_employer);
   qDebug()<<request<<" "<<this->id_employer;
   if(query.exec()){
       return true;
   }else{
        qDebug()<< "erreur de supression  du a:" <<query.lastError().text();
        return false;
   }
}

QVector<Employers> Employers::listeEmployer()
{
    QVector<Employers> tableau;
    QSqlQuery query;
    QByteArray byteArray;
    Employers employer;
    QString request;
    request ="select* from personnes where perso_delete = 'actif' and type_personne = 'employer' order by nom;";
    if(query.exec(request)){
        while(query.next()){

            employer.id_employer = query.value(0).toInt();
            employer.nom = query.value(1).toString();
            employer.prenom = query.value(2).toString();
            employer.sexe = query.value(3).toString();
            employer.poste = query.value(4).toString();
            employer.email = query.value(5).toString();
            employer.id_carte = query.value(6).toString();
            employer.status_matrimnial = query.value(7).toString();
            employer.date_naissance = query.value(8).toDate();
            employer.date_embauche = query.value(9).toDate();
            employer.name_profil = query.value(10).toString();
            employer.perso_delete = query.value(11).toString();
            employer.type_personne = query.value(12).toString();

            byteArray = query.value(13).toByteArray();
            QPixmap map;
            map.loadFromData(byteArray);
            employer.image = map.toImage();
            if(employer.name_profil == "photo.png"){
                employer.name_profil = "C:/Users/idris/Documents/qt/eye_of_god/resource/images/avatar.png";
            }

            tableau.push_back(employer);
        }
    }else{
        qDebug()<<"erreur piang";
         qDebug()<< "erreur du a:" <<query.lastError().text();
    }
    return tableau;
}

QVector<Employers> Employers::listeEmployerRequest(QString request, QString rech, QDate date1, QDate date2)
{
    QVector<Employers> tableau;
    QSqlQuery query;
    Employers employer;
    query.prepare(request);
    query.bindValue(":rech", rech);
    query.bindValue(":date1", date1);
    query.bindValue(":date2", date2);
    if(query.exec()){
        while(query.next()){

            employer.id_employer = query.value(0).toInt();
            employer.nom = query.value(1).toString();
            employer.prenom = query.value(2).toString();
            employer.sexe = query.value(3).toString();
            employer.poste = query.value(4).toString();
            employer.email = query.value(5).toString();
            employer.id_carte = query.value(6).toString();
            employer.status_matrimnial = query.value(7).toString();
            employer.date_naissance = query.value(8).toDate();
            employer.date_embauche = query.value(9).toDate();
            employer.name_profil = query.value(10).toString();
            employer.perso_delete = query.value(11).toString();
            employer.type_personne = query.value(12).toString();
            tableau.push_back(employer);
        }
    }else{
        qDebug()<<"erreur piang";
         qDebug()<< "erreur du a:" <<query.lastError().text();
    }
    return tableau;
}



QVector<Employers> Employers::selectionMultiple(QPair<QString, QString> critere, QList<QString>listchamp)
{
    QVector<Employers> tableau;
    QSqlQuery query;
    Employers employer;
    QString request;
    request ="select ";
    for(auto a:listchamp){
        request += ", ";
        request += a;
    }
    request.replace(7, 1, " ");
    request += " from personnes where ";
    request += critere.first;
    request += " = ";
    request += critere.second;
    request += " order by nom;";


    if(query.exec(request)){
        while(query.next()){

            employer.id_employer = query.value(0).toInt();
            employer.nom = query.value(1).toString();
            employer.prenom = query.value(2).toString();
            employer.sexe = query.value(3).toString();
            employer.poste = query.value(4).toString();
            employer.email = query.value(5).toString();
            employer.id_carte = query.value(6).toString();
            employer.status_matrimnial = query.value(7).toString();
            employer.date_naissance = query.value(8).toDate();
            employer.date_embauche = query.value(9).toDate();
            employer.name_profil = query.value(10).toString();
            employer.perso_delete = query.value(11).toString();
            employer.type_personne = query.value(12).toString();
            tableau.push_back(employer);
        }
    }else{
        qDebug()<<"erreur piang";
         qDebug()<< "erreur du a:" <<query.lastError().text();
    }
    return tableau;
}

Employers Employers::getPrecedent(Employers e, QVector<Employers> tableau)
{
    Employers tmp;
    QVector<Employers>::Iterator it;
    if(tableau.isEmpty()) return tmp;
    for(it=tableau.begin(); it!=tableau.end(); ++it){
        if(it->getId_employer() == e.getId_employer() ){
            tmp =*(it-1);
            return tmp;
        }
    }
    return tmp;
}

Employers Employers::getSuivant(Employers e, QVector<Employers> tableau)
{
    Employers tmp;
    QVector<Employers>::Iterator it;
    if(tableau.isEmpty()) return tmp;
    for(it=tableau.begin(); it!=tableau.end(); ++it){
        if(it->getId_employer() == e.getId_employer() ){
            if(it+1 != tableau.end()){
                tmp =*(it+1);
                return tmp;
            }

        }
    }
    return tmp;
}

void Employers::AfficheListeEmployer(QVector<Employers> t, QTableWidget* tw)
{
    if(t.isEmpty())return;
    tw->clearContents();
    QString filename_masculin = "C:/Users/idris/Documents/qt/eye_of_god/resource/icon/24x24/manager.png";
    QString filename_feminin = "C:/Users/idris/Documents/qt/eye_of_god/resource/icon/24x24/manager(1).png";
    QString filename_marrier = "C:/Users/idris/Documents/qt/eye_of_god/resource/icon/24x24/wedding-rings.png";
    QString filename_celibataire = "C:/Users/idris/Documents/qt/eye_of_god/resource/icon/24x24/single.png";
    QString filename_divorser = "C:/Users/idris/Documents/qt/eye_of_god/resource/icon/24x24/singles.png";
    int index(0);


    for(auto a:t){
        tw->insertRow(index);
        QTableWidgetItem *itemsexe = new QTableWidgetItem();
        QTableWidgetItem *itemstatus = new QTableWidgetItem();
        if(a.sexe == "MASCULIN") {
            itemsexe->setIcon(QIcon(filename_masculin));
        }else {
                    itemsexe->setIcon(QIcon(filename_feminin));
        }

        if(a.status_matrimnial == "MARIE(E)") {

            itemstatus->setIcon(QIcon(filename_marrier));
        }
        else if(a.status_matrimnial == "CELIBATAIRE") {

            itemstatus->setIcon(QIcon(filename_celibataire));
        }
        else {
            itemstatus->setIcon(QIcon(filename_divorser)) ;
        }

   QString cou = QString::number(a.id_employer);
        // tw->setItem(index,0, new QTableWidgetItem(cou));
         tw->setItem(index,1, new QTableWidgetItem(a.nom));
         tw->setItem(index,2, new QTableWidgetItem(a.prenom));
         tw->setItem(index,3, itemsexe);
         tw->setItem(index,4, new QTableWidgetItem(a.poste));
         tw->setItem(index,5, new QTableWidgetItem(a.email));
         tw->setItem(index,6, new QTableWidgetItem(a.id_carte));
         tw->setItem(index,7, itemstatus);
         tw->setItem(index,8, new QTableWidgetItem(a.date_naissance.toString()));
         tw->setItem(index,9, new QTableWidgetItem(a.date_embauche.toString()));
         tw->setItem(index,10, new QTableWidgetItem(a.name_profil));


         QPushButton *btn_ed, *btn_del;
         btn_ed = new QPushButton();
         btn_del = new QPushButton();
         btn_ed->setText("EDITER");
         btn_del->setText("SUPRIMER");
         QString style = "QPushButton{\n	background-color: rgb(50, 50, 50);\n	border: 2px solid rgb(60, 60, 60);\n	border-radius: 5px;\n}\nQPushButton:hover{\n	background-color: rgb(60, 60, 60);\n	border: 2px solid rgb(70, 70, 70);\n\n}\nQPushButton:pressed{\n	background-color: rgb(255, 0, 0);\n	border: 2px solid rgb(255, 0, 127);\n	color: rgb(35, 35, 35);\n\n}";
         QString style1 = "QPushButton {\n	border: 2px solid rgb(52, 59, 72);\n	border-radius: 5px;	\n	background-color: rgb(52, 59, 72);\n}\nQPushButton:hover {\n	background-color: rgb(36, 73, 109);\n	border: 2px solid rgb(61, 70, 86);\n}\nQPushButton:pressed {\n	background-color: rgb(85, 255, 255);\n	border: 2px solid rgb(43, 50, 61);\n}";
         btn_ed->setStyleSheet(style1);
         btn_del->setStyleSheet(style);
         tw->setCellWidget(index,11, btn_ed);
         tw->setCellWidget(index,12, btn_del);
         QLabel *label;
         label = new QLabel();
         label->setText("");
        if(a.name_profil == "photo.png"){

            QPixmap pix("C:/Users/idris/Documents/qt/eye_of_god/resource/images/avatar.png");

            label->setPixmap(pix.scaled(120,120,Qt::KeepAspectRatio));

            tw->setCellWidget(index,0, label);
        }else{
            QPixmap pix(a.name_profil);
            label->setPixmap(pix.scaled(120,120,Qt::KeepAspectRatio));

            tw->setCellWidget(index,0, label);
        }
         tw->verticalHeader()->setDefaultSectionSize(120);
         tw->horizontalHeader()->setDefaultSectionSize(120);
         index++;
    }
}

QVector<QPair<QString, int> > Employers::groupeEmployer_par_poste()
{
    QVector<QPair<QString, int> >t;


    QSqlQuery query;
    QString request;

    request ="select poste, count(id_personne) from personnes  where perso_delete = 'actif' group by poste;";
    if(query.exec(request)){
        while(query.next()){
            QPair<QString, int>a;
            a.first = query.value(0).toString();
            a.second = query.value(1).toInt();
            t.push_back(a);
            qDebug()<<"je travail";

        }
    }else{
        qDebug()<<"erreur lors du comptage des employer";
         qDebug()<< "erreur du a:" <<query.lastError().text();
    }
    return t;
}


















