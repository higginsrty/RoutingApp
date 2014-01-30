#include "algorithm_interface.h"
#include <stdafx.h>

algorithm_interface::algorithm_interface(int number_of_nodes, Node *source_node)
{      
}

void algorithm_interface::get_destination_nodes(Node *source_node)
{
    this->source_node = source_node;
    //destination node pool
    std::vector<Node*> destination_node_pool;
    //get number of nodes in the network
    int number_of_nodes = link_pool.size();
    int current_row = 1;

    std::vector<Node*>::iterator iter;

    for (iter = node_pool.begin(); iter != node_pool.end(); iter++) {
        Node *current_node = *iter;
        if (current_node->get_id() != source_node->get_id())
            destination_node_pool.push_back(current_node);
        }//end of for iter loop
    delete iter;

}//end of get_destionation_nodes
