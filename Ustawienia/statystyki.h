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
    void myfunctiontimer();


private:
    Ui::Statystyki *ui;
    QTimer *timer;
};

#endif // STATYSTYKI_H
