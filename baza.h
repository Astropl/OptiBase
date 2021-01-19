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

    void filtrOn();
    void fillComboBoxes();
private:
    Ui::Baza *ui;

private slots:
    void on_pushButton_2_clicked();

    void on_checkBox_stateChanged();


private:
    QTimer *timer;
    QStandardItemModel *model;
};

#endif // BAZA_H
