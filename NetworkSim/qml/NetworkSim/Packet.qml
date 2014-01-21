import QtQuick 2.0

Item {
    width: 50
    height: 50
    anchors.centerIn: parent
    z:5

    Rectangle {
        color: "lightblue"
        anchors.fill: parent
        radius: parent.width * 0.5
    }
}
