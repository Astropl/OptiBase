#include "kontrahentinfo.h"
#include "ui_kontrahentinfo.h"
//#include "kontrahentinfododajwpis.h"
#include "Timery/timedate.h"
#include "iostream"
#include <ctime>
#include <QTimer>
#include <fstream>

using namespace std;


KontrahentInfo::KontrahentInfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::KontrahentInfo)
{
    ui->setupUi(this);
    ui->labelZegara->setText(" cos tam");
    //---------Sekcja generacji timera
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myfunctiontimer()));
    timer->start(1000);
    //===================
    showTable();
    loadWpis();

}

KontrahentInfo::~KontrahentInfo()
{
    delete ui;
}
void KontrahentInfo::loadWpis()
{
    //Załaduj wpisy




}

void KontrahentInfo::on_pushButton_clicked()
{
    destroy();
}
void KontrahentInfo::showTable()
{
    model = new QStandardItemModel(1, 5, this); //było 14
    ui->tableView->setModel(model);
    //QModelIndex *index;
    model->setHeaderData(0, Qt::Horizontal, "L.P.");
    model->setHeaderData(1, Qt::Horizontal, "Data Wpisu");    //nazwa
    model->setHeaderData(2, Qt::Horizontal, "Temat");        // Imie
    model->setHeaderData(3, Qt::Horizontal, "Treść");   // Imie
    model->setHeaderData(4, Qt::Horizontal, "Przypomnienie"); // Imie

    //TODO: Zrobic wpisywanie i wczytywanie z DBWpisu
    // otworzyc fstream
    // wczytac linie
    // jesli lnia bedzie sie rówanała labelowi z IdUrz i IdKont to wczytac dalej + 11 linii

}



void KontrahentInfo::myfunctiontimer()
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

    wczytajDane();

}
void KontrahentInfo::wczytajDane()
{

}


void KontrahentInfo::wyswietl(QVariant p1,
                              QVariant p2,
                              QVariant p3,
                              QVariant p4,
                              QVariant p5,
                              QVariant p6,
                              QVariant p7,
                              QVariant p8,
                              QVariant p9,
                              QVariant p10,
                              QVariant p11,
                              QVariant p12,
                              QVariant p13,
                              QVariant p14,
                              QVariant p15,
                              QVariant p16,
                              QVariant p17,
                              QVariant p18,
                              QVariant p19)
{
    //cout << "Jestem w kontrahent Info Wyswietl" << endl;
    QVariant przypisanyZp5 = p5; // info o przypisaniu analizatora do kontr.
    ui->lblUrzad_2->setText(p1.toString());
    ui->lblProduc_2->setText(p2.toString());
    ui->lblModel_2->setText(p3.toString());
    ui->lblNrSeryjny_2->setText(p4.toString());
    ui->lblNrKontrahent_2->setText(p6.toString());
    ui->lblNazwa_2->setText(p7.toString());
    ui->lblImie_2->setText(p8.toString());
    ui->lblNazwisko_2->setText(p9.toString());
    ui->lblKraj_2->setText(p10.toString());
    ui->lblRegion_2->setText(p11.toString());
    ui->lblMiasto_2->setText(p12.toString());
    ui->lblZipCode_2->setText(p13.toString());
    ui->lblUlica_2->setText(p14.toString());
    ui->lblNrDomu_2->setText(p15.toString());
    ui->lblTelefon_2->setText(p16.toString());
    ui->lblTelDodat_2->setText(p17.toString());
    ui->lblEmail_2->setText(p18.toString());
    ui->lblUrl_2->setText(p19.toString());
    pobierzDane();


}
void KontrahentInfo::pobierzDane()
{
    QString file18 = "C:/Defaults/Pliki/18.WpisKontrahentInfo.txt";
    fstream wpisDoBazy;

    wpisDoBazy.open(file18.toStdString(),ios::in);
    if (wpisDoBazy.good() == false) {
        cout << "Plik nie istnieje !!!!!";
        //exit(0);
    }
    string linia;
    QString IdUrz, IdKont, IdUrzKont;
    IdUrz=ui->lblUrzad_2->text();
    IdKont = ui->lblNrKontrahent_2->text();
    IdUrzKont = ("{IdUrzadzenia# "+IdUrz+IdKont+"}");
    int nr_lini = 1;
    while (getline(wpisDoBazy, linia)) {
        //ui->comboBoxDodajMiasto->addItem(linia.c_str());
        //cout << linia.c_str() << endl;
        if (linia.c_str()==IdUrzKont)
        {
            cout<<"JESTTTTT"<<endl;
            //Dodoac do tabeli
        }
        nr_lini++;
    }

    wpisDoBazy.close();
}

void KontrahentInfo::on_pushButton_2_clicked()
{
    // Dodaj Wpis
//    KontrahentInfoDodajWpis *kontrDodajWpis = new KontrahentInfoDodajWpis (this);
//    kontrDodajWpis->setSettingsId(ui->lblUrzad_2->text(),ui->lblNrKontrahent_2->text());

//    kontrDodajWpis ->show();
}

void KontrahentInfo::on_pushButton_3_clicked()
{
    // Zapis
}
