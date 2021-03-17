#include "urzadzeniaprzypominacz.h"
#include "DataBase/maindb.h"
#include "Timery/timedate.h"
#include "Ustawienia/ustawienia.h"
#include "ui_urzadzeniaprzypominacz.h"
#include <iostream>
#include <string>
#include <QDebug>
#include <QString>
#include <QTimer>
#include <QDate>

using namespace std;
int hidenNormalDate =0;
int showenNormalDate =0;
QDate dataAll=QDate::currentDate();

UrzadzeniaPrzypominacz::UrzadzeniaPrzypominacz(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UrzadzeniaPrzypominacz)
{
    ui->setupUi(this);
    //---------Sekcja generacji timera
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myfunctiontimer()));
    timer->start(1000);
    //===================
    initMenu();
    wczytajDane();
}

UrzadzeniaPrzypominacz::~UrzadzeniaPrzypominacz()
{
    delete ui;
}

void UrzadzeniaPrzypominacz::on_pushButton_clicked()
{
    timer->stop();

    destroy();
}

void UrzadzeniaPrzypominacz::initMenu()
{
    setWindowTitle("OptiBase v 1.0:Przypomnienia dat");
}

void UrzadzeniaPrzypominacz::changeCheckBoxaFalse()
{
    ui->checkBox->setChecked(false);
    ui->radioButton->setVisible(false);
    ui->radioButton_2->setVisible(false);
    ui->radioButton_3->setVisible(false);
    ui->radioButton->setChecked(true);
    ui->radioButton_2->setChecked(false);
    ui->radioButton_3->setChecked(false);
    //checkBox

}
void UrzadzeniaPrzypominacz::changeCheckBoxaTrue()
{
    ui->checkBox->setChecked(true);
    ui->radioButton->setVisible(true);
    ui->radioButton_2->setVisible(true);
    ui->radioButton_3->setVisible(true);
    ui->radioButton->setChecked(true);
    ui->radioButton_2->setChecked(false);
    ui->radioButton_3->setChecked(false);
    //checkBox

}

