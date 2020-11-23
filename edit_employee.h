#ifndef EDIT_EMPLOYEE_H
#define EDIT_EMPLOYEE_H

#include <QDialog>

namespace Ui {
class edit_employee;
}

class edit_employee : public QDialog
{
    Q_OBJECT

public:
    explicit edit_employee(QWidget *parent = nullptr);
    ~edit_employee();

private:
    Ui::edit_employee *ui;
};

#endif // EDIT_EMPLOYEE_H
