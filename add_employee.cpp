#include "add_employee.h"
#include "ui_add_employee.h"

add_employee::add_employee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_employee)
{
    ui->setupUi(this);
}

add_employee::~add_employee()
{
    delete ui;
}
