#include "edit_employee.h"
#include "ui_edit_employee.h"

edit_employee::edit_employee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit_employee)
{
    ui->setupUi(this);
}

edit_employee::~edit_employee()
{
    delete ui;
}