void UrzadzeniaPrzypominacz::wczytajDane()
{hidenNormalDate=0;
    showenNormalDate =0;
    MainDb *mainDb = new MainDb(this);
    changeCheckBoxaFalse();
    model1 = new QStandardItemModel(0, 8, this);
    model2 = new QStandardItemModel(0, 4, this);
    ui->tbPrzypominacz->setModel(model1);

    ui->tbWazneDaty->setModel(model2);

    model2->setHeaderData(0, Qt::Horizontal, "L.P.");
    model2->setHeaderData(1, Qt::Horizontal, "Data");
    model2->setHeaderData(2, Qt::Horizontal, "Temat");
    model2->setHeaderData(3, Qt::Horizontal, "Tekst");

    QStandardItem *dodajItem1 = new QStandardItem();
    QStandardItem *dodajItem2 = new QStandardItem();

    int pobierzNormalneDatyId = 0, pobierzWazneDatyId = 0;
    QString dataBrak;
    QString QSpobierzDaty = "", QSpobierzWazneDaty = "";

    pobierzWazneDatyId = mainDb->pobierzWazneDatyiD(pobierzWazneDatyId);

    for (int i = 0; i <= pobierzWazneDatyId; i++) {
        for (int d = 0; d <= 3; d++) {
            QSpobierzWazneDaty = mainDb->pobierzWazneDaty(QSpobierzWazneDaty, i, d);
            dodajItem2 = new QStandardItem(QSpobierzWazneDaty);
            // if (dodajIt)
            model2->setItem(i, d, dodajItem2);// model2->setItem(i - 1, d, dodajItem2);
        }
    }

    pobierzNormalneDatyId = mainDb->loadDataRemiderId(pobierzNormalneDatyId);

    for (int i = 1; i <= pobierzNormalneDatyId; i++) {
        for (int d = 0; d <= 8; d++) {
            QSpobierzDaty = mainDb->loadDataRemiderAll(QSpobierzDaty, i, d);
            dodajItem1 = new QStandardItem(QSpobierzDaty);
            if (dodajItem1->text() == "BRAK")

            {
                d=9;
                hidenNormalDate++;
                qWarning() << "Ukrywam rzad: " << i-1;
                ui->tbPrzypominacz->hideRow(i-1); //i+1

                //dataBrak = model1->item(i, 1)->text();
                // qWarning() << "Item do porwniania: " << dataBrak;
                //qWarning ()<<"Ukrywam rzad: "<<i<<"Bo item :"<<dodajItem1->text();
                //if (dataBrak.compare("BRAK")) {
                //           ui->tbPrzypominacz->hideRow(i);
                //ui->tbPrzypominacz->hideRow(i);
                continue;
            } else {
                if (d == 0) {
                    model1->setItem(i-1, 0, dodajItem1);
                } else if (d == 1) {
                    model1->setItem(i-1, 4, dodajItem1);
                } else if (d == 2) {
                    model1->setItem(i-1 , 5, dodajItem1);
                } else if (d == 3) {
                    model1->setItem(i-1 , 6, dodajItem1);
                } else if (d == 4) {
                    model1->setItem(i-1 , 7, dodajItem1);
                } else if (d == 5) {
                    model1->setItem(i-1 , 8, dodajItem1);
                } else if (d == 6) {
                    model1->setItem(i-1 , 1, dodajItem1);
                } else if (d == 7) {
                    model1->setItem(i-1 , 2, dodajItem1);
                } else if (d == 8) {
                    model1->setItem(i-1 , 3, dodajItem1);
                }
                qWarning ()<<"Dodoaje item do rzedu: " <<i-1<<" "<<dodajItem1->text() ;
            }
        }
    }

    //******************8
    // ui->tbPrzypominacz->hideRow(1);
    //*******************88
    ui->tbPrzypominacz->horizontalHeader()->setSectionResizeMode(
                QHeaderView::ResizeToContents); // Rozszerza kolumny do najdłuzszego itema w kolumnie.
    ui->tbPrzypominacz->sortByColumn(
                0,
                Qt::SortOrder(0)); // Pierwsza cyfea mowi od jakiej kolumny sortujemy // od Lp
    ui->tbWazneDaty->horizontalHeader()->setSectionResizeMode(
                QHeaderView::ResizeToContents); // Rozszerza kolumny do najdłuzszego itema w kolumnie.
    ui->tbWazneDaty->sortByColumn(1,
                                  Qt::SortOrder(0)); // Pierwsza cyfea mowi od jakiej kolumny sortujemy

    model1->setHeaderData(0, Qt::Horizontal, "L.P.");
    model1->setHeaderData(1, Qt::Horizontal, "Data Przypomnienia");      //Nr Wpisu
    model1->setHeaderData(6, Qt::Horizontal, "Temat");                   //Data
    model1->setHeaderData(7, Qt::Horizontal, "Tekst");                   //Temat
    model1->setHeaderData(8, Qt::Horizontal, "Przypomnienie");           //Tekst
    model1->setHeaderData(4, Qt::Horizontal, "Data ");                   //Przypomnienie
    model1->setHeaderData(5, Qt::Horizontal, "Nr Wpisu");                //Data Przypomnienia
    model1->setHeaderData(2, Qt::Horizontal, "Tekst przypomnienia");     //Tekst przypomnienia
    model1->setHeaderData(3, Qt::Horizontal, "Numer seyjny urządzenia"); //Numer seyjny urządzenia

    ui->tbWazneDaty->setShowGrid(true);
    ui->tbPrzypominacz->setShowGrid(true);

    //Schowanie słowa brak w dacie.
    //for (int i = 1; i <= pobierzWazneDatyId; i++) {
    //    for (int d = 0; d <= 3; d++) {
    //        //            QSpobierzWazneDaty = mainDb->pobierzWazneDaty(QSpobierzWazneDaty, i, d);
    //        //            dodajItem2 = new QStandardItem(QSpobierzWazneDaty);

    //        //            model2->setItem(i - 1, d, dodajItem2);

    //        QString dataBrak;
    //        dataBrak = model1->item(i, 1)->text();
    //        qWarning() << "Item do porwniania: " << dataBrak;
    //        if (dataBrak.compare("BRAK")) {
    //            ui->tbPrzypominacz->hideRow(i);
    //        }
    //    }
    //}

    ui->tbPrzypominacz->sortByColumn(
                1,
                Qt::SortOrder(0)); // Pierwsza cyfea mowi od jakiej kolumny sortujemy //Od daty
    ui->tbPrzypominacz->horizontalHeader()->setSectionResizeMode(
        QHeaderView::ResizeToContents); // Rozszerza kolumny do najdłuzszego itema w kolumnie.
    ui->tbWazneDaty->horizontalHeader()->setSectionResizeMode(
        QHeaderView::ResizeToContents); // Rozszerza kolumny do najdłuzszego itema w kolumnie.

ui->tbPrzypominacz->setSortingEnabled(true);
ui->tbWazneDaty->setSortingEnabled(true);

}
void UrzadzeniaPrzypominacz::myfunctiontimer()
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

