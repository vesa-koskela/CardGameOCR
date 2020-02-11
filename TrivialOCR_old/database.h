#ifndef DATABASE_H
#define DATABASE_H
#include <QtSql>

class DataBase
{
public:
    DataBase();
    QSqlError initDb();
    QSqlError addCard(const QString text, int cardnumber, int edition, int type);
};

#endif // DATABASE_H
