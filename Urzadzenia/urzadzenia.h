#ifndef URZADZENIA_H
#define URZADZENIA_H

#include <QDebug>
#include <QMainWindow>
#include <QMessageBox>
#include <QShortcut>
#include <QStringListModel>

namespace Ui {
class Urzadzenia;
}

class Urzadzenia : public QMainWindow
{
    Q_OBJECT
    // Podpinam pierwszą listWiew
    QStringListModel *countriesListModel;
    QString country;
    QShortcut *shDelete;

public:
    explicit Urzadzenia(QWidget *parent = nullptr);
    ~Urzadzenia();

public slots:

    void myfunctiontimer();

private slots:
    void on_BtnUrzaZapisz_clicked();
    void on_BtnUrzaZamknij_clicked();
    void on_countriesList_clicked(const QModelIndex &index);
    void on_comboBox_textActivated(const QString);
    void on_comboBox_2_textActivated(const QString);
    void on_comboBox_3_textActivated(const QString);
    void on_actionDodaj_Model_triggered();
    void on_actionDodaj_Producenta_triggered();
    void on_actionDodaj_Numer_Seryjny_triggered();
    void on_actionInformacja_triggered();
    void on_actionOpcje_triggered();
    void on_pushButton_clicked();
    void howMuchDevice();
    void wczytajProducenta();
    void wczytajModel();
    void on_comboBox_highlighted(const QString);
    void on_comboBox_2_highlighted(const QString);

private:
    Ui::Urzadzenia *ui;
    QTimer *timer;
};

#endif
