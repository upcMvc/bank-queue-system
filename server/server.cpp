#include "server.h"
#include "ui_server.h"
#include <QtNetwork>
#include "sql.h"

server::server(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::server)
{
    ui->setupUi(this);
    receive = new QUdpSocket(this);
    serversql = new sql();
    receive->bind(45454,QUdpSocket::ShareAddress);
    connect(receive, SIGNAL(readyRead()), this, SLOT(processPendingDatagram()));
}

server::~server()
{
    delete ui;
}

void server::processPendingDatagram()
{
    while(receive->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(receive->pendingDatagramSize());
        receive->readDatagram(datagram.data(), datagram.size());
        QString data = datagram;
        QString tempsignal = data.section(',',0,0);
        char signal = tempsignal[0].toLatin1();//转换成switch可识别的
        switch (signal) {
        case 'a':
            qDebug()<<"adsa";
            break;
        default:
            break;
        }

        qDebug()<<"";
    }
}
