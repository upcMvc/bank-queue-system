#include "counter.h"
#include "signin.h"
#include <QApplication>
#include <QString>
#include <QIcon>
QString getnumber;
QString username;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Counter counter;
    counter.show();


    return a.exec();
}
