#include "maindb.h"
#include <iostream>
#include <QDebug>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>

using namespace std;

MainDb::MainDb(QWidget *parent)
    : QMainWindow(parent)
{
    cout << "Jestem w construktorze Init mainDB" << endl;
}
void MainDb::init()
{
    cout << "Jestem w Init mainDB" << endl;
    DatabaseConnect();
    DatabaseInit();
    DatabasePopulate();
}
void MainDb::ZapytanieTestowe(QString zapytanie)

{
    //TODO: Stworzyc zapytanie i go wyswietlic

    //Proste testowe zapytanie
    cout<<"Jestem w Main DB proste zapytanie"<<endl;
    //zapytanie . query.exec("SELECT ");
    //zapytanie = QSqlQuery query(
       // "SELECT * FROM kontrahenci");

//    if (!query.isActive())
//        qWarning() << " MainWindow::DatabaseInit - ERROR: " << query.lastError().text();
}
void MainDb::DatabaseConnect()
{
    qWarning("Database Connect");
    const QString DRIVER("QSQLITE");
    if (QSqlDatabase::isDriverAvailable(DRIVER)) {
        QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);
        db.setDatabaseName("C:/Users/pawel/Documents/Cplusplus/OptiBase/OptiBase/DataBase/1003.db");
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

    if (!query.exec("INSERT INTO producenci (producent) VALUES('Selvas')"))
        qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
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
