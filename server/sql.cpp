#include "sql.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

sql::sql()
{
    db = new QSqlDatabase;
    db->addDatabase("QSQLITE");
    db->setDatabaseName("../bank.sql");
}
