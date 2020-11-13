#ifndef KONTRAHENTINFODODAJWPIS_H
#define KONTRAHENTINFODODAJWPIS_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QTableView>


namespace Ui {
class KontrahentInfoDodajWpis;
}

class KontrahentInfoDodajWpis : public QMainWindow
{
    Q_OBJECT

public:
    explicit KontrahentInfoDodajWpis(QWidget *parent = nullptr);
    ~KontrahentInfoDodajWpis();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_checkBox_stateChanged(int arg1);
    void checkedCheckBox();

    void uncheckedCheckBox();
    void setDate();
    void myfunctiontimer();
    //int myfunctiontimerDoDaty(int godzina,int minuta,int sekunda,int dzien,int miesiac,int rok,int dzienTygodnia);

    void on_comboBox_currentTextChanged(const QString);

public:
    void init();
    QString setSettingsId(QString IdUrz, QString IdKontr );


private:
    Ui::KontrahentInfoDodajWpis *ui;
    QStandardItemModel *model;
    QTimer *timer;
};

#endif // KONTRAHENTINFODODAJWPIS_H
