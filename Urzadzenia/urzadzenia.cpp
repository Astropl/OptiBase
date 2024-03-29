#include "urzadzenia.h"

#include "DataBase/checkfiles.h"
#include "DataBase/maindb.h"
#include "Timery/timedate.h"
#include "Ustawienia/ustawienia.h"
#include "mainwindow.h"
#include "time.h"
#include "ui_urzadzenia.h"
#include "urzadzeniadodajmodel.h"
#include "urzadzeniadodajnrseryjny.h"
#include "urzadzeniadodajproducenta.h"
#include "urzadzeniadodajseryjnie.h"
#include <Info/info.h>
#include <ctime>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <QDebug>
#include <QString>
#include <QTimer>

using namespace std;

string stringLabela4 = ("Producent: , Model: , Nr. Seryjny: ");
QString zaznaczono;
QString QStringPobierzProducenta = "";
QString QStringPobierzModel = "";
int pobierzProducentaId = 0;
int pobierzModelId = 0;

fstream plikUrzadzenia;
int iloscUrzadzen = 0;
int checkFlagsVariableProducent = 0;
int checkFlagsVariableModel = 0;



Urzadzenia::Urzadzenia(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Urzadzenia)

{
    ui->setupUi(this);
    ui->comboBox->addItem("");
    ui->comboBox_2->addItem("");
    ui->comboBox_3->addItem("");
    ui->lineEditNumber->setText(QString::number(iloscUrzadzen));

    //---------Sekcja generacji timera
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myfunctiontimer()));
    timer->start(1000);
    //===================
    //qWarning() << "How Much Device";
    howMuchDevice();
    //qWarning() << "How Much Device:End";
    //qWarning() << "initMenuUrzadzenia";
    initMenuUrzadzenia();
    //qWarning() << "initMenuUrzadzenia:END";
    //qWarning() << "wypelnijProducenta";
    wypelnijProducenta();
    //qWarning() << "wypelnijProducenta:End";
    //qWarning() << "wypelnijModel";
    wypelnijModel();
    //qWarning() << "wypelnijModel:End";

    countriesListModel = new QStringListModel(this);

    ui->countriesList->setModel(countriesListModel);
    int row = countriesListModel->rowCount(); // pobieram liczbę wierszy

    countriesListModel->insertRow(row); // wstawiam dodatkowy wiersz na końcu
    // QModelIndex index = countriesListModel->index(row, 0);
    // pobieram obiekt wstawionego indeksu
    //countriesListModel->setData(index, QVariant("*"));

    ui->pushButton->setEnabled(false);
    ui->BtnUrzaZapisz->setEnabled(false);
    ui->comboBox_3->setVisible(false);
}

void Urzadzenia::wypelnijModel()
{
    MainDb *mainDb = new MainDb(this);
    pobierzModelId = mainDb->pobierzModeliD(pobierzModelId);
    for (int i = 1; i <= pobierzModelId; i++) {
        QStringPobierzModel = mainDb->pobierzModel(QStringPobierzModel, i);
        ui->comboBox_2->addItem(QStringPobierzModel);
    }
}

QString Urzadzenia::zMainDb(QString testName)
{
    ui->comboBox->addItem(testName);
    return 0;
}
void Urzadzenia::wypelnijProducenta()
{
    MainDb *mainDb = new MainDb(this);
    pobierzProducentaId = mainDb->pobierzProducentaiD(pobierzProducentaId);
    for (int i = 1; i <= pobierzProducentaId; i++) {
        QStringPobierzProducenta = mainDb->pobierzProducenta(QStringPobierzProducenta, i);
        ui->comboBox->addItem(QStringPobierzProducenta);
    }
}

