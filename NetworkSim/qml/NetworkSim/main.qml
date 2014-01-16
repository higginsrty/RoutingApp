import QtQuick 2.0

Item {
    objectName: "root"
    width: 400
    height: 400

    Item {
        objectName: "MainPanel"
        width: parent.width
        height: parent.height
        // This is where all other items will be added, such as the menu, nodes, links...etc.

        ActionBar {
            id: action_bar
            Rectangle {
                anchors.fill: parent
                color: "red"
            }
        }

        Menu {
            x: -width * 0.9
            y: action_bar.height
            height: parent.height - action_bar.height
            Rectangle {
                anchors.fill: parent
                color: "blue"
            }
        }

        RoutingTable {
            id: route_table
            visible: false
        }

        Node {
            id: node_1

            Packet {
                id: packet_1
                x: 57
                y: 109
            }
        }
    }
}
