#include "statystyki.h"
#include "DataBase/maindb.h"
#include "Timery/timedate.h"
#include "ui_statystyki.h"

#include <QDebug>
#include <QTime>
#include <QTimer>

int iloscUruhomienRun;
Statystyki::Statystyki(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Statystyki)
{
    ui->setupUi(this);

    //---------Sekcja generacji timera
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myfunctiontimer()));
    timer->start(1000);
    //===================
    liczbaUruchomien();
    czasUruchomien();
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

    //Testy do obliczania ile czasu upłyneło uruchomionegoe programu

    int DbSec = 0, DbMin = 0, DbGodz = 0, DbDni = 0;
    QString QDbSec, QDbMin, QDbGodz, QDbDni;
    MainDb *maindb = new MainDb(this);
    //Pobrać ilosc juz upynietego czasu z DB

    DbSec = maindb->PobierzCzasUruchomienDbSec(DbSec);
    DbMin = maindb->PobierzCzasUruchomienDbMin(DbMin);
    DbGodz = maindb->PobierzCzasUruchomienDbGodz(DbGodz);
    DbDni = maindb->PobierzCzasUruchomienDbDni(DbDni);

//    qWarning() << "Ilosc sekund to " << DbSec;
//    qWarning() << "Ilosc minut to " << DbMin;
//    qWarning() << "Ilosc godzin to " << DbGodz;
//    qWarning() << "Ilosc dni to " << DbDni;




    // Obliczenia dodoawania czasu

    DbSec ++;
    if (DbSec>59)
    {
        DbSec =0;
        DbMin ++;
    }
    if (DbMin>59)
    {

        DbMin = 0;
        DbGodz ++;
    }


    QDbSec = timeDate->changeStringsSek(DbSec);
    QDbMin = timeDate->changeStringsMin(DbMin);
    QDbGodz = timeDate->changeStringsGodz(DbGodz);
    QDbDni = timeDate->changeStringsDzien(DbDni);




//    QDbSec = QString::number(DbSec);
//    QDbMin = QString::number(DbMin);
//    QDbGodz = QString::number(DbGodz);
//    QDbDni = QString::number(DbDni);



    QString IntczasUruchomien = maindb->ObliczCzasUruchomien(QDbSec, QDbMin, QDbGodz, QDbDni);
    //QString doLabela_4 =


    ui->label_4->setText(QDbDni + ":" + QDbGodz + ":" + QDbMin + ":" + QDbSec);


}
void Statystyki::liczbaUruchomien()
{
    //Zapytanie do bazy o ilosc juz zapisanych uruchomien.
    MainDb *maindb = new MainDb(this);
    iloscUruhomienRun = maindb->iloscUruchomienFirst(iloscUruhomienRun);
    //qWarning() << "Powrociło ilosc uruchomen: " << iloscUruhomienRun;
    // iloscUruhomienRun++;
    QString QiloscUruhomienRun = QString::number(iloscUruhomienRun);
    //qWarning() << "Powrociło ilosc Quruchomen: " << QiloscUruhomienRun;
    ui->label_2->setText(QiloscUruhomienRun);

    //dodanie do liczby zapisanych ++
}
void Statystyki::liczbaUruchomienFirst()
{
    //Zapytanie do bazy o ilosc juz zapisanych uruchomien.
    MainDb *maindb = new MainDb(this);
    iloscUruhomienRun = maindb->iloscUruchomienFirst(iloscUruhomienRun);
    //qWarning ()<<"First Powrociło ilosc uruchomen: " << iloscUruhomienRun ;
    iloscUruhomienRun++;
    QString QiloscUruhomienRun = QString::number(iloscUruhomienRun);
    // qWarning ()<<"First Powrociło ilosc Quruchomen: " << QiloscUruhomienRun ;
    ui->label_2->setText(QiloscUruhomienRun);
    maindb->iloscUruchomienSave(iloscUruhomienRun);
    //dodanie do liczby zapisanych ++
}
void Statystyki::on_pushButton_clicked()
{
    //Exit
    destroy();
}
void Statystyki::czasUruchomien() {}
