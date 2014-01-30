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
    void update_table(int number_of_nodes, Node *source_node);
    // Visualizing the table if the node is clicked on
    void view_full_table();

private:
    int number_of_nodes;
    Node *source_node;
};

#endif // FLOODINGRT_H
