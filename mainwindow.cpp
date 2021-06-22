#include "mainwindow.h"
#include "DataBase/checkfiles.h"
//#include "Files/checkfiles1.h"
#include "Kontrahent/kontrahentlista.h"
#include "Urzadzenia/urzadzenialista.h"
#include "Urzadzenia/urzadzeniaprzypominacz.h"
#include "Ustawienia/ustawienia.h"
//#include "DataBase/dbmain.h"
#include "DataBase/maindb.h"
#include "DataBase/wpisy.h"
#include "Timery/dates.h"
#include "Timery/timedate.h"
#include "Ustawienia/statystyki.h"
#include "DataBase/magazyn.h"
#include "ui_mainwindow.h"
//#include "Resources/DBIcon.jpg"
#include <Info/info.h>
#include <baza.h>
#include <QToolBar>
//#include <druga.h>
//#include <trzecia.h>
#include <Kontrahent/kontrahent.h>
#include <Urzadzenia/urzadzenia.h>
#include <direct.h>
#include <fstream>
#include <iostream>
#include <windows.h>
#include <QAction>
#include <QApplication>
#include <QMainWindow>
#include <QTime>
#include <QTimer>

#include <QDir>
#include <QToolButton>

#include <QtWidgets>
//#include <QPrinter>
#include <QFileDialog>

int dzienRoku = 0;

using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //---------Sekcja generacji timera
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myfunctiontimer()));
    timer->start(1000);
    //===================
    //ui->QMainWindow-> (setWindowTitle("OptiBase v.1"));

    initWindow();

    CheckIsFileExist();
    InitDB();
    InitToolbar();
    statsy();
    ui->scrollArea_3->setFixedSize(0, 0);
    initCalendarScroll();



}

MainWindow::~MainWindow()
{
    delete ui;
}



//
void MainWindow::initCalendarScroll()
{
    int   pobierzWazneDatyId = 0;
    QString QSpobierzWazneDaty = "";
    MainDb *mainDb = new MainDb(this);
    pobierzWazneDatyId = mainDb->pobierzWazneDatyiD(pobierzWazneDatyId);
    for (int i = 1; i <= pobierzWazneDatyId; i++) {
        for (int d = 0; d <= 3; d++) {
            QSpobierzWazneDaty = mainDb->pobierzWazneDaty(QSpobierzWazneDaty, i, d);

            ui->comboBox_2->addItem(QSpobierzWazneDaty);

            //TODO: Dodoac do kalendarza w main pierwszą wazną datę

        }
    }
}
//

void MainWindow::myfunctiontimer()
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
void MainWindow::initWindow()
{
    setWindowTitle("OptiBase v 1.0");

    QAction *fileSave = new QAction(("&Zapisz"), this);
    QAction *fileEksport = new QAction(("&Eksport"), this);
    // QAction *fileseparator = new QAction(("----------"), this);
    QAction *fileWyjscie = new QAction(("&Wyjście"), this);

    QAction *editKopiuj = new QAction(("&Kopiuj"), this);
    QAction *editWklej = new QAction(("&Wklej"), this);
    QAction *editToolbar = new QAction(("Toolbar"), this);

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
    mainEdycja->addAction(editToolbar);

    mainInfo->addAction(infoOProgramie);
    mainInfo->addAction(infoOAutorze);
    mainInfo->addAction(infoLog);

    mainSettings->addAction(settingsOption);

    //connect(settingsOption, &QAction::triggered,this, SLOT (openInfo()));
    connect(settingsOption, SIGNAL(triggered()), this, SLOT(on_actionOpcje_triggered()));
    connect(infoOProgramie, SIGNAL(triggered()), this, SLOT(on_actionO_programie_triggered()));

    ui->comboBox_2->setVisible(false);
}
void MainWindow::InitToolbar()
{
    QString dirPath = "C:/Users/pawel/Documents/Cplusplus/OptiBase/OptiBase/Resources";

    QIcon dbIcon, dbIcon1;
    QToolBar *toolBar = addToolBar(tr("Pasek"));
    toolBar->setOrientation(Qt::Horizontal);
    toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    //    dbIcon.addPixmap(QPixmap(dirPath + "/DBIcon.png"), QIcon::Normal);
    //    dbIcon1.addPixmap(QPixmap(dirPath + "/Remider.png"), QIcon::Normal);
    //    qDebug() << QDir::current();
    //    qDebug() << QDir::currentPath();

    QToolButton *buttonBaza = new QToolButton();
    QToolButton *buttonRemider = new QToolButton();
    QToolButton *buttonWpis = new QToolButton();

    //toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    buttonBaza->setIcon(QIcon(dirPath + "/DBIcon.png"));
    buttonBaza->setText("Bazownk");
    buttonRemider->setIcon(QIcon(dirPath + "/Remider.png"));
    buttonRemider->setText("Przypominacz");
    buttonWpis->setIcon(QIcon(dirPath + "/Wpisy.png"));
    buttonWpis->setText("Wpisy");
    //buttonBaza->setT

    //    QAction *a1Action = addWidget(buttonBaza);
    //    QAction *a1Action = addWidget(buttonBaza);
    //addAction(buttonBaza);

    QAction *a1 = new QAction;
    a1->setIcon(QIcon(dirPath + "/DBIcon.png"));
    a1->setText("Baza");
    toolBar->addAction(a1);
    toolBar->addSeparator();

    QAction *a2 = new QAction;
    a2->setIcon(QIcon(dirPath + "/Remider.png"));
    a2->setText("Przypominacz");
    toolBar->addAction(a2);
    toolBar->addSeparator();

    QAction *a3 = new QAction;
    a3->setIcon(QIcon(dirPath + "/Wpisy.png"));
    a3->setText("Wpisy");
    toolBar->addAction(a3);
    toolBar->addSeparator();

    //    toolBar->addWidget(buttonBaza);
    //    toolBar->addSeparator();
    //    toolBar->addWidget(buttonRemider);
    //    toolBar->addSeparator();
    //    toolBar->addWidget(buttonWpis);
    //    toolBar->addSeparator();

    //    connect(buttonBaza, SIGNAL(clicked()), this, SLOT(clickButtonBaza()));
    //    connect(buttonRemider, SIGNAL(clicked()), this, SLOT(clickButtonRemider()));
    //    connect(buttonWpis, SIGNAL(clicked()), this, SLOT(clickButtonWpis()));

    connect(a1, SIGNAL(triggered ()), this, SLOT(clickButtonBaza()));
    connect(a2, SIGNAL(triggered()), this, SLOT(clickButtonRemider()));
    connect(a3, SIGNAL(triggered()), this, SLOT(clickButtonWpis()));
}

