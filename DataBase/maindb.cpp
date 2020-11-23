#include "maindb.h"
#include "Urzadzenia/urzadzenia.h"
#include <iostream>
#include <QDebug>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>

using namespace std;

QSqlRecord idName;

MainDb::MainDb(QWidget *parent)
    : QMainWindow(parent)
{
    //cout << "Jestem w construktorze Init mainDB" << endl;
}
void MainDb::init()
{ //Urzadzenia *urzadz = new Urzadzenia(this);
    //cout << "Jestem w Init mainDB" << endl;
    DatabaseConnect();
    DatabaseInit();
    DatabasePopulate();
}
QString MainDb::ZapytanieTestowe(QString zapytanie)

{
    //TODO: Stworzyc zapytanie i go wyswietlic

    //Proste testowe zapytanie
    //cout << "Jestem w Main DB proste zapytanie" << endl;
    QSqlQuery query;
    query.prepare("SELECT miasto FROM miasta");

    if (!query.exec())
        qWarning() << "Error w zapytaniu" << query.lastError().text();
    if (query.first()) {
        zapytanie = query.value(0).toString();
    } else {
        zapytanie = "Dane nie znalezione";
    }

    return zapytanie;
}

QString MainDb::addKontrahent(QString l1,
                              QString l2,
                              QString l3,
                              QString l4,
                              QString l5,
                              QString l6,
                              QString l7,
                              QString l8,
                              QString l9,
                              QString l10,
                              QString l11,
                              QString l12,
                              QString l13)
{
    //Zapisuje do bazy Urzadzenia

    QSqlQuery query;
    qWarning() << ("Dodoaje do bazy " + l1 + " , "  + l2 + " , " + l3 + " , " + l4
                   + " , " + l6 + " , " + l5 + " , " + l7 + " , " + l8 + " , " + l9 + " , " + l10
                   + " , " + l11 + " , " + l12 + " , " + l13);
    if (!query.exec("INSERT INTO kontrahenci (nazwaFirmy, imie , nazwisko , kontrahent_panstwo_id , kontrahent_wojewodztwo_id , kontrahent_miasto_id , kodPocztowy , ulica , nrDomu , telefon , telefonPrywatny , adresEmail , stronaUrl) VALUES('" + l1 + "','"+l2+ "','"+l3+ "','"+l4+ "','"+l6+ "','"+l5+ "','"+l7+ "','"+l8+ "','"+l9+ "','"+l10+ "','"+l11+ "','"+l12+ "','"+l13 +"')"))

{
        qWarning() << "MainDB::Dodoanie Urzadzenia - ERROR: " << query.lastError().text();
}
    else
    {
        qWarning() << "MainDB::Dodoanie Kontrahenci - Udane: " << query.lastError().text();
    }
    return 0;
}
void MainDb::dBKontrahent()
{
    qWarning("Tworzenie tabeli Kontrahent ");
    QSqlQuery query("CREATE TABLE IF NOT EXISTS kontrahenci  (id INTEGER PRIMARY KEY, nazwaFirmy "
                    "TEXT UNIQUE, imie TEXT, nazwisko TEXT, kontrahent_panstwo_id TEXT, "
                    "kontrahent_wojewodztwo_id TEXT, kontrahent_miasto_id TEXT, kodPocztowy TEXT, "
                    "ulica TEXT, nrDomu INTEGER, telefon TEXT, "
                    "telefonPrywatny TEXT, adresEmail TEXT, stronaUrl TEXT, FOREIGN KEY "
                    "(kontrahent_panstwo_id) REFERENCES panstwa(panstwo), FOREIGN KEY "
                    "(kontrahent_wojewodztwo_id) REFERENCES wojewodztwa (wojewodztwo), FOREIGN KEY "
                    "(kontrahent_miasto_id) REFERENCES miasta (miasto))");

    if (!query.isActive())
        qWarning() << " Tworzenie Tabeli - ERROR: " << query.lastError().text();

    if (!query.exec("INSERT INTO kontrahenci (nazwaFirmy, imie , nazwisko , kontrahent_panstwo_id "
                    ", kontrahent_wojewodztwo_id , kontrahent_miasto_id , kodPocztowy , ulica , "
                    "nrDomu , telefon , telefonPrywatny , adresEmail , stronaUrl  ) "
                    "VALUES('VITAKO' , 'Paweł' , 'Martys' , 'Polska' , "
                    "'Zachodniopomorskie' , 'Szczecin' , '71-766' , 'Małej Syrenki' , '2' , "
                    "'692717987' , '723508531' , 'serwis@vbody.pl' , 'www.vitako.pl')"))
        qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
}
QString MainDb::pobierzUrzadzenia(QString daneUrzadzenia, int i, int d)
{
    QSqlQuery query;
    QString testName;
    qWarning() << "Pobrana ilosc Urzadzenia z ::Uradzernia::Lista" << i   + d;

    QString inti = QString::number(i);

    QString name;
    if (query.exec("SELECT * FROM urzadzenia where id =" + inti)) {
        while (query.next()) {
            qWarning() << query.value(d).toString();
            name = query.value(d).toString();
        }
        qWarning() << "udalo sie? : pozniej " << name;
        return name;
    }

}
int MainDb::pobierzUrzadzeniaId(int daneUrzadzeniaId)
{
    qWarning() << "Jestem w MainDB->pobierz Id.";
    QString testName;
    int rows = 0;
    //TODO: pobrac z Bazy Modeli
    QSqlQuery query;

    if (query.exec("SELECT * FROM urzadzenia")) {
        while (query.next()) {
            qWarning() << query.value(1).toString();
            rows++;
        }
        qWarning() << "row to: " << rows;
    }
    qWarning() << "Wychodze z MainDB->pobierz Id z pobraną iloscia wpisów w bazie danych";
    daneUrzadzeniaId = rows;
    return rows;
}
QString MainDb::pobierzKontrahenta(QString daneKontrahent, int i)
{
    QSqlQuery query;
    QString testName;
    qWarning() << "Pobrana ilosc Kontrahenci z ::KontrahenciPaństwa::" << i;

    QString inti = QString::number(i);

    QString name;
    if (query.exec("SELECT * FROM kontrahenci where id =" + inti)) {
        while (query.next()) {
            qWarning() << query.value(1).toString();
            name = query.value(1).toString();
        }
        qWarning() << "udalo sie? : pozniej " << name;
        return name;
    }

}
int MainDb::pobierzKontrahentaId(int daneKontrahentId)
{
    qWarning() << "Jestem w MainDB->pobierz Id.";
    QString testName;
    int rows = 0;
    //TODO: pobrac z Bazy Modeli
    QSqlQuery query;

    if (query.exec("SELECT * FROM kontrahenci")) {
        while (query.next()) {
            qWarning() << query.value(1).toString();
            rows++;
        }
        qWarning() << "row to: " << rows;
    }
    qWarning() << "Wychodze z MainDB->pobierz Id z pobraną iloscia wpisów w bazie danych";
    daneKontrahentId = rows;
    return rows;
}

