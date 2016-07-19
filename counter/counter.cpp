#include "counter.h"
#include "config.h"
#include "signin.h"
#include "ui_counter.h"
#include "evaluate.h"
#include "close.h"
#include "send.h"
#include <QMessageBox>
#include <QCloseEvent>
#include <QEvent>
#include <QDebug>
#include <QtNetwork>
#include <QBrush>
#include <QPixmap>
#include <QPalette>



Counter::Counter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Counter)
{

    ui->setupUi(this);
    QPalette palette;
    palette.setBrush(this->backgroundRole(),QBrush(QPixmap("../img/t6.jpg")));
    this->setPalette(palette);
    Signin *signin = new Signin(this);
    signin->setGeometry(QRect(500,250,376,247));
    signin->setModal(true);
    signin->exec();

    receiver = new QUdpSocket(this);
    receiver->bind(45454,QUdpSocket::ShareAddress);
    connect(receiver, SIGNAL(readyRead()), this, SLOT(processPendingDatagram()));
}

Counter::~Counter()
{
    delete ui;
}
void Counter::closeEvent(QCloseEvent *event)
{
    Close *close = new Close(this);

    close->exec();
    if (close->flag==1)
    {
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

void Counter::on_pushButton_clicked()
{
    evaluate *e = new evaluate(this);
    e->exec();
}

void Counter::on_callButton_clicked()
{



    qDebug()<<config::name;
    send *s = new send();
    QString signal = "f";
    QString counternumber = config::name;

    s->sendDataToServer(signal,counternumber);

}
void Counter::processPendingDatagram()
{

    while(receiver->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(receiver->pendingDatagramSize());
        receiver->readDatagram(datagram.data(), datagram.size());
        QString data = datagram;
        config::getnumber = data.section(',',1,1);
        qDebug()<<config::getnumber;
    }
}

void Counter::on_callAgainButton_clicked()
{
    qDebug()<<config::getnumber;
     send *s = new send();
    QString signal = "g";
    QString counternumber = config::name;
    QString number = config::getnumber;
    s->sendDataToServer(signal,counternumber,number);
}
