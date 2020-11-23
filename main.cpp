#include "mainwindow.h"
#include "authorization.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QIcon winIcon("C:\\Users\\User\\Desktop\\SalarySI\\source\\pic\\ico.ico");

    authorization window;
    window.setWindowIcon(winIcon);
    window.setModal(true);

    int ex = window.exec();
    if (ex){
        MainWindow w;
        w.setWindowIcon(winIcon);
        w.show();
        return a.exec();
    }
    else{
        return -1;
    }
}
