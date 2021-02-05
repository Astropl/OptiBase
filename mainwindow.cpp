#include "mainwindow.h"
#include "DataBase/checkfiles.h"
//#include "Files/checkfiles1.h"
#include "Kontrahent/kontrahentlista.h"
#include "Urzadzenia/urzadzenialista.h"
#include "Ustawienia/ustawienia.h"
//#include "DataBase/dbmain.h"
#include "DataBase/maindb.h"
#include "ui_mainwindow.h"
#include <Info/info.h>
#include "DataBase/wpisy.h"
#include "Ustawienia/statystyki.h"
#include "Timery/timedate.h"
#include <baza.h>
//#include <druga.h>
//#include <trzecia.h>
#include <Kontrahent/kontrahent.h>
#include <Urzadzenia/urzadzenia.h>
#include <direct.h>
#include <fstream>
#include <iostream>
#include <QAction>
#include <QApplication>
#include <QMainWindow>
#include <QTimer>
#include <windows.h>
#include <QTime>


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
    statsy();
    ui->scrollArea_3->setFixedSize(1,1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

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
void MainWindow::statsy()
{
    Statystyki *stats = new Statystyki (this);
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
{//qDebug()<<"on_actionO_programie_triggered";
    Info *info = new Info(this);
    info->show();
}

void MainWindow::on_actionOpcje_triggered()
{//qDebug()<<"on_actionOpcje_triggered";
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
    qWarning()<<"clicked in calndar";

    //qWarning()<<ui->calendar
}

void MainWindow::on_pushButton_10_clicked()
{
    //ScrollArea
    ui->pushButton_10->setText("A");
    for (int x =1;x<=211;x++)
    {
        ui->scrollArea_3->setFixedSize(211,x);
        //QObject().thread()->usleep(1000*1000*1)
       // sleep(1000);
        //_sleep(1);
        QTime dieTime= QTime::currentTime().addMSecs(20) ;       //addSecs(1);
        while (QTime::currentTime() < dieTime)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}