QString MainDb::addUrzadzenia(QString daneProducent, QString daneModel, QString daneNrSeryjny, QString przypisany)
{
    //Zapisuje do bazy Urzadzenia

    QSqlQuery query;
    qWarning() << ("Dodoaje do bazy " + daneModel);
    if (!query.exec("INSERT INTO urzadzenia (urzadzenia_producent_id, urzadzenia_model_id, "
                    "numerSeryjny, przypisany) VALUES('"
                    + daneProducent + "','" + daneModel + "','" + daneNrSeryjny +"','" + przypisany + "' )")) {
        qWarning() << "MainDB::Dodoanie Urzadzenia - ERROR: " << query.lastError().text();
    } else {
        qWarning() << "MainDB::Dodoanie Urzadzenia - Udane: " << query.lastError().text();
    }
    return 0;
}
QString MainDb::addProducent(QString daneProducent)

{
    //TODO: dodoac do Bazy producenta
    QSqlQuery query;
    qWarning() << ("Dodoaje do bazy " + daneProducent);
    if (!query.exec("INSERT INTO producenci (producent) VALUES('" + daneProducent + "')"))
        qWarning() << "MainDB::Dodoanie Producenta - ERROR: " << query.lastError().text();
    return 0;
}
QString MainDb::addModel(QString daneModel)

{
    //TODO: dodoac do Bazy producenta
    QSqlQuery query;
    qWarning() << ("Dodoaje do bazy " + daneModel);
    if (!query.exec("INSERT INTO modele (model) VALUES('" + daneModel + "')"))
        qWarning() << "MainDB::Dodoanie Modelu - ERROR: " << query.lastError().text();
    return 0;
}
QString MainDb::addKraj(QString daneKraj)

{
    //TODO: dodoac do Bazy producenta
    QSqlQuery query;
    qWarning() << ("Dodoaje do bazy " + daneKraj);
    if (!query.exec("INSERT INTO panstwa (panstwo) VALUES('" + daneKraj + "')"))
        qWarning() << "MainDB::Dodoanie Modelu - ERROR: " << query.lastError().text();
    return 0;
}
QString MainDb::addWojewodztwo(QString daneWojewodztwo)

