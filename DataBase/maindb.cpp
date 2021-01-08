#include "maindb.h"
#include "Urzadzenia/urzadzenia.h"
#include <iostream>
#include <QDebug>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>

using namespace std;

QSqlRecord idName;

MainDb::MainDb(QWidget *parent)
    : QMainWindow(parent)
{
    //cout << "Jestem w construktorze Init mainDB" << endl;
}
void MainDb::init()
{ //Urzadzenia *urzadz = new Urzadzenia(this);
    //cout << "Jestem w Init mainDB" << endl;
    DatabaseConnect();
    DatabaseInit();
    DatabasePopulate();
}
QString MainDb::ZapytanieTestowe(QString zapytanie)

{
    //TODO: Stworzyc zapytanie i go wyswietlic

    //Proste testowe zapytanie
    //cout << "Jestem w Main DB proste zapytanie" << endl;
    QSqlQuery query;
    query.prepare("SELECT miasto FROM miasta");

    if (!query.exec())
        qWarning() << "Error w zapytaniu" << query.lastError().text();
    if (query.first()) {
        zapytanie = query.value(0).toString();
    } else {
        zapytanie = "Dane nie znalezione";
    }

    return zapytanie;
}


QString MainDb::addKontrahent(QString l1,
                              QString l2,
                              QString l3,
                              QString l4,
                              QString l5,
                              QString l6,
                              QString l7,
                              QString l8,
                              QString l9,
                              QString l10,
                              QString l11,
                              QString l12,
                              QString l13)
{
    //Zapisuje do bazy Urzadzenia

    QSqlQuery query;
    qWarning() << ("Dodoaje do bazy " + l1 + " , " + l2 + " , " + l3 + " , " + l4 + " , " + l6
                   + " , " + l5 + " , " + l7 + " , " + l8 + " , " + l9 + " , " + l10 + " , " + l11
                   + " , " + l12 + " , " + l13);
    if (!query.exec("INSERT INTO kontrahenci (nazwaFirmy, imie , nazwisko , kontrahent_panstwo_id "
                    ", kontrahent_wojewodztwo_id , kontrahent_miasto_id , kodPocztowy , ulica , "
                    "nrDomu , telefon , telefonPrywatny , adresEmail , stronaUrl) VALUES('"
                    + l1 + "','" + l2 + "','" + l3 + "','" + l4 + "','" + l6 + "','" + l5 + "','"
                    + l7 + "','" + l8 + "','" + l9 + "','" + l10 + "','" + l11 + "','" + l12 + "','"
                    + l13 + "')"))

    {
        qWarning() << "MainDB::Dodoanie Urzadzenia - ERROR: " << query.lastError().text();
    } else {
        qWarning() << "MainDB::Dodoanie Kontrahenci - Udane: " << query.lastError().text();
    }
    return 0;
}




void MainDb::dBPrzypomnienie()
{
    QSqlQuery query;
    query.exec("PRAGMA foreign_keys = ON;"); // włączenia kluczy obcych
    qWarning("Tworzenie tabeli Z przypomnienienami ");
    query.exec("CREATE TABLE IF NOT EXISTS dBPrzypomnienie  (id INTEGER PRIMARY KEY, nr_wpisu "
               "TEXT UNIQUE, data TEXT, temat TEXT, tresc TEXT, "
               "przypomnienie TEXT, data_przypomnienia TEXT, tekst_przypomnienia TEXT, "
               "urzadzenia_numer_seryjny TEXT, "
               "FOREIGN KEY (urzadzenia_numer_seryjny ) REFERENCES urzadzenia (numerSeryjny)  )");

    if (!query.isActive())
        qWarning() << " Tworzenie Tabeli - ERROR: " << query.lastError().text();

//    if (!query.exec("INSERT INTO kontrahenci (nazwaFirmy, imie , nazwisko , kontrahent_panstwo_id "
//                    ", kontrahent_wojewodztwo_id , kontrahent_miasto_id , kodPocztowy , ulica , "
//                    "nrDomu , telefon , telefonPrywatny , adresEmail , stronaUrl  ) "
//                    "VALUES('VITAKO' , 'Paweł' , 'Martys' , 'Polska' , "
//                    "'Zachodniopomorskie' , 'Szczecin' , '71-766' , 'Małej Syrenki' , '2' , "
//                    "'692717987' , '723508531' , 'serwis@vbody.pl' , 'www.vitako.pl')"))
        qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
}

