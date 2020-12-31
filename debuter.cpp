#include "debuter.h"
#include "ui_debuter.h"

#include "connectionbd.h"
#include "connection.h"



Debuter::Debuter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Debuter)
{

    ui->setupUi(this);

    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->ui->progressBar->setValue(0);
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(update_progressbar()));
   timer->start(100);
   QTimer::singleShot(1 * 1000, this, SLOT(description_init()));
   QTimer::singleShot(3 * 1000, this, SLOT(description_conbd()));
   QTimer::singleShot(6 * 1000, this, SLOT(description_parametre()));

    this->show();

}



Debuter::~Debuter()
{
    delete ui;
}
bool Debuter::update_progressbar(){
    if(this->ui->progressBar->value()>=100){
       // this->fin= true;
        this->timer->stop();
        this->a.show();
        //Connection w;
       // w.exec();
        this->close();
       // qDebug()<<this->fin;
        return this->fin;

    }else {
        this->ui->progressBar->setValue(this->ui->progressBar->value() +1);
       // qDebug() <<this->ui->progressBar->value();

        return false;
    }
}

void Debuter::description_init(){
    this->ui->label_description->setText("<strong>EYE OF GOD</strong> Initialisation ");
}

void Debuter::description_conbd(){
     this->ui->label_description->setText("<strong>EYE OF GOD</str ong> Connection avec la base de donnée");
     ConnectionBD();
}
void Debuter::description_parametre(){
     this->ui->label_description->setText("<strong>EYE OF GOD</strong> Choix interface utilisateur");
}
