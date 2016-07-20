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
               "remark int,"
                "number int)");
    query->exec("insert into user(isvip,isdeal,remark) values('0','0','1')");
    return true;
}
bool sql::creatUser()
{
    query->exec("create table user (id INTEGER PRIMARY KEY, "
               "isvip int,"
               "isdeal int,"
               "remark int,"
                "number int)");
    query->exec("insert into user(isvip,isdeal,remark) values('1','0','1')");
    return true;
}
void sql::mydebug()
{
    query->exec("select * from user");
    while(query->next())
    {
       qDebug()<<query->value(0).toString()<<query->value(1).toString()<<query->value(2).toString()<<query->value(3).toString()<<query->value(4).toString();
    }

}
int sql::getCommonUserDealNot()
{
    query->exec("SELECT * FROM user WHERE isvip = '0' AND isdeal = '0'");
    int count = 0;
    while(query->next())
    {
       ++count;
    }
    return count;
}
int sql::getVIPUserDealNot()
{
    query->exec("SELECT * FROM user WHERE isvip = '1' AND isdeal = '0'");
    int count = 0;
    while(query->next())
    {
       ++count;
    }
    return count;
}
int sql::getAllUserDealNot()
{
    return getCommonUserDealNot() + getVIPUserDealNot();
}
int sql::getHasDealCommonUser()
{
    query->exec("SELECT * FROM user WHERE isvip = '0' AND isdeal = '1'");
    int count = 0;
    while(query->next())
    {
       ++count;
    }
    return count;
}
int sql::getHasDealVIPUser()
{
    query->exec("SELECT * FROM user WHERE isvip = '1' AND isdeal = '1'");
        int count = 0;
        while(query->next())
        {
           ++count;
        }
        return count;
}
int sql::getAllHasDealUser()
{
    return getHasDealCommonUser() + getHasDealVIPUser();
}
int sql::getAllCommonUser()
{
    query->exec("SELECT * FROM user WHERE isvip = '0'");
    int count = 0;
    while(query->next())
    {
       ++count;
    }
    return count;
}
int sql::getAllVIPUser()
{
    query->exec("SELECT * FROM user WHERE isvip = '1'");
    int count = 0;
    while(query->next())
    {
       ++count;
    }
    return count;
}

int sql::getAllUser()
{
    return getAllVIPUser() + getAllCommonUser();
}
int sql::getDealUser(QString number)
{
    query->exec("SELECT * FROM user WHERE number = '" + number + "'");
    int count = 0;
    while(query->next())
    {
       ++count;
    }
    return count;
}
void sql::addTest()
{
//    query->exec("insert into user(isvip,isdeal) values('0','0')");
     query->exec("insert into user(isvip,isdeal,remark,number) values('0','1','0','3')");
     query->exec("insert into user(isvip,isdeal,remark,number) values('0','1','1','2')");
     query->exec("insert into user(isvip,isdeal,remark,number) values('0','1','2','1')");
//    query->exec("insert into user(isvip,isdeal) values('1','0')");
}
QString sql::getCallNumber()
{
    query->exec("SELECT * FROM user WHERE isdeal = '0' ORDER BY isvip DESC ");
    while(query->next())
    {
        return query->value(0).toString();

    }
    return "0";
}
bool sql::remark(QString counternumber,QString number,QString re)
{
     query->exec("UPDATE user SET isdeal = '1' ,remark = '" + re + "' ,number = '" + counternumber + "' WHERE id = '" + number + "' ");
     mydebug();
     return true;
}
QString sql::sendRemarkToManager()
{
      QString data;
      query->exec("SELECT * FROM user WHERE isdeal = '1'");
      while(query->next())
      {
            data.append(query->value(1).toString() + ',');
            data.append(query->value(0).toString() + ',');
            data.append(query->value(4).toString() + ',');
            data.append(query->value(3).toString() + ',');
      }
      return data;
}
QString sql::isvip(QString number)
{
   query->exec("SELECT * FROM user WHERE id = '" + number + "'");
   while(query->next())
   {
        return query->value(1).toString();
   }
   return "0";
}
