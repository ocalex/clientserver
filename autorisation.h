#ifndef AUTORISATION_H
#define AUTORISATION_H

#include <QDialog>
#include <database.h>
#include <QCryptographicHash>
#include <mainwindow.h>
#include <insert_user.h>


namespace Ui {
class autorisation;
}

class autorisation : public QDialog
{
    Q_OBJECT
    database* db;
    QString login;
    QString password;
    int user_right;
    insert_user * insert;

    MainWindow* mai;


public:
    explicit autorisation(database* dat= nullptr, MainWindow* main = nullptr,QWidget *parent = nullptr);
    ~autorisation();

public slots:
    void changelogin(QString s);
    void changepassword(QString s);
    void checkuse();


signals:


private:
    Ui::autorisation *ui;
};

#endif // AUTORISATION_H
