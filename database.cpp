#include "database.h"

database::database()
{

    create_database();

}


void database::create_database(){

    db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName(QDir::currentPath()+QString("/dev.db"));


    db.setHostName("localhost");

    qDebug() <<QDir::currentPath()+QString("/dev.db");
    qDebug() <<"dev.db is open? "<< db.open();



    QSqlQuery device;
        if(!device.exec( "CREATE TABLE  DEVICE   ("
                                "id INTEGER PRIMARY KEY AUTOINCREMENT, "



                                "DEVICE_USER    VARCHAR(40)    NOT NULL,"

                                "DEVICE_IP   VARCHAR(26)    NOT NULL,"
                                "DEVICE_DATA    VARCHAR(40)    NOT NULL,"

                                "DEVICE_MAC    VARCHAR(26)    NOT NULL,"
                                "DEVICE_OS VARCHAR(40) NOT NULL,"
                                "DEVICE_HOST VARCHAR(40) NOT NULL,"

                                "DEVICE_INFO VARCHAR(40) NOT NULL"


                            " )"
                      )){

            qDebug()<<"mistake device" << device.lastError().text();
    }




   QSqlQuery apps;


   if(!apps.exec( "CREATE TABLE  DEVICE_APPS   ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "

                     "DEVICE_ID INT NOT NULL,"

                     "DEVICE_APP VARCHAR(50) NOT NULL,"

                    "FOREIGN KEY (DEVICE_ID) REFERENCES DEVICE (id)"


                       " )"
                 )){

       qDebug()<<"mistake apps" << apps.lastError().text();
                    }

       QSqlQuery rules;


       if(!rules.exec( "CREATE TABLE  RULES   ("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT, "

                         "name VARCHAR(50) NOT NULL,"



                         "mistake VARCHAR(50) NOT NULL,"

                         "tabl VARCHAR(50) NOT NULL,"
                        "column VARCHAR(50) NOT NULL"
                        ")"



                     )){

           qDebug()<<"mistake RULES" << rules.lastError().text();


                        }

       QSqlQuery users;


       if(!users.exec( "CREATE TABLE  USERS   ("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT, "

                         "login VARCHAR(50) NOT NULL,"

                         "password VARCHAR(50) NOT NULL,"

                         "admin BOOL NOT NULL"
                        ")"



                     )){

           qDebug()<<"mistake USERS" << users.lastError().text();


                        }


}

database::~database(){}

void database::closedb(){ db.close();}

void database::insert(const QStringList &data){

    qDebug()<<"before query";


     if(!this->checktab(data[1])){


    QSqlQuery query;
    query.prepare("INSERT INTO  DEVICE  (  DEVICE_USER ,  DEVICE_IP ,DEVICE_DATA,  DEVICE_MAC , ""DEVICE_OS, DEVICE_HOST,  DEVICE_INFO)  VALUES ( :DEVICE_USER, :DEVICE_IP,:DEVICE_DATA, :DEVICE_MAC, :DEVICE_OS, :DEVICE_HOST, :DEVICE_INFO )");


    query.bindValue(":DEVICE_USER",    data[0]);
    query.bindValue(":DEVICE_IP",          data[1]);
    query.bindValue(":DEVICE_DATA",          data[2]);
    query.bindValue(":DEVICE_MAC",         data[3]);
    query.bindValue(":DEVICE_OS",         data[4]);
    query.bindValue(":DEVICE_HOST",         data[5]);
    query.bindValue(":DEVICE_INFO",         data[6]);



       if(query.exec())
       {
           query.next();
           qDebug()<<"query insert dev exec" <<  true;
       }
       else
       {
            qDebug() << "addDEVICE"      << query.lastError();
       }


       this->insert_apps(data);
}



}

void database::insert_apps(const QStringList &dat){

    qDebug()<<"insert_apps_begin";

    QSqlQuery query;
    query.prepare("SELECT MAX(id) FROM DEVICE");

    qDebug()<<"insert_apps" << query.exec();
    qDebug() <<        "insert_apps error"      << query.lastError();

    query.next();

    int device_id = query.value(0).toInt();

    qDebug()<<"device_id = " <<  query.value(0).toString();




   for(unsigned int i = 7; i < dat.size(); ++i ){

       QSqlQuery qu;


      qu.prepare("INSERT INTO  DEVICE_APPS (DEVICE_ID, DEVICE_APP) VALUES(:DEVICE_ID, :DEVICE_APP)") ;

        qu.bindValue(":DEVICE_ID",          device_id);
        qu.bindValue(":DEVICE_APP",          dat[i]);

        qDebug()<<dat[i];

        if(qu.exec())
        {
            qu.next();
            qDebug()<<"query insert apps" <<  true;
        }
        else
        {
             qDebug() << "add apps error:"
                      << qu.lastError();
        }



    }


}

