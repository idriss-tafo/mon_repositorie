#include "login.h"
#include "ui_login.h"


Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    this->ui->frame->hide();
    connect(ui->pb_valider, SIGNAL(clicked(bool)),this, SLOT(connection()));
}

Login::~Login()
{
    delete ui;
}
Comptes Login::controle_saisie(){
    Comptes c;
    c.set_id_compte(-1);
    QString stylelineediteerror = "QLineEdit{\n	border: 2px solid rgb(255, 87, 127);\n	border-radius:5px;\n	padding: 15px;\n	background-color: rgb(30, 30, 30);\n	\n	color: rgb(100, 100, 100);\n}\nQLineEdit:hover{\n	border: 2px solid rgb(55, 55, 55);\n}\nQLineEdit:focus{\n	border: 2px solid rgb(255, 0, 0);\n	color: rgb(200, 200, 205);\n}";
    QString stylelineediteerrok = "QLineEdit{\n	border: 2px solid rgb(45, 45, 45);\n	border-radius:5px;\n	padding: 15px;\n	background-color: rgb(30, 30, 30);\n	\n	color: rgb(100, 100, 100);\n}\nQLineEdit:hover{\n	border: 2px solid rgb(55, 55, 55);\n}\nQLineEdit:focus{\n	border: 2px solid rgb(255, 0, 0);\n	color: rgb(200, 200, 205);\n}";


    QString user = "";
    QString password = "";
    QString text;
    if(this->ui->lineEdit_login->text().isEmpty()){
        user= "user empty";
        this->ui->frame->setStyleSheet(styleframeerror);
        this->ui->lineEdit_login->setStyleSheet(stylelineediteerror);
    }else{
       user= "";
       this->ui->lineEdit_login->setStyleSheet(stylelineediteerrok);
    }
    if(this->ui->lineEdit_password->text().isEmpty()){
        password= "password empty";
        this->ui->frame->setStyleSheet(styleframeerror);
        this->ui->lineEdit_password->setStyleSheet(stylelineediteerror);
    }else{
       password= "";
       this->ui->lineEdit_password->setStyleSheet(stylelineediteerrok);
    }
    if(user!="" || password!=""){
        text +=user + " " + password;
        affiche_message(text);
        return c; //return 1 si il ya des erreurs
    }else{
        text = "Mots de passe ou login incorrect";
        c=verification_de_donnee();
        if(c.get_id_compte()!=-1){
            text = "login oK";
            if(this->ui->checkBox->isChecked()){
                text += " | Saver user: OK";

            }
            this->ui->frame->setStyleSheet(styleframeok);
            affiche_message(text);
            qDebug()<<"lid connecter est:"<<c.get_id_compte();
            return c; //return 0 si pas d'erreur
        }

        affiche_message(text);
        return c; //return 1 si bourré d'erreur
    }
}

void Login::affiche_message(QString m){

    this->ui->frame->show();
    this->ui->label_error->setText(m);
}

void Login::connection(){
    Employers e; Roles r; Comptes c;
    c= controle_saisie();
    if(c.get_id_compte() !=-1 ){
        if(c.get_login()=="root"){
            this->fenetre.show();
            this->close();
            fenetre.setlisteEmployers(e.listeEmployer());
            fenetre.setlisteRoles(r.listeRole());
            fenetre.setListeDespostes_et_nbEmployers( e.groupeEmployer_par_poste());
            fenetre.setListeDesdepartements(r.createlistedepartement_poste());
            fenetre.setListeSeriesGeneral();
            e.AfficheListeEmployer(fenetre.getlisteEmployers(),fenetre.getui()->tableWidget);
            r.AfficherListeRoles(fenetre.getlisteRoles(), fenetre.getui()->tableWidget_2);
            fenetre.choix_des_postes();
            fenetre.makeStat();
        }
        else if(c.get_login() == "mohamedali"){
            this->hygene.show();
            this->close();
        }


        /*QList<QString> liste;
        liste <<"id_personne" <<"nom" <<"prenom"<<"sexe"<<"poste"<<"email"<<"id_carte"<<"statut_matrimonial"<<"date_naissance"<<"date_embauche";
        fenetre.selection_multiple("PERSONNES", liste, fenetre.getui()->tableWidget, "nom");
        liste.clear();
        liste<<"libele"<<"cout"<<"temp_de_travail"<<"service_attacher"<<"descriptions";
        fenetre.selection_multiple("POSTES", liste, fenetre.getui()->tableWidget_2, "libele");*/

    }
}

Comptes Login:: verification_de_donnee(){
    Comptes c ;
    QString login;
    QString passwd;
    QByteArray mpd;
    QByteArray mpd_sha;
    QString mpd_crypter;
    QSqlQuery query;
    passwd =this->ui->lineEdit_password->text();
    mpd = passwd.toUtf8();

    mpd_sha= QCryptographicHash::hash(mpd, QCryptographicHash::Sha256);
    mpd_crypter= mpd_sha.toHex();
    QString requette = "select ID_COMPTE, LOGIN, MOT_DE_PASSE from COMPTES where LOGIN = :login and MOT_DE_PASSE = :passwd";

    QSqlQuery request;
        request.prepare(requette);
        request.bindValue(":login", this->ui->lineEdit_login->text());
        request.bindValue(":passwd", mpd_crypter);
        c.set_id_compte(-1);
        if(request.exec()){
            while(request.next()){
            c.set_id_compte(request.value(0).toInt());
            c.set_login(request.value(1).toString());

            }
            qDebug()<<c.get_id_compte()<<c.get_login();
            return c;
        }else return c;

}
