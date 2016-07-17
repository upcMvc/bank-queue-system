#ifndef SQL_H
#define SQL_H

class QSqlDatabase;
class sql
{
public:
    sql();
    QSqlDatabase *db;
    bool creatUser();
};

#endif // SQL_H
