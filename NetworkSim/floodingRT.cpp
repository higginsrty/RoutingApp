#include "stdafx.h"

FloodingRT::FloodingRT(QQuickItem *parent) :
    QQuickItem(parent)
{
}

void FloodingRT::updateTable(int number_of_nodes, Node *source_node)
{
    //Load QML File
    QQmlComponent component(engine, QUrl("qrc:/qml_files/FloodingRTModel.qml"));
    //Create QObject
    QObject *object = component.create();
    this->number_of_nodes = number_of_nodes;
    this->source_node = source_node;
    //Cast to QQuickItem
    QQuickItem *item = qobject_cast<QQuickItem*>(object);
    QQuickItem *node = qobject_cast<QQuickItem*>(source_node->get_q_object());

    //***************************************
    //Need method for clearing previous table
    //***************************************

    //========================
    //Step1 Source Node Column
    //========================
    //Source Node Name
    std::string source_node_name = node->get_name();

    //Create Header
    item->setProperty("eHeader", "Source");

    //Reset row number for table
    int table_row = 1;

    //Populate Source Nodes
    //All the same
    while (number_of_nodes > table_row)
    {
        //increments e1++
        std::string next_row = "e" + std::to_string (table_row);
        table_row++;
        //sets e(row number) as the source node's name
        item->setProperty(next_row, source_node_name);
    }//end while

    //============================
    //Step2 Desination Node Column
    //============================
    //Desination Node Name Placeholder
    std::string desination_node_name;

    //int used to check for all available nodes in network simulation
    int possible_node_IDs = 0;

    //Create Header
    item->setProperty("eHeader", "Destination");

    //Reset row number for table
    table_row = 1;

    //Populate Destination Nodes
    while (number_of_nodes > table_row)
    {
        //increment e1++
        std::string next_row = "e" + std::to_string (table_row);
        table_row++;

        //obtain destination nodes
        //******************************************************************
        //build array or list with node IDs as they are created or deleted??
        //this will make it easy to locate each node in the network and
        //display it's corresponding name in the destination column??
        //******************************************************************

        //sets e(row number) to the destination node's name
        item->setProperty(next_row, destination_node_name);
    }//end while

    //==============================
    //Step3 Distance (Weight) Column
    //==============================
    //Weight Placeholder
    int distance_weight;

    //Create Header
    item->setProperty("eHeader", "Distance");

    //Reset row number for table
    table_row = 1;

    //Populate Weights
    while (number_of_nodes > table_row)
    {
        //increment e1++
        std::string next_row = "e" + std::to_string (table_row);
        table_row++;

        //**********************************************************
        //create link list/array that contains each valid link's id
        //select each link and get each source node and node2
        //Update Distance Column accordingly??????
        //**********************************************************

        //sets e(row number) to the source node's weight to destination
        item->setProperty(next_row, distance_weight);
    }//end while

    //=========================
    //Step4 Gateway Node Column
    //=========================
    //Gateway Node Name's Placeholder
    std::string gateway_node;
    int number_of_links;

    //Create Header
    item->setProperty("eHeader", "Gateway");

    //Reset row number for table
    table_row = 1;

    //Populate Gateway Nodes
    while (number_of_nodes > table_row)
    {
        if(number_of_links != 1)
        {
            gateway_node = " ";
        }//end of if

        //sets e(row number) to the source node's gateway to destination
        item->seetProperty(next_row, gateway_node);
    }//end of while

}// end of FloodingRT->updateTable

void FloodingRT::resetTable()
{
    //fills column with " "
    item->setProperty("eHeader", " ");
    item->setProperty("e1", " ");
    item->setProperty("e2", " ");
    item->setProperty("e3", " ");
    item->setProperty("e4", " ");
    item->setProperty("e5", " ");
    item->setProperty("e6", " ");
    item->setProperty("e7", " ");
    item->setProperty("e8", " ");
    item->setProperty("e9", " ");
}//end of FloodingRT->resetTable



