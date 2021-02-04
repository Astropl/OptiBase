#include "urzadzenialista.h"
#include "DataBase/maindb.h"
#include "Timery/timedate.h"
#include "Ustawienia/ustawienia.h"
#include "ui_urzadzenialista.h"
#include "urzadzenialistakontrahent.h"
#include "urzadzenialistaedytuj.h"
#include <Info/info.h>
#include <ctime>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <QApplication>
#include <QMessageBox>
#include <QString>
#include <QTableView>
#include <QTimer>
#include <QtWidgets>

using namespace std;
fstream fileUrzadzeniaLista, fileUrzadzeniaLista2;
int rowDoSize = 0, iTabelaPustychRzedow = 0;
int pusteRzedy = (rowDoSize) - (iTabelaPustychRzedow);


UrzadzeniaLista::UrzadzeniaLista(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UrzadzeniaLista)
{
    ui->setupUi(this);
    //---------Sekcja generacji timera
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myfunctiontimer()));
    timer->start(1000);
    //===================
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
    initMenuUrzadzeniaLista();
    wczytajDane();
}

UrzadzeniaLista::~UrzadzeniaLista()
{
    delete ui;
}
void UrzadzeniaLista::initMenuUrzadzeniaLista()
{
    //tworze menu kontekstowe
    setWindowTitle("OptiBase v 1.0:Urządzenia - Lista");

    //    QAction *fileSave = new QAction(("&Zapisz"), this);
    //    QAction *fileEksport = new QAction(("&Eksport"), this);
    // QAction *fileseparator = new QAction(("----------"), this);
    QAction *fileWyjscie = new QAction(("&Wyjście"), this);

    //    QAction *edycjaDodajProducenta = new QAction(("Dodaj Producenta"), this);
    //    QAction *edycjaDodajModel = new QAction(("Dodaj Model"), this);

    //    QAction *editKopiuj = new QAction(("&Kopiuj"), this);
    //    QAction *editWklej = new QAction(("&Wklej"), this);

    QAction *infoOProgramie = new QAction(("&O Programie"), this);
    QAction *infoOAutorze = new QAction(("O &Autorze"), this);
    QAction *infoLog = new QAction(("&Log"), this);

    QAction *settingsOption = new QAction(("&Opcje"), this);

    auto mainfile = menuBar()->addMenu("Plik");
   // auto mainEdycja = menuBar()->addMenu("Edycja");
    auto mainInfo = menuBar()->addMenu("Informacje");
    auto mainSettings = menuBar()->addMenu("Ustawienia");

    //    mainfile->addAction(fileSave);
    //    mainfile->addAction(fileEksport);

    mainfile->addSeparator();
    mainfile->addAction(fileWyjscie);

    //    mainEdycja->addAction(edycjaDodajProducenta);
    //    mainEdycja->addAction(edycjaDodajModel);

    //    mainEdycja->addAction(editKopiuj);
    //    mainEdycja->addAction(editWklej);
    mainInfo->addAction(infoOProgramie);
    mainInfo->addAction(infoOAutorze);
    mainInfo->addAction(infoLog);

    mainSettings->addAction(settingsOption);

    //connect(settingsOption, &QAction::triggered,this, SLOT (openInfo()));
    connect(settingsOption, SIGNAL(triggered()), this, SLOT(openSettings()));
    connect(infoOProgramie, SIGNAL(triggered()), this, SLOT(openInfo()));
    //    connect(edycjaDodajProducenta,
    //            SIGNAL(triggered()),
    //            this,
    //            SLOT(on_actionDodaj_Producenta_triggered()));
    //    connect(edycjaDodajModel, SIGNAL(triggered()), this, SLOT(on_actionDodaj_Model_triggered()));

    ui->label->setVisible(false);
    ui->label_2->setVisible(false);
}
void UrzadzeniaLista::wczytajDane()
{//qWarning()<<"Jestem w UrzadzeniaLista:WczytajDane";
    MainDb *mainDb = new MainDb(this);
ui->checkBox->setChecked(false);
    // QString file1 = "C:/Defaults/Pliki/1.DB.txt";
    //QString file2 = "C:/Defaults/Pliki/2.Kontrahent.txt";
    //QString file3 = "C:/Defaults/Pliki/3.Urzadzenie.txt";
    model = new QStandardItemModel(1, 6, this);
    ui->tableView->setModel(model);
    //QModelIndex *index;

    model->setHeaderData(0, Qt::Horizontal, "L.P.");
    model->setHeaderData(1, Qt::Horizontal, "Producent");
    model->setHeaderData(2, Qt::Horizontal, "Model");
    model->setHeaderData(3, Qt::Horizontal, "Nr Seryjny");
    model->setHeaderData(4, Qt::Horizontal, "Przypisany");
     model->setHeaderData(5, Qt::Horizontal, "Kontrahent");

    //    model->setHeaderData(5, Qt::Horizontal, "Kontrahent");
    //    model->setHeaderData(6, Qt::Horizontal, "Imię");
    //    model->setHeaderData(7, Qt::Horizontal, "Nazwisko");

    //    model->setHeaderData(8, Qt::Horizontal, "Kraj");
    //    model->setHeaderData(9, Qt::Horizontal, "Region");
    //        model->setHeaderData(10, Qt::Horizontal, "Miasto");
    //        model->setHeaderData(11, Qt::Horizontal, "Kod Pocztowy");
    //        model->setHeaderData(12, Qt::Horizontal, "Ulica");
    //        model->setHeaderData(13, Qt::Horizontal, "Nr domu/mieszkania");
    //        model->setHeaderData(14, Qt::Horizontal, "Telefon");
    //        model->setHeaderData(15, Qt::Horizontal, "Telefon prywatny");
    //        model->setHeaderData(16, Qt::Horizontal, "Adres E-mail");
    //        model->setHeaderData(17, Qt::Horizontal, "Strona URL");
    //---------------------------------------------------------------
    //ui->tableView->setColumnHidden(0,true); //Ukrywam kolumne z LP
    //---------------------------------------------------------------
    QStandardItem *dodajItem = new QStandardItem();

    int pobierzUrzId = 0;

    QString pobierzUrz = "";

    pobierzUrzId = mainDb->pobierzUrzadzeniaId(pobierzUrzId);
    for (int i = 1; i <= pobierzUrzId; i++) {
        for (int d = 0; d <= 5; d++) {
            pobierzUrz = mainDb->pobierzUrzadzenia(pobierzUrz, i, d);
            dodajItem = new QStandardItem(pobierzUrz);
            model->setItem(i - 1, d, dodajItem);
        }
    }

    int rowDoSize = model->rowCount();
    for (int i = 0; i <= rowDoSize; i++) {
        ui->tableView->setRowHeight(i, 20);
    }
    ui->tableView->horizontalHeader()->setSectionResizeMode(
        QHeaderView::ResizeToContents); // Rozszerza kolumny do najdłuzszego itema w kolumnie.
    ui->tableView->sortByColumn(0,
                                Qt::SortOrder(0)); // Pierwsza cyfea mowi od jakiej kolumny sortujemy

    //ui->tableView->setRowHeight(1,20);
    //ui->tableView->setRowHeight(2,20);
    //ui->tableView->setRowHeight(3,20);
    iloscWierszy();
    //qWarning()<<"Jestem w UrzadzeniaLista:WczytajDane:End";
}

