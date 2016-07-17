#include "dialog.h"
#include "ui_dialog.h"
#include <QDateTime>
#include <QTimer>
#include <QString>
#include <QtCore>
#include <QtNetwork>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //时间表
    QTimer *timer=new QTimer(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(time()));
    timer->start(500);

    //接收从服务器来的数据
    receiver=new QUdpSocket(this);
    receiver->bind(45454,QUdpSocket::ShareAddress);
    connect(receiver,SIGNAL(readyRead()),this,SLOT(processPendingDatagram()));


}

Dialog::~Dialog()
{
    delete ui;
}

//时间函数
void Dialog::time(){
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss ddd");
    ui->label_3->setText(str);
}

void Dialog::processPendingDatagram(){
    //等待数据
    while(receiver->hasPendingDatagrams()){
        QByteArray datagram;
        datagram.resize(receiver->pendingDatagramSize());

        //接受数据，存到datagram中
        receiver->readDatagram(datagram.data(),datagram.size());
        ui->label_5->setText(datagram);
    }
}


