/********************************************************************************
** Form generated from reading UI file 'apps.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPS_H
#define UI_APPS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_apps
{
public:
    QDialogButtonBox *buttonBox;
    QTextEdit *textEdit;

    void setupUi(QDialog *apps)
    {
        if (apps->objectName().isEmpty())
            apps->setObjectName(QString::fromUtf8("apps"));
        apps->resize(474, 365);
        buttonBox = new QDialogButtonBox(apps);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(110, 330, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        textEdit = new QTextEdit(apps);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 10, 441, 311));

        retranslateUi(apps);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, apps, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, apps, qOverload<>(&QDialog::reject));
        QObject::connect(apps, SIGNAL(opened(QString)), textEdit, SLOT(append(QString)));
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, textEdit, qOverload<>(&QTextEdit::clear));
        QObject::connect(apps, &QDialog::finished, textEdit, qOverload<>(&QTextEdit::clear));

        QMetaObject::connectSlotsByName(apps);
    } // setupUi

    void retranslateUi(QDialog *apps)
    {
        apps->setWindowTitle(QCoreApplication::translate("apps", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\273\320\265\320\275\320\275\321\213\320\265 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class apps: public Ui_apps {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPS_H
