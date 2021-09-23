#include "ustawienia.h"
#include "Timery/timedate.h"
#include "time.h"
#include "ui_ustawienia.h"
#include "Ustawienia/statystyki.h"
#include "Timery/addspecialdatesimportant.h"
//#include "Timery/addspecialdates.h"
#include <ctime>
#include <direct.h> //biblio do stworzenia katalogu poprzez mkdir
#include <fstream>
#include <iostream>
#include <iterator> // do obliczenia rozmiaru tablicy FN
#include <windows.h>
#include <QDebug>
#include <QFile>
#include <QMessageBox>

using namespace std;
QString aktHour;
QFile plik; /*=("C:/Users/pawel/Documents/Cplusplus/OptiBase/OptiBase/DataBase/2020.11.17.db");*/
fstream fileUstawienia, fileUstawienia1, fileUstawieniaDB1, fileUstawieniaDB2;
Ustawienia::Ustawienia(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Ustawienia)
{
    ui->setupUi(this);

    //cout << "Jestem w ustawieniach" << endl;
    initMenuSettings ();

}

Ustawienia::~Ustawienia()
{
    delete ui;
}

QString Ustawienia::pobierzDate(QString aktHour)
{
    time_t czas;
    tm timeinfo;
    QString qStrMin, qStrGodz, qStrSek, qStrDzien, qStrMiesiac, stringDzienTygodnia;
    //QString aktHour;
    TimeDate *timeDate = new TimeDate();

    time(&czas);
    timeinfo = *localtime(&czas);
    int godzina = timeinfo.tm_hour;
    int minuta = timeinfo.tm_min;
    int sekunda = timeinfo.tm_sec;
    int dzien = timeinfo.tm_mday;
    int miesiac = timeinfo.tm_mon;
    int rok = timeinfo.tm_year;
    //int dzienTygodnia = timeinfo.tm_wday;
    miesiac = miesiac + 1;
    rok = rok + 1900;
    //dzienTygodnia = dzienTygodnia + 1;

    qStrMin = timeDate->changeStringsMin(minuta);
    qStrSek = timeDate->changeStringsSek(sekunda);
    qStrDzien = timeDate->changeStringsDzien(dzien);
    qStrGodz = timeDate->changeStringsGodz(godzina);
    qStrMiesiac = timeDate->changeStringsMiesiac(miesiac);
    //stringDzienTygodnia = timeDate->changeStringsDzienTygodnia(dzienTygodnia);

    aktHour = QString::number(rok) + "." + qStrMiesiac + "." + qStrDzien + "." + qStrGodz + "."
              + qStrMin + "." + qStrSek;

    return aktHour;
}


void Ustawienia::initMenuSettings ()
{
    setWindowTitle("OptiBase v 1.0:Ustawienia");
}
void Ustawienia::on_pushButton_clicked()
{
//    string stringFile = "Backup/";
//    //qWarning() << "stringFile:" << stringFile.c_str();
//    string patchBasic = "C:/Defaults/Pliki/";
//    //qWarning() << "patchBasic:" << patchBasic.c_str();
//    string patchBasicDB = "C:/Users/pawel/Documents/Cplusplus/OptiBase/OptiBase/DataBase/";
//    //qWarning() << "patchBasicDB:" << patchBasicDB.c_str();
//    string nameOfDB = "2020.12.21.db";
//    QString QnameOfDB = "2020.12.21.db";
//    QString QnameOfDB1 = "2020.12.21a.db";


    QString aktHours = pobierzDate(aktHour);

    ui->lblData->setText(aktHours);
    // Kopia danych plików

    string aktHours1 = aktHours.toStdString();

//    string patchBasicDBBackup = patchBasicDB + stringFile;

//    string aktHoursDB = patchBasicDB + stringFile + aktHours1 + "/";



//    //if(source1.copy())


    cout <<"Nowy katalog do testwó"<<endl;


    string gc1 = "C:/";
    string gc2 = "backup21/";

    string gc3 = "sprawdz/";
    string gc4 = aktHours1 + "/";
    string gc5 = "2021.09.23.db";

    string pelnaSciezka = "C:/Users/pawel/Documents/Cplusplus/OptiBase/OptiBase/DataBase/";
    string gc22 = "backup/";


    string pelnaGc22 = pelnaSciezka+gc22;
    string pelnaGc22Gc4 = pelnaGc22 + gc4;

    string pelnaGc5 = pelnaSciezka + gc5;
    string pelnaGc22Gc4Gc5 = pelnaGc22Gc4 + gc5;

    _mkdir(pelnaGc22.c_str());

     _mkdir(pelnaGc22Gc4.c_str());

     QFile::copy(pelnaGc5.c_str(),pelnaGc22Gc4Gc5.c_str() );


    string gc1Gc2 = gc1+gc2;
    _mkdir(gc1Gc2.c_str());
    string gc1Gc2Gc3 = gc1Gc2 + gc3;
     _mkdir(gc1Gc2Gc3.c_str());
    string gc1Gc2Gc3Gc4 = gc1Gc2Gc3+gc4;
     _mkdir(gc1Gc2Gc3Gc4.c_str());
     string gc1Gc5 = gc1 + gc5;
     string gc1Gc2Gc3Gc4Gc5= gc1Gc2Gc3Gc4 + gc5;
     QFile::copy(gc1Gc5.c_str(),gc1Gc2Gc3Gc4Gc5.c_str() );


    //***************************************************************

}

void Ustawienia::on_pushButton_2_clicked()
{
    destroy();
}

void Ustawienia::on_pushButton_3_clicked()
{
    // Wybierz sciezkę do Bazy Danych

}

void Ustawienia::on_pushButton_4_clicked()
{
    //Statystyki
    Statystyki *stat = new Statystyki(this);
    stat->show();
}

void Ustawienia::on_pushButton_5_clicked()
{
    qWarning()<<" Wazne daty add";
    AddSpecialDatesImportant *asd = new AddSpecialDatesImportant(this);
    asd->show();


}
