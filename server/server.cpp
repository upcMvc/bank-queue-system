#include "server.h"
#include "ui_server.h"
#include <QtNetwork>
#include "sql.h"
#include "send.h"
#include <unistd.h>

server::server(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::server)
{
    ui->setupUi(this);
    receive = new QUdpSocket(this);
    serversql = new sql();
    receive->bind(45454,QUdpSocket::ShareAddress);
    sendsignal = new send();
    sendAllData();
    sendUserAndVipUser();
//    serversql->addTest();
    serversql->mydebug();
    connect(receive, SIGNAL(readyRead()), this, SLOT(processPendingDatagram()));

}

server::~server()
{
    delete sendsignal;
    delete serversql;
    delete receive;
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
            {
               sendsignal->sendDataToCounter("e",QString::number(serversql->getAllUser() + 1,10));
               qDebug()<<"取号成功";
            }
            break;
        case 'b':
            if(serversql->creatUser() == true)
            {
                sendsignal->sendDataToCounter("e",QString::number(serversql->getAllUser() + 1,10));
                qDebug()<<"取号成功";
            }
            break;
        case 'm':
            sendUserAndVipUser();
            break;
        case 'l':
            sendAllData();
            break;
        case 'f':
            sendAllData();
            break;
        default:
            break;
        }

        qDebug()<<"";
    }
}
bool server::sendAllData()
{
    sendsignal->sendDataToManager("j",
    QString::number(serversql->getAllUser(),10),
    QString::number(serversql->getAllCommonUser(),10),
    QString::number(serversql->getAllVIPUser(),10),
    QString::number(serversql->getAllHasDealUser(),10),
    QString::number(serversql->getHasDealCommonUser(),10),
    QString::number(serversql->getHasDealVIPUser(),10),
    QString::number(serversql->getAllUserDealNot(),10),
    QString::number(serversql->getCommonUserDealNot(),10),
    QString::number(serversql->getVIPUserDealNot(),10),
    QString::number(serversql->getDealUser("1"),10),
    QString::number(serversql->getDealUser("2"),10),
    QString::number(serversql->getDealUser("3"),10));
    qDebug()<<"发送成功";
    return true;
}

bool server::sendUserAndVipUser()
{
      sendsignal->sendDataToCustomer("c",
      QString::number(serversql->getCommonUserDealNot(),10),
      QString::number(serversql->getVIPUserDealNot(),10));
      qDebug()<<"发送成功";
      return true;
}