void UrzadzeniaPrzypominacz::on_checkBox_stateChanged(int arg1)
{
    // zmiana checkboxa
    if (ui->checkBox->isChecked())
    {
        changeCheckBoxaTrue();
    }
    else
    {
        changeCheckBoxaFalse();
    }

}



void UrzadzeniaPrzypominacz::on_radioButton_clicked(bool checked)
{
    qWarning()<<"Clicked: Pierwszy nacisniety";
    int iloscWierszy =  model1->rowCount();
    QString datazTabeli1;
    showenNormalDate= iloscWierszy-hidenNormalDate;
    qWarning()<<"iloscWierszy"<<iloscWierszy;
    qWarning()<<"hidenNormalDatey"<<hidenNormalDate;
    qWarning()<<"showenNormalDate"<<showenNormalDate;

    for (int x=1;x<=showenNormalDate ;x++ ) {

        datazTabeli1 = model1->item(x-1,1)->text();
        qWarning()<<"item z tebali: x: "<<x-1<<" "<<datazTabeli1;
        QDate mojaData = QDate::fromString(datazTabeli1,"yyyy/MM/dd");
        qWarning ()<<"Data z komopa: i z tabeli"<<dataAll<<" "<<mojaData;


        //if(x<=10)
        // {
        qWarning()<<"Wszytskie zprzypominaną datą";
        ui->tbPrzypominacz->showRow(x-1);
        //        }else{
        //            qWarning()<<" dzisiaj jest wczesniej niz z tabelki";
        //            ui->tbPrzypominacz->hideRow(x-1);
        //        }

    }
}



