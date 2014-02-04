#include "stdafx.h"


Packet::Packet(QQuickItem *parent) :
    QQuickItem(parent)
{
}

Packet::packet_type Packet::get_packet_type()
{   //get packet type
    //can be hello packet or acknowledgement packet
    return packet_type;
}

void Packet::set_packet_type(packet_type type)
{   //assigns hello or acknowledgement type to packet
    packet_type = type;
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

