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


private:
    Ui::server *ui;

private slots:
    void processPendingDatagram();
};

#endif // SERVER_H
