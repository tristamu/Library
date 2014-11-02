#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QFile>
#include <QSqlQuery>

class DatabaseManager : public QObject
    {
    public:
        DatabaseManager(QObject *parent = 0);
        ~DatabaseManager();

    public:
        bool openDB();
        bool createPersonTable();
        int insertPerson(QString , QString , int );
        bool deleteDB();
        QSqlError lastError();

    private:
        QSqlDatabase db;
    };

#endif // DATABASE_H