void Urzadzenia::initMenuUrzadzenia()
{
    //tworze menu kontekstowe
    setWindowTitle("OptiBase v 1.0:Urządzenia");

    //    QAction *fileSave = new QAction(("&Zapisz"), this);
    //    QAction *fileEksport = new QAction(("&Eksport"), this);
    // QAction *fileseparator = new QAction(("----------"), this);
    QAction *fileWyjscie = new QAction(("&Wyjście"), this);

    QAction *edycjaDodajProducenta = new QAction(("Dodaj Producenta"), this);
    QAction *edycjaDodajModel = new QAction(("Dodaj Model"), this);

    //    QAction *editKopiuj = new QAction(("&Kopiuj"), this);
    //    QAction *editWklej = new QAction(("&Wklej"), this);

    QAction *infoOProgramie = new QAction(("&O Programie"), this);
    QAction *infoOAutorze = new QAction(("O &Autorze"), this);
    QAction *infoLog = new QAction(("&Log"), this);

    QAction *settingsOption = new QAction(("&Opcje"), this);

    auto mainfile = menuBar()->addMenu("Plik");
    auto mainEdycja = menuBar()->addMenu("Edycja");
    auto mainInfo = menuBar()->addMenu("Informacje");
    auto mainSettings = menuBar()->addMenu("Ustawienia");

    //    mainfile->addAction(fileSave);
    //    mainfile->addAction(fileEksport);

    mainfile->addSeparator();
    mainfile->addAction(fileWyjscie);

    mainEdycja->addAction(edycjaDodajProducenta);
    mainEdycja->addAction(edycjaDodajModel);

    //    mainEdycja->addAction(editKopiuj);
    //    mainEdycja->addAction(editWklej);
    mainInfo->addAction(infoOProgramie);
    mainInfo->addAction(infoOAutorze);
    mainInfo->addAction(infoLog);

    mainSettings->addAction(settingsOption);

    //connect(settingsOption, &QAction::triggered,this, SLOT (openInfo()));
    connect(settingsOption, SIGNAL(triggered()), this, SLOT(openSettings()));
    connect(infoOProgramie, SIGNAL(triggered()), this, SLOT(openInfo()));
    connect(edycjaDodajProducenta,
            SIGNAL(triggered()),
            this,
            SLOT(on_actionDodaj_Producenta_triggered()));
    connect(edycjaDodajModel, SIGNAL(triggered()), this, SLOT(on_actionDodaj_Model_triggered()));

    // Ikonka check OK /NO
    QString dirPath = "C:/Users/pawel/Documents/Cplusplus/OptiBase/OptiBase/Resources";
    QPixmap pix1(dirPath+ "/YesRed.png");

    ui->lblCheckOkNo->setPixmap(pix1.scaled(ui->lblCheckOkNo->size(),Qt::KeepAspectRatio));// Skaluje pnp do wymierów labela
    // end Ikonka Check Ok/NO
    //**********************************************
}
void Urzadzenia::howMuchDevice()
{
    //qWarning() << "Jestem w Urzadzenia:HowMuchDevice";
    int deviceCount = 0;
    QString QDeviceCount = "";
    MainDb *mainDb = new MainDb(this);

    deviceCount = mainDb->isNumerSeryjnyTheSameId(deviceCount);

    ui->LblNumberAnaliz->setText(QString::number(deviceCount));

    //    if (deviceCount<10)
    //    {
    //        QDeviceCount = "000" + deviceCount;

    //    }
    //    qWarning ()<<"Device równa się "<<QDeviceCount;
    ui->lineEditNumber->setText(QString::number(deviceCount + 1));

    //qWarning() << "Jestem w Urzadzenia:HowMuchDevice:End";
}
void Urzadzenia::myfunctiontimer()
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

Urzadzenia::~Urzadzenia()
{
    delete ui;
}

void Urzadzenia::on_BtnUrzaZapisz_clicked()
{ //ZAPISZ
    QString file3 = "C:/Defaults/Pliki/3.Urzadzenie.txt";
    //cout << "Zapisz" << endl;

    plikUrzadzenia.open(file3.toStdString(), ios::out | ios::app);

    for (int i = 0; i <= ui->comboBox_4->count() - 1; i++) {
        plikUrzadzenia << ui->comboBox_4->itemText(i).toStdString() << endl;
    }

    //plikUrzadzenia << "" << endl; //- Tutuaj wrzucam pustą linię na info o przypsianiu
    plikUrzadzenia.close();
    ui->BtnUrzaZapisz->setEnabled(false);
    // Ikonka check OK /NO
    QString dirPath = "C:/Users/pawel/Documents/Cplusplus/OptiBase/OptiBase/Resources";
    QPixmap pix1(dirPath+ "/CheckOk.png");

    ui->lblCheckOkNo->setPixmap(pix1.scaled(ui->lblCheckOkNo->size(),Qt::KeepAspectRatio));// Skaluje pnp do wymierów labela
    // end Ikonka Check Ok/NO
    //**********************************************
}

