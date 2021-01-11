#include "kontrahentinfododajwpis.h"
#include "Timery/timedate.h"
#include "DataBase/maindb.h"
#include "iostream"
#include "time.h"
#include "ui_kontrahentinfododajwpis.h"
#include <fstream>
#include <QTableView>
#include <QTimer>
#include <QDebug>
#include <random>
#include <iterator>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>


using namespace std;

time_t czas;
tm timeinfo;
QString qStrMin, qStrGodz, qStrSek, qStrDzien, qStrMiesiac, stringDzienTygodnia;
int godzina;
int minuta;
int sekunda;
int dzien, dzienKolejny;
int miesiac, miesiacKolejny;
int rok, rokKolejny;
int dzienTygodnia;
int idWpisu = 1002;

fstream fileWpis;
bool przypomnienie = false;
string przypomnienieId;

KontrahentInfoDodajWpis::KontrahentInfoDodajWpis(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KontrahentInfoDodajWpis)
{
    ui->setupUi(this);
    //---------Sekcja generacji timera
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myfunctiontimer()));
    timer->start(1000);
    //===================
    uncheckedCheckBox();
    init();
    ui->comboBox->setCurrentIndex(-1);
    initMenu();

}
void KontrahentInfoDodajWpis::initMenu()
{
    setWindowTitle("OptiBase v 1.0: Urzadzenia - Dodaj wpis o urzadzeniu");
}

void KontrahentInfoDodajWpis::setDate()
{
    //Pousawiaj date do obrówki
}
void KontrahentInfoDodajWpis::checkedCheckBox()
{
    //Checked CheckBox
    //cout << "Zaznaczony" << endl;
    ui->comboBox->setVisible(true);
    ui->textEdit_2->setVisible(true);
    ui->label_10->setVisible(true);
    ui->label_11->setVisible(true);
    ui->label_9->setVisible(true);
}
void KontrahentInfoDodajWpis::uncheckedCheckBox()
{
    //Unchecked CheckBox
    //cout << "Nie zazanaczony" << endl;
    ui->comboBox->setVisible(false);
    ui->textEdit_2->setVisible(false);
    ui->label_10->setVisible(false);
    ui->label_11->setVisible(false);
    ui->label_9->setVisible(false);
}

KontrahentInfoDodajWpis::~KontrahentInfoDodajWpis()
{
    delete ui;
}

void KontrahentInfoDodajWpis::on_pushButton_2_clicked()
{
    //Zapisz

    // Dojdz do bazy i zapisz w bazie dane z kontrahent dodaj wpis

    MainDb *mainDb = new MainDb (this);
    QString przypomnienieTemp;
    QString nrWpisu = ui->label_2->text();
    QString dataWpisu = ui->label_4->text() + ui->label_5->text() + ui->label_6->text();
    QString tematWpisu = ui->lineEdit->text();
    QString trescWpisu = ui->textEdit->toPlainText();
    if (ui->checkBox->isChecked()==true)
    {
        przypomnienieTemp = "TAK";
    }
    else
    {
        przypomnienieTemp = "NIE";
    }
    QString przypomnienie = przypomnienieTemp;
    QString dataNajblPrzypom = ui->label_11->text();
    QString tekstPrzypom = ui->textEdit_2->toPlainText();
    QString nrSeryjny = ui->label_12->text();


    mainDb->addPrzypomnienie(nrWpisu, dataWpisu,tematWpisu,trescWpisu,przypomnienie,dataNajblPrzypom,tekstPrzypom,nrSeryjny );



//    QString IdUrzKont = ui->label_12->text() + ui->label_13->text();
//    if (przypomnienie ==true)
//    {
//        przypomnienieId ="True";
//    }
//    else
//    {ui->comboBox->setCurrentIndex(-1);
//        przypomnienieId="false";
//    }

//    QString file18 = "C:/Defaults/Pliki/18.WpisKontrahentInfo.txt";
//    fileWpis.open(file18.toStdString(), ios::out | ios::app);
//    fileWpis << "{#NrWpisu# " + ui->label_2->text().toStdString() + "}" << endl;
//    fileWpis << "{#IdUrzadzenia# " + IdUrzKont.toStdString() + "}"<<endl;
//    fileWpis << "{#Data: Rok# " + ui->label_4->text().toStdString() + "}" << endl;
//    fileWpis << "{#Data: Miesiac# " + ui->label_5->text().toStdString() + "}" << endl;
//    fileWpis << "{#Data: Dzien# " + ui->label_6->text().toStdString() + "}" << endl;
//    fileWpis << "{#Temat# " + ui->lineEdit->text().toStdString() + "}" << endl;
//    fileWpis << "{#Tresc# " + ui->textEdit->toPlainText().toStdString() + "}" << endl;
//    //ui->textEdit->ge

//    fileWpis <<"{#Przypomnienie# " +przypomnienieId +"}" <<endl;
//    fileWpis <<"{#Czestotliwosc# " +ui->comboBox->currentText().toStdString()+"}"<<endl;
//    fileWpis <<"{#DataPrzypomnienia# " +ui->label_11->text().toStdString()+"}"<<endl;
//    fileWpis <<"{#TrescPrzypomnienia# " +ui->textEdit_2->toPlainText().toStdString()+"}"<<endl;
//    fileWpis.close();
}

