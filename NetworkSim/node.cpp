#include "stdafx.h"

Node::Node(QQuickItem *parent) :
    QQuickItem(parent)
{

}

void Node::set_id(int id)
{
    node_id = id;
}

QString Node::get_name()
{
    return name;
}

void Node::setup_node(QString name, int x, int y, QObject *main_panel, QQmlEngine *engine) {
    // Load Node QML file
    QQmlComponent component(engine, QUrl("qrc:/qml_files/node.qml"));
    // Create QObject
    QObject *object = component.create();
    // Cast it as a QQuickItem
    QQuickItem *item = qobject_cast<QQuickItem*>(object);
    // Set the parent as the main_panel (this changes when added to a link)
    item->setParentItem(qobject_cast<QQuickItem*>(main_panel));
    item->setProperty("x", x);
    item->setProperty("y", y);
    item->setProperty("name", name);
    this->node = object;
    this->name = name;

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

int Node::get_id(){
    return node_id;
}
