#ifndef MAINDB_H
#define MAINDB_H

#include <QObject>
#include <QWidget>
#include <QMainWindow>
class MainDb: public QMainWindow
{
public:
   explicit MainDb(QWidget *parent = nullptr);
    void init();
    void DatabaseConnect();
    void DatabaseInit();
    void DatabasePopulate();
};

#endif // MAINDB_H
