#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"projet.h"
#include"operation.h"
#include<QMessageBox>
 #include <QPainter>
#include <QPrinter>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QPrintDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonmenu_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_gestionprojet_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_ajouterprojet_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_afficherprojet_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
     ui->tableView->setModel(tempprojet.afficher());
}

void MainWindow::on_pushButton_okp2_clicked()
{
    int i = ui->lineEditidprojet->text().toInt();
    QString n=ui->lineEditnom->text();
    QString s=ui->lineEditsecteur->text();
    int d = ui->lineEditduree->text().toInt();


   projet p(i,n,s,d);
    bool test=p.ajouter();
    if (test)
    {

        QMessageBox::information(nullptr,"ajouter projet","projet ajouter !");
    }
}


void MainWindow::on_pushButton_anuulerp2_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}



void MainWindow::on_pushButtonsuppp5_clicked()
{
    int id_projet=ui->lineEditidprojet_2->text().toInt();
    bool test=tempprojet.supprimer(id_projet);

    if (test)
    {ui->tableView->setModel(tempprojet.afficher());

        QMessageBox::information(nullptr,"supprimer projet","projet supprimer !");
    }
    else
    {
      QMessageBox::warning(nullptr,"supprimer projet","projet non supprimer !");
    }
}



void MainWindow::on_pushButtonreturn_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}



void MainWindow::on_pushButtonreturn_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButtonsuppp5_2_clicked()
{int id=ui->lineEditi_operation_3->text().toInt();
    bool test=tempoperation.supprimer(id);

    if (test)
    {ui->tableView_2->setModel(tempoperation.afficher());

        QMessageBox::information(nullptr,"supprimer operation","operation supprimer !");
    }
    else
    {
      QMessageBox::warning(nullptr,"supprimer operation","operation non supprimer !");
    }

}

void MainWindow::on_pushButtonmodifier_2_clicked()
{

    int i = ui->lineEditi_operation_3->text().toInt();
    int db=ui->lineEditdatedebut_3->text().toInt();
    int dt=ui->lineEditdatefin_3->text().toInt();
    QString t = ui->lineEdittype_3->text();
    int ne=ui->lineEditnbremployee_3->text().toInt();


   operation o(i,db,dt,t,ne);
    bool test=o.modifier();
    if (test)
    {
ui->tableView_2->setModel(tempoperation.afficher());
        QMessageBox::information(nullptr,"modifier operation","operation modifiee !");
    }
}

void MainWindow::on_pushButton_anuulerp3_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_okp3_clicked()
{
    int i = ui->lineEditi_operation->text().toInt();
    int db=ui->lineEditdatedebut->text().toInt();
    int dt=ui->lineEditdatefin->text().toInt();
    QString t = ui->lineEdittype->text();
    int ne=ui->lineEditnbremployee->text().toInt();


   operation o(i,db,dt,t,ne);
    bool test=o.ajouter();
    if (test)
    {

        QMessageBox::information(nullptr,"ajouter operation","operation ajouter !");
    }
}

void MainWindow::on_pushButton_ajouterprojet_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_afficherprojet_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    ui->tableView_2->setModel(tempoperation.afficher());
}

void MainWindow::on_pushButton_gestionoperation_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButtonmodifier_clicked()
{

    int i = ui->lineEditidprojet_2->text().toInt();
    QString n=ui->lineEditnom_2->text();
    QString s=ui->lineEditsecteur_2->text();
    int d = ui->lineEdit_5->text().toInt();


   projet p(i,n,s,d);
    bool test=p.modifier();
    if (test)
    {
ui->tableView->setModel(tempprojet.afficher());
        QMessageBox::information(nullptr,"modifier projet","projet modifiee !");
    }
}

void MainWindow::on_pushButtontrip3_clicked()
{
    ui->tableView->setModel(tempprojet.tri());
}

void MainWindow::on_pushButtonmodifier_3_clicked()
{
    ui->tableView_2->setModel(tempoperation.tri());
}

void MainWindow::on_pushButtonimprimerp3_clicked()
{
    QPrinter rd; QPrintDialog d(&rd,this);
    d.setWindowTitle("Brain it");
    d.addEnabledOption (QAbstractPrintDialog::PrintSelection);
    if(d.exec() != QDialog::Accepted)
        return ;
}

void MainWindow::on_pushButtonimprimerp6_clicked()
{
    QPrinter rd; QPrintDialog d(&rd,this);
    d.setWindowTitle("Brain it");
    d.addEnabledOption (QAbstractPrintDialog::PrintSelection);
    if(d.exec() != QDialog::Accepted)
        return ;
}


void MainWindow::on_pushButtoncherchep3_clicked()
{
    if (ui->radioButtonid_projet->isChecked())
    {
        QString type= ui->lineEditsearch_2->text() ;
        ui->tableView->setModel(tempprojet.chercherid_projet(type));

    }

    if (ui->radioButtonnom->isChecked())
    {
        QString type= ui->lineEditsearch_2->text() ;
        ui->tableView->setModel(tempprojet.cherchernom(type));

    }

    if (ui->radioButtonsecteur->isChecked())
    {
        QString type= ui->lineEditsearch_2->text() ;
        ui->tableView->setModel(tempprojet.cherchersecteur(type));

    }
    if (!(ui->radioButtonsecteur->isChecked())&&!(ui->radioButtonnom->isChecked())&&!(ui->radioButtonid_projet->isChecked()))
           {
        QMessageBox::critical(nullptr, QObject::tr("cherche échoué"),
                               QObject::tr("\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButtoncherchep6_clicked()
{
    if (ui->radioButtonid->isChecked())
    {
        QString type= ui->lineEditsearch->text() ;
        ui->tableView_2->setModel(tempoperation.chercherid(type));

    }

    if (ui->radioButtontype->isChecked())
    {
        QString type= ui->lineEditsearch->text() ;
        ui->tableView_2->setModel(tempoperation.cherchertype(type));

    }

    if (ui->radioButtonnbr_employee->isChecked())
    {
        QString type= ui->lineEditsearch->text() ;
        ui->tableView_2->setModel(tempoperation.cherchernbr_employee(type));

    }
    if (!(ui->radioButtonnbr_employee->isChecked())&&!(ui->radioButtontype->isChecked())&&!(ui->radioButtonid->isChecked()))
           {
        QMessageBox::critical(nullptr, QObject::tr("cherche échoué"),
                               QObject::tr("\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButtontrip6_clicked()
{
    ui->tableView_2->setModel(tempoperation.tri());
}
