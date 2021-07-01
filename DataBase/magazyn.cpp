#include "magazyn.h"
#include "ui_magazyn.h"
#include "DataBase/maindb.h"
#include "Timery/timedate.h"
#include "Info/info.h"
#include "Ustawienia/statystyki.h"
#include "Ustawienia/ustawienia.h"
#include <iostream>
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
    setWindowTitle("OptiBase v 1.0:Magazyn - LMagazyn");
    //tworze menu kontekstowe
    //setWindowTitle("OptiBase v 1.0:Kontrahent - Lista Kontrahentów");

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
    //    QStandardItem *dodajItem = new QStandardItem("");
    //    MainDb *mainDb = new MainDb(this);
    //    int pobierzUrzKontId = 0;

    QStringList listaModel = QStringList();

    MainDb *mainDb = new MainDb(this);
    QString pobierzUrz = "";
    model = new QStandardItemModel(1, 6, this); //było 14
    ui->tableView->setModel(model);

    model->setHeaderData(0, Qt::Horizontal, "L.P.");
    model->setHeaderData(1, Qt::Horizontal, "Producent");           //nazwa
    model->setHeaderData(2, Qt::Horizontal, "Model");               // Imie
    model->setHeaderData(3, Qt::Horizontal, "Nr Seryjny");          // Imie
    model->setHeaderData(4, Qt::Horizontal, "Przypisany ?");        // Imie
    model->setHeaderData(5, Qt::Horizontal, "Kontrahent");    // Imie
    //    model->setHeaderData(6, Qt::Horizontal, "LP Kontrahenta");      //Nazwisko
    //    model->setHeaderData(7, Qt::Horizontal, "Nazwa");               //Kraj
    //    model->setHeaderData(8, Qt::Horizontal, "Imie");                //Region
    //    model->setHeaderData(9, Qt::Horizontal, "Nazwisko");            //Miasto
    //    model->setHeaderData(10, Qt::Horizontal, "Kraj");               //Kod Pocztowy
    //    model->setHeaderData(11, Qt::Horizontal, "Region");             //Ulica
    //    model->setHeaderData(12, Qt::Horizontal, "Miasto");             //Nr domu/mieszkania
    //    model->setHeaderData(13, Qt::Horizontal, "Kod Pocztowy");       //Telefon
    //    model->setHeaderData(14, Qt::Horizontal, "Ulica");              //Telefon prywatny
    //    model->setHeaderData(15, Qt::Horizontal, "Nr domu/mieszkania"); //Adres E-mail
    //    model->setHeaderData(16, Qt::Horizontal, "Telefon");            //Strona URL
    //    model->setHeaderData(17, Qt::Horizontal, "Telefon prywatny");   //Telefon prywatny
    //    model->setHeaderData(18, Qt::Horizontal, "Adres E-mail");       //Adres E-mail
    //    model->setHeaderData(19, Qt::Horizontal, "Strona URL");         //Strona URL
    //    model->setHeaderData(20, Qt::Horizontal, "Numer Seryjny z Przypisania");
    QStandardItem *dodajItem = new QStandardItem();
    QString pobierzNumerSeryjny = "";
    int pobierzUrzId = 0;
    //Lece do MainDB->pobierz Id

    //Wczytac wszytskie urzadzenia
    pobierzUrzId = mainDb->pobierzUrzadzeniaId(pobierzUrzId);
    for (int i = 1; i <= pobierzUrzId; i++) {
        for (int d = 0; d <= 5; d++) {
            pobierzUrz = mainDb->pobierzUrzadzenia(pobierzUrz, i, d); //(pobierzUrz, i, d
            dodajItem = new QStandardItem(pobierzUrz);

            //ui->comboBox_4->addItem(dodajItem->text());

            model->setItem(i - 1, d, dodajItem);
        }
    }

    int rowDoSize = model->rowCount();
    for (int i = 0; i <= rowDoSize; i++) {
        ui->tableView->setRowHeight(i, 20);
    }
    ui->tableView->horizontalHeader()->setSectionResizeMode(
                QHeaderView::ResizeToContents); // Rozszerza kolumny do najdłuzszego itema w kolumnie.
    ui->tableView->sortByColumn(0,
                                Qt::SortOrder(0));

    //&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&7
    //Sprawdzam tak: pobieram do stringa wartos z tabelą. I wrzucam ją do comboboxa.
    // Pobieram drugą i sprawdzam czy taka jest w combo boxie. Jezeli nie to dodaję.
    // Jezeli jest to biorę drugąwartośc z tablei a stringa nie dodoaję.
    QModelIndex index = ui->tableView->selectionModel()->currentIndex();
    for (int k =0;k<=rowDoSize-1;k++)
    {
        //    QVariant tempSend = index.sibling(k, 2).data();
        //     QString QVartsoc = QVariant(tempSend).toString();
        //    cout<<QVartsoc.toStdString()<<endl;

        QStandardItem *itemTemp = model->item(k,2);
        qWarning()<<itemTemp->text();
        // QStandardItem *itemTemp1 = model->item(k+1,2);

        //        if (itemTemp==itemTemp1)
        //        {
        //            //nic nie rob
        //            cout<<" Równe"<<endl;
        //        }
        //        else
        //        {
        //cout<<" NIE równe"<<endl;
        ui->comboBox_4->addItem(itemTemp->text());
        //        }

    }





    // teraz potrxebuje przelecie wsztskie modele i wyrzucić powtarzające się

    //*****************8
    //Testuje wrzucanie do listy i kasowanie duplikatow/
    int ostatniIndex = ui->comboBox_4->count()-1;

    for (int k=1;k<=ostatniIndex;k++)
    {
        listaModel.push_back(ui->comboBox_4->itemText(k).toUtf8());
    }
    sort(listaModel.begin(), listaModel.end());
    listaModel.removeDuplicates();
    ui->comboBox_4->clear();
    for (int k = 0; k <= listaModel.count() - 1; k++) {
        ui->comboBox_4->addItem(listaModel.at(k));
    }
    //**************************88



    //    for (int k=1;k<=model->rowCount()-1;k++)//k<= rowDoSize-1
    //    {
    //        QString modelUrzadzenia = model->item(k,2)->text();
    //        cout<<modelUrzadzenia.toStdString()<<endl;





    //        for (int u =2;u<=model->rowCount()-1;u++)//u<=rowDoSize-1

    //        {
    //             if (modelUrzadzenia.contains( model->item(u,2)->text()) )
    //             {cout<<"Powtrzenie: " + modelUrzadzenia.toStdString()<<endl;
    //                 //ui->tableView->hideRow(u);
    //                 /ui->comboBox_4->addItem(model->item(u,2)->text());
    //                 model->removeRows(u,1);
    //                 //rowDoSize= rowDoSize-1;
    //             }
    //             else
    //             {
    //                 cout<<"Nie ma powtorzenia."<<endl;
    //             }

    //        }
    // }

    map <QString, int> hashMap;
    int licznikDrugiej =0;
    //QString tablicaModeli[ui->comboBox_4->count() ][100]; //= new QString[ui->comboBox_4->size()];
    QString rozmiarComboBoxa = QString::number(ui->comboBox_4->count()-1);
    qWarning()<<"Rozmiar tablicy to: "+rozmiarComboBoxa;
    //int licznikDrugiej =0;
    QString element;
    QString modelUrzadzenia;
    //Zapetlam mape
    for (int g=0; g<=rozmiarComboBoxa; g++)
    {
        //hashMap["pierwzycos"] = 1;
        hashMap[(ui->comboBox_4->itemText(g))]=0;
    }
    //End
    QString rozmiarTabeli = QString::number(rowDoSize);
    qWarning ()<<"Rozmiara combo: " + rozmiarComboBoxa;
    qWarning ()<<"Rozmiara tabeli: " + rozmiarTabeli;
    for (int a=0;a<=ui->comboBox_4->count()-1;a++)
    {qWarning()<<"1";
        element = ui->comboBox_4->itemText(a);
        qWarning()<<"2";
        for (int k=0; k<=rowDoSize-1; k++){
            qWarning()<<"3";
            modelUrzadzenia = model->item(k,2)->text();
            qWarning()<<"Model urzadzenia to: "<<modelUrzadzenia;
            qWarning()<<"element to: "<<element;
            //tablicaModeli[a][licznikDrugiej] = modelUrzadzenia;
            qWarning()<<"4";
            //hashMap.(element,0);
            if (element.contains( modelUrzadzenia))
            {qWarning()<<"5";
                licznikDrugiej++;
                //qWarning()<<tablicaModeli[a][licznikDrugiej];
                //qWarning()<<"1";
                hashMap[(element)]=licznikDrugiej;
                //hashMap(element,licznikDrugiej);
                qWarning()<<"6";
                qWarning()<<hashMap<<endl;;
            }


        }
        licznikDrugiej =0;
    }
    qWarning()<<"end";
//HashMapa works
    //Teraz kasuje listę w tabeli i wpisać tylko moel z producentem i ile razy wystepuje.

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
