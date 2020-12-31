#ifndef CONNECTIONBD_H
#define CONNECTIONBD_H

#include<QtCore/QCoreApplication>
#include "connection.h"
#include "ui_connection.h"
#include "QtSql"

#include <QtDebug>


#include "comptes.h"

bool ConnectionBD();
int ifExiste(QString table, QString attribut, QString nom);

#endif // CONNECTIONBD_H
