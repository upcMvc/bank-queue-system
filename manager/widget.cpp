#include "widget.h"
#include "ui_widget.h"
#include "dialog.h"
#include <QString>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QIcon>
#include <QtNetwork>
#include <QBrush>
#include <QPixmap>
#include <QPalette>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPalette palette;
    palette.setBrush(this->backgroundRole(),QBrush(QPixmap("../img/050.jpg")));  //括号内为图片的相对目录
    this->setPalette(palette);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    Widget::setWindowTitle(tr("登陆"));

    //向服务器发射请求
    sender=new QUdpSocket(this);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{



    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../bank.sql");
    if (!db.open()) {
       QMessageBox::critical(0, "Cannot open database","Unable to establish a database connection.", QMessageBox::Cancel);
    }
    QSqlQuery query;
    query.exec("select * from manager");
    bool flag=false;
    while(query.next()){
       if(query.value(1).toString()==ui->lineEdit->text()&&query.value(2).toString()==ui->lineEdit_2->text()){
           flag=true;
           break;
       }
    }
    if(flag==true){
        this->close();
        Dialog *dlg=new Dialog();
        dlg->show();
        QByteArray datagram="l";
        sender->writeDatagram(datagram.data(),datagram.size(),QHostAddress("172.19.43.206"),45454);
    }
    else{
        QMessageBox::information(this,tr("警告"),tr("对不起，密码或用户名输入错误"));
    }

}
void Widget::on_pushButton_2_clicked()
{
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
}
