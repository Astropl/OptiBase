#ifndef MAGAZYN_H
#define MAGAZYN_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QTableView>


namespace Ui {
class Magazyn;
}

class Magazyn : public QMainWindow
{
    Q_OBJECT

public:
    explicit Magazyn(QWidget *parent = nullptr);
    ~Magazyn();
public slots:
    void wczytajDane();
    void myfunctiontimer();
    void initMenu();
    void statsy();
    void openInfo();
    void openSettings();
    void fillComboBoxes();
    void on_checkBox_stateChanged();

private slots:
    void on_btnExit_clicked();
    //void on_checkBox_stateChanged(int arg1);

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

private:
    Ui::Magazyn *ui;
    QTimer *timer;
    QStandardItemModel *model;
};

#endif // MAGAZYN_H
