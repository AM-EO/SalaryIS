#ifndef ADD_EMPLOYEE_H
#define ADD_EMPLOYEE_H

#include <QDialog>

namespace Ui {
class add_employee;
}

class add_employee : public QDialog
{
    Q_OBJECT

public:
    explicit add_employee(QWidget *parent = nullptr);
    ~add_employee();

private:
    Ui::add_employee *ui;
};

#endif // ADD_EMPLOYEE_H
