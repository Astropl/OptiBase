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
#include <baza.h>
//#include <druga.h>
//#include <trzecia.h>
#include <Kontrahent/kontrahent.h>
#include <Urzadzenia/urzadzenia.h>
#include <direct.h>
#include <fstream>
#include <iostream>
#include <QApplication>
#include <QMainWindow>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CheckIsFileExist();
    InitDB();
}

MainWindow::~MainWindow()
{
    delete ui;
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
    destroy();
}



void MainWindow::on_pushButton_2_clicked() {}
void MainWindow::on_pushButton_3_clicked() {}
void MainWindow::on_actionO_programie_triggered(){}

void MainWindow::on_actionOpcje_triggered(){}



