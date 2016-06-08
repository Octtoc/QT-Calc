#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile file("C:\\temp\\test.txt");
    QTextStream in(&file);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return a.exec();

    QString stylesheet = in.readAll();
    a.setStyleSheet(stylesheet);
    file.close();

    MainWindow w;
    w.show();

    return a.exec();
}
