#include "add_employee.h"
#include "ui_add_employee.h"
#include <QSqlQuery>
#include <QMessageBox>

add_employee::add_employee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_employee)
{
    ui->setupUi(this);
    setTabOrder(ui->lastname, ui->firstname);
    setTabOrder(ui->firstname, ui->secondname);
    setTabOrder(ui->secondname, ui->position);
    setTabOrder(ui->position, ui->salary);
    setTabOrder(ui->salary, ui->family);
    setTabOrder(ui->family, ui->children);
    setTabOrder(ui->children, ui->confirm);
    setTabOrder(ui->confirm, ui->cancel);
}

add_employee::~add_employee()
{
    delete ui;
}
void add_employee::setData(){
    last_name = ui->lastname->text();
    first_name = ui->firstname->text();
    second_name = ui->secondname->text();
    position = ui->position->text();
    salary = ui->salary->text();
    family = ui->family->text();
    children = ui->children->text();
}

void add_employee::on_confirm_clicked()
{
    setData();
    QSqlQuery query;
    if(!query.exec("INSERT INTO Сотрудники (Фамилия, Имя, Отчество, Должность, Оклад, [Семейное положение], [Количество детей]) VALUES ('" + last_name + "','" + first_name + "','" + second_name + "','" +position + "','" + salary + "','" + family + "','" + children +"')")){
        QMessageBox::critical(this, "Ошибка", "Некорректные данные");
    }else{
        this->done(1);
        this->close();
    }
}

void add_employee::on_cancel_clicked()
{
    this->done(1);
    this->close();
}
