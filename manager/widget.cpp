#include "widget.h"
#include "ui_widget.h"
#include "dialog.h"
#include <QString>

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{


    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../bank.sql");
    if (!db.open()) {
            QMessageBox::critical(0, "Cannot open database",
                "Unable to establish a database connection.", QMessageBox::Cancel);
        }
        QSqlQuery query;
        query.exec("select * from manager");

        bool flag=false;
        while(query.next()){
            if(query.value(1).toString()==ui->lineEdit->text()&&query.value(2).toString()==ui->lineEdit_2->text()){
                flag=true;
                break;
            }


        }

<<<<<<< HEAD
        if(flag==true){
//                   this->close();
//                    Dialog *dlg=new Dialog();
//                    dlg->show();
            qDebug()<<"succeed!";
        }
        else{
            qDebug()<<"failed!";
        }



=======
        if(flag==true)
        {
            this->close();
            Dialog *dlg=new Dialog();
            dlg->show();
        }
>>>>>>> 4979fa2396e0060b0621b892a85d13e9d10a47b6
}
