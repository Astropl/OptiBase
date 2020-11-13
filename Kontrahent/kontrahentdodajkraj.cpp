#include "kontrahentdodajkraj.h"
#include "ui_kontrahentdodajkraj.h"
#include <fstream>
#include <iostream>
#include <QMessageBox>

using namespace std;

fstream plikOdczytDodajKraj;

KontrahentDodajKraj::KontrahentDodajKraj(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KontrahentDodajKraj)
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
    plikOdczytDodajKraj.open(file4.toStdString(), ios::in);
    if (plikOdczytDodajKraj.good() == false) {
        cout << "Plik nie istnieje!!!";
    }
    string linia;

    int nr_lini = 1;
    while (getline(plikOdczytDodajKraj, linia)) {
        ui->comboBoxDodajKraj->addItem(linia.c_str());
        cout << linia.c_str() << endl;
        nr_lini++;
    }

    plikOdczytDodajKraj.close();
}

KontrahentDodajKraj::~KontrahentDodajKraj()
{
    delete ui;
}

void KontrahentDodajKraj::on_pushButton_2_clicked()
{
    // Dodoaj
    QMessageBox msgBox;
    bool porownanieKraj = false;
    //sprawdzam czy label dodawania modelu jest pusty - zrobione
    // Sprawdzić czy elent jest juz na liscie.

    int iloscElementowwCombo = ui->comboBoxDodajKraj->count();
    // Zrobic cos aby najpierw sprawdzało czy jest puste a potm przeszukiwało itemy z comboxa

    if (ui->lineEditDodajKraj->text() != "") {
        cout << "Dodaje Kraj" << endl;
        for (int i = 0; i <= iloscElementowwCombo; i++) {
            QVariant zmienna1 = ui->lineEditDodajKraj->text();
            //QString zmienna2=QVariant(ui->comboBoxDodajMiasto->itemData(i));
            cout << "Wyswietlam po koleji itemy z comboboxa dodaj Kraj" << endl;
            cout << ui->comboBoxDodajKraj->itemText(i).toStdString() << endl;
            ;
            if (zmienna1 != (ui->comboBoxDodajKraj->itemText(i))) {
                cout << "Kraj numer :" << i << " "
                     << ui->comboBoxDodajKraj->itemText(i).toStdString() << endl;
                porownanieKraj = false;

                //Wrzucic do tabeli. Przeleciec tabele. jezeli bedzie wyraz z listy zakonczyc. Jezeli nie dodoać do combo boa.

            } else {
                msgBox.setText("Ten Kraj jezst juz na liscie");
                QMessageBox::information(this,
                                         "Ostrzeżenie",
                                         "Ten Kraj już znajduje się na liście.");
                porownanieKraj = true;

                break;
            }
        }

        if (porownanieKraj == false) // domyslnie true?
        {
            cout << "dodoaje Kraj" << endl;
            QString dodajKraj = ui->lineEditDodajKraj->text();
            ui->comboBoxDodajKraj->addItem(dodajKraj);
            ui->lineEditDodajKraj->setText("");
        } else {
            cout << "Przeszukałem wszytskie Kraje. Jest na liscie." << endl;
        }
    } else {
        //wyswietl info ze pusty label
        QMessageBox::information(this, "Ostrzeżenie", "Nie możesz wprowdzić pustego Kraju.");
    }
    ui->comboBoxDodajKraj->setDuplicatesEnabled(false); // ustawiam aby nie było duplikatów
    ui->lineEditDodajKraj->setText("");
}

void KontrahentDodajKraj::on_pushButton_clicked()
{
    // Zapisz
    fstream checkFlagsinKraj;
    QString file4 = "C:/Defaults/Pliki/4.ZapisKraj.txt";
    QString file11 = "C:/Defaults/Pliki/11.CheckFlagsInKraj.txt";
    cout << "Zapisuje " << endl;

    plikOdczytDodajKraj
        .open(file4.toStdString(),
              ios::out
                  | ios::trunc); //ios::app dopisuje a ios::trunc zawartos usunieta i zastąpiona nową.

    int iloscElementowWcombo;

    iloscElementowWcombo = ui->comboBoxDodajKraj->count();
    for (int i = 0; i <= iloscElementowWcombo - 1; i++) {
        cout << iloscElementowWcombo << endl;
        plikOdczytDodajKraj << ui->comboBoxDodajKraj->itemText(i).toStdString() << endl;
    }
    plikOdczytDodajKraj.close();
    //
    checkFlagsinKraj
        .open(file11.toStdString(),
              ios::in
                  | ios::trunc); //ios::app dopisuje a ios::trunc zawartos usunieta i zastąpiona nową.
    checkFlagsinKraj << "1";
    checkFlagsinKraj.close();
}

void KontrahentDodajKraj::on_pushButton_3_clicked()
{
    // Usuń
    ui->comboBoxDodajKraj->removeItem(ui->comboBoxDodajKraj->currentIndex());
}

void KontrahentDodajKraj::on_pushButton_4_clicked()
{
    // Zamknij
    destroy();
}
