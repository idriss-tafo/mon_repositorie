#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"gestion/projet.h"
#include"gestion/operation.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonmenu_clicked();

    void on_pushButton_gestionprojet_clicked();

    void on_pushButton_ajouterprojet_clicked();

    void on_pushButton_afficherprojet_clicked();

    void on_pushButton_okp2_clicked();

    void on_pushButton_anuulerp2_clicked();



    void on_pushButtonsuppp5_clicked();



    void on_pushButtonreturn_clicked();

    void on_pushButtonreturn_2_clicked();

    void on_pushButtonsuppp5_2_clicked();

    void on_pushButtonmodifier_2_clicked();

    void on_pushButton_anuulerp3_clicked();

    void on_pushButton_okp3_clicked();

    void on_pushButton_ajouterprojet_2_clicked();

    void on_pushButton_afficherprojet_2_clicked();

    void on_pushButton_gestionoperation_clicked();

    void on_pushButtonmodifier_clicked();

    void on_pushButtontrip3_clicked();

    void on_pushButtonmodifier_3_clicked();



    void on_pushButtonimprimerp6_clicked();

    void on_pushButtonimprimerp3_clicked();

    void on_pushButtoncherchep3_clicked();

    void on_pushButtoncherchep6_clicked();

    void on_pushButtontrip6_clicked();

private:
    Ui::MainWindow *ui;
    projet tempprojet;
    operation tempoperation;
};
#endif // MAINWINDOW_H
