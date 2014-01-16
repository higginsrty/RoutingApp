import QtQuick 2.0

Item {
    width: parent.width / 3
    height: parent.height

    MouseArea {
        id: ma_menu
        anchors.fill: parent
        drag.target: parent
        drag.axis: Drag.XAxis
        drag.maximumX: 0
        drag.minimumX: parent.width * -0.9
    }
}
