#ifndef VERIFICATION_H
#define VERIFICATION_H
#include<QtCore/QCoreApplication>
#include <QMainWindow>
#include <QtDebug>

class Verification : public QMainWindow
{
    Q_OBJECT
    int essaie = 3;
public:

    Verification(QWidget *parent = NULL, QString message = "");
    ~Verification();
};

#endif // VERIFICATION_H
