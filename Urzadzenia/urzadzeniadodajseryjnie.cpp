#include "urzadzeniadodajseryjnie.h"
#include "ui_urzadzeniadodajseryjnie.h"
#include "DataBase/maindb.h"
#include <iostream>




using namespace std;

QString producentUrz, modelUrz;
 QString przypisany = "";


UrzadzeniaDodajSeryjnie::UrzadzeniaDodajSeryjnie(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UrzadzeniaDodajSeryjnie)
{
    ui->setupUi(this);
    initMenuUrzadzenia();
    fillComboBoxes ();
}

UrzadzeniaDodajSeryjnie::~UrzadzeniaDodajSeryjnie()
{
    delete ui;
}

void UrzadzeniaDodajSeryjnie::on_pushButton_clicked() //Zamknij
{
    //Zamknij
    destroy ();
}


void UrzadzeniaDodajSeryjnie::initMenuUrzadzenia()
{
    //tworze menu kontekstowe
    setWindowTitle("OptiBase v 1.0:Urządzenia: Dodaj Seryjnie ");
    ui->pushButton_3->setEnabled(false);


    changeIconColor("red");
}
void UrzadzeniaDodajSeryjnie::fillComboBoxes()
{

    //    wypelnijModel();
    int checkFlagsVariableModel = 0;
    int checkFlagsVariableProducent = 0;
    MainDb *mainDb = new MainDb(this);
    checkFlagsVariableModel = mainDb->checkFlagsModel(checkFlagsVariableModel);
    if (checkFlagsVariableModel == 0) {

        QStringList listaModel = QStringList();

        ui->comboBox_2->clear();


        wypelnijModel();

        int ostatniindex = ui->comboBox_2->count() - 1;
        for (int iZmienna = 0; iZmienna <= ostatniindex; iZmienna++) {
            listaModel.push_back(ui->comboBox_2->itemText(iZmienna).toUtf8());
        }

        sort(listaModel.begin(), listaModel.end());
        ui->comboBox_2->clear();
        for (int kZmienna = 0; kZmienna <= listaModel.count() - 1; kZmienna++) {
            ui->comboBox_2->addItem(listaModel.at(kZmienna));
        }
        checkFlagsVariableModel =1;
        on_comboBox_2_highlightedExit(checkFlagsVariableModel);
    }

    ui->pushButton->setEnabled(true);


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
void UrzadzeniaDodajSeryjnie::on_comboBox_highlightedExit(int checkFlagsVariableProducent)
{
    MainDb *mainDb = new MainDb(this);
    checkFlagsVariableProducent = mainDb->checkFlagsProducentInsert1(checkFlagsVariableProducent);
    //cout <<"checkFlagsVariableProducent o zmianue";
    // cout<<checkFlagsVariableProducent<<endl;
}

void UrzadzeniaDodajSeryjnie::on_comboBox_2_highlightedExit(int checkFlagsVariableModel)
{
    MainDb *mainDb = new MainDb(this);
    checkFlagsVariableModel = mainDb->checkFlagsModelInsert1(checkFlagsVariableModel);
    // cout <<"checkFlagsVariableProducent o zmianue";
    //  cout<<checkFlagsVariableModel<<endl;
}
void UrzadzeniaDodajSeryjnie::wypelnijModel()
{
    int pobierzModelId = 0;
    QString QStringPobierzModel = "";

    MainDb *mainDb = new MainDb(this);
    pobierzModelId = mainDb->pobierzModeliD(pobierzModelId);
    for (int i = 1; i <= pobierzModelId; i++) {
        QStringPobierzModel = mainDb->pobierzModel(QStringPobierzModel, i);
        ui->comboBox_2->addItem(QStringPobierzModel);
    }
}
void UrzadzeniaDodajSeryjnie::wypelnijProducenta()
{
    int pobierzProducentaId = 0;
    QString QStringPobierzProducenta = "";


    MainDb *mainDb = new MainDb(this);
    pobierzProducentaId = mainDb->pobierzProducentaiD(pobierzProducentaId);
    for (int i = 1; i <= pobierzProducentaId; i++) {
        QStringPobierzProducenta = mainDb->pobierzProducenta(QStringPobierzProducenta, i);
        ui->comboBox->addItem(QStringPobierzProducenta);
    }
}

void UrzadzeniaDodajSeryjnie::on_pushButton_3_clicked() // Zapisz
{

    changeIconColor("green");
}

void UrzadzeniaDodajSeryjnie::on_pushButton_2_clicked() // Dodaj
{MainDb *mainDb = new MainDb(this);
    ui->pushButton_3->setEnabled(true);
    changeIconColor("yellow");

    //Musze okreslic ile jest numerów seryjnych po przecinku. Chyba splitem


    QString sN; //call to serialNumbers
    QStringList strSN; //call to strSerialNumbers
    sN=ui->textEdit->toPlainText();
    strSN = sN.split(",");


    for (int i =0; i<= strSN.size()-1;i++)
    {
        cout<<strSN.at(i).toStdString()<<endl;
    }

//    cout<<strSN.at(1).toStdString()<<endl;
//    cout<<strSN.at(2).toStdString()<<endl;
    cout<<"Ilosc stringów: "<<strSN.size()<<endl;
    //ui->textEdit->clear();

    // okresl producenta i model

    producentUrz = ui->comboBox->currentText();
    modelUrz = ui-> comboBox_2->currentText();

    //wyslij do MainDb dla kazdego modelu

    for(int j=0;j<=strSN.size()-1; j++)
    {
        mainDb->addUrzadzenia(producentUrz,  modelUrz, strSN.at(j), przypisany);
    }


}
QString UrzadzeniaDodajSeryjnie::changeIconColor(QString colorIcon)
{
    QString dirPath = "C:/Users/pawel/Documents/Cplusplus/OptiBase/OptiBase/Resources";
    QPixmap pix1(dirPath+ "/YesRed.png");
    if (colorIcon == "red")
    {
        //QPixmap pix1(dirPath+ "/YesRed.png");
        pix1=dirPath+ "/YesRed.png";
        cout<<"Red"<<endl;
    }
    else if (colorIcon == "green")
    {
        //QPixmap pix1(dirPath+ "/CheckOk.png");
        pix1=dirPath+ "/CheckOk.png";
        cout<<"green"<<endl;
    }
    else if (colorIcon == "yellow")
    {
        // QPixmap pix1(dirPath+ "/YesYellow.png");
        pix1=dirPath+ "/YesYellow.png";
        cout<<"yellow"<<endl;
    }
    ui->lblCheckOkNo->setPixmap(pix1.scaled(ui->lblCheckOkNo->size(),Qt::KeepAspectRatio));//Skaluje pnp do wymierów labela
    return 0;
}


