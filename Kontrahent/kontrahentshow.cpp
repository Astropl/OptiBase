#include "kontrahentshow.h"

#include "DataBase/checkfiles.h"
#include "DataBase/maindb.h"
#include "Info/info.h"
#include "ui_kontrahentshow.h"
#include <String>
#include <fstream>
#include <iostream>
#include <ostream>
#include <QDebug>
#include <QString>

using namespace std;

int checkFlagsVarriableMiastoKontrahentShow = 0;
int checkFlagsVarriableWojewodztwoKontrahentShow = 0;
int checkFlagsVarriableKrajKontrahentShow = 0;
QString tab[13];

KontrahentShow::KontrahentShow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KontrahentShow)
{
    ui->setupUi(this);

    //cout << "Jestem w Kontrahebt show" << endl;
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
}

KontrahentShow::~KontrahentShow()
{
    delete ui;
}

void KontrahentShow::on_pushButton_2_clicked()
{ // button zamknij
    destroy();
}

QVariant KontrahentShow::wyswietl(QVariant p1,
                                  QVariant p2,
                                  QVariant p3,
                                  QVariant p4,
                                  QVariant p5,
                                  QVariant p6,
                                  QVariant p7,
                                  QVariant p8,
                                  QVariant p9,
                                  QVariant p10,
                                  QVariant p11,
                                  QVariant p12,
                                  QVariant p13,
                                  QVariant p14)
{
    //cout << "Chche wysiwretlic i dopisac do labeli wybranego kontrahenta" << endl;
    ui->lblNumerPorz->setText(p1.toString());
    ui->leNazwa->setText(p2.toString());
    ui->leImie->setText(p3.toString());
    ui->leNazwisko->setText(p4.toString());
    ui->leKraj->setText(p5.toString());
    ui->comboBoxKraj->addItem(p5.toString());
    ui->comboBoxMiasta->addItem(p7.toString());      // tutaj
    ui->comboBoxWojewodztwa->addItem(p6.toString()); // tutaj
    ui->leRegion->setText(p6.toString());            // tutaj
    ui->leMiasto->setText(p7.toString());            // tutaj
    ui->leKod->setText(p8.toString());
    ui->leUlica->setText(p9.toString());
    ui->leNrDomu->setText(p10.toString());
    ui->leTelefon->setText(p11.toString());
    ui->leTelPryw->setText(p12.toString());
    ui->leEmail->setText(p13.toString());
    ui->leUrl->setText(p14.toString());
    return 0;
}
//Info do Gita
void KontrahentShow::on_pushButton_clicked()
{
    // Edycja wybranego kontrahenta

    // Odblokować pola edycyjne
    unblock();

    showCities();
    showWojewodztwa();
    showKraj();
    //wczytać kraj, wojewodztwa i miasta do comboboxów

    // ustawić w vombo boxach aktualne nazwy z wyboru

    //zapisac

    //Zmienić region w UI -> Wojewodzwtwo
}
void KontrahentShow::showKraj()
{ //TODO: ZAMIENIC NA WCZYTYWANIE Z SQL

    //Wczytac liste krajów z MainDB i dodoac ją do comboBoxDodajKra
    ui->comboBoxKraj->clear();
    MainDb *mainDb = new MainDb(this);
    QString QStringpobierzKraj;
    int pobierzKrajId = 0;
    pobierzKrajId = mainDb->pobierzKrajId(pobierzKrajId);
    for (int i = 1; i <= pobierzKrajId; i++) {
        QStringpobierzKraj = mainDb->pobierzKraj(QStringpobierzKraj, i);
        ui->comboBoxKraj->addItem(QStringpobierzKraj);
    }
    ui->comboBoxKraj->setCurrentText(ui->leKraj->text());
}

