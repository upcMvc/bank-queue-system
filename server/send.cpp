#include "send.h"
#include <QtNetwork>
#include "config.h"
#include "sql.h"
send::send()
{
    sender = new QUdpSocket();
}
send::~send()
{
    delete sender;
}

bool send::sendDataToCounter(QString signal,QString data1,char host[])
{
    QString senddata;
    senddata.append(signal + ",");
    senddata.append(data1);
    QByteArray datagram = senddata.toLatin1();
    sender->writeDatagram(datagram.data(), datagram.size(),
                          QHostAddress(host), 45454);
    return true;
}
bool send::sendDataToCounter(QString signal,QString data1,QString data2,char host[])
{
    QString senddata;
    senddata.append(signal + ",");
    senddata.append(data1 + ",");
    senddata.append(data2);
    QByteArray datagram = senddata.toLatin1();
    sender->writeDatagram(datagram.data(), datagram.size(),
                          QHostAddress(host), 45454);
    qDebug()<<"经理端发送成功";
    return true;
}
bool send::sendDataToCounter(QString signal,QString data1,QString data2,QString data3,char host[])
{
    QString senddata;
    senddata.append(signal + ",");
    senddata.append(data1 + ",");
    senddata.append(data2 + ",");
    senddata.append(data3);
    QByteArray datagram = senddata.toLatin1();
    sender->writeDatagram(datagram.data(), datagram.size(),
                          QHostAddress(host), 45454);
    return true;
}
bool send::sendDataToCounter(QString signal,QString data1,QString data2,QString data3,QString data4,char host[])
{
    QString senddata;
    senddata.append(signal + ",");
    senddata.append(data1 + ",");
    senddata.append(data2 + ",");
    senddata.append(data3 + ",");
    senddata.append(data4);
    QByteArray datagram = senddata.toLatin1();
    sender->writeDatagram(datagram.data(), datagram.size(),
                          QHostAddress(host), 45454);
    return true;
}
bool send::sendDataToManager(QString signal,QString data1,QString data2,QString data3,QString data4,
                    QString data5,QString data6,QString data7,QString data8,QString data9,
                    QString data10,QString data11,QString data12)
{
    QString senddata;
    senddata.append(signal + ",");
    senddata.append(data1 + ",");
    senddata.append(data2 + ",");
    senddata.append(data3 + ",");
    senddata.append(data4 + ",");
    senddata.append(data5 + ",");
    senddata.append(data6 + ",");
    senddata.append(data7 + ",");
    senddata.append(data8 + ",");
    senddata.append(data9 + ",");
    senddata.append(data10 + ",");
    senddata.append(data11 + ",");
    senddata.append(data12 );
    QByteArray datagram = senddata.toLatin1();
    sender->writeDatagram(datagram.data(), datagram.size(),
                          QHostAddress(config::managerhost), 45454);
    return true;
}
bool send::sendDataToCustomer(QString signal,QString data1)
{
    QString senddata;
    senddata.append(signal + ",");
    senddata.append(data1);
    QByteArray datagram = senddata.toLatin1();
    sender->writeDatagram(datagram.data(), datagram.size(),
                          QHostAddress(config::customhost), 45454);
    return true;
}
bool send::sendDataToCustomer(QString signal,QString data1,QString data2)
{
    QString senddata;
    senddata.append(signal + ",");
    senddata.append(data1 + ",");
    senddata.append(data2);
    QByteArray datagram = senddata.toLatin1();
    sender->writeDatagram(datagram.data(), datagram.size(),
                          QHostAddress(config::customhost), 45454);
    return true;
}
bool send::sendDataToCustomer(QString signal,QString data1,QString data2,QString data3)
{
    QString senddata;
    senddata.append(signal + ",");
    senddata.append(data1 + ",");
    senddata.append(data2 + ",");
    senddata.append(data3);
    QByteArray datagram = senddata.toLatin1();
    sender->writeDatagram(datagram.data(), datagram.size(),
                          QHostAddress(config::customhost), 45454);
    return true;
}
bool send::sendDataToCustomer(QString signal,QString data1,QString data2,QString data3,QString data4)
{
    QString senddata;
    senddata.append(signal + ",");
    senddata.append(data1 + ",");
    senddata.append(data2 + ",");
    senddata.append(data3 + ",");
    senddata.append(data4);
    QByteArray datagram = senddata.toLatin1();
    sender->writeDatagram(datagram.data(), datagram.size(),
                          QHostAddress(config::customhost), 45454);
    return true;
}
bool send::sendDataToManager(QString signal,QString data1,QString data2,QString data3,QString data4)
{
    QString senddata;
    senddata.append(signal + ",");
    senddata.append(data1 + ",");
    senddata.append(data2 + ",");
    senddata.append(data3 + ",");
    senddata.append(data4);
    QByteArray datagram = senddata.toLatin1();
    sender->writeDatagram(datagram.data(), datagram.size(),
                          QHostAddress(config::managerhost), 45454);
    return true;
}
