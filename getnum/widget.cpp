#include "widget.h"
#include "ui_widget.h"
#include "close.h"
#include <QLabel>
#include <QString>
#include <QByteArray>
#include <QtNetwork>
#include <QDebug>
#include <QCloseEvent>
#include <QEvent>
#include <QPalette>
#include <QBrush>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPalette palette;
    palette.setBrush(this->backgroundRole(),QBrush(QPixmap("../img/zx.jpg")));  //括号内为图片的相对目录
    this->setPalette(palette);

    sender=new QUdpSocket(this);

    receiver=new QUdpSocket(this);
    receiver->bind(45454,QUdpSocket::ShareAddress);

    connect(receiver,SIGNAL(readyRead()),this,SLOT(processPendingDatagram()));

    //时间表
    QTimer *timer=new QTimer(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(time()));
    timer->start(500);



}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked(){
    //向服务器发送信息
    QByteArray datagram="a";
    sender->writeDatagram(datagram.data(),datagram.size(),QHostAddress("172.19.43.206"),45454);
}

void Widget::on_pushButton_2_clicked(){    
    //向服务器发送信息
    QByteArray datagram="b";
    sender->writeDatagram(datagram.data(),datagram.size(),QHostAddress("172.19.43.206"),45454);
}

void Widget::time(){
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss ddd");
    ui->label_5->setText(str);
}

void Widget::processPendingDatagram(){
    //等待数据
    QByteArray datagram;
    while(receiver->hasPendingDatagrams()){

        datagram.resize(receiver->pendingDatagramSize());

        //接受数据，存到datagram中
        receiver->readDatagram(datagram.data(),datagram.size());

    }

    //将QByteArray转换成Qstring
    QString string;
    QString str0;
    string = QString(datagram);
    str0=string.section(",",0,0);
    if("c"==str0){
        QString str1=string.section(',',1,1);
        QString str2=string.section(',',2,2);
        ui->label->setText("普通客户您好，您前面有"+str1+"位普通客户，有"+str2+"位VIP用户");
        ui->label_2->setText("vip客户您好，您前面有"+str2+"人在排队");
    }
    if("e"==str0){
        QString str1=string.section(',',1,1);
        QString str2=string.section(',',2,2);
        QString str3=string.section(',',3,3);
        ui->label->setText("普通客户您好，您前面有"+str2+"位普通客户，有"+str3+"位VIP用户");
        ui->label_2->setText("vip客户您好，您前面有"+str3+"人在排队");
        ui->lineEdit->setText("取号成功，您的号码是"+str1+"号");
    }
    if("x"==str0){
        QString str1=string.section(',',1,1);
        QString str2=string.section(',',2,2);
        QString str3=string.section(',',3,3);
        ui->label->setText("普通客户您好，您前面有"+str2+"位普通客户，有"+str3+"位VIP用户");
        ui->label_2->setText("vip客户您好，您前面有"+str3+"人在排队");
        ui->lineEdit_2->setText("取号成功，您的号码是"+str1+"号");
    }
    if("h"==str0){
        QString str1=string.section(',',1,1);
        QString str2=string.section(',',2,2);
        QString str3=string.section(',',3,3);
        if("0"==str3){

            ui->textEdit->moveCursor(QTextCursor::Start);
            ui->textEdit->insertPlainText("请普通用户"+str1+"号到"+str2+"号柜台办理业务\n");
        }
        else{

            ui->textEdit->moveCursor(QTextCursor::Start);
            ui->textEdit->insertPlainText("请VIP用户"+str1+"号到"+str2+"号柜台办理业务\n");
        }
    }

}
void Widget::closeEvent(QCloseEvent *event)
{
    Close *close = new Close(this);
    close->setModal(true);
    close->exec();
    if (close->flag == 1)
    {
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

