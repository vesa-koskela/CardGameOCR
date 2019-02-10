#ifndef TESSERACTCTRL_H
#define TESSERACTCTRL_H

#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <QObject>
#include "card.h"

class TesseractCtrl: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString text READ get_text NOTIFY textChanged)
    Q_PROPERTY(Card card READ getCard NOTIFY cardChanged)
public:
    TesseractCtrl();
    QString get_text();
    Q_INVOKABLE void readImage();
    //Q_INVOKABLE void imgChanged(QUrl url);


private:
    QString text_;
    //tesseract::TessBaseAPI *api_;

signals:
    void textChanged();
};

#endif // TESSERACTCTRL_H
