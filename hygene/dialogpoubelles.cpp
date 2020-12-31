#include "dialogpoubelles.h"
#include "ui_dialogpoubelles.h"
#include <QPixmap>
#include <QLabel>
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include "QLineEdit"
#include <QDialog>
#include<QPainter>
#include <QPrinter>
#include<QTableView>
#include<QDate>
#include <QIntValidator>
#include <QRegExpValidator>
#include<QRegularExpressionValidator>
#include<QString>
#include<QRadioButton>
#include"poubelle.h"
#include<iostream>
using namespace std;
Dialogpoubelles::Dialogpoubelles(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogpoubelles)
{
    ui->setupUi(this);
        ui->label_Id->setVisible(true);
        ui->lineEdit_Idsupmod->setVisible(true);
        ui->label_Nouv_NumCap->setVisible(false);
        ui->lineEditNouvNumCap->setVisible(false);
        ui->label_NouvLongitude->setVisible(false);
        ui->lineEditNouvLongitude->setVisible(false);
        ui->label_NouvLatitude->setVisible(false);
        ui->lineEditNouvLatitude->setVisible(false);
        ui->label_NouvAdresse->setVisible(false);
        ui->lineEditNouvAdresse->setVisible(false);
        ui->pushButtonSupMod->setEnabled(false);
        ui->comboBox_Etatsupmod->setVisible(false);
        ui->label_Etatsupmod->setVisible(false);
    //REGULAR EXP
    QRegExp num("[1-9][0-9]*");
    //QRegExpValidator *valinumcap=new QRegExpValidator(num,this);
    //ui->lineEdit_numcap->setValidator(valinumcap);
   // QRegExp adresse("^2[0-5]{1},rue [a-z]{4,}$");
    //QRegExpValidator *valiadress=new QRegExpValidator(adresse,this);
    //ui->lineEdit_adr->setValidator(valiadress);
    //QRegExp longitude("^(\\+|-)?(?:90(?:(?:\\.0{1,6})?)|(?:[0-9]|[1-8][0-9])(?:(?:\\.[0-9]{1,6})?))$");
    //QRegExpValidator *valilongitude=new QRegExpValidator(longitude,this);
    //ui->lineEdit_long->setValidator(valilongitude);
   // QRegExp latitude("^(\\+|-)?(?:180(?:(?:\\.0{1,6})?)|(?:[0-9]|[1-9][0-9]|1[0-7][0-9])(?:(?:\\.[0-9]{1,6})?))$");
  // QRegExpValidator *valilatitude=new QRegExpValidator(latitude,this);
    //ui->lineEdit_lat->setValidator(valilatitude);
    //BACKGROUND SET
    QPixmap pix("C:/Users/Sana/Documents/untitled12/background.jpg");
    ui->labelbackajout->setPixmap(pix.scaled(1366,768));
    ui->labelbacsup->setPixmap(pix.scaled(1366,768));
    ui->labelbacmodif->setPixmap(pix.scaled(1366,768));


}

    void Dialogpoubelles::on_pushButtonenregistrer_clicked(){

       QString etat=ui->comboBox_etat->currentText();
        QString adresse= ui->lineEdit_adr->text();
         int numcap=ui->lineEdit_numcap->text().toInt();
          QString longtitude=ui->lineEdit_long->text();
            QString latitude=ui->lineEdit_lat->text();

            poubelle*pb = new poubelle(adresse,numcap,longtitude,latitude,etat);

            // controle de saisie
            bool isInputsValid=true;
            QRegularExpression numRe;

            numRe.setPattern(R"([1-9][0-9]*)");
            if((numcap==NULL) || (!numRe.match(QString::number(numcap)).hasMatch())){
                isInputsValid=false;
                qDebug()<<" num cap invalid";
                ui->lineEdit_numcap->setStyleSheet("border:2px solid ;border-color: rgb(255, 0, 0);border-radius: 25% 10%;");

            }
            else{
                ui->lineEdit_numcap->setStyleSheet("border:2px solid ;border-color:rgb(0,0,0);border-radius: 25% 10%; ");
            }
            QRegularExpression adr;

            adr.setPattern(R"(^2[0-5]{1},rue [a-z]{4,}$)");
            if((adresse!="") && !adr.match((adresse)).hasMatch()){
                isInputsValid=false;
                qDebug()<<" adress invalid";
                ui->lineEdit_adr->setStyleSheet("border:2px solid ;border-color: rgb(255, 0, 0);border-radius: 25% 10%;");

            }
            else{
                ui->lineEdit_adr->setStyleSheet("border:2px solid ;border-color:rgb(0,0,0);border-radius: 25% 10%;");
            }
            QRegularExpression longi;

            longi.setPattern(R"(^(\+|-)?(?:180(?:(?:\.0{1,6})?)|(?:[0-9]|[1-9][0-9]|1[0-7][0-9])(?:(?:\.[0-9]{1,6})?))$)");
            if((longtitude==NULL) || (!longi.match((longtitude)).hasMatch())){
                isInputsValid=false;
                qDebug()<<" logni invalid";
                ui->lineEdit_long->setStyleSheet("border:2px solid ;border-color: rgb(255, 0, 0);border-radius: 25% 10%;");

            }
            else{
                ui->lineEdit_long->setStyleSheet("border:2px solid ;border-color:rgb(0,0,0);border-radius: 25% 10%;");
            }

            QRegularExpression lati;

            lati.setPattern(R"(^(\+|-)?(?:90(?:(?:\.0{1,6})?)|(?:[0-9]|[1-8][0-9])(?:(?:\.[0-9]{1,6})?))$)");
            if((latitude==NULL) || !lati.match((latitude)).hasMatch()){
                isInputsValid=false;
                qDebug()<<" lati invalid";
                ui->lineEdit_lat->setStyleSheet("border:2px solid ;border-color: rgb(255, 0, 0);border-radius: 25% 10%;");

            }
            else{
                ui->lineEdit_lat->setStyleSheet("border:2px solid ;border-color:rgb(0,0,0);border-radius: 25% 10%;");
            }


            //compare return 0 if str1=str2
          if(QString::compare(etat, "Veuiller choisir", Qt::CaseInsensitive)==0){
              isInputsValid=false;
              qDebug()<<" etat invalid";
              ui->comboBox_etat->setStyleSheet("border:2px solid ;border-color: rgb(255, 0, 0);border-radius: 25% 10%;");

          }
          else{
              ui->comboBox_etat->setStyleSheet("border:2px solid ;border-color:rgb(0, 0, 0);border-radius: 25% 10%;");
          }



            if(isInputsValid==true){
                if (pb->enregistrer_poubelle(pb))
                                QMessageBox::information(0, qApp->tr("Enregistrer"),
                                    qApp->tr("Une nouvelle poubelle est ajoutée"), QMessageBox::Ok);
                            else
                                QMessageBox::critical(0, qApp->tr("Enregistrer"),
                                    qApp->tr("Problème d'enregistrement"), QMessageBox::Cancel);
            }
            else{
                QMessageBox::critical(0, qApp->tr("Invalid inputs"),
                    qApp->tr("Please  verif inputs "), QMessageBox::Cancel);
            }
           /* if (pb->enregistrer_poubelle(pb))
                QMessageBox::information(0, qApp->tr("Enregistrer"),
                    qApp->tr("Une nouvelle poubelle est ajoutée"), QMessageBox::Ok);
            else
                QMessageBox::critical(0, qApp->tr("Enregistrer"),
                    qApp->tr("Problème d'enregistrement"), QMessageBox::Cancel);*/
    }
