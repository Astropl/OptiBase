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
    // qWarning() << "pobierz kontr i urzadz:: mam ilosc modeli z bazy danych:" << pobierzUrzKontId;
    int przesuniecieNaKontraheta = 0; //INFO:: przesuwam do id kontrahents
    for (int i = 1; i <= pobierzUrzKontId; i++) {
        for (int d = 0; d <= 20 + przesuniecieNaKontraheta; d++) {
            QString inti = QString::number(i);
            QString dinti = QString::number(d);
            //TODO:: Pobrac numer seryjny z kontrahenci
            //qWarning() << " i = " + inti << " d = " + dinti;
            //pobierzNumerSeryjny = mainDb->pobierzNumerSeryjnyZKontrahenta(pobierzNumerSeryjny);

            QStringPobierzUrzKont = mainDb->pobierzKontrahentaZNrSeryjnym(QStringPobierzUrzKont,
                                                                          i,
                                                                d);
            qWarning() << "Numeroinny jest" <<QStringPobierzUrzKont;
            if (QStringPobierzUrzKont == "Numeros4534") {
                //i++;
                ui->tableViewDB->hideRow(i);
                d = 20;
                //qWarning() << "Numeros inny jest";
            } else {
                dodajItem = new QStandardItem(QStringPobierzUrzKont);
                //qWarning() << "Jestem przed dodawaniu do tabeli";
                model->setItem(i - 1, d + przesuniecieNaKontraheta, dodajItem);
                //qWarning() << "Jestem w po dodawaniu do tabeli";
                // ui->comboBox_2->addItem(QStringPobierzUrzKont);
                //            qDebug() << dodajItem->QString::toStdString(dodajItem);
            }
        }
    }
    //    setSelectionBehavior(QAbstractItemView::SelectRows);
    //    setSelectionMode(QAbstractItemView::SingleSelection);
    //---------------------------------------------------------------
    //NOTE: ukrywam 3 linie
    //ui->tableViewDB->setRowHidden()
    // int iloscRowow = pobierzUrzKontId;
    //int stringrowDoSize = (ui->tableViewDB->currentIndex().row()) + 1;
    //qWarning()<<" string row do sieze pzy inicjalizacji  = "<<stringrowDoSize;
    //        QModelIndex index = ui->tableViewDB  ->selectionModel()->currentIndex();
    //        QVariant vartosc = index.sibling(index.row(), index.column()).data();
    //        QString QVartsoc = QVariant(vartosc).toString();

    int iloscRzedow = model->rowCount();
    //////*****************************************************************8
    //    for (int komorka = 0; komorka <= iloscRzedow;
    //         komorka++) { //qWarning()<<" string row do sieze  = "<<stringrowDoSize;
    //        qWarning() << " komorka  = " << komorka;
    //        //bool flaga = model-> item(komorka,1)->text().isNull();
    //        //porownajItem = new QStandardItem(model->tak)
    //        //QStandardItem cosJest = model->takeItem(komorka,0);
    //        //model->takeRow(int row);
    //        if (model->takeRow(komorka).isEmpty()) {
    //            qWarning() << model->takeRow(komorka).value(komorka)->text();
    //            qWarning() << "rzad " << komorka;
    //            qWarning() << "nie pusty wierz";
    //        } else {
    //            qWarning() << model->takeRow(komorka).value(komorka)->text();;
    //            qWarning() << "pusty wierz";
    //            qWarning() << "rzad " << komorka;
    //        }
    //    }
    //////*******************************************************************8

    //        for (int xyz =0;xyz <=pobierzUrzKontId-2;xyz++)

    //        {qWarning() <<"pobierz urzkontrid"<< xyz;
    //            QString itemModel;

    //               bool flaga = model-> item(xyz,0)->text().isNull();
    //               qWarning ()<< "Flaga is: "<< flaga;
    //               if (!flaga)
    //               {
    //                   //nic nie rob
    //                   qWarning ()<< "nie pusty wierz";
    //               }
    //               else
    //               {qWarning ()<< "pusty wierz";
    //                   ui->tableViewDB->setRowHidden(xyz,true);
    //               }

    //        }
    //    ui->tableViewDB->setColumnHidden(0, true); //Ukrywam kolumne z LP urzadzenia
    //    ui->tableViewDB->setColumnHidden(4, true); // Ukrywam Kolumnę z info o przypsianiu
    //    ui->tableViewDB->setColumnHidden(5, true); // Ukrywam Kolumnę z LP kontrahenta
    //---------------------------------------------------------------
    //model->insertRow(model->rowCount());

    //ui->labelTest->text(QString::number(iloscWierszy));

    //QStandardItem *dodajItem = new QStandardItem("Jakies cos");
    //QStandardItem *dodajItem1 = new QStandardItem("Jakies cos");
    //    model->setItem(iloscWierszy,1,dodajItem);
    //    model->setItem(iloscWierszy, 1, dodajItem); // Dodoaje item i od razu wiersz.

    //Wczytuje kontrahentow z pliku
    //TODO: Wczytaj kontrahentow z DB "kontrahenci"
    QString tempUrzadz;
    QString tempUrzadz1;
    string linia3;
    string linia2;
    string linia1;
    int row3 = 0;
    int nr_lini3 = 0;

    // porownuje i sprawdzam czy sa takie same w combo boxach

    //    int iloscWcomboBox4 = ui->comboBox_4->count(); //krótki z DB kontrahenci
    //    int iloscWComboBox2 = ui->comboBox_2->count(); //dlugi kontrahneci
    //    for (int i = 0; i <= iloscWcomboBox4 - 1; i++) {
    //        QString itZComboBoxa4 = ui->comboBox_4->itemText(i);
    //        //tempUrzadz1 = ui->lblUrzadzenie->text();

    //        for (int z = 0; z <= iloscWComboBox2 - 1; z++) {
    //            QString itZComboBoxa2 = ui->comboBox_2->itemText(z);

    //            if (itZComboBoxa2 == itZComboBoxa4) {
    //                for (int k = 0; k < 14; k++) {
    //                    int naKtorejPozycji = ui->comboBox_2->findText(itZComboBoxa2);
    //                    //cout << " Pozycja nr" << naKtorejPozycji << endl;
    //                    QString tym1 = ui->comboBox_2->itemText(naKtorejPozycji + k);
    //                    dodajItem = new QStandardItem(tym1);
    //                    model->setItem(row3, nr_lini3 + k + 5, dodajItem);
    //                }
    //                row3++;
    //            }
    //        }
    //        //row3++;
    //    }
    //    row3 = 0;

    //    int iloscWcomboBox3 = ui->comboBox_3->count(); //CB4krótki z DB kontrahenci
    //    int iloscWComboBox = ui->comboBox->count();    //CB2dlugi kontrahneci
    //    for (int i = 0; i <= iloscWcomboBox3 - 1; i++) {
    //        QString itZComboBoxa3 = ui->comboBox_3->itemText(i);

    //        for (int z = 0; z <= iloscWComboBox - 1; z++) {
    //            QString itZComboBoxa = ui->comboBox->itemText(z);

    //            if (itZComboBoxa == itZComboBoxa3) {
    //                //cout << "Znalazłem" << endl;
    //                //cout << itZComboBoxa.toStdString() << endl;
    //                for (int k = 0; k < 5; k++) {
    //                    int naKtorejPozycji = ui->comboBox->findText(itZComboBoxa);
    //                    //cout << " Pozycja nr" << naKtorejPozycji << endl;
    //                    QString tym2 = ui->comboBox->itemText(naKtorejPozycji + k);

    //                    dodajItem = new QStandardItem(tym2);
    //                    model->setItem(row3, nr_lini3 + k, dodajItem);
    //                }
    //                row3++;
    //            }
    //        }
    //    }

    int rowDoSize = model->rowCount();
    for (int i = 0; i <= rowDoSize; i++) {
        ui->tableViewDB->setRowHeight(i, 20);
    }
    ui->tableViewDB->horizontalHeader()->setSectionResizeMode(
        QHeaderView::ResizeToContents); // Rozszerza kolumny do najdłuzszego itema w kolumnie.
    ui->tableViewDB->sortByColumn(0,
                                  Qt::SortOrder(
                                      0)); // Pierwsza cyfea mowi od jakiej kolumny sortujemy

    iloscWierszy();
    row3 = 0;
    nr_lini3 = 0;
    //row2 = 0;
    //nr_lini2 = 0;

    // nr_lini1 = 0;
    tempUrzadz = "";
    tempUrzadz1 = "";
    linia3 = "";
    linia2 = "";
    linia1 = "";
    //TODO: Przelec po ilosci rzedów i jezeli Producent czysty to ukryj
    QModelIndex index = ui->tableViewDB->selectionModel()->currentIndex();
    QVariant wartosc;
    QString Qwartosc;
    qWarning() << "Wchodze w petle do ukrycia rzedow ";
    for (int i = 0; i <= rowDoSize - 1; i++) {
        //qWarning()<<(index.siblingAtRow(i) , index.siblingAtColumn(2)).data();

        QString SelectetItem;

        try { //auto item = model->item(i,0);
              //SelectetItem = item;
            //qWarning()<< item->text();

        } catch (const std::exception &ex) {
            qWarning() << "Zbłedem";
        }
        //qWarning()<< index.model()->data
        //qWarning()<< model->item(i,2);
        //qWarning()<<ui->tableViewDB->model()->index(i,2).data().toString();
        //wartosc = index.sibling(i, 2).data().toString();
        //wartosc = (index.siblingAtRow(i) , index.siblingAtColumn(2)).data();
        Qwartosc = QVariant(wartosc).toString();
        qWarning() << "ilosc rzedow = " << i << " z " << rowDoSize;
        qWarning() << "zwykla wartosc = " << i << " " << Qwartosc;
        //Qwartosc = QVariant(wartosc).toString();
        //qWarning() << "QWaertosc = " << i << " " << Qwartosc;
        if (Qwartosc != "") {
            ui->tableViewDB->hideRow(i);
        }
    }
}

void Baza::iloscWierszy()
{
    int iloscWierszy = model->rowCount();
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
