#include "close.h"
#include "ui_close.h"

Close::Close(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Close)
{
    ui->setupUi(this);
}

Close::~Close()
{
    delete ui;
}

void Close::on_okpushButton_clicked()
{
    flag=1;
    reject();
}
void Close::on_cencelpushButton_clicked()
{
    flag=2;

}


void Close::on_pushButton_2_clicked()
{
    reject();
}