Dialogpoubelles::~Dialogpoubelles()
{
    delete ui;
}



void Dialogpoubelles::on_pushButtonAnnuler_clicked()
{
    ui->lineEdit_numcap->setText("");
    ui->lineEdit_long->setText("");
    ui->lineEdit_lat->setText("");
    ui->lineEdit_adr->setText("");

}

void Dialogpoubelles::on_pushButtonSupMod_clicked()
{
    bool rds,rdm;

    rds=ui->radioButtonSupprimerPou->isChecked();
    rdm=ui->radioButtonModifierPou->isChecked();
QString lineEditNouvLatitude,lineEditNouvAdresse,comboBox_Etatsupmod;
int id=ui->lineEdit_Idsupmod->text().toInt();

ui->lineEditNouvLatitude->text();
ui->lineEditNouvLongitude->text();
ui->comboBox_Etatsupmod->currentText();
ui->lineEditNouvAdresse->text();
poubelle *S=new poubelle(id);
poubelle *M=new poubelle(id);

if(rds)

{if(S->Rechercher(id)==1)
    {


        S->Supprimer(id);
        QMessageBox::warning(this,"Information","La poubelle est Supprime");
    }}

    else if(rdm){
    if(S->Rechercher(id)==1)
    { M->setID_poubelle(id);
        M->setnumCap(ui->lineEditNouvNumCap->text().toInt());
        M->setAdress(ui->lineEditNouvAdresse->text());
        M->setLongitude(ui->lineEditNouvLongitude->text());
        M->setLatitude(ui->lineEditNouvLatitude->text());
        M->setEtat(ui->comboBox_Etatsupmod->currentText());

        M->Modifier();
        QMessageBox::warning(this,"Information","la poubelle est modifie");
    }}

}

