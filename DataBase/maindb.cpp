#include "maindb.h"
#include <iostream>
#include <QDebug>
#include <QString>
#include <QDir>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>

#include <map>
#include <list>
#include <stdlib.h>
#include <QList>
#include <fstream>


using namespace std;

QStringList images;
fstream  fileName;
string filePatch = "C:/Accuniq/Standalone/INTERFACE WRITE/";

mainDB::mainDB(QWidget *parent) : QMainWindow(parent)
{

}
void mainDB::init()
{
    // inicjalizacja Bazy
    qWarning ()<<"Initializacja Bazy";
    DatabaseConnect();
    DatabasePopulate();
}

void mainDB::DatabaseConnect()
{
    qWarning("Database Connect");
    const QString DRIVER("QSQLITE");
    if (QSqlDatabase::isDriverAvailable(DRIVER)) {
        QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);
        db.setDatabaseName(
                    "C:/Users/pawel/Documents/Cplusplus/Analizav2/DataBase/2021.06.11.db");
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

void mainDB::DatabasePopulate()
{
    qWarning("Database Wypelnianiae");
    dBFileNames();
    dBSourceDates();
    dBWczytajNazwyPlikow();
    dBWczytajSuroweDane();

    //    dBMiasta();
    //    dBWojewodztwa();
    //    dBKraj();
    //    dBProducent();
    //    dBModel();
    //    dBUrzadzenia();
    //    dBKontrahent();
    //    dBBaza();
    //    dBPrzypomnienie();
    //    dBStatistisc();
    //    dBInfoOTemacie();
    //    dBWazneDaty();

    //QSqlQuery query;
}

void mainDB::dBWczytajSuroweDane()
{
    qDebug ()<< "Start::dBWczytajSuroweDane";

    QSqlQuery query;

    for (int x =0 ;x<=images.size()-1;x++) //1 poniewaz 0 to wpis testowy
    {//fileName.close();
        cout<< "Wczytuje plik " + (images.at(x).toStdString())<<endl;
        //string qFileName = images.at(x).toStdString();

        //wczytac dane z plikow
        //fileName.open(images.at(x).toStdString(),ios::in );


        fileName.open(filePatch +images.at(x).toStdString(),ios::in );
        //qDebug ()<< "Wchdze do If poraz " <<x;
        if( fileName.good() == true )
        {
            cout << "Uzyskano dostep do pliku!" << endl;
            //tu operacje na pliku
            string str; // bufor danych

            while(!fileName.eof())
                // while (fileName>>str)
            { // dopuki nie osiągnięto końca pliku
                getline(fileName, str); // wczytywanie linii tesktu z pliku (do znaku końca linii) do zmiennej typu string
                //cout<<"str??"<<endl;
                cout<<str<<endl;
                //cout<<"end::str??"<<endl;

                QSqlQuery query;
                QString str1 = "check";

                //TODO: Trzeba rodzieclic dane na pojedyncze komórki.


                if (!query.exec("INSERT INTO SourceDatess (data , godzina , IDMrn , name , Hight , Year_ofBirth , sex  , Weight, temp1 , temp2 , temp3 , temp4 , temp5 , temp6 , temp7 , temp8 , temp9 , temp10) VALUES('" + str1 + "','"+ str1 + "','"+ str1 + "','"+ str1 + "','"+ str1 + "','"+ str1 + "','"+ str1 + "','"+ str1 + "','"+ str1 + "','" + str1 + "','"+  str1 + "','"+ str1 + "','" + str1 + "','" + str1 + "','" + str1 + "','" + str1 + "','" + str1 + "','" + str1 + "')"))
                {
                    qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
                }

                fileName.close();
            }
        }
        else

        {
            cout << "Dostep do pliku zostal zabroniony!: " <<+"."+images.at(x).toStdString()+"."<< endl;
        }


        //dodac do bazy.
    }
    fileName.close();
    qDebug ()<< "END::dBWczytajSuroweDane";
}

void mainDB::dBWczytajNazwyPlikow()
{

    QStringList nazwaPliku;


    QDir directory("C:/Accuniq/Standalone/INTERFACE WRITE/");
    //images = directory.entryList(QStringList() << "*.txt" << "*.txt",QDir::Files); ///pliki text
    images = directory.entryList(QStringList() << "*.csv" << "*.csv",QDir::Files); ///pliki csv
    cout<<"'Ilosc plikow: "<<images.length()<<endl;
    qDebug ()<< " Entry in loop";
    for (int x =0 ;x<=images.size()-1;x++)
    {
        //qDebug ()<< images.at(x);
    }
    addFileName();
}
void mainDB::addFileName()
{QSqlQuery query;
    for (int x =0 ;x<=images.size()-1;x++)
    {
        //qDebug ()<< images.at(x);


        if (!query.exec("INSERT INTO FilesNames (fileName) VALUES('" + images.at(x) + "')"))
            qWarning() << "MainDB::FileNames - ERROR: " << query.lastError().text();
        //return 0;
    }
}
int mainDB::pobierzIloscPlikow(int iloscPlikow)
{
    QSqlQuery query;
    //QString testName;
    int rows = 0;
    if (query.exec("SELECT * FROM FilesNames")) {
        while (query.next()) {
            rows++;
        }
    }
    iloscPlikow = rows;
    return rows;
}

void mainDB::dBFileNames()
{
    QSqlQuery query;
    query.exec("PRAGMA foreign_keys = ON;"); // włączenia kluczy obcych
    qWarning("Tworzenie tabeli FilesNames ");
    query.exec("CREATE TABLE IF NOT EXISTS FilesNames  (id INTEGER PRIMARY KEY, fileName TEXT UNIQUE )");

    if (!query.isActive()) {
        qWarning() << " Tworzenie Tabeli - ERROR: " << query.lastError().text();
    }
    // query.exec("PRAGMA foreign_keys = ON;"); // włączenia kluczy obcych
    if (!query.exec("INSERT INTO FilesNames (fileName) VALUES('file_test_temp')")) {
        qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
    }
    qWarning("Tworzenie tabeli FilesName - Zakończone ");
}
void mainDB::dBSourceDates()
{QSqlQuery query;
    qWarning("Tworzenie tabeli dane zrodłowe ");
    query.exec("CREATE TABLE IF NOT EXISTS SourceDatess  (id INTEGER PRIMARY KEY, data TEXT, godzina TEXT, IDMrn TEXT, name TEXT, Hight TEXT, Year_ofBirth TEXT, sex  TEXT, Weight TEXT, temp1 TEXT, temp2 TEXT, temp3 TEXT,temp4 TEXT,temp5 TEXT,temp6 TEXT,temp7 TEXT,temp8 TEXT,temp9 TEXT,temp10 TEXT )");

    if (!query.isActive()) {
        qWarning() << " Tworzenie Tabeli - ERROR: " << query.lastError().text();
    }
    // query.exec("PRAGMA foreign_keys = ON;"); // włączenia kluczy obcych
    if (!query.exec("INSERT INTO SourceDatess (data , godzina , IDMrn , name , Hight , Year_ofBirth , sex  , Weight, temp1 , temp2 , temp3 , temp4 , temp5 , temp6 , temp7 , temp8 , temp9 , temp10) VALUES('2021.01.01', '09:00', '00001', 'Testowy', '200', '25', 'Mężczyzna', '80', '1', '2', '3', '4', '5', '6', '7', '8', '9', '10')")) {
        qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
    }
    qWarning("Tworzenie tabeli FilesName - Zakończone ");
}

void mainDB::dBMainTable()
{
    //    QSqlQuery query;
    //    query.exec("PRAGMA foreign_keys = ON;"); // włączenia kluczy obcych
    //    qWarning("Tworzenie tabeli main ");
    //    query.exec("CREATE TABLE IF NOT EXISTS tableImport  (id INTEGER PRIMARY KEY, miasto TEXT UNIQUE )");

    //    if (!query.isActive()) {
    //        qWarning() << " Tworzenie Tabeli - ERROR: " << query.lastError().text();
    //    }
    //    // query.exec("PRAGMA foreign_keys = ON;"); // włączenia kluczy obcych
    //    if (!query.exec("INSERT INTO miasta (miasto) VALUES('Warszawa')")) {
    //        qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
    //    }
    //    qWarning("Tworzenie tabeli Miasta - Zakończone ");
}