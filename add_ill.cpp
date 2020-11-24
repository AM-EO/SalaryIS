#include "add_ill.h"
#include "ui_add_ill.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QEvent>
#include <QTime>
#include <QDate>
#include <QMessageBox>

add_ill::add_ill(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_ill)
{
    ui->setupUi(this);
    ui->period->setDate(QDate::currentDate());
    ui->startill->setDate(QDate::currentDate());
    ui->endill->setDate(QDate::currentDate());

    QSqlQuery query;
    if(!query.exec("SELECT distinct [Фамилия] FROM [Сотрудники]")){
        QMessageBox::critical(this, "Ошибка", "Потеряна связь с сервером");
        return;
    }
    while (query.next()) {
        QString str = query.value(0).toString();
        ui->lastname->addItem(str);
    }
}

add_ill::~add_ill()
{
    delete ui;
}

void add_ill::on_lastname_currentTextChanged(const QString &arg1)
{
    last_name = ui->lastname->currentText();
    QSqlQuery query;
    if(!query.exec("SELECT distinct [Имя] FROM [Сотрудники] WHERE [Фамилия]='" + last_name +"'")){
        QMessageBox::critical(this, "Ошибка", "Потеряна связь с сервером");
        return;
    }
    while (ui->firstname->count())
        ui->firstname->removeItem(0);
    while (query.next()) {
        QString str = query.value(0).toString();
        ui->firstname->addItem(str);
    }
}

void add_ill::on_firstname_currentTextChanged(const QString &arg1)
{
    first_name = ui->firstname->currentText();
    QSqlQuery query;
    if(!query.exec("SELECT distinct [Отчество] FROM [Сотрудники] WHERE [Фамилия]='" + last_name +"' AND [Имя]='"+ first_name+"'")){
        QMessageBox::critical(this, "Ошибка", "Потеряна связь с сервером");
        return;
    }
    while (ui->secondname->count())
        ui->secondname->removeItem(0);
    while (query.next()) {
        QString str = query.value(0).toString();
        ui->secondname->addItem(str);
    }
}

void add_ill::on_secondname_currentTextChanged(const QString &arg1)
{
    second_name = ui->secondname->currentText();
}

void add_ill::on_confirm_clicked()
{
    setData();
    if((QDate::fromString(start_ill, "dd.MM.yyyy") < QDate::fromString(period, "dd.MM.yyyy")) or (QDate::fromString(end_ill, "dd.MM.yyyy") < QDate::fromString(period, "dd.MM.yyyy")) or (QDate::fromString(end_ill, "dd.MM.yyyy") < QDate::fromString(start_ill, "dd.MM.yyyy"))){
        QMessageBox::critical(this, "Ошибка","Некорректные даты");
        return;
    }
    QSqlQuery query;
    if(!query.exec("SELECT [Личный номер] FROM [Сотрудники] WHERE [Фамилия]='" + last_name +"' AND [Имя]='"+ first_name+"' AND [Отчество]='"+ second_name +"'")){
        QMessageBox::critical(this, "Ошибка", "Потеряна связь с сервером");
        return;
    }
    while (query.next()) {
         id = query.value(0).toString();
    }

    qDebug() << "addToTabЯвка: " << query.exec("INSERT INTO [Явка] ([Личный номер],[Период])VALUES ('"+id+"','"+period+"')");
    if(!query.exec("INSERT INTO [Больничные] ([Личный номер],[Период],[Дата заболевания],[Дата выздоровления]) VALUES ('"+
                           id + "','" + period + "','" + start_ill + "','" + end_ill + "')")){
        QMessageBox::critical(this, "Ошибка","Некорректные данные или потеряна связь с сервером");

    }else{
        this->done(1);
        this->close();
    }
}

void add_ill::on_cancel_clicked()
{
    this->done(1);
    this->close();
}

void add_ill:: setData(){
    second_name = ui->secondname->currentText();
    first_name = ui->firstname->currentText();
    last_name = ui->lastname->currentText();

    period = ui->period->text();
    start_ill = ui->startill->text();
    end_ill = ui->endill->text();}
