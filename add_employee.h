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

private slots:
    void on_confirm_clicked();
    void setData();

    void on_cancel_clicked();

private:
    Ui::add_employee *ui;
    QString last_name;
    QString first_name;
    QString second_name;
    QString position;
    QString salary;
    QString family;
    QString children;
};

#endif // ADD_EMPLOYEE_H
