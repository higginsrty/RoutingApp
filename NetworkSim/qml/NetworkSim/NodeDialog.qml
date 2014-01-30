import QtQuick 2.0

Item {
    id: dialogComponent
    anchors.fill: parent
    objectName: "nodeDialog"
    signal destroy_dialog()
    z:100

    PropertyAnimation {
        target: dialogComponent
        property: "opacity"
        duration: 600
        from: 0
        to: 1
        easing.type: Easing.InOutQuad
        running: true
    }


    Rectangle {
        anchors.fill: parent
        id: overlay
        color: "#000000"
        opacity: 0.6
        MouseArea {
            anchors.fill: parent
        }
    }

    // This rectangle is the actual popup
    Rectangle {
        id: dialogWindow
        width: 400
        height: 200
        radius: 10
        anchors.centerIn: parent

        /*Text {
            anchors.centerIn: parent
            text: "This is the popup"
        }*/


        MouseArea{
            anchors.fill: parent
            PropertyAnimation {
                id: fade_out
                target: dialogComponent
                property: "opacity"
                duration: 600
                alwaysRunToEnd: true
                from: 1
                to: 0
                easing.type: Easing.InOutQuad;
                onRunningChanged: {
                    if (!fade_out.running)
                        destroy_dialog()
                }
            }
            onClicked: {
                fade_out.start()
            }
        }
    }

    Rectangle {
        id:button
        property color button_color: "grey"
        property color hover_color: "lightgrey"
        property color border_color: "black"
        anchors.centerIn: parent
        width: 50
        height: 25
        radius: width*.1
        color: button_color
        Text{
            anchors.centerIn: parent
            text: "Test"
        }


        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onEntered: parent.color = parent.hover_color
            onExited: parent.color = parent.button_color
            //When Mouse is pressed down
            onPressed: {
                parent.color = parent.button_color
                console.log("Button Pressed")
            }
            //When Mouse is Realeased
            onClicked:{
                parent.color = parent.hover_color
                console.log("Button Released")

            }


        }

    }
}