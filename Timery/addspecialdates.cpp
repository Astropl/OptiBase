#include "addspecialdates.h"
#include "ui_addspecialdates.h"
#include <iostream>
#include <QDebug>
#include <QCalendarWidget>
#include <QDateEdit>


using namespace std;



AddSpecialDates::AddSpecialDates(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddSpecialDates)
{
    ui->setupUi(this);
    init();
}

AddSpecialDates::~AddSpecialDates()
{
    delete ui;
}

void AddSpecialDates::on_pushButton_clicked()
{
    destroy();

}

void AddSpecialDates::on_pushButton_2_clicked()
{
    qWarning()<<"Diodoaj i zapisz";
}

void AddSpecialDates::selectedDateChanged()
{qWarning()<<"selectedDateChanged";
    currentDateEdit->setDate(calendar->selectedDate());
}
void AddSpecialDates::minimumDateChanged(QDate date)
{
    calendar->setMinimumDate(date);
    maximumDateEdit->setDate(calendar->maximumDate());
}
void AddSpecialDates::maximumDateChanged(QDate date)
{
    calendar->setMaximumDate(date);
    minimumDateEdit->setDate(calendar->minimumDate());
}

void AddSpecialDates::init()
{
    calendar = new QCalendarWidget;
    calendar->setMinimumDate(QDate(1900, 1, 1));
    calendar->setMaximumDate(QDate(3000, 1, 1));
    calendar->setGridVisible (true);
    connect(calendar, &QCalendarWidget::currentPageChanged,
            this, &AddSpecialDates::reformatCalendarPage);
    connect(currentDateEdit, &QDateEdit::dateChanged,
            calendar, &QCalendarWidget::setSelectedDate);
    connect(calendar, &QCalendarWidget::selectionChanged,
            this, &AddSpecialDates::selectedDateChanged);


    currentDateEdit = new QDateEdit;
    currentDateEdit->setDisplayFormat("MMM d yyyy");
    currentDateEdit->setDate(calendar->selectedDate());
   currentDateEdit->setDateRange(calendar->minimumDate(),calendar->maximumDate());








//    connect(ui->lineEdit, &QDateEdit::dateChanged,
//            calendar, &QCalendarWidget::setSelectedDate);
//    connect(calendar, &QCalendarWidget::selectionChanged,
//            this, &AddSpecialDates::selectedDateChanged);
}
void AddSpecialDates::on_calendarWidget_clicked(const QDate )
{
    qWarning()<<"selectedDateChanged";
   // currentDateEdit->setDate(calendar->selectedDate());

    ui->lineEdit->setText(calendar->selectedDate().toString());
}
void AddSpecialDates::reformatCalendarPage()
{
    QTextCharFormat mayFirstFormat;
    const QDate mayFirst(calendar->yearShown(), 5, 1);

    QTextCharFormat firstFridayFormat;
    QDate firstFriday(calendar->yearShown(), calendar->monthShown(), 1);
    while (firstFriday.dayOfWeek() != Qt::Friday)
        firstFriday = firstFriday.addDays(1);

//    if (firstFridayCheckBox->isChecked()) {
//        firstFridayFormat.setForeground(Qt::blue);
//    } else { // Revert to regular colour for this day of the week.
//        Qt::DayOfWeek dayOfWeek(static_cast<Qt::DayOfWeek>(firstFriday.dayOfWeek()));
//        firstFridayFormat.setForeground(calendar->weekdayTextFormat(dayOfWeek).foreground());
//    }

    calendar->setDateTextFormat(firstFriday, firstFridayFormat);

    // When it is checked, "May First in Red" always takes precedence over "First Friday in Blue".
//    if (mayFirstCheckBox->isChecked()) {
//        mayFirstFormat.setForeground(Qt::red);
//    } else if (!firstFridayCheckBox->isChecked() || firstFriday != mayFirst) {
//        // We can now be certain we won't be resetting "May First in Red" when we restore
//        // may 1st's regular colour for this day of the week.
//        Qt::DayOfWeek dayOfWeek(static_cast<Qt::DayOfWeek>(mayFirst.dayOfWeek()));
//        calendar->setDateTextFormat(mayFirst, calendar->weekdayTextFormat(dayOfWeek));
//    }

    calendar->setDateTextFormat(mayFirst, mayFirstFormat);
}
