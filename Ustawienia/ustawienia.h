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
    void initMenuSettings ();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_checkBox_stateChanged();

    void on_pushButton_6_clicked();
    void initAutomatBackup();

private:
    Ui::Ustawienia *ui;
};

#endif // USTAWIENIA_H
