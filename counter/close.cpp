#include "close.h"
#include "ui_close.h"
#include <QBrush>
#include <QPixmap>
#include <QPalette>


Close::Close(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Close)
{
    ui->setupUi(this);
    QPalette palette;
    palette.setBrush(this->backgroundRole(),QBrush(QPixmap("../untitled/111.jpg")));  //括号内为图片的相对目录
    this->setPalette(palette);
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
