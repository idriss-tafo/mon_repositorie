#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vehicule.h"
#include "parking.h"
#include <QMainWindow>
#include <QMediaPlayer>
#include <QMessageBox>
#include <QtPrintSupport>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_2->setModel(tmpVehicule.afficher());
    ui->tableView->setModel(tmpParking.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_GestionVehicules_clicked()
{
    click = new QMediaPlayer();
    click->setMedia(QUrl("qrc:/sounds/mouse_click.wav"));
    click->play();
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_GestionParking_clicked()
{
    click = new QMediaPlayer();
    click->setMedia(QUrl("qrc:/sounds/mouse_click.wav"));
    click->play();
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_Logout_clicked()
{
    close();
}

void MainWindow::on_Ajouter_Vehicule_clicked()
{
    /*click = new QMediaPlayer();
    click->setMedia(QUrl("qrc:/sounds/mouse_click.wav"));
    click->play();*/
    bool control=true;
    int i= ui->lineEditId->text().toInt();
    if(i<0 || i>9999)
    { //control de saisie
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Ajouter id vehicule"),
                    QObject::tr("ID invlid!\n"
                                "Click Ok to close."), QMessageBox::Ok);
    }
    QString D =ui->lineEditDate->text();
    if(D=="")
    {
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Ajouter une date de mise en circulation "),
                    QObject::tr("Date vide!\n"
                                "Click Ok to close."), QMessageBox::Ok);
    }
    QString Mat =ui->lineEditMatricule->text();
    if(Mat=="")
    {
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Ajouter Matricule "),
                    QObject::tr("Matricule vide!\n"
                                "Click Ok to close."), QMessageBox::Ok);
    }
    QString Marq = ui->lineEditMarque->text();
    if(Marq=="")
    {
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Ajouter une marque "),
                    QObject::tr("Marque vide!\n"
                                "Click Ok to close."), QMessageBox::Ok);
    }
    QString T = ui->lineEditType->text();
    if(T !="Voiture"&&T !="Camion"&& T !="Moto")
    {
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un type "),
                    QObject::tr("Type invalide!\n"
                                "Click Ok to close."), QMessageBox::Ok);
    }
    if (control==true)
    {
    Vehicule V(D,Mat,Marq,T,i);
    bool test=V.ajouter();
    if (test)
        {
        ui->tableView_2->setModel(tmpVehicule.afficher());
       QMessageBox::information(nullptr,QObject::tr("Ajout vehicule"),
                                QObject::tr("Vehicule ajouté.\n"
                                            "Click to exit"), QMessageBox::Cancel);
        }
    }else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un vehicule"),
                    QObject::tr("Erreur !.\n"
                                "Click Ok to close."), QMessageBox::Ok);
}

void MainWindow::on_Modifier_Vehicule_clicked()
{
    bool control=true;
    click = new QMediaPlayer();
    click->setMedia(QUrl("qrc:/sounds/mouse_click.wav"));
    click->play();

    int i= ui->lineEditId_2->text().toInt();
    if(i<0 || i>9999)
    { //control de saisie
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Ajouter id vehicule"),
                    QObject::tr("ID invlid!\n"
                                "Click Ok to close."), QMessageBox::Ok);
     }
    QString D =ui->lineEditDate_2->text();
    if(D=="")
    {
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Ajouter une date de mise en circulation "),
                    QObject::tr("Date vide!\n"
                                "Click Ok to close."), QMessageBox::Ok);
    }
    QString Mat =ui->lineEditMatricule_2->text();
    if(Mat=="")
    {
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Ajouter Matricule "),
                    QObject::tr("Matricule vide!\n"
                                "Click Ok to close."), QMessageBox::Ok);
    }
    QString Marq = ui->lineEditMarque_2->text();
    if(Marq=="")
    {
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Ajouter une marque "),
                    QObject::tr("Marque vide!\n"
                                "Click Ok to close."), QMessageBox::Ok);
    }
    QString T = ui->lineEditType_2->text();
    if(T !="Voiture"&& T !="Camion"&& T !="Moto")
    {
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un type "),
                    QObject::tr("Type invalide!\n"
                                "Click Ok to close."), QMessageBox::Ok);
    }
    bool test1=tmpVehicule.chercher(i);
    if(test1==true)
    {
    if (control==true)
    {
    Vehicule V(D,Mat,Marq,T,i);
    bool test=V.modifier();
    if (test)
        {
        ui->tableView_2->setModel(tmpVehicule.afficher());
       QMessageBox::information(nullptr,QObject::tr("Modifier vehicule"),
                                QObject::tr("Vehicule modifié.\n"
                                            "Click to exit"), QMessageBox::Cancel);
        }
    }else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un vehicule"),
                    QObject::tr("Erreur !.\n"
                                "Click Ok to close."), QMessageBox::Ok);
    }else QMessageBox::critical(nullptr, QObject::tr("Modifier un vehicule"),
                                QObject::tr("Vehicule non existant !.\n"
                                            "Click Ok to close."), QMessageBox::Ok);
}

