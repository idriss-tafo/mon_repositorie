#include "dialogdecharge.h"
#include "ui_dialogdecharge.h"
#include <QMessageBox>
#include "QLineEdit"
#include <QPixmap>
#include <QDialog>
#include <QRegExpValidator>
#include<QRegularExpressionValidator>
#include"quantite.h"
#include"QComboBox"
#include<QString>


Dialogdecharge::Dialogdecharge(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogdecharge)
{
    ui->setupUi(this);
    //REGULAR EXP
    QRegExp poids("[1-9][0-9]*");
    //QRegExpValidator *valipoids=new QRegExpValidator(poids,this);
   // ui->lineEdit_poids->setValidator(valipoids);
   // QRegExp provenance("^[a-zA-Z]+(\\s[a-zA-Z]+)?$");
   // QRegExpValidator *valiprovenance=new QRegExpValidator(provenance,this);
   // ui->lineEdit_proven->setValidator(valiprovenance);
    QPixmap pix("C:/Users/Sana/Documents/untitled12/background.jpg");
    ui->label_dechajout->setPixmap(pix.scaled(1366,768));
    ui->label_BackSupDech->setPixmap(pix.scaled(1366,768));
    ui->label_backhistdech->setPixmap(pix.scaled(1366,768));
}

Dialogdecharge::~Dialogdecharge()
{
    delete ui;
}

void Dialogdecharge::on_pushButtonAnnulerDech_clicked()
{
    ui->lineEdit_poids->setText("");
    ui->lineEdit_proven->setText("");
    this->ui->comboBox_type->clear();

}

void Dialogdecharge::on_pushButtonEnregDech_clicked()
{     QString type=ui->comboBox_type->currentText();
      QString provenance= ui->lineEdit_proven->text();
     float poids=ui->lineEdit_poids->text().toInt();
       quantite*qnt = new quantite(type,provenance,poids);
         // controle de saisie
         bool isInputsValid=true;
         QRegularExpression poi_Exp;

         poi_Exp.setPattern(R"([1-9][0-9]*)");
         if((poids==NULL) || (!poi_Exp.match(QString::number(poids)).hasMatch())){
             isInputsValid=false;
             ui->lineEdit_poids->setStyleSheet("border:2px solid ;border-color: rgb(255, 0, 0);border-radius: 25% 10%;");

         }
         else{
             ui->lineEdit_poids->setStyleSheet("border:2px solid ;border-color:rgb(0, 0, 0);border-radius: 25% 10%; ");
         }
         QRegularExpression Provenance_Exp;

           Provenance_Exp.setPattern(R"(^2[0-5]{1},rue [a-z]{4,}$)");
           if((provenance!="") && !Provenance_Exp.match((provenance)).hasMatch()){
             isInputsValid=false;
             ui->lineEdit_proven->setStyleSheet("border:2px solid ;border-color: rgb(255, 0, 0);border-radius: 25% 10%;");

         }
         else{
             ui->lineEdit_proven->setStyleSheet("border:2px solid ;border-color:rgb(0, 0, 0);border-radius: 25% 10%;");
         }

           //compare return 0 if str1=str2
         if(QString::compare(type, "Veuiller choisir", Qt::CaseInsensitive)==0){
             isInputsValid=false;

             ui->comboBox_type->setStyleSheet("border:2px solid ;border-color: rgb(255, 0, 0);border-radius: 25% 10%;");

         }
         else{
             ui->comboBox_type->setStyleSheet("border:2px solid ;border-color:rgb(0, 0, 0);border-radius: 25% 10%;");
         }


         //
         if(isInputsValid==true){
             if (qnt->enregistrer_quantite(qnt))
                             QMessageBox::information(0, qApp->tr("Enregistrer"),
                                 qApp->tr("Une nouvelle quantite est ajoutée"), QMessageBox::Ok);
                         else
                             QMessageBox::critical(0, qApp->tr("Enregistrer"),
                                 qApp->tr("Problème d'enregistrement"), QMessageBox::Cancel);
         }
         else{
             QMessageBox::critical(0, qApp->tr("Invalid inputs"),
                 qApp->tr("Please  verif inputs "), QMessageBox::Cancel);
         }
}


void Dialogdecharge::on_pushButtonsupmoddech_clicked()
{

}
