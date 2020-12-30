#include "dialoguedepartements.h"
#include "ui_dialoguedepartements.h"
#include"mainwindow.h"



dialogueDepartements::dialogueDepartements(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogueDepartements)
{
    ui->setupUi(this);
}

dialogueDepartements::~dialogueDepartements()
{
    delete ui;
}


