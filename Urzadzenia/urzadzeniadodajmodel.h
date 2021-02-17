#ifndef URZADZENIADODAJMODEL_H
#define URZADZENIADODAJMODEL_H

#include <QMainWindow>

namespace Ui {
class UrzadzeniaDodajModel;
}

class UrzadzeniaDodajModel : public QMainWindow
{
    Q_OBJECT

public:
    explicit UrzadzeniaDodajModel(QWidget *parent = nullptr);
    ~UrzadzeniaDodajModel();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::UrzadzeniaDodajModel *ui;
};

#endif // URZADZENIADODAJMODEL_H
    //Info do Gita