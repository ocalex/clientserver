/********************************************************************************
** Form generated from reading UI file 'list_users.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIST_USERS_H
#define UI_LIST_USERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_list_users
{
public:
    QDialogButtonBox *buttonBox;
    QTableWidget *tableWidget;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *list_users)
    {
        if (list_users->objectName().isEmpty())
            list_users->setObjectName(QString::fromUtf8("list_users"));
        list_users->resize(400, 300);
        buttonBox = new QDialogButtonBox(list_users);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tableWidget = new QTableWidget(list_users);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(20, 20, 361, 192));
        lineEdit = new QLineEdit(list_users);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 230, 113, 22));
        pushButton = new QPushButton(list_users);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 260, 75, 24));

        retranslateUi(list_users);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, list_users, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, list_users, qOverload<>(&QDialog::reject));
        QObject::connect(lineEdit, SIGNAL(textChanged(QString)), list_users, SLOT(delete_user(QString)));
        QObject::connect(pushButton, SIGNAL(clicked()), list_users, SLOT(finale_delete()));

        QMetaObject::connectSlotsByName(list_users);
    } // setupUi

    void retranslateUi(QDialog *list_users)
    {
        list_users->setWindowTitle(QCoreApplication::translate("list_users", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \320\270 \321\203\320\264\320\260\320\273\320\265\320\275\320\270\320\265 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\265\320\271", nullptr));
        pushButton->setText(QCoreApplication::translate("list_users", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class list_users: public Ui_list_users {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIST_USERS_H
