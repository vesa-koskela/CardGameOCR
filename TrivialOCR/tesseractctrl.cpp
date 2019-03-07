#include "tesseractctrl.h"
#include <QDebug>

TesseractCtrl::TesseractCtrl(Card *card)
{
    QString str = "initial text";
    text_ = str;
    mCard = card;

}

QString TesseractCtrl::get_text()
{
    qDebug() << "get text";
    return text_;
}

void TesseractCtrl::readImage()
{
    lines_.clear();
    tesseract::TessBaseAPI* api = new tesseract::TessBaseAPI();
    //tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    // Initialize tesseract-ocr with English, without specifying tessdata path
    if (api->Init(NULL, "fin")) {
        fprintf(stderr, "Could not initialize tesseract.\n");
        exit(1);
    }
    char *outText;
    // Open input image with leptonica library
    //Pix *image = pixRead("/home/vesa/Projects/trivialocr/TrivialOCR/Images/IMG_0001.tif");
    Pix *image = pixRead("/home/veko/Downloads/IMG_0001.jpg");
    api->SetPageSegMode(tesseract::PSM_SINGLE_COLUMN);
    api->SetImage(image);
    api->SetSourceResolution(1000);



    //Iterator
    api->Recognize(0);
    tesseract::ResultIterator* ri = api->GetIterator();
    tesseract::PageIteratorLevel level = tesseract::RIL_TEXTLINE;
    if (ri != 0) {
      do {
        const char* word = ri->GetUTF8Text(level);
        float conf = ri->Confidence(level);
        int x1, y1, x2, y2;
        ri->BoundingBox(level, &x1, &y1, &x2, &y2);
        printf("word: '%s';  \tconf: %.2f; BoundingBox: %d,%d,%d,%d;\n",
                 word, conf, x1, y1, x2, y2);


        QString str = word;
        lines_.append(str);
        delete[] word;
      } while (ri->Next(level));
    }

    for(QString i: lines_) {
        qDebug() << i.contains("?");
    }
    qDebug() << lines_;
    qDebug() << lines_.length();
    mCard->insertOCRresult(lines_);

    /*
    //Basic
    api->SetSourceResolution(1000);
    outText = api->GetUTF8Text();
    qDebug() << "OCR output:" << outText;
    QString str = outText;
    text_ = str;
    emit textChanged();
    */


    // Destroy used object and release memory
    api->End();
    delete [] outText;
    pixDestroy(&image);

}

Card *TesseractCtrl::getCard()
{
    return mCard;
}



/*QString TesseractCtrl::read_image() {
    tesseract::TessBaseAPI* api = new tesseract::TessBaseAPI();
    //tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    // Initialize tesseract-ocr with English, without specifying tessdata path
    if (api->Init(NULL, "eng")) {
        fprintf(stderr, "Could not initialize tesseract.\n");
        exit(1);
    }
    char *outText;
    // Open input image with leptonica library
    Pix *image = pixRead("/home/vesa/Projects/trivialocr/TrivialOCR/Images/phototest.tif");
    api->SetImage(image);
    // Get OCR result
    outText = api->GetUTF8Text();
    qDebug() << "OCR output:" << outText;

    // Destroy used object and release memory
    api->End();
    delete [] outText;
    pixDestroy(&image);
    QString str = outText;
    return str;
}*/
