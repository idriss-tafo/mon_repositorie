#include "fenetre.h"
Framelabelbtn::Framelabelbtn(QWidget* parent) :
    QFrame(parent){
    
}

void Framelabelbtn::mouseDoubleClickEvent(){
    emit Mouse_DoubleClick();
}

Fenetre::Fenetre(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Fenetre), notifie(new func_notification(this))
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/idris/Documents/qt/eye_of_god/resource/images/avatar.png");

    ui->label_img_profil->setPixmap(pix.scaled(120,120,Qt::KeepAspectRatio));
    ui->label_img_profil->installEventFilter(this);
    connect(this, SIGNAL(doubleclicIMG()), this, SLOT(changeimageprofil()));
    listechamp_personne <<"nom" <<"prenom" <<"sexe";
    int return_arduino = this->arduino.connect_arduino();
    switch (return_arduino) {
    case(0):qDebug()<< "arduino est active et est connecte a :" <<this->arduino.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino est active mais pas connecte a :" <<this->arduino.getarduino_port_name();
        break;
    case(-1):qDebug() << "arduino n'est pas active";
    }
    /* etat initial d'objets*/
QString stylecombo = "color: rgb(80, 80, 80);";
    this->ui->frame->hide();
    this->ui->frame_error_poste->hide();
    this->ui->frame_error_recherche->hide();
    this->ui->lineEdit_login->setEnabled(false);
    this->ui->lineEdit_passwd->setEnabled(false);
    this->ui->lineEdit_passwd_2->setEnabled(false);
    this->ui->lineEdit_identifiant->setEnabled(false);
    this->ui->comboBox_date->setEnabled(false);
    this->ui->comboBox_date->setStyleSheet(stylecombo);
    this->ui->dateEdit_first->setEnabled(false);
    this->ui->dateEdit_first->setStyleSheet("color: rgb(80, 80, 80);");
    this->ui->dateEdit_second->setEnabled(false);
    this->ui->dateEdit_second->setStyleSheet("color: rgb(80, 80, 80);");

    /* les differentes connections. */
    connect(this->ui->pushButton_toggle, SIGNAL(clicked(bool)), this,SLOT(togglemenu()));
    connect(this->ui->pushButton_accueil, SIGNAL(clicked()), this,SLOT(setcurrentpageacceueil() ));
    connect(this->ui->pushButton_addposte, SIGNAL(clicked()), this,SLOT(setcurrentpagedachbord()));
    connect(this->ui->pushButton_menuposte, SIGNAL(clicked(bool)), this,SLOT(setcurrentpagehistory()));
    connect(this->ui->pushButton_adduser, SIGNAL(clicked(bool)), this,SLOT(setcurrentpagadduser()));
    connect(this->ui->pushButton_config, SIGNAL(clicked(bool)), this,SLOT(setcurrentpageconf()));
    connect(this->ui->pushButton_reglage, SIGNAL(clicked(bool)), this,SLOT(setcurrentpagereglage()));
    connect(this->arduino.getserial(),SIGNAL(readyRead()), this, SLOT(check_available()));
    /*statistique*/
   setlistecolor();
   //listeDespostes_et_nbEmployers= employer.groupeEmployer_par_poste();
   //listeDesdepartements= rol.createlistedepartement_poste();
   //setListeSeriesGeneral();




    QBarSet *set0 = new QBarSet("altuve");
    QBarSet *set1 = new QBarSet("martinez");
    QBarSet *set2 = new QBarSet("segura");
    QBarSet *set3 = new QBarSet("Simmons");
    QBarSet *set4 = new QBarSet("trout");

    *set0 <<10 << 25 << 76 << 46 << 10 <<56;
    *set1 <<33 << 51 << 20 << 43 << 11 <<125;
    *set2 <<45 << 100 << 92 << 83 << 46 <<20;
    *set3 <<72 << 14 << 38 << 76 << 85 <<75;
    *set4 <<86 << 42 << 42 << 56 << 15 <<86;

    QBarSeries *serie = new QBarSeries();
    serie->append(set0);
    serie->append(set1);
    serie->append(set2);
    serie->append(set3);
    serie->append(set4);


    chart->addSeries(serie);
    chart->setTitle("diagramme a baton");
    chart->setAnimationOptions(QChart::AllAnimations);

    QStringList categorie;
    categorie << "2013" << "2014" << "2015" << "2016" << "2017" << "2018";
    QBarCategoryAxis *axisX = new QBarCategoryAxis();

    axisX->append(categorie);
    //chart->createDefaultAxes();
    chart->addAxis(axisX, Qt::AlignBottom);
    serie->attachAxis(axisX);

    QValueAxis *axisY= new QValueAxis();
    axisY->setRange(0,150);
    chart->addAxis(axisY, Qt::AlignLeft);
    serie->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);


    QChartView *chartview = new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setParent(ui->frame_cercle1_2);
   /* QPalette pal = qApp->palette();
    pal.setColor(QPalette::Window, QRgb(0x9999ff));
    pal.setColor(QPalette::WindowText, QRgb(0x404040));
    qApp->setPalette(pal);*/

    ui->horizontalLayout_chart->addWidget(chartview);

    /* pie chart*/

    QPieSeries *pserie = new QPieSeries();
    pserie ->append("Administration", .2);
    pserie ->append("hygene et salubrite", .18);
    pserie ->append("energie", .20);
    pserie ->append("transport", .40);
    pserie ->append("logement", .8);
    pserie ->append("etude projet", .12);

    QPieSlice *slice, *slice1, *slice2, *slice3, *slice4, *slice5;
    slice = pserie->slices().at(0);
    slice->setLabelVisible();
    slice->setPen(QPen(Qt::darkBlue, 2));
    slice->setBrush(Qt::blue);

    slice1 = pserie->slices().at(1);
    slice1->setExploded();
    slice1->setLabelVisible();

    slice2 = pserie->slices().at(2);
    slice2->setLabelVisible();

    slice3 = pserie->slices().at(3);
    slice3->setLabelVisible();

    slice4 = pserie->slices().at(4);
    slice4->setLabelVisible();

    slice5 = pserie->slices().at(5);
    slice5->setLabelVisible();




    pchar->addSeries(pserie);
    pchar->setTitle("diagramme a circulaire");
    pchar->setAnimationOptions(QChart::AllAnimations);
    pchar->legend()->hide();

    QChartView *pchartview = new QChartView(pchar);
    pchartview->setRenderHint(QPainter::Antialiasing);
    pchartview->setParent(ui->frame_cercle2_2);

    ui->gridLayout_pie->addWidget(pchartview);


    //selection_multiple("PERSONNES", liste, ui->tableWidget, "nom");

}

Fenetre::~Fenetre()
{
    delete ui;
}

void Fenetre::togglemenu(){
    int maxwidth = 200;
    bool enable = true;
    if(enable){
        int width, maxextend, standard, widthextended;
        width = this->ui->menu_gauche->width();
        maxextend = maxwidth;
        standard = 70;
        if(width == standard){
            widthextended = maxextend;
            this->ui->pushButton_accueil->setText(" Accueil");
            this->ui->pushButton_adduser->setText(" Add user");
            this->ui->pushButton_config->setText(" Configuration");
            this->ui->pushButton_menuposte->setText(" gestion de poste ");
            this->ui->pushButton_addposte->setText(" add poste");
            this->ui->pushButton_reglage->setText(" Reglage");
        }
        else{
            widthextended = standard;
            this->ui->pushButton_accueil->setText("");
            this->ui->pushButton_adduser->setText("");
            this->ui->pushButton_config->setText("");
            this->ui->pushButton_menuposte->setText("");
            this->ui->pushButton_addposte->setText("");
            this->ui->pushButton_reglage->setText("");
        }
        this->animation = new QPropertyAnimation(this->ui->menu_gauche, "minimumWidth");
        this->animation->setDuration(400);
        this->animation->setStartValue(width);
        this->animation->setEndValue(widthextended);
        this->animation->setEasingCurve(QEasingCurve::InOutQuad);
        this->animation->start();
    }
}

