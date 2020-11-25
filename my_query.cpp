#include "my_query.h"
#include "edit_employee.h"
#include <QString>
#include <QtSql>
#include <QSqlQuery>
#include <QtDebug>

my_query::my_query()
{

}

my_query::~my_query(){

}

QString my_query::getId(QString last_name, QString first_name,QString second_name){
    QString id;
    str = "SELECT [Личный номер] FROM [Сотрудники] WHERE [Фамилия]='";
    str += last_name;
    str += "' AND [Имя]='";
    str += first_name;
    str += "' AND [Отчество]='";
    str += second_name;
    str += "'";

    return makeQuery(str);
}

QString  my_query::getPosition(QString id){
    str = "SELECT [Должность] FROM [Сотрудники] WHERE [Личный номер]=";
    str += id;


   return makeQuery(str);
}

QString  my_query::getSalary(QString id){
    str = "SELECT [Оклад] FROM [Сотрудники] WHERE [Личный номер]=";
    str += id;

    return makeQuery(str);
}

QString  my_query::getFamily(QString id){
    str = "SELECT [Семейное положение] FROM [Сотрудники] WHERE [Личный номер]=";
    str += id;

    return makeQuery(str);
}

QString  my_query::getChildren(QString id){
    str = "SELECT [Количество детей] FROM [Сотрудники] WHERE [Личный номер]=";
    str += id;

    return makeQuery(str);
}

QString my_query::makeQuery(QString str){
    qDebug() << query.exec(str);
    QString data;
    while (query.next()) {
         data = query.value(0).toString();
         qDebug() << "data " << data;
    }
    return data;
}

void my_query::updateEmployee(QString new_first_name,
                              QString new_second_name,
                              QString new_last_name,
                              QString new_position,
                              QString new_salary,
                              QString new_family,
                              QString new_children,
                              QString id){
    str = "UPDATE Сотрудники SET Фамилия=";
    str += new_last_name;
    str += ", Имя=";
    str += new_first_name;
    //str += ", Отчество="
    str += new_second_name;
    //str += ", Должность="
    str += new_position;
    //str += ", Оклад="
    str += new_salary;
    //str += ", Семейное положение="
    str += new_family;
    //str += ", Количество детей="
    str += new_children;
    //str += "WHERE [Личный номер]="
    str += id;
    makeQuery(str);
}


void my_query::test(){
    QString id = getId("Цуркан", "А", "Г");
    qDebug() << "getId " << id;
    qDebug() << "getPosition " << getPosition(id);
    qDebug() << "getSalary " << getSalary(id);
    qDebug() << "getFamily " << getFamily(id);
    qDebug() << "getChildren " << getChildren(id);
}
