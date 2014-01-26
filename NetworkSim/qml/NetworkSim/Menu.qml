import QtQuick 2.0

Item {
    width: parent.width / 3
    height: parent.height
    id: menu
    z:50

    Rectangle {
        anchors.fill: parent
        color: "blue"
    }

    MenuListView {
        id: list_view
        anchors.fill: parent
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