void Fenetre::setcurrentpageacceueil(){
    this->ui->pages->setCurrentWidget(this->ui->page);
    chart->setAnimationOptions(QChart::NoAnimation);
    pchar->setAnimationOptions(QChart::NoAnimation);


}
void Fenetre::setcurrentpagehistory(){
    this->ui->pages->setCurrentWidget(this->ui->page_2);

    chart->setAnimationOptions(QChart::AllAnimations);
    pchar->setAnimationOptions(QChart::AllAnimations);

    qDebug("is meee");
}
void Fenetre::setcurrentpagedachbord(){
    this->ui->pages->setCurrentWidget(this->ui->page_3);
    chart->setAnimationOptions(QChart::NoAnimation);
    pchar->setAnimationOptions(QChart::NoAnimation);

}
void Fenetre::setcurrentpagadduser(){
    this->ui->pages->setCurrentWidget(this->ui->page_4);
            chart->setAnimationOptions(QChart::NoAnimation);
            pchar->setAnimationOptions(QChart::NoAnimation);
            QPixmap pix("C:/Users/idris/Documents/qt/eye_of_god/resource/images/avatar.png");

            ui->label_img_profil->setPixmap(pix.scaled(120,120,Qt::KeepAspectRatio));
            this->ui->lineEdit_identifiant->clear();
             this->ui->lineEdit_nom->clear();
             this->ui->lineEdit_prenom->clear();
             this->ui->lineEdit_appartement->clear();
             this->ui->lineEdit_cni->clear();
             this->ui->lineEdit_email->clear();
             this->ui->lineEdit_idcarte->clear();
             this->ui->lineEdit_login->clear();
             this->ui->lineEdit_numtelephone->clear();
             this->ui->lineEdit_residence->clear();
             this->ui->lineEdit_quartier->clear();
             this->ui->lineEdit_passwd_2->clear();
            this->ui->lineEdit_passwd->clear();
            QDate date;
            date = date.currentDate();
            this->ui->dateEdit_dateembauche->setDate(date);
}
void Fenetre::setcurrentpageconf(){
    this->ui->pages->setCurrentWidget(this->ui->page_5);
}
void Fenetre::setcurrentpagereglage(){
    this->ui->pages->setCurrentWidget(this->ui->page_6);
}

QString Fenetre::deselectmenu(QString getstyle){
    QString deselect;
    deselect = getstyle.replace("QPushButton { border-right: 7px solid rgb(44, 49, 60); }", "");
    return deselect;
}


QString Fenetre::selectmenu(QString getstyle){
    QString select;
    select = getstyle + ("QPushButton { border-right: 7px solid rgb(44, 49, 60); }");
    return select;
}


void Fenetre::selectmenustandard(QString widget){
    QString a;
    for ( QPushButton *w : this->ui->menu_gauche->findChildren<QPushButton *>() ){
        if(w->objectName() == widget){
            a=w->styleSheet();
            w->setStyleSheet(selectmenu(a));
        }
    }
}

void Fenetre::resetstyle(QString widget){
    
    for ( QPushButton *w : this->ui->menu_gauche->findChildren<QPushButton *>() ){
        if(w->objectName() != widget){
            w->setStyleSheet(deselectmenu(w->styleSheet()));
        }
    }
}


void Fenetre::maximize_restore(){
    bool status;
    status= this->ETAT_GLOBAL;
    if(status){
        this->showMaximized();
        this->ETAT_GLOBAL= true;
        this->ui->horizontalLayout->setContentsMargins(0, 0, 0, 0);
        this->ui->pb_maximize->setToolTip("Restore");
        this->ui->pb_maximize->setIcon(QIcon(":/icon/resource/icon/20x20/cil-window-restore.png"));
        this->ui->top_menu->setStyleSheet("background-color: rgb(27, 29, 35)");
        this->ui->frame_4->hide();
        
    }else{
        this->showNormal();
        this->ETAT_GLOBAL= false;
        this->resize(this->width()+1, this->height()+1);
        this->ui->horizontalLayout->setContentsMargins(10, 10, 10, 10);
        this->ui->pb_maximize->setToolTip("Maximize");
        this->ui->pb_maximize->setIcon(QIcon(":/icon/resource/icon/20x20/cil-window-maximize.png"));
        this->ui->top_menu->setStyleSheet("background-color: rgba(27, 29, 35, 200)");
        this->ui->frame_4->show();
    }
}


void Fenetre::enableMaximumSize(int width, int height){
    if((width != 1500) && (height != 800)){
        this->setMaximumSize(QSize(width, height));
        this->ui->frame_4->hide();
        this->ui->pb_maximize->hide();
    }
}


void Fenetre::doubleclicmaximizerestore(QEvent *event){
    
    if(event->type() == QEvent::MouseButtonDblClick){ 
         QTimer:: singleShot(250, this, SLOT(maximize_restore()));
    }
   
}
void Fenetre::definitionfenetre(){
    
    if(this->TITLE_BAR){
        
        this->setWindowFlag(Qt::FramelessWindowHint);
        this->setAttribute(Qt::WA_TranslucentBackground);
       
        //doubleclicmaximizerestore(Framelabelbtn::mouseDoubleClickEvent(event));
        
    }else{
        this->ui->horizontalLayout->setContentsMargins(0, 0, 0, 0);
        this->ui->frame_label_2->setContentsMargins(8, 0, 0, 5);
        this->ui->frame_label_2->setMinimumHeight(42);
        this->ui->frame_icon->hide();
        this->ui->frame_haut_droit->hide();
        this->ui->frame_4->hide();


    }

    this->shadow->setBlurRadius(17);
    this->shadow->setXOffset(0);
    this->shadow->setYOffset(0);
    this->shadow->setColor(QColor(0,0,0,150));
    this->ui->contenu->setGraphicsEffect(this->shadow);
    this->sizegrip = new QSizeGrip(this->ui->frame_4);
    this->sizegrip->setStyleSheet("width: 20px; height: 20px; margin 0px; padding: 0px;");

    connect(this->ui->pb_minimize, SIGNAL(Clicked),this, SLOT(this->showMinimized()));
    connect(this->ui->pb_maximize, SIGNAL(Clicked), this ,SLOT(maximize_restore()));
    connect(this->ui->pb_close, SIGNAL(Clicked), this, SLOT(this->close()));


}


/*  ajout de users avec controle de saisie*/