void Urzadzenia::on_BtnUrzaZamknij_clicked()
{
    timer->stop();
    iloscUrzadzen = 0;
    checkFlagsVariableProducent =0;
    on_comboBox_highlightedExit(checkFlagsVariableProducent);
    checkFlagsVariableModel =0;
    on_comboBox_2_highlightedExit(checkFlagsVariableModel);
    destroy();
}

void Urzadzenia::on_countriesList_clicked(const QModelIndex &index)
{
    int rowCount = countriesListModel->rowCount();
    countriesListModel->insertRow(rowCount);
    countriesListModel->setData(index, QVariant("Cos innego")); // i ustawiam tekst na "*"

    ui->label_4->setText(zaznaczono + " " + ui->comboBox->currentText());
}

void Urzadzenia::on_comboBox_textActivated(const QString)
{
    ui->label_4->setText("Producent: " + ui->comboBox->currentText());
    ui->label_6->setText("Model: " + ui->comboBox_2->currentText());
    ui->label_7->setText("Numer Seryjny: " + ui->lineEditNrSeryjny->text());
}

void Urzadzenia::on_comboBox_2_textActivated(const QString)
{
    ui->label_4->setText("Producent: " + ui->comboBox->currentText());
    ui->label_6->setText("Model: " + ui->comboBox_2->currentText());
    ui->label_7->setText("Numer Seryjny: " + ui->lineEditNrSeryjny->text());
}

void Urzadzenia::on_comboBox_3_textActivated(const QString)
{
    ui->label_4->setText("Producent: " + ui->comboBox->currentText());
    ui->label_6->setText("Model: " + ui->comboBox_2->currentText());
    ui->label_7->setText("Numer Seryjny: " + ui->lineEditNrSeryjny->text());
}

void Urzadzenia::on_actionDodaj_Model_triggered()
{
    UrzadzeniaDodajModel *urzDodModel = new UrzadzeniaDodajModel(this);
    urzDodModel->show();
}

void Urzadzenia::on_actionDodaj_Producenta_triggered()
{
    UrzadzeniaDodajProducenta *urzDodProd = new UrzadzeniaDodajProducenta(this);
    urzDodProd->show();
}

void Urzadzenia::on_actionDodaj_Numer_Seryjny_triggered()
{
    UrzadzeniaDodajNrSeryjny *urzDodNrSer = new UrzadzeniaDodajNrSeryjny(this);
    urzDodNrSer->show();
}

