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

void Node::send_pack(QString name)
{
    std::vector<Packet*>::iterator iter;
    for (iter = packets.begin(); iter != packets.end(); iter++)
    {
        Packet *pack = *iter;
        if (pack->get_ttl() == 0)
            continue;
        if (pack->get_name().compare(name) == 0) {
            emit sent_pack(pack, pack->get_destination_node()->get_id());
            packets.erase(iter);
            break;
        }
    }

}

void Node::switch_source_dest(Packet *pack)
{
    Node *n1 = pack->get_source_node();
    Node *n2 = pack->get_destination_node();
    pack->set_source_node(n2);
    pack->set_destination_node(n1);
}

void Node::process_packet(Packet *pack, int node_dest_id)
{
    if (this->node_id != node_dest_id)
        return;
    std::vector<Link*>::iterator iter;
    int ttl = pack->get_ttl();
    switch (this->alg_flag) {
    case 0:
        if (ttl == 0) {
            delete pack;
            return;
        }
        for (iter = connections.begin(); iter != connections.end();iter++)
        {
            Link *lnk = *iter;
            Packet *p = new Packet();
            p->create_packet("packets",panel,engine);
            p->set_source_node(this);
            Node* temp = lnk->get_source();
            if(temp->get_id() == this->get_id()){
                p->set_destination_node(lnk->get_node2());
            }
            else
                 p->set_destination_node(temp);
            // Don't send packets to your source node!
            if (pack->get_source_node()->get_id() == p->get_destination_node()->get_id()) {
                delete p;
                delete pack;
                continue;
            }
            p->set_time(lnk->get_weight());
            p->set_ttl(ttl-1);
            packets.push_back(p);
            qDebug() << p->get_ttl();
            p->animate();
        }
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    default:
        break;
    }

}

void Node::add_link(Link *lnk)
{
    connections.push_back(lnk);
}

void Node::set_alg(int alg)
{
    this->alg_flag = alg;
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
    source = false;
    panel = main_panel;
    this->engine = engine;
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
    std::vector<Packet*>::iterator iter;
    for (iter = packets.begin(); iter != packets.end(); iter++)
    {
        Packet *p = *iter;
        if (int pack_x = p->get_q_object()->property("x") == x)
            p->get_q_object()->setProperty("x",x);
    }
    this->x = x;
}

void Node::set_y(int y)
{
    std::vector<Packet*>::iterator iter;
    for (iter = packets.begin(); iter != packets.end(); iter++)
    {
        Packet *p = *iter;
        if (p->get_q_object()->property("y") == y)
            p->get_q_object()->setProperty("y",y);
    }
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
