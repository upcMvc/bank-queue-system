#ifndef COUNTER_H
#define COUNTER_H
#include "ui_counter.h"

#include <QDialog>
#include <QCloseEvent>
#include <QEvent>
#include <QString>
#include <QtNetwork>
class QUdpSocket;

namespace Ui {
class Counter;
}

class Counter : public QDialog
{
    Q_OBJECT

public:
    explicit Counter(QWidget *parent = 0);
    ~Counter();
    void closeEvent(QCloseEvent *event);
    QUdpSocket *receiver;




private slots:
    void on_pushButton_clicked();

    
    void on_callButton_clicked();

    void on_callAgainButton_clicked();
     void processPendingDatagram();

private:
    Ui::Counter *ui;
};

#endif // COUNTER_H