void KontrahentShow::showWojewodztwa()
{ //TODO: ZAMIENIC NA WCZYTYWANIE Z SQL
    ui->comboBoxWojewodztwa->clear();
    //Wczytac liste wojewdoztw z MainDB i dodoac ją do comboBoxDodajWojewdoztwo
    MainDb *mainDb = new MainDb(this);
    QString QStringpobierzWojewodztwo;
    int pobierzWojewodztwoId = 0;
    pobierzWojewodztwoId = mainDb->pobierzWojewodztwoId(pobierzWojewodztwoId);
    for (int i = 1; i <= pobierzWojewodztwoId; i++) {
        QStringpobierzWojewodztwo = mainDb->pobierzWojewodztwo(QStringpobierzWojewodztwo, i);
        ui->comboBoxWojewodztwa->addItem(QStringpobierzWojewodztwo);
    }

    ui->comboBoxWojewodztwa->setCurrentText(ui->leRegion->text());
}
void KontrahentShow::showCities()
{
    ui->comboBoxMiasta->clear();
    //Wczytac liste miast z MainDB i dodoac ją do comboBoxDodajKra
    MainDb *mainDb = new MainDb(this);
    QString QStringpobierzMiasto;
    int pobierzMiastoId = 0;
    pobierzMiastoId = mainDb->pobierzMiastoiD(pobierzMiastoId);
    for (int i = 1; i <= pobierzMiastoId; i++) {
        QStringpobierzMiasto = mainDb->pobierzMiasto(QStringpobierzMiasto, i);
        ui->comboBoxMiasta->addItem(QStringpobierzMiasto);
    }

    ui->comboBoxMiasta->setCurrentText(ui->leMiasto->text());
}
void KontrahentShow::on_pushButton_3_clicked() //ZAPISZ?

