#ifndef CARD_H
#define CARD_H

#include "question.h"

class Card : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString blue MEMBER m_blue NOTIFY blueChanged)
    Q_PROPERTY(QString pink MEMBER m_pink NOTIFY pinkChanged)
    Q_PROPERTY(QString yellow MEMBER m_yellow NOTIFY yellowChanged)
    Q_PROPERTY(QString purple MEMBER m_purple NOTIFY purpleChanged)
    Q_PROPERTY(QString green MEMBER m_green NOTIFY greenChanged)
    Q_PROPERTY(QString orange MEMBER m_orange NOTIFY orangeChanged)
    Q_PROPERTY(QString )
    Q_PROPERTY(int cardNumber READ cardNumber NOTIFY cardNumberChanged)
    Q_PROPERTY(int cardSet READ cardSet NOTIFY cardSetChanged)

public:
    Card();

private:
    QString m_blueQ;
    QString m_blueA;
    QString m_pinkQ;
    QString m_pinkA;
    QString m_yellowQ;
    QString m_yellowA;
    QString m_purpleQ;
    QString m_purpleA;
    QString m_greenQ;
    QString m_greenA;
    QString m_orangeQ;
    QString m_orangeA;
    int cardNumber;
    int cardSet_;

signals:
    void blueQChanged();
    void blueAChanged();
    void pinkQChanged();
    void pinkAChanged();
    void yellowQChanged();
    void yellowAChanged();
    void purpleQChanged();
    void purpleAChanged();
    void greenQChanged();
    void greenAChanged();
    void orangeQChanged();
    void orangeAChanged();

};

#endif // CARD_H
