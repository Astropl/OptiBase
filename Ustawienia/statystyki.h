#ifndef STATYSTYKI_H
#define STATYSTYKI_H

#include <QMainWindow>

namespace Ui {
class Statystyki;
}

class Statystyki : public QMainWindow
{
    Q_OBJECT

public:
    explicit Statystyki(QWidget *parent = nullptr);
    ~Statystyki();

public slots:
    void myfunctiontimer();
    void liczbaUruchomien();
    void liczbaUruchomienFirst ();
    void czasUruchomien();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Statystyki *ui;
    QTimer *timer;
};

#endif // STATYSTYKI_H