void database::insert_user(const QStringList &data, bool ad){

    qDebug()<<"before query user";


    QSqlQuery query;
    query.prepare("INSERT INTO  USERS  (  login ,password, admin)  VALUES ( :login, :password, :admin)");


    query.bindValue(":login",    data[0]);
    query.bindValue(":password",          data[1]);
    query.bindValue(":admin",          ad);


       if(query.exec())
       {
           query.next();
           qDebug()<<"query insert user exec" <<  true;
       }
       else
       {
            qDebug() << "add user"      << query.lastError();
       }



}

void database::insert_rule(const QStringList &data){

    qDebug()<<"before query rule";


    QSqlQuery query;
    query.prepare("INSERT INTO  RULES  (  name ,mistake, tabl, column)  VALUES ( :name, :mistake, :tabl, :column)");


    query.bindValue(":name",    data[0]);
    query.bindValue(":mistake",          data[1]);
    query.bindValue(":tabl",          data[2]);
    query.bindValue(":column",          data[3]);


       if(query.exec())
       {
           query.next();
           qDebug()<<"query insert rule exec" <<  true;
       }
       else
       {
            qDebug() << "add rule mistake"      << query.lastError();
       }



}

bool database::checktab(const QString &data){

     QSqlQuery query;
     query.prepare("SELECT DEVICE_IP FROM DEVICE WHERE DEVICE_IP = (:data)");
     query.bindValue(":data", data);

     if(query.exec()){
         if (query.next())
           {
              return true;// it exists
           }
     }

     return false;

 }

 QStringList database::fromstring(const QString &data){

     qDebug()<<"fromstring" << data.size();

     QStringList f;

     for(int i = 0; i < data.size(); ++i){
          QString temp;
        while( (data[i] != '$') && (i < data.size()) ) {

           temp += data[i];
           ++i;
        }

        f += temp;
        temp.clear();

     }
 qDebug() << f;
     return f;

 }

 void database::clean(){

     QSqlQuery query;
     query.prepare("DROP TABLE DEVICE");
     query.exec();

     QSqlQuery que;
     que.prepare("DROP TABLE DEVICE_APPS");
     que.exec();

     create_database();

 }
 void database::deleteline(const QString &data){

        QSqlQuery query;
        query.prepare("DELETE FROM DEVICE WHERE DEVICE_USER = (:data)");
        query.bindValue(":data", data);




            qDebug() << "removeDevice error:"
                     << query.lastError();


 }

 QString database::getapps(const int row){

     const QString r = QString::number(row);
     QSqlQuery query;
     query.prepare("SELECT DEVICE_APP FROM DEVICE_APPS WHERE DEVICE_ID=(:r)");
     query.bindValue(":r", r);
     qDebug() << query.exec();
     qDebug() <<        "getapps error"              << query.lastError();


     QString res;
     unsigned int i = 0;

     while(query.next()){

         qDebug()<<"value query" <<  query.value(i).toString();
         res += query.value(i).toString();
         res += '\n';

                         }

    qDebug()<< "getaps res" << res;
    return  res;
 }

 void database::recom(){

     qDebug() <<"In recom";


     QSqlQuery query("SELECT tabl, column, mistake, name FROM RULES");

     qDebug() << query.exec();

     while(query.next()){

         qDebug() <<  query.value(0).toString();
         QString tabl = query.value(0).toString();
         qDebug() <<  query.value(1).toString();
         QString column = query.value(1).toString();

         qDebug() <<  query.value(2).toString();
         QString mistake = query.value(2).toString();

         QString name = query.value(3).toString();

         QSqlQuery quer;


         quer.prepare(QObject::tr("SELECT %1 FROM %2 WHERE %1 = \"%3\"").arg(column,tabl, mistake));

         qDebug() <<QObject::tr("SELECT %1 FROM %2 WHERE %1 = \"%3\"").arg(column,tabl, mistake);


         qDebug() <<"Find mistake quer"  <<quer.exec()  ;
         quer.next();
          qDebug() <<"Quer is valid?"<< quer.isValid();

          if( quer.isValid() ) recomes(name);

         qDebug() <<  quer.lastError();
         qDebug()<<"result"  << quer.value(0).toString();
            }


 }

 void database::recomes(const QString mes){

     QMessageBox msgBox;
     msgBox.setText(mes);
     msgBox.exec();

 }

 int database::checkuser(const QStringList &data) {

     qDebug()<<"login"<<data[0];
     qDebug()<<"password"<<data[1];
       QString data1=data[1];
      QSqlQuery query;
      query.prepare("SELECT login, admin FROM USERS WHERE password=(:password) AND login=(:login)");
      query.bindValue(":login", data[0]);
      query.bindValue(":password", data[1]);


      if(query.exec()){
          if (query.next())
            {
              qDebug()<<"has this user";

              if(query.value(1).toInt())  return 2;

              return 1;
            }
                      }

      else { qDebug()<<"Not has this user";}

      return 0;                             }

 void database::delete_user(const QString &data){

     qDebug()<<"login"<<data;
 ;
      QSqlQuery query;
      query.prepare("DELETE FROM USERS WHERE login=(:login)");
      query.bindValue(":login", data);


      if(query.exec()){
          if (query.next())
            {
              qDebug()<<"delete this user";

            }
                      }

      else { qDebug()<<"Not delete this user";}


 }