{
    MainDb *mainDb = new MainDb(this);
    //QString file2 = "C:/Defaults/Pliki/2.Kontrahent.txt";
    ui->comboBoxPomoc->clear();
    ui->comboBoxPomoc1->clear();
    //ZAPISZ wszytsko
    //cout << "Zapisuje po edycji" << endl;
    // Wczytać dane do cmoboBoxaPomoc.
    // Znalesc te same dane co sa w trybie edycji.
    // skasować te dane.
    // Dopisać te nowe
    //Zapisać wszytsko.
    //
    //fstream file;
    string kontrahent;
    //Zapisz
    //cout << "Zapisuje" << endl;

    //file.open("C:/Defaults/Pliki/2.Kontrahent.txt", ios::out | ios::app);

    // musze teraz zrobic petle i zapisac itemy z comboboxa
    //int iloscElementowWcombo;

    //tymczasowo

    // sprawdzic czy labele sa puste
    //QString tymcsowet = ui->leNazwa->text();
    if (ui->leNazwa->text() == "")

    {
        // pusty
    } else {
        ui->comboBoxPomoc->addItem(ui->lblNumerPorz->text());
        ui->comboBoxPomoc->addItem(ui->leNazwa->text());
        ui->comboBoxPomoc->addItem(ui->leImie->text());
        ui->comboBoxPomoc->addItem(ui->leNazwisko->text());
        ui->comboBoxPomoc->addItem(ui->comboBoxKraj->currentText());
        //Wczytaj wojewodztwo
        ui->comboBoxPomoc->addItem(ui->comboBoxWojewodztwa->currentText());
        //Wczytaj miasto
        ui->comboBoxPomoc->addItem(ui->comboBoxMiasta->currentText());
        ui->comboBoxPomoc->addItem(ui->leKod->text());
        ui->comboBoxPomoc->addItem(ui->leUlica->text());
        ui->comboBoxPomoc->addItem(ui->leNrDomu->text());
        ui->comboBoxPomoc->addItem(ui->leTelefon->text());
        ui->comboBoxPomoc->addItem(ui->leTelPryw->text());
        ui->comboBoxPomoc->addItem(ui->leEmail->text());
        ui->comboBoxPomoc->addItem(ui->leUrl->text());
    }

    //plikKontrahent<<ui->

    //int QComboBox::findText(const QString &text, Qt::MatchFlags flags) const;

    int findPosition = ui->comboBoxPomoc->findText(ui->leNazwa->text(), Qt::MatchContains);

    //warning:
    ui->label_14->setText(QString::number(findPosition));
    //file.close();

    //fstream fileKontrahent;

    //Wczytac kontrahentow do CBP1

    // Ilosc kontrahentow

    // pobrac kontarhanta

    int iloscKontrahentow = 0, i = 0, d = 0;
    QString QKontrahent = "";
    iloscKontrahentow = mainDb->pobierzKontrahentaId(iloscKontrahentow);

    //qWarning() << "ilosc kontrahentow pobranych z bazy to: " << iloscKontrahentow;






    QString tym1 = ui->leNazwa->text();
        QString tym2 = ui->leImie->text();
        QString tym3 = ui->leNazwisko->text();

        QString tym4 = ui->comboBoxKraj->currentText();
        QString tym5 = ui->comboBoxWojewodztwa->currentText();
        QString tym6 = ui->comboBoxMiasta->currentText();

        QString tym7 = ui->leKod->text();
        QString tym8 = ui->leUlica->text();
        QString tym9 = ui->leNrDomu->text();
        QString tym10 = ui->leTelefon->text();
        QString tym11 = ui->leTelPryw->text();
        QString tym12 = ui->leEmail->text();
        QString tym13 = ui->leUrl->text();

        mainDb->addKontrahenciUpdate(tym1,tym2,tym3,tym4,tym5,tym6,tym7,tym8,tym9,tym10,tym11,tym12,tym13);


        //// //
        ////    ui->leImie->setText("");
        ////    ui->leNazwisko->setText("");
        ////    ui->leKraj->setText("");
        ////    ui->leRegion->setText("");
        ////    ui->comboBoxKraj->clear();
        ////    ui->comboBoxWojewodztwa->clear();
        ////    ui->comboBoxMiasta->clear();
        ////    ui->leMiasto->setText("");
        ////    ui->leKod->setText("");
        ////    ui->leUlica->setText("");
        ////    ui->leNrDomu->setText("");
        ////    ui->leTelefon->setText("");
        ////    ui->leTelPryw->setText("");
        ////    ui->leEmail->setText("");
        ////    ui->leUrl->setText("");

        //}

        //    int findPosition2 = ui->comboBoxPomoc1->findText(ui->leNazwa->text(), Qt::MatchContains);
        //    //ui->label_15->setText(ui->comboBoxPomoc1->itemText(findPosition2));
        //    int koniecPomocy1 = ui->comboBoxPomoc1->count();
        //    QString tym1 = ui->comboBoxPomoc1->itemText(findPosition2 - 1);
        //    QString tym2 = ui->comboBoxPomoc1->itemText(findPosition2);
        //    QString tym3 = ui->comboBoxPomoc1->itemText(findPosition2 + 1);
        //    QString tym4 = ui->comboBoxPomoc1->itemText(findPosition2 + 2);
        //    QString tym5 = ui->comboBoxPomoc1->itemText(findPosition2 + 3);
        //    QString tym6 = ui->comboBoxPomoc1->itemText(findPosition2 + 4);
        //    QString tym7 = ui->comboBoxPomoc1->itemText(findPosition2 + 5);
        //    QString tym8 = ui->comboBoxPomoc1->itemText(findPosition2 + 6);
        //    QString tym9 = ui->comboBoxPomoc1->itemText(findPosition2 + 7);
        //    QString tym10 = ui->comboBoxPomoc1->itemText(findPosition2 + 8);
        //    QString tym11 = ui->comboBoxPomoc1->itemText(findPosition2 + 9);
        //    QString tym12 = ui->comboBoxPomoc1->itemText(findPosition2 + 10);
        //    QString tym13 = ui->comboBoxPomoc1->itemText(findPosition2 + 11);
        //    QString tym14 = ui->comboBoxPomoc1->itemText(findPosition2 + 12);

        //    for (int i = -1; i <= ui->comboBoxPomoc->count() - 2; i++) {
        //        QString tym8 = ui->comboBoxPomoc1->itemText(findPosition2 - 1);
        //        ui->comboBoxPomoc1->removeItem(findPosition2 - 1);
        //    }

        //    for (int i = 0; i <= ui->comboBoxPomoc->count() - 1; i++) {
        //        ui->comboBoxPomoc1->addItem(ui->comboBoxPomoc->itemText(i));
        //    }

        //    //teraz zapisac itemy z comboxaPomoc1

        //    int iloscWComboPomoc1 = ui->comboBoxPomoc1->count();
        //    string ala1;
        //    for (int i = 0; i <= iloscWComboPomoc1 - 1; i++) {
        //        ala1 = ui->comboBoxPomoc1->itemText(i).toStdString();
        //        //fileKontrahent << ala1 << endl;
        //    }

        //    //fileKontrahent.close();
        //    ui->comboBoxPomoc->clear();

}
void KontrahentShow::on_pushButton_4_clicked()
{
    QString file2 = "C:/Defaults/Pliki/2.Kontrahent.txt";

    //-----------------------------------------
    ui->comboBoxPomoc->clear();
    ui->comboBoxPomoc1->clear();
    //--------------------------------------------
    //Usuń kontrahenta
    cout << "Kontrahent usunięty" << endl;

    // Odblokować pola edycyjne
    unblock();
    //dodac do comboPomoc kontrahenta do usuniecia
    ui->comboBoxPomoc->addItem(ui->lblNumerPorz->text());
    ui->comboBoxPomoc->addItem(ui->leNazwa->text());
    ui->comboBoxPomoc->addItem(ui->leImie->text());
    ui->comboBoxPomoc->addItem(ui->leNazwisko->text());
    ui->comboBoxPomoc->addItem(ui->comboBoxKraj->currentText());
    //Wczytaj wojewodztwo
    ui->comboBoxPomoc->addItem(ui->comboBoxWojewodztwa->currentText());
    //Wczytaj miasto
    ui->comboBoxPomoc->addItem(ui->comboBoxMiasta->currentText());
    ui->comboBoxPomoc->addItem(ui->leKod->text());
    ui->comboBoxPomoc->addItem(ui->leUlica->text());
    ui->comboBoxPomoc->addItem(ui->leNrDomu->text());
    ui->comboBoxPomoc->addItem(ui->leTelefon->text());
    ui->comboBoxPomoc->addItem(ui->leTelPryw->text());
    ui->comboBoxPomoc->addItem(ui->leEmail->text());
    ui->comboBoxPomoc->addItem(ui->leUrl->text());
    //int iloscWComboPomoc1 = ui->comboBoxPomoc1->count();
    //iloscWComboPomoc1 = ui->comboBoxPomoc1->count();

    int findPosition = ui->comboBoxPomoc->findText(ui->leNazwa->text(), Qt::MatchContains);
    fstream fileKontrahent;
    fileKontrahent.open(file2.toStdString(), ios::in);
    string linia;
    while (getline(fileKontrahent, linia)) {
        ui->comboBoxPomoc1->addItem(linia.c_str());
        cout << linia.c_str() << endl;
    }
    fileKontrahent.close();

    ui->label_14->setText(QString::number(findPosition));
    int findPosition2 = ui->comboBoxPomoc1->findText(ui->leNazwa->text(), Qt::MatchContains);
    //wyczyscic pola edycyjne
    ui->leNazwa->setText("");
    ui->leImie->setText("");
    ui->leNazwisko->setText("");
    ui->leKraj->setText("");
    ui->leRegion->setText("");
    ui->comboBoxKraj->clear();
    ui->comboBoxWojewodztwa->clear();
    ui->comboBoxMiasta->clear();
    ui->leMiasto->setText("");
    ui->leKod->setText("");
    ui->leUlica->setText("");
    ui->leNrDomu->setText("");
    ui->leTelefon->setText("");
    ui->leTelPryw->setText("");
    ui->leEmail->setText("");
    ui->leUrl->setText("");

    int iloscWComboPomoc1 = ui->comboBoxPomoc1->count();
    // szukamy nazwy w combo pomoc i i szuamy jej w combopomoc1

    //warning:

    //usuwam w combopomoc1
    for (int i = -1; i <= ui->comboBoxPomoc->count() - 2; i++) {
        QString tym8 = ui->comboBoxPomoc1->itemText(findPosition2 - 1);
        ui->comboBoxPomoc1->removeItem(findPosition2 - 1);
    }
    // i zapisuje
    fileKontrahent.open(file2.toStdString(), ios::out);
    //teraz zapisac itemy z comboxaPomoc1
    fileKontrahent.clear();
    ui->comboBoxPomoc1->update();
    iloscWComboPomoc1 = ui->comboBoxPomoc1->count();
    string ala1;
    for (int i = 0; i <= iloscWComboPomoc1 - 1; i++) {
        ala1 = ui->comboBoxPomoc1->itemText(i).toStdString();
        fileKontrahent << ala1 << endl;
    }

    fileKontrahent.close();
    ui->comboBoxPomoc->clear();
}
void KontrahentShow::unblock()
{
    // Odblokować pola edycyjne
    ui->leNazwa->setEnabled(true);
    ui->leImie->setEnabled(true);
    ui->leNazwisko->setEnabled(true);
    ui->leKraj->setEnabled(true);
    ui->leRegion->setEnabled(true);
    ui->comboBoxKraj->setEnabled(true);
    ui->comboBoxWojewodztwa->setEnabled(true);
    ui->comboBoxMiasta->setEnabled(true);
    ui->leMiasto->setEnabled(true);
    ui->leKod->setEnabled(true);
    ui->leUlica->setEnabled(true);
    ui->leNrDomu->setEnabled(true);
    ui->leTelefon->setEnabled(true);
    ui->leTelPryw->setEnabled(true);
    ui->leEmail->setEnabled(true);
    ui->leUrl->setEnabled(true);

    ui->leNazwa->setReadOnly(false);
    ui->leImie->setReadOnly(false);
    ui->leNazwisko->setReadOnly(false);
    ui->leKraj->setReadOnly(false);
    ui->leRegion->setReadOnly(false);
    ui->leMiasto->setReadOnly(false);
    ui->comboBoxKraj->setEditable(true);
    ui->comboBoxWojewodztwa->setEditable(true);
    ui->comboBoxMiasta->setEditable(true);

    //ui->comboBoxKraj->setEditable(true);
    ui->leKod->setReadOnly(false);
    ui->leUlica->setReadOnly(false);
    ui->leNrDomu->setReadOnly(false);
    ui->leTelefon->setReadOnly(false);
    ui->leTelPryw->setReadOnly(false);
    ui->leEmail->setReadOnly(false);
    ui->leUrl->setReadOnly(false);
}

