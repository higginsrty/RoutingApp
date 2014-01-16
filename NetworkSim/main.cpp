#include "stdafx.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QtQuick2ApplicationViewer viewer;
    viewer.setMainQmlFile(QStringLiteral("qml/NetworkSim/main.qml"));

    viewer.showExpanded();
    return app.exec();
}
