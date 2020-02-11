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

    if(db.tables().size() != 0)
        return QSqlError();
    if (!q.exec(QLatin1String("create table trivial(id integer primary key, "
                              "question text, answer text, cardnumber integer, "
                              "edition integer, type integer)")))
        return q.lastError();
    return QSqlError();
}

QSqlError DataBase::addCard(const QString text, int cardnumber, int edition, int type)
{
    QSqlQuery q;

    if (q.exec("select * from trivial where"))


    if (!q.prepare(QLatin1String("insert into trivial(data, cardnumber, edition"
                                 ", type) values(?,?,?,?)")))
        return q.lastError();
    q.addBindValue(text);
    q.addBindValue(cardnumber);
    q.addBindValue(edition);
    q.addBindValue(type);
    q.exec();
    return QSqlError();
}