void MainDb::dBKontrahent()
{
    QSqlQuery query;
    query.exec("PRAGMA foreign_keys = ON;"); // włączenia kluczy obcych
    qWarning("Tworzenie tabeli Kontrahent ");
    query.exec("CREATE TABLE IF NOT EXISTS kontrahenci  (id INTEGER PRIMARY KEY, nazwaFirmy "
               "TEXT UNIQUE, imie TEXT, nazwisko TEXT, kontrahent_panstwo_id TEXT, "
               "kontrahent_wojewodztwo_id TEXT, kontrahent_miasto_id TEXT, kodPocztowy TEXT, "
               "ulica TEXT, nrDomu INTEGER, telefon TEXT, "
               "telefonPrywatny TEXT, adresEmail TEXT, stronaUrl TEXT, urzadzenia_numer_seryjny "
               "TEXT, FOREIGN KEY "
               "(kontrahent_panstwo_id) REFERENCES panstwa(panstwo), FOREIGN KEY "
               "(kontrahent_wojewodztwo_id) REFERENCES wojewodztwa (wojewodztwo), "
               "FOREIGN KEY "
               "(kontrahent_miasto_id) REFERENCES miasta (miasto), "
               "FOREIGN KEY (urzadzenia_numer_seryjny ) REFERENCES urzadzenia (numerSeryjny)  )");

    if (!query.isActive())
        qWarning() << " Tworzenie Tabeli - ERROR: " << query.lastError().text();

    if (!query.exec("INSERT INTO kontrahenci (nazwaFirmy , imie , nazwisko , kontrahent_panstwo_id "
                    ", kontrahent_wojewodztwo_id , kontrahent_miasto_id , kodPocztowy , ulica , "
                    "nrDomu , telefon , telefonPrywatny , adresEmail , stronaUrl  ) "
                    "VALUES('VITAKO' , 'Paweł' , 'Martys' , 'Polska' , "
                    "'Zachodniopomorskie' , 'Szczecin' , '71-766' , 'Małej Syrenki' , '2' , "
                    "'692717987' , '723508531' , 'serwis@vbody.pl' , 'www.vitako.pl')"))
        qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
}
QString MainDb::pobierzUrzadzenia(QString daneUrzadzenia, int i, int d)
{
    QSqlQuery query;
    QString testName;
    qWarning() << "Pobrana ilosc Urzadzenia z ::Uradzernia::Lista" << i + d;

    QString inti = QString::number(i);

    QString name;
    if (query.exec("SELECT * FROM urzadzenia where id =" + inti)) {
        while (query.next()) {
            qWarning() << query.value(d).toString();
            name = query.value(d).toString();
        }
        daneUrzadzenia = name;
        qWarning() << "udalo sie? : pozniej " << name;
        return name;
    }
    return 0;
}
int MainDb::pobierzUrzadzeniaId(int daneUrzadzeniaId)
{
    QSqlQuery query;
    //qWarning() << "Jestem w MainDB->pobierz Id.";
    QString testName;
    int rows = 0;
    //TODO: pobrac z Bazy Modeli

    if (query.exec("SELECT * FROM urzadzenia")) {
        while (query.next()) {
            //qWarning() << query.value(1).toString();
            rows++;
        }
       // qWarning() << "row to: " << rows;
    }
    //qWarning() << "Wychodze z MainDB->pobierz Id z pobraną iloscia wpisów w bazie danych";
    daneUrzadzeniaId = rows;
    return rows;
}
QString MainDb::pobierzKontrahenta(QString daneKontrahent, int i, int d)
{
    QSqlQuery query;
    QString testName;
    qWarning() << "Pobrana ilosc Kontrahenci z ::KontrahenciPaństwa::" << i;

    QString inti = QString::number(i);

    QString name;
    daneKontrahent = name;
    if (query.exec("SELECT * FROM kontrahenci where id =" + inti)) {
        while (query.next()) {
            qWarning() << query.value(d).toString();
            name = query.value(d).toString();
        }
        qWarning() << "udalo sie? : pozniej " << name;
        return name;
    }
    return 0;
}
int MainDb::pobierzKontrahentaId(int daneKontrahentId)
{
    QSqlQuery query;
    //qWarning() << "Jestem w MainDB->pobierz Id.";
    QString testName;
    int rows = 0;
    //TODO: pobrac z Bazy Modeli

    if (query.exec("SELECT * FROM kontrahenci")) {
        while (query.next()) {
            //qWarning() << query.value(1).toString();
            rows++;
        }
       // qWarning() << "row to: " << rows;
    }
    //qWarning() << "Wychodze z MainDB->pobierz Id z pobraną iloscia wpisów w bazie danych";
    daneKontrahentId = rows;
    return rows;
}
QString MainDb::pobierzKontrahentaZNrSeryjnym(QString daneKontrahent,
                                              int i,
                                              int d)
{
    QSqlQuery query;
    QString testName;
    //qWarning() << "Pobrana ilosc Kontrahenci z ::KontrahenciPaństwa::" << i;
    QString inti = QString::number(i);
    QString dinti = QString::number (d);
    QString name;
    daneKontrahent = name;
//    if (query.exec("SELECT * FROM urzadzenia, kontrahenci WHERE urzadzenia.id =" + inti
//                   + " and kontrahenci.id = " + inti
//                   + " and urzadzenia.kontrahent_id = kontrahenci.nazwaFirmy" ))

//    QVariant a1 = query.value(3);
//    QString a11 = QVariant::toStdString(a1);
     //QVariant a2 = query.value(19);
    if (query.exec("SELECT * FROM urzadzenia, kontrahenci WHERE urzadzenia.id = " + inti
                   + " and urzadzenia.kontrahent_id = kontrahenci.nazwaFirmy" )) {
        while (query.next()) {

            if (query.value(5) != query.value(7))
            { qWarning () <<"Nie Udane: query.value(5) != query.value(7) " <<query.value(5) <<" "<< query.value(7);
                name = "Numeros4534";
                return name;
            }
            else
            {
                qWarning () <<"Udane: query.value(5) != query.value(7) " <<query.value(5) <<" "<< query.value(7);
                qWarning () <<" i = " +inti << " d = "  +dinti;
            qWarning() << query.value(d).toString();
            name = query.value(d).toString();
            return name;
            }
        }
        name = "Numeros4534";
        return name;
        qWarning() << "udalo sie? : pozniej " << name;

    }
    return name;
}

QString MainDb::pobierzNumerSeryjnyZKontrahenta(QString pobierzNumerSeryjny)
{
    QSqlQuery query;
    if (query.exec("SELECT * FROM kontrahenci")) {
        while (query.next()) {
            //if (query.value())
            qWarning() << query.value(14).toString();
            pobierzNumerSeryjny = query.value(14).toString();
            return pobierzNumerSeryjny;
        }
    }
    return 0;
}

int MainDb::pobierzKontrahentaZNrSeryjnymId(int daneKontrahentId)
{
    QSqlQuery query;
    //qWarning() << "Jestem w MainDB->pobierz Id.";
    QString testName;
    int rows = 0;
    //TODO: pobrac z Bazy Modeli

    if (query.exec("SELECT * FROM urzadzenia, kontrahenci WHERE urzadzenia.kontrahent_id = kontrahenci.nazwaFirmy")) {
        while (query.next()) {
           //zliczam ilosc wierszy z seryj w urz = serej kontr
            rows++;
        }

    }

    daneKontrahentId = rows;
    //rows = rows +5; //INFO:: dodoaje  + dla elementwo urzadzenia
    return rows;
}

