#ifndef URZADZENIAPRZYPOMINACZ_H
#define URZADZENIAPRZYPOMINACZ_H

#include <QMainWindow>
#include <QStandardItemModel>


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

public slots:
void myfunctiontimer();
void initMenu();
void wczytajDane();
void changeCheckBoxaFalse();
void changeCheckBoxaTrue();


private:
    Ui::UrzadzeniaPrzypominacz *ui;
    QTimer *timer;
    QStandardItemModel *model1;
    QStandardItemModel *model2;
};

#endif // URZADZENIAPRZYPOMINACZ_H