int Fenetre::Adduser_controle_saisie(){
    QString stylelineediteerror = "QLineEdit{\n	border: 2px solid rgb(255, 87, 127);\n	border-radius:5px;\n	padding: 15px;\n	background-color: rgb(30, 30, 30);\n	\n	color: rgb(100, 100, 100);\n}\nQLineEdit:hover{\n	border: 2px solid rgb(55, 55, 55);\n}\nQLineEdit:focus{\n	border: 2px solid rgb(255, 0, 0);\n	color: rgb(200, 200, 205);\n}";
    QString stylelineediteerrok = "QLineEdit{\n	border: 2px solid rgb(45, 45, 45);\n	border-radius:5px;\n	padding: 15px;\n	background-color: rgb(30, 30, 30);\n	\n	color: rgb(100, 100, 100);\n}\nQLineEdit:hover{\n	border: 2px solid rgb(55, 55, 55);\n}\nQLineEdit:focus{\n	border: 2px solid rgb(255, 0, 0);\n	color: rgb(200, 200, 205);\n}";


    QString nom = "";
    QString prenom = "";
    QString email = "";

    QString user = "";
    QString passwd = "";

    QString idcart = "";
    QString text;
    Employers employer;
    if(this->ui->lineEdit_nom->text().isEmpty()){
        nom= "name empty";
        this->ui->frame->setStyleSheet(styleframeerror);
        this->ui->lineEdit_nom->setStyleSheet(stylelineediteerror);
    }else{
       nom= "";
       this->ui->lineEdit_nom->setStyleSheet(stylelineediteerrok);
    }
    if(this->ui->lineEdit_prenom->text().isEmpty()){
        prenom= "prenom empty";
        this->ui->frame->setStyleSheet(styleframeerror);
        this->ui->lineEdit_prenom->setStyleSheet(stylelineediteerror);
    }else{
       prenom= "";
       this->ui->lineEdit_prenom->setStyleSheet(stylelineediteerrok);
    }
    if(this->ui->lineEdit_idcarte->text().isEmpty()){
        idcart= "id cart empty";
        this->ui->frame->setStyleSheet(styleframeerror);
        this->ui->lineEdit_idcarte->setStyleSheet(stylelineediteerror);
    }else{
       idcart= "";
       this->ui->lineEdit_idcarte->setStyleSheet(stylelineediteerrok);
    }
    if(this->ui->lineEdit_email->text().isEmpty()){
        email= "email empty";
        this->ui->frame->setStyleSheet(styleframeerror);
        this->ui->lineEdit_email->setStyleSheet(stylelineediteerror);
    }else{
        if(emailIsValide(this->ui->lineEdit_email->text())){
            email= "";
            this->ui->lineEdit_email->setStyleSheet(stylelineediteerrok);
        }else{
            email= "email non valide";
            this->ui->frame->setStyleSheet(styleframeerror);
            this->ui->lineEdit_email->setStyleSheet(stylelineediteerror);
        }

    }

    if(nom!="" || prenom!="" || idcart != "" || email != ""){
        text +=nom + " " + prenom + " " + idcart + " " + email;
        affiche_message(text, (ui->frame), this->ui->label_error);
        return 1; //return 1 si il ya des erreurs
    }else{
        QSqlQuery que;

        employer.setNom( this->ui->lineEdit_nom->text());
        employer.setPrenom( this->ui->lineEdit_prenom->text());
        employer.setId_carte( this->ui->lineEdit_idcarte->text());
        employer.setEmail( this->ui->lineEdit_email->text());
        employer.setSexe( this->ui->comboBox_sexe->currentText());
        employer.setPoste( this->ui->comboBox_poste->currentText());
        employer.setStatus( this->ui->comboBox_statu_matrimonial->currentText());
        employer.setDate_naissance( this->ui->dateEdit_datenaissance->date());
        employer.setDate_embauche( this->ui->dateEdit_dateembauche->date());
        employer.setName_profil(this->file);

        this->file.clear();
        if(this->ui->checkBox_compte->isChecked()){
            Comptes compte;
            this->ui->lineEdit_login->setEnabled(true);
            this->ui->lineEdit_passwd->setEnabled(true);
            this->ui->lineEdit_passwd_2->setEnabled(true);

            compte.set_login(this->ui->lineEdit_login->text());
            compte.set_motdepasse(this->ui->lineEdit_passwd->text());
            if(compte.addcompte()){

               text += " | Compte creat: OK";
            }
        }
        if(employer.adduser()){
            text = "user ajouter avec succés ";
            qDebug() << "i am";


            qDebug()<< "debut envoie mail";
            QString subject = "VALIDATION DE COMPTE";
            QString content = "E Y E  O F  G O D  demande la validation de votre compte en cliquant sur ce lien";
            this->CompteGoogle.setAddresse("eyeofgod237@gmail.com");
            this->CompteGoogle.setPasswd("96250011");
            AdresseEmail from("eyeofgod237@gmail.com");
            AdresseEmail to(this->ui->lineEdit_email->text());
            Email email(this->CompteGoogle,from,to,subject,content);
            this->client = new Smtpclient("smtp.gmail.com");
            connect(this->client, SIGNAL(status(Status::e,QString)),this, SLOT(onstatus(Status::e, QString)), Qt::UniqueConnection);
            this->client->envoiEmail(email);
            qDebug()<< "fin envoie mail";
            this->listeEmployers= employer.listeEmployer();
            this->ui->frame->setStyleSheet(styleframeok);
            affiche_message(text, (ui->frame), this->ui->label_error);
            return 0; //return 0 si pas d'erreur
        }else{
            text = "erreur !!! consulte la console ";
            qDebug()<< "erreur du a:" <<que.lastError().text();
            affiche_message(text, (ui->frame), this->ui->label_error);
            return 1; //return 1 si il y'a des erreurs

        }

    }
}

/* ajout de poste avec controle de saisie*/

int Fenetre::Addposte_controle_saisie(){
    QString stylelineediteerror = "QLineEdit{\n	border: 2px solid rgb(255, 87, 127);\n	border-radius:5px;\n	padding: 15px;\n	background-color: rgb(30, 30, 30);\n	\n	color: rgb(100, 100, 100);\n}\nQLineEdit:hover{\n	border: 2px solid rgb(55, 55, 55);\n}\nQLineEdit:focus{\n	border: 2px solid rgb(255, 0, 0);\n	color: rgb(200, 200, 205);\n}";
    QString stylelineediteerrok = "QLineEdit{\n	border: 2px solid rgb(45, 45, 45);\n	border-radius:5px;\n	padding: 15px;\n	background-color: rgb(30, 30, 30);\n	\n	color: rgb(100, 100, 100);\n}\nQLineEdit:hover{\n	border: 2px solid rgb(55, 55, 55);\n}\nQLineEdit:focus{\n	border: 2px solid rgb(255, 0, 0);\n	color: rgb(200, 200, 205);\n}";


    QString libele = "";
    QString cout = "";

    QString service = "";
    QString description = "";

    QString text;
    if(this->ui->lineEdit_libelepost->text().isEmpty()){
        libele= "libele empty";
        this->ui->frame_error_poste->setStyleSheet(styleframeerror);
        this->ui->lineEdit_libelepost->setStyleSheet(stylelineediteerror);
    }else{
       libele= "";
       this->ui->lineEdit_libelepost->setStyleSheet(stylelineediteerrok);
    }
    if(this->ui->lineEdit_cout->text().isEmpty()){
        cout= "cout empty";
        this->ui->frame_error_poste->setStyleSheet(styleframeerror);
        this->ui->lineEdit_cout->setStyleSheet(stylelineediteerror);
    }else{
       cout= "";
       this->ui->lineEdit_cout->setStyleSheet(stylelineediteerrok);
    }

    if(this->ui->textEdit_desc_poste->toPlainText().isEmpty()){
        description= "description empty";
        this->ui->frame_error_poste->setStyleSheet(styleframeerror);
        this->ui->textEdit_desc_poste->setStyleSheet(stylelineediteerror);
    }else{
       description= "";
       this->ui->textEdit_desc_poste->setStyleSheet(stylelineediteerrok);
    }

    if(libele!="" || cout!="" || service != "" || description != ""){
        text +=libele + " " + cout + " " + description;
        affiche_message(text, (ui->frame_error_poste), this->ui->label_error_poste);
        return 1; //return 1 si il ya des erreurs
    }else{
        int cou, temp;
        cou = this->ui->lineEdit_cout->text().toInt();
        temp = this->ui->lineEdit_temptravail->text().toInt();
        QSqlQuery que;
        QString request = "insert into POSTES values (:libele, :cout, :temptravail, :service, :description); ";
        que.prepare(request);
        que.bindValue(":libele", this->ui->lineEdit_libelepost->text());
        que.bindValue(":cout", cou);
        que.bindValue(":temptravail", temp);
        que.bindValue(":service", this->ui->comboBox_service->currentText());
        que.bindValue(":description", this->ui->textEdit_desc_poste->toPlainText());
        if(que.exec()){
             text = "poste ajouter avec succés ";

             this->ui->frame_error_poste->setStyleSheet(styleframeok);
             affiche_message(text, (ui->frame_error_poste), this->ui->label_error_poste);
             /*reinitialisation de l'interface*/

             this->ui->lineEdit_libelepost->setText("");
             this->ui->lineEdit_cout->setText("");
             this->ui->lineEdit_temptravail->clear();
             this->ui->comboBox_poste->setCurrentIndex(0);

             return 0; //return 0 si pas d'erreur
        }else{
            text = "erreur !!! consulte la console ";
            qDebug()<< "erreur du a:" <<que.lastError().text();
            affiche_message(text, (ui->frame_error_poste), this->ui->label_error_poste);
            return 1; //return 1 si il y'a des erreurs
        }

    }
}

