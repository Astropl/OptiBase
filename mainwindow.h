#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void InitDB();

private slots:
    void CheckIsFileExist();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_actionO_programie_triggered();
    void on_actionOpcje_triggered();
    void on_pushButton_8_clicked();
    void initWindow();
    void openInfo();
    void openSettings();

    void on_pushButton_9_clicked();
    void statsy();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
//Info do Gita