void MainWindow::statsy()
{
    Statystyki *stats = new Statystyki(this);
    stats->liczbaUruchomienFirst();
}
void MainWindow::openInfo()
{
    Info *info = new Info(this);
    info->show();
}
void MainWindow::openSettings()
{
    Ustawienia *ustaw = new Ustawienia(this);
    ustaw->show();
}

void MainWindow::CheckIsFileExist()
{
    CheckFiles *checkFiles = new CheckFiles(this);
    checkFiles->init();
}
void MainWindow::InitDB()
{
    MainDb *mainDb = new MainDb(this);
    mainDb->init();
}
void MainWindow::on_pushButton_clicked()
{
    //Baza
    Baza *baza = new Baza(this);
    baza->show();
}

void MainWindow::on_pushButton_7_clicked()
{
    //Lista Kontrahentow
    KontrahentLista *kontrList = new KontrahentLista(this);
    kontrList->show();
}

void MainWindow::on_pushButton_8_clicked()
{
    //Lista Urzadzen
    UrzadzeniaLista *urzList = new UrzadzeniaLista(this);
    urzList->show();
}

void MainWindow::on_pushButton_5_clicked()
{
    //Dodaj Kontrahenta
    Kontrahent *kontrahent = new Kontrahent(this);
    kontrahent->show();
}

void MainWindow::on_pushButton_6_clicked()
{
    //dodaj uradzenie
    Urzadzenia *urzadzenia = new Urzadzenia(this);
    urzadzenia->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    //Zamnkij
    destroy(1);
}

void MainWindow::on_pushButton_2_clicked()
{
    //qDebug ()<<"Wchodze do Wpisów";

    Wpisy *wpisy = new Wpisy(this);
    wpisy->show();
}
void MainWindow::on_pushButton_3_clicked()
{
    //TODO: Zrobic
}
void MainWindow::on_actionO_programie_triggered()
{ //qDebug()<<"on_actionO_programie_triggered";
    Info *info = new Info(this);
    info->show();
}

void MainWindow::on_actionOpcje_triggered()
{ //qDebug()<<"on_actionOpcje_triggered";
    Ustawienia *ustaw = new Ustawienia(this);
    ustaw->show();
}

void MainWindow::on_pushButton_9_clicked()
{
    QString zapytanie = "";
    MainDb *mainDb = new MainDb(this);
    zapytanie = mainDb->ZapytanieTestowe(zapytanie);
    //cout << "Zapytanie w main glownym odpowiedz: " + zapytanie.toStdString() << endl;
    ui->comboBox->addItem(zapytanie);
    mainDb->PrzypiszTestowo();
}

void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    qWarning() << "clicked in calndar";

    //qWarning()<<ui->calendar
}

