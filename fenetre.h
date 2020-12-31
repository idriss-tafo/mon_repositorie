#ifndef FENETRE_H
#define FENETRE_H

#include <QMainWindow>
#include <QPropertyAnimation>
#include<QtCore/QCoreApplication>
#include <QtDebug>
#include <QtCore>
#include <QGraphicsEffect>
#include <QSizeGrip>
#include <QList>
#include <QtWidgets/QStatusBar>

#include <QtCharts>
#include <QBarSet>
#include <QBarSeries>
#include <QChartView>
#include <QDateTime>

#include "ui_fenetre.h"
#include "connectionbd.h"
#include "comptes.h"
#include "func_notification.h"
#include "email.h"
#include "adresseemail.h"
#include "smtpclient.h"
#include "employers.h"
#include "roles.h"
#include "arduino.h"
#include "donutbreakdownchart.h"

QT_CHARTS_USE_NAMESPACE
typedef QPair<QPointF, QString> Data;
typedef QList<Data> DataList;
typedef QList<DataList> DataTable;

namespace Ui {
class Fenetre;
}

class Fenetre : public QMainWindow
{
    Q_OBJECT
public:
    QPropertyAnimation *animation;
    bool ETAT_GLOBAL = false;
    bool TITLE_BAR = true;
    QTimer* timer;
    QEvent* event;
    QGraphicsDropShadowEffect* shadow;
    QSizeGrip* sizegrip;
    QString styleframeok = "background-color: rgb(0, 255, 127);\nborder-radius: 5px;";
     QString styleframeerror = "background-color: rgb(255, 85, 127);\nborder-radius: 5px;";
     QChart *pchar = new QChart();
     QChart *chart = new QChart();
     QList<QString> listechamp_personne;
     QString file;


public:
    explicit Fenetre(QWidget *parent = nullptr);
    ~Fenetre();
    QString selectmenu(QString getstyle);
    QString deselectmenu(QString getstyle);
    void selectmenustandard(QString);
    void resetstyle(QString widget);
    void labelpage(QString texte);
    void maximize_restore();
    void enableMaximumSize(int width, int height);
    void doubleclicmaximizerestore(QEvent *event);
    void definitionfenetre();
    int Adduser_controle_saisie();
    int Addposte_controle_saisie();
    void affiche_message(QString m, QFrame* frame, QLabel* lab);
    void stat_baton();
    void stat_graphe();
    void stat_cercle();
    void choix_des_postes();
    Ui::Fenetre* getui();
    void setlisteEmployers(QVector<Employers> t);
    void setlisteRoles(QVector<Roles> t);
    QVector<Employers> getlisteEmployers();
    QVector<Roles> getlisteRoles();
    void makeStat();
    void setlistecolor();
    void setListeSeriesGeneral();
    void setListeDespostes_et_nbEmployers(QVector<QPair<QString, int>> t);
    void setListeDesdepartements(QVector<QPair<QString, QList<QString>>> t);
    QString makeRequestForEmployer();

    /*verification du format de l'email*/
    bool emailIsValide(QString email);

    /*selection des donnes*/

    int selection_multiple(QString table, QList <QString> liste_des_champ, QTableWidget* tableau, QString ordre);
    /* filtre d'evenement*/

    bool eventFilter(QObject *obj, QEvent *event);
signals:
    void doubleclicIMG();

private slots:
    void togglemenu();
    void setcurrentpageacceueil();
    void setcurrentpagehistory();
    void setcurrentpagedachbord();
    void setcurrentpagadduser();
    void setcurrentpageconf();
    void setcurrentpagereglage();

    void on_pb_close_pup_10_clicked();

    void on_pb_save_postebd_clicked();
    void onstatus(Status::e status, QString errorMessage);

    void on_pb_close_pup_12_clicked();

    void on_pb_close_pup_16_clicked();

    void on_pb_close_pup_13_clicked();

    void on_pb_close_pup_15_clicked();

    void on_pb_close_pup_14_clicked();

    void on_pushButton_menuposte_clicked();

    void on_pb_close_pup_6_clicked();

    void on_pb_close_pup_2_clicked();

    void on_pb_close_pup_3_clicked();

    void on_pb_close_pup_5_clicked();

    void on_pb_close_pup_4_clicked();

    void on_pushButton_accueil_clicked();

    void on_pb_close_pup_9_clicked();

    void on_pb_close_pup_19_clicked();

    void on_checkBox_compte_stateChanged(int arg1);

    void on_comboBox_autres_critere_currentTextChanged();

    void on_comboBox_date_currentTextChanged(const QString &arg1);

    void on_pushButton_recherche_clicked();
    void changeimageprofil();
    void check_available();

    void on_pb_close_pup_7_clicked();

private:
    Ui::Fenetre *ui;
    QByteArray data_recive_form_arduino;
    Arduino arduino;
    func_notification *notifie;
    AdresseEmail CompteGoogle;
    Smtpclient *client;
    Comptes *compte;
    Employers employer;
    Roles rol;
    QVector<Employers> listeEmployers;
    QVector<Employers> listeEmployersRecherche;
    QVector<Roles> listeRoles;
    QVector<QPair<QString, QList<QString>>>listeDesdepartements;
    QVector<QPair<QString, int>>listeDespostes_et_nbEmployers;
    QVector<QPieSeries*>listeSerieGenerale;
    QVector<QColor> listecolors;
};


class Framelabelbtn : public QFrame{
    Q_OBJECT
    
public:
    explicit Framelabelbtn(QWidget *parent = nullptr);
    void mouseDoubleClickEvent();
    
 signals:
     void Mouse_DoubleClick();

};

#endif // FENETRE_H
