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


public slots:
    void init();
    QString setSettingsId(QString NrSeryjny );
    int dodajDateKolejnegoWpisu(int dzien, int miesiac, int rok);


    //void initMenuBazy();


    void openInfo();
    void openSettings();
    //void InfoTemat();
    void openDodajTemat();
//    void on_actionOprogramie_triggered();
//    void on_actionOpenSettings_triggered();
//    void on_actionOpcje_triggered();
//    void on_actionInfoTemat_triggered();
    void loadInfoOTemacie();


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
    void initMenu();
    void on_comboBox_currentIndexChanged(const QString);



    void on_comboBox_2_textActivated(const QString);

    //void on_comboBox_2_activated(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_checkBox_2_stateChanged();

    void on_checkBox_4_stateChanged();

    void on_checkBox_5_stateChanged();

    void on_checkBox_6_stateChanged();

    void on_checkBox_3_stateChanged();
    QString addTextEdit2(QString getTextFromTextEdit);

private:
    Ui::KontrahentInfoDodajWpis *ui;
    QStandardItemModel *model;
    QTimer *timer;
};

#endif // KONTRAHENTINFODODAJWPIS_H
