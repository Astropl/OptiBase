#ifndef MAGAZYN_H
#define MAGAZYN_H

#include <QMainWindow>

namespace Ui {
class Magazyn;
}

class Magazyn : public QMainWindow
{
    Q_OBJECT

public:
    explicit Magazyn(QWidget *parent = nullptr);
    ~Magazyn();

private slots:
    void on_btnExit_clicked();

private:
    Ui::Magazyn *ui;
};

#endif // MAGAZYN_H
