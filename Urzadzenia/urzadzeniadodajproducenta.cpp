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
    // Ikonka check OK /NO
    QString dirPath = "C:/Users/pawel/Documents/Cplusplus/OptiBase/OptiBase/Resources";
    QPixmap pix1(dirPath+ "/YesRed.png");

    ui->lblCheckOkNo->setPixmap(pix1.scaled(ui->lblCheckOkNo->size(),Qt::KeepAspectRatio));// Skaluje pnp do wymierów labela
    // end Ikonka Check Ok/NO
    //**********************************************

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
        // Ikonka check OK /NO
        QString dirPath = "C:/Users/pawel/Documents/Cplusplus/OptiBase/OptiBase/Resources";
        QPixmap pix1(dirPath+ "/CheckOk.png");

        ui->lblCheckOkNo->setPixmap(pix1.scaled(ui->lblCheckOkNo->size(),Qt::KeepAspectRatio));// Skaluje pnp do wymierów labela
        // end Ikonka Check Ok/NO
        //**********************************************
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

    QString dirPath = "C:/Users/pawel/Documents/Cplusplus/OptiBase/OptiBase/Resources";
    QPixmap pix1(dirPath+ "/YesYellow.png");

    ui->lblCheckOkNo->setPixmap(pix1.scaled(ui->lblCheckOkNo->size(),Qt::KeepAspectRatio));//Skaluje pnp do wymierów labela
}
//Info do Gita