void UrzadzeniaLista::iloscWierszy()
{
    int iloscWierszy = model->rowCount();
    QString qIloscWierszy;
    qIloscWierszy.setNum(iloscWierszy);
    ui->labelTest->setText("Ilosć Urządzeń: " + qIloscWierszy);
    cout << iloscWierszy;
}
void UrzadzeniaLista::myfunctiontimer()
{
    time_t czas;
    tm timeinfo;
    QString qStrMin, qStrGodz, qStrSek, qStrDzien, qStrMiesiac, stringDzienTygodnia;

    TimeDate *timeDate = new TimeDate();

    time(&czas);
    timeinfo = *localtime(&czas);
    int godzina = timeinfo.tm_hour;
    int minuta = timeinfo.tm_min;
    int sekunda = timeinfo.tm_sec;
    int dzien = timeinfo.tm_mday;
    int miesiac = timeinfo.tm_mon;
    int rok = timeinfo.tm_year;
    int dzienTygodnia = timeinfo.tm_wday;
    miesiac = miesiac + 1;
    rok = rok + 1900;
    dzienTygodnia = dzienTygodnia + 1;

    qStrMin = timeDate->changeStringsMin(minuta);
    qStrSek = timeDate->changeStringsSek(sekunda);
    qStrDzien = timeDate->changeStringsDzien(dzien);
    qStrGodz = timeDate->changeStringsGodz(godzina);
    qStrMiesiac = timeDate->changeStringsMiesiac(miesiac);
    stringDzienTygodnia = timeDate->changeStringsDzienTygodnia(dzienTygodnia);

    ui->labelZegara->setText(qStrGodz + ":" + qStrMin + ":" + qStrSek);
    ui->labelDaty->setText(QString::number(rok) + "." + qStrMiesiac + "." + qStrDzien);

    ui->labelDzien->setText(stringDzienTygodnia);
}
void UrzadzeniaLista::on_pushButton_clicked()
{
    //Odswiez

    wczytajDane();
}

