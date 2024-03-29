#ifndef MAINDB_H
#define MAINDB_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
//#include <QSqlQuery>


class MainDb : public QMainWindow
{
public:
    explicit MainDb(QWidget *parent = nullptr);
    void init();
    //1*Tworzenie i inicjalizacja BD
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
    void dBBaza();
    void dBPrzypomnienie();
    void dBStatistisc();
    void dBWazneDaty();
     //*1 Tworzenie i inicjalizacja BD

    void PrzypiszTestowo();
    void dBInfoOTemacie();
    void dBCheckInit();
    int checkFlagsProducent(int checkFlagsVariableProducent);
    int checkFlagsProducentInsert1(int checkFlagsVariableProducent);
int checkFlagsModel(int checkFlagsVariableModel);
int checkFlagsModelInsert1(int checkFlagsVariableModel);

    QString ObliczCzasUruchomien(QString DbSec, QString DbMin, QString DbGodz, QString DbDni);
    int PobierzCzasUruchomien(int DbSec,int dBMin,int DbGodz, int DbDni);

    int PobierzCzasUruchomienDbSec(int DbSec);

    int PobierzCzasUruchomienDbMin(int DbMin);

    int PobierzCzasUruchomienDbGodz(int DbGodz);

    int PobierzCzasUruchomienDbDni(int DbDni);
    int pobierzIloscTematowiD(int iloscTematowId);
    QString dodajIloscTematow(QString qIloscTematow);
    QString pobierzIloscTematow(QString qIloscTematow,int i);
    QString loadDataRemiderAll(QString remiderSelf, int i, int n);
    QString UrzadzeniaDelete (QString numerSeryjny);
    QString pobierzNumerWpisu(QString QnrWpisu);
    QString ZapytanieTestowe(QString Zapytanie);

    QString addKontrahent(QString l1,QString l2,QString l3,QString l4,QString l5,QString l6,QString l7,QString l8, QString l9,QString l10,QString l11,QString l12,QString l13);
    QString addKontrahenciUpdate (QString tym1, QString tym2, QString tym3,QString tym4, QString tym5,QString tym6,QString tym7,QString tym8,QString tym9,QString tym10,QString tym11,QString tym12,QString tym13);
    QString pobierzKontrahenta(QString daneKontrahent, int i, int d);
    int pobierzKontrahentaId(int daneKontrahentId);
    QString pobierzUrzadzenia(QString daneUrzadzenia, int i, int d);
    int pobierzUrzadzeniaId(int daneUrzadzeniaId);
    QString addProducent(QString daneProducent);
    QString pobierzProducenta(QString daneProducent, int i);
    int pobierzProducentaiD(int daneProducentId);
    QString addModel(QString daneModel);
    QString pobierzModel(QString daneModel, int i);
    int pobierzModeliD(int daneModelId);
    QString isNumerSeryjnyTheSame(QString nrSeryjnyZLini, int i);
    int isNumerSeryjnyTheSameId(int nrSeryjnyZLini);
    QString addUrzadzenia(QString daneProducent,QString daneModel,QString daneNrSeryjny,QString przypisany);
    //QString addUrzadzeniaUpdate( QString daneNrSeryjny);
    QString addUrzadzeniaUpdate(QString daneNrSeryjny, QString daneUnicueName);

    QString pobierzKraj(QString daneModel, int i);
    int pobierzKrajId(int pobierzKrajId);
    QString addKraj(QString daneKraj);
    int pobierzWojewodztwoId(int pobierzKrajId);
    QString pobierzWojewodztwo(QString daneModel, int i);
    QString addWojewodztwo(QString daneWojewodztwo);
    QString addMiasto(QString daneMiasto);
    QString pobierzMiasto(QString daneModel, int i);
    int pobierzMiastoiD(int daneModelId);
    int pobierzUrzKontiD(int daneProducentId);
    QString pobierzUrzKont(QString daneProducent, int i, int d);
    int pobierzKontrahentaZNrSeryjnymId(int daneKontrahentId);
    QString pobierzKontrahentaZNrSeryjnym(QString daneKontrahent, int i, int d);
    QString pobierzNumerSeryjnyZKontrahenta (QString pobierzNumerSeryjny);
    QString addPrzypomnienie(QString nrWpisu, QString dataWpisu,QString tematWpisu,QString trescWpisu,QString przypomnienie,QString dataNajblPrzypom,QString tekstPrzypom,QString nrSeryjny );
    int loadDataRemiderId(int dataRemiderId);
    QString loadDataRemider(QString remiderSelf, int i,int n,QString numerSeryjnydoPorownania);
    QString addUrzadzeniaUpdate(QString ty1,
                                        QString ty2,
                                        QString ty3,
                                        QString ty4);
    int iloscUruchomienSave (int iloscUruchomien);
    int iloscUruchomienFirst (int iloscUruchomienFirst);
    int pobierzWazneDatyiD(int iloscWpisow);
QString pobierzWazneDatyAddYear(QString data, QString futureData);

    QString pobierzWazneDaty(QString daneProducent, int i, int d);
    QString pobierzWazneDatyZapis(QString qdata, QString temat , QString info );

    int pobierzUrzadzeniaIdzMagazynu(int daneUrzadzeniaId, QString nazwaUrzadzenia);
    void dBSettings ();
    QString addDBSettings (QString codziennyBackup, QString sciezkaBakupu);
QString dBSettingsUstaw (QString ustawUstawienia);
};
//QSqlQuery query;
#endif // MAINDB_H
