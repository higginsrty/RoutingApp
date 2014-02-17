#include "stdafx.h"

FloodingRT::FloodingRT(QQuickItem *parent) :
    QQuickItem(parent)
{
}

void FloodingRT::update_table(int number_of_nodes, Node *source_node, Graph *graph)
{
    //=====================================
    //Calculate Node, Distance, and Gateway
    //Values for selected Source Node
    //=====================================

    this->number_of_nodes = number_of_nodes;
    this->source_node = source_node;

    int current_row = 0;

    //===============================
    //Step1: Obtain Destination Nodes
    //===============================



}//end of updateTable


int FloodingRT::view_full_table(QQmlApplicationEngine *engine, QQuickItem *panel)
{
    //===============================
    //Populate Flooding Routing Table
    //===============================
    // Check to make sure all vectors are of the same size
    if (destination_node_pool.size() != gateway_node_pool.size() ||
            gateway_node_pool.size() != weight_pool.size() ||
            weight_pool.size() != destination_node_pool.size())
        return -1; // return -1 for an error
    // Get the iterators for the different vectors
    std::vector<Node*>::iterator dest_iter = destination_node_pool.begin();
    std::vector<Node*>::iterator gate_iter = gateway_node_pool.begin();
    std::vector<int>::iterator weight_iter = weight_pool.begin();
    // Creating a QObject for the routing table model, this is where
    // all of the items get added to
    QQmlComponent comp(engine, QUrl("qrc:/qml_files/flooding_model.qml"));
    QObject *object = comp.create();
    QQuickItem *model = qobject_cast<QQuickItem*>(object);
    /*
    // While loop setup - Make sure all iterators are not at the end
    while (dest_iter != destination_node_pool.end() &&
           gate_iter != gateway_node_pool.end() &&
           weight_iter != weight_pool.end())
    {
        // Grab the reference to the next item in each vector
        // This is the information for a row in the routing table
        Node *dest = *dest_iter;
        Node *gate = *gate_iter;
        int weight = *weight_iter;
        // Creating the routing table item QObject
        QQmlComponent component(engine, QUrl("qrc:/qml_files/flooding_item.qml"));
        object = component.create();
        QQuickItem *item = qobject_cast<QQuickItem*>(object);
        // Setting the properties of the QObject
        item->setProperty("destination", dest->get_name());
        item->setProperty("gateway", gate->get_name());
        item->setProperty("weight", weight);
        // Adding the routing table item to the model
        item->setParentItem(model);
        // Moving the iterators to the next item
        dest_iter++;
        gate_iter++;
        weight_iter++;
    }
    */
    // Create the routing table to actually be displayed
    QQmlComponent comp1(engine, QUrl("qrc:/qml_files/flooding_routing_table.qml"));
    QObject *obj = comp1.create();
    QQuickItem *routing_table = qobject_cast<QQuickItem*>(obj);
    obj->findChild<QObject*>("table");
    model->setParentItem(routing_table);
    obj->setProperty("model", "flooding_routing_table_model");

    // Add the routing table to the main panel for viewing
    routing_table->setParentItem(panel);

    return 0;
}//end of view_full_table