/* affiche message*/
void Fenetre::affiche_message(QString m, QFrame* frame, QLabel* lab){

    frame->show();
    lab->setText(m);
}

void Fenetre::on_pb_close_pup_10_clicked()
{
    int retour;
    retour = Adduser_controle_saisie();
    //selection_multiple("PERSONNES", listechamp_personne, ui->tableWidget, "nom");
    if(retour == 0){
        /*notifier*/


            this->notifie->notifier("user ajouter avec succes", []()
            {
                qDebug() << "A great action";
            }, 16);


        QList<QString> liste;
        this->ui->tableWidget->clearContents();
        liste <<"id_personne" <<"nom" <<"prenom"<<"sexe"<<"poste"<<"email"<<"id_carte"<<"statut_matrimonial"<<"date_naissance"<<"date_embauche";
        selection_multiple("PERSONNES", liste, getui()->tableWidget, "nom");
        qDebug()<< "aucune erreur";
    }
    if(retour == 1){
        qDebug()<< "bourrer d'erreurs";
    }
}

void Fenetre::stat_baton(){
  /*  QBarSet *set0 = new QBarSet("altuve");
    QBarSet *set1 = new QBarSet("martinez");
    QBarSet *set2 = new QBarSet("segura");
    QBarSet *set3 = new QBarSet("Simmons");
    QBarSet *set4 = new QBarSet("trout");

    *set0 <<283 << 341 << 313 << 338 << 346 <<335;
    *set1 <<250 << 315 << 282 << 307 << 303 <<325;
    *set2 <<260 << 385 << 382 << 107 << 103 <<225;
    *set3 <<248 << 244 << 265 << 281 << 278 <<313;
    *set4 <<323 << 287 << 299 << 315 << 306 <<313;

    QBarSeries *serie = new QBarSeries();
    serie->append(set0);
    serie->append(set1);
    serie->append(set2);
    serie->append(set3);
    serie->append(set4);

    QChart *chart = new QChart();
    chart->addSeries(serie);
    chart->setTitle("diagramme a baton");
    chart->setAnimationOptions(QChart::AllAnimations);

    QStringList categorie;
    categorie << "2013" << "2014" << "2015" << "2016" << "2017" << "2018";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categorie);
    chart->createDefaultAxes();
    chart->setAxisX(axis, serie);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);


    QChartView *chartview = new QChartView;
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setParent(ui->frame_cercle1_2);
    QPalette pal = qApp->palette();
    pal.setColor(QPalette::Window, QRgb(0xffffff));
    pal.setColor(QPalette::WindowText, QRgb(0x404040));
    qApp->setPalette(pal);

*/

}

void Fenetre::choix_des_postes()
{
    QSqlQuery query;
    QString request;
    request = "select LIBELE from POSTES order by LIBELE;";
    if(query.exec(request)){
    qDebug()<<"aaaaaaaaaaaaaa";
        while(query.next()){
            this->ui->comboBox_poste->addItem(query.value(0).toString());
        }
    }
}

Ui::Fenetre *Fenetre::getui()
{
    return this->ui;
}

void Fenetre::setlisteEmployers(QVector<Employers> t)
{
    this->listeEmployers =t;
}

void Fenetre::setlisteRoles(QVector<Roles> t)
{
    this->listeRoles = t;
}

QVector<Employers> Fenetre::getlisteEmployers()
{
    return this->listeEmployers;
}

QVector<Roles> Fenetre::getlisteRoles()
{
    return this->listeRoles;
}

void Fenetre::makeStat()
{
    QVector<QPieSeries*> ::Iterator it;
    QVector<QPair<QString, QList<QString>>> ::Iterator jt;
    jt = listeDesdepartements.begin();
    for(it = this->listeSerieGenerale.begin(); it!= this->listeSerieGenerale.end(); ++it){
        *it = new QPieSeries();
        //qDebug()<<jt->first;
        (*it)->setName(jt->first);
        for(auto a :jt->second){
            QVector<QPair<QString, int>> ::Iterator xt;
            for (xt = listeDespostes_et_nbEmployers.begin(); xt!= listeDespostes_et_nbEmployers.end(); ++xt) {
                //qDebug()<<a<<"-->"<<xt->first;
                if (xt->first == a){
                    (*it)->append(a,xt->second);
                }
            }


        }
        ++jt;
    }

    DonutBreakdownChart *donutBreakdown = new DonutBreakdownChart();
    donutBreakdown->setAnimationOptions(QChart::AllAnimations);
    donutBreakdown->setTitle("Etude sur le nombre d'employer par departement et poste");
    donutBreakdown->legend()->setAlignment(Qt::AlignRight);
    QVector<QColor>::Iterator ct;
    ct= listecolors.begin();
    int i(0);
    qDebug()<<" jarrive tres bien ici";
    for(it = this->listeSerieGenerale.begin(); it!= this->listeSerieGenerale.end(); ++it){
        donutBreakdown->addBreakdownSeries(*it, *ct);
        //qDebug()<<i<<" fois";
        ++ct;
        i++;
    }
    qDebug()<<" jarrive aussi bien ici";
    QChartView *chartView = new QChartView(donutBreakdown);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->verticalLayout_15->addWidget(chartView);

}

void Fenetre::setlistecolor()
{
    listecolors.push_back(Qt::red);
    listecolors.push_back(Qt::darkGreen);
    listecolors.push_back(Qt::blue);
    listecolors.push_back(Qt::yellow);
    listecolors.push_back(Qt::green);
    listecolors.push_back(Qt::darkBlue);
    listecolors.push_back(Qt::magenta);
    listecolors.push_back(Qt::darkRed);
}

void Fenetre::setListeSeriesGeneral()
{
    listeSerieGenerale.clear();
    QVector<QPair<QString, QList<QString>>>:: Iterator it;
    for (it= listeDesdepartements.begin(); it != listeDesdepartements.end() ; ++it) {
        QPieSeries* a;
        listeSerieGenerale.push_back(a);

    }
}

void Fenetre::setListeDespostes_et_nbEmployers(QVector<QPair<QString, int> > t)
{
    listeDespostes_et_nbEmployers= t;
}

void Fenetre::setListeDesdepartements(QVector<QPair<QString, QList<QString> > > t)
{
    listeDesdepartements = t;
}

