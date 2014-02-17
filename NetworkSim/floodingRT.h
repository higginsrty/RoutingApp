#ifndef FLOODINGRT_H
#define FLOODINGRT_H

#include <stdafx.h>

class FloodingRT : public QQuickItem
{
    Q_OBJECT

public:
    // Constructor (parent specifies the parent of this item
    explicit FloodingRT(QQuickItem *parent = 0);
    // Updating the table for each node
    void update_table(int number_of_nodes, Node *source_node, Graph *graph);
    // Visualizing the table if the node is clicked on
    int view_full_table(QQmlApplicationEngine *engine, QQuickItem *panel);

private:
    int number_of_nodes;
    Node *source_node;
    std::vector<Node*> destination_node_pool;
    std::vector<Node*> gateway_node_pool;
    std::vector<int> weight_pool;
};

#endif // FLOODINGRT_H
