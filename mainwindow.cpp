#include "mainwindow.h"
#include "ui_mainwindow.h"
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
