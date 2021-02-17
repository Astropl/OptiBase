#ifndef INFO_H
#define INFO_H

#include <QMainWindow>

namespace Ui {
class Info;
}

class Info : public QMainWindow
{
    Q_OBJECT

public:
    explicit Info(QWidget *parent = nullptr);
    ~Info();
private slots:
    void on_pushButton_clicked();

private:
    Ui::Info *ui;
};

#endif // INFO_H
