#include "urzadzenialista.h"
#include "DataBase/maindb.h"
#include "Timery/timedate.h"
#include "Ustawienia/ustawienia.h"
#include "ui_urzadzenialista.h"
#include "urzadzenialistakontrahent.h"
#include "urzadzenialistaedytuj.h"
#include <Info/info.h>
#include <ctime>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <QApplication>
#include <QMessageBox>
#include <QString>
#include <QTableView>
#include <QTimer>
#include <QtWidgets>

using namespace std;
fstream fileUrzadzeniaLista, fileUrzadzeniaLista2;
int rowDoSize = 0, iTabelaPustychRzedow = 0;
int pusteRzedy = (rowDoSize) - (iTabelaPustychRzedow);
QString aktywnyProducent="";

UrzadzeniaLista::UrzadzeniaLista(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UrzadzeniaLista)
{
    ui->setupUi(this);
    //---------Sekcja generacji timera
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myfunctiontimer()));
    timer->start(1000);
    //===================
//    QString file1 = "C:/Defaults/Pliki/1.DB.txt";
//    QString file2 = "C:/Defaults/Pliki/2.Kontrahent.txt";
//    QString file3 = "C:/Defaults/Pliki/3.Urzadzenie.txt";
//    QString file4 = "C:/Defaults/Pliki/4.ZapisKraj.txt";
//    QString file5 = "C:/Defaults/Pliki/5.ZapisMiasta.txt";
//    QString file6 = "C:/Defaults/Pliki/6.ZapisWojewodztwa.txt";
//    QString file7 = "C:/Defaults/Pliki/7.ZapisProducenta.txt";
//    QString file8 = "C:/Defaults/Pliki/8.ZapisModel.txt";
//    QString file9 = "C:/Defaults/Pliki/9.ZapisNrSeryjny.txt";
//    QString file10 = "C:/Defaults/Pliki/10.CheckFlagsInMiasto.txt";
//    QString file11 = "C:/Defaults/Pliki/11.CheckFlagsInKraj.txt";
//    QString file12 = "C:/Defaults/Pliki/12.CheckFlagsInWojewodztwa.txt";
//    QString file13 = "C:/Defaults/Pliki/13.CheckFlagsInKrajKontrahentShow.txt";
//    QString file14 = "C:/Defaults/Pliki/14.CheckFlagsInMiastoKontrahentShow.txt";
//    QString file15 = "C:/Defaults/Pliki/15.CheckFlagsInWojewodztwoKontrahentShow.txt";
    initMenuUrzadzeniaLista();
    wczytajDane();
}

