#include "statistic.h"
#include "ui_statistic.h"

statistic::statistic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistic)
{
    ui->setupUi(this);
}

statistic::~statistic()
{
    delete ui;
}
int statistic::Statistique_partie1()
{

    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from Parkings where nb_Place=30") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;



}

int statistic::Statistique_partie2()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from parkings where nb_Place=50") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;



}
void statistic::paintEvent(QPaintEvent *)
{

    int a=Statistique_partie1();
    cout<<a<<endl  ;
    int b=Statistique_partie2();
    cout<<b<<endl ;

    float s1= a*100 ;
    float s2= b*100 ;
    float nb = a+b;
    float q1 ;
    q1 = s1/nb ;
    float q2 ;
    q2 = s2/nb ;
    float x  ;
    x= (q1*360)/100 ;
    float y  ;
    y = (q2*360)/100 ;
    QPainter painter(this);
    QRectF size=QRectF(50,50,this->width()-500,this->width()-500);
    painter.setBrush(Qt::blue);
    painter.drawPie(size,0,16*x);
    ui->label->setText("Parking de 30 places") ;
    painter.setBrush(Qt::cyan);
    painter.drawPie(size,16*x,16*y);
    ui->label_2->setText("Parking de 50 places") ;
}
void statistic::on_Return_clicked()
{
    QMediaPlayer * music = new QMediaPlayer();
         music->setMedia(QUrl("qrc:/sounds/mouse_click.wav"));
         music->play();
        hide();
}
