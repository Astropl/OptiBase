#include "wpisy.h"
#include "ui_wpisy.h"
#include <QTableView>
#include <QDebug>

Wpisy::Wpisy(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Wpisy)
{
    ui->setupUi(this);
    qDebug()<<"Jstem w Wpisy";
}

Wpisy::~Wpisy()
{
    delete ui;
}