UrzadzeniaLista::~UrzadzeniaLista()
{
    delete ui;
}
void UrzadzeniaLista::initMenuUrzadzeniaLista()
{
    //tworze menu kontekstowe
    setWindowTitle("OptiBase v 1.0:Urządzenia - Lista");

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
    // auto mainEdycja = menuBar()->addMenu("Edycja");
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

//   // ui->label->setVisible(false);
//    ui->label_2->setVisible(false);
//ui->label_3->setVisible(false);
//ui->label_4->setVisible(false);
//ui->label_5->setVisible(false);
//ui->label_6->setVisible(false);

    //    ui->label_4->setText(ui->comboBox->currentText());
    //    ui->label_5->setText(ui->comboBox_2->currentText());
    //    ui->label_6->setText(ui->comboBox_3->currentText());

    ui->label_4->setText("Brak");
    ui->label_5->setText("Brak");
    ui->label_6->setText("Brak");
//    ui->comboBox->setVisible(false);
//    ui->comboBox_2->setVisible(false);
//    ui->comboBox_3->setVisible(false);
    ui->comboBox->clear();
    ui->comboBox_2->clear();
    ui->comboBox_3->clear();
    ui->checkBox->setChecked(false);
    ui->chbLast10->setChecked(false);
  //   ui->chbLast10->setVisible(false);
}
void UrzadzeniaLista::wczytajDane()
{ //qWarning ()<<"1";
    MainDb *mainDb = new MainDb(this);



    model = new QStandardItemModel(1, 6, this);
    ui->tableView->setModel(model);
//qWarning ()<<"2";

    model->setHeaderData(0, Qt::Horizontal, "L.P.");
    model->setHeaderData(1, Qt::Horizontal, "Producent");
    model->setHeaderData(2, Qt::Horizontal, "Model");
    model->setHeaderData(3, Qt::Horizontal, "Nr Seryjny");
    model->setHeaderData(4, Qt::Horizontal, "Przypisany");
    model->setHeaderData(5, Qt::Horizontal, "Kontrahent");
//qWarning ()<<"3";

    //---------------------------------------------------------------
    //ui->tableView->setColumnHidden(0,true); //Ukrywam kolumne z LP
    //---------------------------------------------------------------
    QStandardItem *dodajItem = new QStandardItem();

    int pobierzUrzId = 0;

    QString pobierzUrz = "";
//qWarning ()<<"4";
    pobierzUrzId = mainDb->pobierzUrzadzeniaId(pobierzUrzId);
    for (int i = 1; i <= pobierzUrzId; i++) {
        for (int d = 0; d <= 5; d++) {
            pobierzUrz = mainDb->pobierzUrzadzenia(pobierzUrz, i, d);
            dodajItem = new QStandardItem(pobierzUrz);
            model->setItem(i - 1, d, dodajItem);
        }
    }
//qWarning ()<<"5";
    int rowDoSize = model->rowCount();
    for (int i = 0; i <= rowDoSize; i++) {
        ui->tableView->setRowHeight(i, 20);
    }
    ui->tableView->horizontalHeader()->setSectionResizeMode(
                QHeaderView::ResizeToContents); // Rozszerza kolumny do najdłuzszego itema w kolumnie.
    ui->tableView->sortByColumn(0,
                                Qt::SortOrder(0)); // Pierwsza cyfea mowi od jakiej kolumny sortujemy

    //ui->tableView->setRowHeight(1,20);
    //ui->tableView->setRowHeight(2,20);
    //ui->tableView->setRowHeight(3,20);
    iloscWierszy();
    //qWarning ()<<"6";

    for(int f=0;f<=model->rowCount()-1;f++)
    {
        ui->tableView->showRow(f);
    }


    if ( ui->label_4->text()!="Brak" || ui->label_5->text()!="Brak" || ui->label_6->text()!="Brak")
    {
        ui->checkBox->setChecked(true);

        if (ui->comboBox->currentText()!="Brak")
        {//qWarning ()<<"7";
            aktywnyProducent=ui->comboBox->currentText();

        }
        else if (ui->comboBox_2->currentText()!="Brak")
        {//qWarning ()<<"8";
            aktywnyProducent=ui->comboBox_2->currentText();
        }
        else if (ui->comboBox_3->currentText()!="Brak")
        {//qWarning ()<<"9";
            aktywnyProducent=ui->comboBox_3->currentText();
        }
        //qWarning ()<<"10";
        //qWarning ()<<"Aktywny producent to: "<<aktywnyProducent;
        filtrOn(aktywnyProducent);
        //qWarning ()<<"11";
    }
    else
    {
       // qWarning ()<<"Którys label ma brak";
        ui->checkBox->setChecked(false);
    }
//qWarning ()<<"12 end";
}

void UrzadzeniaLista::iloscWierszy()
{
    int iloscWierszy = model->rowCount();
    QString qIloscWierszy;
    qIloscWierszy.setNum(iloscWierszy);
    ui->labelTest->setText("Ilosć Urządzeń: " + qIloscWierszy);
    cout << iloscWierszy;
}
void UrzadzeniaLista::myfunctiontimer()
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
void UrzadzeniaLista::on_pushButton_clicked()
{
    //Odswiez
    ui->label_4->setText(ui->comboBox->currentText());
    ui->label_5->setText(ui->comboBox_2->currentText());
    ui->label_6->setText(ui->comboBox_3->currentText());

    wczytajDane();
}

void UrzadzeniaLista::on_pushButton_2_clicked()
{
    //Zamknij
    destroy();
}

