import QtQuick 2.0

//data coloumns for Flooding Routing Table
//populate node names and weights using C++??
//used right now for testing purposes

ListModel {

    property string destination
    property int weight
    property string gateway

    id: flooding_routing_table_model


}//end of ListModel
