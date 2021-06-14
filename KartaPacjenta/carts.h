#ifndef CARTS_H
#define CARTS_H

#include <QMainWindow>
#include <QStandardItemModel>
namespace Ui {
class Carts;
}

class Carts : public QMainWindow
{
    Q_OBJECT

public:
    explicit Carts(QWidget *parent = nullptr);
    ~Carts();
void init();



private slots:
    void on_btnExit_clicked();

    void on_pushButton_clicked();

private:
    Ui::Carts *ui;
     QStandardItemModel *model;
};

#endif // CARTS_H
