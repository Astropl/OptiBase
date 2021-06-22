#ifndef DATES_H
#define DATES_H
#include <QObject>

class Dates: public QObject
{
public:
    explicit Dates(QObject *parent = nullptr);

    Dates();



public:

    int DzienRoku (int dzien);
    QString znakZodiaku(QString d);
};



#endif // DATES_H
