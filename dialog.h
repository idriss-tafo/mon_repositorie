#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPainter>
#include <QTextDocument>
#include <QtDebug>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    virtual void paintEvent(QPaintEvent *event);
private slots:
    int dclicked(int a); //fonction slot
private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
