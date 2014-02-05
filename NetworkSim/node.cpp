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

//added 2/3/14
int Node::process_packet(Packet packet){
    int destination_node = packet.get_destination_node()->get_id();

    if(destination_node != node_id)
    {
        if(routing_table.get_cost(destination_node) != -1)
            return routing_table.get_cost(destination_node) + routing_table.get_next_hop(destination_node)->process_packet(packet);
        else
            update_packets.push_back(packet);
    }
    else
    {   //I'm assuming we're going to add data packets??
        if(packet.get_packet_type() == Packet::data)
            return 0;
        else
        {
            if(process_packet(packet))
                send_update_packets(packet.get_time());
            return 0;
        }
    }
}//end of process_packet