QString MainDb::addUrzadzeniaUpdate(QString daneNrSeryjny, QString daneUnicueName)
{
    //Zapisuje do bazy Urzadzenia
    //TODO: Tutuaj dodoac update do Kontrahenci i pobrac unikalny kontrahent i dodoac numer seryjny
    QSqlQuery query;
    query.exec("PRAGMA foreign_keys = ON;"); // włączenia kluczy obcych
    qWarning() << ("Dodoaje do bazy " + daneNrSeryjny);
    QString przypisany = "TAK";
    /*if (!query.exec("INSERT INTO urzadzenia (numerSeryjny, przypisany) VALUES('"
                    + daneNrSeryjny +"','" + przypisany + "' )")) {
        qWarning() << "MainDB::Dodoanie Urzadzenia - ERROR: " <<*/
    if (!query.exec("UPDATE urzadzenia SET przypisany = '" + przypisany + "' WHERE numerSeryjny ='"
                    + daneNrSeryjny + "' "))

    {
        qWarning() << "MainDB::Update Urzadzenia - ERROR: " << query.lastError().text();
    } else {
        qWarning() << "MainDB::Update Urzadzenia - Udane: " << query.lastError().text();
    }
    //..............
//    if (!query.exec("UPDATE urzadzenia SET przypisany = '" + przypisany + "' WHERE numerSeryjny ='"
//                    + daneNrSeryjny + "' "))

//    {
//        qWarning() << "MainDB::Update Urzadzenia: Przypisany - ERROR: " << query.lastError().text();
//    } else {
//        qWarning() << "MainDB::Update Urzadzenia: Przypisany - Udane: " << query.lastError().text();
//    }
    if (!query.exec("UPDATE urzadzenia SET kontrahent_id = '" + daneUnicueName + "' WHERE numerSeryjny ='"
                    + daneNrSeryjny + "' "))

    {
        qWarning() << "MainDB::Update Urzadzenia:Nr Id Kontr. - ERROR: " << daneUnicueName<< query.lastError().text();
    } else {
        qWarning() << "MainDB::Update Urzadzenia:Nr Id Kontr. - Udane: " << daneUnicueName<< query.lastError().text();
    }

//    if (!query.exec("UPDATE kontrahenci SET urzadzenia_numer_seryjny = '" + daneNrSeryjny
//                    + "' WHERE nazwaFirmy ='" + daneUnicueName + "' "))

//    {
//        qWarning() << "MainDB::Update Kontrahenci z numerem seryjnym - ERROR: "
//                   << query.lastError().text();
//    } else {
//        qWarning() << "MainDB::Update Kontrahenci z numerem seryjnym - Udane: "
//                   << query.lastError().text();
//    }

    return 0;
}
QString MainDb::addUrzadzenia(QString daneProducent,
                              QString daneModel,
                              QString daneNrSeryjny,
                              QString przypisany)
{
    //Zapisuje do bazy Urzadzenia

    QSqlQuery query;
    query.exec("PRAGMA foreign_keys = ON;"); // włączenia kluczy obcych
    qWarning() << ("Dodoaje do bazy " + daneModel);
    if (!query.exec("INSERT INTO urzadzenia (urzadzenia_producent_id, urzadzenia_model_id, "
                    "numerSeryjny, przypisany) VALUES('"
                    + daneProducent + "','" + daneModel + "','" + daneNrSeryjny + "','" + przypisany
                    + "' )"))
    {
        qWarning() << "MainDB::Dodoanie Urzadzenia - ERROR: " << query.lastError().text();
    } else {
        qWarning() << "MainDB::Dodoanie Urzadzenia - Udane: " << query.lastError().text();
    }
    return 0;
}
QString MainDb::addProducent(QString daneProducent)

{
    //TODO: dodoac do Bazy producenta
    QSqlQuery query;
    query.exec("PRAGMA foreign_keys = ON;"); // włączenia kluczy obcych
    qWarning() << ("Dodoaje do bazy " + daneProducent);
    if (!query.exec("INSERT INTO producenci (producent) VALUES('" + daneProducent + "')"))
        qWarning() << "MainDB::Dodoanie Producenta - ERROR: " << query.lastError().text();
    return 0;
}

QString MainDb::addPrzypomnienie(QString nrWpisu, QString dataWpisu,QString tematWpisu,QString trescWpisu,QString przypomnienie,QString dataNajblPrzypom,QString tekstPrzypom,QString nrSeryjny )
{
    //Wczytaj dane z formatki przypomnienie
    //TODO: dodoac do Bazy przypomnienia
    QSqlQuery query;
    query.exec("PRAGMA foreign_keys = ON;"); // włączenia kluczy obcych
    qWarning() << ("Dodoaje do bazy sekcje przypomnienia");


    if (!query.exec("INSERT INTO dBPrzypomnienie (nr_wpisu, data, temat, tresc, przypomnienie, data_przypomnienia, tekst_przypomnienia, urzadzenia_numer_seryjny) VALUES('"
                    + nrWpisu + "','" + dataWpisu + "','" + tematWpisu + "','" + trescWpisu + "','" + przypomnienie + "','" + dataNajblPrzypom + "','" + tekstPrzypom + "','" + nrSeryjny
                    + "' )"))
    {
        qWarning() << "MainDB::Dodoanie Przypomnienia - ERROR: " << query.lastError().text();
    } else {
        qWarning() << "MainDB::Dodoanie Przypomnienia - Udane: " << query.lastError().text();
    }
    return 0;
}

QString MainDb::addModel(QString daneModel)

{
    //TODO: dodoac do Bazy producenta
    QSqlQuery query;
    query.exec("PRAGMA foreign_keys = ON;"); // włączenia kluczy obcych
    qWarning() << ("Dodoaje do bazy " + daneModel);
    if (!query.exec("INSERT INTO modele (model) VALUES('" + daneModel + "')"))
        qWarning() << "MainDB::Dodoanie Modelu - ERROR: " << query.lastError().text();
    return 0;
}
QString MainDb::addKraj(QString daneKraj)

