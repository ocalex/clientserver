#include "pingbut.h"
#include "ui_pingbut.h"

#include <QRegExp>


#include "winsock2.h"
#include "iphlpapi.h"
#include "icmpapi.h"

pingbut::pingbut(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pingbut)
{
    ui->setupUi(this);

    // Производим валидацию вводимых данных IP-адреса
       QString ipRange = "(?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])";

       QRegExp ipRegex ("^" + ipRange
                        + "\\." + ipRange
                        + "\\." + ipRange
                        + "\\." + ipRange + "$");


       //QRegExpValidator *ipValidator = new QRegExpValidator(ipRegex, this);

       //ui->lineEdit->setValidator(ipValidator);


}

pingbut::~pingbut()
{
    delete ui;
}
