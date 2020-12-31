#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class HMainWindow; }
QT_END_NAMESPACE

class HMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    HMainWindow(QWidget *parent = nullptr);
    ~HMainWindow();

private slots:
    void on_pushButtonDecharge_clicked();

    void on_pushButtonpoubelles_clicked();

    //void on_pushButtondecharge_clicked();

private:
    Ui::HMainWindow *ui;
};
#endif // MAINWINDOW_H
