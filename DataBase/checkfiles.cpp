#include "checkfiles.h"
#include <direct.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

CheckFiles::CheckFiles(QWidget *parent)
    : QMainWindow(parent)
{cout <<"Jestem w contstr"<<endl;}

void CheckFiles::initMkDir()
{
    //TODO: Zrobic
}

void CheckFiles::initDB()
{
    //TODO: Zrobic
}

void CheckFiles::initUrzadzenie()
{
    //TODO: Zrobic
}

void CheckFiles::initKontrahent()
{
    //TODO: Zrobic
}

void CheckFiles::initZapisKraj()
{
    //TODO: Zrobic
}

void CheckFiles::initZapisMiasta()
{
    //TODO: Zrobic
}

void CheckFiles::initZapisWojewodztwa()
{
    //TODO: Zrobic
}
void CheckFiles::initZapisModel()
{
    //TODO: Zrobic
}
void CheckFiles::initZapisNrSeryjny()
{
    //TODO: Zrobic
}
void CheckFiles::initZapisProducenta()
{
    //TODO: Zrobic
}
void CheckFiles::initCheckFlagsInKrajKontrahentShow()
{
    //TODO: Zrobic
}
void CheckFiles::initCheckFlagsInMiastoKontrahentShow()
{
    //TODO: Zrobic
}
void CheckFiles::initCheckFlagsInWojewodztwoKontrahentShow()
{
    //TODO: Zrobic
}
void CheckFiles::initCheckFlagsInMiasto()
{
    //TODO: Zrobic
}
void CheckFiles::initCheckFlagsInWojewodztwa()
{
    //TODO: Zrobic
}
void CheckFiles::initCheckFlagsInKraj()
{
    //TODO: Zrobic
}
void CheckFiles::initCheckFlagsInModelUrzadzenia()
{
    //TODO: Zrobic
}
void CheckFiles::initCheckFlagsProducent()
{
    //TODO: Zrobic
}
void CheckFiles::initCheckFlagsInProducentUrzadzenia()
{
    //TODO: Zrobic
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