#include "apps.h"
#include "ui_apps.h"

apps::apps(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::apps)
{
    ui->setupUi(this);

}

apps::~apps()
{
    delete ui;
}
