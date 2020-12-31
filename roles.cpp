#include "roles.h"

Roles::Roles()
{

}

Roles::Roles(QString libele, QString service, QString description, float cout, int temptravail)
{
    this->status ="actif";
    this->libele = libele;
    this->service = service;
    this->description = description;
    this->cout = cout;
    this->temp_de_travail = temptravail;
}

QString Roles::getStatus()
{
    return this->status;
}

QString Roles::getLibele()
{
    return this->libele;
}

QString Roles::getService()
{
    return this->service;
}

QString Roles::getDescription()
{
    return  this->description;
}

float Roles::getCout()
{
    return this->cout;
}

int Roles::gettemp_de_travail()
{
    return this->temp_de_travail;
}

void Roles::setLibele(QString libele)
{
    this->libele= libele;
}

void Roles::setService(QString service)
{
    this->service = service;
}

void Roles::setDescription(QString description)
{
    this->description = description;
}

void Roles::setCout(float cout)
{
    this->cout = cout;
}

void Roles::settTemp_de_travail(int temp)
{
    this->temp_de_travail = temp;
}

void Roles::setStatus(QString status)
{
    this->status =status;
}

QList<Roles> Roles::rechercheTous(QPair<QString, QString> condition)
{
    QList<Roles> listerole;
    QSqlQuery query;
    float nombre;
    Roles role;
    QString request;
    request = "select* from POSTES where ";
    request += condition.first;
    request += " = ";
    if(condition.first == "cout" || condition.first == "temp_de_travail"){
        nombre= condition.second.toFloat();
        request += nombre;

    }else{
       request += condition.second;

}
    request +=" and status = actif";
    request +=" order by libele;";
    if(query.exec(request)){
        while(query.next()){
            role.libele = query.value(0).toString();
            role.cout = query.value(1).toFloat();
            role.temp_de_travail = query.value(2).toInt();
            role.service = query.value(3).toString();
            role.description = query.value(4).toString();
            listerole<<role;
        }
    }else{
        qDebug()<<"erreur piang";
         qDebug()<< "erreur du a:" <<query.lastError().text();
    }

    return listerole;
}

QVector<Roles> Roles::listeRole()
{
    QVector<Roles> tableauRole;
    QSqlQuery query;
    Roles role;
    QString request;
    request ="select* from POSTES where status = 'actif' order by libele;";
    if(query.exec(request)){
        while(query.next()){

            role.libele = query.value(0).toString();
            role.cout = query.value(1).toFloat();
            role.temp_de_travail = query.value(2).toInt();
            role.service = query.value(3).toString();
            role.description = query.value(4).toString();
            tableauRole.push_back(role);
        }
    }else{
        qDebug()<<"erreur piang";
         qDebug()<< "erreur du a:" <<query.lastError().text();
    }
    return tableauRole;
}

bool Roles::addRole(Roles role)
{

    QSqlQuery que;
    QString request = "insert into POSTES values (:libele, :cout, :temptravail, :service, :description, actif); ";
    que.prepare(request);
    que.bindValue(":libele", role.libele);
    que.bindValue(":cout", role.cout);
    que.bindValue(":temptravail", role.temp_de_travail);
    que.bindValue(":service", role.service);
    que.bindValue(":description", role.description);
    if(que.exec()){
        return true;
    }else{
         qDebug()<< "erreur du a:" <<que.lastError().text();
         return false;
    }
}

bool Roles::suprimerRole(QString libele)
{
    QSqlQuery query;
    QString request ="update POSTES set status ='suprimer' where libele = '";
    request += libele;
    request += "' ;";
    if(query.exec(request)){
        return true;
    }else{
         qDebug()<< "erreur de supresion de role du a:" <<query.lastError().text();
         return false;
    }
}

bool Roles::modifierRole(Roles correcte)
{
    QSqlQuery query;
    QString request = "update POSTES set libele= :libele, cout = :cout, temp_de_travail = :temp, service_attacher = :service, descriptions = :desc, status = :status where libele = ";
    request += correcte.libele;
    request +=" ;";
    query.prepare(request);
    query.bindValue(":libele", correcte.libele);
    query.bindValue(":cout", correcte.cout);
    query.bindValue(":temptravail", correcte.temp_de_travail);
    query.bindValue(":service", correcte.service);
    query.bindValue(":description", correcte.description);
    if(query.exec()){
        return true;
    }else{
         qDebug()<< "erreur de modification de role du a:" <<query.lastError().text();
         return false;
    }
}

