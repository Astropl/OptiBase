#include "kontrahentinfododajwpis.h"
#include "DataBase/maindb.h"
#include "Info/info.h"
#include "Timery/timedate.h"
#include "Ustawienia/statystyki.h"
#include "Ustawienia/ustawienia.h"
#include "ui_kontrahentinfododajwpis.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <random>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>
#include <QDebug>
#include <QTableView>
#include <QTimer>
#include <QMessageBox>
#include <QInputDialog>
#include <QLineEdit>

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
QString dataWpisu;
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
    loadInfoOTemacie();
    dataWpisu = ui->label_4->text() + "/" + ui->label_5->text() + "/" + ui->label_6->text()
            + " | " + ui->label_14->text();
}

void KontrahentInfoDodajWpis::loadInfoOTemacie()
{
    MainDb *mainDb = new MainDb(this);
    //Sprawwdz ile jest wpisów w bazie
    //dodoaj do comboBox_2
    int iloscTematow =0;
    QString qIloscTematow ="";
    iloscTematow = mainDb->pobierzIloscTematowiD(iloscTematow);

    //qDebug()<<"Info o ilosci wpisów do Tematu: "<< iloscTematow;
    for(int i=1;i<=iloscTematow;i++)
    {

        qIloscTematow =  mainDb->pobierzIloscTematow(qIloscTematow,i);
        //qDebug()<<"Info o ilosci wpisów do Tematu: "<< iloscTematow<<" i teamt to: "<<qIloscTematow;
        ui->comboBox_2->addItem(qIloscTematow);
    }
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
    ui->checkBox_2->setVisible(true);
    ui->checkBox_3->setVisible(true);
    ui->checkBox_4->setVisible(true);
    ui->checkBox_5->setVisible(true);
    ui->checkBox_6->setVisible(true);
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
    ui->checkBox_2->setVisible(false);
    ui->checkBox_3->setVisible(false);
    ui->checkBox_4->setVisible(false);
    ui->checkBox_5->setVisible(false);
    ui->checkBox_6->setVisible(false);
}

KontrahentInfoDodajWpis::~KontrahentInfoDodajWpis()
{
    delete ui;
}

void KontrahentInfoDodajWpis::on_pushButton_2_clicked()
{
    //Zapisz

    // Dojdz do bazy i zapisz w bazie dane z kontrahent dodaj wpis

    MainDb *mainDb = new MainDb(this);
    QString przypomnienieTemp;
    QString dataNajblPrzypom;
    QString nrWpisu = ui->label_2->text();
    dataWpisu = ui->label_4->text() + "/" + ui->label_5->text() + "/" + ui->label_6->text()
            + " | " + ui->label_14->text();
    QString tematWpisu = ui->label_15->text();
    //QString tematWpisu = "tempoczasowy";
    //TODO: Zamienic teamt wpisu na prawdziwy temat z comboBoxa_2
    QString trescWpisu = ui->textEdit->toPlainText();
    //QString dataNajblPrzypom = ui->label_11->text();
    if (ui->checkBox->isChecked() == true) {
        przypomnienieTemp = "TAK";
        //qWarning ()<<"Data przypomnieniea TAK";
        dataNajblPrzypom = ui->label_11->text();
    } else {
        przypomnienieTemp = "NIE";
        ui->label_11->setText("BRAK");
        //qWarning ()<<"Data przypomnieniea NIE";
        dataNajblPrzypom = ui->label_11->text();
    }

    QString przypomnienie = przypomnienieTemp;

    QString tekstPrzypom = ui->textEdit_2->toPlainText();
    QString nrSeryjny = ui->label_12->text();
    //qWarning() << "Data przypomnieniea NIE i wydruk zniej " << dataNajblPrzypom;

    mainDb->addPrzypomnienie(nrWpisu,
                             dataWpisu,
                             tematWpisu,
                             trescWpisu,
                             przypomnienie,
                             dataNajblPrzypom,
                             tekstPrzypom,
                             nrSeryjny);
    QString dirPath = "C:/Users/pawel/Documents/Cplusplus/OptiBase/OptiBase/Resources";
    QPixmap pix1(dirPath+ "/CheckOk.png");

    ui->lblCheckOkNo->setPixmap(pix1.scaled(ui->lblCheckOkNo->size(),Qt::KeepAspectRatio));// Skaluje pnp do wymierów labela
}

