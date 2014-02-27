#ifndef ALGORITHM_INTERFACE_H
#define ALGORITHM_INTERFACE_H

#include "stdafx.h"

class algorithm_interface
{
public:
   int number_of_nodes;
   int min;
    int distance[];
    bool shortest_path_set[];
    int u;
    std::vector<Node*> destination_node_pool;
};

#endif // ALGORITHM_INTERFACE_H
