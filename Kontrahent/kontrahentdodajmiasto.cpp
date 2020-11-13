#include "kontrahentdodajmiasto.h"
#include "ui_kontrahentdodajmiasto.h"
#include <fstream>
#include <iostream>
#include <QApplication>
#include <QFile>
#include <QMessageBox>
#include <QtWidgets>

using namespace std;

fstream plikOdczytDodajMiasto;

KontrahentDodajMiasto::KontrahentDodajMiasto(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KontrahentDodajMiasto)
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
    //---------------------------------------------------------

    plikOdczytDodajMiasto.open(file5.toStdString(), ios::in);
    if (plikOdczytDodajMiasto.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        //exit(0);
    }
    string linia;

    int nr_lini = 1;
    while (getline(plikOdczytDodajMiasto, linia)) {
        ui->comboBoxDodajMiasto->addItem(linia.c_str());
        //cout << linia.c_str() << endl;
        nr_lini++;
    }

    plikOdczytDodajMiasto.close();
}

KontrahentDodajMiasto::~KontrahentDodajMiasto()
{
    delete ui;
}

void KontrahentDodajMiasto::on_pushButton_clicked() //zapisz
{
    fstream checkFlagsinMiasta;
    QString file10 = "C:/Defaults/Pliki/10.CheckFlagsInMiasto.txt";
    QString file5 = "C:/Defaults/Pliki/5.ZapisMiasta.txt";
    cout << "Zapisuje " << endl;
    // musze zapisać do pliku
    plikOdczytDodajMiasto
        .open(file5.toStdString(),
              ios::out
                  | ios::trunc); //ios::app dopisuje a ios::trunc zawartos usunieta i zastąpiona nową.

    int iloscElementowWcombo;

    iloscElementowWcombo = ui->comboBoxDodajMiasto->count();
    for (int i = 0; i <= iloscElementowWcombo - 1; i++) {
        cout << iloscElementowWcombo << endl;
        plikOdczytDodajMiasto << ui->comboBoxDodajMiasto->itemText(i).toStdString() << endl;
    }
    plikOdczytDodajMiasto.close();
    //
    checkFlagsinMiasta
        .open(file10.toStdString(),
              ios::in
                  | ios::trunc); //ios::app dopisuje a ios::trunc zawartos usunieta i zastąpiona nową.
    checkFlagsinMiasta << "1";
    checkFlagsinMiasta.close();
}

void KontrahentDodajMiasto::on_pushButton_2_clicked() //dodoaj do comboboxa
{
    QMessageBox msgBox;
    bool porownanieMiast = false;
    //sprawdzam czy label dodawania modelu jest pusty - zrobione
    // Sprawdzić czy elent jest juz na liscie.

    int iloscElementowwCombo = ui->comboBoxDodajMiasto->count();

    if (ui->lineEditDodajMiasto->text() != "") {
        cout << "Dodaje miasto" << endl;
        for (int i = 0; i <= iloscElementowwCombo; i++) {
            QVariant zmienna1 = ui->lineEditDodajMiasto->text();
            //QString zmienna2=QVariant(ui->comboBoxDodajMiasto->itemData(i));
            cout << "Wyswietlam po koleji itemy z comboboxa dodaj miasta" << endl;
            cout << ui->comboBoxDodajMiasto->itemText(i).toStdString() << endl;
            ;
            if (zmienna1 != (ui->comboBoxDodajMiasto->itemText(i))) {
                cout << "Miasto numer :" << i << " "
                     << ui->comboBoxDodajMiasto->itemText(i).toStdString() << endl;
                porownanieMiast = false;

                //Wrzucic do tabeli. Przeleciec tabele. jezeli bedzie wyraz z listy zakonczyc. Jezeli nie dodoać do combo boa.

            } else {
                msgBox.setText("Te miasto jezst juz na liscie");
                QMessageBox::information(this,
                                         "Ostrzeżenie",
                                         "Te miasto już znajduje się na liście.");
                porownanieMiast = true;

                break;
            }
        }

        if (porownanieMiast == false) // domyslnie true?
        {
            cout << "dodoaje miasto" << endl;
            QString dodajMiasto = ui->lineEditDodajMiasto->text();
            ui->comboBoxDodajMiasto->addItem(dodajMiasto);
            ui->lineEditDodajMiasto->setText("");
        } else {
            cout << "Przeszukałem wszytskie miasta. Jest na liscie." << endl;
        }
    } else {
        //wyswietl info ze pusty label
        QMessageBox::information(this, "Ostrzeżenie", "Nie możesz wprowdzić pustego miasta.");
    }
    ui->comboBoxDodajMiasto->setDuplicatesEnabled(false); // ustawiam aby nie było duplikatów
    ui->lineEditDodajMiasto->setText("");
}

void KontrahentDodajMiasto::on_comboBoxDodajMiasto_activated(const QString)
{
    //string[] items = ui->comboBoxDodajMiasto->getItems();
}

void KontrahentDodajMiasto::on_pushButton_3_clicked() //usuń item
{
    //Usuń zaznaczony item

    ui->comboBoxDodajMiasto->removeItem(ui->comboBoxDodajMiasto->currentIndex());
}

void KontrahentDodajMiasto::on_pushButton_4_clicked() // zamknij bez zapisywania
{                                                     //zamknij be zpisywania
    destroy();
}
//Info do Gita