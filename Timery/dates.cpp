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
