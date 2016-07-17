#ifndef SEND_H
#define SEND_H
class QString;
class QUdpSocket;
class send
{
public:
    send();
    QUdpSocket *sender;
    bool sendData(QString,QString);
};

#endif // SEND_H
