#ifndef NODE_H
#define NODE_H

#include "stdafx.h"

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

public:
    explicit Node(QQuickItem *parent = 0);
    int get_id();
    bool is_source();
    QString get_name();
    void set_source(bool new_source);
    void setup_node(QString name, int x, int y, QObject* main_panel, QQmlEngine* engine);
    //void addLink(QString name, int weight, Node* node2, QObject* main_panel, QQmlEngine* engine);
    QObject* get_q_object();
    void set_id(int id);
    int node_weight = 0;

    //added 2/4/14
    std::vector<int> get_neighbor_vector();

    void add_route(Node* destination_node, Node* next_hop, int weight);
    void remove_link(int linked_node_id, double weight);
    int get_link_cost(int linked_nod_id);
    /*
    std::vector<dv> get_dvr_table(int destination_node);

    std::vector<Packet> get_update_packets();
    */

    int process_packet(Packet packet);



private:
    int node_id;
    QString name;
    bool source;
    QObject* node;

    bool process_dv_packet(Packet packet);
    void send_update_packets(double weight);

signals:

public slots:

};

#endif // NODE_H
