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
};



#endif // DATES_H
