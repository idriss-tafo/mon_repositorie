#ifndef DIALOGPOUBELLES_H
#define DIALOGPOUBELLES_H

#include "QLineEdit"
#include <QDialog>
#include<hygene/poubelle.h>
using namespace std;
namespace Ui {
class Dialogpoubelles;
}

class Dialogpoubelles : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogpoubelles(QWidget *parent = nullptr);
    ~Dialogpoubelles();


private slots:

    void on_pushButtonenregistrer_clicked();

    void on_pushButtonAnnuler_clicked();

    void on_pushButtonSupMod_clicked();

    void on_radioButtonModifierPou_clicked();

   // void on_radioButtonSupprimer_clicked();

    void on_pushButtonValiderpou_clicked();

    void on_lineEdit_Idsupmod_textChanged(const QString &arg1);


    void on_radioButtonSupprimerPou_clicked();

    void on_rechercher_Pb_clicked();

    void on_Afficher_Pb_clicked();

private:
    Ui::Dialogpoubelles *ui;
    poubelle pou;
};

#endif // DIALOGPOUBELLES_H
