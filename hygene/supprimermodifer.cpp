#include "supprimermodifer.h"
#include "ui_dialogpoubelles.h"
#include <QRadioButton>
#include <QSqlQuery>
#include<QString>
#include<QLineEdit>

#include <QMessageBox>
#include "poubelle.h"

/*void SupprimerModifer::on_pushButtonSupMod_clicked()
{
    bool rds,rdm;

    rds=ui->sup->isChecked();
    rdm=ui->mod->isChecked();
QString lab,desc;
int id=ui->lineEdit_Idsupmod->text().toInt();
lab=ui->labelleLE->text();
prix=ui->Prix_unitaireLE->text().toFloat();
desc=ui->DescriptionLE->text();
Article * S=new Article(id);
Article *M=new Article(id,lab,prix,desc);
//createConnection();
if(rds)

{if(S->Rechercher(id)==1)
    {


        S->Supprimer(id);
        QMessageBox::warning(this,"Information","L'article est Supprim� ");
    }}

    else if(rdm){
    if(S->Rechercher(id)==1)
    {
        M->Modifier(id);
        QMessageBox::warning(this,"Information","L'Article est modifi� ");
    }}

}

void suppmod::on_mod_clicked()
{int id=ui->idALE->text().toInt();
    Article * S=new Article(id);
    if(S->Rechercher(id)==1)
{

     ui->labelleLE->setVisible(true);
    ui->Prix_unitaireLE->setVisible(true);
    ui->DescriptionLE->setVisible(true);
    ui->labelLA->setVisible(true);
    ui->prixuLA->setVisible(true);
    ui->descriptionLA->setVisible(true);
    ui->labelleLE->setEnabled(true);
        ui->Prix_unitaireLE->setEnabled(true);
        ui->DescriptionLE->setEnabled(true);
ui->modsup->setEnabled(true);
}
    else{
            ui->labelleLE->setVisible(true);
               ui->Prix_unitaireLE->setVisible(true);
               ui->DescriptionLE->setVisible(true);
               ui->labelLA->setVisible(true);
               ui->prixuLA->setVisible(true);
               ui->descriptionLA->setVisible(true);
               ui->labelleLE->setEnabled(false);
                   ui->Prix_unitaireLE->setEnabled(false);
                   ui->DescriptionLE->setEnabled(false);
                   ui->modsup->setEnabled(false);
        }

        ui->modsup->setText("Modifier");



}

void suppmod::on_sup_clicked()
{
    int id=ui->idALE->text().toInt();
        Article * S=new Article(id);
        ui->Prix_unitaireLE->setVisible(false);
         ui->DescriptionLE->setVisible(false);
         ui->prixuLA->setVisible(false);
         ui->descriptionLA->setVisible(false);
         ui->labelleLE->setEnabled(false);

        if(S->Rechercher(id)==1)
    {ui->labelleLE->setVisible(true);

    ui->labelLA->setVisible(true);
    ui->modsup->setEnabled(true);}

    ui->modsup->setText("Supprimer");


}

void suppmod::on_validerPB_clicked()
{
    int id=ui->idALE->text().toInt();
           Article * A=new Article(id);
    if(A->Rechercher(id)==1)
{QMessageBox::information(this,"Information"," Article trouv�  ");
        ui->labelleLE->setEnabled(true);
            ui->Prix_unitaireLE->setEnabled(true);
            ui->DescriptionLE->setEnabled(true);
            ui->modsup->setEnabled(true);

    }
   else {QMessageBox::critical(this,"Erreur "," Article non trouv� ! ");
        ui->labelleLE->setEnabled(false);
            ui->Prix_unitaireLE->setEnabled(false);
            ui->DescriptionLE->setEnabled(false);
            ui->modsup->setEnabled(false);

}}

void suppmod::on_idALE_textChanged(const QString &arg1)
{
    int id=ui->idALE->text().toInt();Article * A=new Article(id);

     if(A->Rechercher(id)==0)
     {
         ui->idALE->setStyleSheet("background: red ");
         ui->labelleLE->setVisible(false);
         ui->Prix_unitaireLE->setVisible(false);
         ui->DescriptionLE->setVisible(false);
         ui->labelLA->setVisible(false);
         ui->prixuLA->setVisible(false);
         ui->descriptionLA->setVisible(false);
         ui->modsup->setText("identifiant incorrect !!");
         ui->modsup->setEnabled(false);
ui->labelleLE->setEnabled(false);
        }
     else
     {
         ui->labelleLE->setText(art.TrouverLibelle(id));
         ui->Prix_unitaireLE->setText(QString::number(art.TrouverPrixu(id)));
         ui->DescriptionLE->setText(art.TrouverDescription(id));

         ui->idALE->setStyleSheet("background: white ");
        ui->modsup->setEnabled(false);

        if(ui->mod->isChecked()){
             ui->labelleLE->setVisible(true);
             ui->Prix_unitaireLE->setVisible(true);
             ui->DescriptionLE->setVisible(true);
             ui->labelLA->setVisible(true);
             ui->prixuLA->setVisible(true);
             ui->descriptionLA->setVisible(true);
             ui->labelleLE->setEnabled(true);
                 ui->Prix_unitaireLE->setEnabled(true);
                 ui->DescriptionLE->setEnabled(true);
                 ui->modsup->setText("Modifier");
                 ui->modsup->setEnabled(true);
         }
         if(ui->sup->isChecked()){ ui->labelleLE->setVisible(true);
             ui->Prix_unitaireLE->setVisible(false);
              ui->DescriptionLE->setVisible(false);
              ui->labelLA->setVisible(true);
              ui->prixuLA->setVisible(false);
              ui->descriptionLA->setVisible(false);
              ui->labelleLE->setEnabled(false);
              ui->modsup->setEnabled(true);
         ui->modsup->setText("Supprimer");


         }
         if(!(ui->mod->isChecked())&&!(ui->sup->isChecked()))ui->modsup->setText("Choisir une Option");
     }



}

}
*/
