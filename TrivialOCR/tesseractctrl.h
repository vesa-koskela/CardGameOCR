#ifndef TESSERACTCTRL_H
#define TESSERACTCTRL_H

#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <QObject>

class TesseractCtrl: public QObject
{

public:
    TesseractCtrl();
    Q_INVOKABLE char read_image();

private:
    //tesseract::TessBaseAPI *api_;
};

#endif // TESSERACTCTRL_H