QString Fenetre::makeRequestForEmployer()
{
    QString text ="", request = "", rech = "", nom ="", typedate = "", operateur ="";
    QDate date1, date2;
    QString stylelineediteerror = "QLineEdit {\n	background-color: rgb(250, 0, 0);\n	border-radius: 5px;\n	border: 2px solid rgb(27, 29, 35);\n	padding-left: 10px;\n}\nQLineEdit:hover {\n	border: 2px solid rgb(64, 71, 88);\n}\nQLineEdit:focus {\n	border: 2px solid rgb(91, 101, 124);\n}";
    QString stylelineediteerrok = "QLineEdit {\n	background-color: rgb(27, 29, 35);\n	border-radius: 5px;\n	border: 2px solid rgb(27, 29, 35);\n	padding-left: 10px;\n}\nQLineEdit:hover {\n	border: 2px solid rgb(64, 71, 88);\n}\nQLineEdit:focus {\n	border: 2px solid rgb(91, 101, 124);\n}";

    if(!this->ui->lineEdit->text().isEmpty()){
        rech =this->ui->lineEdit->text();
        if(this->ui->comboBox->currentText() == "IDENTIFIANT"){
            nom = "id_personne";
        }else{
        nom = this->ui->comboBox->currentText();
        }
    }
    if(this->ui->comboBox_autres_critere->currentText() != "Autres Critères"){
        if(this->ui->comboBox_autres_critere->currentText() == "Date Naissance"){
            typedate= "date_naissance";
        }else{
             typedate= "date_embauche";
        }
    }
    if(this->ui->comboBox_date->currentText() == "Date égale à"){
        operateur ="=";
        date1 = this->ui->dateEdit_first->date();
    }else if(this->ui->comboBox_date->currentText() == "Date superieur à" ){
        operateur = ">";
        date1 = this->ui->dateEdit_first->date();
    }else if(this->ui->comboBox_date->currentText() == "Date inferieur à"){
        operateur = "<";
        date1 = this->ui->dateEdit_first->date();
    }else if(this->ui->comboBox_date->currentText() == "Date Compris entre"){
        if(this->ui->dateEdit_first->date() > this->ui->dateEdit_second->date()){
            text = "erreur de comparaison";
        }else{
          operateur = "between";
          date1 = this->ui->dateEdit_first->date();
          date2 = this->ui->dateEdit_second->date();
        }

    }else{
        if(this->ui->dateEdit_first->date() > this->ui->dateEdit_second->date()){
            text = "erreur de comparaison";
        }else{
          operateur = "not between";
          date1 = this->ui->dateEdit_first->date();
          date2 = this->ui->dateEdit_second->date();
        }
    }
    if(text != ""){
        this->ui->frame_error_recherche->show();
        this->ui->dateEdit_first->setStyleSheet("color: rgb(250, 0, 0);");
        ui->frame_error_recherche->setStyleSheet(styleframeerror);
        affiche_message(text, (ui->frame_error_recherche), this->ui->label_error_recherche);
        return request;
    }
    if(rech =="" && typedate == ""){
        text = "seach empty ! ! !";
        this->ui->frame_error_recherche->show();
        ui->frame_error_recherche->setStyleSheet(styleframeerror);
        return request;
    }else if(typedate == ""){
        request = "select* from personnes where ";
        request +=nom;
        request +=" = ";
        request += ":rech";
        request += ";";
    }else if(rech == ""){
        request = "select* from personnes where ";
        request += typedate;
        request += " ";
        request += operateur;
        if(operateur != "between" && operateur != "not between"){
          request += " :date1 ;";
        }else{
           request += " :date1 and :date2);";
        }


    }else{
        request = "select* from personnes where ";
        request +=nom;
        request +=" = ";
        request += ":rech and ( ";
        request += typedate;
        request += " ";
        request += operateur;
        if(operateur != "between" && operateur != "not between"){
          request += " :date1 ;";
        }else{
           request += " :date1 and :date2);";
        }

    }
    text = "requette valide";
    affiche_message(text, (ui->frame_error_recherche), this->ui->label_error_recherche);
    this->ui->frame_error_recherche->show();
    ui->frame_error_recherche->setStyleSheet(styleframeok);
    this->ui->dateEdit_first->setStyleSheet("");
    return request;

}


void Fenetre::on_pb_save_postebd_clicked()
{
    int retour;
    retour = Addposte_controle_saisie();
    choix_des_postes();
    if(retour == 0){
        QList<QString> liste;
        /*notifier*/


            this->notifie->notifier("poste ou role ajouter avec success", []()
            {
                qDebug() << "A great action";
            }, 16);


        this->ui->tableWidget_2->clear();
        liste<<"libele"<<"cout"<<"temp_de_travail"<<"service_attacher"<<"descriptions";
        selection_multiple("POSTES", liste, getui()->tableWidget_2, "libele");


        qDebug()<< "aucune erreur";
    }
    if(retour == 1){
        qDebug()<< "bourrer d'erreurs";
    }
}

void Fenetre::onstatus(Status::e status, QString errorMessage)
{
    switch (status) {
    case Status::Success:
       { qDebug()<< "message envoyer avec succes";
        break;}
    case Status::Failed:
    { qDebug()<< "erreur lors de l'envoi du message";
         qCritical()<< errorMessage;}

    break;
    default:
        break;
    }
    this->client->deleteLater();
}


