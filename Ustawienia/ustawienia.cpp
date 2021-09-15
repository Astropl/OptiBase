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
    string stringFile = "Backup/";
    //qWarning() << "stringFile:" << stringFile.c_str();
    string patchBasic = "C:/Defaults/Pliki/";
    //qWarning() << "patchBasic:" << patchBasic.c_str();
    string patchBasicDB = "C:/Users/pawel/Documents/Cplusplus/OptiBase/OptiBase/DataBase/";
    //qWarning() << "patchBasicDB:" << patchBasicDB.c_str();
    string nameOfDB = "2020.12.21.db";
    QString QnameOfDB = "2020.12.21.db";
    QString QnameOfDB1 = "2020.12.21a.db";
    //qWarning() << "nameOfDB:" << nameOfDB.c_str();

    QString aktHours = pobierzDate(aktHour);
     //new QString aktHours = aktHours;
    //qWarning() << "aktHours:" << aktHours;
    ui->lblData->setText(aktHours);
    // Kopia danych plików

    string aktHours1 = aktHours.toStdString();
    //qWarning() << "aktHours1:" << aktHours1.c_str();
    string aktHours2 = patchBasic + stringFile + aktHours1 + "/";
    //qWarning() << "aktHours2:" << aktHours2.c_str();
    string patchBasicDBBackup = patchBasicDB + stringFile;
    //qWarning() << "patchBasicDBBackup:" << patchBasicDBBackup.c_str();
    string aktHoursDB = patchBasicDB + stringFile + aktHours1 + "/";
   //qWarning() << "aktHoursDB:" << aktHoursDB.c_str();

    _mkdir(aktHours2.c_str());
   // qWarning() << "1. Stworyłem katalog: " << aktHours2.c_str();
    _mkdir(patchBasicDBBackup.c_str());
   // qWarning() << "2. Stworyłem katalog: " << patchBasicDBBackup.c_str();

    _mkdir(aktHoursDB.c_str());
    //qWarning() << "3. Stworyłem katalog: " << aktHoursDB.c_str();
 _mkdir(aktHours2.c_str());
    string patchExt = patchBasicDB + nameOfDB;
    //qWarning() << "patchExt: " << patchExt.c_str();
    string patchDest = aktHoursDB + nameOfDB;
    string patchExt1 = patchBasicDB + nameOfDB + "1";
   // qWarning() << "patchDest: " << patchDest.c_str();
    QString source ("patchExt");
    QFile source1 ("patchExt");
    //QFile sourceDest ("patchDest");
    QString sourceDest ("patchDest");
   // QString Qsource = QString::toStdString(source);
    QString dest ("patchExt1");

    //if(source1.copy())

    if (plik.exists("patchExt1"))

    {
        //qWarning("Plik wystepuje: usuwam");
        //plik.remove("patchExt1");
        //QFile::remove("patchExt1");
    } else {
        //        plik.copy("patchExt" , "patchExt1");
        if (plik.rename("C:/Users/pawel/Documents/Cplusplus/OptiBase/OptiBase/DataBase/" + QnameOfDB, "C:/Users/pawel/Documents/Cplusplus/OptiBase/OptiBase/DataBase/" + QnameOfDB1))
        {//qDebug() << "success";}
        }
            else
        {//qDebug() << "failed";
            if (!source1.copy("patchExt1"))
            {
                //qWarning()<<"BłąD: "<<source1.error();
            }

        }
        //QFile::copy("patchExt" , "patchExt1");
        //qWarning() << "Tworze backup z :" << patchExt.c_str() << "na " << patchExt1.c_str();
    }

    bool udalosiezgrac =QFile::copy(source,sourceDest);
    //qWarning()<< "************************"<< "Udalo się czy nie ? "<< udalosiezgrac;
    // TO DZIAŁA::
    QFile::copy("C:/Users/pawel/Documents/Cplusplus/OptiBase/OptiBase/DataBase/2020.12.21.db","C:/Users/pawel/Documents/Cplusplus/OptiBase/OptiBase/DataBase/Backup/2020.12.21.db");

    cout << "Zapisano: " + aktHours2 << endl;
    cout << "Zapisano: " + aktHoursDB << endl;
    QMessageBox::information(this, "Ostrzeżenie", "Kopia Bazy Danych zrobiona.");
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
