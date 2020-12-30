#include "dialogdecharge.h"
#include "ui_dialogdecharge.h"
#include <QMessageBox>
#include "QLineEdit"
#include <QPixmap>
#include <QDialog>
#include <QRegExpValidator>
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
    QRegExpValidator *valipoids=new QRegExpValidator(poids,this);
    ui->lineEdit_poids->setValidator(valipoids);
    QRegExp provenance("^[a-zA-Z]+(\\s[a-zA-Z]+)?$");
    QRegExpValidator *valiprovenance=new QRegExpValidator(provenance,this);
    ui->lineEdit_proven->setValidator(valiprovenance);
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
        if (qnt->enregistrer_quantite(qnt))
            QMessageBox::information(0, qApp->tr("Enregistrer"),
                qApp->tr("Une nouvelle quantite est ajoutée"), QMessageBox::Ok);
        else
            QMessageBox::critical(0, qApp->tr("Enregistrer"),
                qApp->tr("Problème d'enregistrement"), QMessageBox::Cancel);
}
