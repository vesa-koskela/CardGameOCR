#ifndef CARD_H
#define CARD_H

#include "question.h"

class Card
{
public:
    Card();

private:
    shared_ptr<Question> blueQ_;
    shared_ptr<Question> pinkQ_;
    shared_ptr<Question> yellowQ_;
    shared_ptr<Question> purpleQ_;
    shared_ptr<Question> greenQ_;
    shared_ptr<Question> orangeQ_;
    int cardNumber_;
};

#endif // CARD_H
