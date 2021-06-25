#include "kontrahentinfo.h"
#include "ui_kontrahentinfo.h"
//#include "kontrahentinfododajwpis.h"
#include "DataBase/maindb.h"
#include "Timery/timedate.h"
#include "Info/info.h"
#include "Ustawienia/ustawienia.h"
#include "Ustawienia/statystyki.h"
#include "iostream"
#include "kontrahentinfododajwpis.h"
#include <ctime>
#include <fstream>
#include <QTimer>
#include <QDebug>

using namespace std;

KontrahentInfo::KontrahentInfo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KontrahentInfo)
{
    ui->setupUi(this);
    ui->labelZegara->setText(" cos tam");
    //---------Sekcja generacji timera
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myfunctiontimer()));
    timer->start(1000);
    //===================
    showTable();

    initMenuBazy();

}

KontrahentInfo::~KontrahentInfo()
{
    delete ui;
}

void KontrahentInfo::initMenuBazy()
{
    //tworze menu kontekstowe
    setWindowTitle("OptiBase v 1.0:Kontrahent - Informacje o Kontrahencie");

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
void KontrahentInfo::openInfo()
{
    Info *info = new Info(this);
    info->show();
}
void KontrahentInfo::openSettings()
{
    Ustawienia *ustaw = new Ustawienia(this);
    ustaw->show();
}



void KontrahentInfo::loadWpis()
{
    //Załaduj wpisy
    //qWarning()<<"KontrahentInfo:LoadWpisy";
    model->sort(0,Qt::AscendingOrder);
    MainDb *mainDb = new MainDb(this);
    QStandardItem *dodajItem = new QStandardItem();

    int iTabelaPustychRzedow = 0;
    int iloscWpisow = 0;
    QString pobierzWpisy;
    iloscWpisow = mainDb->loadDataRemiderId(iloscWpisow);
vector<int> tabelaPustychRzedow[iloscWpisow];
//qWarning()<< "Pobrałerm ilosc wpisów: "<< iloscWpisow;
    for (int i = 1; i <= iloscWpisow; i++) {
        for (int d = 0; d <= 8; d++) {

            QString numerSeryjnydoPorownania = ui->lblNrSeryjny_2->text();
            pobierzWpisy = mainDb->loadDataRemider(pobierzWpisy, i, d, numerSeryjnydoPorownania);

            if (pobierzWpisy =="Numeros4534")
            {
                d=8;
                    tabelaPustychRzedow->push_back(i);
                iTabelaPustychRzedow++;
                dodajItem= new QStandardItem("");
                model->setItem(i-1, d, dodajItem);
            }
            else
            {
                dodajItem = new QStandardItem(pobierzWpisy);
                //if(ui->lblNrSeryjny_2==)
               // qWarning()<<"Dodoaje linie w tablewiew: "<<i;
                model->setItem(i - 1, d, dodajItem);
            }
        }
    }
    int rowDoSize = model->rowCount();
    for (int i = 0; i <= rowDoSize; i++) {
        ui->tableView->setRowHeight(i, 20);
    }
    ui->tableView->horizontalHeader()->setSectionResizeMode(
        QHeaderView::ResizeToContents); // Rozszerza kolumny do najdłuzszego itema w kolumnie.
    ui->tableView->sortByColumn(0,
                                  Qt::SortOrder(
                                      0)); // Pierwsza cyfea mowi od jakiej kolumny sortujemy



    //++++++++++++++++++++++++++++++++++++++
   // int iTabelaPustychRzedow = 0;
//    qWarning() << "Wchodze w petle do ukrycia rzedow ";
//    qWarning() << "rowDoSize to : " << rowDoSize;
//    qWarning() << "iTabelaPustychRzedow to : " << iTabelaPustychRzedow;
    //+++++++++++
    for (int i = rowDoSize; i >= (rowDoSize ) - (iTabelaPustychRzedow);i--) {
        //qWarning() << "Pusty rzad to : "<<i;

        ui->tableView->hideRow(i);
    }
}

void KontrahentInfo::on_pushButton_clicked()
{
    destroy();
}
void KontrahentInfo::showTable()
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
                                      2)); // Pierwsza cyfea mowi od jakiej kolumny sortujemy





    //++++++++++++++++++++++++++++++++++++++++
}

void KontrahentInfo::myfunctiontimer()
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

    wczytajDane();
}
void KontrahentInfo::wczytajDane() {}

void KontrahentInfo::wyswietl(QVariant p1,
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
                              QVariant p14,
                              QVariant p15,
                              QVariant p16,
                              QVariant p17,
                              QVariant p18,
                              QVariant p19,
                              QVariant p20)
{
    //cout << "Jestem w kontrahent Info Wyswietl" << endl;
    QVariant przypisanyZp5 = p5; // info o przypisaniu analizatora do kontr.
    //cout << QVariant::toString( p8.toString())<< endl;
    ui->lblUrzad_2->setText(p1.toString());
    ui->lblProduc_2->setText(p2.toString());
    ui->lblModel_2->setText(p3.toString());
    ui->lblNrSeryjny_2->setText(p4.toString());
    ui->lblNrKontrahent_2->setText(p7.toString());//było p6
    ui->lblNazwa_2->setText(p6.toString());//było p7
    ui->lblImie_2->setText(p9.toString());
    ui->lblNazwisko_2->setText(p10.toString());
    ui->lblKraj_2->setText(p11.toString());
    ui->lblRegion_2->setText(p12.toString());
    ui->lblMiasto_2->setText(p13.toString());
    ui->lblZipCode_2->setText(p14.toString());
    ui->lblUlica_2->setText(p15.toString());
    ui->lblNrDomu_2->setText(p16.toString());
    ui->lblTelefon_2->setText(p17.toString());
    ui->lblTelDodat_2->setText(p18.toString());
    ui->lblEmail_2->setText(p19.toString());
    ui->lblUrl_2->setText(p20.toString());
    pobierzDane();
    loadWpis();
}
void KontrahentInfo::pobierzDane()
{
//    QString file18 = "C:/Defaults/Pliki/18.WpisKontrahentInfo.txt";
//    fstream wpisDoBazy;

//    wpisDoBazy.open(file18.toStdString(), ios::in);
//    if (wpisDoBazy.good() == false) {
//        cout << "Plik nie istnieje !!!!!";
//        //exit(0);
//    }
//    string linia;
//    QString IdUrz, IdKont, IdUrzKont;
//    IdUrz = ui->lblUrzad_2->text();
//    IdKont = ui->lblNrKontrahent_2->text();
//    IdUrzKont = ("{IdUrzadzenia# " + IdUrz + IdKont + "}");
//    int nr_lini = 1;
//    while (getline(wpisDoBazy, linia)) {

//        if (linia.c_str() == IdUrzKont) {
//            cout << "JESTTTTT" << endl;

//        }
//        nr_lini++;
//    }

//    wpisDoBazy.close();
}

void KontrahentInfo::on_pushButton_2_clicked()
{
    // Dodaj Wpis
    KontrahentInfoDodajWpis *kontrDodajWpis = new KontrahentInfoDodajWpis(this);
    kontrDodajWpis->setSettingsId(ui->lblNrSeryjny_2->text());

    kontrDodajWpis->show();
}

void KontrahentInfo::on_pushButton_3_clicked()
{
    // Odswiez
    //qDebug ()<<"Odsiwezam i wchodze w load Wpis";
    //ui->tableView->cle
    model->clear();
    showTable();
    loadWpis();

}
