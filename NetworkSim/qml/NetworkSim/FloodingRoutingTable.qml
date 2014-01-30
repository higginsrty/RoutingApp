import QtQuick 2.0
import QtQuick.Controls 1.1

Item{
    height: parent.height
    width: parent.width
    visible: true //change to false if other algorithm
    z: 70

    Rectangle {
        anchors.bottom: table.top
        Text {
            text: "Source: A"
            anchors.centerIn: parent
        }

        anchors.top: parent.top
        anchors.right: parent.right
        anchors.left: parent.left
    }

    TableView {
        id: table
        y: 100
        model: flooding_routing_table_model
        TableViewColumn{role:destination;title:"Destination"}
        TableViewColumn{role:weight;title:"Weight"}
        TableViewColumn{role:gateway;title:"Gateway"}
    }

}//end of item
