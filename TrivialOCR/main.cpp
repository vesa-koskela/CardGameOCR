#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "tesseractctrl.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    TesseractCtrl tess;
    //tess.read_image;

    qmlRegisterType<TesseractCtrl>("io.qt.trivialocr.tesseractctrl",1,0,"TesseractCtrl");


    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
