#include "info.h"
#include "ui_info.h"

Info::Info(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Info)
{
    ui->setupUi(this);
}

Info::~Info()
{
    delete ui;
}
void Info::on_pushButton_clicked()
{
    destroy();
}