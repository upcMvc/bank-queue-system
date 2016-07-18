#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>
class QUdpSocket;
class sql;
class send;

namespace Ui {
class server;
}

class server : public QMainWindow
{
    Q_OBJECT

public:
    explicit server(QWidget *parent = 0);
    ~server();
    QUdpSocket *receive;
    sql        *serversql;
    send       *sendsignal;
    bool sendAllData();//向经理端发送所有数据
    bool sendUserAndVipUser();//向取号端发送有几个vip和普通用户排队
private:
    Ui::server *ui;

private slots:
    void processPendingDatagram();
};

#endif // SERVER_H
