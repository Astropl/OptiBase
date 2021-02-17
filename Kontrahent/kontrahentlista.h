#ifndef KONTRAHENTLISTA_H
#define KONTRAHENTLISTA_H

#include <QDialog>
#include <QItemDelegate>
#include <QMainWindow>
#include <QStandardItemModel>
#include <QTableView>

namespace Ui {
class KontrahentLista;
}

class KontrahentLista : public QMainWindow
{
    Q_OBJECT

public:
    explicit KontrahentLista(QWidget *parent = 0);
    ~KontrahentLista();
public slots:
    //    int zmianaLabela(
    //        int godzina, int minuta, int sekunda, int dzien, int miesiac, int rok, int dzienTygodnia);
    void wczytajDane();
    void myfunctiontimer();
    void iloscWierszy();
    void initMenuKontrahentLista();
private slots:
    void on_pushButton_2_clicked();
    void on_tableView_activated(const QModelIndex);

    void on_tableView_doubleClicked(const QModelIndex); //(const QModelIndex &index);

    void on_tableView_clicked(const QModelIndex); //(const QModelIndex &index)

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::KontrahentLista *ui;
    QTimer *timer;
    QStandardItemModel *model;
};

#endif // KONTRAHENTLISTA_H
    //Info do Gita