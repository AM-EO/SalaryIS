#include "add_ill.h"
#include "ui_add_ill.h"

add_ill::add_ill(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_ill)
{
    ui->setupUi(this);
}

add_ill::~add_ill()
{
    delete ui;
}