void KontrahentInfoDodajWpis::on_pushButton_clicked()
{
    //Zamknij
    timer->stop();
    destroy();
}
void KontrahentInfoDodajWpis::init()
{
    MainDb *mainDb = new MainDb(this);
    //cout << "Jstem w show" << endl;
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

    //idWpisu = rand() %1000000 +1;
    //TODO: nowa funkcja wczytująca numer wpisu.
    //Wyodrebnic koncówke
    // zaminic na int
    // dodac kolejny numer
    // zapisac całosc.

    ui->label_14->setText(qStrGodz + ":" + qStrMin);
    QString QnrWpisu;
    QnrWpisu = mainDb->pobierzNumerWpisu(QnrWpisu);
    //QnrWpisu = mainDb ->pobierzNumerWpisu(QnrWpisu.toUtf8().constData());
    //qWarning() << "KontrahentInfododoajWpis::QNumr wpsiu rowna się " << QnrWpisu;

    string str0 = QnrWpisu.toStdString();
    std::string str1 = str0.substr(0, 3);
    std::string str2 = str0.substr(5, 2);
    std::string str3 = str0.substr(0, 4);
    std::string str4 = str0.substr(11, 4);

    //qWarning() << str4.c_str();
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

void KontrahentInfoDodajWpis::on_comboBox_currentTextChanged(const QString) //(const QString &arg1)
{
    dzienKolejny = dzien;
    miesiacKolejny = miesiac;
    rokKolejny = rok;

    if (ui->comboBox->currentText().toStdString() == "Co 1 dzień") {
        cout << "Co 1 dzień" << endl;
        //Dodac do dnia 1 dzien. Jezeli wychodzi po za miesiac to dodoac mc

        dzienKolejny = dzienKolejny + 1;
        if (dzienKolejny >= 30) {
            dzienKolejny = 1;
            miesiacKolejny++;
        }
        cout << "Plus 1 dzien" << dzien << endl;
    }
    if (ui->comboBox->currentText().toStdString() == "Co tydzień") {
        cout << "Co tydzien" << endl;
        dzienKolejny = dzienKolejny + 7;
        if (dzienKolejny >= 30) {
            int tempData = 0;
            tempData = dzienKolejny + 7 - 30;
            dzienKolejny = 1 + tempData;
            miesiacKolejny++;
        }
        cout << "Plus tydzien" << dzien << endl;
    }
    if (ui->comboBox->currentText().toStdString() == "Co miesiąc") {
        cout << "Co miesiac" << endl;
        miesiacKolejny = miesiacKolejny + 1;
        if (miesiacKolejny > 12) {
            miesiacKolejny = 1;
            rokKolejny++;
        }
        cout << "Plus 1 mc" << miesiac << endl;
    }
    if (ui->comboBox->currentText().toStdString() == "Co rok") {
        cout << "Co rok" << endl;
        rokKolejny = rokKolejny + 1;
        cout << "Plus 1 rok" << rok << endl;
    }
    dodajDateKolejnegoWpisu(dzienKolejny, miesiacKolejny, rokKolejny);
}

int KontrahentInfoDodajWpis::dodajDateKolejnegoWpisu(int dzienKolejny,
                                                     int miesiacKolejny,
                                                     int rokKolejny)
{
    TimeDate *timeDate = new TimeDate();

    qStrDzien = timeDate->changeStringsDzien(dzienKolejny);

    qStrMiesiac = timeDate->changeStringsMiesiac(miesiacKolejny);

    QString nrWpisuKolejnego;
    nrWpisuKolejnego = QString::number(rokKolejny) + "/" + qStrMiesiac + "/" + qStrDzien;

    ui->label_11->setText(nrWpisuKolejnego);
    return 0;
}
QString KontrahentInfoDodajWpis::setSettingsId(QString NrSeryjny)
{
    ui->label_12->setText(NrSeryjny);

    return 0;
}
void KontrahentInfoDodajWpis::on_comboBox_currentIndexChanged(const QString)
{
    //Zmiana daty przypomnienia
    //qWarning() << "Zmiana na : " << ui->comboBox->currentText();

}

void KontrahentInfoDodajWpis::initMenu()
{
    //tworze menu kontekstowe
    //setWindowTitle("OptiBase v 1.0:Kontrahent - Informacje o Kontrahencie");
    setWindowTitle("OptiBase v 1.0: Urzadzenia - Dodaj wpis o urzadzeniu");
    //    QAction *fileSave = new QAction(("&Zapisz"), this);
    //    QAction *fileEksport = new QAction(("&Eksport"), this);
    // QAction *fileseparator = new QAction(("----------"), this);
    QAction *fileWyjscie = new QAction(("&Wyjście"), this);

    QAction *edycjaDodajInfoTemat = new QAction(("Dodaj Info o Temacie"), this);
    //    QAction *edycjaDodajModel = new QAction(("Dodaj Model"), this);

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

    mainEdycja->addAction(edycjaDodajInfoTemat);
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

    connect(edycjaDodajInfoTemat, SIGNAL(triggered()), this, SLOT(openDodajTemat()));

    //    connect(edycjaDodajProducenta,
    //            SIGNAL(triggered()),
    //            this,
    //            SLOT(on_actionDodaj_Producenta_triggered()));
    //    connect(edycjaDodajModel, SIGNAL(triggered()), this, SLOT(on_actionDodaj_Model_triggered()));

    //QIcon iconOk;
    //.*********************************************
    // Ikonka check OK /NO
    QString dirPath = "C:/Users/pawel/Documents/Cplusplus/OptiBase/OptiBase/Resources";
    QPixmap pix1(dirPath+ "/CheckFalse.png");

    ui->lblCheckOkNo->setPixmap(pix1.scaled(ui->lblCheckOkNo->size(),Qt::KeepAspectRatio));// Skaluje pnp do wymierów labela
    // end Ikonka Check Ok/NO
    //**********************************************

}


void KontrahentInfoDodajWpis::openDodajTemat()
{ //QMessageBox msgBox;
    //qDebug() << "Info o temacie";
    //QMasage box. info i dodoajemy do bazy

    //    //QMessageBox::question(this,
    //                             "Ostrzeżenie",
    //                             "Ten Kraj już znajduj się na liście.");
    //    //***********************************
    //    // QDialogBox???
    MainDb *mainDb = new MainDb(this);
    bool ok;
    QString infoTemat = QInputDialog::getText(0, "Wprowadź nowy temat", "Wprowadź nowy temat", QLineEdit::Normal,"",&ok);
    if (ok && !infoTemat.isEmpty())
    {
        //qDebug()<<"Cos jest";
        // qDebug()<<infoTemat;
        ui->comboBox_2->addItem(infoTemat);
        mainDb->dodajIloscTematow(infoTemat);
    }
    else
    {
        // qDebug()<<"pusrt";
        // qDebug()<<infoTemat;
        QMessageBox::information(this,
                                 "Ostrzeżenie",
                                 "Nie wprowaziłes żadnego tematu.");
    }
    ui->label_15->setText("Temat: "+infoTemat);
}

void KontrahentInfoDodajWpis::openInfo()
{
    Info *info = new Info(this);
    info->show();
}
void KontrahentInfoDodajWpis::openSettings()
{
    Ustawienia *ustaw = new Ustawienia(this);
    ustaw->show();
}

void KontrahentInfoDodajWpis::on_comboBox_2_textActivated(const QString )
{
    ui->label_15->setText("Temat: "+ui->comboBox_2->currentText());
    QString aktualData = "";
    ui->textEdit->setPlainText(ui->comboBox_2->currentText() + ": " +dataWpisu);
}



void KontrahentInfoDodajWpis::on_pushButton_3_clicked() // Dodoaj Przypomnienie
{




}

void KontrahentInfoDodajWpis::on_pushButton_4_clicked() //Wyczysc Przypomnienie
{
    ui->textEdit_2->clear();
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox_4->setChecked(false);
    ui->checkBox_5->setChecked(false);
    ui->checkBox_6->setChecked(false);
}

void KontrahentInfoDodajWpis::on_pushButton_5_clicked()
{
    ui->textEdit->clear();
}

void KontrahentInfoDodajWpis::on_checkBox_2_stateChanged()
{
    // Przypomnienie: Przegląd techniczny
    if (ui->checkBox_2->isChecked())
    {QString getTextFromTextEdit=": Przegląd Techniczny\n";
        //QString getTextFromTextEditWithData=dataWpisu;
        cout<<"zaznaczony"<<endl;
        getTextFromTextEdit = dataWpisu+getTextFromTextEdit;
        addTextEdit2(getTextFromTextEdit);
        // ui->textEdit_2->setPlainText("Przegląd Techniczny: ");
    }
    else
    {
        cout<<"NIE zaznaczony"<<endl;
    }

}

QString KontrahentInfoDodajWpis::addTextEdit2(QString getTextFromTextEdit)
{
    QString allTexTEdit;
    allTexTEdit = ui->textEdit_2->toPlainText();
    ui->textEdit_2->clear();
    ui->textEdit_2->setPlainText(allTexTEdit + getTextFromTextEdit);
    return 0;

}

void KontrahentInfoDodajWpis::on_checkBox_4_stateChanged()
{
    // Przypomnienie: Koniec Gwarancji
    if (ui->checkBox_4->isChecked())
    {QString getTextFromTextEdit=": Koniec Gwarancji\n";
        //QString getTextFromTextEditWithData=dataWpisu;
        cout<<"zaznaczony"<<endl;
        getTextFromTextEdit = dataWpisu+getTextFromTextEdit;
        addTextEdit2(getTextFromTextEdit);
        cout<<"zaznaczony"<<endl;
        // ui->textEdit_2->setPlainText("Koniec Gwarancji: ");
    }
    else
    {
        cout<<"NIE zaznaczony"<<endl;
    }
}

void KontrahentInfoDodajWpis::on_checkBox_5_stateChanged()
{
    // Przypomnienie: Wysłac
    if (ui->checkBox_5->isChecked())
    {QString getTextFromTextEdit=": Wysłać\n";
        //QString getTextFromTextEditWithData=dataWpisu;
        cout<<"zaznaczony"<<endl;
        getTextFromTextEdit = dataWpisu+getTextFromTextEdit;
        addTextEdit2(getTextFromTextEdit);
        cout<<"zaznaczony"<<endl;
        // ui->textEdit_2->setPlainText("Wysłać: ");
    }
    else
    {
        cout<<"NIE zaznaczony"<<endl;
    }
}

void KontrahentInfoDodajWpis::on_checkBox_6_stateChanged()
{
    // Przypomnienie: Odebrać od klienta
    if (ui->checkBox_6->isChecked())
    {QString getTextFromTextEdit=": Odebrać od klienta\n";
        //QString getTextFromTextEditWithData=dataWpisu;
        cout<<"zaznaczony"<<endl;
        getTextFromTextEdit = dataWpisu+getTextFromTextEdit;
        addTextEdit2(getTextFromTextEdit);
        cout<<"zaznaczony"<<endl;
        //ui->textEdit_2->setPlainText("Odebrać od klienta: ");
    }
    else
    {
        cout<<"NIE zaznaczony"<<endl;
    }
}

void KontrahentInfoDodajWpis::on_checkBox_3_stateChanged()
{
    // Przypomnienie: Inne
    if (ui->checkBox_3->isChecked())
    {QString getTextFromTextEdit=": Inne\n";
        //QString getTextFromTextEditWithData=dataWpisu;
        cout<<"zaznaczony"<<endl;
        getTextFromTextEdit = dataWpisu+getTextFromTextEdit;
        addTextEdit2(getTextFromTextEdit);
        cout<<"zaznaczony"<<endl;
        //ui->textEdit_2->setPlainText("Inne: ");
    }
    else
    {
        cout<<"NIE zaznaczony"<<endl;
    }
}
