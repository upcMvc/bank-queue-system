#include "sql.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

sql::sql()
{
    db = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
    db->setDatabaseName("../bank.sql");
    query = new QSqlQuery;
    if (!db->open()) {
        QMessageBox::critical(0, "Cannot open database",
            "Unable to establish a database connection.", QMessageBox::Cancel);
    }
}
bool sql::creatUser(int isvip)
{
    qDebug()<<isvip;
    query->exec("create table user (id INTEGER PRIMARY KEY, "
               "isvip int,"
               "isdeal int,"
               "remark int)");
    query->exec("insert into user(isvip,isdeal) values('0','0')");
    return true;
}
bool sql::creatUser()
{
    query->exec("create table user (id INTEGER PRIMARY KEY, "
               "isvip int,"
               "isdeal int,"
               "remark int)");
    query->exec("insert into user(isvip,isdeal) values('1','0')");
    return true;
}
void sql::mydebug()
{
    query->exec("select * from user");
    while(query->next())
    {
       qDebug()<<query->value(0).toString()<<query->value(1).toString()<<query->value(2).toString()<<query->value(3).toString();
    }

}
int sql::getCommonUser()
{
    query->exec("SELECT * FROM user WHERE isvip = '0' AND isdeal = '0'");
    int count = 0;
    while(query->next())
    {
       ++count;
    }
    return count;
}
int sql::getVIPUser()
{
    query->exec("SELECT * FROM user WHERE isvip = '1' AND isdeal = '0'");
    int count = 0;
    while(query->next())
    {
       ++count;
    }
    return count;
}
