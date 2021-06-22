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
    void setLabelsTrue();

    void setLabelsFalse();
    QVariant setLabelsInfo(QVariant lp, QVariant producent, QVariant model, QVariant nrSeryjny, QVariant przypisany, QVariant kontrahent);
    void wypelnijProducenta();
    void wypelnijModel();
    void initFrame();


private slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

private:
    Ui::UrzadzeniaListaEdytuj *ui;
    QTimer *timer;
};

#endif // URZADZENIALISTAEDYTUJ_H
