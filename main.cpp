#include "bulb.h"
#include <QApplication>
#include <iostream>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Bulb w;
    w.setWindowTitle("Voltage Input Validator");
    w.show();
    return a.exec();



}


// main.cpp








