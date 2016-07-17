#include "send.h"
#include <QtNetwork>

send::send()
{
    sender = new QUdpSocket();

}
bool send::sendData(QString signal,QString data1)
{
    QString senddata;
    senddata.append(signal + ",");
    senddata.append(data1);
    QByteArray datagram = senddata.toLatin1();
    sender->writeDatagram(datagram.data(), datagram.size(),
                          QHostAddress::LocalHost, 45454);
    return true;
}
