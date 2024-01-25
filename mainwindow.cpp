#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow( database* dat, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = dat;
    serv = new Server(db);
    ap = new apps;


    qDebug() << "Create main";

    headers = {"", "User", "IP адрес","Дата и время", "MAC адрес", "Версия ПО", "Хост","Общая","apps"};


    this->createUI();
    this->filltable();

}

database* MainWindow::getbase(){
    return db;
}

void MainWindow::changetcp(QString s){
    tcp = s;
    qDebug()<< s;
}

void MainWindow::changemistake(QString s){
    mistake = s;
    qDebug()<< s;
}
void MainWindow::changename(QString s){
    name = s;
    qDebug()<< s;
}
void MainWindow::changetabl(QString s){
    tabl = s;
    qDebug()<< s;
}
void MainWindow::changecolumn(QString s){
    column = s;
    qDebug()<< s;
}


void MainWindow::setrule(){
    QStringList rule = { name, mistake, tabl, column };
    db->insert_rule(rule);

}
void MainWindow::slotconec(){


    HANDLE hIcmpFile;                       // Обработчик
    unsigned long ipaddr = INADDR_NONE;     // Адрес назначения
    DWORD dwRetVal = 0;                     // Количество ответов
    char SendData[32] = "Data Buffer";      // Буффер отсылаемых данных
    LPVOID ReplyBuffer = NULL;              // Буффер ответов
    DWORD ReplySize = 0;                    // Размер буффера ответов

    // Устанавливаем IP-адрес из поля lineEdit
    ipaddr = inet_addr(tcp.toStdString().c_str());
    hIcmpFile = IcmpCreateFile();   // Создаём обработчик

    // Выделяем память под буффер ответов
    ReplySize = sizeof(ICMP_ECHO_REPLY) + sizeof(SendData);
    ReplyBuffer = (VOID*) malloc(ReplySize);

    // Вызываем функцию ICMP эхо запроса
    dwRetVal = IcmpSendEcho(hIcmpFile, ipaddr, SendData, sizeof(SendData),
                NULL, ReplyBuffer, ReplySize, 1000);

    // создаём строку, в которою запишем сообщения ответа
    QString strMessage = "";

    if (dwRetVal != 0) {
        QString cd = QDate::currentDate().toString() +" "+ QTime::currentTime().toString();;


        QStringList list1 = { "*", tcp, cd , "*", "*", "*", "*", "*", "App1", "App2"};

        db->insert(list1);
        this->filltable();


        // Структура эхо ответа
        PICMP_ECHO_REPLY pEchoReply = (PICMP_ECHO_REPLY)ReplyBuffer;
        struct in_addr ReplyAddr;
        ReplyAddr.S_un.S_addr = pEchoReply->Address;

        strMessage += "Sent icmp message to " + tcp + "\n";
        if (dwRetVal > 1) {
            strMessage += "Received " + QString::number(dwRetVal) + " icmp message responses \n";
            strMessage += "Information from the first response: ";
        }
        else {
            strMessage += "Received " + QString::number(dwRetVal) + " icmp message response \n";
            strMessage += "Information from the first response: ";
        }
            strMessage += "Received from ";
            strMessage += inet_ntoa( ReplyAddr );
            strMessage += "\n";
            strMessage += "Status = " + pEchoReply->Status;
            strMessage += "Roundtrip time = " + QString::number(pEchoReply->RoundTripTime) + " milliseconds \n";
    } else {
        strMessage += "Call to IcmpSendEcho failed.\n";
        strMessage += "IcmpSendEcho returned error: ";
        strMessage += QString::number(GetLastError());
    }

    //ui->textEdit->setText(strMessage); // Отображаем информацию о полученных данных
    qDebug() << strMessage;
    free(ReplyBuffer); // Освобождаем память


}



MainWindow::~MainWindow()
{
    delete serv;
    delete ui;
    delete ap;
}

void MainWindow::createUI()
{
    qDebug() << "CreateUI";
    ui->tableWidget->setColumnCount(8);
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->hideColumn(0);


 }


void MainWindow::pingdia(){

    for(int i = 0; i < 36; ++i){
        tcp = "192.168.0."+ QString::number(i);
        qDebug() << tcp;
        this->slotconec();
                            }
}

void MainWindow::filltable(){

    ui->tableWidget->clearContents();

    QSqlQuery query("SELECT * from DEVICE");

    qDebug()<< "Table mistake" << query.lastError().text();


    for(int i = 0; query.next(); i++){
        // Insert row
        ui->tableWidget->removeRow(i);
        ui->tableWidget->insertRow(i);
        /* Set the id column in the first taking it from the result of the SQL-query.
         * This column will be hidden
         * */

            for(int j = 0; j < 9; ++j){
        ui->tableWidget->setItem(i,j, new QTableWidgetItem(query.value(j).toString()));
                                       }

                  }

}

void MainWindow::cleandat(){

    db->clean();
    this->filltable();
}

void MainWindow::refre(){
    this->filltable();
}

void MainWindow::slotcellpr(int row, int col){

    ap->opened(db->getapps(++row));

    ap->show();

}

void MainWindow::slotrecom(){

    db->recom();
}



