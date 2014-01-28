#ifndef GRAPH_H
#define GRAPH_H

#include "stdafx.h"

class Link;
class Node;

class Graph : public QQuickItem
{
    Q_OBJECT
public:
    Graph(QObject *panel, QQmlEngine *engine);
    Node* add_node(QString name, int x, int y, int id);
    std::vector<Link*> get_link_from_node(Node *node);
    std::vector<Node*> get_node_from_link(Link *link);
    std::vector<Link*> get_link_from_node_id(int id);
    int add_link(Node *node1, Node *node2, int weight);
    Node* get_node_by_name(QString string);
    Node* get_node_by_id(int id);
    bool update_link_weight(Link* lkn, int weight);
    bool update_link_weight(Node *node1, Node *node2, int weight);

    bool update_algorithm(int alg_id);

    void change_to_flooding();
    void change_to_cbt();
    void change_to_dv();
    void change_to_ls();

private:
    QObject *panel;
    QQmlEngine *engine;
    std::vector<Link*> link_pool;
    std::vector<Node*> node_pool;

signals:

public slots:
    void update_node_position(qreal x, qreal y, QString string);
    void press_and_hold_node(QString node_name);
    void destroy_dialog();
};

#endif // GRAPH_H