void KontrahentShow::on_comboBoxKraj_highlighted(const QString)
{
    fstream checkFlags;
    QString file13 = "C:/Defaults/Pliki/13.CheckFlagsInKrajKontrahentShow.txt";
    // Sortowanie kraj
    CheckFiles *checkFiles = new CheckFiles(this);
    //cout << "Otrzymanie highland przycisku wczytaj Kraj" << endl;
    checkFlagsVarriableKrajKontrahentShow = checkFiles->checkFlagsKraj(
        checkFlagsVarriableKrajKontrahentShow);
    if (checkFlagsVarriableKrajKontrahentShow != 0) {
        //cout << "textHighlighted" << endl;
        QStringList listaKraj = QStringList();

        ui->comboBoxKraj->clear();
        showKraj();
        int ostatniindex = ui->comboBoxKraj->count() - 1;
        for (int iZmienna = 0; iZmienna <= ostatniindex; iZmienna++) {
            listaKraj.push_back(ui->comboBoxKraj->itemText(iZmienna).toUtf8());
        }
        sort(listaKraj.begin(), listaKraj.end());
        ui->comboBoxKraj->clear();
        for (int kZmienna = 0; kZmienna <= listaKraj.count() - 1; kZmienna++) {
            ui->comboBoxKraj->addItem(listaKraj.at(kZmienna));
        }
    }
    checkFlags.open(file13.toStdString(), ios::out | ios::trunc);
    checkFlags << "0" << endl;
    checkFlags.close();
}

