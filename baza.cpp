#include "baza.h"
#include "Kontrahent/kontrahentinfo.h"
#include "QApplication"
#include "Timery/timedate.h"
#include "time.h"
//#include "ui_Baza.h"
#include "ui_baza.h"
//#include <Info/info.h>
#include "DataBase/maindb.h"
#include <ctime>
#include <exception>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <QString>
#include <QTableView>
#include <QTimer>
#include <QtWidgets>

using namespace std;

//int labelGodzinaPierwsza;
//int labelDataPierwsza;
//int wynikPierwsza;
int rowDoSize = 0, iTabelaPustychRzedow = 0;

int pusteRzedy = (rowDoSize) - (iTabelaPustychRzedow);
fstream fileDataBase1, fileDataBase2, fileDataBase3;
Baza::Baza(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Baza)
{
    ui->setupUi(this);
    ui->labelZegara->setText(" cos tam");
    //---------Sekcja generacji timera
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myfunctiontimer()));
    timer->start(1000);
    //===================

    initMenuBazy();

    wczytajDane();
}

void Baza::initMenuBazy()
{
    //tworze menu kontekstowe
    setWindowTitle("OptiBase v 1.0:Kontrahent - Główna BAZA");

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

void Baza::wczytajDane()
{
    ui->comboBox_5->setVisible(false);
    ui->comboBox_6->setVisible(false);
    ui->checkBox->setChecked(false);

    // Wczytac z Bazy. Kontrahneci i Urzadzenia które mają zakładkę TAK
    QStandardItem *dodajItem = new QStandardItem("");
    MainDb *mainDb = new MainDb(this);
    int pobierzUrzKontId = 0;

    QString QStringPobierzUrzKont = "";
    QString sprawdz;

    // Tworze modele do Qtable

    model = new QStandardItemModel(1, 21, this); //było 14
    ui->tableViewDB->setModel(model);

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

    //INFO:: 1. Pobrac ilosc wszytskich kontrahentow = int iloscWszytskichKontr
    //INFO:: 2.Pobrac ilosc kontrahentow które nie mają NULL w numerze seryjnym int= iloscKontrBezNull
    //INFO:: 3. Przeleciec kontrqhentow i jezeli nie ma null w numerze seryjnym wroci z tym ID.
    //INFO:: 4. Pobrac Kontrahentow z tym numerem seryjnym i urzadzenie z tym numerem seryjnym
    QString pobierzNumerSeryjny = "";
    //qWarning() << "Lece do MainDB->pobierz Id.";

    //
    pobierzUrzKontId = mainDb->pobierzUrzadzeniaId(pobierzUrzKontId);
    qWarning() << "BAZA: Pobierz ilosc urzadzen: " << pobierzUrzKontId;
    vector<int> tabelaPustychRzedow[pobierzUrzKontId];
    int iTabelaPustychRzedow = 0;
    // qWarning() << "pobierz kontr i urzadz:: mam ilosc modeli z bazy danych:" << pobierzUrzKontId;
    int przesuniecieNaKontraheta = 0; //INFO:: przesuwam do id kontrahents
    for (int i = 1; i <= pobierzUrzKontId; i++) {
        for (int d = 0; d <= 20 + przesuniecieNaKontraheta; d++) {
            QString inti = QString::number(i);
            QString dinti = QString::number(d);

            QStringPobierzUrzKont = mainDb->pobierzKontrahentaZNrSeryjnym(QStringPobierzUrzKont,
                                                                          i,
                                                                          d);
            qWarning() << "Numeroinny jest" << QStringPobierzUrzKont;
            if (QStringPobierzUrzKont == "Numeros4534") {
                d = 20;
                // qWarning() << "Do Ukryciaif rzad: Numeros inny jest : " << i;
                tabelaPustychRzedow->push_back(i);
                iTabelaPustychRzedow++;
                dodajItem = new QStandardItem("");
                model->setItem(i - 1, d, dodajItem);

            } else {
                dodajItem = new QStandardItem(QStringPobierzUrzKont);
                //qWarning() << "Jestem przed dodawaniu do tabeli";
                model->setItem(i - 1, d + przesuniecieNaKontraheta, dodajItem);
            }
        }
    }

    //    for (int i = 0; i <= pobierzUrzKontId - 1; i++) {
    //        //qWarning() << " Puste linie to: " << tabelaPustychRzedow[i];
    //    }

    //////*****************************************************************8

    //////*******************************************************************8

    //    ui->tableViewDB->setColumnHidden(0, true); //Ukrywam kolumne z LP urzadzenia
    //    ui->tableViewDB->setColumnHidden(4, true); // Ukrywam Kolumnę z info o przypsianiu
    //    ui->tableViewDB->setColumnHidden(5, true); // Ukrywam Kolumnę z LP kontrahenta
    //---------------------------------------------------------------

    //TODO: Wczytaj kontrahentow z DB "kontrahenci"
    QString tempUrzadz;
    QString tempUrzadz1;
    string linia3;
    string linia2;
    string linia1;
    int row3 = 0;
    int nr_lini3 = 0;

    int rowDoSize = model->rowCount();
    for (int i = 0; i <= rowDoSize; i++) {
        ui->tableViewDB->setRowHeight(i, 20);
    }
    ui->tableViewDB->horizontalHeader()->setSectionResizeMode(
        QHeaderView::ResizeToContents); // Rozszerza kolumny do najdłuzszego itema w kolumnie.
    ui->tableViewDB->sortByColumn(0,
                                  Qt::SortOrder(
                                      0)); // Pierwsza cyfea mowi od jakiej kolumny sortujemy

    row3 = 0;
    nr_lini3 = 0;

    tempUrzadz = "";
    tempUrzadz1 = "";
    linia3 = "";
    linia2 = "";
    linia1 = "";
    //TODO: Przelec po ilosci rzedów i jezeli Producent czysty to ukryj
    QModelIndex index = ui->tableViewDB->selectionModel()->currentIndex();
    QVariant wartosc;
    QString Qwartosc;
    pusteRzedy = (rowDoSize) - (iTabelaPustychRzedow);

    // ui->label_2->setText(QString::number(pusteRzedy));
    ui->label_2->setText(QString::number(iTabelaPustychRzedow));
    //    qWarning() << "Wchodze w petle do ukrycia rzedow ";
    //    //int pusteRzedy;

    //    qWarning() << "rowDoSize to : " << rowDoSize;
    //    qWarning() << "iTabelaPustychRzedow to : " << iTabelaPustychRzedow;
    //+++++++++++
    //for (int i = rowDoSize; i >= (rowDoSize) - (iTabelaPustychRzedow); i--) {
    for (int i = rowDoSize; i >= pusteRzedy; i--) {
        //qWarning() << "Pusty rzad to : "<<i;

        ui->tableViewDB->hideRow(i);
    }
    //++++++++++++++

    iloscWierszy(iTabelaPustychRzedow);
}

void Baza::iloscWierszy(int iTabelaPustychRzedow)
{
    int iloscWierszy = model->rowCount() - iTabelaPustychRzedow;
    QString qIloscWierszy;
    qIloscWierszy.setNum(iloscWierszy);
    ui->labelTest->setText("Ilosć Kontrahentów: " + qIloscWierszy);
    cout << iloscWierszy;
}

void Baza::myfunctiontimer()
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

Baza::~Baza()
{
    delete ui;
}

void Baza::on_pushButton_clicked()
{ //Zamknij
    timer->stop();

    destroy();
}

void Baza::DataiCzas()
{
    cout << "Wszedłem do daty i czsu" << endl;
}
//Info do Gita
void Baza::on_pushButton_2_clicked()
{
    // Informacje o knotrahencie
    KontrahentInfo *kontrInfo = new KontrahentInfo(this);
    int iloscColumn = model->columnCount();
    QString qIloscColumn;
    qIloscColumn.setNum(iloscColumn);

    //--------------
    int stringrowDoSize = (ui->tableViewDB->currentIndex().row()) + 1;
    //cout << "Zaznaczony rzad to: " << stringrowDoSize << endl;

    //ui->label_2->setText(QString::number(iloscColumn) + " " + QString::number(stringrowDoSize));
    QModelIndex index = ui->tableViewDB->selectionModel()->currentIndex();
    QVariant vartosc = index.sibling(index.row(), index.column()).data();
    QString QVartsoc = QVariant(vartosc).toString();
    //ui->label->setText(QVartsoc); //Pokazuje kliknietą komórkę.
    //Sprawdzam czy jest kliknięta komórka

    if (QVartsoc == "") {
        cout << "Pusty. Nie wykonujemy" << endl;

        QMessageBox::information(this, "Ostrzeżenie", "Zaznacz jakieś rekordy.");

    } else {
        QVariant tab[iloscColumn];
        QVariant wyslij;
        for (int i = 0; i <= iloscColumn; i++) {
            tab[i] = index.sibling(stringrowDoSize - 1, i).data();
        }

        kontrInfo->wyswietl(tab[0],
                            tab[1],
                            tab[2],
                            tab[3],
                            tab[4],
                            tab[5],
                            tab[6],
                            tab[7],
                            tab[8],
                            tab[9],
                            tab[10],
                            tab[11],
                            tab[12],
                            tab[13],
                            tab[14],
                            tab[15],
                            tab[16],
                            tab[17],
                            tab[18],
                            tab[19]);

        kontrInfo->show();
    }
}

void Baza::on_checkBox_stateChanged() // Checked Mark Filtr :ON/OFF

{
    pusteRzedy = ui->label_2->text().toInt();
    qWarning() << "checekd Mark Filtr ON:OFF";
    if (ui->checkBox->isChecked()) {
        qWarning() << "cKliknietey";
        ui->comboBox_5->setVisible(true);
        ui->comboBox_6->setVisible(true);
        filtrOn();
        fillComboBoxes();
    } else {
        qWarning() << "NIE Klikniety";
        ui->comboBox_5->setVisible(false);
        ui->comboBox_6->setVisible(false);
        ui->comboBox_5->clear();
        ui->comboBox_6->clear();
        for (int i = 0; i <= model->rowCount() - 1 - pusteRzedy; i++) {
            qWarning() << "Wejscie do odkrycia rzedów numer : " << i;
            ui->tableViewDB->showRow(i);
        }
    }
}
void Baza::fillComboBoxes()
{
    bool jestItem;
    pusteRzedy = ui->label_2->text().toInt();
    ui->comboBox_5->addItem("Brak");
    ui->comboBox_6->addItem("Brak");

    for (int i = 0; i <= model->rowCount() - 1 - pusteRzedy; i++) {
        //int iloscElemtowWCB5 = ui->comboBox_5->count();

        QStandardItem *item1 = model->item(i, 1);
        QStandardItem *item2 = model->item(i, 2);

        //NOTE: Sprawdzam czy element jest juz na liscie w comboBox

        //
        ui->comboBox_5->addItem(item1->text());
        ui->comboBox_6->addItem(item2->text());
    }
    int iloscElemetowWCB5 = ui->comboBox_5->count();

    for (int j = 0; j <= iloscElemetowWCB5; j++)

    {
        qWarning() << "wyraz do porowniaa to: " << ui->comboBox_5->itemText(j);

        for (int k = 1; k <= iloscElemetowWCB5; k++) {
            if (ui->comboBox_5->itemText(j) == ui->comboBox_5->itemText(k)) {
                ui->comboBox_5->removeItem(k);
            }
        }

    } //
    int iloscElemetowWCB6 = ui->comboBox_6->count();

    for (int j = 0; j <= iloscElemetowWCB6; j++)

    {
        qWarning() << "wyraz do porowniaa to: " << ui->comboBox_6->itemText(j);

        for (int k = 1; k <= iloscElemetowWCB6; k++) {
            if (ui->comboBox_6->itemText(j) == ui->comboBox_6->itemText(k)) {
                ui->comboBox_6->removeItem(k);
            }
        }

    } //


}
//    ui->comboBox_5->setDuplicatesEnabled(false);
//    ui->comboBox_6->setDuplicatesEnabled(true);

void Baza::filtrOn()
{
    for (int k = 0; k <= model->rowCount() - 1; k++) {
        qWarning() << "Ukrywam rzad : " << k;

        ui->tableViewDB->hideRow(k);
    }

    qWarning() << "Jestem w filtrze";
    QString filter = "Jawon";

    qWarning() << " Odkrywam takie co mają w nazwie Jawon";
    pusteRzedy = ui->label_2->text().toInt();
    qWarning() << "Puste rzedy to : " << pusteRzedy;
    //for (int i =0; i<=model ->rowCount()-1;i++)// pusteRzedy
    for (int i = 0; i <= model->rowCount() - 1 - pusteRzedy; i++) // pusteRzedy
    {
        for (int j = 0; j <= model->columnCount() - 1; j++) {
            QStandardItem *item = model->item(i, j);
            qWarning() << " Wyswietlam i: " << i << " j: " << j << " wyraz to: " << item->text();

            if (item->text().contains(filter)) {
                qWarning() << "Wiersz: " << i << " zawiera: " << filter;
                ui->tableViewDB->showRow(i);
            }
        }
        //TODO: Jakis problem przy wyswietlaniu powyzej 12 linii. ( czyli 13) tam gdzie mam puste czyli nulle.
    }

    //    for (int i = 1; i <= model->rowCount() - 1; ++i) //int i = 0; i < model->rowCount()
    //    //for( int i = 0; i < ui->tableViewDB->rowCount(); ++i )
    //    {
    //        bool match = false;
    //        for (int j = 1; j <= model->columnCount() - 1;
    //             ++j) { //QTableWidgetItem //int j = 0; j < model->columnCount()
    //            QStandardItem *item = model->item(i, j);
    //            if (item->text().contains(filter)) {
    //                qWarning() << "Pokazuje Numer i: " << i << " Numer j: " << j;
    //                qWarning() << item->text();
    //                ui->tableViewDB->showRow(i);
    //                j = 20;
    //            } else {
    //                qWarning() << item->text();
    //                //ui->tableViewDB->hideRow(i);
    //                qWarning() << "Ukrywam Numer i: " << i << " Numer j: " << j;
    //                //                match = true;
    //                //                break;
    //            }
    //        }
    //        //ui->tableViewDB->setRowHidden(i, !match);
    //    }
}
