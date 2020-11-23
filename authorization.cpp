#include "authorization.h"
#include "ui_authorization.h"
#include <QSql>
#include <QSqlQuery>
#include <QtDebug>
#include <QMessageBox>

authorization::authorization(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::authorization)
{
    ui->setupUi(this);
}

authorization::~authorization()
{
    delete ui;
}

int verify(QString login, QString pass){
    QSqlQuery query_pass;
    query_pass.exec("SELECT pass FROM authorization WHERE login='" + login +"'");
    while (query_pass.next()) {
        QString query = query_pass.value(0).toString();
        if (query == pass){
            return 1;
        }else
            return 0;
        }
    return -1;
}

void authorization::on_confirm_clicked()
{
    QString login = ui->login->text();
    QString pass = ui->password->text();
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    qDebug() << "authorization: " << db.drivers();
    db.setDatabaseName("DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ=C:\\Users\\User\\Desktop\\SalaryIS\\source\\db\\db_authorization.mdb");
    bool error = db.open();
    qDebug() << error;
    verify(login, pass);
    if (!error){
        QMessageBox::warning(this, "Автоизация","Нет доступа к серверу");
    }else if (1/*verify(login, pass) == 1*/){
        this->done(1);
        this->close();
    } else {
        QMessageBox::critical(this, "Автоизация","Неверный логин или пароль");
    }
}
