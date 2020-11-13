#ifndef MAINDB_H
#define MAINDB_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
class MainDb : public QMainWindow
{
public:
    explicit MainDb(QWidget *parent = nullptr);
    void init();
    void DatabaseConnect();
    void DatabaseInit();
    void DatabasePopulate();

    void dBMiasta();
    void dBWojewodztwa();
    void dBKraj();
    void dBKontrahent();
    void dBProducent();
    void dBModel();
    void ZapytanieTestowe(QString Zapytanie);
};

#endif // MAINDB_H