void Roles::AfficherListeRoles(QVector<Roles> t, QTableWidget *tw)
{
    if(t.isEmpty())return;
    tw->clearContents();
    int index(1);
    for(auto a: t){
        QString cou, tmp;
        cou = QString::number(a.cout);
        tmp = QString::number(a.temp_de_travail);
                tw->insertRow(index);
                tw->setItem(index,0, new  QTableWidgetItem(a.libele));
                tw->setItem(index,1, new QTableWidgetItem(cou));
                tw->setItem(index,2, new QTableWidgetItem(tmp));
                tw->setItem(index,3, new QTableWidgetItem(a.service));
                tw->setItem(index,4, new QTableWidgetItem(a.description));

                QPushButton *btn_ed, *btn_del;
                btn_ed = new QPushButton();
                btn_del = new QPushButton();
                btn_ed->setText("EDITER");
                btn_del->setText("SUPRIMER");
                QString style = "QPushButton{\n	background-color: rgb(50, 50, 50);\n	border: 2px solid rgb(60, 60, 60);\n	border-radius: 5px;\n}\nQPushButton:hover{\n	background-color: rgb(60, 60, 60);\n	border: 2px solid rgb(70, 70, 70);\n\n}\nQPushButton:pressed{\n	background-color: rgb(255, 0, 0);\n	border: 2px solid rgb(255, 0, 127);\n	color: rgb(35, 35, 35);\n\n}";
                QString style1 = "QPushButton {\n	border: 2px solid rgb(52, 59, 72);\n	border-radius: 5px;	\n	background-color: rgb(52, 59, 72);\n}\nQPushButton:hover {\n	bbackground-color: rgb(57, 65, 80);\n	\n	background-color: rgb(36, 73, 109);\n	border: 2px solid rgb(61, 70, 86);\n}\nQPushButton:pressed {	\n	bbackground-color: rgb(35, 40, 49);\n	\n	background-color: rgb(85, 255, 255);\n	border: 2px solid rgb(43, 50, 61);\n}";
                btn_ed->setStyleSheet(style1);
                btn_del->setStyleSheet(style);
                tw->setCellWidget(index,5, btn_ed);
                tw->setCellWidget(index,6, btn_del);

                index++;
                qDebug()<<"pim pim";

    }
}

Roles Roles::getprecedent(QVector<Roles> t, Roles r)
{
    Roles tmp;
    QVector<Roles>::Iterator it;
    if(t.isEmpty()) return tmp;
    for(it=t.begin(); it!=t.end(); ++it){
        if(it->getLibele() == r.getLibele() ){
            tmp =*(it-1);
            return tmp;
        }
    }
    return tmp;
}

Roles Roles::getsuivant(QVector<Roles> t, Roles r)
{
    Roles tmp;
    QVector<Roles>::Iterator it;
    if(t.isEmpty()) return tmp;
    for(it=t.begin(); it!=t.end(); ++it){
        if(it->getLibele() == r.getLibele() ){
            tmp =*(it+1);
            return tmp;
        }
    }
    return tmp;
}

QVector<QPair<QString, QList<QString> > > Roles::createlistedepartement_poste()
{
   QVector<QPair<QString, QList<QString> > > t;
    QSqlQuery query;
    QString request;

    request ="select DISTINCT service_attacher from postes;";
    if(query.exec(request)){
        while(query.next()){
            QPair<QString, QList<QString> > a;
            a.first = query.value(0).toString();
            t.push_back(a);
        }
    }else{
        qDebug()<<"erreur lors du resencement des services";
         qDebug()<< "erreur du a:" <<query.lastError().text();
         return t;
    }

    QVector<QPair<QString, QList<QString> > >::Iterator it;
    for(it = t.begin(); it!= t.end(); ++it){
        QSqlQuery quer;
        QString requeste;
        QList<QString> l;
        requeste ="select libele from postes where service_attacher = '";
        requeste += it->first;
        requeste += "';";
        if(quer.exec(requeste)){
            while(quer.next()){

                 l<<quer.value(0).toString();
            }
        }else{
            qDebug()<<"erreur lors de la creation des listes de poste du departement ";
             qDebug()<< "erreur du a:" <<quer.lastError().text();
             return t;
        }
        it->second = l;

    }
    return t;

}
