#include "mainwindow.h"
#include "DataBase/checkfiles.h"
#include "DataBase/maindb.h"
#include "ui_mainwindow.h"
#include "baza.h"

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
    Baza *baza=new Baza(this);
    baza->show();

}

void MainWindow::on_pushButton_7_clicked()
{
    //Lista Kontrahentow
}

void MainWindow::on_pushButton_8_clicked()
{
    //Lista Urzadzen
}

void MainWindow::on_pushButton_5_clicked()
{
    //Dodaj Kontrahenta
}

void MainWindow::on_pushButton_6_clicked()
{
    //dodaj uradzenie
}

void MainWindow::on_pushButton_4_clicked()
{
    //Zamnkij
    destroy();
}