int Fenetre::selection_multiple(QString table, QList <QString> liste_des_champ, QTableWidget* tableau, QString ordre){
    QString request;
    QSqlQuery query;
    tableau->clearContents();
    request = "select ";
    for(QString a: liste_des_champ){
        request += ", ";
        request += a;
    }
    request.replace(7, 1, " ");
    request += " from ";
    request += table;
    request += " order by ";
    request += ordre;
    request += ";";
    qDebug() << request;
    if(query.exec(request)){
        tableau->setRowCount(query.size());
        int index(0);

            QString filename_masculin = "C:/Users/idris/Documents/qt/eye_of_god/resource/icon/24x24/manager.png";
            QString filename_feminin = "C:/Users/idris/Documents/qt/eye_of_god/resource/icon/24x24/manager(1).png";
            QString filename_marrier = "C:/Users/idris/Documents/qt/eye_of_god/resource/icon/24x24/wedding-rings.png";
            QString filename_celibataire = "C:/Users/idris/Documents/qt/eye_of_god/resource/icon/24x24/single.png";
            QString filename_divorser = "C:/Users/idris/Documents/qt/eye_of_god/resource/icon/24x24/singles.png";

        while (query.next()){
            if(table == "PERSONNES"){

                for(int i =0; i<liste_des_champ.size(); ++i){
                    if(i == 3 || i==7){

                        QString file;
                        if(query.value(i).toString() == "MASCULIN") file = filename_masculin;
                        else if(query.value(i).toString() == "FEMININ") file = filename_feminin;
                        else if(query.value(i).toString() == "MARIE(E)") file = filename_marrier;
                        else if(query.value(i).toString() == "CELIBATAIRE") file = filename_celibataire;
                        else if(query.value(i).toString() == "DIVORSE(E)") file = filename_divorser;

                        QTableWidgetItem *item = new QTableWidgetItem();
                        item->setIcon(QIcon(file));
                        tableau->setItem(index,i,item);
                    }
                        else{
                        tableau->setItem(index,i, new QTableWidgetItem(query.value(i).toString()));
                    }
                }

            QPushButton *btn_ed, *btn_del;
            btn_ed = new QPushButton();
            btn_del = new QPushButton();
            btn_ed->setText("EDITER");
            btn_del->setText("SUPRIMER");
            QString style = "QPushButton{\n	background-color: rgb(50, 50, 50);\n	border: 2px solid rgb(60, 60, 60);\n	border-radius: 5px;\n}\nQPushButton:hover{\n	background-color: rgb(60, 60, 60);\n	border: 2px solid rgb(70, 70, 70);\n\n}\nQPushButton:pressed{\n	background-color: rgb(255, 0, 0);\n	border: 2px solid rgb(255, 0, 127);\n	color: rgb(35, 35, 35);\n\n}";
            QString style1 = "QPushButton {\n	border: 2px solid rgb(52, 59, 72);\n	border-radius: 5px;	\n	background-color: rgb(52, 59, 72);\n}\nQPushButton:hover {	\n	background-color: rgb(36, 73, 109);\n	border: 2px solid rgb(61, 70, 86);\n}\nQPushButton:pressed {\n	background-color: rgb(85, 255, 255);\n	border: 2px solid rgb(43, 50, 61);\n}";
            btn_ed->setStyleSheet(style1);
            btn_del->setStyleSheet(style);
            tableau->setCellWidget(index,liste_des_champ.size()+1, btn_ed);
            tableau->setCellWidget(index,liste_des_champ.size()+2, btn_del);

            }else{
                for(int i =0; i<liste_des_champ.size(); ++i){
                    tableau->setItem(index,i, new QTableWidgetItem(query.value(i).toString()));
                }
                QPushButton *btn_ed, *btn_del;
                btn_ed = new QPushButton();
                btn_del = new QPushButton();
                btn_ed->setText("EDITER");
                btn_del->setText("SUPRIMER");
                QString style = "QPushButton{\n	background-color: rgb(50, 50, 50);\n	border: 2px solid rgb(60, 60, 60);\n	border-radius: 5px;\n}\nQPushButton:hover{\n	background-color: rgb(60, 60, 60);\n	border: 2px solid rgb(70, 70, 70);\n\n}\nQPushButton:pressed{\n	background-color: rgb(255, 0, 0);\n	border: 2px solid rgb(255, 0, 127);\n	color: rgb(35, 35, 35);\n\n}";
                QString style1 = "QPushButton {\n	border: 2px solid rgb(52, 59, 72);\n	border-radius: 5px;	\n	background-color: rgb(52, 59, 72);\n}\nQPushButton:hover {\n	background-color: rgb(36, 73, 109);\n	border: 2px solid rgb(61, 70, 86);\n}\nQPushButton:pressed {	\n background-color: rgb(85, 255, 255);\n	border: 2px solid rgb(43, 50, 61);\n}";
                btn_ed->setStyleSheet(style1);
                btn_del->setStyleSheet(style);
                tableau->setCellWidget(index,liste_des_champ.size(), btn_ed);
                tableau->setCellWidget(index,liste_des_champ.size()+1, btn_del);

            }
            index++;
            tableau->insertRow(index);
        }
        return query.size();
    }else{
        qDebug()<<"erreur piang";
         qDebug()<< "erreur du a:" <<query.lastError().text();
       return 0;
    }

}

bool Fenetre::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == this->ui->label_img_profil && event->type() == QEvent::MouseButtonDblClick)
           {
                   emit doubleclicIMG();
                   return true;
           }
           return QObject::eventFilter(obj, event);
}
    
bool Fenetre::emailIsValide(QString email){
    QRegExp reg("^[\\w|\\.]+@[\\w]+\\.[\\w]{2,4}$") ;
    if(email.contains(reg)){
        return true;
    }
    else return false;
}
    
    
    
    
    
    
    
    

void Fenetre::on_pb_close_pup_12_clicked()
{
    this->ui->lineEdit_libelepost->setText(this->listeRoles.begin()->getLibele());
    this->ui->lineEdit_cout->setText(QString::number(this->listeRoles.begin()->getCout()));
    this->ui->lineEdit_temptravail->setText(QString::number(this->listeRoles.begin()->gettemp_de_travail()));
    this->ui->comboBox_service->setCurrentText(this->listeRoles.begin()->getService());
    this->ui->textEdit_desc_poste->setText(this->listeRoles.begin()->getDescription());

}

void Fenetre::on_pb_close_pup_16_clicked()
{
    Roles r;
    qDebug()<<"je suis ici";
    QVector<Roles>::Iterator it;
    it =this->listeRoles.end();
    r=*(it-1);
    this->ui->lineEdit_libelepost->setText(r.getLibele());
    this->ui->lineEdit_cout->setText(QString::number(r.getCout()));
    this->ui->lineEdit_temptravail->setText(QString::number(r.gettemp_de_travail()));
    this->ui->comboBox_service->setCurrentText(r.getService());
    this->ui->textEdit_desc_poste->setText(r.getDescription());
    qDebug()<<"je termine ici";
}

void Fenetre::on_pb_close_pup_13_clicked()
{
    Roles r;
    if(this->ui->lineEdit_libelepost->text().isEmpty())return;
    r.setLibele(this->ui->lineEdit_libelepost->text());
    r=r.getprecedent(this->listeRoles, r);

    this->ui->lineEdit_libelepost->setText(r.getLibele());
    this->ui->lineEdit_cout->setText(QString::number(r.getCout()));
    this->ui->lineEdit_temptravail->setText(QString::number(r.gettemp_de_travail()));
    this->ui->comboBox_service->setCurrentText(r.getService());
    this->ui->textEdit_desc_poste->setText(r.getDescription());
}

void Fenetre::on_pb_close_pup_15_clicked()
{
    Roles r;
    if(this->ui->lineEdit_libelepost->text().isEmpty())return;
    r.setLibele(this->ui->lineEdit_libelepost->text());
    r=r.getsuivant(this->listeRoles, r);

    this->ui->lineEdit_libelepost->setText(r.getLibele());
    this->ui->lineEdit_cout->setText(QString::number(r.getCout()));
    this->ui->lineEdit_temptravail->setText(QString::number(r.gettemp_de_travail()));
    this->ui->comboBox_service->setCurrentText(r.getService());
    this->ui->textEdit_desc_poste->setText(r.getDescription());
}

void Fenetre::on_pb_close_pup_14_clicked()
{
    Roles r;
    if(this->ui->lineEdit_libelepost->text().isEmpty())return;
    r.setLibele(this->ui->lineEdit_libelepost->text());
    if(r.suprimerRole(r.getLibele())){

    QVector<Roles>::Iterator it;
    it =this->listeRoles.end();
    r=*(it-1);
    this->ui->lineEdit_libelepost->setText(r.getLibele());
    this->ui->lineEdit_cout->setText(QString::number(r.getCout()));
    this->ui->lineEdit_temptravail->setText(QString::number(r.gettemp_de_travail()));
    this->ui->comboBox_service->setCurrentText(r.getService());
    this->ui->textEdit_desc_poste->setText(r.getDescription());
    this->listeRoles = r.listeRole();
    }

}

void Fenetre::on_pushButton_menuposte_clicked()
{
    Roles r;
    r.AfficherListeRoles(this->listeRoles,this->ui->tableWidget_2);
}

void Fenetre::on_pb_close_pup_6_clicked()
{
    Employers e;
    qDebug()<<"je suis ici";
    QVector<Employers>::Iterator it;
    it =this->listeEmployers.end();
    e=*(it-1);
    QString id= QString::number(e.getId_employer());
    this->ui->lineEdit_identifiant->setText(id);
    this->ui->lineEdit_nom->setText(e.getNom());
    this->ui->lineEdit_prenom->setText(e.getPrenom());
    this->ui->comboBox_sexe->setCurrentText(e.getSexe());
    this->ui->comboBox_poste->setCurrentText(e.getPoste());
    this->ui->lineEdit_email->setText(e.getEmail());
    this->ui->lineEdit_idcarte->setText(e.getId_carte());
    this->ui->comboBox_statu_matrimonial->setCurrentText(e.getStatus());
    this->ui->dateEdit_datenaissance->setDate(e.getDate_naissance());
    this->ui->dateEdit_dateembauche->setDate(e.getDate_embauche());
    if(QString::compare(e.getName_profil(), QString()) != 0){
        QImage image;
        bool valid = image.load(e.getName_profil());

        if(valid){
            image = image.scaledToWidth(120, Qt::SmoothTransformation);
            this->ui->label_img_profil->setPixmap(QPixmap::fromImage(image));

        }
        else{
            qDebug()<<"erreur de chargement de l'image";
        }
    }

    qDebug()<<"je termine ici";
}