{
    //TODO: dodoac do Bazy producenta
    QSqlQuery query;
    qWarning() << ("Dodoaje do bazy " + daneWojewodztwo);
    if (!query.exec("INSERT INTO wojewodztwa (wojewodztwo) VALUES('" + daneWojewodztwo + "')"))
        qWarning() << "MainDB::Dodoanie Modelu - ERROR: " << query.lastError().text();
    return 0;
}
QString MainDb::addMiasto(QString daneMiasto)

{
    //TODO: dodoac do Bazy producenta
    QSqlQuery query;
    qWarning() << ("Dodoaje do bazy " + daneMiasto);
    if (!query.exec("INSERT INTO miasta (miasto) VALUES('" + daneMiasto + "')"))
        qWarning() << "MainDB::Dodoanie Modelu - ERROR: " << query.lastError().text();
    return 0;
}
QString MainDb::pobierzKraj(QString daneModel, int i)
{
    QSqlQuery query;
    QString testName;
    qWarning() << "Pobrana ilosc Kraji z ::Państwa::" << i;

    QString inti = QString::number(i);

    QString name;
    if (query.exec("SELECT * FROM panstwa where id =" + inti)) {
        while (query.next()) {
            qWarning() << query.value(1).toString();
            name = query.value(1).toString();
        }
        qWarning() << "udalo sie? : pozniej " << name;
        return name;
    }
}
int MainDb::pobierzKrajId(int pobierzKrajId)

{
    qWarning() << "Jestem w MainDB->pobierz Id.";
    QString testName;
    int rows = 0;
    //TODO: pobrac z Bazy Modeli
    QSqlQuery query;

    if (query.exec("SELECT * FROM panstwa")) {
        while (query.next()) {
            qWarning() << query.value(1).toString();
            rows++;
        }
        qWarning() << "row to: " << rows;
    }
    qWarning() << "Wychodze z MainDB->pobierz Id z pobraną iloscia wpisów w bazie danych";
    return rows;
}

QString MainDb::pobierzWojewodztwo(QString daneModel, int i)
{
    QSqlQuery query;
    QString testName;
    qWarning() << "Pobrana ilosc Kraji z ::Państwa::" << i;

    QString inti = QString::number(i);
    QString name;
    if (query.exec("SELECT * FROM wojewodztwa where id =" + inti)) {
        while (query.next()) {
            qWarning() << query.value(1).toString();
            name = query.value(1).toString();
        }
        qWarning() << "udalo sie? : pozniej " << name;
        return name;
    }
}
int MainDb::pobierzWojewodztwoId(int pobierzWojewodztwoId)

{
    qWarning() << "Jestem w MainDB->pobierz Id.";
    QString testName;
    int rows = 0;
    //TODO: pobrac z Bazy Modeli
    QSqlQuery query;

    if (query.exec("SELECT * FROM wojewodztwa")) {
        while (query.next()) {
            qWarning() << query.value(1).toString();
            rows++;
        }
        qWarning() << "row to: " << rows;
    }
    qWarning() << "Wychodze z MainDB->pobierz Id z pobraną iloscia wpisów w bazie danych";
    return rows;
}

QString MainDb::pobierzModel(QString daneModel, int i)

{
    QSqlQuery query;
    QString testName;
    qWarning() << "Pobrana ilosc modeli z ::Urzadzenia::" << i;

    QString inti = QString::number(i);

    QString name;
    if (query.exec("SELECT * FROM modele where id =" + inti)) {
        while (query.next()) {
            qWarning() << query.value(1).toString();
            name = query.value(1).toString();
        }
        qWarning() << "udalo sie? : pozniej " << name;
        return name;
    }
}

int MainDb::pobierzModeliD(int daneModelId)

{
    qWarning() << "Jestem w MainDB->pobierz Id.";
    QString testName;
    int rows = 0;
    //TODO: pobrac z Bazy Modeli
    QSqlQuery query;

    if (query.exec("SELECT * FROM modele")) {
        while (query.next()) {
            qWarning() << query.value(1).toString();
            rows++;
        }
        qWarning() << "row to: " << rows;
    }
    qWarning() << "Wychodze z MainDB->pobierz Id z pobraną iloscia wpisów w bazie danych";
    return rows;
}
QString MainDb::pobierzMiasto(QString daneModel, int i)

