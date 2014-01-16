import QtQuick 2.0

Item{
    Rectangle {
        id: address
        width: 100
        height: parent.height
        x: 0
    }

    Rectangle {
        id: gateway
        width: 100
        height: parent.height
        x: 100
    }

    Rectangle {
        id: destination
        width: 100
        height: parent.height
        x: 200
    }

    Rectangle {
        id: weight
        width: 100
        height: parent.height
        x: 300
    }
}
