import QtQuick 2.0

Item {
    objectName: "root"
    width: 800
    height: 600

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

    }
}
