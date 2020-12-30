#include "dialoguecapteur.h"
#include "ui_dialoguecapteur.h"
#include"mainwindow.h"
#include "capteur.h"
#include<QMessageBox>


MainWindow  *mainw;

dialogueCapteur::dialogueCapteur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogueCapteur)
{
    ui->setupUi(this);
    ui->tableViewcapteur->setModel(tempC.afficher());
}

dialogueCapteur::~dialogueCapteur()
{
    delete ui;
}




void dialogueCapteur::on_pushButton_clicked()
{
    hide();
   mainw =new MainWindow(this);
   mainw->show();
}

void dialogueCapteur::on_bouttonajouterCapteur_clicked()
{
    int ID=ui->lavel_idajoutcapteur->text().toInt();
    QString type=ui->label_type->currentText();
    QString departement=ui->label_Departementajoutcapteur->text();
 capteur C1(ID,type,departement);
 bool test=C1.ajouter();
 if (test)
 {
     ui->tableViewcapteur->setModel(tempC.afficher());
QMessageBox::information(nullptr,QObject::tr("ok"),
                         QObject::tr("ajout effectue\n"
                         "click cancel to exit."),QMessageBox::Cancel);



 }
 else
     QMessageBox::critical(nullptr,QObject::tr("not ok"),
                           QObject::tr("ajout non effectue.\n"
                                       "click cancel to exil."),QMessageBox::Cancel);

 }




void dialogueCapteur::on_bouttonsupprimerIDcapteur_clicked()
{
    int ID =ui->lineEdit_IDsupp->text().toInt();
    bool test=tempC.supprimer(ID);
    if (test)
    {
        ui->tableViewcapteur->setModel(tempC.afficher());
   QMessageBox::information(nullptr,QObject::tr("ok"),
                            QObject::tr("suppresion effectue\n"
                            "click cancel to exit."),QMessageBox::Cancel);



    }
    else
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                              QObject::tr("suppression non effectue.\n"
                                          "click cancel to exil."),QMessageBox::Cancel);

}

void dialogueCapteur::on_checkBox_clicked()
{
    bool test = true;
          if (test)
              {
              ui->tableViewcapteur->setModel(tempC.afficher());

                  ui->tableViewcapteur->setModel(tempC.trierID());



              }

          else
          {
              QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                    QObject::tr("Erreur !.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
          }

    }



void dialogueCapteur::on_bouttonrecherchecapteur_clicked()
{
    ui->tableViewcapteur->setModel(tempC.afficher());
            QString type = ui->lineEditrechercheCapteur->text();
           ui->tableViewrechcapteur->setModel(tempC.afficher_type(type));
}
