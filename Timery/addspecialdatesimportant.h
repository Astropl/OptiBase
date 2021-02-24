#ifndef ADDSPECIALDATESIMPORTANT_H
#define ADDSPECIALDATESIMPORTANT_H
#include "QCalendarWidget"
#include <QMainWindow>

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
private:
    Ui::AddSpecialDatesImportant *ui;
    QCalendarWidget *calendar = new QCalendarWidget;
};

#endif // ADDSPECIALDATESIMPORTANT_H
