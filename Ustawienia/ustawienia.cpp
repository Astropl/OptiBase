#include "ustawienia.h"
#include "Timery/timedate.h"
#include "time.h"
#include "ui_ustawienia.h"
#include <ctime>
#include <direct.h> //biblio do stworzenia katalogu poprzez mkdir
#include <direct.h>
#include <fstream>
#include <iostream>
#include <iterator> // do obliczenia rozmiaru tablicy FN
#include <windows.h>
#include <QMessageBox>

using namespace std;
QString aktHour;
fstream fileUstawienia, fileUstawienia1;
Ustawienia::Ustawienia(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Ustawienia)
{
    ui->setupUi(this);

    cout << "Jestem w ustawieniach" << endl;
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

void Ustawienia::on_pushButton_clicked()
{
    string stringFile = "Backup/";
    string patchBasic = "C:/Defaults/Pliki/";

    string tableOfstrings[17] = {"1.DB.txt",
                                 "2.Kontrahent.txt",
                                 "3.Urzadzenie.txt",
                                 "4.ZapisKraj.txt",
                                 "5.ZapisMiasta.txt",
                                 "6.ZapisWojewodztwa.txt",
                                 "7.ZapisProducenta.txt",
                                 "8.ZapisModel.txt",
                                 "9.ZapisNrSeryjny.txt",
                                 "10.CheckFlagsInMiasto.txt",
                                 "11.CheckFlagsInKraj.txt",
                                 "12.CheckFlagsInWojewodztwa.txt",
                                 "13.CheckFlagsInKrajKontrahentShow.txt",
                                 "14.CheckFlagsInMiastoKontrahentShow.txt",
                                 "15.CheckFlagsInWojewodztwoKontrahentShow.txt",
                                 "16.CheckFlagsInProducentUrzadzenia.txt",
                                 "17.CheckFlagsInModelUrzadzenia.txt"};

    QString aktHours = pobierzDate(aktHour);
    ui->lblData->setText(aktHours);
    // Kopia danych plików
    string aktHours1 = aktHours.toStdString();
    string aktHours2 = patchBasic + stringFile + aktHours1 + "/";

    _mkdir(aktHours2.c_str());

    int sizeOfTable = 17;                 //Podać ręcznie
    for (int i = 0; i < sizeOfTable; i++) // int i = 0; i < sizeOfTable-1; i++
    {
        fileUstawienia.open(patchBasic + tableOfstrings[i], ios::in);
        fileUstawienia1.open(aktHours2 + tableOfstrings[i], ios::out);
        string linia;

        int nr_lini = 1;
        while (getline(fileUstawienia, linia)) {
            ui->comboBox->addItem(linia.c_str());
            fileUstawienia1 << linia.c_str() << endl;
            cout << linia.c_str() << endl;
            nr_lini++;
        }
        ui->comboBox->clear();

        fileUstawienia.close();
        fileUstawienia1.close();
    }
    //    QMessageBox msgBox;
    //    msgBox.setText("Kopia Bazy Danych zrobiona");
    cout << "Zapisano: " + aktHours2 << endl;
    QMessageBox::information(this, "Ostrzeżenie", "Kopia Bazy Danych zrobiona.");
}

void Ustawienia::on_pushButton_2_clicked()
{
    destroy();
}
