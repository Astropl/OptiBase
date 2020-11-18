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
    //cout << "Zapytanie w mainDB odpowiedz: " + zapytanie.toStdString() << endl;
    // zapytanie
    return zapytanie;
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
QString MainDb::pobierzProducenta(QString daneProducent, int i)

{
        QSqlQuery query;
        QString testName;
        qWarning()<< "Pobrana ilosc producentow z ::Urzadzenia::" <<i;

        QString inti = QString::number(i);

QString name;
        if (query.exec("SELECT * FROM producenci where id ="+inti)) {
            while (query.next()) {
                qWarning() << query.value(1).toString();
                name = query.value(1).toString();
                            }
            qWarning() <<"udalo sie? : pozniej "<<name;
            return name;
        }
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

    QSqlQuery query;
}

void MainDb::dBProducent()
{
    qWarning("Tworzenie tabeli Producent ");
    QSqlQuery query(
        "CREATE TABLE IF NOT EXISTS producenci  (id INTEGER PRIMARY KEY, producent TEXT UNIQUE )");

    if (!query.isActive())
        qWarning() << " Tworzenie Tabeli - ERROR: " << query.lastError().text();
//NOTE:: dodoaje dwa przykładowe wpisy Producenci
//    if (!query.exec("INSERT INTO producenci (producent) VALUES('Selvas')"))
//        qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
//    if (!query.exec("INSERT INTO producenci (producent) VALUES('Jawon')"))
//        qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
}
void MainDb::dBModel()
{
    qWarning("Tworzenie tabeli Model Urzadzenia ");
    QSqlQuery query(
        "CREATE TABLE IF NOT EXISTS modele  (id INTEGER PRIMARY KEY, model TEXT UNIQUE )");

    if (!query.isActive())
        qWarning() << " Tworzenie Tabeli - ERROR: " << query.lastError().text();

    if (!query.exec("INSERT INTO modele (model) VALUES('IOI 353')"))
        qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
}

void MainDb::dBKontrahent()
{
    qWarning("Tworzenie tabeli Kontrahent ");
    QSqlQuery query("CREATE TABLE IF NOT EXISTS kontrahenci  (id INTEGER PRIMARY KEY, nazwaFirmy "
                    "TEXT UNIQUE, imie TEXT, nazwisko TEXT, panstwo TEXT, wojewodztwo TEXT, miasto "
                    "TEXT, kodPocztowy TEXT, ulica TEXT, nrDomu INTEGER, telefon TEXT, "
                    "telefonPrywatny TEXT, adresEmail TEXT, stronaUrl TEXT )");

    if (!query.isActive())
        qWarning() << " Tworzenie Tabeli - ERROR: " << query.lastError().text();

    if (!query.exec("INSERT INTO kontrahenci (nazwaFirmy , imie , nazwisko , panstwo , wojewodztwo "
                    ", miasto , kodPocztowy , ulica , nrDomu , telefon , telefonPrywatny , "
                    "adresEmail , stronaUrl ) VALUES('VITAKO' , 'Paweł' , 'Martys' , 'Polska' , "
                    "'Zachodniopomorskie' , 'Szczecin' , '71-766' , 'Małej Syrenki' , '2' , "
                    "'692717987' , '723508531' , 'serwis@vbody.pl' , 'www.vitako.pl')"))
        qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
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
    qWarning("Tworzenie tabeli Kraj ");
    QSqlQuery query(
        "CREATE TABLE IF NOT EXISTS panstwa  (id INTEGER PRIMARY KEY, panstwo TEXT UNIQUE )");

    if (!query.isActive())
        qWarning() << " Tworzenie Tabeli - ERROR: " << query.lastError().text();

    if (!query.exec("INSERT INTO panstwa (panstwo) VALUES('Polska')"))
        qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
}