void Fenetre::on_pb_close_pup_2_clicked()
{
    /*premier element*/
    QVector<Employers>::Iterator it;
    it =this->listeEmployers.begin();
    Employers e;
    e=*(it);
    QString id= QString::number(e.getId_employer());
    this->ui->lineEdit_identifiant->setText(id);
    this->ui->lineEdit_nom->setText(e.getNom());
    this->ui->lineEdit_prenom->setText(e.getPrenom());
    this->ui->comboBox_sexe->setCurrentText(e.getSexe());
    this->ui->comboBox_poste->setCurrentText(e.getPoste());
    this->ui->lineEdit_email->setText(e.getEmail());
    this->ui->lineEdit_idcarte->setText(e.getId_carte());
    this->ui->comboBox_statu_matrimonial->setCurrentText(e.getStatus());
    this->ui->dateEdit_datenaissance->setDate(e.getDate_naissance());
    this->ui->dateEdit_dateembauche->setDate(e.getDate_embauche());
    if(QString::compare(e.getName_profil(), QString()) != 0){
        QImage image;
        bool valid = image.load(e.getName_profil());

        if(valid){
            image = image.scaledToWidth(120, Qt::SmoothTransformation);
            this->ui->label_img_profil->setPixmap(QPixmap::fromImage(image));

        }
        else{
            qDebug()<<"erreur de chargement de l'image";
        }
    }
}

void Fenetre::on_pb_close_pup_3_clicked()
{
    /*employer precedent*/
    Employers e;
    if(this->ui->lineEdit_identifiant->text().isEmpty())return;
    e.setId_employer(this->ui->lineEdit_identifiant->text().toInt());
    e=e.getPrecedent(e,this->listeEmployers);

    QString id= QString::number(e.getId_employer());
    this->ui->lineEdit_identifiant->setText(id);
    this->ui->lineEdit_nom->setText(e.getNom());
    this->ui->lineEdit_prenom->setText(e.getPrenom());
    this->ui->comboBox_sexe->setCurrentText(e.getSexe());
    this->ui->comboBox_poste->setCurrentText(e.getPoste());
    this->ui->lineEdit_email->setText(e.getEmail());
    this->ui->lineEdit_idcarte->setText(e.getId_carte());
    this->ui->comboBox_statu_matrimonial->setCurrentText(e.getStatus());
    this->ui->dateEdit_datenaissance->setDate(e.getDate_naissance());
    this->ui->dateEdit_dateembauche->setDate(e.getDate_embauche());
    if(QString::compare(e.getName_profil(), QString()) != 0){
        QImage image;
        bool valid = image.load(e.getName_profil());

        if(valid){
            image = image.scaledToWidth(120, Qt::SmoothTransformation);
            this->ui->label_img_profil->setPixmap(QPixmap::fromImage(image));

        }
        else{
            qDebug()<<"erreur de chargement de l'image";
        }
    }
}

void Fenetre::on_pb_close_pup_5_clicked()
{
    /*employer suivant*/
    Employers e;
    if(this->ui->lineEdit_identifiant->text().isEmpty())return;
    e.setId_employer(this->ui->lineEdit_identifiant->text().toInt());
    e=e.getSuivant(e,this->listeEmployers);
    qDebug()<<e.getId_employer();

    QString id= QString::number(e.getId_employer());
    this->ui->lineEdit_identifiant->setText(id);
    this->ui->lineEdit_nom->setText(e.getNom());
    this->ui->lineEdit_prenom->setText(e.getPrenom());
    this->ui->comboBox_sexe->setCurrentText(e.getSexe());
    this->ui->comboBox_poste->setCurrentText(e.getPoste());
    this->ui->lineEdit_email->setText(e.getEmail());
    this->ui->lineEdit_idcarte->setText(e.getId_carte());
    this->ui->comboBox_statu_matrimonial->setCurrentText(e.getStatus());
    this->ui->dateEdit_datenaissance->setDate(e.getDate_naissance());
    this->ui->dateEdit_dateembauche->setDate(e.getDate_embauche());
    if(QString::compare(e.getName_profil(), QString()) != 0){
        QImage image;
        bool valid = image.load(e.getName_profil());

        if(valid){
            image = image.scaledToWidth(120, Qt::SmoothTransformation);
            this->ui->label_img_profil->setPixmap(QPixmap::fromImage(image));

        }
        else{
            qDebug()<<"erreur de chargement de l'image";
        }
    }
}

void Fenetre::on_pb_close_pup_4_clicked()
{
    Employers e;
    if(this->ui->lineEdit_identifiant->text().isEmpty())return;
    e.setId_employer(this->ui->lineEdit_identifiant->text().toInt());
    if(e.suprimer()){

    QVector<Employers>::Iterator it;
    it = this->listeEmployers.end();
    e=*(it-1);
    qDebug()<<"je suprime";
    QString id= QString::number(e.getId_employer());
    this->ui->lineEdit_identifiant->setText(id);
    this->ui->lineEdit_nom->setText(e.getNom());
    this->ui->lineEdit_prenom->setText(e.getPrenom());
    this->ui->comboBox_sexe->setCurrentText(e.getSexe());
    this->ui->comboBox_poste->setCurrentText(e.getPoste());
    this->ui->lineEdit_email->setText(e.getEmail());
    this->ui->lineEdit_idcarte->setText(e.getId_carte());
    this->ui->comboBox_statu_matrimonial->setCurrentText(e.getStatus());
    this->ui->dateEdit_datenaissance->setDate(e.getDate_naissance());
    this->ui->dateEdit_dateembauche->setDate(e.getDate_embauche());
    if(QString::compare(e.getName_profil(), QString()) != 0){
        QImage image;
        bool valid = image.load(e.getName_profil());

        if(valid){
            image = image.scaledToWidth(120, Qt::SmoothTransformation);
            this->ui->label_img_profil->setPixmap(QPixmap::fromImage(image));

        }
        else{
            qDebug()<<"erreur de chargement de l'image";
        }
    }

    this->listeEmployers = e.listeEmployer();
    }
}

void Fenetre::on_pushButton_accueil_clicked()
{
    Employers e;
    e.AfficheListeEmployer(this->listeEmployers, this->ui->tableWidget);
    qDebug()<<"c'est fait";
}

void Fenetre::on_pb_close_pup_9_clicked()
{
    Employers e,employer;

    e.setId_employer(this->ui->lineEdit_identifiant->text().toInt());
    e.setNom( this->ui->lineEdit_nom->text());
    e.setPrenom( this->ui->lineEdit_prenom->text());
    e.setId_carte( this->ui->lineEdit_idcarte->text());
    e.setEmail( this->ui->lineEdit_email->text());
    e.setSexe( this->ui->comboBox_sexe->currentText());
    e.setPoste( this->ui->comboBox_poste->currentText());
    e.setStatus( this->ui->comboBox_statu_matrimonial->currentText());
    e.setDate_naissance( this->ui->dateEdit_datenaissance->date());
    e.setDate_embauche( this->ui->dateEdit_dateembauche->date());
    if(!(this->file.isEmpty())){
        e.setName_profil(this->file);
    }

    e.setType_personne("employer");
    e.setPerso_delete("actif");

    if(employer.modifier(e)){
      this->listeEmployers = e.listeEmployer();
        qDebug()<<"fait";
    }


}