void UrzadzeniaLista::on_pushButton_3_clicked()
{
    //Usuń
    // usunać zaznaczony rząd
    MainDb *mainDb = new MainDb(this);
    QMessageBox msgBox;
    if (QMessageBox::question(this,
                              "Ostrzeżenie",
                              "Czy na pewno chcesz usunąć zaznaczony rekord?.",
                              QMessageBox::Ok | QMessageBox::Cancel)
            == QMessageBox::Ok)
        //(QMessageBox::Ok)
    {
        int iloscColumn = model->columnCount();
        QString qIloscColumn;
        qIloscColumn.setNum(iloscColumn);

        //--------------
        int stringrowDoSize = (ui->tableView->currentIndex().row()) + 1;
        //cout << "Zaznaczony rzad to: " << stringrowDoSize << endl;

        ui->label_2->setText(QString::number(iloscColumn) + " " + QString::number(stringrowDoSize));
        QModelIndex index = ui->tableView->selectionModel()->currentIndex();
        QVariant vartosc = index.sibling(index.row(), index.column()).data();
        QString QVartsoc = QVariant(vartosc).toString();
        ui->label->setText(QVartsoc); //Pokazuje kliknietą komórkę.

        QVariant tab[iloscColumn];
        QVariant wyslij;
        for (int i = 0; i <= iloscColumn; i++) {
            tab[i] = index.sibling(stringrowDoSize - 1, i).data();
        }



        QString QNumerSeryjny="";

        QVariant VNumerSeryjny = index.sibling(index.row(), (3)).data();


        QNumerSeryjny = QVariant(VNumerSeryjny).toString();
        mainDb->UrzadzeniaDelete(QNumerSeryjny);

        model->removeRows(stringrowDoSize - 1, 1);
        //wczytaj ponownie dane
        iloscWierszy();



        QMessageBox::information(this, "Ostrzeżenie", "Rekord  usunięty");
    } else {
        QMessageBox::information(this, "Ostrzeżenie", "Rekord nie usunięty");
    }
}

void UrzadzeniaLista::on_pushButton_4_clicked()
{
    //Edytuj
    QString qLp="Test", qProducent="Test", qModel="Test", qNrSeryjny="Test", qPrzypisany="Test", qKontrahent="Test";
    UrzadzeniaListaEdytuj *Ule = new UrzadzeniaListaEdytuj(this);

    int iloscColumn = model->columnCount();
    int stringRowDosize = (ui->tableView->currentIndex().row())+1;
    QModelIndex index = ui->tableView->selectionModel()->currentIndex();
    QVariant vartosc = index.sibling(index.row(), index.column()).data();
    QString QVartsoc = QVariant(vartosc).toString();
    ui->label->setText(QVartsoc); //Pokazuje kliknietą komórkę.

    QVariant tab[iloscColumn];
    QVariant wyslij;
    for (int i = 0; i <= iloscColumn; i++) {
        tab[i] = index.sibling(stringRowDosize - 1, i).data();
    }



    Ule->setLabelsInfo (tab[0],
            tab[1],
            tab[2],
            tab[3],
            tab[4],
            tab[5] );
    Ule->show();

}

void UrzadzeniaLista::on_pushButton_5_clicked()
{
    //Zapisz
}

