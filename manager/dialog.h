#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimer>



namespace Ui {
class Dialog;
}

class QUdpSocket;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);

    ~Dialog();

private:
    Ui::Dialog *ui;
    QUdpSocket *receiver;

public slots:
    void time();
    void processPendingDatagram();
};

#endif // DIALOG_H
