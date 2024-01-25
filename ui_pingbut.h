/********************************************************************************
** Form generated from reading UI file 'pingbut.ui'
**
** Created by: Qt User Interface Compiler version 6.0.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PINGBUT_H
#define UI_PINGBUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pingbut
{
public:

    void setupUi(QWidget *pingbut)
    {
        if (pingbut->objectName().isEmpty())
            pingbut->setObjectName(QString::fromUtf8("pingbut"));
        pingbut->resize(400, 300);

        retranslateUi(pingbut);

        QMetaObject::connectSlotsByName(pingbut);
    } // setupUi

    void retranslateUi(QWidget *pingbut)
    {
        pingbut->setWindowTitle(QCoreApplication::translate("pingbut", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pingbut: public Ui_pingbut {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PINGBUT_H
