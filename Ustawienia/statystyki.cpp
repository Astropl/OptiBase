#include "statystyki.h"
#include "ui_statystyki.h"
#include"Timery/timedate.h"
#include "DataBase/maindb.h"

#include "QTimer"
#include <QDebug>


int iloscUruhomienRun;
Statystyki::Statystyki(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Statystyki)
{
    ui->setupUi(this);

    //---------Sekcja generacji timera
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myfunctiontimer()));
    timer->start(1000);
    //===================
    liczbaUruchomien();
}

Statystyki::~Statystyki()
{
    delete ui;
}
void Statystyki::myfunctiontimer()
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
void Statystyki::liczbaUruchomien ()
{
    //Zapytanie do bazy o ilosc juz zapisanych uruchomien.
    MainDb *maindb = new MainDb (this);
     iloscUruhomienRun = maindb->iloscUruchomienFirst(iloscUruhomienRun);
     qWarning ()<<"Powrociło ilosc uruchomen: " << iloscUruhomienRun ;
    // iloscUruhomienRun++;
     QString QiloscUruhomienRun = QString::number(iloscUruhomienRun);
     qWarning ()<<"Powrociło ilosc Quruchomen: " << QiloscUruhomienRun ;
     ui->label_2 ->setText(QiloscUruhomienRun);

    //dodanie do liczby zapisanych ++
}
void Statystyki::liczbaUruchomienFirst ()
{
    //Zapytanie do bazy o ilosc juz zapisanych uruchomien.
    MainDb *maindb = new MainDb (this);
    iloscUruhomienRun = maindb->iloscUruchomienFirst(iloscUruhomienRun);
    qWarning ()<<"First Powrociło ilosc uruchomen: " << iloscUruhomienRun ;
    iloscUruhomienRun++;
    QString QiloscUruhomienRun = QString::number(iloscUruhomienRun);
    qWarning ()<<"First Powrociło ilosc Quruchomen: " << QiloscUruhomienRun ;
    ui->label_2 ->setText(QiloscUruhomienRun);
    maindb->iloscUruchomienSave(iloscUruhomienRun);
    //dodanie do liczby zapisanych ++
}
void Statystyki::on_pushButton_clicked()
{
    //Exit

}
