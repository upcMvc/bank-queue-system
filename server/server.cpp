#include "server.h"
#include "ui_server.h"
#include <QtNetwork>
#include "sql.h"
#include "send.h"
#include <unistd.h>
#include "config.h"

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
    sendRemarkToManager();
//    serversql->mydebug();
//    sendsignal->sendDataToCustomer("h","2","1","1");
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
        QString countnumber,number;
        QString tempsignal = data.section(',',0,0);
        char signal = tempsignal[0].toLatin1();//转换成switch可识别的
        qDebug()<<data;
        switch (signal) {
        case 'a':
            if(serversql->creatUser(0) == true)
            {
               sendsignal->sendDataToCustomer("e",QString::number(serversql->getAllUser() + 1,10),QString::number(serversql->getCommonUserDealNot(),10),QString::number(serversql->getVIPUserDealNot(),10));
               qDebug()<<"取号成功";
               //sendUserAndVipUser();
               sendAllData();
            }
            break;
        case 'b':
            if(serversql->creatUser() == true)
            {
               sendsignal->sendDataToCustomer("x",QString::number(serversql->getAllUser() + 1,10),QString::number(serversql->getCommonUserDealNot(),10),QString::number(serversql->getVIPUserDealNot(),10));
                qDebug()<<"取号成功";
//                sendUserAndVipUser();
                sendAllData();
            }
            break;
        case 'm':
            sendUserAndVipUser();
            break;
        case 'l':
            sendAllData();
            break;
        case 'f':
            countnumber = data.section(',',1,1);//case 中不能定义变量 在上面已经定义
            number = serversql->getCallNumber();
            qDebug()<<number;
            if(countnumber == "1")
                sendsignal->sendDataToCounter("n",number,config::counterhost1);
            if(countnumber == "2")
                sendsignal->sendDataToCounter("n",number,config::counterhost2);
            if(countnumber == "3")
                sendsignal->sendDataToCounter("n",number,config::counterhost3);
            sendsignal->sendDataToCustomer("h",number,countnumber,isvip(number));
            break;
        case 'g':
            countnumber = data.section(',',1,1);
            number = data.section(',',2,2);
            sendsignal->sendDataToCustomer("h",number,countnumber,isvip(number));
            break;
        case 'i':
            remark(data.section(',',1,1),data.section(',',2,2),data.section(',',3,3));
            sendUserAndVipUser();
            sendRemarkToManager();
            break;
        default:
            break;
        }
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
bool server::remark(QString counternumber,QString number,QString re)
{
    return serversql->remark(counternumber,number,re);
}
bool server::sendRemarkToManager()
{
    QString data;
    data = serversql->sendRemarkToManager();
    int i = 0;//循环变量
    while(data.section(',',i,i) == "0" || data.section(',',i,i) =="1")
    {
       sendsignal->sendDataToManager("k",data.section(',',i,i),
                                     data.section(',',i + 1,i +1),
                                     data.section(',',i + 2,i +2),
                                     data.section(',',i + 3,i + 3));
       sleep(1);
       i+=4;
    }
    return true;
}
QString server::isvip(QString number)
{
    return serversql->isvip(number);
}
