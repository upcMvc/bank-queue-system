#include "evaluate.h"
#include "ui_evaluate.h"
#include <QMessageBox>

evaluate::evaluate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::evaluate)
{
    ui->setupUi(this);
}

evaluate::~evaluate()
{
    delete ui;
}

void evaluate::on_checkBox_clicked()
{
    evaluate::value=0;
   thanks.setWindowTitle("评价");
    thanks.setText("感谢您的评价！欢迎下次光临！");
     thanks.show();
    reject();
}

void evaluate::on_checkBox_2_clicked()
{
    evaluate::value=1;
   thanks.setWindowTitle("评价");
    thanks.setText("感谢您的评价！欢迎下次光临！");
     thanks.show();
    reject();
}

void evaluate::on_checkBox_3_clicked()
{
    evaluate::value=0;
   thanks.setWindowTitle("评价");
    thanks.setText("感谢您的评价！我们将努力改进！欢迎下次光临！");
     thanks.show();
    reject();
}
