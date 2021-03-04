#include "urzadzeniaprzypominacz.h"
#include "DataBase/maindb.h"
#include "Timery/timedate.h"
#include "Ustawienia/ustawienia.h"
#include "ui_urzadzeniaprzypominacz.h"
#include <iostream>
#include <QDebug>
#include <QString>
#include <QTimer>

using namespace std;

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

void UrzadzeniaPrzypominacz::wczytajDane()
{
    MainDb *mainDb = new MainDb(this);
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

    for (int i = 1; i <= pobierzWazneDatyId; i++) {
        for (int d = 0; d <= 3; d++) {
            QSpobierzWazneDaty = mainDb->pobierzWazneDaty(QSpobierzWazneDaty, i, d);
            dodajItem2 = new QStandardItem(QSpobierzWazneDaty);
            // if (dodajIt)
            model2->setItem(i - 1, d, dodajItem2);
        }
    }

    pobierzNormalneDatyId = mainDb->loadDataRemiderId(pobierzNormalneDatyId);

    for (int i = 1; i <= pobierzNormalneDatyId; i++) {
        for (int d = 0; d <= 8; d++) {
            QSpobierzDaty = mainDb->loadDataRemiderAll(QSpobierzDaty, i, d);
            dodajItem1 = new QStandardItem(QSpobierzDaty);
            if (dodajItem1->text() == "BRAK")

            {
                d=8;
                ui->tbPrzypominacz->hideRow(i);

                        //dataBrak = model1->item(i, 1)->text();
                      // qWarning() << "Item do porwniania: " << dataBrak;
                qWarning ()<<"nic nie robie";
                //if (dataBrak.compare("BRAK")) {
                    //           ui->tbPrzypominacz->hideRow(i);
                    //ui->tbPrzypominacz->hideRow(i);
            } else {
                if (d == 0) {
                    model1->setItem(i - 1, 0, dodajItem1);
                } else if (d == 1) {
                    model1->setItem(i - 1, 4, dodajItem1);
                } else if (d == 2) {
                    model1->setItem(i - 1, 5, dodajItem1);
                } else if (d == 3) {
                    model1->setItem(i - 1, 6, dodajItem1);
                } else if (d == 4) {
                    model1->setItem(i - 1, 7, dodajItem1);
                } else if (d == 5) {
                    model1->setItem(i - 1, 8, dodajItem1);
                } else if (d == 6) {
                    model1->setItem(i - 1, 1, dodajItem1);
                } else if (d == 7) {
                    model1->setItem(i - 1, 2, dodajItem1);
                } else if (d == 8) {
                    model1->setItem(i - 1, 3, dodajItem1);
                }
            }
        }
    }


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