void UrzadzeniaLista::on_pushButton_6_clicked()
{
    // Przypisz Kontrahenta

    //Wyswietl Tabele kontrahentów.
    // Zaznacz jakiegos
    //Dopisz do TABELI z urzadzeniami
    //Zapisz w pliku BDMain
cout <<"1"<<endl;
    QModelIndex index = ui->tableView->selectionModel()->currentIndex();
    QVariant vartosc = index.sibling(index.row(), index.column()).data();
    QString QVartsoc = QVariant(vartosc).toString();
    ui->label->setText(QVartsoc); //Pokazuje kliknietą komórkę.
    cout <<"2"<<endl;
    if (QVariant(vartosc).toString() == "Przypisany") {
        cout <<"2.1"<<endl;
        QMessageBox::information(this,
                                 "Ostrzeżenie",
                                 "Ten analizator jest juz przypisany do konkretnego kontrahenta. "
                                         "Nie możesz go przypisać do innego.");

    } else {
        cout <<"2.2"<<endl;
        //cout << "nie przypisany" << endl;

        UrzadzeniaListaKontrahent *urzkl = new UrzadzeniaListaKontrahent(this);
        cout <<"2.3"<<endl;
        int iloscColumn = model->columnCount();
        cout <<" Ilosc kolumn : "<<endl;
        cout << iloscColumn <<endl;
        int stringrowDoSize = (ui->tableView->currentIndex().row()) + 1;
        cout <<" stringrowDoSize : "<<endl;
        cout << stringrowDoSize <<endl;
        cout <<"2.4"<<endl;
        QVariant tab[model->columnCount()]; //QVariant tab[iloscColumn];
        cout <<" Ilosc kolumn w tab: "<<endl;
        qWarning ()<< (tab[iloscColumn].toString());
        cout <<"2.5"<<endl;
        QVariant wyslij;
        for (int i = 0; i <= iloscColumn-1; i++) {
            tab[i] = index.sibling(stringrowDoSize - 1, i).data();
        }
cout <<"2.6"<<endl;
        urzkl->wyswietl(tab[0], tab[1], tab[2], tab[3]);

        urzkl->show();
    }
    cout <<"3 end"<<endl;
}
void UrzadzeniaLista::openInfo()
{
    Info *info = new Info(this);
    info->show();
}
void UrzadzeniaLista::openSettings()
{
    Ustawienia *ustaw = new Ustawienia(this);
    ustaw->show();
}
void UrzadzeniaLista::on_checkBox_stateChanged()
{

    pusteRzedy = ui->label_2->text().toInt();
    //qWarning() << "checekd Mark Filtr ON:OFF";
    if (ui->checkBox->isChecked()) {
        //qWarning() << "cKliknietey";
        ui->comboBox->setVisible(true);
        ui->comboBox_2->setVisible(true);
        ui->comboBox_3->setVisible(true);
        //filtrOn("Brak");
        ui->chbLast10->setVisible(true);        fillComboBoxes();
    } else {
        // qWarning() << "NIE Klikniety";
        ui->comboBox->setVisible(false);
        ui->comboBox_2->setVisible(false);
        ui->comboBox_3->setVisible(false);
        ui->comboBox->clear();
        ui->comboBox_2->clear();
        ui->comboBox_3->clear();
         ui->chbLast10->setVisible(false);
         ui->chbLast10->setChecked(false);
        for (int i = 0; i <= model->rowCount() - 1 - pusteRzedy; i++) {
            // qWarning() << "Wejscie do odkrycia rzedów numer : " << i;
            ui->tableView->showRow(i);
        }
    }

}

void UrzadzeniaLista::fillComboBoxes()
{
    vector <QString> vfillCb10;
    vector <QString> vfillCb11;
    vector <QString> vfillCb12;

    pusteRzedy = ui->label_3->text().toInt();
    ui->comboBox->addItem("Brak");
    ui->comboBox_2->addItem("Brak");
    ui->comboBox_3->addItem("Brak");

    for (int i = 0; i <= model->rowCount() - 1 - pusteRzedy; i++) {
        //int iloscElemtowWCB5 = ui->comboBox_5->count();

        QStandardItem *item1 = model->item(i, 1);
        QStandardItem *item2 = model->item(i, 2);
        QStandardItem *item3 = model->item(i, 4);

        //NOTE: Sprawdzam czy element jest juz na liscie w comboBox

        //
        vfillCb10.push_back(item1->text());
        vfillCb11.push_back(item2->text());
        vfillCb12.push_back(item3->text());

    }
    sort(vfillCb10.begin(),vfillCb10.end());
    vfillCb10.erase(unique(vfillCb10.begin(),vfillCb10.end()),vfillCb10.end());
    sort(vfillCb11.begin(),vfillCb11.end());
    vfillCb11.erase(unique(vfillCb11.begin(),vfillCb11.end()),vfillCb11.end());
    sort(vfillCb12.begin(),vfillCb12.end());
    vfillCb12.erase(unique(vfillCb12.begin(),vfillCb12.end()),vfillCb12.end());

    //cout << "Po usunieciu duplikatow\n";
    for(int k = 0; k < vfillCb10.size(); ++k)
    //for(int k = 0; k < vfillCb10.size(); ++k)
    {
        ui->comboBox->addItem(vfillCb10[k]) ;
    }
    for(int k = 0; k < vfillCb11.size(); ++k)
    {
        ui->comboBox_2->addItem(vfillCb11[k]) ;
    }
    for(int k = 0; k < vfillCb12.size(); ++k)
    {
        ui->comboBox_3->addItem(vfillCb12[k]) ;
    }

}
void UrzadzeniaLista::on_comboBox_activated(const QString &arg1)
{
    //qWarning() << "Activatefd w CB5: " << ui->comboBox_5->currentText();
    aktywnyProducent = ui->comboBox->currentText();
    filtrOn(aktywnyProducent);
    ui->label_4->setText(ui->comboBox->currentText());
}

