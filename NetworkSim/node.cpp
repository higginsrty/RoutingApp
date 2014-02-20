#include "stdafx.h"

Node::Node(QQuickItem *parent) :
    QQuickItem(parent)
{

}

void Node::set_id(int id)
{
    node_id = id;
}
/*
int Node::process_packet(Packet *packet){
    int flood_flag = packet->get_flood_flag();
    if (flood_flag == 1)
        // do something (flooding wise)
        return 0;
    int destination_node = packet->get_destination_node()->get_id();

    if(destination_node != this->get_id())
    {
        if(routing_table->get_cost(destination_node) != -1)
            return routing_table->get_cost(destination_node) + routing_table->get_next_hop(destination_node)->process_packet(packet);
        else
            update_packets.push_back(packet);
    }
    else
    {   //I'm assuming we're going to add data packets??
        if(packet->get_packet_type() == DATA)
            return 0;
        else
        {
            if(process_packet(packet))
                send_update_packets(packet->get_time());
            return 0;
        }
    }
}//end of process_packet

*/

void Node::process_packet()
{
    int number_of_links;
    link connected_link;
    std::stack<packet> packet_copies;

    //get the number of links connected
    number_of_links = links_stack.size()

    //create that number copy of packets
      for ( int x = 0; x < number_of_links-1; x++ ) {
        packet_copies.push(packet.get_packet_type());
      }

    //forward each packet to links
      for (int x = 0; x < number_of_links; x++){
          connected_link = links_stack.pop();
          //forward packet down that link
          //if link = recent link, don't forward

      }
    qDebug() << "Process Packets";
}

QString Node::get_name()
{
    return name;
}

void Node::setup_node(QString name, int x, int y, QObject *main_panel, QQmlApplicationEngine *engine) {
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
    this->x = x;
    this->y = y;
    this->node = object;
    this->name = name;
    rt = new FloodingRT();
    routing_table = new RoutingTable();
}


bool Node::is_source()
{
    return source;
}

void Node::set_source(bool new_source)
{
    source = new_source;
}

QObject* Node::get_q_object()
{
    return node;
}

int Node::get_id()
{
    return node_id;
}

int Node::get_x()
{
    return x;
}

int Node::get_y()
{
    return y;
}

void Node::set_x(int x)
{
    this->x = x;
}

void Node::set_y(int y)
{
    this->y = y;
}

void Node::show_routing_table(QQmlApplicationEngine *engine, QQuickItem *panel)
{
    rt->view_full_table(engine,panel);
}

void Node::send_update_packets(double weight)
{
    return;
}
