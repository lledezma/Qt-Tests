#include "databasetest.h"

DatabaseTest::DatabaseTest()
{
    QString database = "";
    QString dbName = "";
    QString table = "";
    db = new Database(database, dbName, table, this);
    records = db->selectAll();

    qInfo() << "\n\n Testing a User table with id, companyId, email, and department fields";
}

void DatabaseTest::testExpectedRecords()
{
    qInfo() << "Testing expected number of records....";

    if(records.size() == 3)
        qInfo() << "User table contains expected number of records: 3!";
    else
        QFAIL("Expected 3 records but got " + records.size());
}

void DatabaseTest::testAddUniqueRecord_data()
{
    qInfo() << "\n\n Generating User test data";

    QTest::addColumn<QString>("id");
    QTest::addColumn<QString>("companyId");
    QTest::addColumn<QString>("email");
    QTest::addColumn<QString>("department");

    QTest::addRow("Fake record") << "A100" << "90" << "900@fakeemail.com" << "department1";
    QTest::addRow("Real record") << "A200" << "200" << "200@fakeemail.com" << "department2";
    QTest::addRow("Real record") << "A300" << "300" << "300@fakeemail.com" << "department3";

    qInfo() << "User test data generated!";

}

void DatabaseTest::testAddUniqueRecord()
{
    qInfo() << "\n\n Testing unique record insertion....";

    QFETCH(QString, id);
    QFETCH(QString, companyId);
    QFETCH(QString, email);
    QFETCH(QString, department);

    qInfo() << "Testing record " + id + " | " + companyId + " | " + email + " | " + department;

    bool ok = db->addRecord(QStringList({id,companyId,email,department}));
    qDebug() << ok;
    if(ok){
        QFAIL("Unique id constrain failed! Record added.");
        db->dropRecord("id",id);
    }
    else
        qInfo() << "Unique id constrain worked! Record not added.";

}











