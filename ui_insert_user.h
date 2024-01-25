/********************************************************************************
** Form generated from reading UI file 'insert_user.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERT_USER_H
#define UI_INSERT_USER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_insert_user
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QRadioButton *radioButton;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;

    void setupUi(QDialog *insert_user)
    {
        if (insert_user->objectName().isEmpty())
            insert_user->setObjectName(QString::fromUtf8("insert_user"));
        insert_user->resize(420, 300);
        buttonBox = new QDialogButtonBox(insert_user);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(insert_user);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(50, 110, 113, 22));
        lineEdit_2 = new QLineEdit(insert_user);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(180, 110, 113, 22));
        radioButton = new QRadioButton(insert_user);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(300, 110, 111, 20));
        label = new QLabel(insert_user);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 90, 49, 16));
        label_2 = new QLabel(insert_user);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(180, 90, 49, 16));
        pushButton = new QPushButton(insert_user);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 250, 141, 24));

        retranslateUi(insert_user);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, insert_user, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, insert_user, qOverload<>(&QDialog::reject));
        QObject::connect(lineEdit, SIGNAL(textChanged(QString)), insert_user, SLOT(changelogin(QString)));
        QObject::connect(radioButton, SIGNAL(clicked(bool)), insert_user, SLOT(changeadmin(bool)));
        QObject::connect(lineEdit_2, SIGNAL(textChanged(QString)), insert_user, SLOT(changepassword(QString)));
        QObject::connect(buttonBox, SIGNAL(accepted()), insert_user, SLOT(insertdata()));
        QObject::connect(pushButton, SIGNAL(clicked()), insert_user, SLOT(show_users()));

        QMetaObject::connectSlotsByName(insert_user);
    } // setupUi

    void retranslateUi(QDialog *insert_user)
    {
        insert_user->setWindowTitle(QCoreApplication::translate("insert_user", "\320\222\320\262\320\265\321\201\321\202\320\270 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        radioButton->setText(QCoreApplication::translate("insert_user", "\320\220\320\264\320\274\320\270\320\275\320\270\321\201\321\202\321\200\320\260\321\202\320\276\321\200", nullptr));
        label->setText(QCoreApplication::translate("insert_user", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        label_2->setText(QCoreApplication::translate("insert_user", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        pushButton->setText(QCoreApplication::translate("insert_user", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\265\320\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class insert_user: public Ui_insert_user {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERT_USER_H
