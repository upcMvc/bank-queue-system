/********************************************************************************
** Form generated from reading UI file 'signin.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNIN_H
#define UI_SIGNIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Signin
{
public:
    QLineEdit *nameLineEdit;
    QLineEdit *passwordLineEdit;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;

    void setupUi(QDialog *Signin)
    {
        if (Signin->objectName().isEmpty())
            Signin->setObjectName(QStringLiteral("Signin"));
        Signin->resize(376, 247);
        nameLineEdit = new QLineEdit(Signin);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));
        nameLineEdit->setGeometry(QRect(120, 50, 181, 31));
        passwordLineEdit = new QLineEdit(Signin);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));
        passwordLineEdit->setEnabled(true);
        passwordLineEdit->setGeometry(QRect(120, 110, 181, 31));
        passwordLineEdit->setEchoMode(QLineEdit::Password);
        label = new QLabel(Signin);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 60, 54, 12));
        label_2 = new QLabel(Signin);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 120, 54, 12));
        pushButton = new QPushButton(Signin);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(230, 180, 75, 23));

        retranslateUi(Signin);

        QMetaObject::connectSlotsByName(Signin);
    } // setupUi

    void retranslateUi(QDialog *Signin)
    {
        Signin->setWindowTitle(QApplication::translate("Signin", "\347\231\273\345\275\225", 0));
        label->setText(QApplication::translate("Signin", "\350\264\246\345\217\267", 0));
        label_2->setText(QApplication::translate("Signin", "\345\257\206\347\240\201", 0));
        pushButton->setText(QApplication::translate("Signin", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class Signin: public Ui_Signin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNIN_H
