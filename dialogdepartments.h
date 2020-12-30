#ifndef DIALOGDEPARTMENTS_H
#define DIALOGDEPARTMENTS_H
#include <QDialog>

namespace Ui {
class DialogDepartments;
}

class DialogDepartments : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDepartments(QWidget *parent = nullptr);
    ~DialogDepartments();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogDepartments *ui;
};

#endif // DIALOGDEPARTMENTS_H
