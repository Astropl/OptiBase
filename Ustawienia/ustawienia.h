#ifndef USTAWIENIA_H
#define USTAWIENIA_H

#include <QMainWindow>

namespace Ui {
class Ustawienia;
}

class Ustawienia : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ustawienia(QWidget *parent = nullptr);
    ~Ustawienia();
    QString pobierzDate(QString aktHour);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Ustawienia *ui;
};

#endif // USTAWIENIA_H
