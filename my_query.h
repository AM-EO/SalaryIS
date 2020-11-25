#ifndef MY_QUERY_H
#define MY_QUERY_H
#include <QString>
#include <QtSql>
#include <QSqlQuery>

#include "edit_employee.h"

class my_query
{
public:
    my_query();
    ~my_query();
    void test();
public slots:
    QString makeQuery(QString str);
    QString getId(QString last_name, QString first_name, QString second_name);
    QString getPosition(QString id);
    QString getSalary(QString id);
    QString getFamily(QString id);
    QString getChildren(QString id);
    void updateEmployee(QString new_first_name,
                        QString new_second_name,
                        QString new_last_name,
                        QString new_position,
                        QString new_salary,
                        QString new_family,
                        QString new_children,
                        QString id);

private:
     QString str = "";
     bool error = 0;
     QSqlQuery query;
};






#endif // MY_QUERY_H
