#include "urzadzeniadodajnrseryjny.h"
#include "ui_urzadzeniadodajnrseryjny.h"
#include <fstream>
#include <iostream>
#include <QFile>
#include <QMessageBox>

using namespace std;
fstream plikNrSeryjny;

UrzadzeniaDodajNrSeryjny::UrzadzeniaDodajNrSeryjny(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UrzadzeniaDodajNrSeryjny)
{
    ui->setupUi(this);
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

    plikNrSeryjny.open(file9.toStdString(), ios::in);

    if (plikNrSeryjny.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        //return(0);
    }
    string linia;
    int nr_lini = 1;
    while (getline(plikNrSeryjny, linia)) {
        ui->comboBoxDodajNrSeryjny->addItem(linia.c_str());
        cout << linia.c_str() << endl;
        nr_lini++;
    }
    plikNrSeryjny.close();
}

UrzadzeniaDodajNrSeryjny::~UrzadzeniaDodajNrSeryjny()
{
    delete ui;
}

void UrzadzeniaDodajNrSeryjny::on_pushButton_clicked()
{
    // Dodoaj do ComboBoxa
    //sprawdzam czy label dodawania modelu jest pusty - zrobione
    // Sprawdzić czy elent jest juz na liscie.
    if (ui->lineEditDodajNrSeryjny->text() != "") {
        cout << "Dodaje model analizatora" << endl;
        QString dodajModel = ui->lineEditDodajNrSeryjny->text();

        ui->comboBoxDodajNrSeryjny->addItem(dodajModel);
        ui->lineEditDodajNrSeryjny->setText("");
    } else {
        //wyswietl info ze pusty label
        QMessageBox::information(this, "Ostrzeżenie", "Nie możesz wprowdzić pustego modelu.");
    }
}

void UrzadzeniaDodajNrSeryjny::on_pushButton_2_clicked()
{
    QString file9 = "C:/Defaults/Pliki/9.ZapisNrSeryjny.txt";
    // Zapisz i zamknij
    cout << "Zapisuje i wychodze z okienka" << endl;
    // musze zapisać do pliku
    plikNrSeryjny.open(file9.toStdString(), ios::out | ios::app);
    // musze teraz zrobic petle i zapisac itemy z comboboxa
    int iloscElementowWcombo;
    iloscElementowWcombo = ui->comboBoxDodajNrSeryjny->count();
    for (int i = 0; i <= iloscElementowWcombo - 1; i++) {
        //  petla wczytująca liste z combo
        cout << iloscElementowWcombo << endl;
        plikNrSeryjny << ui->comboBoxDodajNrSeryjny->itemText(i).toStdString() << endl;
    }
    plikNrSeryjny.close();
    destroy();
}
//Info do Gita