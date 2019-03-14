#include "card.h"
#include <QDebug>

Card::Card()
{

}

void Card::insertOCRresult(QList<QString> data)
{
    QList<QString> test;

    textLines.clear();
    int QMarkCount = 0;


    QString str;
    for (QString i: data) {
        //i = i.trimmed();
        str.append(i);
        str = str.trimmed();
        str.append(" ");

        if (i.endsWith("\n\n")) {
            str = str.trimmed();
            if (str.length() > 0) {
                test.append(str);
            }

            str.clear();
        }


        if (i.contains("?")) {
            QMarkCount++;
            textLines.append(str);
            str.clear();
        }

    }
    textLines.append(str);
    if (QMarkCount > 0) {
        isSideA = false;
    }
    else {
        isSideA = true;
    }
    mBlue = textLines.at(0);
    mPink = textLines.at(1);
    mYellow = textLines.at(2);
    mPurple = textLines.at(3);
    mGreen = textLines.at(4);
    mOrange = textLines.at(5);
    cardNumber = textLines.at(6);

    blueChanged();
    pinkChanged();
    yellowChanged();
    purpleChanged();
    greenChanged();
    orangeChanged();
    cardNumberChanged();
    sideChanged();

    qDebug() << textLines;
    qDebug() << data;
    qDebug() << test;
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

QString Card::getCardNumber()
{
    return cardNumber;
}

void Card::setCardNumber(QString number)
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