void Urzadzenia::on_actionInformacja_triggered()
{
    Info *info = new Info(this);
    info->show();
}
//Info do Gita
void Urzadzenia::on_pushButton_clicked() // DODAJ urzadzena do Comboboxa
{
    MainDb *mainDb = new MainDb(this);
    QString nrSeryjnyZLiniText = ui->lineEditNrSeryjny->text();
    QString nrSeryjnyZLini = "";
    QString przypisany = "";
    int nrSeryjnyZLiniId = 0;
    ui->comboBox_3->clear();
    // Dodaj do comboBoxa
    // Sprawdzić czysą takie same numery seryjne juz zapisany i dodawanay
    //-------------------
    //QString file3 = "C:/Defaults/Pliki/3.Urzadzenie.txt";
    //cout << "Dodoaj i sprawdz czy jest taki numer seryjny" << endl;
    //Wczytaj z Bazy i Dodoaj i sprawdz czy jest taki numer seryjny

    //Sprawdzić w bazie czy jest taki numer seryjny

    nrSeryjnyZLiniId = mainDb->isNumerSeryjnyTheSameId(nrSeryjnyZLiniId);

    for (int i = 1; i <= nrSeryjnyZLiniId; i++) {
        nrSeryjnyZLini = mainDb->isNumerSeryjnyTheSame(nrSeryjnyZLini, i);
        ui->comboBox_3->addItem(nrSeryjnyZLini);
        //qDebug() << nrSeryjnyZLini;
    }

    //Najpierw sprawdzam czy linia z numerem seryjnym nie jest pusta

    if (nrSeryjnyZLiniText == "") {
        QMessageBox::information(this,
                                 "Ostrzeżenie",
                                 "Nie możesz pozostawić pustego numeru seryjnego.");

    } else {
        bool IsNrSeryjnySame = false;
        for (int i = 0; i <= ui->comboBox_3->count() - 1; i++) {
            QString nrSeryjny = ui->comboBox_3->itemText(i);

            if (nrSeryjnyZLiniText == nrSeryjny) {
                IsNrSeryjnySame = true;
                i = ui->comboBox_3->count();
                break;
            } else {
                IsNrSeryjnySame = false;
            }
        }
        if (IsNrSeryjnySame == true) {
            QMessageBox::information(this,
                                     "Ostrzeżenie",
                                     "Analizator o takim numerze seryjnym już jest w bazie");
        } else {
            //cout << "Dodaje i zapisuje" << endl;

            ui->BtnUrzaZapisz->setEnabled(false);
            //-----------------

            QString dodajNapis = ui->lineEditNumber->text();
            QString dodajNapis1 = "[IdUrzadzenia:" + dodajNapis + "]";
            ui->comboBox_4->addItem(dodajNapis1);

            ui->comboBox_4->addItem(ui->comboBox->currentText());
            ui->comboBox_4->addItem(ui->comboBox_2->currentText());
            ui->comboBox_4->addItem(ui->lineEditNrSeryjny->text());
            ui->comboBox_4->addItem(""); // pusta linia do przypisania
            ui->BtnUrzaZapisz->setEnabled(true);
            ui->pushButton->setEnabled(false);
            ui->label_4->setText("Producent: " + ui->comboBox->currentText());
            ui->label_6->setText("Model: " + ui->comboBox_2->currentText());
            ui->label_7->setText("Numer Seryjny: " + ui->lineEditNrSeryjny->text());
            //Wysyłam do bazy w celu zapisania
            QString daneModel = "", daneProducent, daneNrSeryjny;
            int iloscElementowWcombo;
            iloscElementowWcombo = ui->comboBox_4->count();
            int i = 1;
            //for (int i =1;i<=iloscElementowWcombo -1;i++)
            {
                daneProducent = ui->comboBox_4->itemText(i);
                daneModel = ui->comboBox_4->itemText(i + 1);
                daneNrSeryjny = ui->comboBox_4->itemText(i + 2);
                if (ui->checkBox->isChecked())
                {
                    cout<<"Checkbox Dodaj do mazgazuny zaznaczony"<<endl;
                     mainDb->addUrzadzenia(daneProducent, daneModel, daneNrSeryjny, przypisany);
                    mainDb->addUrzadzeniaUpdate(daneNrSeryjny,"MAGAZYN");
                }
                else
                {
                mainDb->addUrzadzenia(daneProducent, daneModel, daneNrSeryjny, przypisany);
                }
            }
        }
    }
    QString dirPath = "C:/Users/pawel/Documents/Cplusplus/OptiBase/OptiBase/Resources";
    QPixmap pix1(dirPath+ "/YesYellow.png");

    ui->lblCheckOkNo->setPixmap(pix1.scaled(ui->lblCheckOkNo->size(),Qt::KeepAspectRatio));//Skaluje pnp do wymierów labela
}
void Urzadzenia::on_actionOpcje_triggered()
{
    Ustawienia *ustaw = new Ustawienia(this);
    ustaw->show();
}
void Urzadzenia::on_comboBox_highlightedExit(int checkFlagsVariableProducent)
{
    MainDb *mainDb = new MainDb(this);
    checkFlagsVariableProducent = mainDb->checkFlagsProducentInsert1(checkFlagsVariableProducent);
    //cout <<"checkFlagsVariableProducent o zmianue";
    // cout<<checkFlagsVariableProducent<<endl;
}
void Urzadzenia::on_comboBox_highlighted(const QString)
{
    MainDb *mainDb = new MainDb(this);
    // Odswiiez producenta

    checkFlagsVariableProducent = mainDb->checkFlagsProducent(checkFlagsVariableProducent);
    if (checkFlagsVariableProducent == 0) {




        QStringList listaProducent = QStringList();

        ui->comboBox->clear();
        //wczytajProducenta();
        wypelnijProducenta();
        int ostatniindex = ui->comboBox->count() - 1;
        for (int iZmienna = 0; iZmienna <= ostatniindex; iZmienna++) {
            listaProducent.push_back(ui->comboBox->itemText(iZmienna).toUtf8());
        }
        sort(listaProducent.begin(), listaProducent.end());
        ui->comboBox->clear();
        for (int kZmienna = 0; kZmienna <= listaProducent.count() - 1; kZmienna++) {
            ui->comboBox->addItem(listaProducent.at(kZmienna));
        }
        checkFlagsVariableProducent =1;
        on_comboBox_highlightedExit(checkFlagsVariableProducent);
    }
}
void Urzadzenia::wczytajProducenta()
{
    wypelnijProducenta();
}
void Urzadzenia::wczytajModel()
{
    wypelnijModel();
}
void Urzadzenia::on_comboBox_2_highlighted(const QString)
{
    // odwiez model.
    //cout <<"1"<<endl;
    //    fstream checkFlags;
    //    QString file17 = "17.CheckFlagsInModelUrzadzenia.txt";
    //    CheckFiles *checkFiles = new CheckFiles(this);
    //cout <<"2"<<endl;
    //    checkFlagsVariableModel = checkFiles->checkFlagsModel(checkFlagsVariableModel);
    //cout <<"3"<<endl;
    //cout <<checkFlagsVariableModel<<endl;

    MainDb *mainDb = new MainDb(this);
    checkFlagsVariableModel = mainDb->checkFlagsModel(checkFlagsVariableModel);
    if (checkFlagsVariableModel == 0) {
        // cout << "textHighlighted odswierzam /model" << endl;
        QStringList listaModel = QStringList();

        ui->comboBox_2->clear();
        // cout <<"4"<<endl;
        //wczytajModel();
        wypelnijModel();
        //  cout <<"5"<<endl;
        int ostatniindex = ui->comboBox_2->count() - 1;
        for (int iZmienna = 0; iZmienna <= ostatniindex; iZmienna++) {
            listaModel.push_back(ui->comboBox_2->itemText(iZmienna).toUtf8());
        }
        //  cout <<"6"<<endl;
        sort(listaModel.begin(), listaModel.end());
        ui->comboBox_2->clear();
        for (int kZmienna = 0; kZmienna <= listaModel.count() - 1; kZmienna++) {
            ui->comboBox_2->addItem(listaModel.at(kZmienna));
        }
        checkFlagsVariableModel =1;
        on_comboBox_2_highlightedExit(checkFlagsVariableModel);
    }
    //    cout <<"7"<<endl;
    //    checkFlags.open(file17.toStdString(), ios::out | ios::trunc);
    //    checkFlags << "0" << endl;
    //    checkFlags.close();
    ui->pushButton->setEnabled(true);
    //    cout <<"8 End"<<endl;
}
void Urzadzenia::on_comboBox_2_highlightedExit(int checkFlagsVariableModel)
{
    MainDb *mainDb = new MainDb(this);
    checkFlagsVariableModel = mainDb->checkFlagsModelInsert1(checkFlagsVariableModel);
    // cout <<"checkFlagsVariableProducent o zmianue";
    //  cout<<checkFlagsVariableModel<<endl;
}
void Urzadzenia::openInfo()
{
    Info *info = new Info(this);
    info->show();
}
void Urzadzenia::openSettings()
{
    Ustawienia *ustaw = new Ustawienia(this);
    ustaw->show();
}


void Urzadzenia::on_pushButton_2_clicked() // seryjnie
{
UrzadzeniaDodajSeryjnie *urzDoSe = new UrzadzeniaDodajSeryjnie (this);

urzDoSe ->show ();

}
