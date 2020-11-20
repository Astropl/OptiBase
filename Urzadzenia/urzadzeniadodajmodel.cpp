#include "urzadzeniadodajmodel.h"
#include "ui_urzadzeniadodajmodel.h"
#include "DataBase/maindb.h"
#include <fstream>
#include <iostream>
#include <QFile>
#include <QMessageBox>
#include <QDebug>

using namespace std;

fstream plikOdczyt;

UrzadzeniaDodajModel::UrzadzeniaDodajModel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UrzadzeniaDodajModel)
{
    ui->setupUi(this);
    setWindowTitle("Urządzenia::Dodaj Model");
    cout << "Wczytac itemy z pliku" << endl;

    //---------------------------------------------------------
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



    //TODO:: Wczytac model z bazy danych MainB
    int modelId=0;
    QString QStringPobierzModel;
    MainDb *mainDb = new MainDb (this);
    modelId = mainDb->pobierzModeliD(modelId);
    //QStringPobierzModel = mainDb->pobierzModel(QStringPobierzModel,modelId);

    for (int i = 1; i <= modelId; i++) {
        QStringPobierzModel = mainDb->pobierzModel(QStringPobierzModel, i);
        ui->comboBoxDodajModel->addItem(QStringPobierzModel);
        qDebug() << QStringPobierzModel;
    }


//    plikOdczyt.open(file8.toStdString(), ios::in);
//    if (plikOdczyt.good() == false) {
//        cout << "Plik nie istnieje !!!!!";
//        //exit(0);
//    }
//    string linia;
//    int nr_lini = 1;
//    while (getline(plikOdczyt, linia)) {
//        ui->comboBoxDodajModel->addItem(linia.c_str());
//        cout << linia.c_str() << endl;
//        nr_lini++;
//    }
//    plikOdczyt.close();

    //--------------------------------------------------------
}

UrzadzeniaDodajModel::~UrzadzeniaDodajModel()
{
    delete ui;
}

void UrzadzeniaDodajModel::on_pushButton_clicked()
{
    //// DOdaj model/

    //sprawdzam czy label dodawania modelu jest pusty - zrobione
    // Sprawdzić czy elent jest juz na liscie.
    if (ui->lineEditDodajModel->text() != "") {
        cout << "Dodaje model analizatora" << endl;
        QString dodajModel = ui->lineEditDodajModel->text();

        ui->comboBoxDodajModel->addItem(dodajModel);
        ui->lineEditDodajModel->setText("");
    } else {
        //wyswietl info ze pusty label
        QMessageBox::information(this, "Ostrzeżenie", "Nie możesz wprowdzić pustego modelu.");
    }
}

void UrzadzeniaDodajModel::on_pushButton_2_clicked()
{ ////Zamknij i zapisz

    //TODO: dodoac do Bazy
    QString daneModel="";

    //daneModel=
    MainDb *mainDb = new MainDb (this);

    int iloscElementowWcombo;
    iloscElementowWcombo = ui->comboBoxDodajModel->count();

    for (int i = 0; i <= iloscElementowWcombo - 1; i++) {
        //        //  petla wczytująca liste z combo
        daneModel = ui->comboBoxDodajModel->itemText(i);
        //        cout << iloscElementowWcombo << endl;
        //        //plikProducent << ui->comboBoxDodajProdcuenta->itemText(i).toStdString() << endl;
        //        //plikProducent << daneProducent.toStdString() << endl;
        mainDb -> addModel (daneModel);
    }

//    QString file8 = "C:/Defaults/Pliki/8.ZapisModel.txt";
//    cout << "Zapisuje i wychodze z okienka" << endl;
//    // musze zapisać do pliku
//    plikOdczyt.open(file8.toStdString(), ios::out | ios::trunc);

//    // musze teraz zrobic petle i zapisac itemy z comboboxa
//    int iloscElementowWcombo;

//    iloscElementowWcombo = ui->comboBoxDodajModel->count();
//    for (int i = 0; i <= iloscElementowWcombo - 1; i++) {
//        //  petla wczytująca liste z combo
//        cout << iloscElementowWcombo << endl;
//        plikOdczyt << ui->comboBoxDodajModel->itemText(i).toStdString() << endl;
//    }
//    plikOdczyt.close();
//    //ui->Jak zrobic aby comboxy na urzadzeniach się odswiezały

    destroy();
}
//Info do Gita