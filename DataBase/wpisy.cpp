#include "wpisy.h"
#include "DataBase/maindb.h"
#include "Timery/timedate.h"
#include "Ustawienia/statystyki.h"
#include "Ustawienia/ustawienia.h"
#include "time.h"
#include "ui_wpisy.h"
#include <Info/info.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <QDebug>
#include <QString>
#include <QTableView>
#include <QTimer>

using namespace std;

Wpisy::Wpisy(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Wpisy)
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
{ //Zamknij
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
                                Qt::SortOrder(1)); // Pierwsza cyfea mowi od jakiej kolumny sortujemy

    loadWpis();

    //++++++++++++++++++++++++++++++++++++++++
}

void Wpisy::loadWpis()
{
    ui->comboBox->setVisible(false);
    ui->comboBox_2->setVisible(false);
    ui->comboBox_3->setVisible(false);

    model->sort(0, Qt::DescendingOrder);
    MainDb *mainDb = new MainDb(this);
    QStandardItem *dodajItem = new QStandardItem();

    int iloscWpisow = 0;
    QString pobierzWpisy;

    iloscWpisow = mainDb->loadDataRemiderId(iloscWpisow);
    //qDebug()<<" Ilosc wpisów: "<<iloscWpisow;
    for (int i = 1; i <= iloscWpisow; i++) {
        for (int d = 0; d <= 8; d++) {
            pobierzWpisy = mainDb->loadDataRemiderAll(pobierzWpisy, i, d);
            //qDebug()<<"Dodoaje item wiersz: "<< i <<" , d: "<<d<<" o nazwie: "<<pobierzWpisy;
            dodajItem = new QStandardItem(pobierzWpisy);
            model->setItem(i - 1, d, dodajItem);
        }
    }
    int rowDoSize = model->rowCount();
    for (int i = 0; i <= rowDoSize; i++) {
        ui->tableView->setRowHeight(i, 20);
    }
    ui->tableView->horizontalHeader()->setSectionResizeMode(
        QHeaderView::ResizeToContents); // Rozszerza kolumny do najdłuzszego itema w kolumnie.
    ui->tableView->sortByColumn(2,
                                Qt::SortOrder(1)); // Pierwsza cyfea mowi od jakiej kolumny sortujemy
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
    Statystyki *stats = new Statystyki(this);
    stats->liczbaUruchomienFirst();
}
void Wpisy::on_checkBox_stateChanged()
{
    if (ui->checkBox->isChecked()) {
        //Klikniety

        ui->comboBox->setVisible(true);
        ui->comboBox_2->setVisible(true);
        ui->comboBox_3->setVisible(true);
        fillComboBoxes();

    } else {
        //nie klikniety
        ui->comboBox->setVisible(false);
        ui->comboBox_2->setVisible(false);
        ui->comboBox_3->setVisible(false);
        ui->comboBox->clear();
        ui->comboBox_2->clear();
        ui->comboBox_3->clear();

        filtrOn("Brak");
    }
}
void Wpisy::fillComboBoxes()
{
    ui->comboBox->addItem("Brak");
    ui->comboBox_2->addItem("Brak");
    ui->comboBox_3->addItem("Brak");

    vector<QString> vfillCb0;
    vector<QString> vfillCb2;
    vector<QString> vfillCb3;

    for (int i = 0; i <= model->rowCount() - 1; i++) {
        QStandardItem *item0 = model->item(i, 3); //temat
        QStandardItem *item2 = model->item(i, 2); //data wpsiu
        QStandardItem *item3 = model->item(i, 8); // numer seryjny

        vfillCb0.push_back(item0->text());
        vfillCb2.push_back(item2->text());
        vfillCb3.push_back(item3->text());
    }

    sort(vfillCb0.begin(), vfillCb0.end());
    vfillCb0.erase(unique(vfillCb0.begin(), vfillCb0.end()), vfillCb0.end());
    sort(vfillCb2.begin(), vfillCb2.end());
    vfillCb2.erase(unique(vfillCb2.begin(), vfillCb2.end()), vfillCb2.end());
    sort(vfillCb3.begin(), vfillCb3.end());
    vfillCb3.erase(unique(vfillCb3.begin(), vfillCb3.end()), vfillCb3.end());

    for (int k = 0; k < vfillCb0.size(); ++k) {
        ui->comboBox->addItem(vfillCb0[k]);
    }
    for (int k = 0; k < vfillCb2.size(); ++k) {
        ui->comboBox_2->addItem(vfillCb2[k]);
    }
    for (int k = 0; k < vfillCb3.size(); ++k) {
        ui->comboBox_3->addItem(vfillCb3[k]);
    }
}
void Wpisy::on_comboBox_activated(const QString) {
    QString aktywnyFiltr = ui->comboBox->currentText();
    filtrOn(aktywnyFiltr);
}

void Wpisy::on_comboBox_3_activated(const QString) {
    QString aktywnyFiltr = ui->comboBox_3->currentText();
    filtrOn(aktywnyFiltr);
}

void Wpisy::on_comboBox_2_activated(const QString) {
    QString aktywnyFiltr = ui->comboBox_2->currentText();
    filtrOn(aktywnyFiltr);
}

QString Wpisy::filtrOn(QString aktywnyFiltr)
{
    for (int k = 0; k <= model->rowCount() - 1; k++) {
        //Ukrywam rzedy

        ui->tableView->hideRow(k);
    }

    // "Jestem w filtrze";
    qDebug ()<< "aktywny filtr to: "<< aktywnyFiltr;
    QString filter = aktywnyFiltr;
    for (int i = 0; i <= model->rowCount() - 1; i++) {
        for (int j = 0; j <= model->columnCount() - 1; j++) {
            QStandardItem *item = model->item(i, j);
            if (filter == "Brak") {
                ui->tableView->showRow(i);
            } else {
                if (item->text().contains(filter)) {
                    ui->tableView->showRow(i);
                }
            }
        }
    }

    return 0;
}