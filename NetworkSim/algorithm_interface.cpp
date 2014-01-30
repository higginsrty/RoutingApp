#include "algorithm_interface.h"
#include <stdafx.h>

algorithm_interface::algorithm_interface(Node *source_node)
{      
}

void algorithm_interface::get_destination_nodes(Node *source_node)
{
    this->source_node = source_node;
    //destination node pool
    std::vector<Node*> destination_node_pool;
    //get number of nodes in the network
    int number_of_nodes = link_pool.size();

    std::vector<Node*>::iterator iter1;
    for (iter1 = node_pool.begin(); iter1 != node_pool.end(); iter1++) {
        Node *current_node = *iter1;
        if (current_node->get_id() != source_node->get_id())
            destination_node_pool.push_back(current_node);
        }//end of for iter loop
    delete iter1;
}//end of get_destionation_nodes

void algorithm_interface::dijkstra_algorithm(Node *source_node)
{//used to calculated the shortest path from source node to each destination node

    this->source_node = source_node;
    //create the origin used in Dijkstra's Algorithm
    Node origin_node = source_node;
    //vector containing all unvisited nodes
    std::vector<Node*> unvisited_node_pool;

    //Step 1)
    //fill unvisited node vector with destination nodes
    //origin_node weight value is preset to 0
    //set all other nodes to infinity

    std::vector<Node*>::iterator iter2;
    for (iter2 = destination_node_pool.begin(); iter2 != destination_node_pool.end(); iter2++ )
    {
        Node *current_node = *iter2;
        current_node->node_weight = INT_MAX;
        unvisited_node_pool.push_back(current_node);
    }


}//end of dijkstra's algorithm
