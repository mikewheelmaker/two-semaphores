#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "semaphoremanager.h"

int main(int argc, char* argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    SemaphoreManager semaphoreManager;

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("semaphoreManager", &semaphoreManager);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
