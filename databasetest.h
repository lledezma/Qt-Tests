#ifndef DATABASETEST_H
#define DATABASETEST_H

#include <QObject>
#include <QTest>
#include "database.h"

class DatabaseTest: public QObject
{
    Q_OBJECT
public:
    DatabaseTest();
private:
    Database* db;
    QList<QStringList> records;

private slots:
    void testExpectedRecords();
    void testAddUniqueRecord_data();
    void testAddUniqueRecord();
    void testDeleteRecord_data();
    void testDeleteRecord();
};

#endif // DATABASETEST_H
