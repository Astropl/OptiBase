#ifndef MAINDB_H
#define MAINDB_H

#include <QMainWindow>

class mainDB : public QMainWindow
{
    Q_OBJECT
public:
    explicit mainDB(QWidget *parent = nullptr);
void init();
void DatabaseConnect();
void DatabasePopulate();
void dBWczytajNazwyPlikow();
void dBMainTable();
void dBFileNames();
void addFileName();
int pobierzIloscPlikow(int iloscPlikow);
void dBWczytajSuroweDane();
void dBSourceDates();


signals:

};

#endif // MAINDB_H
