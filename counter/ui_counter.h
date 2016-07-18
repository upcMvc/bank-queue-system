/********************************************************************************
** Form generated from reading UI file 'counter.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COUNTER_H
#define UI_COUNTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Counter
{
public:
    QPushButton *callButton;
    QPushButton *callAgainButton;
    QPushButton *pushButton;

    void setupUi(QDialog *Counter)
    {
        if (Counter->objectName().isEmpty())
            Counter->setObjectName(QStringLiteral("Counter"));
        Counter->resize(493, 308);
        callButton = new QPushButton(Counter);
        callButton->setObjectName(QStringLiteral("callButton"));
        callButton->setGeometry(QRect(160, 30, 171, 61));
        callAgainButton = new QPushButton(Counter);
        callAgainButton->setObjectName(QStringLiteral("callAgainButton"));
        callAgainButton->setGeometry(QRect(160, 120, 171, 61));
        pushButton = new QPushButton(Counter);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(160, 210, 171, 51));

        retranslateUi(Counter);

        QMetaObject::connectSlotsByName(Counter);
    } // setupUi

    void retranslateUi(QDialog *Counter)
    {
        Counter->setWindowTitle(QApplication::translate("Counter", "\346\237\234\345\217\260\347\253\257", 0));
        callButton->setText(QApplication::translate("Counter", "\345\221\274\345\217\253\345\256\242\346\210\267", 0));
        callAgainButton->setText(QApplication::translate("Counter", "\351\207\215\346\226\260\345\221\274\345\217\253", 0));
        pushButton->setText(QApplication::translate("Counter", "\350\257\204\344\273\267", 0));
    } // retranslateUi

};

namespace Ui {
    class Counter: public Ui_Counter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COUNTER_H