void MainWindow::on_Supprimer_vehicule_clicked()
{
    click = new QMediaPlayer();
    click->setMedia(QUrl("qrc:/sounds/mouse_click.wav"));
    click->play();

    QSqlQuery query ;

    int id= ui->lineEditId_3->text().toInt();
    bool test1=tmpVehicule.chercher(id);
    if(test1)
    {

    bool test=tmpVehicule.supprimer(id);
    if(test)
    {
        ui->tableView_2->setModel(tmpVehicule.afficher());

        QMessageBox::information(nullptr,QObject::tr("Supprimer Vehicule"),
                                 QObject::tr("Vehicule suprimé.\n"
                                             "Click to exit"),QMessageBox::Cancel);
    }
    }else  QMessageBox::critical(nullptr, QObject::tr("Supprimer Vehicule "),
                                 QObject::tr("Vehicule inexistant!\n"
                                             "Click Ok to close."), QMessageBox::Ok);

}

void MainWindow::on_Return_clicked()
{
    click = new QMediaPlayer();
    click->setMedia(QUrl("qrc:/sounds/mouse_click.wav"));
    click->play();
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_Ajouter_Parking_clicked()
{
    click = new QMediaPlayer();
    click->setMedia(QUrl("qrc:/sounds/mouse_click.wav"));
    click->play();

    bool control=true;

    int R =ui->lineEditreff->text().toInt();
    if(R<0 || R>9999)
       { //control de saisie
           control = false;
           QMessageBox::critical(nullptr, QObject::tr("Ajouter reference Parking"),
                       QObject::tr("reference invlide!\n"
                                   "Click Ok to close."), QMessageBox::Ok);
       }

    QString A =ui->lineEditAdresse->text();
    if(A=="")
        {
            control = false;
            QMessageBox::critical(nullptr, QObject::tr("Ajouter une Adresse "),
                        QObject::tr("Adresse vide!\n"
                                    "Click Ok to close."), QMessageBox::Ok);
        }

    int nb = ui->lineEditNbplace->text().toInt();
    if(nb<0 ||nb>100){
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Ajouter nombre de place parking"),
                    QObject::tr("Nombre de place max est 100!\n"
                                "Click Ok to close."), QMessageBox::Ok);
       }
    QString n= ui->lineEditNom->text();
    if(n=="")
        {
            control = false;
            QMessageBox::critical(nullptr, QObject::tr("Ajouter un nom "),
                        QObject::tr("Nom vide!\n"
                                    "Click Ok to close."), QMessageBox::Ok);
        }
    if (control==true)
        {

    Parking P(R,n,A,nb);
    bool test=P.ajouter();
    if (test)
    {
        ui->tableView->setModel(tmpParking.afficher());
        QMessageBox::information(nullptr,QObject::tr("Ajout parking"),
                                 QObject::tr("parking ajouté.\n"
                                             "Click to exit"), QMessageBox::Cancel);
    }
    }else
QMessageBox::critical(nullptr, QObject::tr("Ajouter un Parking"),
            QObject::tr("Erreur !.\n"
                        "Click Ok to close."), QMessageBox::Ok);
}

void MainWindow::on_Modifier_Parking_clicked()
{
    click = new QMediaPlayer();
    click->setMedia(QUrl("qrc:/sounds/mouse_click.wav"));
    click->play();
    bool control=true;
    int R =ui->lineEditreff_2->text().toInt();
    if(R<0 || R>9999)
       { //control de saisie
           control = false;
           QMessageBox::critical(nullptr, QObject::tr("Modifier reference Parking"),
                       QObject::tr("reference invlide!\n"
                                   "Click Ok to close."), QMessageBox::Ok);
       }
    QString A =ui->lineEditAdresse_2->text();
    if(A=="")
        {
            control = false;
            QMessageBox::critical(nullptr, QObject::tr("Modifier une Adresse "),
                        QObject::tr("Adresse vide!\n"
                                    "Click Ok to close."), QMessageBox::Ok);
        }
    int nb = ui->lineEditNbplace_2->text().toInt();
    if(nb<0 ||nb>100)
    {
        control = false;
        QMessageBox::critical(nullptr, QObject::tr("Modifier nombre de place parking"),
                    QObject::tr("Nombre de place max est 100!\n"
                                "Click Ok to close."), QMessageBox::Ok);
    }
    QString n= ui->lineEditNom_2->text();
    if(n=="")
        {
            control = false;
            QMessageBox::critical(nullptr, QObject::tr("Modifier un nom "),
                        QObject::tr("Nom vide!\n"
                                    "Click Ok to close."), QMessageBox::Ok);
        }
    if (control==true)
        {

    Parking P(R,n,A,nb);
    bool test=P.modifier();
    if (test)

    {
        ui->tableView->setModel(tmpParking.afficher());
        QMessageBox::information(nullptr,QObject::tr("Modifier parking"),
                                 QObject::tr("parking modifié.\n"
                                             "Click to exit"), QMessageBox::Cancel);
    }
    }else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un parking"),
                    QObject::tr("Erreur !.\n"
                                "Click Ok to close."), QMessageBox::Ok);
}

