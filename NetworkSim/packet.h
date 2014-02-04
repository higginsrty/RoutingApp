#ifndef PACKET_H
#define PACKET_H

#include "stdafx.h"

class packet
{
public:
    //packet type-> hello or acknowledgement.. should we add "Data Packet Type"?
    enum packet_type{hello, acknowledgement};

    packet();

    packet_type get_packet_type();
    void set_packet_type(packet_type type);

    Node* get_source_node();
    void set_source_node(Node* node);

    Node* get_destination_node();
    void set_destination_node(Node* node);

    double get_time();
    void set_time(double t);

    /*
     void set_dvr_table(std::vector<Dv> dvr_table);
     void add_dvr_entry(Node* destination_node, int cost);

     int get_dvr_table_size();
     Node* get_dvr_table_destination(int index);
     int get_dvr_table_cost(int index);
    */

private:
    packet_type type;
    Node* source_node;
    Node* destination_node;
    double time;

    //std::vector<Dv dvr_table;

};

#endif // PACKET_H
