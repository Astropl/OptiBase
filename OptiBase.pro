QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DataBase/checkfiles.cpp \
    DataBase/maindb.cpp \
    Info/info.cpp \
    Kontrahent/kontrahent.cpp \
    Kontrahent/kontrahentdodajkraj.cpp \
    Kontrahent/kontrahentdodajmiasto.cpp \
    Kontrahent/kontrahentdodajwojewodztwo.cpp \
    Kontrahent/kontrahentinfo.cpp \
    Kontrahent/kontrahentinfododajwpis.cpp \
    Kontrahent/kontrahentlista.cpp \
    Kontrahent/kontrahentshow.cpp \
    Kontrahent/tableviewlistakontrahentow.cpp \
    Timery/timedate.cpp \
    Urzadzenia/urzadzenia.cpp \
    Urzadzenia/urzadzeniadodajmodel.cpp \
    Urzadzenia/urzadzeniadodajnrseryjny.cpp \
    Urzadzenia/urzadzeniadodajproducenta.cpp \
    Urzadzenia/urzadzenialista.cpp \
    Urzadzenia/urzadzenialistakontrahent.cpp \
    Ustawienia/statystyki.cpp \
    Ustawienia/ustawienia.cpp \
    baza.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    DataBase/checkfiles.h \
    DataBase/maindb.h \
    Info/info.h \
    Kontrahent/kontrahent.h \
    Kontrahent/kontrahentdodajkraj.h \
    Kontrahent/kontrahentdodajmiasto.h \
    Kontrahent/kontrahentdodajwojewodztwo.h \
    Kontrahent/kontrahentinfo.h \
    Kontrahent/kontrahentinfododajwpis.h \
    Kontrahent/kontrahentlista.h \
    Kontrahent/kontrahentshow.h \
    Kontrahent/tableviewlistakontrahentow.h \
    Timery/timedate.h \
    Urzadzenia/urzadzenia.h \
    Urzadzenia/urzadzeniadodajmodel.h \
    Urzadzenia/urzadzeniadodajnrseryjny.h \
    Urzadzenia/urzadzeniadodajproducenta.h \
    Urzadzenia/urzadzenialista.h \
    Urzadzenia/urzadzenialistakontrahent.h \
    Ustawienia/statystyki.h \
    Ustawienia/ustawienia.h \
    baza.h \
    mainwindow.h

FORMS += \
    Info/info.ui \
    Kontrahent/kontrahent.ui \
    Kontrahent/kontrahentdodajkraj.ui \
    Kontrahent/kontrahentdodajmiasto.ui \
    Kontrahent/kontrahentdodajwojewodztwo.ui \
    Kontrahent/kontrahentinfo.ui \
    Kontrahent/kontrahentinfododajwpis.ui \
    Kontrahent/kontrahentlista.ui \
    Kontrahent/kontrahentshow.ui \
    Urzadzenia/urzadzenia.ui \
    Urzadzenia/urzadzeniadodajmodel.ui \
    Urzadzenia/urzadzeniadodajnrseryjny.ui \
    Urzadzenia/urzadzeniadodajproducenta.ui \
    Urzadzenia/urzadzenialista.ui \
    Urzadzenia/urzadzenialistakontrahent.ui \
    Ustawienia/statystyki.ui \
    Ustawienia/ustawienia.ui \
    baza.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
