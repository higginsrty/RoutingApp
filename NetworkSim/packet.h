#ifndef PACKET_H
#define PACKET_H

#include "stdafx.h"

 class Packet : public QQuickItem
 {

     Q_OBJECT
 public:
    //packet type-> hello or acknowledgement.. should we add "Data Packet Type"?
    Packet(QQuickItem *parent = 0);

    PacketType get_packet_type();
    void set_packet_type(PacketType type);

    Node* get_source_node();
    void set_source_node(Node* node);

    Node* get_destination_node();
    void set_destination_node(Node* node);

    int get_flood_flag();
    void set_flood_flag(int flag);

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
    PacketType type;
    Node* source_node;
    Node* destination_node;
    double time;
    int flood_flag;
    int x,y;
    //std::vector<Dv dvr_table;

 };
 
 #endif // PACKET_H
