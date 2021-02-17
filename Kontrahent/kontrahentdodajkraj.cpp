#include "kontrahentdodajkraj.h"
#include "ui_kontrahentdodajkraj.h"
#include "DataBase/maindb.h"
#include <fstream>
#include <iostream>
#include <QMessageBox>
#include <QDebug>

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

    loadKraj();

    ui->pushButton->setEnabled(false); // Przycisk Zapisz



}

void KontrahentDodajKraj::loadKraj()

{
    //Wczytac liste krajów z MainDB i dodoac ją do comboBoxDodajKra
    MainDb *mainDb = new MainDb (this);
    QString QStringpobierzKraj;
    int pobierzKrajId=0;
        pobierzKrajId = mainDb->pobierzKrajId(pobierzKrajId);
        for (int i = 1; i <= pobierzKrajId; i++) {
        QStringpobierzKraj = mainDb->pobierzKraj(QStringpobierzKraj, i);
        ui->comboBoxDodajKraj ->addItem(QStringpobierzKraj);
        //qDebug() << QStringpobierzKraj;
    }

}

KontrahentDodajKraj::~KontrahentDodajKraj()
{
    delete ui;
}

void KontrahentDodajKraj::on_pushButton_2_clicked()
{
    // Dodaj Kraj


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
    ui->pushButton->setEnabled(true); // Przycisk Zapisz
    ui->pushButton_2->setEnabled(false); // Przycisk Dodaj
}

void KontrahentDodajKraj::on_pushButton_clicked()
{
    // Zapisz
     MainDb *mainDb = new MainDb(this);
     QString daneKraj="";
    fstream checkFlagsinKraj;
    //QString file4 = "C:/Defaults/Pliki/4.ZapisKraj.txt";
    QString file11 = "C:/Defaults/Pliki/11.CheckFlagsInKraj.txt";
    cout << "Zapisuje " << endl;

    /*plikOdczytDodajKraj
        .open(file4.toStdString(),
              ios::out
                  | ios::trunc); //ios::app dopisuje a ios::trunc zawartos usunieta i zastąpiona nową*/

    int iloscElementowWcombo;

    iloscElementowWcombo = ui->comboBoxDodajKraj->count();
    for (int i = 0; i <= iloscElementowWcombo - 1; i++) {
        cout << iloscElementowWcombo << endl;
        //plikOdczytDodajKraj << ui->comboBoxDodajKraj->itemText(i).toStdString() << endl;
        daneKraj = ui->comboBoxDodajKraj->itemText(i);
        mainDb->addKraj(daneKraj)  ;
    }
//    plikOdczytDodajKraj.close();
    //
    checkFlagsinKraj
        .open(file11.toStdString(),
              ios::in
                  | ios::trunc); //ios::app dopisuje a ios::trunc zawartos usunieta i zastąpiona nową.
    checkFlagsinKraj << "1";
    checkFlagsinKraj.close();
    ui->pushButton->setEnabled(false); // Przycisk Zapisz
}

void KontrahentDodajKraj::on_pushButton_3_clicked()
{
    // Usuń
    ui->comboBoxDodajKraj->removeItem(ui->comboBoxDodajKraj->currentIndex());
    ui->pushButton->setEnabled(true);
}

void KontrahentDodajKraj::on_pushButton_4_clicked()
{
    // Zamknij
    destroy();
}
