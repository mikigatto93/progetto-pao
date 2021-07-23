#include <iostream>
#include "mainwindow.h"
#include "model.h"
#include "preventivo.h"
#include "scuro.h"
#include "legno.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Model model;
    Controller controller;


    MainWindow view(&model, &controller);

    controller.setModel(&model);
    controller.setView(&view);

    view.setWindowTitle("Fattr");
    view.setWindowState(Qt::WindowMaximized);
    view.setMinimumSize(900, 800);

    view.show();

    return a.exec();

}
