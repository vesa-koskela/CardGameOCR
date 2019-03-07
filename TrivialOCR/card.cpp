#include "card.h"

Card::Card(QList<QString> data, bool side, int number, int cardSet)
{

}

bool Card::isSideQ()
{
    if(side == true) {
        return true;
    }
    else {
        return false;
    }
}

void Card::changeSide(bool val)
{
    side = val;
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
