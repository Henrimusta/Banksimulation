#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <QString>



class databaseConnection
{
public:
    databaseConnection();
    static QString getBaseUrl();
};

#endif // DATABASECONNECTION_H