void UrzadzeniaLista::on_comboBox_2_activated(const QString &arg1)
{
    //qWarning() << "Activatefd w CB6: " << ui->comboBox_6->currentText();
     aktywnyProducent = ui->comboBox_2->currentText();
    filtrOn(aktywnyProducent);
    ui->label_5->setText(ui->comboBox_2->currentText());
}
void UrzadzeniaLista::on_comboBox_3_activated(const QString &arg1)
{
    //qWarning() << "Activatefd w CB6: " << ui->comboBox_6->currentText();
    aktywnyProducent = ui->comboBox_3->currentText();
    filtrOn(aktywnyProducent);
    ui->label_6->setText(ui->comboBox_3->currentText());
}
QString UrzadzeniaLista::filtrOn(QString aktywnyProducent)
{
    for (int k = 0; k <= model->rowCount() - 1; k++) {
        //qWarning() << "Ukrywam rzad : " << k;

        ui->tableView->hideRow(k);
    }

   // qWarning() << "Jestem w filtrze";
    QString filter = aktywnyProducent;

    //qWarning() << " Odkrywam takie co mają w nazwie Jawon";
    pusteRzedy = ui->label_2->text().toInt();
    //qWarning() << "Puste rzedy to : " << pusteRzedy;
    //for (int i =0; i<=model ->rowCount()-1;i++)// pusteRzedy
    for (int i = 0; i <= model->rowCount() - 1 - pusteRzedy; i++) // pusteRzedy
    {
        for (int j = 0; j <= model->columnCount() - 1; j++) {
            QStandardItem *item = model->item(i, j);
            //qWarning() << " Wyswietlam i: " << i << " j: " << j << " wyraz to: " << item->text();

            if (filter == "Brak") {
                ui->tableView->showRow(i);
            } else {
                if (item->text().contains(filter)) {
                    //qWarning() << "Wiersz: " << i << " zawiera: " << filter;
                    ui->tableView->showRow(i);
                }
            }
        }
        //qWarning ()<<"12 filtron";
        //TODO: Jakis problem przy wyswietlaniu powyzej 12 linii. ( czyli 13) tam gdzie mam puste czyli nulle.
    }
    return 0;
}
void UrzadzeniaLista::on_chbLast10_stateChanged() // last 10
{
    // Ostatnie 10.
    if (ui->chbLast10->isChecked())
    {
        qWarning ()<<"Swieci";
// Przelec po wszytskich. Oceń ile ich jest. ukryh wszytskie wyswietl w petli ostanie 10 od tyłu
        for(int f=0;f<=model->rowCount()-1;f++)
        {
            ui->tableView->hideRow(f);
        }

        for (int g=model->rowCount()-1;g>=(model->rowCount() -1) -10; g--)
        {

            //
             ui->tableView->showRow(g);
        }


    }
    else
    {
        qWarning ()<<"NIE Swieci";

        for(int f=0;f<=model->rowCount()-1;f++)
        {
            ui->tableView->showRow(f);
        }
    }

}
