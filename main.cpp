#include "mainwindow.h"

#include "database.h"
#include <QApplication>
#include <QSysInfo>
#include <QSettings>
#include <autorisation.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    database *data = new database();

    MainWindow w(data);

    autorisation author(data, &w);
    author.show();


    delete data;
    return a.exec();
}
