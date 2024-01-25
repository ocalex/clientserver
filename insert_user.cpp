#include "insert_user.h"
#include "ui_insert_user.h"

insert_user::insert_user(database *data, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::insert_user)
{
    ui->setupUi(this);
    db = data;
    users = new list_users(data);

}

void insert_user::changelogin(QString s){

    login = s;
    qDebug() <<login;

}

void insert_user::changepassword(QString s){

    password = s;
    qDebug() <<password;

}

void insert_user::changeadmin(bool adm){

    admin = adm;
    qDebug() <<adm;

}

bool insert_user::getadmin(){

    return admin;
}

QString insert_user::getlogin(){
    return login;
}
QString insert_user::getpassword(){
    return password;
}

void insert_user::insertdata(){

    QStringList res;
    res += login;

    QCryptographicHash *hash = new QCryptographicHash(QCryptographicHash::Sha1);
    hash->addData(password.toUtf8());
    QString pass = hash->result().toBase64();
    res += pass;
    qDebug()<<"String List" <<res;

    db->insert_user(res, admin);

}
insert_user::~insert_user()
{
    delete ui;
}
void insert_user::show_users(){
    users->show();
}
