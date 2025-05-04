#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{
    bool test=false;
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_PRojet2A");
    db.setUserName("proballManager");
    db.setPassword("foot123456");

    if (db.open())
        test=true;

    return  test;
}
void Connection::closeconnection(){db.close();}
