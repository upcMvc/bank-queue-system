/********************************************************************************
** Form generated from reading UI file 'close.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOSE_H
#define UI_CLOSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Close
{
public:
    QPushButton *okpushButton;
    QPushButton *pushButton_2;
    QLabel *label;

    void setupUi(QDialog *Close)
    {
        if (Close->objectName().isEmpty())
            Close->setObjectName(QStringLiteral("Close"));
        Close->resize(331, 210);
        okpushButton = new QPushButton(Close);
        okpushButton->setObjectName(QStringLiteral("okpushButton"));
        okpushButton->setGeometry(QRect(80, 120, 75, 23));
        okpushButton->setStyleSheet(QStringLiteral(""));
        pushButton_2 = new QPushButton(Close);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(180, 120, 75, 23));
        pushButton_2->setStyleSheet(QStringLiteral(""));
        label = new QLabel(Close);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 50, 241, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        retranslateUi(Close);

        QMetaObject::connectSlotsByName(Close);
    } // setupUi

    void retranslateUi(QDialog *Close)
    {
        Close->setWindowTitle(QApplication::translate("Close", "\351\200\200\345\207\272", 0));
        okpushButton->setText(QApplication::translate("Close", "\346\230\257", 0));
        pushButton_2->setText(QApplication::translate("Close", "\345\220\246", 0));
        label->setText(QApplication::translate("Close", "\346\230\257\345\220\246\350\246\201\351\200\200\345\207\272\346\237\234\345\217\260\347\253\257", 0));
    } // retranslateUi

};

namespace Ui {
    class Close: public Ui_Close {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOSE_H