void KontrahentInfoDodajWpis::on_pushButton_clicked()
{
    //Zamknij
    timer->stop();
    destroy();
}
void KontrahentInfoDodajWpis::init()
{MainDb *mainDb = new MainDb (this);
    cout << "Jstem w show" << endl;
    TimeDate *timeDate = new TimeDate();
    QString nrWpisu;
    //myfunctiontimerDoDaty(godzina,minuta,sekunda,dzien,miesiac,rok,dzienTygodnia);
    time(&czas);
    timeinfo = *localtime(&czas);
    godzina = timeinfo.tm_hour;
    minuta = timeinfo.tm_min;
    sekunda = timeinfo.tm_sec;
    dzien = timeinfo.tm_mday;
    miesiac = timeinfo.tm_mon;
    rok = timeinfo.tm_year;
    dzienTygodnia = timeinfo.tm_wday;
    miesiac = miesiac + 1;
    rok = rok + 1900;
    dzienTygodnia = dzienTygodnia + 1;

    qStrMin = timeDate->changeStringsMin(minuta);
    qStrSek = timeDate->changeStringsSek(sekunda);
    qStrDzien = timeDate->changeStringsDzien(dzien);
    qStrGodz = timeDate->changeStringsGodz(godzina);
    qStrMiesiac = timeDate->changeStringsMiesiac(miesiac);
    //stringDzienTygodnia = timeDate->changeStringsDzienTygodnia(dzienTygodnia);

    idWpisu = rand() %1000000 +1;
//TODO: nowa funkcja wczytująca numer wpisu.
    //Wyodrebnic koncówke
    // zaminic na int
    // dodac kolejny numer
    // zapisac całosc.

    QString QnrWpisu;
    QnrWpisu = mainDb ->pobierzNumerWpisu(QnrWpisu);
//QnrWpisu = mainDb ->pobierzNumerWpisu(QnrWpisu.toUtf8().constData());
    qWarning ()<< "KontrahentInfododoajWpis::QNumr wpsiu rowna się " <<QnrWpisu;

    string str0 = QnrWpisu.toStdString();
    std::string str1 = str0.substr (0,3);
    std::string str2 = str0.substr (5,2);
    std::string str3 = str0.substr (0,4);
    std::string str4 = str0.substr (11,4);

    qWarning ()<< str4.c_str();
    int IntNrwpisu = atoi(str4.c_str());
    IntNrwpisu++;



    nrWpisu = QString::number(rok) + "/" + qStrMiesiac + "/" + qStrDzien + "/"
              + QString::number(IntNrwpisu);
    ui->label_2->setText(nrWpisu);
    ui->label_4->setText(QString::number(rok));
    ui->label_5->setText(qStrMiesiac);
    ui->label_6->setText(qStrDzien);
}

