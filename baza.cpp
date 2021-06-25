#include "baza.h"
#include "Info/info.h"
#include "Kontrahent/kontrahentinfo.h"
#include "QApplication"
#include "Timery/timedate.h"
#include "Ustawienia/statystyki.h"
#include "Ustawienia/ustawienia.h"
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
#include <algorithm>
#include <vector>

using namespace std;


int rowDoSize1 = 0, iTabelaPustychRzedow1 = 0;

int pusteRzedy1 = (rowDoSize1) - (iTabelaPustychRzedow1);

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

void Baza::openInfo()
{
    Info *info = new Info(this);
    info->show();
}
void Baza::openSettings()
{
    Ustawienia *ustaw = new Ustawienia(this);
    ustaw->show();
}

void Baza::wczytajDane()
{
    ui->comboBox_5->setVisible(false);
    ui->comboBox_6->setVisible(false);
    ui->checkBox->setChecked(false);
    ui->comboBox_7->setVisible(false);
    ui->comboBox_8->setVisible(false);
    ui->comboBox_9->setVisible(false);
    ui->pushButton_3->setVisible(false);
    ui->lineEditSzukaj->setVisible(false);

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

    QString pobierzNumerSeryjny = "";
    //Lece do MainDB->pobierz Id

    //
    pobierzUrzKontId = mainDb->pobierzUrzadzeniaId(pobierzUrzKontId);
    // "BAZA: Pobierz ilosc urzadzen: " << pobierzUrzKontId;
    vector<int> tabelaPustychRzedow[pobierzUrzKontId];
    int iTabelaPustychRzedow = 0;
    //  "pobierz kontr i urzadz:: mam ilosc modeli z bazy danych:" << pobierzUrzKontId;
    int przesuniecieNaKontraheta = 0; //INFO:: przesuwam do id kontrahents
    for (int i = 1; i <= pobierzUrzKontId; i++) {
        for (int d = 0; d <= 20 + przesuniecieNaKontraheta; d++) {
            QString inti = QString::number(i);
            QString dinti = QString::number(d);

            QStringPobierzUrzKont = mainDb->pobierzKontrahentaZNrSeryjnym(QStringPobierzUrzKont,
                                                                          i,
                                                                          d);
            // "Numeroinny jest" << QStringPobierzUrzKont;
            if (QStringPobierzUrzKont == "Numeros4534") {
                d = 20;
                //  "Do Ukryciaif rzad: Numeros inny jest : " << i;
                tabelaPustychRzedow->push_back(i);
                iTabelaPustychRzedow++;
                dodajItem = new QStandardItem("");
                model->setItem(i - 1, d, dodajItem);

            } else {
                dodajItem = new QStandardItem(QStringPobierzUrzKont);
                // "Jestem przed dodawaniu do tabeli";
                model->setItem(i - 1, d + przesuniecieNaKontraheta, dodajItem);
            }
        }
    }



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


    int rowDoSize = model->rowCount();
    for (int i = 0; i <= rowDoSize; i++) {
        ui->tableViewDB->setRowHeight(i, 20);
    }
    ui->tableViewDB->horizontalHeader()->setSectionResizeMode(
        QHeaderView::ResizeToContents); // Rozszerza kolumny do najdłuzszego itema w kolumnie.
    ui->tableViewDB->sortByColumn(0,
                                  Qt::SortOrder(
                                      0)); // Pierwsza cyfea mowi od jakiej kolumny sortujemy
ui->tableViewDB->setAlternatingRowColors(true);


    tempUrzadz = "";
    tempUrzadz1 = "";
    linia3 = "";
    linia2 = "";
    linia1 = "";

    QVariant wartosc;
    QString Qwartosc;
    pusteRzedy1 = (rowDoSize1) - (iTabelaPustychRzedow1);


    ui->label_2->setText(QString::number(iTabelaPustychRzedow));

    for (int i = rowDoSize1; i >= pusteRzedy1; i--) {
        //qWarning() << "Pusty rzad to : "<<i;

        ui->tableViewDB->hideRow(i);
    }


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

void Baza::on_pushButton_2_clicked()
{
    // Informacje o knotrahencie
    KontrahentInfo *kontrInfo = new KontrahentInfo(this);
    int iloscColumn = model->columnCount();
    QString qIloscColumn;
    qIloscColumn.setNum(iloscColumn);

    //--------------
    int stringrowDoSize = (ui->tableViewDB->currentIndex().row()) + 1;
    //Zaznaczony rzad to: " << stringrowDoSize << endl;


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
    pusteRzedy1 = ui->label_2->text().toInt();
    // "checekd Mark Filtr ON:OFF";
    if (ui->checkBox->isChecked()) {
        qWarning() << "cKliknietey";
        ui->comboBox_5->setVisible(true);
        ui->comboBox_6->setVisible(true);
        ui->comboBox_7->setVisible(true);
        ui->comboBox_8->setVisible(true);
        ui->comboBox_9->setVisible(true);
        ui->pushButton_3->setVisible(true);
        ui->lineEditSzukaj->setVisible(true);

        fillComboBoxes();
    } else {
        // "NIE Klikniety";
        ui->comboBox_5->setVisible(false);
        ui->comboBox_6->setVisible(false);
        ui->comboBox_7->setVisible(false);
        ui->comboBox_8->setVisible(false);
        ui->comboBox_9->setVisible(false);
        ui->pushButton_3->setVisible(false);
        ui->lineEditSzukaj->setVisible(false);
        ui->comboBox_5->clear();
        ui->comboBox_6->clear();
        ui->comboBox_7->clear();
        ui->comboBox_8->clear();
        ui->comboBox_9->clear();
        for (int i = 0; i <= model->rowCount() - 1 - pusteRzedy1; i++) {
            //Wejscie do odkrycia rzedów numer : " << i;
            ui->tableViewDB->showRow(i);
        }
    }
}
void Baza::fillComboBoxes()
{

    pusteRzedy1 = ui->label_2->text().toInt();
    //int rowCount = model->rowCount();
    vector <QString> vfillCb5;
    vector <QString> vfillCb6;
    vector <QString> vfillCb7;
    vector <QString> vfillCb8;
    vector <QString> vfillCb9;


    //qWarning() << "row count to: " << model->rowCount();

    ui->comboBox_5->addItem("Brak");
    ui->comboBox_6->addItem("Brak");

    ui->comboBox_8->addItem("Brak");
    ui->comboBox_9->addItem("Brak");
    ui->comboBox_7->addItem("Brak");
    ui->comboBox_7->addItem("TAK");
    ui->comboBox_7->addItem("MAGAZYN");
    for (int i = 0; i <= model->rowCount() - 1 - pusteRzedy1; i++) {



        QStandardItem *item1 = model->item(i, 1);
        QStandardItem *item2 = model->item(i, 2);
        QStandardItem *item3 = model->item(i, 4);
        QStandardItem *item4 = model->item(i, 12);
        QStandardItem *item5 = model->item(i, 11);

        vfillCb5.push_back(item1->text());
        vfillCb6.push_back(item2->text());
        vfillCb7.push_back(item3->text());
        vfillCb8.push_back(item4->text());
        vfillCb9.push_back(item5->text());

    }
     // Przed usunieciem duplikatow

    sort(vfillCb5.begin(),vfillCb5.end());
    vfillCb5.erase(unique(vfillCb5.begin(),vfillCb5.end()),vfillCb5.end());
    sort(vfillCb6.begin(),vfillCb6.end());
    vfillCb6.erase(unique(vfillCb6.begin(),vfillCb6.end()),vfillCb6.end());
    sort(vfillCb7.begin(),vfillCb7.end());
    vfillCb7.erase(unique(vfillCb7.begin(),vfillCb7.end()),vfillCb7.end());
    sort(vfillCb8.begin(),vfillCb8.end());
    vfillCb8.erase(unique(vfillCb8.begin(),vfillCb8.end()),vfillCb8.end());
    sort(vfillCb9.begin(),vfillCb9.end());
    vfillCb9.erase(unique(vfillCb9.begin(),vfillCb9.end()),vfillCb9.end());
    // Po usunieciu duplikatow
    for(int k = 0; k < vfillCb5.size(); ++k)
    {
        ui->comboBox_5->addItem(vfillCb5[k]) ;
    }
    for(int k = 0; k < vfillCb6.size(); ++k)
    {
        ui->comboBox_6->addItem(vfillCb6[k]) ;
    }
    for(int k = 0; k < vfillCb7.size(); ++k)
    {
        ui->comboBox_7->addItem(vfillCb7[k]) ;
    }
    for(int k = 0; k < vfillCb8.size(); ++k)
    {
        ui->comboBox_8->addItem(vfillCb8[k]) ;
    }
    for(int k = 0; k < vfillCb9.size(); ++k)
    {
        ui->comboBox_9->addItem(vfillCb9[k]) ;
    }

}

QString Baza::filtrOn(QString aktywnyProducent)
{
    for (int k = 0; k <= model->rowCount() - 1; k++) {
        //Ukrywam rzad : " << k;

        ui->tableViewDB->hideRow(k);
    }

    // "Jestem w filtrze";
    QString filter = aktywnyProducent;


    pusteRzedy1 = ui->label_2->text().toInt();

    for (int i = 0; i <= model->rowCount() - 1 - pusteRzedy1; i++) // pusteRzedy
    {
        for (int j = 0; j <= model->columnCount() - 1; j++) {
            QStandardItem *item = model->item(i, j);


            if (filter == "Brak") {
                ui->tableViewDB->showRow(i);
            } else {
                if (item->text().contains(filter)) {
                    //qWarning() << "Wiersz: " << i << " zawiera: " << filter;
                    ui->tableViewDB->showRow(i);
                }
            }
        }

    }
    return 0;
}

void Baza::on_comboBox_5_activated(const QString)
{//Producent d combo boxa


    QString aktywnyProducent = ui->comboBox_5->currentText();
    filtrOn(aktywnyProducent);
}

void Baza::on_comboBox_6_activated(const QString)
{

    QString aktywnyProducent = ui->comboBox_6->currentText();
    filtrOn(aktywnyProducent);
}

void Baza::on_comboBox_7_activated(const QString)
{
    QString aktywnyProducent = ui->comboBox_7->currentText();
    filtrOn(aktywnyProducent);
}

void Baza::on_comboBox_8_activated(const QString )
{
    QString aktywnyProducent = ui->comboBox_8->currentText();
    filtrOn(aktywnyProducent);
}

void Baza::on_comboBox_9_activated(const QString )
{
    QString aktywnyProducent = ui->comboBox_9->currentText();
    filtrOn(aktywnyProducent);
}

void Baza::on_lineEditSzukaj_textEdited(const QString) //szukaj
{}

void Baza::on_pushButton_3_clicked()
{
    int iloscColumn = model->columnCount() - 1;
    int iloscRzedow = model->rowCount() - 2;

    //int szukanyRzad[iloscRzedow];
    qWarning() << "ilosc rzedów to: " << iloscRzedow;
    for (int x = 0; x <= iloscRzedow; x++) {
        qWarning() << " Ukrywam rzad: " << x;
        ui->tableViewDB->hideRow(x);
    }

    QString szukany = QString::fromStdString(ui->lineEditSzukaj->text().toStdString());
    szukany = szukany.toLower();

    QString przeszukiwany;
    //qWarning() << "Szukaj wyrazu: " << szukany;

    for (int i = 0; i <= iloscRzedow; i++) {
        for (int x = 0; x <= iloscColumn; x++) {
            przeszukiwany = model->item(i, x)->text();
            przeszukiwany = przeszukiwany.toLower();
            qWarning() << "Jestem w: rzad: " << i << " kolumna: " << x
                       << " wyraz: " << przeszukiwany;
            if (przeszukiwany == szukany) {
                qWarning() << " ************";
                qWarning() << " JEST!!!!!!";
                qWarning() << " ************";
                //szukanyRzad[i] = i;
                ui->tableViewDB->showRow(i);
            }
        }
    }


}
// do gita

