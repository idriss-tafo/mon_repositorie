QT       += core gui
QT       += sql
QT       += core gui charts
QT       += network
QT       += serialport
QT       += printsupport
QT       += widgets multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG += c++11


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
include(hygene/include.pri)
//include(gestion/include_emna.pri)
//include(traffique/include_traffique.pri)
SOURCES += \
    ConnectionBD.cpp \
    arduino.cpp \
    adresseemail.cpp \
    comptes.cpp \
    debuter.cpp \
    dialog.cpp \
    donutbreakdownchart.cpp \
    email.cpp \
    employers.cpp \
    fenetre.cpp \
    fonction_c_cpp.cpp \
    func_notification.cpp \
    login.cpp \
    main.cpp \
    connection.cpp \
    mainslice.cpp \
    notification.cpp \
    roles.cpp \
    smtpclient.cpp

HEADERS += \
    adresseemail.h \
    arduino.h \
    comptes.h \
    connection.h \
    connectionbd.h \
    debuter.h \
    dialog.h \
    donutbreakdownchart.h \
    email.h \
    employers.h \
    fenetre.h \
    fonction_c_cpp.h \
    func_notification.h \
    include.h \
    login.h \
    mainslice.h \
    notification.h \
    roles.h \
    smtpclient.h

FORMS += \
    connection.ui \
    debuter.ui \
    dialog.ui \
    fenetre.ui \
    login.ui \
    notification.ui

TRANSLATIONS += \
    eye_of_god_en_US.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    source.qrc