void UrzadzeniaLista::on_pushButton_2_clicked()
{
    //Zamknij
    destroy();
}

void UrzadzeniaLista::on_pushButton_3_clicked()
{
    //Usuń
    // usunać zaznaczony rząd
MainDb *mainDb = new MainDb(this);
    QMessageBox msgBox;
    if (QMessageBox::question(this,
                              "Ostrzeżenie",
                              "Czy na pewno chcesz usunąć zaznaczony rekord?.",
                              QMessageBox::Ok | QMessageBox::Cancel)
        == QMessageBox::Ok)
    //(QMessageBox::Ok)
    {
        int iloscColumn = model->columnCount();
        QString qIloscColumn;
        qIloscColumn.setNum(iloscColumn);

        //--------------
        int stringrowDoSize = (ui->tableView->currentIndex().row()) + 1;
        //cout << "Zaznaczony rzad to: " << stringrowDoSize << endl;

        ui->label_2->setText(QString::number(iloscColumn) + " " + QString::number(stringrowDoSize));
        QModelIndex index = ui->tableView->selectionModel()->currentIndex();
        QVariant vartosc = index.sibling(index.row(), index.column()).data();
        QString QVartsoc = QVariant(vartosc).toString();
        ui->label->setText(QVartsoc); //Pokazuje kliknietą komórkę.

        QVariant tab[iloscColumn];
        QVariant wyslij;
        for (int i = 0; i <= iloscColumn; i++) {
            tab[i] = index.sibling(stringrowDoSize - 1, i).data();
        }


 //TODO: usunać z bazy danych urzadzenie  o takim numerze seryjnym
        QString QNumerSeryjny="";
        //QVariant VNumerSeryjny = index.sibling(index.row(), index.column()).data();
        QVariant VNumerSeryjny = index.sibling(index.row(), (3)).data();


        QNumerSeryjny = QVariant(VNumerSeryjny).toString();
        mainDb->UrzadzeniaDelete(QNumerSeryjny);

        model->removeRows(stringrowDoSize - 1, 1);
        //wczytaj ponownie dane
        iloscWierszy();



        QMessageBox::information(this, "Ostrzeżenie", "Rekord  usunięty");
    } else {
        QMessageBox::information(this, "Ostrzeżenie", "Rekord nie usunięty");
    }
}

void UrzadzeniaLista::on_pushButton_4_clicked()
{
    //Edytuj
    QString qLp="Test", qProducent="Test", qModel="Test", qNrSeryjny="Test", qPrzypisany="Test", qKontrahent="Test";
    UrzadzeniaListaEdytuj *Ule = new UrzadzeniaListaEdytuj(this);

    int iloscColumn = model->columnCount();
    int stringRowDosize = (ui->tableView->currentIndex().row())+1;
    QModelIndex index = ui->tableView->selectionModel()->currentIndex();
    QVariant vartosc = index.sibling(index.row(), index.column()).data();
    QString QVartsoc = QVariant(vartosc).toString();
    ui->label->setText(QVartsoc); //Pokazuje kliknietą komórkę.

    QVariant tab[iloscColumn];
    QVariant wyslij;
    for (int i = 0; i <= iloscColumn; i++) {
        tab[i] = index.sibling(stringRowDosize - 1, i).data();
    }



    Ule->setLabelsInfo (tab[0],
                       tab[1],
                       tab[2],
                       tab[3],
                       tab[4],
                       tab[5] );
    Ule->show();

}

