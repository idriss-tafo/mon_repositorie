#include "dialogdepartments.h"
#include "ui_dialogdepartments.h"
#include "mainwindow.h"

MainWindow *main1;

DialogDepartments::DialogDepartments(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDepartments)
{
    ui->setupUi(this);
}

DialogDepartments::~DialogDepartments()
{
    delete ui;
}

void DialogDepartments::on_pushButton_clicked()
{
   hide();
   main1=new MainWindow(this);
   main1->show();
}
