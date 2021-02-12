#ifndef URZADZENIAPRZYPOMINACZ_H
#define URZADZENIAPRZYPOMINACZ_H

#include <QMainWindow>

namespace Ui {
class UrzadzeniaPrzypominacz;
}

class UrzadzeniaPrzypominacz : public QMainWindow
{
    Q_OBJECT

public:
    explicit UrzadzeniaPrzypominacz(QWidget *parent = nullptr);
    ~UrzadzeniaPrzypominacz();

private slots:
    void on_pushButton_clicked();


public slots:
void myfunctiontimer();

private:
    Ui::UrzadzeniaPrzypominacz *ui;
    QTimer *timer;
};

#endif // URZADZENIAPRZYPOMINACZ_H
