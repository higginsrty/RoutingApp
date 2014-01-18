#include "stdafx.h"

QObject* addNode(QString name, int x, int y, QQmlEngine *engine, QObject *main_panel);
QObject* addLink(QString name, QObject *node1, QObject *node2, QQmlEngine *engine, QObject *main_panel);

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QtQuick2ApplicationViewer viewer;
    QObject *main_panel;
    viewer.setMainQmlFile(QStringLiteral("qml/NetworkSim/main.qml"));
    QObject *root = viewer.rootObject();
    main_panel = root->findChild<QObject*>("MainPanel");
    QQmlEngine *engine = viewer.engine();
    QObject *node1 = addNode("node1", 100,100, engine, main_panel);
    QObject *node2 = addNode("node2", 200,200, engine, main_panel);
    QObject *link1 = addLink("link1",node1, node2, engine, main_panel);
    viewer.showExpanded();
    return app.exec();
}

QObject* addNode(QString name, int x, int y, QQmlEngine *engine, QObject *main_panel) {
    QQmlComponent component(engine, "qml/NetworkSim/Nodes.qml");
    QObject *object = component.create();
    QQuickItem *item = qobject_cast<QQuickItem*>(object);
    item->setParentItem(qobject_cast<QQuickItem*>(main_panel));
    item->setProperty("x", x);
    item->setProperty("y", y);
    item->setObjectName(name);
    return object;
}

QObject* addLink(QString name, QObject *node1, QObject *node2, QQmlEngine *engine, QObject *main_panel) {
    QQmlComponent component(engine, "qml/NetworkSim/Link2.qml");
    QObject *object = component.create();
    QQuickItem *item = qobject_cast<QQuickItem*>(object);
    item->setParentItem(qobject_cast<QQuickItem*>(main_panel));
    QQuickItem *node = qobject_cast<QQuickItem*>(node1);
    int x1 = node->x() + node->width()/2;
    int y1 = node->y() + node->height()/2;
    node = qobject_cast<QQuickItem*>(node2);
    int x2 = node->x() + node->width()/2;
    int y2 = node->y() + node->height()/2;
    item->setProperty("x1", x1);
    item->setProperty("y1", y1);
    item->setProperty("x2", x2);
    item->setProperty("y2", y2);
    item->setObjectName(name);
    return object;

}
