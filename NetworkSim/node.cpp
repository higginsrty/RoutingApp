#include "stdafx.h"

Node::Node(QQuickItem *parent) :
    QQuickItem(parent)
{
}

void Node::setup_node(QString name, int x, int y, QObject *main_panel, QQmlEngine *engine) {
    // Load Node QML file
    QQmlComponent component(engine, "qml/NetworkSim/Nodes.qml");
    // Create QObject
    QObject *object = component.create();
    // Cast it as a QQuickItem
    QQuickItem *item = qobject_cast<QQuickItem*>(object);
    // Set the parent as the main_panel (this changes when added to a link)
    item->setParentItem(qobject_cast<QQuickItem*>(main_panel));
    item->setProperty("x", x);
    item->setProperty("y", y);
    item->setObjectName(name);
    QObject::connect(object,SIGNAL(position_changed_sig(qreal,qreal)),this,SLOT(position_changed(qreal,qreal)));
    this->node = object;
}

bool Node::is_source() {
    return source;
}

void Node::set_source(bool new_source) {
    source = new_source;
}

QObject* Node::get_q_object() {
    return node;
}

void Node::addLink(QString name, Node* node2, QObject *main_panel, QQmlEngine *engine) {
    Link *link1 = new Link(qobject_cast<QQuickItem*>(main_panel));
    link1->addLink(name, this,node2,main_panel,engine);
    links.push_back(link1);
    node2->links.push_back(link1);
}

void Node::position_changed(qreal x, qreal y) {
    for (std::vector<Link*>::iterator iter = links.begin(); iter != links.end(); iter++)
    {
        Link *temp = *iter;
        QQuickItem *tmp = qobject_cast<QQuickItem*>(temp->get_q_object());
        QQuickItem *node1 = qobject_cast<QQuickItem*>(node);
        int y_off = node1->height();
        int x_off = node1->width();
        if (temp->get_source() == this) {
            tmp->setProperty("x1", x + x_off/2);
            tmp->setProperty("y1", y + y_off/2);
        } else {
            tmp->setProperty("x2", x + x_off/2);
            tmp->setProperty("y2", y + y_off/2);
        }
    }
}