void MainWindow::on_pushButton_10_clicked()
{
    if (ui->pushButton_10->text() == "V") {
        Dzienroku();
        ZnakZodiaku();
        ShowImportantDate();
        ui->pushButton_10->setText("/\\");
        for (int x = 0; x <= 211; x++) {
            ui->scrollArea_3->setFixedSize(211, x);
            QTime dieTime = QTime::currentTime().addMSecs(2);
            while (QTime::currentTime() < dieTime)
                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        }

    }

    else {
        ui->pushButton_10->setText("V");
        for (int y = 211; y >= 0; y--) {
            ui->scrollArea_3->setFixedSize(211, y);
            QTime dieTime = QTime::currentTime().addMSecs(2);
            while (QTime::currentTime() < dieTime)
                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        }
    }
}
void MainWindow::ShowImportantDate()
{
    QDate DataToday=QDate::currentDate();
    QDate QDatazComba;
    QString SDatazComba;


    int ileDni, ileDni2;
    int tymczasowaIleDni=365;
    int tymczasoweK;
    QString stringDoDaty="";
    int module;
    QString doSetText;
    QString doSetText1;
    // dodoaj do kalnedarza w main wazną datę


    int iloscWcomboBox = ui->comboBox_2->count();
    int tablicaIntow[iloscWcomboBox];
    qWarning()<<" Ilosc w ComboBox: "<<iloscWcomboBox;

    for (int k=iloscWcomboBox-1;k>=0;k--)
    {
        //modulo 0
        module = k%4;
        qWarning ()<<"Itrm: "<<ui->comboBox_2->itemText(k);
        qWarning()<<" modulo: "<<module;

//        if (module ==0)
//        {
//            ui->comboBox_2->removeItem(k);
//        }
        if (module ==1)
        {
            qWarning()<<" Data to: "<<ui->comboBox_2->itemText(k);
            //TODO:: Tutuaj obliczamy date.....

            SDatazComba = ui->comboBox_2->itemText(k);
            QDatazComba = QDate::fromString(SDatazComba,"yyyy/MM/dd");
            qWarning ()<<"Data z komopa: i z tabeli"<<DataToday<<" "<<QDatazComba;

            //            if (QDatazComba<DataToday)
            //            {
            //                ui->comboBox_2->removeItem(k);
            //                ui->comboBox_2->removeItem(k+1);
            //            }

            ileDni = DataToday.daysTo(QDatazComba);
            qWarning ()<<"Ile dni do"<<ileDni;

            if (tymczasowaIleDni>ileDni)
            {
                tymczasowaIleDni = ileDni;
                tablicaIntow[k]= ileDni;
                qDebug()<<sizeof(tablicaIntow);
                qWarning ()<<"Najmniejsza ilosc dni to"<<tymczasowaIleDni;
                tymczasoweK = k;
                qWarning ()<<"Najmniejsza ilosc dni to"<<ui->comboBox_2->itemText(k);
                stringDoDaty = ui->comboBox_2->itemText(k+2);
            }
            doSetText = "Za " + QString::number(tymczasowaIleDni);
            doSetText1 = doSetText + " dni: ";


            ui->label_9->setText(doSetText1 + stringDoDaty);
ui->textBrowser->setText(doSetText1 + stringDoDaty);
//ui->textBrowser->setEnabled(false);
//ui->textBrowser->setFo
        }
    }
    ui->comboBox_2->update();
    // Sprawdzam tablice intów
int rozmiarTablicy = sizeof(tablicaIntow);
qDebug()<<"rozmiar tablicy to: "<<rozmiarTablicy;
    for (int r=0;r<=rozmiarTablicy-1 ;r++)
    {
        qDebug()<<" nr" << r << " to: "<< tablicaIntow[r] ;
    }
}
void MainWindow::Dzienroku()
{
    Dates *dates = new Dates(this);
    dzienRoku = dates->DzienRoku(dzienRoku);
    ui->label_5->setText(QString::number(dzienRoku));
}
void MainWindow::ZnakZodiaku()
{
    //Label-7 -> nak zodiaku

    QString znakzodiaku = "";
    Dates *dates = new Dates(this);
    qWarning() << " Lece do Dates";
    znakzodiaku = dates->znakZodiaku(znakzodiaku);
    //if
    qWarning() << " Po przyjsciu daje nam : " << znakzodiaku;
    ui->label_7->setText(znakzodiaku);
}
void MainWindow::on_pushButton_11_clicked()
{
    //Przypominacz

    UrzadzeniaPrzypominacz *urzPrzy = new UrzadzeniaPrzypominacz(this);
    urzPrzy->show();
}

void MainWindow::clickButtonBaza()
{
    qDebug() << "Ikonka baza z toolbara";
    on_pushButton_clicked();
}
void MainWindow::clickButtonRemider()
{
    qDebug() << "Ikonka Remider z toolbara";
    on_pushButton_11_clicked();
}
void MainWindow::clickButtonWpis()
{
    qDebug() << "Ikonka Wpisy z toolbara";
    on_pushButton_2_clicked();
}
// do gita


void MainWindow::on_btnMagazyn_clicked()// magazyn

{
    Magazyn *magazyn = new Magazyn(this);
    magazyn->show();
}
