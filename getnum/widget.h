#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QCloseEvent>
#include <QEvent>

namespace Ui {
class Widget;
}

class QUdpSocket;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
     void closeEvent(QCloseEvent *event);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void time();

    void processPendingDatagram();

private:
    Ui::Widget *ui;
    QUdpSocket *sender;
    QUdpSocket *receiver;

};



#endif // WIDGET_H
