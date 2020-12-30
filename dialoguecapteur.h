#ifndef DIALOGUECAPTEUR_H
#define DIALOGUECAPTEUR_H
#include <QComboBox>
#include <QDialog>
#include"capteur.h"

namespace Ui {
class dialogueCapteur;
}

class dialogueCapteur : public QDialog
{
    Q_OBJECT

public:
    explicit dialogueCapteur(QWidget *parent = nullptr);
    ~dialogueCapteur();



private slots:
    void on_pushButton_clicked();

    void on_bouttonajouterCapteur_clicked();

    void on_bouttonsupprimerIDcapteur_clicked();

    void on_checkBox_clicked();

    void on_bouttonrecherchecapteur_clicked();

private:
    Ui::dialogueCapteur *ui;
    capteur tempC;

};

#endif // DIALOGUECAPTEUR_H
