#ifndef ADDSPECIALDATESIMPORTANT_H
#define ADDSPECIALDATESIMPORTANT_H
#include "QCalendarWidget"
#include <QMainWindow>
#include <QDateTime>


QT_BEGIN_NAMESPACE
class QCalendarWidget;
class QCheckBox;
class QComboBox;
class QDate;
class QDateEdit;
class QGridLayout;
class QGroupBox;
class QLabel;
QT_END_NAMESPACE


namespace Ui {
class AddSpecialDatesImportant;
}

class AddSpecialDatesImportant : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddSpecialDatesImportant(QWidget *parent = nullptr);
    ~AddSpecialDatesImportant();

public slots:
    void on_calendarWidget_clicked(const QDate );
    void  initShow();
    void selectionChanged();
    void testcos();
    void createDatesGroupBox();
    void selectedDateChanged();
    void initMenu();

    void openInfo();

    void openSettings();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AddSpecialDatesImportant *ui;
    QCalendarWidget *calendar = new QCalendarWidget;
    QDateEdit *currentDateEdit;
    QDateEdit *minimumDateEdit;
    QDateEdit *maximumDateEdit;
};

#endif // ADDSPECIALDATESIMPORTANT_H
