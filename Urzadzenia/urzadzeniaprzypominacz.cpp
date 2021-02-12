#include "urzadzeniaprzypominacz.h"
#include "ui_urzadzeniaprzypominacz.h"
#include "DataBase/maindb.h"
#include <QDebug>
#include <QString>
#include <QTimer>
#include <iostream>
#include "Timery/timedate.h"
#include "Ustawienia/ustawienia.h"


using namespace std;


UrzadzeniaPrzypominacz::UrzadzeniaPrzypominacz(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UrzadzeniaPrzypominacz)
{
    ui->setupUi(this);
    //---------Sekcja generacji timera
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myfunctiontimer()));
    timer->start(1000);
   //===================


}

UrzadzeniaPrzypominacz::~UrzadzeniaPrzypominacz()
{
    delete ui;
}

void UrzadzeniaPrzypominacz::on_pushButton_clicked()
{
    timer->stop();

    destroy();
}

void UrzadzeniaPrzypominacz::myfunctiontimer()
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
