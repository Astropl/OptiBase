#ifndef WPISY_H
#define WPISY_H

#include <QMainWindow>

namespace Ui {
class Wpisy;
}

class Wpisy : public QMainWindow
{
    Q_OBJECT

public:
    explicit Wpisy(QWidget *parent = nullptr);
    ~Wpisy();

private:
    Ui::Wpisy *ui;
};

#endif // WPISY_H
