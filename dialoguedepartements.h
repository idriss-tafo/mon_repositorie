#ifndef DIALOGUEDEPARTEMENTS_H
#define DIALOGUEDEPARTEMENTS_H

#include <QDialog>

namespace Ui {
class dialogueDepartements;
}

class dialogueDepartements : public QDialog
{
    Q_OBJECT

public:
    explicit dialogueDepartements(QWidget *parent = nullptr);
    ~dialogueDepartements();

private:
    Ui::dialogueDepartements *ui;
};

#endif // DIALOGUEDEPARTEMENTS_H
