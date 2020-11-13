#ifndef URZADZENIALISTAKONTRAHENT_H
#define URZADZENIALISTAKONTRAHENT_H

#include <QDialog>
#include <QItemDelegate>
#include <QMainWindow>

#include <QStandardItemModel>
#include <QTableView>
namespace Ui {
class UrzadzeniaListaKontrahent;
}

class UrzadzeniaListaKontrahent : public QMainWindow
{
    Q_OBJECT

public:
    explicit UrzadzeniaListaKontrahent(QWidget *parent = nullptr);
    ~UrzadzeniaListaKontrahent();
public slots:

    void wczytajDane();
    void iloscWierszy();
    void myfunctiontimer();
    void wyswietl(QVariant p1, QVariant p2, QVariant p3, QVariant p4);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::UrzadzeniaListaKontrahent *ui;
    QTimer *timer;
    QStandardItemModel *model;
};

#endif // URZADZENIALISTAKONTRAHENT_H
