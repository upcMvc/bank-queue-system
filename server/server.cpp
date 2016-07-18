#include "server.h"
#include "ui_server.h"
#include <QtNetwork>
#include "sql.h"
#include "send.h"

server::server(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::server)
{
    ui->setupUi(this);
    receive = new QUdpSocket(this);
    serversql = new sql();
    receive->bind(45454,QUdpSocket::ShareAddress);
    sendsignal = new send();
    sendsignal->sendData("1234a","as","da","haha","dsff","as","da","haha","dsff","as","da","haha","dsff");
    connect(receive, SIGNAL(readyRead()), this, SLOT(processPendingDatagram()));

}

server::~server()
{
    delete ui;
}

void server::processPendingDatagram()
{
    while(receive->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(receive->pendingDatagramSize());
        receive->readDatagram(datagram.data(), datagram.size());
        QString data = datagram;
        QString tempsignal = data.section(',',0,0);
        char signal = tempsignal[0].toLatin1();//转换成switch可识别的
        switch (signal) {
        case 'a':
            if(serversql->creatUser(0) == true)
                qDebug()<<"创建成功";
            break;
        case 'b':
            if(serversql->creatUser() == true)
                qDebug()<<"创建成功";
            break;
        case 'c':
            serversql->mydebug();
            break;
        default:
            break;
        }

        qDebug()<<"";
    }
}

