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
    bool sendData(QString,QString,QString);
    bool sendData(QString,QString,QString,QString);
    bool sendData(QString,QString,QString,QString,QString);
    bool sendData(QString,QString,QString,QString,QString,QString,QString,QString,
                  QString,QString,QString,QString,QString);
};

#endif // SEND_H
