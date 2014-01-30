import QtQuick 2.0

item{
    height: parent.height
    width: parent.width
    visible: true //change to false if other algorithm
    z: 70

    Rectangle {
        anchors.fill: parent
        color: "purple"
    }

    FloodingRTView {
        id: frtGridView
    }

}//end of item
