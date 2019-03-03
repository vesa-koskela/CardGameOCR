#ifndef CARD_H
#define CARD_H

#include <QObject>

class Card : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString blue MEMBER blue NOTIFY blueChanged)
    Q_PROPERTY(QString pink MEMBER pink NOTIFY pinkChanged)
    Q_PROPERTY(QString yellow MEMBER yellow NOTIFY yellowChanged)
    Q_PROPERTY(QString purple MEMBER purple NOTIFY purpleChanged)
    Q_PROPERTY(QString green MEMBER green NOTIFY greenChanged)
    Q_PROPERTY(QString orange MEMBER orange NOTIFY orangeChanged)
    Q_PROPERTY(bool cardSide READ isQSide WRITE changeSideType)
    Q_PROPERTY(int cardNumber READ cardNumber WRITE setCardNumber
               NOTIFY cardNumberChanged)
    Q_PROPERTY(int cardSet READ cardSet WRITE setCardSet NOTIFY cardSetChanged)

public:
    Card();

private:
    QString blue;
    QString pink;
    QString yellow;
    QString purple;
    QString green;
    QString orange;
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
