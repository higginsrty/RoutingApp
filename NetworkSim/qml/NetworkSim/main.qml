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
        }

        Nodes {
            id: myNode

            x: 103
            y: 118

            Packet {
                id: packet_1
            }

            MouseArea {
                anchors.fill: parent;

                onClicked: {
                   (route_table.visible == true) ? route_table.visible = false : route_table.visible = true
                    console.log("clicked")
                }
            }
        }

        Link2 {
            x1: 300
            y1: 100
            x2: 100
            y2:  40
        }

        RoutingTable {
            id: route_table
        }
    }
}