{
    //TODO: dodoac do Bazy producenta
    QSqlQuery query;
    query.exec("PRAGMA foreign_keys = ON;"); // włączenia kluczy obcych
    qWarning() << ("Dodoaje do bazy " + daneKraj);
    if (!query.exec("INSERT INTO panstwa (panstwo) VALUES('" + daneKraj + "')"))
        qWarning() << "MainDB::Dodoanie Modelu - ERROR: " << query.lastError().text();
    return 0;
}
QString MainDb::addWojewodztwo(QString daneWojewodztwo)

{
    //TODO: dodoac do Bazy producenta
    QSqlQuery query;
    query.exec("PRAGMA foreign_keys = ON;"); // włączenia kluczy obcych
    qWarning() << ("Dodoaje do bazy " + daneWojewodztwo);
    if (!query.exec("INSERT INTO wojewodztwa (wojewodztwo) VALUES('" + daneWojewodztwo + "')"))
        qWarning() << "MainDB::Dodoanie Modelu - ERROR: " << query.lastError().text();
    return 0;
}
QString MainDb::addMiasto(QString daneMiasto)

{
    //TODO: dodoac do Bazy producenta
    QSqlQuery query;
    query.exec("PRAGMA foreign_keys = ON;"); // włączenia kluczy obcych
    qWarning() << ("Dodoaje do bazy " + daneMiasto);
    if (!query.exec("INSERT INTO miasta (miasto) VALUES('" + daneMiasto + "')"))
        qWarning() << "MainDB::Dodoanie Modelu - ERROR: " << query.lastError().text();
    return 0;
}
QString MainDb::pobierzKraj(QString daneModel, int i)
{
    QSqlQuery query;
    query.exec("PRAGMA foreign_keys = ON;"); // włączenia kluczy obcych
    QString testName;
    qWarning() << "Pobrana ilosc Kraji z ::Państwa::" << i;

    QString inti = QString::number(i);

    QString name;
    daneModel = name;
    if (query.exec("SELECT * FROM panstwa where id =" + inti)) {
        while (query.next()) {
            qWarning() << query.value(1).toString();
            name = query.value(1).toString();
        }
        qWarning() << "udalo sie? : pozniej " << name;
        return name;
    }
    return 0;
}
int MainDb::pobierzKrajId(int pobierzKrajId)

{
    QSqlQuery query;
    //qWarning() << "Jestem w MainDB->pobierz Id.";
    QString testName;
    int rows = 0;
    //TODO: pobrac z Bazy Modeli

    if (query.exec("SELECT * FROM panstwa")) {
        while (query.next()) {
            qWarning() << query.value(1).toString();
            rows++;
        }
        qWarning() << "row to: " << rows;
    }
    //qWarning() << "Wychodze z MainDB->pobierz Id z pobraną iloscia wpisów w bazie danych";
    pobierzKrajId = rows;
    return rows;
}

QString MainDb::pobierzWojewodztwo(QString daneModel, int i)
{
    QSqlQuery query;
    QString testName = daneModel;
    qWarning() << "Pobrana ilosc Kraji z ::Państwa::" << i;

    QString inti = QString::number(i);
    QString name;
    if (query.exec("SELECT * FROM wojewodztwa where id =" + inti)) {
        while (query.next()) {
            qWarning() << query.value(1).toString();
            name = query.value(1).toString();
        }
        qWarning() << "udalo sie? : pozniej " << name;
        return name;
    }
    return 0;
}
int MainDb::pobierzWojewodztwoId(int pobierzWojewodztwoId)

{
    QSqlQuery query;
    //qWarning() << "Jestem w MainDB->pobierz Id.";
    QString testName;
    int rows = 0;
    pobierzWojewodztwoId = rows;
    //TODO: pobrac z Bazy Modeli

    if (query.exec("SELECT * FROM wojewodztwa")) {
        while (query.next()) {
            //qWarning() << query.value(1).toString();
            rows++;
        }
        //qWarning() << "row to: " << rows;
    }
    //qWarning() << "Wychodze z MainDB->pobierz Id z pobraną iloscia wpisów w bazie danych";
    return rows;
}

QString MainDb::pobierzModel(QString daneModel, int i)

{
    QSqlQuery query;
    QString testName;
    qWarning() << "Pobrana ilosc modeli z ::Urzadzenia::" << i;

    QString inti = QString::number(i);

    QString name;
    if (query.exec("SELECT * FROM modele where id =" + inti)) {
        while (query.next()) {
            qWarning() << query.value(1).toString();
            name = query.value(1).toString();
        }
        qWarning() << "udalo sie? : pozniej " << name;
        return name;
    }
    return 0;
}

int MainDb::pobierzModeliD(int daneModelId)

{
    QSqlQuery query;

    QString testName;
    int rows = 0;
    daneModelId = rows;


    if (query.exec("SELECT * FROM modele")) {
        while (query.next()) {

            rows++;
        }

    }

    return rows;
}
//*******************888
QString MainDb::loadDataRemider(QString remiderSelf,int i,int n, QString numerSeryjnydoPorownania)

{
    QSqlQuery query;
    QString testName;
    qWarning() << "Pobrana ilosc wpisu z ::dBPrzypomnienie::" << i;

    QString inti = QString::number(i);
QString ninti = QString::number(n);
    QString name;
    qWarning ()<<numerSeryjnydoPorownania<< "tutaj numer seryjny do porowniania ";
    if (query.exec("SELECT * FROM dBPrzypomnienie where id =" + inti +" and urzadzenia_numer_seryjny = '" +numerSeryjnydoPorownania+"'")) {
        while (query.next()) {
            qWarning() << query.value(n).toString();
            name = query.value(n).toString();
            remiderSelf=name ;
        }
        qWarning() << "udalo sie? : pozniej " << name;
        return name;
    }
    return 0;
}

int MainDb::loadDataRemiderId(int dataRemiderId)

{
    QSqlQuery query;

    QString testName;
    int rows = 0;
    dataRemiderId = rows;


    if (query.exec("SELECT * FROM dBPrzypomnienie")) {
        while (query.next()) {

            rows++;
        }

    }

    return rows;
}
//*********************



QString MainDb::pobierzMiasto(QString daneModel, int i)

