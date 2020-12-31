#ifndef HMAINWINDOW_H
#define HMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class HMainWindow;
}

class HMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit HMainWindow(QWidget *parent = nullptr);
    ~HMainWindow();

private slots:
    void on_pushButtonDecharge_clicked();

    void on_pushButtonpoubelles_clicked();

    //void on_pushButtondecharge_clicked();


private:
    Ui::HMainWindow *ui;
};

#endif // HMAINWINDOW_H
