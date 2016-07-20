#include "evaluate.h"
#include "ui_evaluate.h"
#include <QMessageBox>
#include "send.h"
#include "config.h"#include <QBrush>
#include <QPixmap>
#include <QPalette>


evaluate::evaluate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::evaluate)
{
    ui->setupUi(this);
    QPalette palette;
    palette.setBrush(this->backgroundRole(),QBrush(QPixmap("../img/t6.jpg")));
    this->setPalette(palette);
}

evaluate::~evaluate()
{
    delete ui;
}

void evaluate::on_checkBox_clicked()
{
    evaluate::value="0";
    send *s = new send();
    QString signal = "i";
    s->sendDataToServer(signal,config::name,config::getnumber,value);
   thanks.setWindowTitle("评价");
    thanks.setText("感谢您的评价！欢迎下次光临！");
     thanks.show();
    reject();
}

void evaluate::on_checkBox_2_clicked()
{
    evaluate::value="1";
    send *s = new send();
    QString signal = "i";
    s->sendDataToServer(signal,config::name,config::getnumber,value);
   thanks.setWindowTitle("评价");
    thanks.setText("感谢您的评价！欢迎下次光临！");


     thanks.show();
    reject();
}

void evaluate::on_checkBox_3_clicked()
{
    evaluate::value = "2";
    send *s = new send();
    QString signal = "i";
    s->sendDataToServer(signal,config::name,config::getnumber,value);
     thanks.show();
   thanks.setWindowTitle("评价");
    thanks.setText("感谢您的评价！我们将努力改进！欢迎下次光临！");

    reject();
}
