#include "mainwindow.h"
#include <QStyleFactory>
#include "database.h"
#include <QApplication>
#include <QSysInfo>
#include <QSettings>
#include <autorisation.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setWindowIcon(QIcon("./icon.png"));
    QApplication::setStyle(QStyleFactory::create("Fusion"));


    database *data = new database();

    MainWindow w(data);

    autorisation author(data, &w);
    author.show();


    delete data;
    return a.exec();
}
