
#include "send.h"
#include <QtNetwork>
#include "config.h"
#include <QDebug>


send::send()
{
    sender = new QUdpSocket();
}
send::~send()
{
    delete sender;
}

bool send::sendDataToServer(QString signal,QString data1)
{
    QString senddata;
    senddata.append(signal + ",");
    senddata.append(data1);
    QByteArray datagram = senddata.toLatin1();
    sender->writeDatagram(datagram.data(), datagram.size(),
                          QHostAddress(config::servehost), 45454);

    return true;
}
bool send::sendDataToServer(QString signal,QString data1,QString data2)
{
    QString senddata;
    senddata.append(signal + ",");
    senddata.append(data1 + ",");
    senddata.append(data2);
    QByteArray datagram = senddata.toLatin1();
    sender->writeDatagram(datagram.data(), datagram.size(),
                          QHostAddress(config::servehost), 45454);
    return true;
}
bool send::sendDataToServer(QString signal,QString data1,QString data2,QString data3)
{
    QString senddata;
    senddata.append(signal + ",");
    senddata.append(data1 + ",");
    senddata.append(data2 + ",");
    senddata.append(data3);
    QByteArray datagram = senddata.toLatin1();
    sender->writeDatagram(datagram.data(), datagram.size(),
                          QHostAddress(config::servehost), 45454);
    return true;
}
