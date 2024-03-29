#include "urzadzenialistakontrahent.h"
#include "Timery/timedate.h"
#include "ui_urzadzenialistakontrahent.h"
#include "Info/info.h"
#include "DataBase/maindb.h"
#include <fstream>
#include <iostream>
#include <QTableView>
#include <QTimer>
#include <QtWidgets>

using namespace std;

fstream fileDB, plikUrzadzeniaKontrahentLista, fileUrzadzenia;
QString dirPath = "C:/Users/pawel/Documents/Cplusplus/OptiBase/OptiBase/Resources";
UrzadzeniaListaKontrahent::UrzadzeniaListaKontrahent(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UrzadzeniaListaKontrahent)
{
    ui->setupUi(this);

    //---------Sekcja generacji timera
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myfunctiontimer()));
    timer->start(1000);
    //===================
    QString file1 = "C:/Defaults/Pliki/1.DB.txt";
    QString file2 = "C:/Defaults/Pliki/2.Kontrahent.txt";
    QString file3 = "C:/Defaults/Pliki/3.Urzadzenie.txt";
    QString file4 = "C:/Defaults/Pliki/4.ZapisKraj.txt";
    QString file5 = "C:/Defaults/Pliki/5.ZapisMiasta.txt";
    QString file6 = "C:/Defaults/Pliki/6.ZapisWojewodztwa.txt";
    QString file7 = "C:/Defaults/Pliki/7.ZapisProducenta.txt";
    QString file8 = "C:/Defaults/Pliki/8.ZapisModel.txt";
    QString file9 = "C:/Defaults/Pliki/9.ZapisNrSeryjny.txt";
    QString file10 = "C:/Defaults/Pliki/10.CheckFlagsInMiasto.txt";
    QString file11 = "C:/Defaults/Pliki/11.CheckFlagsInKraj.txt";
    QString file12 = "C:/Defaults/Pliki/12.CheckFlagsInWojewodztwa.txt";
    QString file13 = "C:/Defaults/Pliki/13.CheckFlagsInKrajKontrahentShow.txt";
    QString file14 = "C:/Defaults/Pliki/14.CheckFlagsInMiastoKontrahentShow.txt";
    QString file15 = "C:/Defaults/Pliki/15.CheckFlagsInWojewodztwoKontrahentShow.txt";
 initMenuUrzadzeniaListaKontrahent();
    wczytajDane();

    ui->pushButton_3->setEnabled(false);
    ui->pushButton->setEnabled(true);
    // Ikonka check OK /NO
    QString dirPath = "C:/Users/pawel/Documents/Cplusplus/OptiBase/OptiBase/Resources";
    QPixmap pix1(dirPath+ "/YesRed.png");

    ui->lblCheckOkNo->setPixmap(pix1.scaled(ui->lblCheckOkNo->size(),Qt::KeepAspectRatio));// Skaluje pnp do wymierów labela
    // end Ikonka Check Ok/NO
    //**********************************************
}

UrzadzeniaListaKontrahent::~UrzadzeniaListaKontrahent()
{
    delete ui;
}
void UrzadzeniaListaKontrahent::initMenuUrzadzeniaListaKontrahent()
{
    //tworze menu kontekstowe
    setWindowTitle("OptiBase v 1.0:Urządzenia - Lista Przypisz Kontrahenta");

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

    ui->lblNrKontr->setVisible(false);
    ui->labelTest->setVisible(false);
    ui->lblNrUrza->setVisible(false);
    ui->comboBox->setVisible(false);
    ui->comboBox_2->setVisible(false);
    ui->comboBox_3->setVisible(false);
}
void UrzadzeniaListaKontrahent::on_pushButton_clicked()// Przypisz
{

    //cout << "przypisz klienta do analziatora" << endl;
    //pobierz z comboboxa

    int iloscColumn = model->columnCount();

    QModelIndex index = ui->tableView->selectionModel()->currentIndex();
    int stringrowDoSize = (ui->tableView->currentIndex().row()) + 1;
    QVariant tab[iloscColumn];
    QVariant wyslij;
    for (int i = 0; i <= iloscColumn - 1; i++) {
        tab[i] = index.sibling(stringrowDoSize - 1, i).data();
        ui->comboBox_2->addItem(tab[i].toString());
    }
    ui->pushButton_3->setEnabled(true);
    ui->pushButton->setEnabled(false);
    // Ikonka check OK /NO
    //QString dirPath = "C:/Users/pawel/Documents/Cplusplus/OptiBase/OptiBase/Resources";
    QPixmap pix1(dirPath+ "/YesYellow.png");

    ui->lblCheckOkNo->setPixmap(pix1.scaled(ui->lblCheckOkNo->size(),Qt::KeepAspectRatio));// Skaluje pnp do wymierów labela
    // end Ikonka Check Ok/NO
    //**********************************************
}

void UrzadzeniaListaKontrahent::on_pushButton_2_clicked()//zamknij
{


    //cout << "Zamknij liste urzadzen z prypisania" << endl;
    timer->stop();
    destroy();
}

