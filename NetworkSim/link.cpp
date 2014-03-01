#include "stdafx.h"

Link::Link(QQuickItem *parent) :
    QQuickItem(parent)
{
}


void Link::addLink(QString name, int weight, Node *node1, Node *node2, QObject *panel, QQmlApplicationEngine *engine) {
    // Loading the Link QML file
    QQmlComponent component(engine,QUrl("qrc:/qml_files/link.qml"));
    // Creating the QObject to work with
    QObject *object = component.create();
    this->node1 = node1;
    this->node2 = node2;
    // Need to cast QObjects to QQuickItems to work with them
    QQuickItem *item = qobject_cast<QQuickItem*>(object);
    QQuickItem *node = qobject_cast<QQuickItem*>(node1->get_q_object());
    // The linke will be a child of the main_panel
    item->setParentItem(qobject_cast<QQuickItem*>(panel));
    // Get the middle coordinates of the first node
    int x1 = node->x() + node->width()/2;
    int y1 = node->y() + node->height()/2;
    node = qobject_cast<QQuickItem*>(node2->get_q_object());
    int x2 = node->x() + node->width()/2;
    int y2 = node->y() + node->height()/2;
    item->setProperty("x1", x1);
    item->setProperty("y1", y1);
    item->setProperty("x2", x2);
    item->setProperty("y2", y2);
    item->setObjectName(name);
#ifdef Q_OS_ANDROID
    item->setProperty("link_height", 25);
#else
    item->setProperty("link_height", 10);
#endif
    this->weight = weight;
    this->link = object;
}

QObject* Link::get_q_object() {
    return link;
}

Node* Link::get_source() {
    return node1;
}

Node* Link::get_node2() {
    return node2;
}

void Link::update_weight(int w) {
    weight = w;
}

double Link::get_weight(){
    return weight;
}
