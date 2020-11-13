#ifndef URZADZENIADODAJPRODUCENTA_H
#define URZADZENIADODAJPRODUCENTA_H

#include <QMainWindow>

namespace Ui {
class UrzadzeniaDodajProducenta;
}

class UrzadzeniaDodajProducenta : public QMainWindow
{
    Q_OBJECT

public:
    explicit UrzadzeniaDodajProducenta(QWidget *parent = nullptr);
    ~UrzadzeniaDodajProducenta();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

private:
    Ui::UrzadzeniaDodajProducenta *ui;
};

#endif