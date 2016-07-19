#ifndef SEND_H
#define SEND_H

class QString;
class QUdpSocket;
class send{
public:
    send();
    QUdpSocket *sender;
    /*
     * 处理发送数据函数
     */
    bool sendDataToServer(QString,QString);
    bool sendDataToServer(QString,QString,QString);
     bool sendDataToServer(QString,QString,QString,QString);

    ~send();

};







#endif // SEND_H
