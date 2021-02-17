#include "wpisy.h"
#include "ui_wpisy.h"
#include <QTableView>
#include <QDebug>
#include "Timery/timedate.h"
#include "time.h"
#include "DataBase/maindb.h"
#include <Info/info.h>
#include "Ustawienia/ustawienia.h"
#include "Ustawienia/statystyki.h"
#include <iostream>
#include <QTimer>


Wpisy::Wpisy(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Wpisy)
{
    ui->setupUi(this);
    //qDebug()<<"Jstem w Wpisy";
    //---------Sekcja generacji timera
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myfunctiontimer()));
    timer->start(1000);
    //===================


    initWindow();
    showTable();


}

Wpisy::~Wpisy()
{
    delete ui;
}

void Wpisy::myfunctiontimer()
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



void Wpisy::initWindow()
{
    setWindowTitle("OptiBase v 1.0: Wpisy");

    QAction *fileSave = new QAction(("&Zapisz"), this);
    QAction *fileEksport = new QAction(("&Eksport"), this);
    // QAction *fileseparator = new QAction(("----------"), this);
    QAction *fileWyjscie = new QAction(("&Wyjście"), this);

    QAction *editKopiuj = new QAction(("&Kopiuj"), this);
    QAction *editWklej = new QAction(("&Wklej"), this);

    QAction *infoOProgramie = new QAction(("&O Programie"), this);
    QAction *infoOAutorze = new QAction(("O &Autorze"), this);
    QAction *infoLog = new QAction(("&Log"), this);

    QAction *settingsOption = new QAction(("&Opcje"), this);

    auto mainfile = menuBar()->addMenu("Plik");
    auto mainEdycja = menuBar()->addMenu("Edycja");
    auto mainInfo = menuBar()->addMenu("Informacje");
    auto mainSettings = menuBar()->addMenu("Ustawienia");

    mainfile->addAction(fileSave);
    mainfile->addAction(fileEksport);

    mainfile->addSeparator();
    mainfile->addAction(fileWyjscie);

    mainEdycja->addAction(editKopiuj);
    mainEdycja->addAction(editWklej);
    mainInfo->addAction(infoOProgramie);
    mainInfo->addAction(infoOAutorze);
    mainInfo->addAction(infoLog);

    mainSettings->addAction(settingsOption);

    //connect(settingsOption, &QAction::triggered,this, SLOT (openInfo()));
    connect(settingsOption, SIGNAL(triggered()), this, SLOT(on_actionOpcje_triggered()));
    connect(infoOProgramie, SIGNAL(triggered()), this, SLOT(on_actionO_programie_triggered()));
}
void Wpisy::on_pushButton_clicked()
{//Zamknij
    timer->stop();

    destroy();
}
void Wpisy::showTable()
{
    model = new QStandardItemModel(1, 9, this); //było 14
    ui->tableView->setModel(model);
    //QModelIndex *index;
    model->setHeaderData(0, Qt::Horizontal, "L.P.");
    model->setHeaderData(1, Qt::Horizontal, "Numer Wpisu");              //nazwa
    model->setHeaderData(2, Qt::Horizontal, "Data wpisu");               // Imie
    model->setHeaderData(3, Qt::Horizontal, "Temat");                    // Imie
    model->setHeaderData(4, Qt::Horizontal, "Treść");                    // Imie
    model->setHeaderData(5, Qt::Horizontal, "Przypomnienie");            // Imie
    model->setHeaderData(6, Qt::Horizontal, "Data Przypomnienia");       // Imie
    model->setHeaderData(7, Qt::Horizontal, "Tekst Przypomnienia");      // Imie
    model->setHeaderData(8, Qt::Horizontal, "Numer seryjny urządzenia"); // Imie


    int rowDoSize = model->rowCount();
    for (int i = 0; i <= rowDoSize; i++) {
        ui->tableView->setRowHeight(i, 20);
    }
    ui->tableView->horizontalHeader()->setSectionResizeMode(
        QHeaderView::ResizeToContents); // Rozszerza kolumny do najdłuzszego itema w kolumnie.
    ui->tableView->sortByColumn(2,
                                Qt::SortOrder(
                                    1)); // Pierwsza cyfea mowi od jakiej kolumny sortujemy



    loadWpis();

    //++++++++++++++++++++++++++++++++++++++++
}

void Wpisy::loadWpis()
{
    model->sort(0,Qt::DescendingOrder);
    MainDb *mainDb = new MainDb(this);
    QStandardItem *dodajItem = new QStandardItem();

    int iloscWpisow = 0;
    QString pobierzWpisy;

    iloscWpisow = mainDb->loadDataRemiderId(iloscWpisow);
    //qDebug()<<" Ilosc wpisów: "<<iloscWpisow;
    for(int i =1; i<=iloscWpisow;i++)
    {
        for( int d=0;d<=8;d++)
        {
            pobierzWpisy= mainDb->loadDataRemiderAll(pobierzWpisy, i,d);
            //qDebug()<<"Dodoaje item wiersz: "<< i <<" , d: "<<d<<" o nazwie: "<<pobierzWpisy;
            dodajItem = new QStandardItem(pobierzWpisy);
            model->setItem(i-1,d,dodajItem);




        }
    }
    int rowDoSize = model->rowCount();
    for (int i = 0; i <= rowDoSize; i++) {
        ui->tableView->setRowHeight(i, 20);
    }
    ui->tableView->horizontalHeader()->setSectionResizeMode(
        QHeaderView::ResizeToContents); // Rozszerza kolumny do najdłuzszego itema w kolumnie.
    ui->tableView->sortByColumn(2,
                                Qt::SortOrder(
                                    1)); // Pierwsza cyfea mowi od jakiej kolumny sortujemy

}

void Wpisy::openInfo()
{
    Info *info = new Info(this);
    info->show();
}
void Wpisy::openSettings()
{
    Ustawienia *ustaw = new Ustawienia(this);
    ustaw->show();
}
void Wpisy::statsy()
{
    Statystyki *stats = new Statystyki (this);
    stats->liczbaUruchomienFirst();
}