void KontrahentInfoDodajWpis::on_checkBox_stateChanged(int arg1)
{
    //CheckBox zmiania

    if (arg1 == 2) //if (ui->checkBox->isChecked())
    {              //Zaznaczony

        checkedCheckBox();
        przypomnienie = true;
        //cout << "Arg: " << arg1 << endl;

    } else if (arg1 == 0) {
        //Niezaznaczony
        przypomnienie = false;
        uncheckedCheckBox();
        ui->comboBox->setCurrentIndex(-1);
        //cout << "Arg: " << arg1 << endl;
    }
}
void KontrahentInfoDodajWpis::myfunctiontimer()
{
    //  //  time_t czas;
    //    tm timeinfo;
    //    QString qStrMin, qStrGodz, qStrSek, qStrDzien, qStrMiesiac, stringDzienTygodnia;

    TimeDate *timeDate = new TimeDate();
    //myfunctiontimerDoDaty(godzina,minuta,sekunda,dzien,miesiac,rok,dzienTygodnia);
    time(&czas);
    timeinfo = *localtime(&czas);
    godzina = timeinfo.tm_hour;
    minuta = timeinfo.tm_min;
    sekunda = timeinfo.tm_sec;
    dzien = timeinfo.tm_mday;
    miesiac = timeinfo.tm_mon;
    rok = timeinfo.tm_year;
    dzienTygodnia = timeinfo.tm_wday;
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

//int KontrahentInfoDodajWpis::myfunctiontimerDoDaty(int godzina, int minuta,int sekunda,int dzien,int miesiac,int rok,int dzienTygodnia)
//{TimeDate *timeDate = new TimeDate();
//    time(&czas);
//    timeinfo = *localtime(&czas);
//    godzina = timeinfo.tm_hour;
//    minuta = timeinfo.tm_min;
//    sekunda = timeinfo.tm_sec;
//    dzien = timeinfo.tm_mday;
//    miesiac = timeinfo.tm_mon;
//    rok = timeinfo.tm_year;
//    dzienTygodnia = timeinfo.tm_wday;
//    miesiac = miesiac + 1;
//    rok = rok + 1900;
//    dzienTygodnia = dzienTygodnia + 1;
//    qStrMin = timeDate->changeStringsMin(minuta);
//    qStrSek = timeDate->changeStringsSek(sekunda);
//    qStrDzien = timeDate->changeStringsDzien(dzien);
//    qStrGodz = timeDate->changeStringsGodz(godzina);
//    qStrMiesiac = timeDate->changeStringsMiesiac(miesiac);
//    stringDzienTygodnia = timeDate->changeStringsDzienTygodnia(dzienTygodnia);
//}
void KontrahentInfoDodajWpis::on_comboBox_currentTextChanged(const QString ) //(const QString &arg1)
{dzienKolejny = dzien;
    miesiacKolejny = miesiac;
    rokKolejny=rok;

    if (ui->comboBox->currentText().toStdString()=="Co 1 dzień")
    {
        cout<<"Co 1 dzień"<<endl;
        //Dodac do dnia 1 dzien. Jezeli wychodzi po za miesiac to dodoac mc

        dzienKolejny = dzienKolejny+1;
        cout<<"Plus 1 dzien"<<dzien<<endl;
    }
    if (ui->comboBox->currentText().toStdString()=="Co tydzień")
    {
        cout<<"Co tydzien"<<endl;
        dzienKolejny = dzienKolejny+7;
        cout<<"Plus tydzien"<<dzien<<endl;
    }
    if (ui->comboBox->currentText().toStdString()=="Co miesiąc")
    {
        cout<<"Co miesiac"<<endl;
        miesiacKolejny = miesiacKolejny+1;
        if (miesiacKolejny>12)
        {
            miesiacKolejny =1;
            rokKolejny++;
        }
        cout<<"Plus 1 mc"<<miesiac<<endl;
    }
    if (ui->comboBox->currentText().toStdString()=="Co rok")
    {
        cout<<"Co rok"<<endl;
        rokKolejny=rokKolejny+1;
        cout<<"Plus 1 rok"<<rok<<endl;
    }
    dodajDateKolejnegoWpisu(dzienKolejny, miesiacKolejny, rokKolejny);
}

int KontrahentInfoDodajWpis::dodajDateKolejnegoWpisu(int dzienKolejny, int miesiacKolejny, int rokKolejny)
{
    //label_11 -> data najbizeszego przypomnienia
    QString QrokKolejny = QString::number(rokKolejny);
    QString QmiesiacKolejny = QString::number(miesiacKolejny);
    QString QdzienKolejny = QString::number(dzienKolejny);
    ui->label_11->setText(QrokKolejny + ":"+ QmiesiacKolejny+":"+QdzienKolejny);
    return 0;
}
QString KontrahentInfoDodajWpis::setSettingsId(QString NrSeryjny )
{
    ui->label_12->setText(NrSeryjny);
    //ui->label_13->setText(IdKontr);
    return 0;
}
void KontrahentInfoDodajWpis::on_comboBox_currentIndexChanged(const QString &arg1)
{
    //Zmiana daty przypomnienia
    qWarning ()<<"Zmiana na : " <<ui->comboBox->currentText();
}
