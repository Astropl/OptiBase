#include "checkfiles.h"
#include <direct.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
fstream file;
QString file1 = "C:/Defaults/Pliki/1.DB.txt";
QString file2 = "C:/Defaults/Pliki/2.Kontrahent.txt";
QString file3 = "C:/Defaults/Pliki/3.Urzadzenie.txt";
QString file4 = "C:/Defaults/Pliki/4.ZapisKraj.txt";
QString file5 = "C:/Defaults/Pliki/5.ZapisMiasta.txt";
QString file6 = "C:/Defaults/Pliki/6.ZapisWojewodztwa.txt";
QString file7 = "C:/Defaults/Pliki/7.ZapisProducenta.txt";
QString file8 = "C:/Defaults/Pliki/8.ZapisModel.txt";
QString file9 = "C:/Defaults/Pliki/9.ZapisNrSeryjny.txt";
QString file10 = "C:/Defaults/Pliki/10.CheckFlagsInMiasto.txt";
QString file11 = "C:/Defaults/Pliki/11.CheckFlagsInKraj.txt";
QString file12 = "C:/Defaults/Pliki/12.CheckFlagsInWojewodztwa.txt";
QString file13 = "C:/Defaults/Pliki/13.CheckFlagsInKrajKontrahentShow.txt";
QString file14 = "C:/Defaults/Pliki/14.CheckFlagsInMiastoKontrahentShow.txt";
QString file15 = "C:/Defaults/Pliki/15.CheckFlagsInWojewodztwoKontrahentShow.txt";
QString file16 = "C:/Defaults/Pliki/16.CheckFlagsInProducentUrzadzenia.txt";
QString file17 = "C:/Defaults/Pliki/17.CheckFlagsInModelUrzadzenia.txt";

CheckFiles::CheckFiles(QWidget *parent)
    : QMainWindow(parent)
{//cout <<"Jestem w contstr"<<endl;}
}
void CheckFiles::initMkDir()
{
    mkdir("C:/Defaults");
    mkdir("C:/Defaults/Pliki");
}

void CheckFiles::initDB()
{
    file.open(file1.toStdString()); //, ios::app
    if (file.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        file.open(file1.toStdString(), ios::app);
        //exit(0);
    }
    file.close();
}

void CheckFiles::initUrzadzenie()
{
    file.open(file3.toStdString()); //, ios::app
    if (file.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        file.open(file3.toStdString(), ios::app);
        //exit(0);
    }
    file.close();
}

void CheckFiles::initKontrahent()
{
    file.open(file2.toStdString()); //, ios::app
    if (file.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        file.open(file2.toStdString(), ios::app);
        //exit(0);
    }
    file.close();
}

void CheckFiles::initZapisKraj()
{
    file.open(file4.toStdString());
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
        file.open(file4.toStdString(), ios::app);
    } else {
        //cout << "Plik jest" << endl;
    }
    file.close();
}

void CheckFiles::initZapisMiasta()
{
    file.open(file5.toStdString());
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
        file.open(file5.toStdString(), ios::app);
    } else {
        //cout << "Plik jest" << endl;
    }
    file.close();
}

void CheckFiles::initZapisWojewodztwa()
{
    file.open(file6.toStdString());
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
        file.open(file6.toStdString(), ios::app);
    } else {
        //cout << "Plik jest" << endl;
    }
    file.close();
}
void CheckFiles::initZapisModel()
{
    file.open(file8.toStdString());
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
        file.open(file8.toStdString(), ios::app);
    } else {
        //cout << "Plik jest" << endl;
    }
    file.close();
}
void CheckFiles::initZapisNrSeryjny()
{
    file.open(file9.toStdString());
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
        file.open(file9.toStdString(), ios::app);
    } else {
        //cout << "Plik jest" << endl;
    }
    file.close();
}
void CheckFiles::initZapisProducenta()
{
    file.open(file7.toStdString());
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
        file.open(file7.toStdString(), ios::app);
    } else {
        //cout << "Plik jest" << endl;
    }
    file.close();
}
void CheckFiles::initCheckFlagsInKrajKontrahentShow()
{
    file.open(file13.toStdString());
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
        file.open(file13.toStdString(), ios::app);
    } else {
        //cout << "Plik jest" << endl;
    }
    file << "0" << endl;
    file.close();
}
void CheckFiles::initCheckFlagsInMiastoKontrahentShow()
{
    file.open(file14.toStdString());
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
        file.open(file14.toStdString(), ios::app);
    } else {
        //cout << "Plik jest" << endl;
    }
    file << "0" << endl;
    file.close();
}
void CheckFiles::initCheckFlagsInWojewodztwoKontrahentShow()
{
    file.open(file15.toStdString());
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
        file.open(file15.toStdString(), ios::app);
    } else {
        //cout << "Plik jest" << endl;
    }
    file << "0" << endl;
    file.close();
}
void CheckFiles::initCheckFlagsInMiasto()
{
    file.open(file10.toStdString());
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
        file.open(file10.toStdString(), ios::app);
    } else {
        //cout << "Plik jest" << endl;
    }
    file << "0" << endl;
    file.close();
}
void CheckFiles::initCheckFlagsInWojewodztwa()
{
    file.open(file12.toStdString());
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
        file.open(file12.toStdString(), ios::app);
    } else {
        //cout << "Plik jest" << endl;
    }
    file << "0" << endl;
    file.close();
}
void CheckFiles::initCheckFlagsInKraj()
{
    file.open(file11.toStdString());
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
        file.open(file11.toStdString(), ios::app);
    } else {
        //cout << "Plik jest" << endl;
    }
    file << "0" << endl;
    file.close();
}
void CheckFiles::initCheckFlagsInModelUrzadzenia()
{
    file.open(file17.toStdString());
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
        file.open(file17.toStdString(), ios::app);
    } else {
        //cout << "Plik jest" << endl;
    }
    file << "0" << endl;
    file.close();
}
void CheckFiles::initCheckFlagsProducent()
{

        file.open(file16.toStdString());
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
        file.open(file16.toStdString(), ios::app);
    } else {
        // cout << "Plik jest" << endl;
    }
    file << "0" << endl;
    file.close();
    //    cout << "Plik Check Flags In Produckt Jest." << endl;
}
void CheckFiles::initCheckFlagsInProducentUrzadzenia()
{
    file.open(file16.toStdString());
    if (file.good() == false) {
        cout << "Brak pliku" << endl;
        file.open(file16.toStdString(), ios::app);
    } else {
        //cout << "Plik jest" << endl;
    }
    file << "0" << endl;
    file.close();
}

