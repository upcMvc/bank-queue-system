#include "admin.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

bool Widget::createManager(QString username,QString password)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../bank.sql");
    if (!db.open()) {
        QMessageBox::critical(0, "Cannot open database",
            "Unable to establish a database connection.", QMessageBox::Cancel);
        return false;
    }
    QSqlQuery query;
    query.exec("create table manager (id INTEGER PRIMARY KEY, "
               "name varchar(20),"
               "password varchar(20))");
    query.exec("insert into manager(name,password) values('" + username + "','" + password + "')");
    db.close();
    return true;
}

bool Widget::createEmployee(QString username,QString password)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../bank.sql");
    if (!db.open()) {
        QMessageBox::critical(0, "Cannot open database",
            "Unable to establish a database connection.", QMessageBox::Cancel);
        return false;
    }
    QSqlQuery query;
    query.exec("create table employee (id INTEGER PRIMARY KEY, "
               "name varchar(20),"
               "password varchar(20))");
    query.exec("insert into employee(name,password) values('" + username + "','" + password + "')");
    return true;
}


void Widget::on_pushButton_clicked()
{
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    createManager(username,password);
    QMessageBox::information(this,"infomation","插入成功");
}


void Widget::on_pushButton_2_clicked()
{
    QString username = ui->lineEdit_3->text();
    QString password = ui->lineEdit_4->text();
    createManager(username,password);
    QMessageBox::information(this,"infomation","插入成功");
}
