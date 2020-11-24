#ifndef ADD_ILL_H
#define ADD_ILL_H

#include <QDialog>

namespace Ui {
class add_ill;
}

class add_ill : public QDialog
{
    Q_OBJECT

public:
    explicit add_ill(QWidget *parent = nullptr);
    ~add_ill();

private slots:
    void on_lastname_currentTextChanged(const QString &arg1);

    void on_firstname_currentTextChanged(const QString &arg1);

    void on_secondname_currentTextChanged(const QString &arg1);


    void on_confirm_clicked();

    void on_cancel_clicked();
    void setData();

private:
    Ui::add_ill *ui;
    QString first_name;
    QString second_name;
    QString last_name;
    QString period;
    QString start_ill;
    QString end_ill;
    QString id;
};

#endif // ADD_ILL_H
