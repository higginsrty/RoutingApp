import QtQuick 2.0

Item {
    id: menu
    z:50

    Image {
        anchors.fill: parent
        anchors.bottom: parent.bottom
        anchors.top: parent.top
        source: "qrc:/images/side_menu"
    }

   /* MenuListView {
        id: list_view
        anchors.fill: parent
    }*/

    MouseArea {
        id: ma_menu
        anchors.fill: parent
        hoverEnabled: true
        drag.target: parent
        drag.axis: Drag.XAxis
        drag.maximumX: 0
        drag.minimumX: parent.width * -0.9
        onEntered: {
            openMenu.start()
        }
        onExited: {
            closeMenu.start();
        }

        PropertyAnimation {
            id: openMenu
            target: menu
            property: "x"
            to: 0
            easing.type: Easing.InOutQuad
        }

        PropertyAnimation {
            id: closeMenu
            target: menu
            property: "x"
            to: menu.width * -0.9
            easing.type: Easing.InOutQuad
        }

        Rectangle {
            id: add_node_rect
            anchors.top:parent.top
            anchors.left:  parent.left
            anchors.right: parent.right
            height: parent.height/7
            opacity: 0
        }

        Rectangle {
            id: add_node
            anchors.verticalCenter: add_node_rect.verticalCenter
            x: parent.width*.7
            width: parent.width /7
            height: width
            radius: width*.5
            color:"black"
        }

        MouseArea{
            anchors.fill: add_node
            x: add_node.x
            y: add_node.y
            onPressAndHold: {
                console.log("Added a Node")
            }
        }

    }
}
