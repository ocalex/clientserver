/********************************************************************************
** Form generated from reading UI file 'autorisation.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTORISATION_H
#define UI_AUTORISATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_autorisation
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *autorisation)
    {
        if (autorisation->objectName().isEmpty())
            autorisation->setObjectName(QString::fromUtf8("autorisation"));
        autorisation->resize(400, 300);
        buttonBox = new QDialogButtonBox(autorisation);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(autorisation);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(100, 70, 231, 22));
        lineEdit_2 = new QLineEdit(autorisation);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(100, 120, 231, 22));
        label = new QLabel(autorisation);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 70, 49, 16));
        label_2 = new QLabel(autorisation);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 120, 49, 16));

        retranslateUi(autorisation);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, autorisation, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, autorisation, qOverload<>(&QDialog::reject));
        QObject::connect(lineEdit, SIGNAL(textChanged(QString)), autorisation, SLOT(changelogin(QString)));
        QObject::connect(lineEdit_2, SIGNAL(textChanged(QString)), autorisation, SLOT(changepassword(QString)));
        QObject::connect(buttonBox, SIGNAL(accepted()), autorisation, SLOT(checkuse()));
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, autorisation, qOverload<>(&QDialog::accept));

        QMetaObject::connectSlotsByName(autorisation);
    } // setupUi

    void retranslateUi(QDialog *autorisation)
    {
        autorisation->setWindowTitle(QCoreApplication::translate("autorisation", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        lineEdit->setText(QString());
        lineEdit_2->setText(QString());
        label->setText(QCoreApplication::translate("autorisation", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        label_2->setText(QCoreApplication::translate("autorisation", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class autorisation: public Ui_autorisation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTORISATION_H