void CheckFiles::init()
{
    initMkDir();
    initDB();               //
    initKontrahent();       //
    initUrzadzenie();       //
    initZapisKraj();        //
    initZapisMiasta();      //
    initZapisWojewodztwa(); //
    initZapisModel();       //
    initZapisNrSeryjny();   //
    initZapisProducenta();  //
    initCheckFlagsInKrajKontrahentShow();
    initCheckFlagsInMiastoKontrahentShow();
    initCheckFlagsInWojewodztwoKontrahentShow();
    initCheckFlagsInMiasto();
    initCheckFlagsInWojewodztwa();
    initCheckFlagsInKraj();
    initCheckFlagsProducent();

    initCheckFlagsInModelUrzadzenia();
    initCheckFlagsInProducentUrzadzenia();

    // i tak samo jak wyzej ale do modelu

//    CheckSystem *checkSystem = new CheckSystem();
//    checkSystem->show();

    //cout << "Jestem w CheckFiles" << endl;

    //Sprawdzam czy pliki istnieją jezeli nie tworzę je.

    //
}
int CheckFiles::checkFlagsWojewodztwa(int checkFlagsVarriableWojewodztwo)
{
    //cout<<" W checkfiles1:: checkFlags Wojewdoztwa"<<endl;
    file.open(file12.toStdString(),
              ios::in); //ios::app dopisuje a ios::trunc zawartos usunieta i zastąpiona nową.
    string linia;       // Wczytuje  tutuaj flage do Wczytywania miast

    int nr_lini = 1;
    while (getline(file, linia)) {
        //cout << linia << endl;
        if (linia == "0") {
            //cout << "Linia równa się 0" << endl;
            return 0;
        } else if (linia == "1") {
            //cout << "Linia równa się 1" << endl;
            return 1;
        }
        nr_lini++;
    }

    file.close();
}
int CheckFiles::checkFlagsMiasto(int checkFlagsVarriableMiasto)
{
    //cout << " W CheckFiles1: CheckFlags" << endl;

    file.open(file10.toStdString(),
              ios::in); //ios::app dopisuje a ios::trunc zawartos usunieta i zastąpiona nową.
    string linia;       // Wczytuje  tutuaj flage do Wczytywania miast

    int nr_lini = 1;
    while (getline(file, linia)) {
        //cout << linia << endl;
        if (linia == "0") {
            //cout << "Linia równa się 0" << endl;
            return 0;
        } else if (linia == "1") {
            //cout << "Linia równa się 1" << endl;
            return 1;
        }
        nr_lini++;
    }

    file.close();
}

int CheckFiles::checkFlagsKraj(int checkFlagsVarriableKraj) //int checkFlagsVarriableKraj
{
    //cout << " W CheckFiles1: CheckFlags" << endl;

    file.open(file11.toStdString(),
              ios::in); //ios::app dopisuje a ios::trunc zawartos usunieta i zastąpiona nową.
    string linia;       // Wczytuje  tutuaj flage do Wczytywania miast

    int nr_lini = 1;
    while (getline(file, linia)) {
        //cout << linia << endl;
        if (linia == "0") {
            // cout << "Linia równa się 0" << endl;
            return 0;
        } else if (linia == "1") {
            // cout << "Linia równa się 1" << endl;
            return 1;
        }
        nr_lini++;
    }

    file.close();
    //return 0;
}
int CheckFiles::checkFlagsProducent(int checkFlagsVarriableProducent)
{
    //cout << " W CheckFiles1: CheckFlagsProducent" << endl;

    file.open(file16.toStdString(),
              ios::in); //ios::app dopisuje a ios::trunc zawartos usunieta i zastąpiona nową.
    string linia;       // Wczytuje  tutuaj flage do Wczytywania miast

    int nr_lini = 1;
    while (getline(file, linia)) {
        //cout << linia << endl;
        if (linia == "0") {
            //cout << "Linia równa się 0" << endl;
            return 0;
        } else if (linia == "1") {
            //cout << "Linia równa się 1" << endl;
            return 1;
        }
        nr_lini++;
    }

    file.close();
}
int CheckFiles::checkFlagsModel(int checkFlagsVarriableModel)
{
    //cout << " W CheckFiles1: CheckFlagsProducent" << endl;

    file.open(file16.toStdString(),
              ios::in); //ios::app dopisuje a ios::trunc zawartos usunieta i zastąpiona nową.
    string linia;       // Wczytuje  tutuaj flage do Wczytywania miast

    int nr_lini = 1;
    while (getline(file, linia)) {
        //cout << linia << endl;
        if (linia == "0") {
            //cout << "Linia równa się 0" << endl;
            return 0;
        } else if (linia == "1") {
            //cout << "Linia równa się 1" << endl;
            return 1;
        }
        nr_lini++;
    }

    file.close();
}
