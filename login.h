#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "fenetre.h"
#include "hygene/hmainwindow.h"

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT
public:
    Fenetre fenetre;
    HMainWindow hygene;

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
 QString styleframeok = "background-color: rgb(0, 255, 127);\nborder-radius: 5px;";
  QString styleframeerror = "background-color: rgb(255, 85, 127);\nborder-radius: 5px;";
    void affiche_message(QString m);
    Comptes verification_de_donnee();
private slots:
    Comptes controle_saisie();
    void connection();
private:
    Ui::Login *ui;
};

#endif // LOGIN_H
