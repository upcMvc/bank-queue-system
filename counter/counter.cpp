#include "counter.h"
#include "signin.h"
#include "ui_counter.h"
#include "evaluate.h"
#include "close.h"
#include <QMessageBox>
#include <QCloseEvent>
#include <QEvent>

Counter::Counter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Counter)
{
    ui->setupUi(this);
    Signin *signin = new Signin(this);
    signin->setGeometry(QRect(500,250,376,247));
    signin->setModal(true);
    signin->exec();
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
