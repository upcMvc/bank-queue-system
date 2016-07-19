#include "close.h"
#include "ui_close.h"
#include <QMessageBox>

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

void Close::on_pushButton_clicked()
{
    QMessageBox error;
    error.setWindowTitle("退出验证");
    error.setText("密码输入错误！请重新输入！");

    if (ui->lineEdit->text() == "123456")
    {
        Close::flag=1;
        reject();
    }
    else
    {
        flag = 0;
        error.exec();
    }
}
