import QtQuick 2.0

Item {
    width: parent.width / 3
    height: parent.height
    id: menu
    z:50

    Image {
        anchors.fill: parent
        source: "/home/jarad/Desktop/Menu Bar Buttons/Side Menu2.png"
    }

   /* MenuListView {
        id: list_view
        anchors.fill: parent
    }*/

    Rectangle {
        id: add_node
        x: parent.width*.7
        y: 14
        width: parent.width/5
        height: parent.height/10
        radius: width*.5
        color: "black"

        MouseArea{
            anchors.fill: parent
            onClicked: {
                console.log("Added a Node")
            }
        }
    }

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

    }
}
