#ifndef PINGBUT_H
#define PINGBUT_H

#include <QWidget>

namespace Ui {
class pingbut;
}

class pingbut : public QWidget
{
    Q_OBJECT

public:
    explicit pingbut(QWidget *parent = nullptr);
    ~pingbut();

private:
    Ui::pingbut *ui;

private slots:
    //void on_pushButton_clicked();
};

#endif // PINGBUT_H
