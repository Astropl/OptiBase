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
#include "Ustawienia/statystyki.h"
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

using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->QMainWindow-> (setWindowTitle("OptiBase v.1"));

    initWindow();

    CheckIsFileExist();
    InitDB();
    statsy();
}

MainWindow::~MainWindow()
{
    delete ui;
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
{ //TODO: Zrobic
}
void MainWindow::on_pushButton_3_clicked()
{ //TODO: Zrobic
}
void MainWindow::on_actionO_programie_triggered()
{
    Info *info = new Info(this);
    info->show();
}

void MainWindow::on_actionOpcje_triggered()
{
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