void KontrahentShow::on_comboBoxWojewodztwa_highlighted(const QString)
{
    QString file15 = "C:/Defaults/Pliki/15.CheckFlagsInWojewodztwoKontrahentShow.txt";
    // Sortowanie wojewodztwo
    fstream checkFlags;
    // Sortowanie wojewodztwo
    CheckFiles *checkFiles = new CheckFiles(this);
    //cout << "Otrzymanie highland przycisku wczytaj wojewodztwo" << endl;
    checkFlagsVarriableWojewodztwoKontrahentShow = checkFiles->checkFlagsWojewodztwa(
        checkFlagsVarriableWojewodztwoKontrahentShow);
    if (checkFlagsVarriableWojewodztwoKontrahentShow != 0) {
       // cout << "textHighlighted" << endl;
        QStringList listaWojewodztwo = QStringList();

        ui->comboBoxWojewodztwa->clear();
        showWojewodztwa();
        int ostatniindex = ui->comboBoxWojewodztwa->count() - 1;
        for (int iZmienna = 0; iZmienna <= ostatniindex; iZmienna++) {
            listaWojewodztwo.push_back(ui->comboBoxWojewodztwa->itemText(iZmienna).toUtf8());
        }
        sort(listaWojewodztwo.begin(), listaWojewodztwo.end());
        ui->comboBoxWojewodztwa->clear();
        for (int kZmienna = 0; kZmienna <= listaWojewodztwo.count() - 1; kZmienna++) {
            ui->comboBoxWojewodztwa->addItem(listaWojewodztwo.at(kZmienna));
        }
    }
    checkFlags.open(file15.toStdString(), ios::out | ios::trunc);
    checkFlags << "0" << endl;
    checkFlags.close();
}

