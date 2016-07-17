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
};

#endif // SQL_H
