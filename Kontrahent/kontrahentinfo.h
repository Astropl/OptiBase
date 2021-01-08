#ifndef KONTRAHENTINFO_H
#define KONTRAHENTINFO_H

#include <QMainWindow>
#include <QStandardItemModel>

namespace Ui {
class KontrahentInfo;
}

class KontrahentInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit KontrahentInfo(QWidget *parent = nullptr);
    ~KontrahentInfo();

public slots:
    void wyswietl(QVariant p1,
                  QVariant p2,
                  QVariant p3,
                  QVariant p4,
                  QVariant p5,
                  QVariant p6,
                  QVariant p7,
                  QVariant p8,
                  QVariant p9,
                  QVariant p10,
                  QVariant p11,
                  QVariant p12,
                  QVariant p13,
                  QVariant p14,
                  QVariant p15,
                  QVariant p16,
                  QVariant p17,
                  QVariant p18,
                  QVariant p19,
                  QVariant p20);
    void myfunctiontimer();
    void wczytajDane();
    void showTable();
    void pobierzDane();
    void loadWpis();
    void initMenuBazy();


private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

signals:
public:
    Ui::KontrahentInfo *ui;

private:

    QTimer *timer;
    QStandardItemModel *model;
};

#endif // KONTRAHENTINFO_H
