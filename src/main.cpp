#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Shortest way");
    w.setWindowIcon(QIcon("myapp.ico"));
    w.show();
    return a.exec();
}
