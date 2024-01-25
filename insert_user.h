#ifndef INSERT_USER_H
#define INSERT_USER_H

#include <QDialog>
#include <QDebug>
#include <database.h>
#include <QCryptographicHash>
#include <list_users.h>


namespace Ui {
class insert_user;
}

class insert_user : public QDialog
{
    Q_OBJECT
    QString login = "";
    QString password = "";
    bool admin = false;
    database* db;

    list_users* users ;



public:
    explicit insert_user( database* data = nullptr, QWidget *parent = nullptr);
    ~insert_user();
    QString getlogin();
    QString getpassword();
    bool getadmin();


public slots:
    void changelogin(QString s);
    void changepassword(QString s);
    void changeadmin(bool adm);
    void insertdata();
    void show_users();





private:
    Ui::insert_user *ui;
};

#endif // INSERT_USER_H
