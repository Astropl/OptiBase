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
void loadInfoOTemacie();


private slots:
void on_pushButton_clicked();

private:
    Ui::Wpisy *ui;
private:
    QTimer *timer;
    QStandardItemModel *model;

};

#endif // WPISY_H