{
    QSqlQuery query;
    QString testName;
    qWarning() << "Pobrana ilosc miasta z ::kontrahenta::" << i;

    QString inti = QString::number(i);

    QString name;
    if (query.exec("SELECT * FROM miasta where id =" + inti)) {
        while (query.next()) {
            qWarning() << query.value(1).toString();
            name = query.value(1).toString();
        }
        qWarning() << "udalo sie? : pozniej " << name;
        return name;
    }
    return 0;
}

int MainDb::pobierzMiastoiD(int daneModelId)

{
    QSqlQuery query;
    //qWarning() << "Jestem w MainDB->pobierz Id.";
    QString testName;
    int rows = 0;
    //TODO: pobrac z Bazy Modeli

    if (query.exec("SELECT * FROM miasta")) {
        while (query.next()) {
            //qWarning() << query.value(1).toString();
            rows++;
        }
        //qWarning() << "row to: " << rows;
    }
    //qWarning() << "Wychodze z MainDB->pobierz Id z pobraną iloscia wpisów w bazie danych";
    daneModelId = rows;
    return rows;
}

int MainDb::pobierzProducentaiD(int daneProducentId)

{
    QSqlQuery query;
    //qWarning() << "Jestem w MainDB->pobierz Id.";
    QString testName;
    int rows = 0;
    //TODO: pobrac z Bazy producenta

    if (query.exec("SELECT * FROM producenci")) {
        while (query.next()) {
            //qWarning() << query.value(1).toString();
            rows++;
        }
        //qWarning() << "row to: " << rows;
    }
    daneProducentId = rows;
    //qWarning() << "Wychodze z MainDB->pobierz Id z pobraną iloscia wpisów w bazie danych";
    return rows;
}
QString MainDb::pobierzProducenta(QString daneProducent, int i)

{
    QSqlQuery query;
    QString testName;
    qWarning() << "Pobrana ilosc producentow z ::Urzadzenia::" << i;

    QString inti = QString::number(i);

    QString name;
    if (query.exec("SELECT * FROM producenci where id =" + inti)) {
        while (query.next()) {
            qWarning() << "Producent : " << query.value(1).toString();
            name = query.value(1).toString();
        }
        //daneProducent = name;
        qWarning() << "udalo sie? : pozniej " << name;
        return name;
    }
    return 0;
}

int MainDb::pobierzUrzKontiD(int daneProducentId)

{
    QSqlQuery query;
    //qWarning() << "Jestem w MainDB->pobierz Id.";
    QString testName;
    int rows = 0;
    //TODO: pobrac z Bazy producenta

    if (query.exec("SELECT * FROM producenci")) {
        while (query.next()) {
            //qWarning() << query.value(1).toString();
            rows++;
        }
        //qWarning() << "row to: " << rows;
    }
    //qWarning() << "Wychodze z MainDB->pobierz Id z pobraną iloscia wpisów w bazie danych";
    return rows;
}
QString MainDb::pobierzUrzKont(QString daneProducent, int i, int d)

{
    QSqlQuery query;
    QString testName;
    qWarning() << "Pobrana ilosc producentow z ::Urzadzenia::" << i;

    QString inti = QString::number(i);

    QString name;
    if (query.exec("SELECT * FROM producenci where id =" + inti)) {
        while (query.next()) {
            qWarning() << query.value(d).toString();
            name = query.value(d).toString();
        }
        qWarning() << "udalo sie? : pozniej " << name;
        return name;
    }
    return 0;
}

void MainDb::DatabaseConnect()
{
    qWarning("Database Connect");
    const QString DRIVER("QSQLITE");
    if (QSqlDatabase::isDriverAvailable(DRIVER)) {
        QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);
        db.setDatabaseName(
            "C:/Users/pawel/Documents/Cplusplus/OptiBase/OptiBase/DataBase/2020.12.21.db");
        qWarning(" Powstała baza");

        if (db.open()) {
            qWarning() << (" Otwarto DB") << db.lastError().text();
            qWarning() << (" Otwarto DB") << db.isDriverAvailable(DRIVER);
            //qWarning() << (" Otwarto DB") << db.connectOptions().
        } else {
            qWarning() << (" Brak otwarcia") << db.lastError().text();
        }
    }
}

void MainDb::DatabaseInit()
{
    qWarning("Database init ");
    //    QSqlQuery query("CREATE TABLE IF NOT EXISTS people  (id INTEGER PRIMARY KEY, name TEXT)");

    //    if (!query.isActive())
    //        qWarning() << " MainWindow::DatabaseInit - ERROR: " << query.lastError().text();
}
void MainDb::DatabasePopulate()
{
    qWarning("Database Wypelnianiae");

    dBMiasta();
    dBWojewodztwa();
    dBKraj();
    dBProducent();
    dBModel();
    dBUrzadzenia();
    dBKontrahent();
    dBBaza();
    dBPrzypomnienie();
    dBStatistisc();

    //QSqlQuery query;
}
void MainDb::dBUrzadzenia()
{
    QSqlQuery query;
    query.exec("PRAGMA foreign_keys = ON;"); // włączenia kluczy obcych
    qWarning("Tworzenie tabeli Urzadzenia ");
    query.exec("CREATE TABLE IF NOT EXISTS urzadzenia  (id INTEGER PRIMARY KEY, "
               "urzadzenia_producent_id TEXT,"
               "urzadzenia_model_id TEXT, "
               "numerSeryjny TEXT UNIQUE, "
               "przypisany TEXT,"
               "kontrahent_id,"
               "FOREIGN KEY (urzadzenia_producent_id) REFERENCES "
               "producenci(producent),"
               "FOREIGN KEY (urzadzenia_model_id) REFERENCES modele(model),"
               "FOREIGN KEY (kontrahent_id) REFERENCES kontrahenci(nazwaFirmy))");
    if (!query.isActive())
        qWarning() << "1. Tworzenie Tabeli - ERROR: " << query.lastError().text();

    //    if (!query.exec("INSERT INTO urzadzenia (urzadzenia_producent_id , urzadzenia_model_id, "
    //                    "numerSeryjny) VALUES('Jawon', 'IOI-353', 'AP00034232-324222')"))
    //        qWarning() << "2. MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();

    //    if (!query.exec("INSERT INTO urzadzenia (urzadzenia_producent_id , urzadzenia_model_id, "
    //                    "numerSeryjny) VALUES('Selvas', 'BC-380', 'AP4222')"))
    //        qWarning() << "3. MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
}
void MainDb::dBProducent()
{
    QSqlQuery query;
    query.exec("PRAGMA foreign_keys = ON;"); // włączenia kluczy obcych
    qWarning("Tworzenie tabeli Producent ");

    query.exec(
        "CREATE TABLE IF NOT EXISTS producenci  (id INTEGER PRIMARY KEY, producent TEXT UNIQUE )");

    if (!query.isActive())
        qWarning() << " Tworzenie Tabeli - ERROR: " << query.lastError().text();
    //NOTE:: dodoaje dwa przykładowe wpisy Producenci
}
void MainDb::dBModel()
{
    QSqlQuery query;
    query.exec("PRAGMA foreign_keys = ON;"); // włączenia kluczy obcych
    qWarning("Tworzenie tabeli Model Urzadzenia ");
    query.exec("CREATE TABLE IF NOT EXISTS modele  (id INTEGER PRIMARY KEY, model TEXT UNIQUE )");

    //NOTE:: dodoaje dwa przykładowe wpisy Modeli
    if (!query.isActive())
        qWarning() << " Tworzenie Tabeli - ERROR: " << query.lastError().text();

    //    if (!query.exec("INSERT INTO modele (model) VALUES('IOI 353')"))
    //        qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
    query.exec("PRAGMA foreign_keys = ON;"); // włączenia kluczy obcych
}

