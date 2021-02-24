#include "addspecialdatesimportant.h"
#include "ui_addspecialdatesimportant.h"
#include <iostream>
#include <QDebug>


AddSpecialDatesImportant::AddSpecialDatesImportant(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddSpecialDatesImportant)
{
    ui->setupUi(this);

    initShow();
}

AddSpecialDatesImportant::~AddSpecialDatesImportant()
{
    delete ui;
}

void AddSpecialDatesImportant::on_calendarWidget_clicked(const QDate)
{
    qWarning()<<"zmiana daty"<<calendar->selectedDate().toString();
     ui->label->setText(calendar->selectedDate().toString());
     //ui->label_2->setText(calendar->)
}


void AddSpecialDatesImportant:: initShow()
{
    //QCalendarWidget *calendar = new QCalendarWidget;
    calendar->selectedDate();
    calendar->setGridVisible(true);
    calendar->setDateEditEnabled(true);
    calendar->setMaximumDate(QDate(2023,7,3));
    calendar->setMinimumDate(QDate(2002, 6, 19));

    qWarning()<<"Data to: " <<calendar->selectedDate();
    //calendar->setSelectedDate("2021");
   // ui->label->setText(calendar->selectedDate().toString());
}
void AddSpecialDatesImportant:: selectionChanged()
{
     //ui->label->setText(calendar->selectedDate().toString());
}