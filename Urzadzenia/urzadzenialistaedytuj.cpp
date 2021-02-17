#include "urzadzenialistaedytuj.h"
#include "ui_urzadzenialistaedytuj.h"
#include "DataBase/maindb.h"
#include "Timery/timedate.h"
#include "Ustawienia/ustawienia.h"
#include "time.h"
#include <Info/info.h>
#include <iostream>
#include <QDebug>
#include <QString>
#include <QTimer>


using namespace std;

int pobierzProducentaIdEdytuj = 0;
QString QStringPobierzProducentaEdytuj = "";
int pobierzModelIdEdytuj = 0;
QString QStringPobierzModelEdytuj = "";

UrzadzeniaListaEdytuj::UrzadzeniaListaEdytuj(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UrzadzeniaListaEdytuj)
{
    ui->setupUi(this);

    //---------Sekcja generacji timera
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myfunctiontimer()));
    timer->start(1000);
    //===================

    ui->lineEditLp2->setText("L.P.");
    ui->lineEditProd2->setText("Producent");
    ui->lineEditModel2->setText("Model");
    ui->lineEditNrsery2->setText("Numer Seryjny");
    ui->lineEditPrzypis2->setText("Przypisany");
    ui->lineEditKontrh2->setText("Kontrahent");
    setLabelsFalse();
    wypelnijProducenta();
    wypelnijModel();


}

UrzadzeniaListaEdytuj::~UrzadzeniaListaEdytuj()
{
    delete ui;
}

void UrzadzeniaListaEdytuj::on_pushButton_clicked()
{
    destroy();

}

void UrzadzeniaListaEdytuj::myfunctiontimer()
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



void UrzadzeniaListaEdytuj::on_pushButton_3_clicked()//Edytyju
{
    setLabelsTrue();


}


void UrzadzeniaListaEdytuj::setLabelsTrue()
{

    //ui->lineEditLp2->setEnabled(true);
    ui->lineEditProd2->setEnabled(true);
    ui->lineEditModel2->setEnabled(true);
    ui->lineEditNrsery2->setEnabled(true);
    ui->comboBox->setEnabled(true);
    ui->comboBox_2->setEnabled(true);
    //ui->lineEditPrzypis2->setEnabled(true);
   // ui->lineEditKontrh2->setEnabled(true);
}
void UrzadzeniaListaEdytuj::setLabelsFalse()
{

 ui->lineEditLp2->setEnabled(false);
 ui->lineEditProd2->setEnabled(false);
 ui->lineEditModel2->setEnabled(false);
 ui->lineEditNrsery2->setEnabled(false);
 ui->lineEditPrzypis2->setEnabled(false);
 ui->lineEditKontrh2->setEnabled(false);
 ui->comboBox->setEnabled(false);
 ui->comboBox_2->setEnabled(false);
}
QVariant UrzadzeniaListaEdytuj::setLabelsInfo(QVariant lp, QVariant producent, QVariant model, QVariant nrSeryjny, QVariant przypisany, QVariant kontrahent)
{
    ui->lineEditLp2->setText(lp.toString());
    ui->lineEditProd2->setText(producent.toString());
    ui->lineEditModel2->setText(model.toString());
    ui->lineEditNrsery2->setText(nrSeryjny.toString());
    ui->lineEditPrzypis2->setText(przypisany.toString());
    ui->lineEditKontrh2->setText(kontrahent.toString());

    ui->lblNrsery2->setText(nrSeryjny.toString());
    if (przypisany !="TAK")
    {
         ui->lineEditPrzypis2->setText("Brak Kontrahenta");
    }

    qWarning()<<"producent to: "<<producent;
    qWarning()<<"model to: "<<model;
    ui->comboBox->setCurrentText(producent.toString());
    ui->comboBox_2->setCurrentText(model.toString());
    return 0;
}

void UrzadzeniaListaEdytuj::wypelnijProducenta()
{
    MainDb *mainDb = new MainDb(this);
    pobierzProducentaIdEdytuj = mainDb->pobierzProducentaiD(pobierzProducentaIdEdytuj);
    for (int i = 1; i <= pobierzProducentaIdEdytuj; i++) {
        QStringPobierzProducentaEdytuj = mainDb->pobierzProducenta(QStringPobierzProducentaEdytuj, i);
        ui->comboBox->addItem(QStringPobierzProducentaEdytuj);
    }
}
void UrzadzeniaListaEdytuj::wypelnijModel()
{
    MainDb *mainDb = new MainDb(this);
    pobierzModelIdEdytuj = mainDb->pobierzModeliD(pobierzModelIdEdytuj);
    for (int i = 1; i <= pobierzModelIdEdytuj; i++) {
        QStringPobierzModelEdytuj = mainDb->pobierzModel(QStringPobierzModelEdytuj, i);
        ui->comboBox_2->addItem(QStringPobierzModelEdytuj);
    }
}
void UrzadzeniaListaEdytuj::on_pushButton_4_clicked()
{
    MainDb *mainDb = new MainDb(this);


    //Wczytac z MainDb urzadenia z którym zgadza się numer seryjny

    //zapisac do MainDB . .najlepiej poprzez Update zgodnie z numerem seryjnym
    QString producent;
    QString model;
    QString numerSeryjny;
    QString numerSeryjnyOryginal;

    //producent=ui->lineEditProd2->text();
    producent=ui->comboBox->currentText();
    //model=ui->lineEditModel2->text();
    model=ui->comboBox_2->currentText();
    numerSeryjny=ui->lineEditNrsery2->text();
    numerSeryjnyOryginal=ui->lblNrsery2->text();

    mainDb->addUrzadzeniaUpdate(producent,model,numerSeryjny,numerSeryjnyOryginal);
    qWarning()<<"Update urzadzen udany";
}
