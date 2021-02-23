#ifndef ADDSPECIALDATES_H
#define ADDSPECIALDATES_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
class QCalendarWidget;
class QDateEdit;
QT_END_NAMESPACE


namespace Ui {
class AddSpecialDates;
}

class AddSpecialDates : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddSpecialDates(QWidget *parent = nullptr);
    ~AddSpecialDates();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_calendarWidget_clicked(const QDate );
    void reformatCalendarPage();
    void selectedDateChanged();
    void minimumDateChanged(QDate date);
    void maximumDateChanged(QDate date);

    QDateEdit *currentDateEdit;
    QDateEdit *minimumDateEdit;
    QDateEdit *maximumDateEdit;
public slots:

    void init();

private:
    Ui::AddSpecialDates *ui;
    QCalendarWidget *calendar;
};

#endif // ADDSPECIALDATES_H