void MainDb::dBMiasta()
{
    QSqlQuery query;
    query.exec("PRAGMA foreign_keys = ON;"); // włączenia kluczy obcych
    qWarning("Tworzenie tabeli Miasta ");
    query.exec("CREATE TABLE IF NOT EXISTS miasta  (id INTEGER PRIMARY KEY, miasto TEXT UNIQUE )");

    if (!query.isActive())
        qWarning() << " Tworzenie Tabeli - ERROR: " << query.lastError().text();
    query.exec("PRAGMA foreign_keys = ON;"); // włączenia kluczy obcych
    if (!query.exec("INSERT INTO miasta (miasto) VALUES('Warszawa')"))
        qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
}
void MainDb::dBWojewodztwa()
{
    QSqlQuery query;
    query.exec("PRAGMA foreign_keys = ON;"); // włączenia kluczy obcych
    qWarning("Tworzenie tabeli Wojewdztwa ");
    query.exec("CREATE TABLE IF NOT EXISTS wojewodztwa  (id INTEGER PRIMARY KEY, wojewodztwo "
               "TEXT UNIQUE )");

    if (!query.isActive())
        qWarning() << " Tworzenie Tabeli - ERROR: " << query.lastError().text();
    query.exec("PRAGMA foreign_keys = ON;"); // włączenia kluczy obcych
    if (!query.exec("INSERT INTO wojewodztwa (wojewodztwo) VALUES('Zachodniopomorskie')"))
        qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
}
void MainDb::dBBaza()
{
    QSqlQuery query;
    query.exec("PRAGMA foreign_keys = ON;"); // włączenia kluczy obcych
    //qWarning("Tworzenie tabeli Urzadzenia ");
    qWarning("Tworzenie tabeli Głownej Bazy ");
    query.exec("CREATE TABLE IF NOT EXISTS dbbaza  (id INTEGER PRIMARY KEY, "
               "dbbaza_urzadzenia_id TEXT, "
               "dbbaza_kontrahent_id TEXT, "
               "FOREIGN KEY (dbbaza_urzadzenia_id) REFERENCES urzadzenia(id),"
               "FOREIGN KEY (dbbaza_kontrahent_id) REFERENCES kontrahenci(id))");

    //    query.exec(
    //        "CREATE TABLE IF NOT EXISTS dbbaza  (id INTEGER PRIMARY KEY, "
    //        "dbbaza_urzadzenia_producent_id TEXT, "
    //        "dbbaza_urzadzenia_model_id TEXT, "
    //        "dbbaza_urzadzenia_numerSeryjny TEXT UNIQUE, "
    //        "dbbaza_urzadzenia_przypisany TEXT, "
    //        "testowa TEXT, "
    //        "FOREIGN KEY (dbbaza_urzadzenia_producent_id) REFERENCES "
    //        "urzadzenia(urzadzenia_producent_id),"
    //        "FOREIGN KEY (dbbaza_urzadzenia_model_id) REFERENCES urzadzenia(urzadzenia_model_id),"
    //        "FOREIGN KEY (dbbaza_urzadzenia_numerSeryjny) REFERENCES urzadzenia(numerSeryjny),"
    //        "FOREIGN KEY (dbbaza_urzadzenia_przypisany) REFERENCES urzadzenia(przypisany))");

    if (!query.isActive())
        qWarning() << " Tworzenie Tabeli DB - ERROR: " << query.lastError().text();

    if (!query.exec(
            "INSERT INTO dbbaza (dbbaza_urzadzenia_id, dbbaza_kontrahent_id ) VALUES(2, 1)"))
        qWarning() << "MainWindow::DatabasePopulate Tabela DB- ERROR: " << query.lastError().text();

    //    if (!query.exec("INSERT INTO panstwa (panstwo) VALUES('Nuemcy')"))
    //        qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
}
void MainDb::dBKraj()
{
    QSqlQuery query;
    query.exec("PRAGMA foreign_keys = ON;"); // włączenia kluczy obcych
    qWarning("Tworzenie tabeli Kraj ");
    query.exec(
        "CREATE TABLE IF NOT EXISTS panstwa  (id INTEGER PRIMARY KEY, panstwo TEXT UNIQUE )");

    if (!query.isActive())
        qWarning() << " Tworzenie Tabeli - ERROR: " << query.lastError().text();

    if (!query.exec("INSERT INTO panstwa (panstwo) VALUES('Polska')"))
        qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
    if (!query.exec("INSERT INTO panstwa (panstwo) VALUES('Nuemcy')"))
        qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
}
void MainDb::dBStatistisc()
{
    QSqlQuery query;
    //query.exec("PRAGMA foreign_keys = ON;"); // włączenia kluczy obcych
    qWarning("Tworzenie tabeli ststystyki ");
    query.exec("CREATE TABLE IF NOT EXISTS dBStatRun  (id INTEGER PRIMARY KEY, ilosc INTEGER )");

    if (!query.isActive())
        qWarning() << " Tworzenie Tabeli - ERROR: " << query.lastError().text();
    //query.exec("PRAGMA foreign_keys = ON;"); // włączenia kluczy obcych
    query.exec("CREATE TABLE IF NOT EXISTS dBStatDays  (id INTEGER PRIMARY KEY, years INTEGER, month INTEGER, days INTEGER, hours INTEGER, minuts INTEGER, secunds INTEGER )");
    if (!query.isActive())
        qWarning() << " Tworzenie Tabeli - ERROR: " << query.lastError().text();
    if (!query.exec("INSERT INTO dBStatRun (id, ilosc) VALUES(1,1)"))
        qWarning() << "MainWindow::dBStatRun - ERROR: " << query.lastError().text();
    if (!query.exec("INSERT INTO dBStatDays (id, years , month , days , hours , minuts, secunds ) VALUES(1,0,0,0,0,0,1)"))
        qWarning() << "MainWindow::dBStatDays - ERROR: " << query.lastError().text();
}

