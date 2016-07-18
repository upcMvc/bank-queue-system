#include "signin.h"
#include "ui_signin.h"
#include <QString>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

Signin::Signin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Signin)
{
    ui->setupUi(this);
}

Signin::~Signin()
{
    delete ui;
}
void Signin::closeEvent(QCloseEvent *event)
{
    event->ignore();

}
void Signin::on_pushButton_clicked()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../bank.sql");
    if(!db.open())
    {
        QMessageBox::critical(0,"Cannot open datebase",
                              "Unable to establish a database connection.",QMessageBox::Cancel);

    }
    QSqlQuery query;
    query.exec("select * from employee");

    bool flag=false;

    QMessageBox error;
    error.setWindowTitle("登录失败");
    QString name;
    QString password;
    name = ui->nameLineEdit->text();
    password = ui->passwordLineEdit->text();
    //qDebug()<<password;
   while (query.next()) {
        qDebug()<<query.value(1).toString();
        if (query.value(1).toString() == name && query.value(2).toString() == password)
        {
            flag=true;
            break;
        }
    }

    if (flag)
    {
        reject();

    }
    else
    {
        error.setText("密码或账户输入错误");
        error.exec();
    }
}

