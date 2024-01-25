#include "list_users.h"
#include "ui_list_users.h"

list_users::list_users(database* data, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::list_users)
{
    ui->setupUi(this);

    db = data;

    this->createUl();
    this->filltable();
}

list_users::~list_users()
{
    delete ui;
}

void list_users::createUl()
{
    QStringList headers = {"N", "Пользователь", "Администратор"};

    qDebug() << "CreateUI";
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->hideColumn(0);


 }

void list_users::filltable(){

    ui->tableWidget->clearContents();

    QSqlQuery query("SELECT id, login, admin from USERS");

    qDebug()<< "I am filling table";

    qDebug()<< "Table mistake" << query.lastError().text();


    for(int i = 0; query.next(); i++){
        // Insert row
        ui->tableWidget->removeRow(i);
        ui->tableWidget->insertRow(i);
        /* Set the id column in the first taking it from the result of the SQL-query.
         * This column will be hidden
         * */

            for(int j = 0; j < 3; ++j){
        ui->tableWidget->setItem(i,j, new QTableWidgetItem(query.value(j).toString()));
                                       }

                                     }

}

void list_users::delete_user( QString str){

        user_delete = str;
        qDebug()<<user_delete;

}
void list_users::finale_delete(){

    db->delete_user(user_delete);

}
