#include"database.h"
#include <QDir>
#include <QVariant>


bool DatabaseManager::openDB()
    {
    // Find QSLite driver
    db = QSqlDatabase::addDatabase("QSQLITE");//driver sqlite

    #ifdef Q_OS_LINUX
    // NOTE: We have to store database file into user home folder in Linux
    QString path(QDir::home().path());
    path.append(QDir::separator()).append("my.db.sqlite");
    path = QDir::toNativeSeparators(path);
    db.setDatabaseName(path);
    #else
    // NOTE: File exists in the application private folder, in Symbian Qt implementation
    db.setDatabaseName("my.db.sqlite");
    #endif

    // Open databasee
    return db.open();
    }

bool DatabaseManager::createPersonTable()
    {
    // Create table "person"
    bool ret = false;
    if (db.isOpen())
        {
        QSqlQuery query;
        ret = query.exec("create table person "
                  "(id integer primary key, "
                  "firstname varchar(20), "
                  "lastname varchar(30), "
                  "age integer)");

        }
    return ret;
    }

int DatabaseManager::insertPerson(QString firstname, QString lastname, int age)
    {
    int newId = -1;
    bool ret = false;

    if (db.isOpen())
        {
        //http://www.sqlite.org/autoinc.html
        // NULL = is the keyword for the autoincrement to generate next value

        QSqlQuery query;
        ret = query.exec(QString("insert into person values(NULL,'%1','%2',%3)")
        .arg(firstname).arg(lastname).arg(age));

        // Get database given autoincrement value
        if (ret)
            {
            // http://www.sqlite.org/c3ref/last_insert_rowid.html
            newId = query.lastInsertId().toInt();
            }

        }
    return newId;
    }


QSqlError DatabaseManager::lastError()
    {
    // If opening database has failed user can ask
    // error description by QSqlError::text()
    return db.lastError();
    }

bool DatabaseManager::deleteDB()
    {
    // Close database
    db.close();

    #ifdef Q_OS_LINUX
    // NOTE: We have to store database file into user home folder in Linux
    QString path(QDir::home().path());
    path.append(QDir::separator()).append("my.db.sqlite");
    path = QDir::toNativeSeparators(path);
    return QFile::remove(path);
    #else

    // Remove created database binary file
    return QFile::remove("my.db.sqlite");
    #endif
    }
