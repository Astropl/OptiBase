#include "addspecialdatesimportant.h"
#include "DataBase/maindb.h"
#include "Ustawienia/statystyki.h"
#include "Ustawienia/ustawienia.h"
#include "ui_addspecialdatesimportant.h"
#include <Info/info.h>
#include <iostream>
#include <QCalendarWidget>
#include <QDateEdit>
#include <QDebug>
#include <QLabel>

AddSpecialDatesImportant::AddSpecialDatesImportant(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AddSpecialDatesImportant)
{
    ui->setupUi(this);
    initMenu();
    initShow();

    createDatesGroupBox();
}

AddSpecialDatesImportant::~AddSpecialDatesImportant()
{
    delete ui;
}

void AddSpecialDatesImportant::createDatesGroupBox()
{
    //    minimumDateEdit = new QDateEdit;
    //    minimumDateEdit->setDisplayFormat("MMM d yyyy");
    //    minimumDateEdit->setDateRange(calendar->minimumDate(),
    //                                  calendar->maximumDate());
    //    minimumDateEdit->setDate(calendar->minimumDate());

    //    currentDateEdit = new QDateEdit;
    //    currentDateEdit->setDisplayFormat("MMM d yyyy");
    //    currentDateEdit->setDate(calendar->selectedDate());
    //    currentDateEdit->setDateRange(calendar->minimumDate(),
    //                                  calendar->maximumDate());
    //    maximumDateEdit = new QDateEdit;
    //    maximumDateEdit->setDisplayFormat("MMM d yyyy");
    //    maximumDateEdit->setDateRange(calendar->minimumDate(),
    //                                  calendar->maximumDate());
    //    maximumDateEdit->setDate(calendar->maximumDate());

    //    connect(currentDateEdit, &QDateEdit::dateChanged,
    //            calendar, &QCalendarWidget::setSelectedDate);
    //    connect(calendar, &QCalendarWidget::selectionChanged,
    //            this, &AddSpecialDatesImportant::selectedDateChanged);
    //    connect(minimumDateEdit, &QDateEdit::dateChanged,
    //            this, &QCalendarWidget::minimumDateChanged);
    //    connect(maximumDateEdit, &QDateEdit::dateChanged,
    //            this, &QCalendarWidget::maximumDateChanged);
}

void AddSpecialDatesImportant::on_calendarWidget_clicked(const QDate)
{
    qWarning() << "on_calendarWidget_clicked(const QDate";
    QDate dataCurrent = QDate();

    // dataCurrent->DateFormat("dd.MM.yyyy");
    calendar->setSelectedDate(calendar->selectedDate());
    qWarning() << "zmiana daty z: " << calendar->selectedDate().toString()
               << " Na: " << ui->calendarWidget->selectedDate();
    //ui->label->setText(calendar->selectedDate().toString());
    //ui->label_2->setText(calendar->)
    //connect(calendar, calendar->selectedDate(), this, &AddSpecialDatesImportant::testcos);
    //ui->lineEdit->setEnabled(false);

    QString da=ui->calendarWidget->selectedDate().toString("yyyy/MM/dd");
    qWarning()<<"on calnendar click: "<<da;
    ui->lineEdit->setText(da);
    //ui->lineEdit->setText(ui->calendarWidget->selectedDate().toString());
}
void AddSpecialDatesImportant::selectedDateChanged()
{
    qWarning() << "selectedDateChanged";
    currentDateEdit->setDate(calendar->selectedDate());
}

void AddSpecialDatesImportant::initShow()
{
    //QCalendarWidget *calendar = new QCalendarWidget;
    ui->lineEdit->setEnabled(false);
    calendar->selectedDate();
    calendar->setGridVisible(true);
    calendar->setDateEditEnabled(true);
    //    calendar->setMaximumDate(QDate(2023,7,3));
    //    calendar->setMinimumDate(QDate(2002, 6, 19));

    qWarning() << "Data to: " << calendar->selectedDate();
    //calendar->setSelectedDate("2021");
    // ui->label->setText(calendar->selectedDate().toString());
}
void AddSpecialDatesImportant::selectionChanged()
{
    qWarning() << "selectionChanged";
    //ui->label->setText(calendar->selectedDate().toString());
}
void AddSpecialDatesImportant::testcos()
{
    qWarning() << "stestcos";
    //ui->label->setText(calendar->selectedDate().toString());
}
void AddSpecialDatesImportant::on_pushButton_clicked() //exit
{
    destroy();
}
void AddSpecialDatesImportant::initMenu()
{
    //Inicjalizacja menu

    //tworze menu kontekstowe
    setWindowTitle("OptiBase v 1.0:Kalendarz - Dodawanie Ważnych dat");

    //    QAction *fileSave = new QAction(("&Zapisz"), this);
    //    QAction *fileEksport = new QAction(("&Eksport"), this);
    // QAction *fileseparator = new QAction(("----------"), this);
    QAction *fileWyjscie = new QAction(("&Wyjście"), this);

    QAction *edycjaDodajKraj = new QAction(("Dodaj Kraj"), this);
    QAction *edycjaDodajWojewodztwo = new QAction(("Dodaj Województwo"), this);
    QAction *edycjaDodajMiasto = new QAction(("Dodaj Miasto"), this);
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

    mainEdycja->addAction(edycjaDodajKraj);
    mainEdycja->addAction(edycjaDodajWojewodztwo);
    mainEdycja->addAction(edycjaDodajMiasto);

    //    mainEdycja->addAction(editKopiuj);
    //    mainEdycja->addAction(editWklej);
    mainInfo->addAction(infoOProgramie);
    mainInfo->addAction(infoOAutorze);
    mainInfo->addAction(infoLog);

    mainSettings->addAction(settingsOption);

    connect(settingsOption, SIGNAL(triggered()), this, SLOT(openSettings()));
    connect(infoOProgramie, SIGNAL(triggered()), this, SLOT(openInfo()));
}
void AddSpecialDatesImportant::openInfo()
{
    Info *info = new Info(this);
    info->show();
}
void AddSpecialDatesImportant::openSettings()
{
    Ustawienia *ustaw = new Ustawienia(this);
    ustaw->show();
}
void AddSpecialDatesImportant::on_pushButton_2_clicked() //Zapiszi wyjdz
{
    //Zapiszi wyjdz
    QDate QdataWazne;
    MainDb *mainDb = new MainDb(this);
    QString dataWazneDaty, tematWazneDaty, infoWazneDaty;
    //qWarning() << "Wazna data :QdataWazne to: " << QdataWazne;
    dataWazneDaty = ui->lineEdit->text();
    qWarning() << "Przed zmiana :QdataWazne to: " << dataWazneDaty;
    //QdataWazne = QDate::toString(dataWazneDaty, "dd.MM.yyyy");
    //QDate da = QDate::fromString(dataWazneDaty, "dd.MM.yyyy");

    //dataWazneDaty.toString()

    //qWarning() << "Wazna data :da to: " << da;
    tematWazneDaty = ui->lineEdit_2->text();
    infoWazneDaty = ui->lineEdit_3->text();
    mainDb->pobierzWazneDatyZapis(dataWazneDaty, tematWazneDaty, infoWazneDaty);

    // mainDb->pobierzWazneDatyZapis(dataWazneDaty, tematWazneDaty, infoWazneDaty);
}
