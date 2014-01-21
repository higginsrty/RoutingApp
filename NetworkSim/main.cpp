#include "stdafx.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QtQuick2ApplicationViewer viewer;
    QObject *main_panel;
    viewer.setMainQmlFile(QStringLiteral("qml/NetworkSim/main.qml"));
    QObject *root = viewer.rootObject();
    main_panel = root->findChild<QObject*>("MainPanel");
    QQmlEngine *engine = viewer.engine();
    Node *node1 = new Node(qobject_cast<QQuickItem*>(main_panel));
    node1->setup_node("node1", 100, 100, main_panel, engine);
    Node *node2 = new Node(qobject_cast<QQuickItem*>(main_panel));
    node2->setup_node("node2",200,200,main_panel,engine);
    Node *node3 = new Node(qobject_cast<QQuickItem*>(main_panel));
    node3->setup_node("node3",300,150,main_panel,engine);
    node1->addLink("link1", node2, main_panel,engine);
    node3->addLink("link2",node1,main_panel,engine);
    node2->addLink("link3", node3, main_panel,engine);
   // QObject *link1 = addLink("link1",node1, node2, engine, main_panel);
    viewer.showExpanded();
    return app.exec();
}
