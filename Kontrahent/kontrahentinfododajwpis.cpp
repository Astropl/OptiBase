#include "kontrahentinfododajwpis.h"
#include "Timery/timedate.h"
#include "iostream"
#include "time.h"
#include "ui_kontrahentinfododajwpis.h"
#include <fstream>
#include <QTableView>
#include <QTimer>

using namespace std;

time_t czas;
tm timeinfo;
QString qStrMin, qStrGodz, qStrSek, qStrDzien, qStrMiesiac, stringDzienTygodnia;
int godzina;
int minuta;
int sekunda;
int dzien;
int miesiac;
int rok;
int dzienTygodnia;
int idWpisu = 1000;

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
    QString IdUrzKont = ui->label_12->text() + ui->label_13->text();
    if (przypomnienie ==true)
    {
        przypomnienieId ="True";
    }
    else
    {ui->comboBox->setCurrentIndex(-1);
        przypomnienieId="false";
    }

    QString file18 = "C:/Defaults/Pliki/18.WpisKontrahentInfo.txt";
    fileWpis.open(file18.toStdString(), ios::out | ios::app);
    fileWpis << "{#NrWpisu# " + ui->label_2->text().toStdString() + "}" << endl;
    fileWpis << "{#IdUrzadzenia# " + IdUrzKont.toStdString() + "}"<<endl;
    fileWpis << "{#Data: Rok# " + ui->label_4->text().toStdString() + "}" << endl;
    fileWpis << "{#Data: Miesiac# " + ui->label_5->text().toStdString() + "}" << endl;
    fileWpis << "{#Data: Dzien# " + ui->label_6->text().toStdString() + "}" << endl;
    fileWpis << "{#Temat# " + ui->lineEdit->text().toStdString() + "}" << endl;
    fileWpis << "{#Tresc# " + ui->textEdit->toPlainText().toStdString() + "}" << endl;
    //ui->textEdit->ge

    fileWpis <<"{#Przypomnienie# " +przypomnienieId +"}" <<endl;
    fileWpis <<"{#Czestotliwosc# " +ui->comboBox->currentText().toStdString()+"}"<<endl;
    fileWpis <<"{#DataPrzypomnienia# " +ui->label_11->text().toStdString()+"}"<<endl;
    fileWpis <<"{#TrescPrzypomnienia# " +ui->textEdit_2->toPlainText().toStdString()+"}"<<endl;
    fileWpis.close();
}

void KontrahentInfoDodajWpis::on_pushButton_clicked()
{
    //Zamknij
    timer->stop();
    destroy();
}
void KontrahentInfoDodajWpis::init()
{
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

    nrWpisu = QString::number(rok) + "/" + qStrMiesiac + "/" + qStrDzien + "/"
              + QString::number(idWpisu);
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
{
    if (ui->comboBox->currentText().toStdString()=="Co 1 dzień")
    {
        cout<<"Co 1 dzień"<<endl;
        //Dodac do dnia 1 dzien. Jezeli wychodzi po za miesiac to dodoac mc

        dzien = dzien+1;
        cout<<"Plus 1 dzien"<<dzien<<endl;
    }
    if (ui->comboBox->currentText().toStdString()=="Co tydzień")
    {
        cout<<"Co tydzien"<<endl;
        dzien = dzien+7;
        cout<<"Plus tydzien"<<dzien<<endl;
    }
    if (ui->comboBox->currentText().toStdString()=="Co miesiąc")
    {
        cout<<"Co miesiac"<<endl;
        miesiac = miesiac+1;
        cout<<"Plus 1 mc"<<miesiac<<endl;
    }
    if (ui->comboBox->currentText().toStdString()=="Co rok")
    {
        cout<<"Co rok"<<endl;
        rok=rok+1;
        cout<<"Plus 1 rok"<<rok<<endl;
    }
}
QString KontrahentInfoDodajWpis::setSettingsId(QString IdUrz, QString IdKontr )
{
    ui->label_12->setText(IdUrz);
    ui->label_13->setText(IdKontr);
    return 0;
}