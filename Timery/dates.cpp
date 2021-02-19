#include "dates.h"
#include "QDebug"
#include "dates.h"
#include <cstring>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

Dates::Dates(QObject *parent)
    : QObject(parent)
{}

int Dates::DzienRoku(int d)
{
    time_t czas;
    tm timeinfo;
    time(&czas);
    timeinfo = *localtime(&czas);
    d = timeinfo.tm_yday;
    qWarning() << "dzien z ....: " << d;
    d++;
    return d;
}
QString Dates::znakZodiaku(QString d)
{qWarning () <<" Jestem w  Dates";
    time_t czas;
    tm timeinfo;
    time(&czas);
    timeinfo = *localtime(&czas);
    int miesiac = timeinfo.tm_mon;
    int dzien = timeinfo.tm_mday;
    //Testy dnia i miresiaa
    //miesiac =4;
    //dzien = 1;
    //Koniec testów
    miesiac = miesiac+1;
    qWarning() << "miesiac z ....: " << d;
    //Wodnik
    if (((miesiac == 1) || (miesiac == 2)) && ((dzien >= 20) || (dzien <= 18))) {
        qWarning() << "Mamy wodnika";
        d = "Wodnik";
    } else if (((miesiac == 2) || (miesiac == 3)) && ((dzien >= 19) || (dzien <= 19)))
{
        qWarning() << "Mamy Ryby";
        d = "Ryby";
    }
    else if (((miesiac == 3) || (miesiac == 4)) && ((dzien >= 21)|| (dzien <= 19))) {
        qWarning() << "Mamy Barana";
        d = "Baran";
    }
    else if (((miesiac == 4) || (miesiac == 5)) && ((dzien >= 20) || (dzien <= 22))) {
        qWarning() << "Mamy Byka";
        d = "Byk";
    }else if (((miesiac == 5) || (miesiac == 6)) && ((dzien >= 23) || (dzien <= 21))) {
        qWarning() << "Mamy Bliźnięta";
        d = "Bliźnięta";
    }
    else if (((miesiac == 6) || (miesiac == 7)) && ((dzien >= 22) || (dzien <= 22))) {
        qWarning() << "Mamy Raka";
        d = "Rak";
    }
    else if (((miesiac == 7) || (miesiac == 8)) && ((dzien >= 23) || (dzien <= 23))) {
        qWarning() << "Mamy Lwa";
        d = "Lew";
    }
    else if (((miesiac == 8) || (miesiac == 9)) && ((dzien >= 24) || (dzien <= 22))) {
        qWarning() << "Mamy Panne";
        d = "Panna";
    }else if (((miesiac == 9) || (miesiac == 10)) && ((dzien >= 23) || (dzien <= 22))) {
        qWarning() << "Mamy Wage";
        d = "Waga";
    }
    else if (((miesiac == 10) || (miesiac == 11)) && ((dzien >= 23) || (dzien <= 21))) {
        qWarning() << "Mamy Skorpiona";
        d = "Skorpion";
    }
    else if (((miesiac == 11) || (miesiac == 12)) && ((dzien >= 22) || (dzien <= 21))) {
        qWarning() << "Mamy Strzelca";
        d = "Strzelec";
    } else if (((miesiac == 12) || (miesiac == 1)) && ((dzien >= 22) || (dzien <= 19))) {
        qWarning() << "Mamy Koziorozca";
        d = "Koziorożec";
    }
    else {
        qWarning() << "Mamy cosik";
        d = "cosik";
    }
    qWarning() << "data i miesiac: "<<dzien<<" "<<miesiac;
    return d;
}
