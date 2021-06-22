#include "magazyn.h"
#include "ui_magazyn.h"
#include "DataBase/maindb.h"
#include "Timery/timedate.h"
#include "Info/info.h"
#include "Ustawienia/statystyki.h"
#include "Ustawienia/ustawienia.h"
#include <QTableView>
#include <QTimer>
#include <ctime>
#include <QDebug>

using namespace std;
//rowDoSize1 = 0;
//iTabelaPustychRzedow1 = 0;



Magazyn::Magazyn(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Magazyn)
{
    ui->setupUi(this);
    //---------Sekcja generacji timera
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myfunctiontimer()));
    timer->start(1000);
    //===================
    initMenu();
    wczytajDane();
}

Magazyn::~Magazyn()
{
    delete ui;
}

void Magazyn::on_btnExit_clicked() // Exit
{
    destroy();
}
void Magazyn::initMenu()
{
setWindowTitle("OptiBase v 1.0:Magazyn - Lista Urządzeń");
//tworze menu kontekstowe
setWindowTitle("OptiBase v 1.0:Kontrahent - Lista Kontrahentów");

//    QAction *fileSave = new QAction(("&Zapisz"), this);
//    QAction *fileEksport = new QAction(("&Eksport"), this);
// QAction *fileseparator = new QAction(("----------"), this);
QAction *fileWyjscie = new QAction(("&Wyjście"), this);

//    QAction *edycjaDodajProducenta = new QAction(("Dodaj Producenta"), this);
//    QAction *edycjaDodajModel = new QAction(("Dodaj Model"), this);

//    QAction *editKopiuj = new QAction(("&Kopiuj"), this);
//    QAction *editWklej = new QAction(("&Wklej"), this);

QAction *infoOProgramie = new QAction(("&O Programie"), this);
QAction *infoOAutorze = new QAction(("O &Autorze"), this);
QAction *infoLog = new QAction(("&Log"), this);

QAction *settingsOption = new QAction(("&Opcje"), this);

auto mainfile = menuBar()->addMenu("Plik");
//auto mainEdycja = menuBar()->addMenu("Edycja");
auto mainInfo = menuBar()->addMenu("Informacje");
auto mainSettings = menuBar()->addMenu("Ustawienia");

//    mainfile->addAction(fileSave);
//    mainfile->addAction(fileEksport);

mainfile->addSeparator();
mainfile->addAction(fileWyjscie);

//    mainEdycja->addAction(edycjaDodajProducenta);
//    mainEdycja->addAction(edycjaDodajModel);

//    mainEdycja->addAction(editKopiuj);
//    mainEdycja->addAction(editWklej);
mainInfo->addAction(infoOProgramie);
mainInfo->addAction(infoOAutorze);
mainInfo->addAction(infoLog);

mainSettings->addAction(settingsOption);

//connect(settingsOption, &QAction::triggered,this, SLOT (openInfo()));
connect(settingsOption, SIGNAL(triggered()), this, SLOT(openSettings()));
connect(infoOProgramie, SIGNAL(triggered()), this, SLOT(openInfo()));
//    connect(edycjaDodajProducenta,
//            SIGNAL(triggered()),
//            this,
//            SLOT(on_actionDodaj_Producenta_triggered()));
//    connect(edycjaDodajModel, SIGNAL(triggered()), this, SLOT(on_actionDodaj_Model_triggered()));



}