{
    QSqlQuery query;
    QString testName;
    qWarning() << "Pobrana ilosc miasta z ::kontrahenta::" << i;

    QString inti = QString::number(i);

    QString name;
    if (query.exec("SELECT * FROM miasta where id =" + inti)) {
        while (query.next()) {
            qWarning() << query.value(1).toString();
            name = query.value(1).toString();
        }
        qWarning() << "udalo sie? : pozniej " << name;
        return name;
    }
}

int MainDb::pobierzMiastoiD(int daneModelId)

{
    qWarning() << "Jestem w MainDB->pobierz Id.";
    QString testName;
    int rows = 0;
    //TODO: pobrac z Bazy Modeli
    QSqlQuery query;

    if (query.exec("SELECT * FROM miasta")) {
        while (query.next()) {
            qWarning() << query.value(1).toString();
            rows++;
        }
        qWarning() << "row to: " << rows;
    }
    qWarning() << "Wychodze z MainDB->pobierz Id z pobraną iloscia wpisów w bazie danych";
    return rows;
}

int MainDb::pobierzProducentaiD(int daneProducentId)

{
    qWarning() << "Jestem w MainDB->pobierz Id.";
    QString testName;
    int rows = 0;
    //TODO: pobrac z Bazy producenta
    QSqlQuery query;

    if (query.exec("SELECT * FROM producenci")) {
        while (query.next()) {
            qWarning() << query.value(1).toString();
            rows++;
        }
        qWarning() << "row to: " << rows;
    }
    qWarning() << "Wychodze z MainDB->pobierz Id z pobraną iloscia wpisów w bazie danych";
    return rows;
}
QString MainDb::pobierzProducenta(QString daneProducent, int i)

{
    QSqlQuery query;
    QString testName;
    qWarning() << "Pobrana ilosc producentow z ::Urzadzenia::" << i;

    QString inti = QString::number(i);

    QString name;
    if (query.exec("SELECT * FROM producenci where id =" + inti)) {
        while (query.next()) {
            qWarning() << query.value(1).toString();
            name = query.value(1).toString();
        }
        qWarning() << "udalo sie? : pozniej " << name;
        return name;
    }
}

void MainDb::DatabaseConnect()
{
    qWarning("Database Connect");
    const QString DRIVER("QSQLITE");
    if (QSqlDatabase::isDriverAvailable(DRIVER)) {
        QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);
        db.setDatabaseName(
            "C:/Users/pawel/Documents/Cplusplus/OptiBase/OptiBase/DataBase/2020.11.17.db");
        qWarning(" Powstała baza");

        if (db.open()) {
            qWarning() << (" Otwarto DB") << db.lastError().text();
            qWarning() << (" Otwarto DB") << db.isDriverAvailable(DRIVER);
            //qWarning() << (" Otwarto DB") << db.connectOptions().
        } else {
            qWarning() << (" Brak otwarcia") << db.lastError().text();
        }
    }
}

void MainDb::DatabaseInit()
{
    qWarning("Database init ");
    QSqlQuery query("CREATE TABLE IF NOT EXISTS people  (id INTEGER PRIMARY KEY, name TEXT)");

    if (!query.isActive())
        qWarning() << " MainWindow::DatabaseInit - ERROR: " << query.lastError().text();
}
void MainDb::DatabasePopulate()
{
    qWarning("Database Wypelnianiae");

    dBMiasta();
    dBWojewodztwa();
    dBKraj();
    dBKontrahent();
    dBProducent();
    dBModel();
    dBUrzadzenia();

    //QSqlQuery query;
}
void MainDb::dBUrzadzenia()
{
    QSqlQuery query;
    query.exec("PRAGMA foreign_keys = ON;"); // włączenia kluczy obcych
    qWarning("Tworzenie tabeli Urzadzenia ");
    query.exec("CREATE TABLE IF NOT EXISTS urzadzenia  (id INTEGER PRIMARY KEY, urzadzenia_producent_id TEXT, urzadzenia_model_id TEXT, numerSeryjny TEXT UNIQUE, przypisany TEXT, FOREIGN KEY (urzadzenia_producent_id) REFERENCES producenci(producent),FOREIGN KEY (urzadzenia_model_id) REFERENCES modele(model))");
    if (!query.isActive())
        qWarning() << "1. Tworzenie Tabeli - ERROR: " << query.lastError().text();

//    if (!query.exec("INSERT INTO urzadzenia (urzadzenia_producent_id , urzadzenia_model_id, "
//                    "numerSeryjny) VALUES('Jawon', 'IOI-353', 'AP00034232-324222')"))
//        qWarning() << "2. MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();

//    if (!query.exec("INSERT INTO urzadzenia (urzadzenia_producent_id , urzadzenia_model_id, "
//                    "numerSeryjny) VALUES('Selvas', 'BC-380', 'AP4222')"))
//        qWarning() << "3. MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
}
void MainDb::dBProducent()
{
    qWarning("Tworzenie tabeli Producent ");
    QSqlQuery query(
        "CREATE TABLE IF NOT EXISTS producenci  (id INTEGER PRIMARY KEY, producent TEXT UNIQUE )");

    if (!query.isActive())
        qWarning() << " Tworzenie Tabeli - ERROR: " << query.lastError().text();
    //NOTE:: dodoaje dwa przykładowe wpisy Producenci
}
void MainDb::dBModel()
{
    qWarning("Tworzenie tabeli Model Urzadzenia ");
    QSqlQuery query(
        "CREATE TABLE IF NOT EXISTS modele  (id INTEGER PRIMARY KEY, model TEXT UNIQUE )");

    //NOTE:: dodoaje dwa przykładowe wpisy Modeli
    //    if (!query.isActive())
    //        qWarning() << " Tworzenie Tabeli - ERROR: " << query.lastError().text();

    //    if (!query.exec("INSERT INTO modele (model) VALUES('IOI 353')"))
    //        qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
}

