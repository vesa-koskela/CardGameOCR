#include "database.h"
#include <QtSql>
#include <QDebug>

DataBase::DataBase()
{
}

QSqlError DataBase::initDb()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("test2.db");
    if(!db.open())
        return db.lastError();
    QSqlQuery q;

    if (!q.exec(QLatin1String("create table trivial(id integer primary key, "
                              "data text, cardnumber integer, "
                              "edition integer, type integer, used boolean)")))
        return q.lastError();

    return QSqlError();
}

QSqlError DataBase::addCard(const QString text, int cardnumber, int edition, int type)
{
    QSqlQuery q;
    if (!q.prepare(QLatin1String("insert into trivial(data, cardnumber, edition"
                                 ", type, used) values(?,?,?,?,?)")))
        return q.lastError();
    q.addBindValue(text);
    q.addBindValue(cardnumber);
    q.addBindValue(edition);
    q.addBindValue(type);
    q.addBindValue(false);
    q.exec();
    return QSqlError();
}
