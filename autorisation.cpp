#include "autorisation.h"
#include "ui_autorisation.h"

autorisation::autorisation(database* dat,MainWindow* main,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::autorisation)
{
    ui->setupUi(this);
    db = dat;
    mai = main;
    insert = new insert_user();


}

autorisation::~autorisation()
{
    delete ui;
}

void autorisation::checkuse(){

    qDebug()<<"before check use";
    QStringList res;
    res += login;
    QCryptographicHash *hash = new QCryptographicHash(QCryptographicHash::Sha1);
    hash->addData(password.toUtf8());
    QString pass = hash->result().toBase64();
    res += pass;

    user_right = db->checkuser(res);

    if(user_right){qDebug()<<"ALL RIGHT";
                 mai->show();}



    if(user_right == 2){
        qDebug()<<"User right 2";
        insert->show();

    }

    delete hash;


}

void autorisation::changelogin(QString s){
    login = s;
    qDebug()<<login;

}
void autorisation::changepassword(QString s){
    password = s;
    qDebug()<<password;
}


