#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

#include "globalvars.h"
#include "connectmysql.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

#if USE_DATABASE
    ConnectMySQL sql;

    if(sql.createConnection())
    {
        qDebug() << "Success: connect DB!!";
    }


#endif //USE_DATABASE

    MainWindow w;
    w.show();

    int res = app.exec();

#if USE_DATABASE
    sql.closeConnection();
#endif //USE_DATABASE

    return res;
}
