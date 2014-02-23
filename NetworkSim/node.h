#ifndef NODE_H
#define NODE_H

#include "stdafx.h"

class FloodingRT;
class Link;
class Packet;

struct Neighbor{
    int neighbor_ID;
    double link_delay;
    Neighbor(){neighbor_ID = 0; link_delay = 0;}
    Neighbor(int ID, double delay){neighbor_ID = ID; link_delay = delay;}
};

class Node : public QQuickItem
{
    Q_OBJECT

    int packet_reached_destination = 0; //change to 1 if it has

public:
    int x,y;
    explicit Node(QQuickItem *parent = 0);
    int get_id();
    bool is_source();
    int get_x();
    int get_y();
    QString get_name();
    void set_source(bool new_source);
    void setup_node(QString name, int x, int y, QObject* main_panel, QQmlApplicationEngine *engine);
    //void addLink(QString name, int weight, Node* node2, QObject* main_panel, QQmlEngine* engine);
    QObject* get_q_object();
    void set_id(int id);
    void show_routing_table(QQmlApplicationEngine *engine, QQuickItem *panel);

    void set_x(int x);
    void set_y(int y);

    //added 2/4/14
    std::vector<int> get_neighbor_vector();

    void add_route(Node* destination_node, Node* next_hop, int weight);
    void remove_link(int linked_node_id, double weight);
    int get_link_cost(int linked_nod_id);
    /*
    std::vector<dv> get_dvr_table(int destination_node);

    std::vector<Packet> get_update_packets();
    */

    std::vector<Packet*> packets; // All of the packets created by this node

    void set_alg(int alg);
    void add_link(Link *lnk);

private:
    QObject *panel;
    QQmlApplicationEngine *engine;
    int node_id;
    QString name;
    bool source;
    QObject* node;
    FloodingRT *rt;
    RoutingTable *routing_table;
    std::vector<Packet*> update_packets;
    bool process_dv_packet(Packet *packet);
    void send_update_packets(double weight);
    int alg_flag; // 0 = Flooding; 1 = DVRP; 2 = LSR; 3 = CBT
    void switch_source_dest(Packet *pack);
    std::vector<Link*> connections;



signals:
    void sent_pack(Packet *pack, int node_dest_id);

public slots:
    void send_pack(QString name);
    void process_packet(Packet *pack, int node_dest_id);
};

#endif // NODE_H