void Magazyn::statsy()
{
    Statystyki *stats = new Statystyki(this);
    stats->liczbaUruchomienFirst();
}
void Magazyn::openInfo()
{
    Info *info = new Info(this);
    info->show();
}
void Magazyn::openSettings()
{
    Ustawienia *ustaw = new Ustawienia(this);
    ustaw->show();
}
void Magazyn::wczytajDane()
{
    ui->comboBox->setVisible(false);
    ui->comboBox_2->setVisible(false);
    ui->checkBox->setChecked(false);
    ui->comboBox_3->setVisible(false);
    ui->label->setVisible(false);
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);

    // Wczytac z Bazy. Kontrahneci i Urzadzenia które mają zakładkę TAK
    QStandardItem *dodajItem = new QStandardItem("");
    MainDb *mainDb = new MainDb(this);
    int pobierzUrzKontId = 0;

    QString QStringPobierzUrzKont = "";
    model = new QStandardItemModel(1, 21, this); //było 14
    ui->tableView->setModel(model);

    model->setHeaderData(0, Qt::Horizontal, "L.P.");
    model->setHeaderData(1, Qt::Horizontal, "Producent");           //nazwa
    model->setHeaderData(2, Qt::Horizontal, "Model");               // Imie
    model->setHeaderData(3, Qt::Horizontal, "Nr Seryjny");          // Imie
    model->setHeaderData(4, Qt::Horizontal, "Przypisany ?");        // Imie
    model->setHeaderData(5, Qt::Horizontal, "Kontrahent Nazwa");    // Imie
    model->setHeaderData(6, Qt::Horizontal, "LP Kontrahenta");      //Nazwisko
    model->setHeaderData(7, Qt::Horizontal, "Nazwa");               //Kraj
    model->setHeaderData(8, Qt::Horizontal, "Imie");                //Region
    model->setHeaderData(9, Qt::Horizontal, "Nazwisko");            //Miasto
    model->setHeaderData(10, Qt::Horizontal, "Kraj");               //Kod Pocztowy
    model->setHeaderData(11, Qt::Horizontal, "Region");             //Ulica
    model->setHeaderData(12, Qt::Horizontal, "Miasto");             //Nr domu/mieszkania
    model->setHeaderData(13, Qt::Horizontal, "Kod Pocztowy");       //Telefon
    model->setHeaderData(14, Qt::Horizontal, "Ulica");              //Telefon prywatny
    model->setHeaderData(15, Qt::Horizontal, "Nr domu/mieszkania"); //Adres E-mail
    model->setHeaderData(16, Qt::Horizontal, "Telefon");            //Strona URL
    model->setHeaderData(17, Qt::Horizontal, "Telefon prywatny");   //Telefon prywatny
    model->setHeaderData(18, Qt::Horizontal, "Adres E-mail");       //Adres E-mail
    model->setHeaderData(19, Qt::Horizontal, "Strona URL");         //Strona URL
    model->setHeaderData(20, Qt::Horizontal, "Numer Seryjny z Przypisania");

    QString pobierzNumerSeryjny = "";
    //Lece do MainDB->pobierz Id






}
void Magazyn::myfunctiontimer()
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
void Magazyn::on_checkBox_stateChanged()
{
    int rowDoSize1 =0, iTabelaPustychRzedow1 =0;
    int pusteRzedy1 = (rowDoSize1) - (iTabelaPustychRzedow1);

    pusteRzedy1 = ui->lblPusteRzedy->text().toInt();
    if (
            ui->checkBox->isChecked()) {
        qWarning() << "cKliknietey";
        ui->comboBox->setVisible(true);
        ui->comboBox_2->setVisible(true);
        ui->comboBox_3->setVisible(true);
        ui->label->setVisible(true);
        ui->label_2->setVisible(true);
        ui->label_3->setVisible(true);


        fillComboBoxes();
    } else {
        // "NIE Klikniety";
        ui->comboBox->setVisible(false);
        ui->comboBox_2->setVisible(false);
        ui->comboBox_3->setVisible(false);
        ui->label->setVisible(false);
        ui->label_2->setVisible(false);
        ui->label_3->setVisible(false);
       // ui->lineEditSzukaj->setVisible(false);
        ui->comboBox->clear();
        ui->comboBox_2->clear();
        ui->comboBox_3->clear();

        for (int i = 0; i <= model->rowCount() - 1 - pusteRzedy1; i++) {
            //Wejscie do odkrycia rzedów numer : " << i;
            ui->tableView->showRow(i);
        }
    }
}
void Magazyn::fillComboBoxes()

{


}
