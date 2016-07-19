#include "signin.h"
#include "ui_signin.h"
#include "config.h"
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
      config::name= ui->nameLineEdit->text();


   while (query.next()) {

            if (query.value(1).toString() == ui->nameLineEdit->text() && query.value(2).toString() == ui->passwordLineEdit->text())
        {
            flag=true;
            break;
        }
    }
    qDebug()<<flag;
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

