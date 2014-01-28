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
        duration: 1000
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
        width: 100
        height: 62
        radius: 10
        anchors.centerIn: parent

        Text {
            anchors.centerIn: parent
            text: "This is the popup"
        }

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
}
