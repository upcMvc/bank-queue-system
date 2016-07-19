#ifndef SIGNIN_H
#define SIGNIN_H


#include <QDialog>
#include <QEvent>
#include <QCloseEvent>
#include <QString>
#include "ui_signin.h"
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class Signin;
}

class Signin : public QDialog
{
    Q_OBJECT
public:
//    static QString name;
//    static QString password;
//    void getName();
//    void getPassword();

public:
    explicit Signin(QWidget *parent = 0);
    ~Signin();
    void closeEvent(QCloseEvent *event);




private:
    Ui::Signin *ui;
private slots:
    void on_pushButton_clicked();
    //void on_closepushButton_clicked();
};

#endif // SIGNIN_H
