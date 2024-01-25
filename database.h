#ifndef DATABASE_H
#define DATABASE_H

#define TABLE

#define TABLE_NAME

#define TABLE_MESSAGE

#include <QSqlDatabase>
#include <QtDebug>
#include <QDir>
#include <QStringList>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QMessageBox>



class database
{
    QSqlDatabase db;

public:
    database();
    void insert(const QStringList &data);
    ~database();
    void closedb();
    bool checktab(const QString &data);
    QStringList fromstring(const QString &data);
    void clean();
    void deleteline(const QString &data);
    QString getapps(const int row);
    void insert_apps(const QStringList &dat);
    void insert_user(const QStringList &data, bool ad);
    void insert_rule(const QStringList &data);
    void recom();
    int checkuser(const QStringList &data);
    void delete_user(const QString &data);
    void delete_rule(const QString &name);




private:

      void recomes(const QString mes);
      void create_database();

};

#endif // DATABASE_H
