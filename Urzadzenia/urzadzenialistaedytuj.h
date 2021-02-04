#ifndef URZADZENIALISTAEDYTUJ_H
#define URZADZENIALISTAEDYTUJ_H

#include <QMainWindow>

namespace Ui {
class UrzadzeniaListaEdytuj;
}

class UrzadzeniaListaEdytuj : public QMainWindow
{
    Q_OBJECT

public:
    explicit UrzadzeniaListaEdytuj(QWidget *parent = nullptr);
    ~UrzadzeniaListaEdytuj();


public slots:
    void myfunctiontimer();


private slots:
    void on_pushButton_clicked();

private:
    Ui::UrzadzeniaListaEdytuj *ui;
    QTimer *timer;
};

#endif // URZADZENIALISTAEDYTUJ_H
