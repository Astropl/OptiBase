#ifndef KONTRAHENTDODAJWOJEWODZTWO_H
#define KONTRAHENTDODAJWOJEWODZTWO_H

#include <QMainWindow>

namespace Ui {
class KontrahentDodajWojewodztwo;
}

class KontrahentDodajWojewodztwo : public QMainWindow
{
    Q_OBJECT

public:
    explicit KontrahentDodajWojewodztwo(QWidget *parent = nullptr);
    ~KontrahentDodajWojewodztwo();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

private:
    Ui::KontrahentDodajWojewodztwo *ui;
};

#endif // KONTRAHENTDODAJWOJEWODZTWO_H
    //Info do Gita