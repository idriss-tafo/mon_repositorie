#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    QString text;
    QString valider;
    int i =3;
    QString nombre = QString::number(i);
    text += "bonjour";
    text += "\n login ou mot de passe\n incorect";
    ui->setupUi(this);
    ui->label_2->setText(text);
    valider += "Reessayer (";
    valider += nombre;
    valider += ")";
    ui->valider ->setText(valider);
    ui->annuler ->setText("Annuler");
     connect(ui->valider, SIGNAL(clicked(bool)),this,SLOT(dclicked(Connection.reessayer)));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *event){
    QPainter mymessage(this);
    /*mymessage.drawText(QPoint(10, 10), "blabla");
    qDebug() <<"le texte a ete saisie";
    mymessage.translate(100,50);

    QTextDocument document;
    QRect rect(0,0,150,100);

    document.setHtml("<b> bonjour</b><font color = 'blue' size = '30'>je fait une text bien long </font>");
     document.drawContents(&mymessage, rect);
*/

}

int Dialog::dclicked(int a)
{
      a--;
     qDebug() <<"vous aavez cliquez fois";
     close();
     return a;
}

