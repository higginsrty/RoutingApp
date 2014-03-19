#include "lsrt.h"

lsRT::lsRT(QQuickItem *parent) :
    QQuickItem(parent)
{
}

//check link state
//returns 00 == bad, 01 == good
string get_link_state(Link *current_link)
{
    if (link.get_state()=="true"){
    return "01";
    }else if (link.get_state()=="false"){
        return "00";
    }else
        return "00";
    //need error code here
}

//run algorithm
void lsRT::run_algorithm(int number_of_nodes){
    //create vector to hold each node's map
    node_map.resize(number_of_nodes);
    for(int i=0; i<number_of_nodes; i++){
        node_map[i][] = dijkstra_algorithm(graph.node_pool[i]);
    }

}//end of run_algorithm