void UrzadzeniaListaKontrahent::wyswietl(QVariant p1, QVariant p2, QVariant p3, QVariant p4)
{
    ui->comboBox->addItem(p1.toString());
    ui->comboBox->addItem(p2.toString());
    ui->comboBox->addItem(p3.toString());
    ui->comboBox->addItem(p4.toString());
}

void UrzadzeniaListaKontrahent::wczytajDane()
{ MainDb *mainDb = new MainDb(this);

    // Tworze modele do Qtable

    model = new QStandardItemModel(1, 14, this);
    ui->tableView->setModel(model);

    model->setHeaderData(0, Qt::Horizontal, "L.P.");
    model->setHeaderData(1, Qt::Horizontal, "Nazwa");
    model->setHeaderData(2, Qt::Horizontal, "Imię");
    model->setHeaderData(3, Qt::Horizontal, "Nazwisko");
    model->setHeaderData(4, Qt::Horizontal, "Kraj");
    model->setHeaderData(5, Qt::Horizontal, "Region");
    model->setHeaderData(6, Qt::Horizontal, "Miasto");
    model->setHeaderData(7, Qt::Horizontal, "Kod Pocztowy");
    model->setHeaderData(8, Qt::Horizontal, "Ulica");
    model->setHeaderData(9, Qt::Horizontal, "Nr domu/mieszkania");
    model->setHeaderData(10, Qt::Horizontal, "Telefon");
    model->setHeaderData(11, Qt::Horizontal, "Telefon prywatny");
    model->setHeaderData(12, Qt::Horizontal, "Adres E-mail");
    model->setHeaderData(13, Qt::Horizontal, "Strona URL");
    model->setHeaderData(14, Qt::Horizontal, "Numer Seryjny z Przypisania");


    //---------------------------------------------------------------
    //TODO: Ukrywam linie w kolumnie 1
    //ui->tableView->setColumnHidden(0, true); //Ukrywam kolumne z LP
        //---------------------------------------------------------------


    QStandardItem *dodajItem = new QStandardItem();
    int pobierzKontrId = 0;

    QString pobierzKontr = "";

    pobierzKontrId = mainDb->pobierzKontrahentaId(pobierzKontrId);
    for (int i = 1; i <= pobierzKontrId; i++) {
        for (int d = 0; d <= 14; d++) {
            pobierzKontr = mainDb->pobierzKontrahenta(pobierzKontr, i, d);
            dodajItem = new QStandardItem(pobierzKontr);
            model->setItem(i - 1, d, dodajItem);
        }
    }





    // pobierz ilosc rzedów
    int rowDoSize = model->rowCount();
    for (int i = 0; i <= rowDoSize; i++) {
        ui->tableView->setRowHeight(i, 20);
    }
    ui->tableView->horizontalHeader()->setSectionResizeMode(
        QHeaderView::ResizeToContents); // Rozszerza kolumny do najdłuzszego itema w kolumnie.
    ui->tableView->setSortingEnabled(true);
    ui->tableView->sortByColumn(1,
                                Qt::SortOrder(0)); // Pierwsza cyfea mowi od jakiej kolumny sortujemy

    iloscWierszy();


}

void UrzadzeniaListaKontrahent::iloscWierszy()
{
    int iloscWierszy = model->rowCount();
    QString qIloscWierszy;
    qIloscWierszy.setNum(iloscWierszy);
    ui->labelTest->setText("Ilosć Kontrahentów: " + qIloscWierszy);
    cout << iloscWierszy;
}
void UrzadzeniaListaKontrahent::myfunctiontimer()
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

void UrzadzeniaListaKontrahent::on_pushButton_3_clicked()// Zapisz
{
MainDb *mainDb = new MainDb(this);
    ui->comboBox->addItem("Przypisany");

 QString nrSeryjnyzCB1 = ui->comboBox->itemText(3); //numer seryjny dla którego przyisujemy pacjenta

 QString nazwaZComboBoxa1 = ui->comboBox_2->itemText(1);

 mainDb->addUrzadzeniaUpdate(nrSeryjnyzCB1,nazwaZComboBoxa1);


    ui->comboBox->clear();
    ui->comboBox_2->clear();
    ui->comboBox_3->clear();

    QPixmap pix1(dirPath+ "/CheckOk.png");

    ui->lblCheckOkNo->setPixmap(pix1.scaled(ui->lblCheckOkNo->size(),Qt::KeepAspectRatio));// Skaluje pnp do wymierów labela

}

void UrzadzeniaListaKontrahent::on_pushButton_4_clicked()//Przypisz na Magazyn
{
    cout<<"Ustaw na magazyn"<<endl;
    QString ustawiony = "MAGAZYN";
    for (int i =0;i<= model->rowCount()-1;i++)
    {
       QStandardItem *itemSzukany = model->item(i,1);
       QString QitemSzukany = itemSzukany->text();

       if (ustawiony==QitemSzukany)
       {
       cout<<"znalazłem Magazyb"<<endl;
           ui->tableView->selectRow(i);
       }
    }
    //long skue = ui->tableView->find("MAGAZYN");
}