int MainDb::iloscUruchomienSave (int iloscUruchomien)
{
    QSqlQuery query;
    //qWarning() << "Jestem w pobierz ilosc uruchomien";
    QString QIloscUruchomien = QString::number(iloscUruchomien);
    if (query.exec("UPDATE dBStatRun SET ilosc = '" +QIloscUruchomien+"' WHERE id ='1'")) {
        while (query.next()) {
            //qWarning() << inti << " pobrany: " << query.value(3).toString();
            iloscUruchomien = query.value(1).toInt();
            //qWarning() << "Ilosc uruchomien to : "<< iloscUruchomien;
        }
        //qWarning() << "udalo sie? : pozniej " << iloscUruchomien;

    }
    return iloscUruchomien;

}
int MainDb::iloscUruchomienFirst (int iloscUruchomienFirst)
{
    QSqlQuery query;
    //qWarning() << "Jestem w pobierz ilosc First uruchomien";
    if (query.exec("SELECT * FROM dBStatRun WHERE id ='1'")) {
        while (query.next()) {
            //qWarning() << inti << " pobrany: " << query.value(3).toString();
            iloscUruchomienFirst = query.value(1).toInt();
            //qWarning() << "Ilosc uruchomien to : "<< iloscUruchomienFirst;
        }
        //qWarning() << "First udalo sie? : pozniej " << iloscUruchomienFirst;

    }
    return iloscUruchomienFirst;

}

QString MainDb::isNumerSeryjnyTheSame(QString nrSeryjnyZLini, int i)
{
    QSqlQuery query;
    QString testName = nrSeryjnyZLini;
    qWarning() << "Pobrana ilosc Urzadzen z ::Urzadzenia::" << i;

    QString inti = QString::number(i);

    QString name;
    if (query.exec("SELECT * FROM urzadzenia where id =" + inti)) {
        while (query.next()) {
            qWarning() << inti << " pobrany: " << query.value(3).toString();
            name = query.value(3).toString();
        }
        qWarning() << "udalo sie? : pozniej " << name;
        return name;
    }
    return 0;
}
int MainDb::isNumerSeryjnyTheSameId(int nrSeryjnyZLini)
{
    qWarning() << "Jestem w MainDB::isNumerSeryjnyTheSameId";
    qWarning() << "Przekazany Numer seryjny wprowadzany" << nrSeryjnyZLini;

    //TODO: Wczytac z bazy urzadzenia same numery seryjne

    QString testName;
    int rows = 0;
    //TODO: pobrac z Bazy Urzadzeń same numery seryjne
    QSqlQuery query;

    if (query.exec("SELECT * FROM urzadzenia")) {
        while (query.next()) {
            //qWarning() << query.value(1).toString();
            rows++;
        }
        //qWarning() << "row to: " << rows;
    }
    //qWarning() << "Wychodze z MainDB->pobierz Id z pobraną iloscia wpisów w bazie danych";
    return rows;
}

void MainDb::PrzypiszTestowo()

