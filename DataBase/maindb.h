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
    void dBUrzadzenia();
    QString ZapytanieTestowe(QString Zapytanie);
    //void addProducent();
    QString addProducent(QString daneProducent);
    QString pobierzProducenta(QString daneProducent, int i);
    int pobierzProducentaiD(int daneProducentId);
    QString addModel(QString daneModel);
    QString pobierzModel(QString daneModel, int i);
    int pobierzModeliD(int daneModelId);
    QString isNumerSeryjnyTheSame(QString nrSeryjnyZLini, int i);
    int isNumerSeryjnyTheSameId(int nrSeryjnyZLini);
    QString addUrzadzenia(QString daneProducent,QString daneModel,QString daneNrSeryjny);
};

#endif // MAINDB_H
