#ifndef KONTRAHENTDODAJKRAJ_H
#define KONTRAHENTDODAJKRAJ_H

#include <QMainWindow>

namespace Ui {
class KontrahentDodajKraj;
}

class KontrahentDodajKraj : public QMainWindow
{
    Q_OBJECT

public:
    explicit KontrahentDodajKraj(QWidget *parent = nullptr);
    ~KontrahentDodajKraj();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::KontrahentDodajKraj *ui;
};

#endif // KONTRAHENTDODAJKRAJ_H