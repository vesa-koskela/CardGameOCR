#include "card.h"
#include <QDebug>

Card::Card()
{

}

void Card::insertOCRresult(QList<QString> data)
{
    textLines.clear();
    int QMarkCount = 0;
    for (QString i: data) {
        if (i.contains("?")) {
            QMarkCount++;
        }
    }
    if (QMarkCount > 0) {
        isSideA = false;
    }
    else {
        isSideA = true;
    }

    QString str;
    for (QString i: data) {
        str.append(i);
        str = str.trimmed();
        if (i.contains("?")) {
            textLines.append(str);
            str.clear();
        }
    }
    mBlue = textLines.at(0);
    blueChanged();

    qDebug() << textLines;
}

bool Card::isSideQ()
{
    if(isSideA == true) {
        return false;
    }
    else {
        return true;
    }
}

void Card::changeSide(bool val)
{
    isSideA = val;
}

int Card::getCardNumber()
{
    return cardNumber;
}

void Card::setCardNumber(int number)
{
    cardNumber = number;
}

int Card::getCardSet()
{
    return cardSet;
}

void Card::setCardSet(int number)
{
    cardSet = number;
}
