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
    ui->label_5->deleteLater();
    ui->pushButton->deleteLater();
    Dialog::setWindowTitle(tr("经理管理页面"));


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


//接受数据
void Dialog::processPendingDatagram(){
    //等待数据
    QByteArray datagram;
    while(receiver->hasPendingDatagrams()){

        datagram.resize(receiver->pendingDatagramSize());

        //接受数据，存到datagram中
        receiver->readDatagram(datagram.data(),datagram.size());

    }

    //将QByteArray转换成Qstring
    QString string;
    string = QString(datagram);

    QString str0=string.section(',',0,0);  //j  或 k
    if("j"==str0){
        QString str1=string.section(',',1,1);
        QString str2=string.section(',',2,2);
        QString str3=string.section(',',3,3);

        QString str4=string.section(',',4,4);
        QString str5=string.section(',',5,5);
        QString str6=string.section(',',6,6);

        QString str7=string.section(',',7,7);
        QString str8=string.section(',',8,8);
        QString str9=string.section(',',9,9);

        QString str10=string.section(',',10,10);
        QString str11=string.section(',',11,11);
        QString str12=string.section(',',12,12);

        ui->textEdit->setPlainText(tr("总排队人数：")+str1);
        ui->textEdit->append(tr("普通客户排队人数：")+str2);
        ui->textEdit->append(tr("VIP客户排队人数：")+str3);

        ui->textEdit->append(tr("已受理总人数：")+str4);
        ui->textEdit->append(tr("已受理普通客户人数：")+str5);
        ui->textEdit->append(tr("已受理VIP客户人数：")+str6);

        ui->textEdit->append(tr("当前未受理总人数：")+str7);
        ui->textEdit->append(tr("当前未受理普通客户人数：")+str8);
        ui->textEdit->append(tr("当前未受理VIP客户人数：")+str9);

        ui->textEdit->append(tr("柜员1已受理人数：")+str10);
        ui->textEdit->append(tr("柜员2已受理人数：")+str11);
        ui->textEdit->append(tr("柜员3已受理人数：")+str12);
    }
    if("k"==str0){
        QString str1=string.section(',',1,1);  //普通==0或VIP==1
        QString str2=string.section(',',2,2);  //用户
        QString str3=string.section(',',3,3);  //柜员
        QString str4=string.section(',',4,4);  //评价0==好评  1==中评  2==差评

        if("0"==str1){
            if("0"==str4){
                ui->textEdit_2->append(tr("普通用户")+str2+("号")+tr("对柜员")+str3+tr("的评价是好评"));
            }
            if("1"==str4){
                ui->textEdit_2->append(tr("普通用户")+str2+("号")+tr("对柜员")+str3+tr("的评价是中评"));
            }
            if("2"==str4){
                ui->textEdit_2->append(tr("普通用户")+str2+("号")+tr("对柜员")+str3+tr("的评价是差评"));
            }
        }
        if("1"==str1){
            if("0"==str4){
                ui->textEdit_2->append(tr("VIP用户")+str2+("号")+tr("对柜员")+str3+tr("的评价是好评"));
            }
            if("1"==str4){
                ui->textEdit_2->append(tr("VIP用户")+str2+("号")+tr("对柜员")+str3+tr("的评价是中评"));
            }
            if("2"==str4){
                ui->textEdit_2->append(tr("VIP用户")+str2+("号")+tr("对柜员")+str3+tr("的评价是差评"));
            }

        }
    }


}


