/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *GestionVehicules;
    QPushButton *GestionParking;
    QLabel *label;
    QWidget *page_2;
    QLabel *label_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *Ajouter_Vehicule;
    QLineEdit *lineEditId;
    QLineEdit *lineEditMatricule;
    QLineEdit *lineEditMarque;
    QLineEdit *lineEditType;
    QLineEdit *lineEditDate;
    QWidget *tab_2;
    QPushButton *Modifier_Vehicule;
    QLabel *label_13;
    QLineEdit *lineEditDate_2;
    QLineEdit *lineEditId_2;
    QLineEdit *lineEditType_2;
    QLabel *label_12;
    QLabel *label_11;
    QLineEdit *lineEditMarque_2;
    QLabel *label_10;
    QLineEdit *lineEditMatricule_2;
    QLabel *label_9;
    QWidget *tab_5;
    QPushButton *Supprimer_vehicule;
    QLabel *label_14;
    QLineEdit *lineEditId_3;
    QWidget *tab_6;
    QFrame *line_11;
    QFrame *line_7;
    QPushButton *Trier_Vehicule;
    QFrame *line_9;
    QLineEdit *id;
    QFrame *line_8;
    QTableView *tableView_2;
    QPushButton *Recherche_Vehicule;
    QFrame *line_10;
    QFrame *line_12;
    QPushButton *Imprimer_vehicule;
    QWidget *tab_7;
    QPushButton *Return;
    QWidget *page_3;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QLineEdit *lineEditNom;
    QLineEdit *lineEditAdresse;
    QLineEdit *lineEditreff;
    QPushButton *Ajouter_Parking;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLineEdit *lineEditNbplace;
    QLabel *label_18;
    QWidget *tab_4;
    QPushButton *Modifier_Parking;
    QLabel *label_22;
    QLineEdit *lineEditAdresse_2;
    QLabel *label_20;
    QLineEdit *lineEditreff_2;
    QLineEdit *lineEditNom_2;
    QLabel *label_21;
    QLineEdit *lineEditNbplace_2;
    QLabel *label_19;
    QWidget *tab_8;
    QLineEdit *lineEditreff_3;
    QLabel *label_23;
    QPushButton *Supprimer_Parking;
    QWidget *tab_9;
    QTableView *tableView;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QFrame *line_6;
    QPushButton *Imprimer_Parking;
    QPushButton *Trier_Parking;
    QPushButton *Recherche_Parking;
    QLineEdit *Reff;
    QLabel *label_3;
    QPushButton *Return1;
    QPushButton *Logout;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(809, 491);
        MainWindow->setStyleSheet(QString::fromUtf8("*{\n"
"font-family: century gothic;\n"
"font-size: 24fpx;\n"
"	background-color: rgb(57, 57, 85);\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton\n"
"{\n"
"background:lightblue;\n"
"border-radius:60px;\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"color:black;\n"
"border-radius:15px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"color:white;\n"
"border-radius:15px;\n"
"background:lightpink;\n"
"}\n"
"Qlabel\n"
"{\n"
"background-color:none;\n"
"color: rgb(255, 255, 255);\n"
"font: 75 italic 12pt \"Century Gothic\";\n"
"}\n"
"QLineEdit\n"
"{\n"
"background:lightpink;\n"
"border:none;\n"
"border-radius:15px;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 20, 761, 401));
        stackedWidget->setStyleSheet(QString::fromUtf8("\n"
"*{\n"
"font-family: century gothic;\n"
"font-size: 24fpx;\n"
"\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton\n"
"{\n"
"background:lightblue;\n"
"border-radius:60px;\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"color:black;\n"
"border-radius:15px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"color:white;\n"
"border-radius:15px;\n"
"background:lightpink;\n"
"}\n"
"Qlabel\n"
"{\n"
"background-color:none;\n"
"color: rgb(255, 255, 255);\n"
"font: 75 italic 12pt \"Century Gothic\";\n"
"}"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        GestionVehicules = new QPushButton(page);
        GestionVehicules->setObjectName(QString::fromUtf8("GestionVehicules"));
        GestionVehicules->setGeometry(QRect(240, 220, 321, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("century gothic"));
        font.setPointSize(14);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        GestionVehicules->setFont(font);
        GestionParking = new QPushButton(page);
        GestionParking->setObjectName(QString::fromUtf8("GestionParking"));
        GestionParking->setGeometry(QRect(240, 300, 321, 51));
        GestionParking->setFont(font);
        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 70, 371, 81));
        QFont font1;
        font1.setFamily(QString::fromUtf8("century gothic"));
        font1.setPointSize(36);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("background-color:none;\n"
"color: rgb(255, 255, 255);"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        label_2 = new QLabel(page_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 10, 291, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("century gothic"));
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setItalic(true);
        font2.setWeight(75);
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("background-color:none;\n"
"color: rgb(255, 255, 255);"));
        tabWidget = new QTabWidget(page_2);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 40, 731, 311));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 30, 101, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Century Gothic"));
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setItalic(true);
        font3.setWeight(9);
        label_4->setFont(font3);
        label_4->setStyleSheet(QString::fromUtf8("background-color:none;\n"
"color: rgb(255, 255, 255);\n"
"font: 75 italic 12pt \"Century Gothic\";"));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(40, 80, 91, 31));
        label_5->setStyleSheet(QString::fromUtf8("background-color:none;\n"
"color: rgb(255, 255, 255);\n"
"font: 75 italic 12pt \"Century Gothic\";"));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(40, 130, 81, 31));
        label_6->setStyleSheet(QString::fromUtf8("background-color:none;\n"
"color: rgb(255, 255, 255);\n"
"font: 75 italic 12pt \"Century Gothic\";"));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(40, 180, 81, 31));
        label_7->setStyleSheet(QString::fromUtf8("background-color:none;\n"
"color: rgb(255, 255, 255);\n"
"font: 75 italic 12pt \"Century Gothic\";"));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(40, 230, 201, 31));
        label_8->setStyleSheet(QString::fromUtf8("background-color:none;\n"
"color: rgb(255, 255, 255);\n"
"font: 75 italic 12pt \"Century Gothic\";"));
        Ajouter_Vehicule = new QPushButton(tab);
        Ajouter_Vehicule->setObjectName(QString::fromUtf8("Ajouter_Vehicule"));
        Ajouter_Vehicule->setGeometry(QRect(580, 240, 131, 31));
        QFont font4;
        font4.setFamily(QString::fromUtf8("century gothic"));
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setItalic(true);
        font4.setWeight(75);
        Ajouter_Vehicule->setFont(font4);
        lineEditId = new QLineEdit(tab);
        lineEditId->setObjectName(QString::fromUtf8("lineEditId"));
        lineEditId->setGeometry(QRect(250, 30, 221, 31));
        lineEditMatricule = new QLineEdit(tab);
        lineEditMatricule->setObjectName(QString::fromUtf8("lineEditMatricule"));
        lineEditMatricule->setGeometry(QRect(250, 80, 221, 31));
        lineEditMarque = new QLineEdit(tab);
        lineEditMarque->setObjectName(QString::fromUtf8("lineEditMarque"));
        lineEditMarque->setGeometry(QRect(250, 130, 221, 31));
        lineEditType = new QLineEdit(tab);
        lineEditType->setObjectName(QString::fromUtf8("lineEditType"));
        lineEditType->setGeometry(QRect(250, 180, 221, 31));
        lineEditDate = new QLineEdit(tab);
        lineEditDate->setObjectName(QString::fromUtf8("lineEditDate"));
        lineEditDate->setGeometry(QRect(250, 230, 221, 31));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        Modifier_Vehicule = new QPushButton(tab_2);
        Modifier_Vehicule->setObjectName(QString::fromUtf8("Modifier_Vehicule"));
        Modifier_Vehicule->setGeometry(QRect(580, 240, 131, 31));
        Modifier_Vehicule->setFont(font4);
        label_13 = new QLabel(tab_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(40, 80, 91, 31));
        label_13->setStyleSheet(QString::fromUtf8("background-color:none;\n"
"color: rgb(255, 255, 255);\n"
"font: 75 italic 12pt \"Century Gothic\";"));
        lineEditDate_2 = new QLineEdit(tab_2);
        lineEditDate_2->setObjectName(QString::fromUtf8("lineEditDate_2"));
        lineEditDate_2->setGeometry(QRect(250, 230, 221, 31));
        lineEditId_2 = new QLineEdit(tab_2);
        lineEditId_2->setObjectName(QString::fromUtf8("lineEditId_2"));
        lineEditId_2->setGeometry(QRect(250, 30, 221, 31));
        lineEditType_2 = new QLineEdit(tab_2);
        lineEditType_2->setObjectName(QString::fromUtf8("lineEditType_2"));
        lineEditType_2->setGeometry(QRect(250, 180, 221, 31));
        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(40, 130, 81, 31));
        label_12->setStyleSheet(QString::fromUtf8("background-color:none;\n"
"color: rgb(255, 255, 255);\n"
"font: 75 italic 12pt \"Century Gothic\";"));
        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(40, 180, 81, 31));
        label_11->setStyleSheet(QString::fromUtf8("background-color:none;\n"
"color: rgb(255, 255, 255);\n"
"font: 75 italic 12pt \"Century Gothic\";"));
        lineEditMarque_2 = new QLineEdit(tab_2);
        lineEditMarque_2->setObjectName(QString::fromUtf8("lineEditMarque_2"));
        lineEditMarque_2->setGeometry(QRect(250, 130, 221, 31));
        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(40, 30, 101, 31));
        label_10->setFont(font3);
        label_10->setStyleSheet(QString::fromUtf8("background-color:none;\n"
"color: rgb(255, 255, 255);\n"
"font: 75 italic 12pt \"Century Gothic\";"));
        lineEditMatricule_2 = new QLineEdit(tab_2);
        lineEditMatricule_2->setObjectName(QString::fromUtf8("lineEditMatricule_2"));
        lineEditMatricule_2->setGeometry(QRect(250, 80, 221, 31));
        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(40, 230, 201, 31));
        label_9->setStyleSheet(QString::fromUtf8("background-color:none;\n"
"color: rgb(255, 255, 255);\n"
"font: 75 italic 12pt \"Century Gothic\";"));
        tabWidget->addTab(tab_2, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        Supprimer_vehicule = new QPushButton(tab_5);
        Supprimer_vehicule->setObjectName(QString::fromUtf8("Supprimer_vehicule"));
        Supprimer_vehicule->setGeometry(QRect(570, 230, 131, 31));
        Supprimer_vehicule->setFont(font4);
        label_14 = new QLabel(tab_5);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(110, 100, 101, 31));
        label_14->setStyleSheet(QString::fromUtf8("background-color:none;\n"
"color: rgb(255, 255, 255);\n"
"font: 75 italic 12pt \"Century Gothic\";"));
        lineEditId_3 = new QLineEdit(tab_5);
        lineEditId_3->setObjectName(QString::fromUtf8("lineEditId_3"));
        lineEditId_3->setGeometry(QRect(320, 100, 221, 31));
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        line_11 = new QFrame(tab_6);
        line_11->setObjectName(QString::fromUtf8("line_11"));
        line_11->setGeometry(QRect(470, 170, 241, 31));
        line_11->setStyleSheet(QString::fromUtf8("background-color:none;\n"
"color: rgb(255, 255, 255);\n"
""));
        line_11->setFrameShape(QFrame::HLine);
        line_11->setFrameShadow(QFrame::Sunken);
        line_7 = new QFrame(tab_6);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setGeometry(QRect(470, 90, 241, 31));
        line_7->setStyleSheet(QString::fromUtf8("background-color:none;\n"
"color: rgb(255, 255, 255);\n"
""));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);
        Trier_Vehicule = new QPushButton(tab_6);
        Trier_Vehicule->setObjectName(QString::fromUtf8("Trier_Vehicule"));
        Trier_Vehicule->setGeometry(QRect(500, 130, 181, 41));
        Trier_Vehicule->setFont(font4);
        line_9 = new QFrame(tab_6);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setGeometry(QRect(470, 240, 241, 41));
        line_9->setStyleSheet(QString::fromUtf8("background-color:none;\n"
"color: rgb(255, 255, 255);\n"
""));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);
        id = new QLineEdit(tab_6);
        id->setObjectName(QString::fromUtf8("id"));
        id->setGeometry(QRect(610, 200, 91, 41));
        line_8 = new QFrame(tab_6);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setGeometry(QRect(470, 15, 241, 31));
        line_8->setStyleSheet(QString::fromUtf8("background-color:none;\n"
"color: rgb(255, 255, 255);\n"
""));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);
        tableView_2 = new QTableView(tab_6);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setGeometry(QRect(10, 30, 451, 231));
        tableView_2->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 255, 255);"));
        Recherche_Vehicule = new QPushButton(tab_6);
        Recherche_Vehicule->setObjectName(QString::fromUtf8("Recherche_Vehicule"));
        Recherche_Vehicule->setGeometry(QRect(480, 202, 121, 41));
        Recherche_Vehicule->setFont(font4);
        line_10 = new QFrame(tab_6);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setGeometry(QRect(453, 30, 31, 231));
        line_10->setStyleSheet(QString::fromUtf8("background-color:none;\n"
"color: rgb(255, 255, 255);\n"
"\n"
"\n"
""));
        line_10->setFrameShape(QFrame::VLine);
        line_10->setFrameShadow(QFrame::Sunken);
        line_12 = new QFrame(tab_6);
        line_12->setObjectName(QString::fromUtf8("line_12"));
        line_12->setGeometry(QRect(690, 30, 41, 231));
        line_12->setStyleSheet(QString::fromUtf8("background-color:none;\n"
"color: rgb(255, 255, 255);\n"
"\n"
"\n"
""));
        line_12->setFrameShape(QFrame::VLine);
        line_12->setFrameShadow(QFrame::Sunken);
        Imprimer_vehicule = new QPushButton(tab_6);
        Imprimer_vehicule->setObjectName(QString::fromUtf8("Imprimer_vehicule"));
        Imprimer_vehicule->setGeometry(QRect(500, 50, 181, 41));
        Imprimer_vehicule->setFont(font4);
        tabWidget->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        tabWidget->addTab(tab_7, QString());
        Return = new QPushButton(page_2);
        Return->setObjectName(QString::fromUtf8("Return"));
        Return->setGeometry(QRect(10, 360, 61, 31));
        QFont font5;
        font5.setFamily(QString::fromUtf8("century gothic"));
        font5.setPointSize(11);
        font5.setBold(true);
        font5.setItalic(true);
        font5.setWeight(75);
        Return->setFont(font5);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        tabWidget_2 = new QTabWidget(page_3);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(10, 40, 741, 311));
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        lineEditNom = new QLineEdit(tab_3);
        lineEditNom->setObjectName(QString::fromUtf8("lineEditNom"));
        lineEditNom->setGeometry(QRect(270, 90, 221, 31));
        lineEditAdresse = new QLineEdit(tab_3);
        lineEditAdresse->setObjectName(QString::fromUtf8("lineEditAdresse"));
        lineEditAdresse->setGeometry(QRect(270, 140, 221, 31));
        lineEditreff = new QLineEdit(tab_3);
        lineEditreff->setObjectName(QString::fromUtf8("lineEditreff"));
        lineEditreff->setGeometry(QRect(270, 40, 221, 31));
        Ajouter_Parking = new QPushButton(tab_3);
        Ajouter_Parking->setObjectName(QString::fromUtf8("Ajouter_Parking"));
        Ajouter_Parking->setGeometry(QRect(580, 240, 131, 31));
        Ajouter_Parking->setFont(font4);
        label_15 = new QLabel(tab_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(60, 40, 101, 31));
        label_15->setStyleSheet(QString::fromUtf8("background-color:none;\n"
"color: rgb(255, 255, 255);\n"
"font: 75 italic 12pt \"Century Gothic\";"));
        label_16 = new QLabel(tab_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(60, 140, 81, 31));
        label_16->setStyleSheet(QString::fromUtf8("background-color:none;\n"
"color: rgb(255, 255, 255);\n"
"font: 75 italic 12pt \"Century Gothic\";"));
        label_17 = new QLabel(tab_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(60, 190, 151, 31));
        label_17->setStyleSheet(QString::fromUtf8("background-color:none;\n"
"color: rgb(255, 255, 255);\n"
"font: 75 italic 12pt \"Century Gothic\";"));
        lineEditNbplace = new QLineEdit(tab_3);
        lineEditNbplace->setObjectName(QString::fromUtf8("lineEditNbplace"));
        lineEditNbplace->setGeometry(QRect(270, 190, 221, 31));
        label_18 = new QLabel(tab_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(60, 90, 91, 31));
        label_18->setStyleSheet(QString::fromUtf8("background-color:none;\n"
"color: rgb(255, 255, 255);\n"
"font: 75 italic 12pt \"Century Gothic\";"));
        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        Modifier_Parking = new QPushButton(tab_4);
        Modifier_Parking->setObjectName(QString::fromUtf8("Modifier_Parking"));
        Modifier_Parking->setGeometry(QRect(580, 240, 131, 31));
        Modifier_Parking->setFont(font4);
        label_22 = new QLabel(tab_4);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(60, 190, 151, 31));
        label_22->setStyleSheet(QString::fromUtf8("background-color:none;\n"
"color: rgb(255, 255, 255);\n"
"font: 75 italic 12pt \"Century Gothic\";"));
        lineEditAdresse_2 = new QLineEdit(tab_4);
        lineEditAdresse_2->setObjectName(QString::fromUtf8("lineEditAdresse_2"));
        lineEditAdresse_2->setGeometry(QRect(270, 140, 221, 31));
        label_20 = new QLabel(tab_4);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(60, 140, 81, 31));
        label_20->setStyleSheet(QString::fromUtf8("background-color:none;\n"
"color: rgb(255, 255, 255);\n"
"font: 75 italic 12pt \"Century Gothic\";"));
        lineEditreff_2 = new QLineEdit(tab_4);
        lineEditreff_2->setObjectName(QString::fromUtf8("lineEditreff_2"));
        lineEditreff_2->setGeometry(QRect(270, 40, 221, 31));
        lineEditNom_2 = new QLineEdit(tab_4);
        lineEditNom_2->setObjectName(QString::fromUtf8("lineEditNom_2"));
        lineEditNom_2->setGeometry(QRect(270, 90, 221, 31));
        label_21 = new QLabel(tab_4);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(60, 90, 91, 31));
        label_21->setStyleSheet(QString::fromUtf8("background-color:none;\n"
"color: rgb(255, 255, 255);\n"
"font: 75 italic 12pt \"Century Gothic\";"));
        lineEditNbplace_2 = new QLineEdit(tab_4);
        lineEditNbplace_2->setObjectName(QString::fromUtf8("lineEditNbplace_2"));
        lineEditNbplace_2->setGeometry(QRect(270, 190, 221, 31));
        label_19 = new QLabel(tab_4);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(60, 40, 101, 31));
        label_19->setStyleSheet(QString::fromUtf8("background-color:none;\n"
"color: rgb(255, 255, 255);\n"
"font: 75 italic 12pt \"Century Gothic\";"));
        tabWidget_2->addTab(tab_4, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QString::fromUtf8("tab_8"));
        lineEditreff_3 = new QLineEdit(tab_8);
        lineEditreff_3->setObjectName(QString::fromUtf8("lineEditreff_3"));
        lineEditreff_3->setGeometry(QRect(330, 110, 221, 31));
        label_23 = new QLabel(tab_8);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(120, 110, 111, 31));
        label_23->setStyleSheet(QString::fromUtf8("background-color:none;\n"
"color: rgb(255, 255, 255);\n"
"font: 75 italic 12pt \"Century Gothic\";"));
        Supprimer_Parking = new QPushButton(tab_8);
        Supprimer_Parking->setObjectName(QString::fromUtf8("Supprimer_Parking"));
        Supprimer_Parking->setGeometry(QRect(550, 230, 131, 31));
        Supprimer_Parking->setFont(font4);
        tabWidget_2->addTab(tab_8, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QString::fromUtf8("tab_9"));
        tableView = new QTableView(tab_9);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(20, 30, 451, 231));
        tableView->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 255, 255);"));
        line = new QFrame(tab_9);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(480, 15, 241, 31));
        line->setStyleSheet(QString::fromUtf8("background-color:none;\n"
"color: rgb(255, 255, 255);\n"
""));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(tab_9);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(480, 90, 241, 31));
        line_2->setStyleSheet(QString::fromUtf8("background-color:none;\n"
"color: rgb(255, 255, 255);\n"
""));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(tab_9);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(463, 30, 31, 231));
        line_3->setStyleSheet(QString::fromUtf8("background-color:none;\n"
"color: rgb(255, 255, 255);\n"
"\n"
"\n"
""));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(tab_9);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(700, 30, 41, 231));
        line_4->setStyleSheet(QString::fromUtf8("background-color:none;\n"
"color: rgb(255, 255, 255);\n"
"\n"
"\n"
""));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(tab_9);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(480, 170, 241, 31));
        line_5->setStyleSheet(QString::fromUtf8("background-color:none;\n"
"color: rgb(255, 255, 255);\n"
""));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        line_6 = new QFrame(tab_9);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(480, 240, 241, 41));
        line_6->setStyleSheet(QString::fromUtf8("background-color:none;\n"
"color: rgb(255, 255, 255);\n"
""));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        Imprimer_Parking = new QPushButton(tab_9);
        Imprimer_Parking->setObjectName(QString::fromUtf8("Imprimer_Parking"));
        Imprimer_Parking->setGeometry(QRect(510, 50, 181, 41));
        Imprimer_Parking->setFont(font4);
        Trier_Parking = new QPushButton(tab_9);
        Trier_Parking->setObjectName(QString::fromUtf8("Trier_Parking"));
        Trier_Parking->setGeometry(QRect(510, 130, 181, 41));
        Trier_Parking->setFont(font4);
        Recherche_Parking = new QPushButton(tab_9);
        Recherche_Parking->setObjectName(QString::fromUtf8("Recherche_Parking"));
        Recherche_Parking->setGeometry(QRect(490, 202, 121, 41));
        Recherche_Parking->setFont(font4);
        Reff = new QLineEdit(tab_9);
        Reff->setObjectName(QString::fromUtf8("Reff"));
        Reff->setGeometry(QRect(620, 200, 91, 41));
        tabWidget_2->addTab(tab_9, QString());
        label_3 = new QLabel(page_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 10, 291, 21));
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("background-color:none;\n"
"color: rgb(255, 255, 255);"));
        Return1 = new QPushButton(page_3);
        Return1->setObjectName(QString::fromUtf8("Return1"));
        Return1->setGeometry(QRect(10, 360, 61, 31));
        QFont font6;
        font6.setFamily(QString::fromUtf8("century gothic"));
        font6.setPointSize(10);
        font6.setBold(true);
        font6.setItalic(true);
        font6.setWeight(75);
        Return1->setFont(font6);
        stackedWidget->addWidget(page_3);
        Logout = new QPushButton(centralwidget);
        Logout->setObjectName(QString::fromUtf8("Logout"));
        Logout->setGeometry(QRect(710, 40, 81, 31));
        Logout->setFont(font5);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 809, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);
        tabWidget->setCurrentIndex(3);
        tabWidget_2->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        GestionVehicules->setText(QApplication::translate("MainWindow", "Gestion Vehicules", nullptr));
        GestionParking->setText(QApplication::translate("MainWindow", "Gestion Parking", nullptr));
        label->setText(QApplication::translate("MainWindow", "Gestion Trafic", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Gestion Vehicules", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Identifiant", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Matricule", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Marque", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Type", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Date de mise en marche", nullptr));
        Ajouter_Vehicule->setText(QApplication::translate("MainWindow", "Ajouter", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Ajouter", nullptr));
        Modifier_Vehicule->setText(QApplication::translate("MainWindow", "Modifier", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "Matricule", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "Marque", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "Type", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "Identifiant", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Date de mise en marche", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Modifier", nullptr));
        Supprimer_vehicule->setText(QApplication::translate("MainWindow", "Supprimer", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "Identifiant", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "Supprimer", nullptr));
        Trier_Vehicule->setText(QApplication::translate("MainWindow", "Trier", nullptr));
        Recherche_Vehicule->setText(QApplication::translate("MainWindow", "Recherche", nullptr));
        Imprimer_vehicule->setText(QApplication::translate("MainWindow", "Imprimer", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("MainWindow", "Afficher", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QApplication::translate("MainWindow", "Statistiques", nullptr));
        Return->setText(QApplication::translate("MainWindow", "Return", nullptr));
        Ajouter_Parking->setText(QApplication::translate("MainWindow", "Ajouter", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "Refference", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "Adresse", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "Nombre de place", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "Nom", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("MainWindow", "Ajouter", nullptr));
        Modifier_Parking->setText(QApplication::translate("MainWindow", "Modifier", nullptr));
        label_22->setText(QApplication::translate("MainWindow", "Nombre de place", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "Adresse", nullptr));
        label_21->setText(QApplication::translate("MainWindow", "Nom", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "Refference", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("MainWindow", "Modifier", nullptr));
        label_23->setText(QApplication::translate("MainWindow", "Refference", nullptr));
        Supprimer_Parking->setText(QApplication::translate("MainWindow", "Supprimer", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_8), QApplication::translate("MainWindow", "Supprimer", nullptr));
        Imprimer_Parking->setText(QApplication::translate("MainWindow", "Imprimer", nullptr));
        Trier_Parking->setText(QApplication::translate("MainWindow", "Trier", nullptr));
        Recherche_Parking->setText(QApplication::translate("MainWindow", "Recherche", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_9), QApplication::translate("MainWindow", "Afficher", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Gestion Parking", nullptr));
        Return1->setText(QApplication::translate("MainWindow", "Return", nullptr));
        Logout->setText(QApplication::translate("MainWindow", "log out", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
