#ifndef SQL_H
#define SQL_H
class QSqlQuery;
class QSqlDatabase;
class QString;
class sql
{
public:
    sql();
    QSqlDatabase *db;
    QSqlQuery *query;
    bool creatUser();
    bool creatUser(int);
    void mydebug();//打印所有表 调试用的
    int getCommonUserDealNot();
    int getVIPUserDealNot();
    int getAllUserDealNot();

    int getHasDealCommonUser();
    int getHasDealVIPUser();
    int getAllHasDealUser();

    int getAllCommonUser();
    int getAllVIPUser();
    int getAllUser();

    int getDealUser(QString);//获取某柜台受理人数
    void addTest();//增加测试用例
};

#endif // SQL_H
