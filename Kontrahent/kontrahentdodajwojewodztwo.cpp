#include "kontrahentdodajwojewodztwo.h"
#include "ui_kontrahentdodajwojewodztwo.h"
#include <fstream>
#include <iostream>
#include <QApplication>
#include <QFile>
#include <QMessageBox>
#include <QtWidgets>

using namespace std;

fstream plikOdczytDodajWojewodztwa;

KontrahentDodajWojewodztwo::KontrahentDodajWojewodztwo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KontrahentDodajWojewodztwo)
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
    cout << "Wczytac itemy z pliku" << endl;

    //---------------------------------------------------------

    plikOdczytDodajWojewodztwa.open(file6.toStdString(), ios::in);
    if (plikOdczytDodajWojewodztwa.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        //exit(0);
    }
    string linia;
    int nr_lini = 1;
    while (getline(plikOdczytDodajWojewodztwa, linia)) {
        ui->comboBoxDodajWojewodztwa->addItem(linia.c_str());
        cout << linia.c_str() << endl;
        nr_lini++;
    }
    plikOdczytDodajWojewodztwa.close();
    //ui->comboBoxDodajMiasto->sor
}

KontrahentDodajWojewodztwo::~KontrahentDodajWojewodztwo()
{
    delete ui;
}

void KontrahentDodajWojewodztwo::on_pushButton_clicked()
{
    fstream checkflagsInWojewodztwo;
    QString file12 = "C:/Defaults/Pliki/12.CheckFlagsInWojewodztwa.txt";
    QString file6 = "C:/Defaults/Pliki/6.ZapisWojewodztwa.txt";
    cout << "Button Zapisz. Zapisuje i wychodze z okienka" << endl;
    // musze zapisać do pliku
    plikOdczytDodajWojewodztwa.open(file6.toStdString(), ios::out | ios::trunc);

    // musze teraz zrobic petle i zapisac itemy z comboboxa
    int iloscElementowWcombo;

    iloscElementowWcombo = ui->comboBoxDodajWojewodztwa->count();
    for (int i = 0; i <= iloscElementowWcombo - 1; i++) {
        //  petla wczytująca liste z combo
        cout << iloscElementowWcombo << endl;
        plikOdczytDodajWojewodztwa << ui->comboBoxDodajWojewodztwa->itemText(i).toStdString()
                                   << endl;
    }
    plikOdczytDodajWojewodztwa.close();
    checkflagsInWojewodztwo
        .open(file12.toStdString(),
              ios::in
                  | ios::trunc); //ios::app dopisuje a ios::trunc zawartos usunieta i zastąpiona nową.
    checkflagsInWojewodztwo << "1";
    checkflagsInWojewodztwo.close();
    //ui->Jak zrobic aby comboxy na urzadzeniach się odswiezały
    //ui->comboBoxDodajMiasto->rep
}

void KontrahentDodajWojewodztwo::on_pushButton_2_clicked()
{
    QMessageBox msgBox;
    bool porownanieWojewodztw = false;

    int iloscElementowWcombo = ui->comboBoxDodajWojewodztwa->count();

    if (ui->lineEditDodajWojewodztwa->text() != "") {
        cout << "Dodoaje Wojewdoztwo" << endl;
        for (int i = 0; i <= iloscElementowWcombo; i++) {
            QVariant zmienna1 = (ui->lineEditDodajWojewodztwa->text());
            cout << "Wyswietlam po koleji itemy z comboboxa dodaj wojewodztwo" << endl;
            cout << ui->comboBoxDodajWojewodztwa->itemText(i).toStdString() << endl;
            ;
            if (zmienna1 != (ui->comboBoxDodajWojewodztwa->itemText(i))) {
                cout << "Miasto numer :" << i << " "
                     << ui->comboBoxDodajWojewodztwa->itemText(i).toStdString() << endl;
                porownanieWojewodztw = false;

            } else {
                msgBox.setText("Te województwo jest juz na liscie");
                QMessageBox::information(this,
                                         "Ostrzeżenie",
                                         "Te województwo już znajduje się na liście.");
                porownanieWojewodztw = true;

                break;
            }
        }
        if (porownanieWojewodztw == false) {
            cout << "dodaje wojewodztwo" << endl;
            QString dodajWojewodztwo = ui->lineEditDodajWojewodztwa->text();
            ui->comboBoxDodajWojewodztwa->addItem(dodajWojewodztwo);
            ui->lineEditDodajWojewodztwa->setText("");

        } else {
            //wyswietl info ze pusty label
            QMessageBox::information(this,
                                     "Ostrzeżenie",
                                     "Nie możesz wprowdzić pustego województwa.");
        }
        ui->comboBoxDodajWojewodztwa->setDuplicatesEnabled(
            false); // ustawiam aby nie było duplikatów
        ui->lineEditDodajWojewodztwa->setText("");
    }
}
//Info do Gita

void KontrahentDodajWojewodztwo::on_pushButton_3_clicked()
{
    // Button Usuń
    //Usuń zaznaczony item

    ui->comboBoxDodajWojewodztwa->removeItem(ui->comboBoxDodajWojewodztwa->currentIndex());
}

void KontrahentDodajWojewodztwo::on_pushButton_4_clicked()
{
    //Button Zamkinj
    destroy();
}