void MainWindow::on_Supprimer_Parking_clicked()
{
    click = new QMediaPlayer();
    click->setMedia(QUrl("qrc:/sounds/mouse_click.wav"));
    click->play();

    int ref= ui->lineEditreff_3->text().toInt();
    bool test1=tmpVehicule.chercher(ref);
    if(test1){
    bool test=tmpParking.supprimer(ref);
    if(test)
    {
        ui->tableView->setModel(tmpParking.afficher());

        QMessageBox::information(nullptr,QObject::tr("Supprimer parking"),
                                 QObject::tr("Parking suprimé.\n"
                                             "Click to exit"),QMessageBox::Cancel);
    }
    }else QMessageBox::critical(nullptr, QObject::tr("Supprimer un parking"),
                                QObject::tr("Parking inexistant !.\n"
                                            "Click Ok to close."), QMessageBox::Ok);
}

void MainWindow::on_Return1_clicked()
{
    click = new QMediaPlayer();
    click->setMedia(QUrl("qrc:/sounds/mouse_click.wav"));
    click->play();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_Recherche_Vehicule_clicked()
{
    click = new QMediaPlayer();
    click->setMedia(QUrl("qrc:/sounds/mouse_click.wav"));
    click->play();

    int id =ui->id->text().toInt();
    bool test=tmpVehicule.chercher(id);
    if(test)
    {
        ui->tableView_2->setModel(tmpVehicule.chercher(id));//refresh

        QMessageBox::information(nullptr, QObject::tr("Recherche Terminer"),
                    QObject::tr("Recherche Terminer.\n"
                                "Click Ok to close."), QMessageBox::Ok);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Recherche"),
                    QObject::tr("Vehicule non trouvé!\n"
                                "Click Ok to close."), QMessageBox::Ok);
}

void MainWindow::on_Recherche_Parking_clicked()
{
    click = new QMediaPlayer();
    click->setMedia(QUrl("qrc:/sounds/mouse_click.wav"));
    click->play();
    int reff=ui->Reff->text().toInt();
    bool test=tmpParking.chercher(reff);
    if(test)
    {
        ui->tableView->setModel(tmpParking.chercher(reff));//refresh

        QMessageBox::information(nullptr, QObject::tr("Recherche Terminer"),
                    QObject::tr("Recherche Terminer.\n"
                                "Click Ok to close."), QMessageBox::Ok);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Recherche"),
                    QObject::tr("Parking non trouvé!\n"
                                "Click Ok to close."), QMessageBox::Ok);
}

void MainWindow::on_Trier_Vehicule_clicked()
{
    click = new QMediaPlayer();
    click->setMedia(QUrl("qrc:/sounds/mouse_click.wav"));
    click->play();
    bool test = tmpVehicule.tri_id();
    if (test){
    ui->tableView_2->setModel(tmpVehicule.tri_id());}//refresh
    QMessageBox::information(nullptr, QObject::tr("Trier vehicules"),
    QObject::tr("Tri vehicules terminé.\n"
    "Click ok to exit."), QMessageBox::Ok);
}

void MainWindow::on_Trier_Parking_clicked()
{
    click = new QMediaPlayer();
    click->setMedia(QUrl("qrc:/sounds/mouse_click.wav"));
    click->play();
    bool test = tmpParking.tri_reff();
    if (test){
    ui->tableView->setModel(tmpParking.tri_reff());}//refresh
    QMessageBox::information(nullptr, QObject::tr("Trier Parkings"),
    QObject::tr("Tri parkings terminé.\n"
    "Click ok to exit."), QMessageBox::Ok);

}

void MainWindow::on_Imprimer_Parking_clicked()
{
    click = new QMediaPlayer();
    click->setMedia(QUrl("qrc:/sounds/mouse_click.wav"));
    click->play();
    QPrinter printer;
        QPainter painter;
        printer.setPrinterName("desired printer name");
        QPrintDialog dialog(&printer,this);
        if(dialog.exec()==QDialog::Rejected)return;
        ui->tableView->render(&printer);
}

void MainWindow::on_Imprimer_vehicule_clicked()
{
    click = new QMediaPlayer();
    click->setMedia(QUrl("qrc:/sounds/mouse_click.wav"));
    click->play();
    QPrinter printer;
        QPainter painter;
        printer.setPrinterName("desired printer name");
        QPrintDialog dialog(&printer,this);
        if(dialog.exec()==QDialog::Rejected)return;
        ui->tableView_2->render(&printer);
}
