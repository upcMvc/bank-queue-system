#include "admin.h"
#include <QApplication>
#include <QIcon>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setWindowIcon(QIcon("../img/LOGO.png"));
    w.show();

    return a.exec();
}
