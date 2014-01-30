#include "stdafx.h"

FloodingRT::FloodingRT(QQuickItem *parent) :
    QQuickItem(parent)
{
}

void FloodingRT::update_table(int number_of_nodes, Node *source_node)
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


void FloodingRT::view_full_table()
{
    //===============================
    //Populate Flooding Routing Table
    //===============================

    //Load QML File
    QQmlComponent component(engine, QUrl("qrc:/qml_files/FloodingRoutingTable.qml"));
    //Create QObject
    QObject *object = component.create();
    //Displays on the parent
    item->setParentItem(qobject_cast<QQuickItem*>(node->parent()));

}//end of view_full_table