{
    QSqlQuery query;
    //Dodaje Miasta
    if (!query.exec("INSERT INTO miasta (miasto) VALUES('Szczecin')"))
        qWarning() << "MainDB::Dodoanie Modelu - ERROR: " << query.lastError().text();
    if (!query.exec("INSERT INTO miasta (miasto) VALUES('Wrocław')"))
        qWarning() << "MainDB::Dodoanie Modelu - ERROR: " << query.lastError().text();
    //------------------------------------------------------------------------
    //Dodaje Wojewodztwa
    qWarning() << ("Dodoaje do bazy  + Szczecin");
    if (!query.exec("INSERT INTO wojewodztwa (wojewodztwo) VALUES('Brak')"))
        qWarning() << "MainDB::Dodoanie Modelu - ERROR: " << query.lastError().text();
    if (!query.exec("INSERT INTO wojewodztwa (wojewodztwo) VALUES('Dolnośląskie')"))
        qWarning() << "MainDB::Dodoanie Modelu - ERROR: " << query.lastError().text();
    //---------------------------------------------------------------------------
    //Dodaje Producentów
    if (!query.exec("INSERT INTO producenci (producent) VALUES('Selvas')"))
        qWarning() << "MainDB::Dodoanie Modelu - ERROR: " << query.lastError().text();
    if (!query.exec("INSERT INTO producenci (producent) VALUES('Jawon')"))
        qWarning() << "MainDB::Dodoanie Modelu - ERROR: " << query.lastError().text();
    //----------------------------------------------------------------------------
    //dodaje Modele
    if (!query.exec("INSERT INTO modele (model) VALUES('IOI 353')"))
        qWarning() << "MainDB::Dodoanie Modelu - ERROR: " << query.lastError().text();
    if (!query.exec("INSERT INTO modele (model) VALUES('BC-310')"))
        qWarning() << "MainDB::Dodoanie Modelu - ERROR: " << query.lastError().text();
    //----------------------------------------------------------------------------

    //dodaje kontrahentow
    if (!query.exec("INSERT INTO  kontrahenci (nazwaFirmy , imie , nazwisko , kontrahent_panstwo_id , kontrahent_wojewodztwo_id , kontrahent_miasto_id , kodPocztowy , ulica , nrdomu , telefon , telefonPrywatny , adresEmail , stronaUrl ) VALUES('MarPaw10', 'Paw', 'Mar', 'Polska', 'Zachodniopomorskie' , 'Szczecin', '70-890', 'Maciejowicka', '20/123', '512052411', '723508531', 'serwsi@vbody.pl', 'www.vitako.pl')"))
        qWarning() << "MainDB::Dodoanie Modelu - ERROR: " << query.lastError().text();

    //query.exec("PRAGMA foreign_keys = ON;"); // włączenia kluczy obcych


}
QString MainDb::ObliczCzasUruchomien(QString DbSec,QString DbMin, QString DbGodz, QString DbDni)
{QSqlQuery query;
    qWarning() << "w Main DB ";
    qWarning() << "Ilosc sekund to " << DbSec;
    qWarning() << "Ilosc minut to " << DbMin;
    qWarning() << "Ilosc godzin to " << DbGodz;
    qWarning() << "Ilosc dni to " << DbDni;
    if (query.exec("UPDATE dBStatDays SET secunds = '" +DbSec+"' WHERE id ='1'")) {
        while (query.next()) {
            //qWarning() << inti << " pobrany: " << query.value(3).toString();
            //iloscUruchomien = query.value(1).toInt();
            //qWarning() << "Ilosc uruchomien to : "<< iloscUruchomien;
        }
        //qWarning() << "udalo sie? : pozniej " << iloscUruchomien;

    }
    if (query.exec("UPDATE dBStatDays SET minuts = '" +DbMin+"' WHERE id ='1'")) {
        while (query.next()) {
            //qWarning() << inti << " pobrany: " << query.value(3).toString();
            //iloscUruchomien = query.value(1).toInt();
            //qWarning() << "Ilosc uruchomien to : "<< iloscUruchomien;
        }
        //qWarning() << "udalo sie? : pozniej " << iloscUruchomien;

    }
    if (query.exec("UPDATE dBStatDays SET hours = '" +DbGodz+"' WHERE id ='1'")) {
        while (query.next()) {
            //qWarning() << inti << " pobrany: " << query.value(3).toString();
            //iloscUruchomien = query.value(1).toInt();
            //qWarning() << "Ilosc uruchomien to : "<< iloscUruchomien;
        }
        //qWarning() << "udalo sie? : pozniej " << iloscUruchomien;

    }
    if (query.exec("UPDATE dBStatDays SET days = '" +DbDni+"' WHERE id ='1'")) {
        while (query.next()) {
            //qWarning() << inti << " pobrany: " << query.value(3).toString();
            //iloscUruchomien = query.value(1).toInt();
            //qWarning() << "Ilosc uruchomien to : "<< iloscUruchomien;
        }
        //qWarning() << "udalo sie? : pozniej " << iloscUruchomien;

    }
    return 0;
}
int MainDb::PobierzCzasUruchomienDbSec(int DbSec)
{
    QSqlQuery query;
    qWarning() << "Jestem w pobierz ilosc secund";
    if (query.exec("SELECT * FROM dBStatDays WHERE id ='1'")) {
        while (query.next()) {
           // qWarning() << inti << " pobrany: " << query.value(3).toString();
            DbSec = query.value(6).toInt();
            //qWarning() << "Ilosc uruchomien to : "<< iloscUruchomienFirst;
        }
        //qWarning() << "First udalo sie? : pozniej " << iloscUruchomienFirst;

    }
    return DbSec;
}
int MainDb::PobierzCzasUruchomienDbMin(int DbMin)
{
    QSqlQuery query;
    qWarning() << "Jestem w pobierz ilosc minut";
    if (query.exec("SELECT * FROM dBStatDays WHERE id ='1'")) {
        while (query.next()) {
            // qWarning() << inti << " pobrany: " << query.value(3).toString();
            DbMin = query.value(5).toInt();
            //qWarning() << "Ilosc uruchomien to : "<< iloscUruchomienFirst;
        }
        //qWarning() << "First udalo sie? : pozniej " << iloscUruchomienFirst;

    }
    return DbMin;
}
int MainDb::PobierzCzasUruchomienDbGodz(int DbGodz)
{
    QSqlQuery query;
    qWarning() << "Jestem w pobierz ilosc godzin";
    if (query.exec("SELECT * FROM dBStatDays WHERE id ='1'")) {
        while (query.next()) {
            // qWarning() << inti << " pobrany: " << query.value(3).toString();
            DbGodz = query.value(4).toInt();
            //qWarning() << "Ilosc uruchomien to : "<< iloscUruchomienFirst;
        }
        //qWarning() << "First udalo sie? : pozniej " << iloscUruchomienFirst;

    }
    return DbGodz;
}
int MainDb::PobierzCzasUruchomienDbDni(int DbDni)
{
    QSqlQuery query;
    qWarning() << "Jestem w pobierz ilosc dni";
    if (query.exec("SELECT * FROM dBStatDays WHERE id ='1'")) {
        while (query.next()) {
            // qWarning() << inti << " pobrany: " << query.value(3).toString();
            DbDni = query.value(3).toInt();
            //qWarning() << "Ilosc uruchomien to : "<< iloscUruchomienFirst;
        }
        //qWarning() << "First udalo sie? : pozniej " << iloscUruchomienFirst;

    }
    return DbDni;
}