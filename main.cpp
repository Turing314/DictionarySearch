#include "mainwindow.h"
#include <bits/stdc++.h>
#include <QApplication>

int main(int argc, char *argv[])    // main program
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
