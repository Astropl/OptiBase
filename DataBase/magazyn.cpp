#include "magazyn.h"
#include "ui_magazyn.h"

Magazyn::Magazyn(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Magazyn)
{
    ui->setupUi(this);
}

Magazyn::~Magazyn()
{
    delete ui;
}

void Magazyn::on_btnExit_clicked() // Exit
{
    destroy();
}
