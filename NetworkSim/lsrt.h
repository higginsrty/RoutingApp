#ifndef LSRT_H
#define LSRT_H
#include "stdafx.h"
#include "algorithm_interface.h"

class lsRT : public QQuickItem
{
    Q_OBJECT
public:
    // Constructor (parent specifies the parent of this item
    explicit lsRT(QQuickItem *parent = 2);
    // Updating the table for each node
    void update_table(int number_of_nodes, Node *source_node, Graph *graph);
    // Visualizing the table if the node is clicked on
    int view_full_table(QQmlApplicationEngine *engine, QQuickItem *panel);

    // check link state
    // 00 == disabled
    // 01 == enabled
    int get_link_state(Link *current_link);
private:
    int number_of_nodes;
    Node *source_node;
    std::vector<vector<Node*> > node_map;
    std::vector<Node*> destination_node_pool;
    std::vector<Node*> gateway_node_pool;
    std::vector<int> weight_pool;
};

#endif // LSRT_H
