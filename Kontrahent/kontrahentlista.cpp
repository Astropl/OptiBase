#include "kontrahentlista.h"
#include "Timery/timedate.h"
#include "kontrahentshow.h"
#include "tableviewlistakontrahentow.h"
#include "ui_kontrahentlista.h"
#include "Info/info.h"
#include "DataBase/maindb.h"
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
time_t czasKontrahentLista;
tm timeinfoKontrahentLista;
int labelGodzinaKontrahentLista;
int labelDataKontrahentLista;
int wynikKontrahentLista;
int godzinaKontrahentLista, minutaKontrahentLista, sekundaKontrahentLista, dzienKontrahentLista,
    miesiacKontrahentLista, rokKontrahentLista;
int dzienTygodniaKontrahentLista;
string stringDzienTygodniaKontrahentLista;
string zmiennasKontrahentLista;

fstream plikKontrahentLista;

KontrahentLista::KontrahentLista(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KontrahentLista)
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
 initMenuKontrahentLista();
    wczytajDane();
}

KontrahentLista::~KontrahentLista()
{
    delete ui;
}
void KontrahentLista::initMenuKontrahentLista()
{


    //tworze menu kontekstowe
    setWindowTitle("OptiBase v 1.0:Kontrahent - Lista Kontrahentów");

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
    //auto mainEdycja = menuBar()->addMenu("Edycja");
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

}
void KontrahentLista::wczytajDane()
{ MainDb *mainDb = new MainDb(this);
    //QString file2 = "C:/Defaults/Pliki/2.Kontrahent.txt";
    // Tworze modele do Qtable

    model = new QStandardItemModel(1, 15, this);
    ui->tableView->setModel(model);

    model->setHeaderData(0, Qt::Horizontal, "L.P.");
    model->setHeaderData(1, Qt::Horizontal, "Nazwa");
    model->setHeaderData(2, Qt::Horizontal, "Imię");
    model->setHeaderData(3, Qt::Horizontal, "Nazwisko");
    model->setHeaderData(4, Qt::Horizontal, "Kraj");
    model->setHeaderData(5, Qt::Horizontal, "Region");
    model->setHeaderData(6, Qt::Horizontal, "Miasto");
    model->setHeaderData(7, Qt::Horizontal, "Kod Pocztowy");
    model->setHeaderData(8, Qt::Horizontal, "Ulica");
    model->setHeaderData(9, Qt::Horizontal, "Nr domu/mieszkania");
    model->setHeaderData(10, Qt::Horizontal, "Telefon");
    model->setHeaderData(11, Qt::Horizontal, "Telefon prywatny");
    model->setHeaderData(12, Qt::Horizontal, "Adres E-mail");
    model->setHeaderData(13, Qt::Horizontal, "Strona URL");
    model->setHeaderData(14, Qt::Horizontal, "Numer Seryjny z przypisania");

    //---------------------------------------------------------------
    //ui->tableView->setColumnHidden(0, true); //Ukrywam kolumne z LP
        //---------------------------------------------------------------

    QStandardItem *dodajItem = new QStandardItem();



    QString daneKontrahenta;
    int kontrahentId =0, i = 0, d =0;

   kontrahentId=  mainDb->pobierzKontrahentaId(kontrahentId);


   for (i=1;i<= kontrahentId;i++)
   {
       for (d=0;d<=14;d++)
       {
           daneKontrahenta= mainDb->pobierzKontrahenta(daneKontrahenta, i, d);
           dodajItem =new QStandardItem(daneKontrahenta);
           model->setItem(i-1,d,dodajItem);
   }
}



    // pobierz ilosc rzedów
    int rowDoSize = model->rowCount();
    for (int i = 0; i <= rowDoSize; i++) {
        ui->tableView->setRowHeight(i, 20);
    }
    ui->tableView->horizontalHeader()->setSectionResizeMode(
        QHeaderView::ResizeToContents); // Rozszerza kolumny do najdłuzszego itema w kolumnie.
    ui->tableView->sortByColumn(0,
                                Qt::SortOrder(0)); // Pierwsza cyfea mowi od jakiej kolumny sortujemy

    iloscWierszy();
}

void KontrahentLista::iloscWierszy()
{
    int iloscWierszy = model->rowCount();
    QString qIloscWierszy;
    qIloscWierszy.setNum(iloscWierszy);
    ui->labelTest->setText("Ilosć Kontrahentów: " + qIloscWierszy);
    cout << iloscWierszy;
}

void KontrahentLista::myfunctiontimer()
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

void KontrahentLista::on_pushButton_2_clicked() //Exit
{
    timer->stop();
    destroy();
}

void KontrahentLista::on_tableView_activated(const QModelIndex)
{
    //ui->tableView->set
}

void KontrahentLista::on_tableView_doubleClicked(const QModelIndex) //(const QModelIndex &index)
{
    QMessageBox msgBox;
    msgBox.setText("Click, Click, dwa razy");
    msgBox.exec();
}

void KontrahentLista::on_tableView_clicked(const QModelIndex) //(const QModelIndex &index)
{
    QMessageBox msgBox;
    //    msgBox.setText("Click,  tylko raz Click");
    //    msgBox.exec();
    QString pierwszazmienna = "Cos ik tam jest";
    //rzad pokaz
}
//Info do Gita
void KontrahentLista::on_pushButton_clicked()
{
    // Odswiez i wyswietl kontrahentów
    wczytajDane();
}

void KontrahentLista::on_pushButton_3_clicked()
{
    // Edycaj /. usuń
    KontrahentShow *kontrShow = new KontrahentShow(this);
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

    kontrShow->wyswietl(tab[0].toString(),
                        tab[1].toString(),
                        tab[2].toString(),
                        tab[3].toString(),
                        tab[4].toString(),
                        tab[5].toString(),
                        tab[6].toString(),
                        tab[7].toString(),
                        tab[8].toString(),
                        tab[9].toString(),
                        tab[10].toString(),
                        tab[11].toString(),
                        tab[12].toString(),
                        tab[13].toString());

    kontrShow->show();
}
