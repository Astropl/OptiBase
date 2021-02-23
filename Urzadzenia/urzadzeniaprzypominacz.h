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


public slots:
void myfunctiontimer();
void initMenu();
void wczytajDane();



private:
    Ui::UrzadzeniaPrzypominacz *ui;
    QTimer *timer;
    QStandardItemModel *model1;
    QStandardItemModel *model2;
};

#endif // URZADZENIAPRZYPOMINACZ_H