void Dialogpoubelles::on_radioButtonModifierPou_clicked()
{  ui->label_Id->setVisible(true);
    ui->lineEdit_Idsupmod->setVisible(true);
    {int id=ui->lineEdit_Idsupmod->text().toInt();
        poubelle * S=new poubelle(id);
        if(S->Rechercher(id)==1)
    {

            ui->label_Nouv_NumCap->setVisible(true);
            ui->lineEditNouvNumCap->setVisible(true);
            ui->label_NouvLongitude->setVisible(true);
            ui->lineEditNouvLongitude->setVisible(true);
            ui->label_NouvLatitude->setVisible(true);
            ui->lineEditNouvLatitude->setVisible(true);
            ui->label_NouvAdresse->setVisible(true);
            ui->lineEditNouvAdresse->setVisible(true);
            ui->label_Etatsupmod->setVisible(true);
            ui->comboBox_Etatsupmod->setVisible(true);

             ui->comboBox_Etatsupmod->setEnabled(true);
             ui->lineEditNouvNumCap->setEnabled(true);
              ui->lineEditNouvLongitude->setEnabled(true);
               ui->lineEditNouvAdresse->setEnabled(true);
                ui->lineEditNouvLatitude->setEnabled(true);
                ui->pushButtonSupMod->setEnabled(true);

    }
        else{ui->label_Etatsupmod->setVisible(true);
            ui->comboBox_Etatsupmod->setVisible(true);
            ui->label_Nouv_NumCap->setVisible(true);
            ui->lineEditNouvNumCap->setVisible(true);
            ui->label_NouvLongitude->setVisible(true);
            ui->lineEditNouvLongitude->setVisible(true);
            ui->label_NouvLatitude->setVisible(true);
            ui->lineEditNouvLatitude->setVisible(true);
            ui->label_NouvAdresse->setVisible(true);
            ui->lineEditNouvAdresse->setVisible(true);

             ui->comboBox_Etatsupmod->setEnabled(false);
             ui->lineEditNouvNumCap->setEnabled(false);
              ui->lineEditNouvLongitude->setEnabled(false);
               ui->lineEditNouvAdresse->setEnabled(false);
                ui->lineEditNouvLatitude->setEnabled(false);
                ui->pushButtonSupMod->setEnabled(false);

            }

            ui->pushButtonSupMod->setText("Modifier");

    }

}
void Dialogpoubelles::on_radioButtonSupprimerPou_clicked(){


    int id=ui->lineEdit_Idsupmod->text().toInt();
        poubelle * S=new poubelle(id);
        ui->comboBox_Etatsupmod->setVisible(false);
        ui->lineEditNouvNumCap->setVisible(false);
         ui->lineEditNouvLongitude->setVisible(false);
         ui->lineEditNouvLatitude->setVisible(false);
         ui->lineEditNouvAdresse->setVisible(false);


         ui->label_Etatsupmod->setVisible(false);
         ui->label_Nouv_NumCap->setVisible(false);
         ui->label_NouvLatitude->setVisible(false);
         ui->label_NouvLongitude->setVisible(false);
         ui->label_NouvAdresse->setVisible(false);

        if(S->Rechercher(id)==1)
    {ui->lineEditNouvLongitude->setVisible(false);

    ui->label_NouvLongitude->setVisible(false);
    ui->pushButtonSupMod->setEnabled(true);}

    ui->pushButtonSupMod->setText("Supprimer");


}
  void Dialogpoubelles::on_pushButtonValiderpou_clicked(){

      int id= ui ->lineEdit_Idsupmod->text().toInt();
                poubelle * A=new poubelle(id);
         if(A->Rechercher(id)==1)
     {QMessageBox::information(this,"Information"," poubelle trouvee  ");
                 ui->lineEditNouvNumCap->setEnabled(true);
                 ui->lineEditNouvLongitude->setEnabled(true);
                 ui->lineEditNouvLatitude->setEnabled(true);
                 ui->lineEditNouvAdresse->setEnabled(true);
                 ui->comboBox_Etatsupmod->setEnabled(true);
                 ui->pushButtonSupMod->setEnabled(true);



         }
        else {QMessageBox::critical(this,"Erreur "," poubelle non trouvee ! ");
             ui->lineEditNouvNumCap->setEnabled(false);
             ui->comboBox_Etatsupmod->setEnabled(false);
             ui->lineEditNouvLongitude->setEnabled(false);
                 ui->lineEditNouvLatitude->setEnabled(false);
                 ui->lineEditNouvAdresse->setEnabled(false);
                 ui->pushButtonSupMod->setEnabled(false);

     }

}


void Dialogpoubelles::on_rechercher_Pb_clicked()
{poubelle *tmpCl= new poubelle();
    QString idRech=ui->idRech_le->text();
        if (idRech=="")
        {
            QMessageBox::critical(0, qApp->tr("recherche"),
                qApp->tr("Veuillez introduire un ID"), QMessageBox::Cancel);
        }
        else
        {
            int id =ui->idRech_le->text().toInt();
                QSqlQueryModel *model =tmpCl->afficher_poubelleRech(id);
               int idRechResult = model->data(model->index(0, 0)).toInt();
                if(id == idRechResult)
                {   ui->recherche_View->setModel(model);
                }
                 else
                { ui->recherche_View->setModel(NULL);
                    QMessageBox::critical(0, qApp->tr("Recherche"),
                        qApp->tr("poubelle non trouvee"), QMessageBox::Cancel);
                }
        }
}

