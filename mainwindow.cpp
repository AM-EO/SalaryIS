#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "add_employee.h"
#include "add_ill.h"
#include "edit_employee.h"
#include "edit_ill.h"

#include <QtDebug>
#include <QSqlDatabase>
#include <QtSql>
#include <QTableView>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSqlQueryModel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    update_table();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_7_triggered()
{
    QString str = "Информационная подсистема ЗАРПЛАТА для автоматизации начислений заработной платы в бухгалтерии.\nРазработали:\nАмельченко Евгений Олегович\nЦуркан Алина Григорьевна\n";
    str += "WRWco";
    str += char(0xAE);
    QMessageBox::information(this, "О программе", str);
}

void MainWindow::on_action_4_triggered()
{
    add_employee *window;
    window = new add_employee(this);
    window->setModal(true);
    window->show();
    int ex = window->exec();
    if (ex == 1)
        update_table();
}



void MainWindow:: update_table(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    qDebug() << db.drivers();
    db.setDatabaseName("DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ=C:\\Users\\User\\Desktop\\SalaryIS\\source\\db\\db_bookkeeping.mdb");
    if(db.open()){
        model_1 = new QSqlTableModel(this, db);
        model_1->setTable("Сотрудники");
        model_1->select();
        ui->tableView->setModel(model_1);

        model_2 = new QSqlQueryModel();
        model_2->setQuery("SELECT Фамилия, Имя, Отчество, Период, [Дата заболевания], [Дата выздоровления] FROM Больничные LEFT JOIN Сотрудники ON Сотрудники.[Личный номер]=Больничные.[Личный номер]");
        ui->tableView_2->setModel(model_2);

        model_3 = new QSqlQueryModel;
        model_3->setQuery("SELECT Фамилия, Имя, Отчество, [Период оплаты], [Итого к выдаче] FROM Выплаты LEFT JOIN Сотрудники ON Сотрудники.[Личный номер]=Выплаты.[Личный номер]");
        ui->tableView_3->setModel(model_3);
    }
}

void MainWindow::on_action_5_triggered()
{
    add_ill *window;
    window = new add_ill(this);
    window->setModal(true);
    window->show();
    int ex = window->exec();
    if (ex == 1)
        update_table();
}
