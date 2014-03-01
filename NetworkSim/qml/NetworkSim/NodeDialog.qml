import QtQuick 2.0
import QtQuick.Controls 1.1

Item {
    id: dialogComponent
    anchors.fill: parent
    objectName: "nodeDialog"
    signal set_source()
    signal update_name(string name);
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

        TextInput {
            id: txt_name

        }

        Button {
            id:btn_name
            anchors.right:btn_source.left
            anchors.top:btn_source.top
            text: "Update Name"
            onClicked: update_name(txt_name.text)
        }

        Button {
            id:btn_source
            anchors.left:parent.horizontalCenter
            anchors.top:parent.verticalCenter
            text: "Is Source"
            onClicked: set_source()
        }
    }
}
