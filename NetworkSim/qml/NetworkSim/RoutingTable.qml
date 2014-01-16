import QtQuick 2.0

Item{
    height: parent.height
    width: parent.width
    visible: false
    x: 0
    y: 0
    Rectangle {
        anchors.fill: parent
        color: "black"
        Rectangle {
            id: address
            width: 100
            height: parent.height
            x: 0
            color: "red"
        }

        Rectangle {
            id: gateway
            width: 100
            height: parent.height
            x: 100
            color: "darkgreen"
        }

        Rectangle {
            id: destination
            width: 100
            height: parent.height
            x: 200
            color: "lightgreen"
        }

        Rectangle {
            id: weight
            width: 100
            height: parent.height
            x: 300
            color: "lightsteelblue"
        }
    }
}
