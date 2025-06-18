#include "database.h"

Database::Database()
{

}

Database::Database(QString database, QString dbName, QString table, QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase(database);
    db.setDatabaseName(dbName);

    // Open the database
    if (!db.open()) {
        qDebug() << "Error: Failed to connect to database.";
        return;
    } else {
        qDebug() << "Database connection successful!";
    }

    this->table = table;
}

Database::~Database()
{
    qInfo() << "Closing database...";
    db.close();
}

QList<QStringList> Database::selectAll()
{
    QList<QStringList> records_list;
    QString cmd = "SELECT * FROM `"+table+"`";
    QSqlQuery query(cmd);

    qDebug() << query.executedQuery();
    bool ok = query.exec();

    if(!ok){
        qDebug() << "Query " + query.executedQuery() + "not executed";
    }

    while(query.next())
    {
        row = query.record();
        QStringList record;
        for(int i = 0; i < row.count(); i++){
            // qInfo() << row.value(i).toString();
            record.append(row.value(i).toString());
        }
        // qInfo() << "\n\n";
        records_list.append(record);
    }

    return records_list;
}

bool Database::dropRecord(QString column, QString value)
{
    QSqlQuery query;
    QString cmd = "DELETE FROM `"+table+"` WHERE "+column+" = :value";
    query.prepare(cmd);
    query.bindValue(":value", value);


    bool ok = query.exec();

    qDebug() <<  query.executedQuery();
    if(!ok){
        qDebug() << "Query " + query.executedQuery() + " not executed";
        return false;
    }

    return true;

}

bool Database::addRecord(QStringList values)
{
    QSqlQuery query("SELECT * FROM `"+table+"` LIMIT 1");
    QString insert("INSERT INTO `"+table+"` (");
    QStringList columns;


    if(query.exec()){
        int numColumns = query.record().count();

        for(int column = 0; column < numColumns; column++){
            columns.append(query.record().fieldName(column));
            if(column != numColumns-1)
                insert.append(query.record().fieldName(column)+",");
            else
                insert.append(query.record().fieldName(column)+") VALUES (");
        }

        for(int column = 0; column < numColumns; column++){
            if(column != numColumns-1)
                insert.append(":"+columns.at(column)+",");
            else
                insert.append(":"+columns.at(column)+");");
        }

        query.prepare(insert);
        for(int column = 0; column < numColumns; column++){
            query.bindValue(":"+columns.at(column), values.at(column));
        }

        // qInfo() << query.executedQuery();

    }else{
        qDebug() << query.lastError().text();
        return false;
    }

    if(!query.exec()){
        qDebug() << query.lastError().text();
        return false;
    }

    return true;
}
























