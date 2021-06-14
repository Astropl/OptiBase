#include "carts.h"
#include "ui_carts.h"
#include <DataBase/maindb.h>
#include <QDebug>
#include <QTableView>

Carts::Carts(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Carts)
{
    ui->setupUi(this);
    init();
}

Carts::~Carts()
{
    delete ui;
}

void Carts::on_btnExit_clicked()
{
    destroy();

}

void Carts::init()
{mainDB *mainDb = new mainDB(this);
    //mainDb->show();
    qWarning ()<< "Jesem w init Kart Pacjebta";

    model = new QStandardItemModel(1, 79, this);
    ui->tableView->setModel(model);
    //qWarning ()<<"2";

    model->setHeaderData(0, Qt::Horizontal, "Data");
    model->setHeaderData(1, Qt::Horizontal, "Godzina");
    model->setHeaderData(2, Qt::Horizontal, "Numer LP");
    model->setHeaderData(3, Qt::Horizontal, "Nazwa Pacjenta");
    model->setHeaderData(4, Qt::Horizontal, "wzrost");
    model->setHeaderData(5, Qt::Horizontal, "wiek");
    model->setHeaderData(6, Qt::Horizontal, "wiek");
    model->setHeaderData(7, Qt::Horizontal, "wiek");
    model->setHeaderData(8, Qt::Horizontal, "wiek");
    model->setHeaderData(9, Qt::Horizontal, "wiek");
    model->setHeaderData(10, Qt::Horizontal, "wiek");
    model->setHeaderData(11, Qt::Horizontal, "wiek");
    model->setHeaderData(12, Qt::Horizontal, "wiek");
    model->setHeaderData(13, Qt::Horizontal, "wiek");

    model->setHeaderData(14, Qt::Horizontal, "wiek");
    model->setHeaderData(15, Qt::Horizontal, "wiek");


    model->setHeaderData(16, Qt::Horizontal, "wiek");
    model->setHeaderData(17, Qt::Horizontal, "wiek");


    // pobierz nazwy plików

QStandardItem *dodajItem = new QStandardItem();
    int pobierzIloscPlikow =0;
    QString pobierzNazwePliku ="";

    pobierzIloscPlikow = mainDb->pobierzIloscPlikow(pobierzIloscPlikow);

    qDebug()<<" carts: ilosc plikow: "<<pobierzIloscPlikow;


    // pobierz dane z plików
for (int i =1; i<=pobierzIloscPlikow; i++)
{
    for (int d=0; d<=78 ;d++ )
    {
//        pobierzNazwePliku=mainDb->pobierzDaneZPliku(pobierzNazwePliku,i,d);
//        dodajItem = new QStandardItem


    }
}


}
void Carts::on_pushButton_clicked()
{
    // Pobierz dane
    mainDB *mainDb = new mainDB(this);
    mainDb->show();



}
