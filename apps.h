#ifndef APPS_H
#define APPS_H

#include <QDialog>

namespace Ui {
class apps;
}

class apps : public QDialog
{
    Q_OBJECT

public:
    explicit apps(QWidget *parent = nullptr);
    ~apps();
signals:
    void opened(QString s);

private:
    Ui::apps *ui;
};

#endif // APPS_H
