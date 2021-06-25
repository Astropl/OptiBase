#ifndef KONTRAHENTSHOW_H
#define KONTRAHENTSHOW_H

#include <QMainWindow>

namespace Ui {
class KontrahentShow;
}

class KontrahentShow : public QMainWindow
{
    Q_OBJECT

public:
    explicit KontrahentShow(QWidget *parent = nullptr);
    ~KontrahentShow();

public slots:

    //KontrahentShow(QString pierwszazmienna);
    void showCities(); //jest
    void showWojewodztwa(); //jest
    void showKraj(); //jest
    void unblock(); //jest
    QVariant wyswietl(QVariant p1,
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
                      QVariant p14); //jest
private slots:
    void on_pushButton_2_clicked();//jest
    void on_pushButton_clicked(); //jest
    void on_pushButton_3_clicked(); //jest
    void on_pushButton_4_clicked(); //jest
    void on_comboBoxKraj_highlighted(const QString); //jest
    void on_comboBoxWojewodztwa_highlighted(const QString); //jest
    void on_comboBoxMiasta_highlighted(const QString); //jest

private:
    Ui::KontrahentShow *ui;
};

#endif