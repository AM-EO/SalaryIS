#include "edit_employee.h"
#include "ui_edit_employee.h"
#include "my_query.h"

#include <QSqlQuery>
#include <QMessageBox>


edit_employee::edit_employee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit_employee)
{
    ui->setupUi(this);

    QSqlQuery query;
    if(!query.exec("SELECT distinct [Фамилия] FROM [Сотрудники]")){
        QMessageBox::critical(this, "Ошибка", "Потеряна связь с сервером");
        return;
    }
    while (query.next()) {
        QString str = query.value(0).toString();
        ui->lastname->addItem(str);
    }
   ////// mquery = new my_query;
    //my_query mquery;
    //mquery.test();
    setData();

}

edit_employee::~edit_employee()
{
    delete ui;
}

void edit_employee::on_confirm_clicked()
{
    setData();

}

void edit_employee::on_cancel_clicked()
{
    this->done(1);
    this->close();
}

void edit_employee::on_lastname_currentTextChanged(const QString &arg1)
{
    setName();
    QSqlQuery query;
    if(!query.exec("SELECT distinct [Имя] FROM [Сотрудники] WHERE [Фамилия]='" + old_last_name +"'")){
        QMessageBox::critical(this, "Ошибка", "Потеряна связь с сервером");
        return;
    }
    while (ui->firstname->count())
        ui->firstname->removeItem(0);
    while (query.next()) {
        QString str = query.value(0).toString();
        ui->firstname->addItem(str);
    }
    setData();
}

void edit_employee::on_firstname_currentTextChanged(const QString &arg1)
{
    setName();
    QSqlQuery query;
    if(!query.exec("SELECT distinct [Отчество] FROM [Сотрудники] WHERE [Фамилия]='" + old_last_name +"' AND [Имя]='"+ old_first_name+"'")){
        QMessageBox::critical(this, "Ошибка", "Потеряна связь с сервером");
        return;
    }
    while (ui->secondname->count())
        ui->secondname->removeItem(0);
    while (query.next()) {
        QString str = query.value(0).toString();
        ui->secondname->addItem(str);
    }
    setData();
}

void edit_employee::on_secondname_currentTextChanged(const QString &arg1)
{
    setData();
}

void edit_employee::on_lastname_editTextChanged(const QString &arg1)
{
    setData();
}

/*void edit_employee::setId(){
    QSqlQuery query;
    if(!query.exec("SELECT [Личный номер] FROM [Сотрудники] WHERE [Фамилия]='" + old_last_name +"' AND [Имя]='"+ old_first_name+"' AND [Отчество]='"+ old_second_name +"'")){
        QMessageBox::critical(this, "Ошибка", "Потеряна связь с сервером");
        return;
    }
    while (query.next()) {
        id = query.value(0).toString();
    }
}*/

void edit_employee::setData(){
    setName();
    my_query mquery;
    id = mquery.getId(old_last_name,old_first_name,old_second_name);
    old_position = mquery.getPosition(id);
    old_salary = mquery.getSalary(id);
    old_family = mquery.getFamily(id);
    old_children = mquery.getChildren(id);
    ui->position->setText(old_position);
    ui->salary->setText(old_salary);
    ui->family->setText(old_family);
    ui->children->setText(old_children);

}
void edit_employee::updateData(){
    if(ui->new_last_name->text() !="")
        new_last_name = ui->new_last_name->text();
    else
        new_last_name = old_last_name;
    if(ui->new_first_name->text() !="")
        new_first_name = ui->new_first_name->text();
    else
        new_first_name = old_first_name;
    if(ui->new_second_name->text() !="")
        new_second_name = ui->new_second_name->text();
    else
        new_second_name = old_second_name;

    new_position = ui->position->text();
    new_salary = ui->salary->text();
    new_family = ui->family->text();
    new_children = ui->children->text();
    my_query mquery;
    mquery.updateEmployee(new_first_name,new_second_name,new_last_name,new_position,new_salary,new_family, new_children,id);
}

void edit_employee::setName(){
    old_last_name = ui->lastname->currentText();
    old_first_name = ui->firstname->currentText();
    old_second_name = ui->secondname->currentText();


}






//QString edit_employee::get_new_first_name(){

//}
//QString edit_employee::get_new_second_name(){

//}
//QString edit_employee::get_new_last_name(){

//}

//QString edit_employee::get_new_position(){

//}
//QString edit_employee::get_new_salary(){

//}
//QString edit_employee::get_new_family(){

//}
//QString edit_employee::get_new_children(){

//}
//QString edit_employee::get_id(){

//}
