#include "dialog.h"
#include "ui_dialog.h"
#include <QDateTime>
#include <QTimer>
#include <QString>
#include <QtCore>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QTimer *timer=new QTimer(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(time()));
    timer->start(500);


}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::time(){
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss ddd");
    ui->label_3->setText(str);
}


