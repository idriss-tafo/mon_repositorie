HEADERS += hygene/dialogdecharge.h \
    $$PWD/hmainwindow.h
HEADERS += hygene/dialogpoubelles.h
HEADERS += hygene/quantite.h
HEADERS += hygene/poubelle.h
HEADERS += hygene/connexionbd.h


SOURCES += \
    $$PWD/hmainwindow.cpp \
    hygene/dialogdecharge.cpp \
    hygene/dialogpoubelles.cpp \
    hygene/poubelle.cpp \
    hygene/quantite.cpp

 FORMS += \
    $$PWD/hmainwindow.ui \
        hygene/dialogdecharge.ui \
        hygene/dialogpoubelles.ui \


RESOURCES += \
    hygene/Images.qrc
