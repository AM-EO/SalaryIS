#include "edit_ill.h"
#include "ui_edit_ill.h"

edit_ill::edit_ill(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit_ill)
{
    ui->setupUi(this);
}

edit_ill::~edit_ill()
{
    delete ui;
}
