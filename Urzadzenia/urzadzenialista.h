#ifndef URZADZENIALISTA_H
#define URZADZENIALISTA_H

#include <QMainWindow>
#include <QStandardItemModel>

namespace Ui {
class UrzadzeniaLista;
}

class UrzadzeniaLista : public QMainWindow
{
    Q_OBJECT

public:
    explicit UrzadzeniaLista(QWidget *parent = nullptr);
    ~UrzadzeniaLista();

public slots:

    void wczytajDane();
    void iloscWierszy();
    void myfunctiontimer();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();

private:
    Ui::UrzadzeniaLista *ui;
    QTimer *timer;
    QStandardItemModel *model;
};

#endif // URZADZENIALISTA_H