void Dialogpoubelles::on_Afficher_Pb_clicked()
{poubelle *tmpCl1= new poubelle();
    QString t=ui->comboBox_Tri->currentText();
    QString ty=ui->Type_Tri->currentText();
 QSqlQueryModel *model =tmpCl1->Afficher(t,ty);
 qDebug()<<"total rows" <<model->rowCount();
    ui->tableView_Afficher->setModel(model);
}

void Dialogpoubelles::on_lineEdit_Idsupmod_textChanged(const QString &arg1)
{

    int id=ui->lineEdit_Idsupmod->text().toInt();poubelle * A=new poubelle(id);

     if(A->Rechercher(id)==0)
     {
         ui->lineEdit_Idsupmod->setStyleSheet("background: red ");
         ui->lineEditNouvNumCap->setVisible(false);
         ui->lineEditNouvAdresse->setVisible(false);
         ui->lineEditNouvLongitude->setVisible(false);
         ui->lineEditNouvLatitude->setVisible(false);
         ui->comboBox_Etatsupmod->setVisible(false);
         ui->label_Nouv_NumCap->setVisible(false);
         ui->label_NouvLongitude->setVisible(false);
         ui->pushButtonSupMod->setText("identifiant incorrect !!");
         ui->pushButtonSupMod->setEnabled(false);
ui->lineEditNouvNumCap->setEnabled(false);
        }
     else
     {poubelle *pubelleFromDB =poubelle ::getPoubelleParId(id);


         ui->lineEditNouvNumCap->setText(QString::number(pubelleFromDB->getnumCap()));
         ui->lineEditNouvAdresse->setText(pou.TrouverAdresse(id));
         ui->lineEditNouvLatitude->setText(pou.TrouverLatitude(id));
         ui->lineEditNouvLongitude->setText(pou.TrouverLongitude(id));
         ui->comboBox_Etatsupmod->currentText()=pou.TrouverEtat(id);
         ui->comboBox_Etatsupmod->setCurrentIndex(ui->comboBox_Etatsupmod->findText(pubelleFromDB->getetat()));//CurrentText(pubelleFromDB->getetat());



         ui->lineEdit_Idsupmod->setStyleSheet("background: white ");
        ui->pushButtonSupMod->setEnabled(false);

        if(ui->radioButtonModifierPou->isChecked()){
             ui->lineEditNouvNumCap->setVisible(true);
             ui->lineEditNouvAdresse->setVisible(true);
             ui->lineEditNouvLatitude->setVisible(true);
             ui->lineEditNouvLongitude->setVisible(true);
             ui->comboBox_Etatsupmod->setVisible(true);


             ui->label_Etatsupmod->setVisible(true);
             ui->label_Nouv_NumCap->setVisible(true);
             ui->label_NouvLatitude->setVisible(true);
             ui->label_NouvLongitude->setVisible(true);
             ui->label_NouvAdresse->setVisible(true);
             ui->lineEditNouvNumCap->setVisible(true);
             ui->lineEditNouvAdresse->setVisible(true);
             ui->lineEditNouvLatitude->setVisible(true);
             ui->lineEditNouvLongitude->setVisible(true);
             ui->comboBox_Etatsupmod->setVisible(true);

                 ui->pushButtonSupMod->setText("Modifier");
                 ui->pushButtonSupMod->setEnabled(true);
         }
         if(ui->radioButtonSupprimerPou->isChecked()){ ui->lineEditNouvNumCap->setVisible(true);
             ui->lineEditNouvAdresse->setVisible(false);
             ui->label_NouvAdresse->setVisible(false);
             ui->lineEditNouvLongitude->setVisible(false);
             ui->label_NouvLongitude->setVisible(false);
             ui->lineEditNouvLatitude->setVisible(false);
             ui->label_NouvLatitude->setVisible(false);
              ui->comboBox_Etatsupmod->setVisible(false);
              ui->label_Etatsupmod->setVisible(false);
              ui->lineEditNouvNumCap->setVisible(true);
              ui->label_Nouv_NumCap->setEnabled(false);
              ui->pushButtonSupMod->setEnabled(true);
         ui->pushButtonSupMod->setText("Supprimer");


         }
         if(!(ui->radioButtonModifierPou->isChecked())&&!(ui->radioButtonSupprimerPou->isChecked()))ui->pushButtonSupMod->setText("Choisir une Option");
     }



}