void UrzadzeniaLista::on_pushButton_5_clicked()
{
    //Zapisz
}

void UrzadzeniaLista::on_pushButton_6_clicked()
{
    // Przypisz Kontrahenta

    //Wyswietl Tabele kontrahentów.
    // Zaznacz jakiegos
    //Dopisz do TABELI z urzadzeniami
    //Zapisz w pliku BDMain

    QModelIndex index = ui->tableView->selectionModel()->currentIndex();
    QVariant vartosc = index.sibling(index.row(), index.column()).data();
    QString QVartsoc = QVariant(vartosc).toString();
    ui->label->setText(QVartsoc); //Pokazuje kliknietą komórkę.
    if (QVariant(vartosc).toString() == "Przypisany") {
        QMessageBox::information(this,
                                 "Ostrzeżenie",
                                 "Ten analizator jest juz przypisany do konkretnego kontrahenta. "
                                 "Nie możesz go przypisać do innego.");

    } else {
        //cout << "nie przypisany" << endl;

        UrzadzeniaListaKontrahent *urzkl = new UrzadzeniaListaKontrahent(this);
        int iloscColumn = model->columnCount();

        int stringrowDoSize = (ui->tableView->currentIndex().row()) + 1;
        QVariant tab[iloscColumn];
        QVariant wyslij;
        for (int i = 0; i <= iloscColumn; i++) {
            tab[i] = index.sibling(stringrowDoSize - 1, i).data();
        }

        urzkl->wyswietl(tab[0], tab[1], tab[2], tab[3]);

        urzkl->show();
    }
}
void UrzadzeniaLista::openInfo()
{
    Info *info = new Info(this);
    info->show();
}
void UrzadzeniaLista::openSettings()
{
    Ustawienia *ustaw = new Ustawienia(this);
    ustaw->show();
}
void UrzadzeniaLista::on_checkBox_stateChanged()
{

    pusteRzedy = ui->label_2->text().toInt();
    //qWarning() << "checekd Mark Filtr ON:OFF";
    if (ui->checkBox->isChecked()) {
        //qWarning() << "cKliknietey";
        ui->comboBox->setVisible(true);
        ui->comboBox_2->setVisible(true);
        ui->comboBox_3->setVisible(true);
        //filtrOn("Brak");
        fillComboBoxes();
    } else {
       // qWarning() << "NIE Klikniety";
        ui->comboBox->setVisible(false);
        ui->comboBox_2->setVisible(false);
        ui->comboBox_3->setVisible(false);
        ui->comboBox->clear();
        ui->comboBox_2->clear();
        ui->comboBox_3->clear();
        for (int i = 0; i <= model->rowCount() - 1 - pusteRzedy; i++) {
           // qWarning() << "Wejscie do odkrycia rzedów numer : " << i;
            ui->tableView->showRow(i);
        }
    }

}

