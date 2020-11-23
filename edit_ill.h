#ifndef EDIT_ILL_H
#define EDIT_ILL_H

#include <QDialog>

namespace Ui {
class edit_ill;
}

class edit_ill : public QDialog
{
    Q_OBJECT

public:
    explicit edit_ill(QWidget *parent = nullptr);
    ~edit_ill();

private:
    Ui::edit_ill *ui;
};

#endif // EDIT_ILL_H
