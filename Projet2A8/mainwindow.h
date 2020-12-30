#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "vehicule.h"
#include "parking.h"
#include <QMainWindow>
#include <QMediaPlayer>

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
    void on_GestionVehicules_clicked();

    void on_GestionParking_clicked();

    void on_Logout_clicked();

    void on_Ajouter_Vehicule_clicked();

    void on_Modifier_Vehicule_clicked();

    void on_Supprimer_vehicule_clicked();

    void on_Return_clicked();

    void on_Ajouter_Parking_clicked();

    void on_Modifier_Parking_clicked();

    void on_Supprimer_Parking_clicked();

    void on_Return1_clicked();

    void on_Recherche_Vehicule_clicked();

    void on_Recherche_Parking_clicked();

    void on_Trier_Vehicule_clicked();

    void on_Trier_Parking_clicked();

    void on_Imprimer_Parking_clicked();

    void on_Imprimer_vehicule_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlayer * click;
    Vehicule tmpVehicule;
    Parking tmpParking;
};
#endif // MAINWINDOW_H
