#ifndef GRAPH_H
#define GRAPH_H

#include "stdafx.h"

class Link;
class Node;
class Packet;
class QmlDocument;

class Graph : public QQuickItem
{
    Q_OBJECT
public:
    Graph(QObject *panel, QQmlApplicationEngine *engine);
    Node* add_node(QString name, int x, int y, int id);
    std::vector<Link*> get_link_from_node(Node *node);
    std::vector<Node*> get_node_from_link(Link *link);
    std::vector<Link*> get_link_from_node_id(int id);
    int add_link(Node *node1, Node *node2, int weight);
    Node* get_node_by_name(QString string);
    Node* get_node_by_id(int id);
    bool update_link_weight(Link* lkn, int weight);
    bool update_link_weight(Node *node1, Node *node2, int weight);

    void destroy_packets();
    void pause_animation();
    void resume_animation();
    void start_animation();

    void update_algorithm(int alg_id);
    void change_to_flooding();
    void change_to_cbt();
    void change_to_dv();
    void change_to_ls();
    Node* get_source();
    void create_node();
    void stop_send_packets();

private:
    int time;
    QTimer *timer;
    QObject *panel;
    QQmlApplicationEngine *engine;
    std::vector<Link*> link_pool;
    std::vector<Node*> node_pool;
    std::vector<Packet*> packet_pool;
    void update_dests(Node *node);
    void update_source_packet_pos(Node *node);
    int node_id = 0;
    bool started;
    bool paused;

signals:
     void animatePackets();

public slots:
    void update_node_position(qreal x, qreal y, QString string);
    void press_and_hold_node(QString node_name);
    void destroy_dialog();
    void show_routing_table(QString node_name);
    void send_packets();
};

#endif // GRAPH_H
