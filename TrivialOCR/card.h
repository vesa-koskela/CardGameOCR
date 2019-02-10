#ifndef CARD_H
#define CARD_H

#include "question.h"

class Card : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Question blue READ blue NOTIFY blueChanged)
    Q_PROPERTY(Question pink READ pink NOTIFY pinkChanged)
    Q_PROPERTY(Question yellow READ yellow NOTIFY yellowChanged)
    Q_PROPERTY(Question purple READ purple NOTIFY purpleChanged)
    Q_PROPERTY(Question green READ green NOTIFY greenChanged)
    Q_PROPERTY(Question orange READ orange NOTIFY orangeChanged)
    Q_PROPERTY(int cardNumber READ cardNumber NOTIFY cardNumberChanged)
    Q_PROPERTY(int cardSet READ cardSet NOTIFY cardSetChanged)

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
    int cardSet_;
};

#endif // CARD_H
