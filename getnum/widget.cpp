#include "widget.h"
#include "ui_widget.h"
#include <QLabel>
#include <QString>

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


int queue=0;
int common=0;
int vip=0;

void Widget::on_pushButton_clicked()
{
    ui->label->setText("普通客户您好，您前面有"+QString::number(queue)+"人在排队");
    queue++;
    common++;
    ui->lineEdit->setText("取号成功，您的号码是"+QString::number(common)+"号");

}

void Widget::on_pushButton_2_clicked()
{
    queue++;
    ui->label->setText("普通客户您好，您前面有"+QString::number(queue)+"人在排队");
    ui->label_2->setText("vip客户您好，您前面有"+QString::number(vip)+"人在排队");
    vip++;
    ui->lineEdit_2->setText("取号成功，您的号码是"+QString::number(vip)+"号");
}
