import QtQuick 2.0
import QtQuick.Controls 1.1


Item{
    id: windowsDVRtable
    height: parent.height
    width: parent.width
    visible: false
    objectName: "dvrTable"
    signal destroy_dvrTable()
    y:0
    z:100

    PropertyAnimation {
        target: windowsDVRtable
        property: "opacity"
        duration: 600
        from: 0
        to: 1
        easing.type: Easing.InOutQuad
        running: true
    }

    Rectangle {
        id: dvrLabelText
        anchors.centerIn: parent
        z:150
        Text {
            text: "Distance-Vector Routing Table"
            font.pointSize: 24
            color: "red"
        }
    }

    Item {
        id: dvrMatrixComponent
        function readValues(anArray, anObject) {
                for (var i=0; i<anArray.length; i++)
                    console.log("Array item:", anArray[i])

                for (var prop in anObject) {
                    console.log("Object item:", prop, "=", anObject[prop])
                }
            }

    }

    Rectangle {
        id: dvrDisplayWindow
        height: parent.height
        width: parent.width
        anchors.centerIn: parent
        Button {
            anchors.centerIn: parent
            text: "Close"
        }

    }

  }
