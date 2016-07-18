#ifndef SEND_H
#define SEND_H
class QString;
class QUdpSocket;
class sql;
class send
{
public:
    send();
    QUdpSocket *sender;
    /*
     * 处理发送数据函数
     */
    bool sendDataToCounter(QString,QString);
    bool sendDataToCounter(QString,QString,QString);
    bool sendDataToCounter(QString,QString,QString,QString);
    bool sendDataToCounter(QString,QString,QString,QString,QString);
    bool sendDataToCustomer(QString,QString);
    bool sendDataToCustomer(QString,QString,QString);
    bool sendDataToCustomer(QString,QString,QString,QString);
    bool sendDataToCustomer(QString,QString,QString,QString,QString);
    bool sendDataToManager(QString,QString,QString,QString,QString,QString,QString,QString,
                  QString,QString,QString,QString,QString);
    ~send();
};

#endif // SEND_H
