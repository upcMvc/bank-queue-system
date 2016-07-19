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
    bool remark(QString,QString,QString);//几号柜台  几号  评价
    bool sendRemarkToManager(); //向经理端发送各个评价信息
    QString isvip(QString);//判断是否是vip
private:
    Ui::server *ui;

private slots:
    void processPendingDatagram();
};

#endif // SERVER_H
