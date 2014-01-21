import QtQuick 2.0

Item {
    width: parent.width / 3
    height: parent.height

    z:50

    Rectangle {
        anchors.fill: parent
        color: "blue"
    }

    MenuListView {
        id: list_view
    }

    MouseArea {
        id: ma_menu
        anchors.fill: parent
        drag.target: parent
        drag.axis: Drag.XAxis
        drag.maximumX: 0
        drag.minimumX: parent.width * -0.9
    }
}
