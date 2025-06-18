#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QTest>

class Database: public QObject
{
    Q_OBJECT

public:
    Database(QString database, QString dbName, QString table, QObject *parent = nullptr);
    Database();
    ~Database();
    QList<QStringList> selectAll();
    bool dropRecord(QString column, QString value);
    bool addRecord(QStringList values);

private:
    QSqlDatabase db;
    QSqlRecord row;
    QString table;
};

#endif // DATABASE_H
