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

private:
    Ui::add_ill *ui;
};

#endif // ADD_ILL_H
