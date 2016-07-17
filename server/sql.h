#ifndef SQL_H
#define SQL_H
class QSqlQuery;
class QSqlDatabase;
class sql
{
public:
    sql();
    QSqlDatabase *db;
    QSqlQuery *query;
    bool creatUser();
    bool creatUser(int);
    void mydebug();//打印所有表 调试用的
    int getCommonUser();
    int getVIPUser();
};

#endif // SQL_H
