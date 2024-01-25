#include <QtCore>
#include <QtNetwork>
#include <QTextCodec>
#include <QDebug>
//#include "mainwindow.h"
#include "database.h"

#pragma once
class Server : public QObject
{
    Q_OBJECT


private:
    QTcpServer *server;
    QHash<QTcpSocket*, QByteArray*> buffers; //We need a buffer to store data until block has completely received
    QHash<QTcpSocket*, qint32*> sizes; //We need to store the size to verify if a block has received completely
    database *db;

public:
    explicit Server(database *d, QObject *parent = 0);



signals:
    void dataReceived(QByteArray);


private slots:
    void newConnection();
    void disconnected();
    void readyRead();


};
