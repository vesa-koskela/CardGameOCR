#include "tesseractctrl.h"
#include <QDebug>

TesseractCtrl::TesseractCtrl()
{
    QString str = "initial text";
    text_ = str;

}

QString TesseractCtrl::get_text()
{
    qDebug() << "get text";
    return text_;
}

void TesseractCtrl::readImage()
{
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
    Pix *image = pixRead("/home/koskela/Downloads/IMG_0001.jpg");
    api->SetImage(image);
    api->SetSourceResolution(1000);

    // Get OCR result
    outText = api->GetUTF8Text();
    qDebug() << "OCR output:" << outText;
    QString str = outText;
    text_ = str;
    emit textChanged();
    // Destroy used object and release memory
    api->End();
    delete [] outText;
    pixDestroy(&image);

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
