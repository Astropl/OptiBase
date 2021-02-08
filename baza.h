#ifndef BAZA_H
#define BAZA_H

#include <QMainWindow>
#include <QDialog>
#include <QItemDelegate>

#include <QStandardItemModel>
#include <QTableView>

namespace Ui {
class Baza;
}

class Baza : public QMainWindow
{
    Q_OBJECT

public:
    explicit Baza(QWidget *parent = nullptr);
    ~Baza();
public slots:
    void on_pushButton_clicked();
    void myfunctiontimer();
    void DataiCzas();
    void wczytajDane();
    void iloscWierszy(int iTabelaPustychRzedow);
    void initMenuBazy();

    QString  filtrOn(QString aktywnyProducent);
    void fillComboBoxes();

    void openInfo();

    void openSettings();

private:
    Ui::Baza *ui;

private slots:
    void on_pushButton_2_clicked();

    void on_checkBox_stateChanged();


    void on_comboBox_5_activated(const QString &arg1);

    void on_comboBox_6_activated(const QString &arg1);

    void on_comboBox_7_activated(const QString &arg1);

    void on_comboBox_8_activated(const QString &arg1);

    void on_comboBox_9_activated(const QString &arg1);

    void on_lineEditSzukaj_textEdited(const QString );

    void on_pushButton_3_clicked();

private:
    QTimer *timer;
    QStandardItemModel *model;
};

#endif // BAZA_H
