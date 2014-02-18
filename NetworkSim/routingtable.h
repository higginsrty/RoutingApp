#ifndef ROUTINGTABLE_H
#define ROUTINGTABLE_H

#include "stdafx.h"

class Node;

class RoutingTable
{
public:
    RoutingTable();
    int get_cost(int dest_id);
    Node* get_next_hop(int dest_id);
};

#endif // ROUTINGTABLE_H
