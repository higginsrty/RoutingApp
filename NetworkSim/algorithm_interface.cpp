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

int minimum_distance(int distance[], bool shortest_path_set[])
{
    //set the minimum value
    int min = INT_MAX, min_index;

    for (int v = 0; v < number_of_nodes; v++)
    {
        if(shortest_path_set[v] == false && distance[v] <= min)
        {
            min = distance[v], min_index = v;
        }//end of if statement
    }//end of for loop

    return min_index;

}//end of minimum_distance


void algorithm_interface::dijkstra_algorithm(Node *source_node)
{//used to calculated the shortest path from source node to each destination node

    //output array will hold the shortest distance from source_node to each node
    int distance[number_of_nodes];

    //set to true if the vertex is included in the shortest path
    bool shortest_path_set[number_of_nodes];

    //pre-set all disstances to INT_MAX and shortestPathSet to false
    for (int i = 0; i < number_of_nodes; i++)
    {
        distance[i] = INT_MAX;
        shortest_path_set[i] = false;
    }//end of for loop

    //set distance of source node to 0
    distance[source_node] = 0;

    //find the shortest path for all nodes
    for (int count = 0; count < number_of_nodes-1; count++)
    {
        //pick the minimum distance from the set of nodes not yet processed
        int u = minimum_distance(distance,shortest_path_set);

        //mark node as processed
        shortest_path_set[u] = true;

        //update the distance value of the same vertices of hte picked node
        for(int v = 0; v < number_of_nodes; v++)
        {
            //only update if it is not in shortest_path_set
            if(!shortest_path_set[number_of_nodes] && graph[u][v] && distance[u] != INT_MAX && distance[u]+graph[u][v] < distance[v])
            {
                distance[v] = distance[u] + graph[u][v];

            }//end of if statement
        }//end of for loop
    }//end of for loop

}//end of dijkstra's algorithm

