#include "stdafx.h"


Packet::Packet(QQuickItem *parent) :
    QQuickItem(parent)
{
}

int Packet::get_flood_flag()
{
    return this->flood_flag;
}

void Packet::set_flood_flag(int flag)
{
    this->flood_flag = flag;
}

PacketType Packet::get_packet_type()
{   //get packet type
    //can be hello packet or acknowledgement packet
    return type;
}

void Packet::set_packet_type(PacketType type)
{   //assigns hello or acknowledgement type to packet
    this->type = type;
}

void Packet::set_source_node(Node* node)
{   //assign the source node
    source_node = node;
}

void Packet::set_destination_node(Node* node)
{  //assign the destination node
    destination_node = node;
}

double Packet::get_time()
{   //might need adjusted
    return time;
}

void Packet::set_time(double t)
{
    time = t;
}

Node* Packet::get_source_node()
{
    return source_node;
}

Node* Packet::get_destination_node()
{
    return destination_node;
}

std::pair<int,int> location(Node* node){
    std::pair<int,int> loc;
    loc.first = node->get_x();
    loc.second = node->get_y();
    return loc;
}

void Packet::create_packet(QString name, Node* source, Node* dest, QObject *main_panel, QQmlApplicationEngine *engine) {
    // Load Node QML file
    QQmlComponent component(engine, QUrl("qrc:/qml_files/packet.qml"));
    // Create QObject
    QObject *object = component.create();
    // Cast it as a QQuickItem
    QQuickItem *item = qobject_cast<QQuickItem*>(object);
    // Set the parent as the main_panel (this changes when added to a link)
    item->setParentItem(qobject_cast<QQuickItem*>(main_panel));
    std::pair<int,int> loc = location(source);
    std::pair<int,int> dest_loc = location(dest);
    item->setProperty("x", loc.first+25);
    item->setProperty("y", loc.second+25);
    //item->setProperty("state", get_packet_type);
    item->setProperty("dest_x", dest_loc.first+25);
    item->setProperty("dest_y", dest_loc.second+25);
    item->setProperty("name", name);
}

/***The following will need to be adjusted after DVR table is created***
 *
void Packet::set_dvr_table(vector<Dv> dv_table)
{
dvr_Table = dv_table;
}

void Packet::add_dvr_entry(Node* destination_node, int cost)
{
dvr_table.push_back(Dv(destination_node,cost));
}

int Packet::get_dvr_table_size()
{
return dvr_table.size();
}

Node* Packet::get_dvr_table_destination(int index)
{
return dvr_table[index].destination_node;
}

int Packet::get_dvr_table_cost(int index)
{
return dvr_table[index].cost;
}
*************************************************************************/

