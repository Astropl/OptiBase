#include "timedate.h"

//#include "Baza.h"
#include <cstring>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

TimeDate::TimeDate(QObject *parent) : QObject(parent)
{

}
void TimeDate::init() {}

//Wyodrebnię QStringi z minutami i godzinami i resztą

QString TimeDate::changeStringsMin(int minuta4)
{
    QString qStrMin4 = QString::number(minuta4);
    if (minuta4 < 10) {
        qStrMin4 = "0" + QString::number(minuta4);
    }
    return qStrMin4;
}
QString TimeDate::changeStringsSek(int sekunda4)
{
    QString qStrSek4 = QString::number(sekunda4);
    if (sekunda4 < 10) {
        qStrSek4 = "0" + QString::number(sekunda4);
    }
    return qStrSek4;
}
QString TimeDate::changeStringsGodz(int godzina4)
{
    QString qStrGodz4 = QString::number(godzina4);
    if (godzina4 < 10) {
        qStrGodz4 = "0" + QString::number(godzina4);
    }
    return qStrGodz4;
}
QString TimeDate::changeStringsDzien(int dzien4)
{
    QString qStrDzien4 = QString::number(dzien4);
    if (dzien4 < 10) {
        qStrDzien4 = "0" + QString::number(dzien4);
    }
    return qStrDzien4;
}
QString TimeDate::changeStringsMiesiac(int miesiac4)
{
    QString qStrMiesiac4 = QString::number(miesiac4);

    if (miesiac4 < 10) {
        qStrMiesiac4 = "0" + QString::number(miesiac4);
    }
    return qStrMiesiac4;
}
QString TimeDate::changeStringsDzienTygodnia(int dzienTygodnia4)
{
    QString stringDzienTygodnia4;
    switch (dzienTygodnia4) {
    case 1:
        stringDzienTygodnia4 = "Niedziela";
        break;
    case 2:
        stringDzienTygodnia4 = "Poniedziałek";
        break;
    case 3:
        stringDzienTygodnia4 = "Wtorek";
        break;
    case 4:
        stringDzienTygodnia4 = "Środa";
        break;
    case 5:
        stringDzienTygodnia4 = "Czwartek";
        break;
    case 6:
        stringDzienTygodnia4 = "Piątek";
        break;
    case 7:
        stringDzienTygodnia4 = "Sobota";
        break;
    }
    return stringDzienTygodnia4;
}