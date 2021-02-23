#include "urzadzeniaprzypominacz.h"
#include "ui_urzadzeniaprzypominacz.h"
#include "DataBase/maindb.h"
#include <QDebug>
#include <QString>
#include <QTimer>
#include <iostream>
#include "Timery/timedate.h"
#include "Ustawienia/ustawienia.h"


using namespace std;


UrzadzeniaPrzypominacz::UrzadzeniaPrzypominacz(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UrzadzeniaPrzypominacz)
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
    model1 = new QStandardItemModel(0, 4, this);
    model2 = new QStandardItemModel(0, 4, this);
    ui->tbPrzypominacz->setModel(model1);
    //QModelIndex *index;
    ui->tbWazneDaty->setModel(model2);
    //tbPrzypominacz tbWazneDaty

    model1->setHeaderData(0, Qt::Horizontal, "L.P.");
    model1->setHeaderData(1, Qt::Horizontal, "Data");
    model1->setHeaderData(2, Qt::Horizontal, "Temat");
    model1->setHeaderData(3, Qt::Horizontal, "Tekst");

    model2->setHeaderData(0, Qt::Horizontal, "L.P.");
    model2->setHeaderData(1, Qt::Horizontal, "Data");
    model2->setHeaderData(2, Qt::Horizontal, "Temat");
    model2->setHeaderData(3, Qt::Horizontal, "Tekst");

    //***************
    //Wazne daty//

     QStandardItem *dodajItem1 = new QStandardItem();
    QStandardItem *dodajItem2 = new QStandardItem();

    int pobierzDatyId =0, pobierzWazneDatyId=0;

    QString QSpobierzDaty ="", QSpobierzWazneDaty="";

    pobierzWazneDatyId= mainDb->pobierzWazneDatyiD(pobierzWazneDatyId);

    for (int i=1;i<= pobierzWazneDatyId;i++)
    {
        for (int d =0;d<=3;d++)
        {
            QSpobierzWazneDaty = mainDb->pobierzWazneDaty(QSpobierzWazneDaty, i,d );
            dodajItem2 = new QStandardItem(QSpobierzWazneDaty);
            model2->setItem(i-1,d, dodajItem2);
        }
    }

    ui->tbPrzypominacz->horizontalHeader()->setSectionResizeMode(
        QHeaderView::ResizeToContents); // Rozszerza kolumny do najdłuzszego itema w kolumnie.
    ui->tbPrzypominacz->sortByColumn(1,
                                Qt::SortOrder(0)); // Pierwsza cyfea mowi od jakiej kolumny sortujemy
    ui->tbWazneDaty->horizontalHeader()->setSectionResizeMode(
        QHeaderView::ResizeToContents); // Rozszerza kolumny do najdłuzszego itema w kolumnie.
    ui->tbWazneDaty->sortByColumn(1,
                                     Qt::SortOrder(0)); // Pierwsza cyfea mowi od jakiej kolumny sortujemy
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
// do gita