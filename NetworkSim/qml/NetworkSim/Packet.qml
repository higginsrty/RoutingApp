import QtQuick 2.0

Item {
    width: 100
    height: 100
    x: parent.x
    y: parent.y
    Rectangle {
        color: "lightblue"
        anchors.fill: parent
        radius: parent.width * 0.5
    }
}
