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
    void initMenuUrzadzeniaLista();
    void openSettings();
    void openInfo();
    void fillComboBoxes();

    void on_comboBox_activated(const QString &arg1);


    void on_comboBox_2_activated(const QString &arg1);

    void on_comboBox_3_activated(const QString &arg1);

    QString filtrOn(QString aktywnyProducent);


private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();

    void on_checkBox_stateChanged();

    void on_chbLast10_stateChanged();

    void on_checkBox_2_stateChanged();

private:
    Ui::UrzadzeniaLista *ui;
    QTimer *timer;
    QStandardItemModel *model;
};

#endif // URZADZENIALISTA_H
