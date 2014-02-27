#include "dvrRT.h"
#include "stdafx.h"


DvrRT::DvrRT(QQuickItem *parent) :
    QQuickItem(parent)
{

}

//run algorithm
void DvrRT::run_algorithm(Node *source_node){
    //set the source node
    this->source_node = source_node;

    //get destination nodes (all nodes excluding the source node)
    algorithm_interface.get_destination_nodes(source_node);

    //shortest path first alg
    algorithm_interface.dijkstra_algorithm(source_node);

    //populate routing table

}