void KontrahentShow::on_comboBoxMiasta_highlighted(const QString)
{
    QString file14 = "C:/Defaults/Pliki/14.CheckFlagsInMiastoKontrahentShow.txt";
    // Sortowanie Miasta
    fstream checkFlags;
    // Sortowanie wojewodztwo
    CheckFiles *checkFiles = new CheckFiles(this);
    //cout << "Otrzymanie highland przycisku wczytaj Miasta" << endl;
    checkFlagsVarriableMiastoKontrahentShow = checkFiles->checkFlagsMiasto(
        checkFlagsVarriableMiastoKontrahentShow);
    if (checkFlagsVarriableMiastoKontrahentShow != 0) {
        //cout << "textHighlighted" << endl;
        QStringList listaMiasto = QStringList();

        ui->comboBoxMiasta->clear();
        showCities();
        int ostatniindex = ui->comboBoxMiasta->count() - 1;
        for (int iZmienna = 0; iZmienna <= ostatniindex; iZmienna++) {
            listaMiasto.push_back(ui->comboBoxMiasta->itemText(iZmienna).toUtf8());
        }
        sort(listaMiasto.begin(), listaMiasto.end());
        ui->comboBoxMiasta->clear();
        for (int kZmienna = 0; kZmienna <= listaMiasto.count() - 1; kZmienna++) {
            ui->comboBoxMiasta->addItem(listaMiasto.at(kZmienna));
        }
    }
    checkFlags.open(file14.toStdString(), ios::out | ios::trunc);
    checkFlags << "0" << endl;
    checkFlags.close();
}
