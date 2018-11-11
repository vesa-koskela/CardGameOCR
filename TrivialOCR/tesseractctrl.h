#ifndef TESSERACTCTRL_H
#define TESSERACTCTRL_H

#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <QObject>

class TesseractCtrl: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString text READ get_text NOTIFY textChanged)
public:
    TesseractCtrl();
    QString get_text();
    Q_INVOKABLE void tessImage();


private:
    QString text_;
    //tesseract::TessBaseAPI *api_;

signals:
    void textChanged();
};

#endif // TESSERACTCTRL_H