void MainDb::dBMiasta()
{
    qWarning("Tworzenie tabeli Miasta ");
    QSqlQuery query(
        "CREATE TABLE IF NOT EXISTS miasta  (id INTEGER PRIMARY KEY, miasto TEXT UNIQUE )");

    if (!query.isActive())
        qWarning() << " Tworzenie Tabeli - ERROR: " << query.lastError().text();

    if (!query.exec("INSERT INTO miasta (miasto) VALUES('Warszawa')"))
        qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
}
void MainDb::dBWojewodztwa()
{
    qWarning("Tworzenie tabeli Wojewdztwa ");
    QSqlQuery query("CREATE TABLE IF NOT EXISTS wojewodztwa  (id INTEGER PRIMARY KEY, wojewodztwo "
                    "TEXT UNIQUE )");

    if (!query.isActive())
        qWarning() << " Tworzenie Tabeli - ERROR: " << query.lastError().text();

    if (!query.exec("INSERT INTO wojewodztwa (wojewodztwo) VALUES('Zachodniopomorskie')"))
        qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
}
void MainDb::dBKraj()
{
    QSqlQuery query;
    qWarning("Tworzenie tabeli Kraj ");
    query.exec(
        "CREATE TABLE IF NOT EXISTS panstwa  (id INTEGER PRIMARY KEY, panstwo TEXT UNIQUE )");

    if (!query.isActive())
        qWarning() << " Tworzenie Tabeli - ERROR: " << query.lastError().text();

    if (!query.exec("INSERT INTO panstwa (panstwo) VALUES('Polska')"))
        qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
    if (!query.exec("INSERT INTO panstwa (panstwo) VALUES('Nuemcy')"))
        qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
}

QString MainDb::isNumerSeryjnyTheSame(QString nrSeryjnyZLini, int i)
{
    QSqlQuery query;
    QString testName;
    qWarning() << "Pobrana ilosc Urzadzen z ::Urzadzenia::" << i;

    QString inti = QString::number(i);

    QString name;
    if (query.exec("SELECT * FROM urzadzenia where id =" + inti)) {
        while (query.next()) {
            qWarning() << inti << " pobrany: " << query.value(3).toString();
            name = query.value(3).toString();
        }
        qWarning() << "udalo sie? : pozniej " << name;
        return name;
    }
}
int MainDb::isNumerSeryjnyTheSameId(int nrSeryjnyZLini)
{
    qWarning() << "Jestem w MainDB::isNumerSeryjnyTheSameId";
    qWarning() << "Przekazany Numer seryjny wprowadzany" << nrSeryjnyZLini;

    //TODO: Wczytac z bazy urzadzenia same numery seryjne

    QString testName;
    int rows = 0;
    //TODO: pobrac z Bazy Urzadzeń same numery seryjne
    QSqlQuery query;

    if (query.exec("SELECT * FROM urzadzenia")) {
        while (query.next()) {
            qWarning() << query.value(1).toString();
            rows++;
        }
        qWarning() << "row to: " << rows;
    }
    qWarning() << "Wychodze z MainDB->pobierz Id z pobraną iloscia wpisów w bazie danych";
    return rows;
}