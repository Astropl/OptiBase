#ifndef URZADZENIADODAJSERYJNIE_H
#define URZADZENIADODAJSERYJNIE_H

#include <QMainWindow>

namespace Ui {
class UrzadzeniaDodajSeryjnie;
}

class UrzadzeniaDodajSeryjnie : public QMainWindow
{
    Q_OBJECT

public:
    explicit UrzadzeniaDodajSeryjnie(QWidget *parent = nullptr);
    ~UrzadzeniaDodajSeryjnie();

private slots:
    void on_pushButton_clicked();
    void initMenuUrzadzenia();
void fillComboBoxes();
void wypelnijModel();

void wypelnijProducenta();

void on_comboBox_2_highlightedExit(int checkFlagsVariableModel);
void on_comboBox_highlightedExit(int checkFlagsVariableProducent);
void on_pushButton_3_clicked();

void on_pushButton_2_clicked();


public slots:

QString changeIconColor(QString colorIcon);

private:
    Ui::UrzadzeniaDodajSeryjnie *ui;
};

#endif // URZADZENIADODAJSERYJNIE_H
