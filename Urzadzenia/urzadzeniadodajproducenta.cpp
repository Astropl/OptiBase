#include "urzadzeniadodajproducenta.h"
#include "ui_urzadzeniadodajproducenta.h"
#include <fstream>
#include <iostream>
#include <QDebug>
#include <QFile>
#include <QMessageBox>
#include <DataBase/maindb.h>

using namespace std;

fstream plikProducent;

UrzadzeniaDodajProducenta::UrzadzeniaDodajProducenta(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UrzadzeniaDodajProducenta)
{
    ui->setupUi(this);
    //ui->setTitle->
    setWindowTitle("Urządzenia::Dodaj Producenta");
//    QString file1 = "C:/Defaults/Pliki/1.DB.txt";
//    QString file2 = "C:/Defaults/Pliki/2.Kontrahent.txt";
//    QString file3 = "C:/Defaults/Pliki/3.Urzadzenie.txt";
//    QString file4 = "C:/Defaults/Pliki/4.ZapisKraj.txt";
//    QString file5 = "C:/Defaults/Pliki/5.ZapisMiasta.txt";
//    QString file6 = "C:/Defaults/Pliki/6.ZapisWojewodztwa.txt";
//    QString file7 = "C:/Defaults/Pliki/7.ZapisProducenta.txt";
//    QString file8 = "C:/Defaults/Pliki/8.ZapisModel.txt";
//    QString file9 = "C:/Defaults/Pliki/9.ZapisNrSeryjny.txt";
//    QString file10 = "C:/Defaults/Pliki/10.CheckFlagsInMiasto.txt";
//    QString file11 = "C:/Defaults/Pliki/11.CheckFlagsInKraj.txt";
//    QString file12 = "C:/Defaults/Pliki/12.CheckFlagsInWojewodztwa.txt";
//    QString file13 = "C:/Defaults/Pliki/13.CheckFlagsInKrajKontrahentShow.txt";
//    QString file14 = "C:/Defaults/Pliki/14.CheckFlagsInMiastoKontrahentShow.txt";
//    QString file15 = "C:/Defaults/Pliki/15.CheckFlagsInWojewodztwoKontrahentShow.txt";


    ui->comboBoxDodajProdcuenta->setVisible(false);
    int producentId=0;
    QString QStringPobierzProducenta;
    MainDb *mainDb = new MainDb (this);
   producentId = mainDb->pobierzProducentaiD(producentId);
    QStringPobierzProducenta = mainDb->pobierzProducenta(QStringPobierzProducenta,producentId);

    for (int i = 1; i <= producentId; i++) {
        QStringPobierzProducenta = mainDb->pobierzProducenta(QStringPobierzProducenta, i);
        cout<<"powrocił producent : "<< QStringPobierzProducenta.toStdString() <<endl;
        ui->comboBoxDodajProdcuenta->addItem(QStringPobierzProducenta);
        qDebug() << QStringPobierzProducenta;
    }


}

UrzadzeniaDodajProducenta::~UrzadzeniaDodajProducenta()
{
    delete ui;
}

void UrzadzeniaDodajProducenta::on_pushButton_2_clicked()
{
    //TODO: dodoac do Bazy
    QString daneProducent="";

    //daneProducent=
    MainDb *mainDb = new MainDb (this);

    int iloscElementowWcombo;
        iloscElementowWcombo = ui->comboBoxDodajProdcuenta->count();

        for (int i = 0; i <= iloscElementowWcombo - 1; i++) {
            //        //  petla wczytująca liste z combo
                    daneProducent = ui->comboBoxDodajProdcuenta->itemText(i);
            //        cout << iloscElementowWcombo << endl;
            //        //plikProducent << ui->comboBoxDodajProdcuenta->itemText(i).toStdString() << endl;
            //        //plikProducent << daneProducent.toStdString() << endl;
                    mainDb -> addProducent (daneProducent);
                }
   // mainDb -> addProducent (daneProducent);



//    QString file7 = "C:/Defaults/Pliki/7.ZapisProducenta.txt";
//    // Zapisz i zamknij
//    cout << "Zapisuje i wychodze z okienka" << endl;
//    // musze zapisać do pliku
//    plikProducent.open(file7.toStdString(), ios::out | ios::trunc); //ios::app);
//    // musze teraz zrobic petle i zapisac itemy z comboboxa
//    int iloscElementowWcombo;
//    iloscElementowWcombo = ui->comboBoxDodajProdcuenta->count();
//    for (int i = 0; i <= iloscElementowWcombo - 1; i++) {
//        //  petla wczytująca liste z combo
//        daneProducent = ui->comboBoxDodajProdcuenta->itemText(i);
//        cout << iloscElementowWcombo << endl;
//        //plikProducent << ui->comboBoxDodajProdcuenta->itemText(i).toStdString() << endl;
//        //plikProducent << daneProducent.toStdString() << endl;
//        mainDb -> addProducent (daneProducent);
//    }
//    plikProducent.close();
    destroy();
}

void UrzadzeniaDodajProducenta::on_pushButton_clicked()
{
    //sprawdzam czy label dodawania modelu jest pusty - zrobione
    // Sprawdzić czy elent jest juz na liscie.
    if (ui->lineEditDodajProducenta->text() != "") {
        cout << "Dodaje model analizatora" << endl;
        QString dodajModel = ui->lineEditDodajProducenta->text();

        ui->comboBoxDodajProdcuenta->addItem(dodajModel);
        ui->lineEditDodajProducenta->setText("");
    } else {
        //wyswietl info ze pusty label
        QMessageBox::information(this, "Ostrzeżenie", "Nie możesz wprowdzić pustego modelu.");
    }
}
//Info do Gita