void UrzadzeniaPrzypominacz::on_radioButton_2_clicked(bool checked)
{//QString qStringDateFromLabel;
    //QDate qDateDateFromLabel;
    //     qStringDateFromLabel = ui->labelDaty->text();
    //     qDateDateFromLabel = QDate::fromString(qStringDateFromLabel,"yyyy/MM/dd");
    //    qWarning()<<"Clicked: Drugi nacisniety";

    //    qWarning()<<ui->labelDaty->text();
    //     qWarning()<<QDate::fromString(qStringDateFromLabel,"yyyy/MM/dd");
    //     ui->label->setText(qStringDateFromLabel);



    qWarning()<<dataAll;
    ui->label->setText(dataAll.toString());
    QString dataTemp;
    string SDataTemp;
    dataTemp = "2021/05/12";
    SDataTemp = dataTemp.toStdString();
    int day, month, year, dayTabela, monthTabela, yearTabela;
    string sday, smonth, syear, sdayTabela, smonthTabela, syearTabela;
    sday = SDataTemp.substr(8,2);
    qWarning()<<"Dzien:" << sday.c_str();
    day=atoi( sday.c_str());

    smonth = SDataTemp.substr(5,2);
    qWarning()<<"miesiac:" << smonth.c_str();
    month=atoi( smonth.c_str());

    syear = SDataTemp.substr(0,4);
    qWarning()<<"rok:" << syear.c_str();
    year=atoi( syear.c_str());

    //ilosc wpisów w tablei
    int iloscWierszy =  model1->rowCount();
    QString datazTabeli1;
    //int tempower=0;

    qWarning()<<"Ilosc wierszy w  me=odelu 1: "<< iloscWierszy;
    qWarning()<<"ilosc ukrytych wierszu  me=odelu 1: "<< hidenNormalDate;
    showenNormalDate= iloscWierszy-hidenNormalDate;
    qWarning()<<"Ilosc wierszy odkrytych  me=odelu 1: "<< showenNormalDate;

    for (int x=1;x<=showenNormalDate ;x++ ) {

        datazTabeli1 = model1->item(x-1,1)->text();
        qWarning()<<"item z tebali: x: "<<x-1<<" "<<datazTabeli1;
        //        //QString na string
        //        syearTabela = datazTabeli1.toStdString();
        //        syearTabela = syearTabela.substr(0,4);
        //        yearTabela=atoi(syearTabela.c_str());
        //        qWarning()<<"Rok z tabeli to: "<<syearTabela.c_str();

        //        smonthTabela = datazTabeli1.toStdString();
        //       smonthTabela = smonthTabela.substr(5,2);
        //       monthTabela =atoi(smonthTabela.c_str());
        //        qWarning()<<"Rok z tabeli to: "<<smonthTabela.c_str();

        //        sdayTabela = datazTabeli1.toStdString();
        //       sdayTabela = sdayTabela.substr(8,2);
        //        dayTabela=atoi(sdayTabela.c_str());
        //       qWarning()<<"Rok z tabeli to: "<<sdayTabela.c_str();


        //QDate *mojaData = new QDate (yearTabela,monthTabela,dayTabela,"yyyy/MM/dd");
        QDate mojaData = QDate::fromString(datazTabeli1,"yyyy/MM/dd");
        qWarning ()<<"Data z komopa: i z tabeli"<<dataAll<<" "<<mojaData;


        if(mojaData>=dataAll)
        {
            qWarning()<<"data z tabelki jest pozniej niz dzisiaj";
            ui->tbPrzypominacz->showRow(x-1);
        }else{
            qWarning()<<" dzisiaj jest wczesniej niz z tabelki";
            ui->tbPrzypominacz->hideRow(x-1);
        }

    }

    ui->tbPrzypominacz->setAlternatingRowColors(true);
    //ui->tbPrzypominacz->verticalHeader()->count();
    //ui->tbPrzypominacz->verticalHeader->

    qWarning()<<"Po petli ilosc wwierszy z innej metody "<<ui->tbPrzypominacz->verticalHeader()->count();
    //Wyciganac po koleji wszytskie



    //    for(int i =0; i<=iloscWierszy;i++)
    //    {
    //        datazTabeli1=model1->item(i,1)->text();
    //        qWarning()<<"item z tebali: "<<"i: "<<i<<" "<<datazTabeli1;
    //    }
    //Zamianiec na Date te sringi

    // porównac z datą obecną

    // wyswierlic od dzisiaj do kiedys






}

void UrzadzeniaPrzypominacz::on_radioButton_3_clicked(bool checked)
{
    qWarning()<<"Clicked: Trzeci nacisniety";

    int iloscWierszy =  model1->rowCount();
    QString datazTabeli1;
    showenNormalDate= iloscWierszy-hidenNormalDate;
    qWarning()<<"iloscWierszy"<<iloscWierszy;
    qWarning()<<"hidenNormalDatey"<<hidenNormalDate;
    qWarning()<<"showenNormalDate"<<showenNormalDate;
int tymczasowaNa10=1;
    for (int x=1;x<=showenNormalDate ;x++ ) {

        datazTabeli1 = model1->item(x-1,1)->text();
        qWarning()<<"item z tebali: x: "<<x-1<<" "<<datazTabeli1;
        QDate mojaData = QDate::fromString(datazTabeli1,"yyyy/MM/dd");
        qWarning ()<<"Data z komopa: i z tabeli"<<dataAll<<" "<<mojaData;


        if(mojaData>=dataAll)

        {
            if(tymczasowaNa10<=10)
            {



                qWarning()<<"data z tabelki jest pozniej niz dzisiaj";
                ui->tbPrzypominacz->showRow(x-1);
            }else{
                qWarning()<<" dzisiaj jest wczesniej niz z tabelki";
                ui->tbPrzypominacz->hideRow(x-1);
            }
        tymczasowaNa10++;
        }
        else
        {
            ui->tbPrzypominacz->hideRow(x-1);
        }


    }

}
