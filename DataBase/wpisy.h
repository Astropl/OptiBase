#ifndef WPISY_H
#define WPISY_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QTableView>

namespace Ui {
class Wpisy;
}

class Wpisy : public QMainWindow
{
    Q_OBJECT

public:
    explicit Wpisy(QWidget *parent = nullptr);
    ~Wpisy();

public slots:
    void initWindow();
    void myfunctiontimer();
    void showTable();
    void loadWpis();
    void openInfo();

    void openSettings();
    void statsy();
   // void loadInfoOTemacie();

private slots:
    void on_pushButton_clicked();

    void on_checkBox_stateChanged();
    void fillComboBoxes();

    void on_comboBox_activated(const QString);

    void on_comboBox_3_activated(const QString);

    QString filtrOn(QString aktywnyFiltr);

    void on_comboBox_2_activated(const QString);

private:
    Ui::Wpisy *ui;

private:
    QTimer *timer;
    QStandardItemModel *model;
};

#endif // WPISY_H
