#ifndef URZADZENIADODAJNRSERYJNY_H
#define URZADZENIADODAJNRSERYJNY_H

#include <QMainWindow>

namespace Ui {
class UrzadzeniaDodajNrSeryjny;
}

class UrzadzeniaDodajNrSeryjny : public QMainWindow
{
    Q_OBJECT

public:
    explicit UrzadzeniaDodajNrSeryjny(QWidget *parent = nullptr);
    ~UrzadzeniaDodajNrSeryjny();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::UrzadzeniaDodajNrSeryjny *ui;
};

#endif // URZADZENIADODAJNRSERYJNY_H
    //Info do Gita