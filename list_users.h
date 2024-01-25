#ifndef LIST_USERS_H
#define LIST_USERS_H

#include <QDialog>
#include "database.h"

namespace Ui {
class list_users;
}

class list_users : public QDialog
{
    Q_OBJECT
    database *db;
    QString user_delete;


public:
    explicit list_users( database* data = nullptr, QWidget *parent = nullptr);
    ~list_users();
    void filltable();
    void createUl();

public slots:

    void delete_user(QString str);
    void finale_delete();


private:
    Ui::list_users *ui;
};

#endif // LIST_USERS_H
