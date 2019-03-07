#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "tesseractctrl.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    app.setOrganizationName("TrivialOCR");
    app.setOrganizationDomain("none");

    QQmlApplicationEngine engine;

    Card card;
    TesseractCtrl tess(&card);

    //tess.read_image;

    QQmlContext *ctxt = engine.rootContext();
    engine.rootContext()->setContextProperty("applicationDirPath", QGuiApplication::applicationDirPath());
    ctxt->setContextProperty("tesseractCtrl", &tess);
    ctxt->setContextProperty("cardTemplate", &card);

    //qmlRegisterType<TesseractCtrl>("io.qt.trivialocr.tesseractctrl",1,0,"TesseractCtrl");


    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
