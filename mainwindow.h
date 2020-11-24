#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QSqlQueryModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_action_7_triggered();

    void on_action_4_triggered();

    void update_table();

    void on_action_5_triggered();

private:
    Ui::MainWindow *ui;
    QSqlTableModel *model_1;
    QSqlQueryModel *model_2;
    QSqlQueryModel *model_3;

};
#endif // MAINWINDOW_H