void UrzadzeniaLista::fillComboBoxes()
{
    bool jestItem;
    pusteRzedy = ui->label_3->text().toInt();
    ui->comboBox->addItem("Brak");
    ui->comboBox_2->addItem("Brak");
    ui->comboBox_3->addItem("Brak");

    for (int i = 0; i <= model->rowCount() - 1 - pusteRzedy; i++) {
        //int iloscElemtowWCB5 = ui->comboBox_5->count();

        QStandardItem *item1 = model->item(i, 1);
        QStandardItem *item2 = model->item(i, 2);
        QStandardItem *item3 = model->item(i, 4);

        //NOTE: Sprawdzam czy element jest juz na liscie w comboBox

        //
        ui->comboBox->addItem(item1->text());
        ui->comboBox_2->addItem(item2->text());
        ui->comboBox_3->addItem(item3->text());
    }
    int iloscElemetowWCB2 = ui->comboBox_2->count();

    for (int j = 0; j <= iloscElemetowWCB2; j++)

    {
        //qWarning() << "wyraz do porowniaa to: " << ui->comboBox_5->itemText(j);

        for (int k =j+ 1; k <= iloscElemetowWCB2; k++) {
            if (ui->comboBox_2->itemText(j) == ui->comboBox_2->itemText(k)) {
                ui->comboBox_2->removeItem(k);
            }
        }

    } //
    int iloscElemetowWCB3 = ui->comboBox_3->count();

    for (int j = 0; j <= iloscElemetowWCB3; j++)

    {
        //qWarning() << "wyraz do porowniaa to: " << ui->comboBox_6->itemText(j);

        for (int k =j+ 1; k <= iloscElemetowWCB3 - 1; k++) {
            //qWarning() << "Porownuje : " << ui->comboBox_6->itemText(j)
            //<< " z: " << ui->comboBox_6->itemText(k);
            if (ui->comboBox_3->itemText(j) == ui->comboBox_3->itemText(k)) {
                //qWarning() << "Usuwam : " << ui->comboBox_6->itemText(k);
                ui->comboBox_3->removeItem(k);
            }
        }

    } //
    int iloscElemetowWCB0 = ui->comboBox->count();

    for (int j = 0; j <= iloscElemetowWCB0; j++)

    {
        //qWarning() << "wyraz do porowniaa to: " << ui->comboBox_6->itemText(j);

        for (int k =j+ 1; k <= iloscElemetowWCB0 - 1; k++) {
            //qWarning() << "Porownuje : " << ui->comboBox_6->itemText(j)
            //<< " z: " << ui->comboBox_6->itemText(k);
            if (ui->comboBox->itemText(j) == ui->comboBox->itemText(k)) {
                //qWarning() << "Usuwam : " << ui->comboBox_6->itemText(k);
                ui->comboBox->removeItem(k);
            }
        }

    } //


}
void UrzadzeniaLista::on_comboBox_activated(const QString &arg1)
{
    //qWarning() << "Activatefd w CB5: " << ui->comboBox_5->currentText();
    QString aktywnyProducent = ui->comboBox->currentText();
    filtrOn(aktywnyProducent);
}

void UrzadzeniaLista::on_comboBox_2_activated(const QString &arg1)
{
    //qWarning() << "Activatefd w CB6: " << ui->comboBox_6->currentText();
    QString aktywnyProducent = ui->comboBox_2->currentText();
    filtrOn(aktywnyProducent);
}
void UrzadzeniaLista::on_comboBox_3_activated(const QString &arg1)
{
    //qWarning() << "Activatefd w CB6: " << ui->comboBox_6->currentText();
    QString aktywnyProducent = ui->comboBox_3->currentText();
    filtrOn(aktywnyProducent);
}
QString UrzadzeniaLista::filtrOn(QString aktywnyProducent)
{
    for (int k = 0; k <= model->rowCount() - 1; k++) {
        //qWarning() << "Ukrywam rzad : " << k;

        ui->tableView->hideRow(k);
    }

    //qWarning() << "Jestem w filtrze";
    QString filter = aktywnyProducent;

    //qWarning() << " Odkrywam takie co mają w nazwie Jawon";
    pusteRzedy = ui->label_2->text().toInt();
    //qWarning() << "Puste rzedy to : " << pusteRzedy;
    //for (int i =0; i<=model ->rowCount()-1;i++)// pusteRzedy
    for (int i = 0; i <= model->rowCount() - 1 - pusteRzedy; i++) // pusteRzedy
    {
        for (int j = 0; j <= model->columnCount() - 1; j++) {
            QStandardItem *item = model->item(i, j);
            //qWarning() << " Wyswietlam i: " << i << " j: " << j << " wyraz to: " << item->text();

            if (filter == "Brak") {
                ui->tableView->showRow(i);
            } else {
                if (item->text().contains(filter)) {
                    //qWarning() << "Wiersz: " << i << " zawiera: " << filter;
                    ui->tableView->showRow(i);
                }
            }
        }
        //TODO: Jakis problem przy wyswietlaniu powyzej 12 linii. ( czyli 13) tam gdzie mam puste czyli nulle.
    }
}