#include "urzadzeniadodajmodel.h"
#include "ui_urzadzeniadodajmodel.h"
#include "DataBase/maindb.h"
#include <fstream>
#include <iostream>
#include <QFile>
#include <QMessageBox>
#include <QDebug>

using namespace std;

fstream plikOdczyt;

UrzadzeniaDodajModel::UrzadzeniaDodajModel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UrzadzeniaDodajModel)
{
    ui->setupUi(this);
    setWindowTitle("Urządzenia::Dodaj Model");

    ui->comboBoxDodajModel->setVisible(false);

    int modelId=0;
    QString QStringPobierzModel;
    MainDb *mainDb = new MainDb (this);
    modelId = mainDb->pobierzModeliD(modelId);

    for (int i = 1; i <= modelId; i++) {
        QStringPobierzModel = mainDb->pobierzModel(QStringPobierzModel, i);
        ui->comboBoxDodajModel->addItem(QStringPobierzModel);
        qDebug() << QStringPobierzModel;
    }
    // Ikonka check OK /NO
    QString dirPath = "C:/Users/pawel/Documents/Cplusplus/OptiBase/OptiBase/Resources";
    QPixmap pix1(dirPath+ "/YesRed.png");

    ui->lblCheckOkNo->setPixmap(pix1.scaled(ui->lblCheckOkNo->size(),Qt::KeepAspectRatio));// Skaluje pnp do wymierów labela
    // end Ikonka Check Ok/NO
    //**********************************************
}

UrzadzeniaDodajModel::~UrzadzeniaDodajModel()
{
    delete ui;
}

void UrzadzeniaDodajModel::on_pushButton_clicked()
{
    //// DOdaj model/

    //sprawdzam czy label dodawania modelu jest pusty - zrobione
    // Sprawdzić czy elent jest juz na liscie.
    if (ui->lineEditDodajModel->text() != "") {
        cout << "Dodaje model analizatora" << endl;
        QString dodajModel = ui->lineEditDodajModel->text();

        ui->comboBoxDodajModel->addItem(dodajModel);
        ui->lineEditDodajModel->setText("");
    } else {
        //wyswietl info ze pusty label
        QMessageBox::information(this, "Ostrzeżenie", "Nie możesz wprowdzić pustego modelu.");
    }
    QString dirPath = "C:/Users/pawel/Documents/Cplusplus/OptiBase/OptiBase/Resources";
    QPixmap pix1(dirPath+ "/YesYellow.png");

    ui->lblCheckOkNo->setPixmap(pix1.scaled(ui->lblCheckOkNo->size(),Qt::KeepAspectRatio));//Skaluje pnp do wymierów labela
}

void UrzadzeniaDodajModel::on_pushButton_2_clicked()
{ ////Zamknij i zapisz

    QString daneModel="";
    MainDb *mainDb = new MainDb (this);
    int iloscElementowWcombo;
    iloscElementowWcombo = ui->comboBoxDodajModel->count();

    for (int i = 0; i <= iloscElementowWcombo - 1; i++) {
        //        //  petla wczytująca liste z combo
        daneModel = ui->comboBoxDodajModel->itemText(i);

        mainDb -> addModel (daneModel);
    }

    // Ikonka check OK /NO
    QString dirPath = "C:/Users/pawel/Documents/Cplusplus/OptiBase/OptiBase/Resources";
    QPixmap pix1(dirPath+ "/CheckOk.png");

    ui->lblCheckOkNo->setPixmap(pix1.scaled(ui->lblCheckOkNo->size(),Qt::KeepAspectRatio));// Skaluje pnp do wymierów labela
    // end Ikonka Check Ok/NO
    //**********************************************
    destroy();
}
