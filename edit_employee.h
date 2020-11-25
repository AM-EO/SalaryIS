#ifndef EDIT_EMPLOYEE_H
#define EDIT_EMPLOYEE_H

#include <QDialog>
#include "my_query.h"

namespace Ui {
class edit_employee;
}

class edit_employee : public QDialog
{
    Q_OBJECT

public:
    explicit edit_employee(QWidget *parent = nullptr);
    ~edit_employee();

private slots:
    void on_confirm_clicked();

    void on_cancel_clicked();

    void on_lastname_currentTextChanged(const QString &arg1);

    void on_firstname_currentTextChanged(const QString &arg1);

    void on_secondname_currentTextChanged(const QString &arg1);

    void on_lastname_editTextChanged(const QString &arg1);
    void updateData();
    void setData();
    void setName();
//public slots:
//    QString get_new_first_name();
//    QString get_new_second_name();
//    QString get_new_last_name();

//    QString get_new_position();
//    QString get_new_salary();
//    QString get_new_family();
//    QString get_new_children();
//    QString get_id();




private:
    Ui::edit_employee *ui;
    QString old_first_name;
    QString old_second_name;
    QString old_last_name;



    QString old_position;
    QString old_salary;
    QString old_family;
    QString old_children;

    QString new_first_name;
    QString new_second_name;
    QString new_last_name;
    QString new_position;
    QString new_salary;
    QString new_family;
    QString new_children;

    QString id;
    //my_query mquery;

};

#endif // EDIT_EMPLOYEE_H
