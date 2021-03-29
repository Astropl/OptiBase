#ifndef URZADZENIAPRZYPOMINACZ_H
#define URZADZENIAPRZYPOMINACZ_H

#include <QMainWindow>
#include <QStandardItemModel>
//#include <QStandardItem>


namespace Ui {
class UrzadzeniaPrzypominacz;
}

class UrzadzeniaPrzypominacz : public QMainWindow
{
    Q_OBJECT

public:
    explicit UrzadzeniaPrzypominacz(QWidget *parent = nullptr);
    ~UrzadzeniaPrzypominacz();

private slots:
    void on_pushButton_clicked();
    void on_checkBox_stateChanged(int arg1);
    void on_radioButton_clicked(bool checked);
    void on_radioButton_2_clicked(bool checked);
    void on_radioButton_3_clicked(bool checked);

    void on_pushButton_2_clicked();

public slots:
    void myfunctiontimer();
    void initMenu();
    void wczytajDane();
    void changeCheckBoxaFalse();
    void changeCheckBoxaTrue();
    void wczytajDoPrzypominacza();
    void wczytajDoWazneDaty();
    int PrzelecWazneDni(int iloscWaznychDni);

//QStandardItem *item ;
private:
    Ui::UrzadzeniaPrzypominacz *ui;
    QTimer *timer;
    QStandardItemModel *model1;
    QStandardItemModel *model2;
   // QStandardItem *item ;
};

#endif // URZADZENIAPRZYPOMINACZ_H
