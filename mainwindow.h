#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "winsock2.h"
#include "iphlpapi.h"
#include "icmpapi.h"
#include "server.h"
#include <QDateTime>
#include <apps.h>




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#include <QSqlQuery>

#include <database.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QString tcp;//TCP
    QString name;
    QString mistake;
    QString tabl;
    QString column;

    QStringList headers;
    Server* serv;
    apps* ap;
    database *db;


public:
    MainWindow(database *dat = nullptr, QWidget *parent = nullptr);
    ~MainWindow();
    database* getbase();



public slots:


    void changetcp(QString s);
    void changename(QString s);
    void changemistake(QString s);
    void changetabl(QString s);
    void changecolumn(QString s);

    void slotconec();
    void cleandat();
    void refre();
    void pingdia();
    void slotcellpr(int row, int col);
    void slotrecom();

    void setrule();
    void deleterule();



signals:

public:

private:
    void createUI();
    void filltable();





private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