void Fenetre::on_pb_close_pup_19_clicked()
{
   Roles r;
   r.setLibele(this->ui->lineEdit_libelepost->text());
   r.setCout(this->ui->lineEdit_cout->text().toInt());
   r.settTemp_de_travail(this->ui->lineEdit_temptravail->text().toInt());
   r.setService(this->ui->comboBox_service->currentText());
   r.setDescription(this->ui->textEdit_desc_poste->toPlainText());
   r.setStatus("actif");
   if(r.modifierRole(r)){
       this->listeRoles = r.listeRole();
   }

}

void Fenetre::on_checkBox_compte_stateChanged(int arg1)
{
    if(arg1 == 0){
        this->ui->lineEdit_login->setEnabled(false);
        this->ui->lineEdit_passwd->setEnabled(false);
        this->ui->lineEdit_passwd_2->setEnabled(false);
        this->ui->lineEdit_login->clear();
        this->ui->lineEdit_passwd->clear();
        this->ui->lineEdit_passwd_2->clear();
        }else if(arg1 == 2){
        this->ui->lineEdit_login->setEnabled(true);
        this->ui->lineEdit_passwd->setEnabled(true);
        this->ui->lineEdit_passwd_2->setEnabled(true);
        this->ui->lineEdit_login->setText(this->ui->lineEdit_email->text());
        this->ui->lineEdit_passwd->setText("123456789");
        this->ui->lineEdit_passwd_2->setText(this->ui->lineEdit_passwd->text());
    }
}

void Fenetre::on_comboBox_autres_critere_currentTextChanged()
{
    QString style_en, style;
    style_en ="QComboBox{\n	background-color: rgb(27, 29, 35);\n	border-radius: 5px;\n	border: 2px solid rgb(27, 29, 35);\n	padding: 5px;\n	padding-left: 10px;\n}\nQComboBox:hover{\n	border: 2px solid rgb(64, 71, 88);\n}\nQComboBox QAbstractItemView {\n	color: rgb(85, 170, 255);	\n	background-color: rgb(27, 29, 35);\n	padding: 10px;\n	selection-background-color: rgb(39, 44, 54);\n}";
    style = "QComboBox{\n	background-color: rgb(27, 29, 35);\n	border-radius: 5px;\n	border: 2px solid rgb(27, 29, 35);\n	padding: 5px;\n	padding-left: 10px;\n}\nQComboBox:hover{\n	border: 2px solid rgb(64, 71, 88);\n}\nQComboBox QAbstractItemView {\n	color: rgb(80, 80, 80);	\n	background-color: rgb(27, 29, 35);\n	padding: 10px;\n	selection-background-color: rgb(39, 44, 54);\n}";
    if(this->ui->comboBox_autres_critere->currentText() != "Autres Critères"){
        this->ui->comboBox_date->setEnabled(true);
        this->ui->comboBox_date->setStyleSheet(style_en);
        this->ui->dateEdit_first->setEnabled(true);
        this->ui->dateEdit_first->setStyleSheet("");

    }else{
        this->ui->comboBox_date->setEnabled(false);
        this->ui->comboBox_date->setStyleSheet(style);
        this->ui->dateEdit_first->setEnabled(false);
        this->ui->dateEdit_first->setStyleSheet("color: rgb(80, 80, 80);");
        this->ui->dateEdit_second->setEnabled(false);
        this->ui->dateEdit_second->setStyleSheet("color: rgb(80, 80, 80);");
    }
}

void Fenetre::on_comboBox_date_currentTextChanged(const QString &arg1)
{
    if(this->ui->comboBox_date->currentText() == "Date Compris entre" || this->ui->comboBox_date->currentText() == "Date Pas Compris entre" ){
        this->ui->dateEdit_second->setEnabled(true);
        this->ui->dateEdit_second->setStyleSheet("");
    }else{
        this->ui->dateEdit_second->setEnabled(false);
        this->ui->dateEdit_second->setStyleSheet("color: rgb(80, 80, 80);");
    }
}

void Fenetre::on_pushButton_recherche_clicked()
{
    QString request,rech;
    QDate date1,date2;
    Employers e;
    rech = this->ui->lineEdit->text();
    date1 = this->ui->dateEdit_first->date();
    date2 = this->ui->dateEdit_second->date();
    request = makeRequestForEmployer();
    qDebug()<<request;
    if(request !=""){
    this->listeEmployersRecherche.clear();
    this->listeEmployersRecherche = e.listeEmployerRequest(request, rech, date1, date2);
        e.AfficheListeEmployer(this->listeEmployersRecherche, this->ui->tableWidget);
    }
}

void Fenetre::changeimageprofil()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("choisir"), "", tr("Images (*.png *.jpg *.jpeg *.bmp *.gif)"));

    if(QString::compare(filename, QString()) != 0){
        QImage image;
        bool valid = image.load(filename);

        if(valid){
            image = image.scaledToWidth(120, Qt::SmoothTransformation);
            this->ui->label_img_profil->setPixmap(QPixmap::fromImage(image));
            this->file = filename;
        }
        else{
            qDebug()<<"erreur de chargement de l'image";
        }
    }
}

void Fenetre::check_available()
{
    this->data_recive_form_arduino = arduino.read_from_arduino();
    QVector<Employers>::Iterator it;
    bool resultat =false;
    qDebug()<<"la valeur lu est: "<<this->data_recive_form_arduino;
    for (it =this->listeEmployers.begin();it != this->listeEmployers.end() ; ++it) {
       if(it->getId_carte() == this->data_recive_form_arduino){
           qDebug() <<it->getId_carte()<< "==>"<<this->data_recive_form_arduino;
           resultat = true;
           break;
       }
    }
    if(resultat==true){
        qDebug()<<"je dois ecris v";
        this->arduino.write_to_arduino("v");
        QString msg;
        msg= it->getNom();
        msg +=" ";
        msg +=it->getPrenom();
        msg += " \nest connecter";
        this->notifie->notifier(msg, []()
        {
            qDebug() << "A great action";
        }, 16);


    }else{
        qDebug()<<"je dois ecris f";
        this->arduino.write_to_arduino("f");
        this->notifie->notifier("un intruit essaye\n de se connecter", []()
        {
            qDebug() << "A great action";
        }, 16);
    }
}


void Fenetre::on_pb_close_pup_7_clicked()
{
    QPixmap pix("C:/Users/idris/Documents/qt/eye_of_god/resource/images/avatar.png");

    ui->label_img_profil->setPixmap(pix.scaled(120,120,Qt::KeepAspectRatio));
    this->ui->lineEdit_identifiant->clear();
     this->ui->lineEdit_nom->clear();
     this->ui->lineEdit_prenom->clear();
     this->ui->lineEdit_appartement->clear();
     this->ui->lineEdit_cni->clear();
     this->ui->lineEdit_email->clear();
     this->ui->lineEdit_idcarte->clear();
     this->ui->lineEdit_login->clear();
     this->ui->lineEdit_numtelephone->clear();
     this->ui->lineEdit_residence->clear();
     this->ui->lineEdit_quartier->clear();
     this->ui->lineEdit_passwd_2->clear();
    this->ui->lineEdit_passwd->clear();
    QDate date;
    date = date.currentDate();
    this->ui->dateEdit_dateembauche->setDate(date);
}
